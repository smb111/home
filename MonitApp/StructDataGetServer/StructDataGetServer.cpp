#include "StructDataGetServer.h"
#include "StructDataGetImp.h"
#include "StructDataGetServerConfigHolder.h"
#include <iostream>
using namespace std;

StructDataGetServer g_app;

/////////////////////////////////////////////////////////////////
void
StructDataGetServer::initialize()
{
    //initialize application here:
    //...

    addServant<StructDataGetImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".StructDataGetObj");
	ConfigHolderFactory::Initialize(g_app);

	const StructDataGetServerConfigHolder *cfg = ConfigHolderFactory::getCfgHolder<StructDataGetServerConfigHolder>();
	if (cfg == NULL) {
		TLOGDEBUG("Load StructDataGetServer Config File Failed!" << std::endl);
		return;
	}
	TLOGDEBUG("host_ip: " << cfg->host_ip << std::endl);
}
/////////////////////////////////////////////////////////////////
void
StructDataGetServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
