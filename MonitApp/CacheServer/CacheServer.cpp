#include "CacheServer.h"
#include "CacheImp.h"
#include "CacheServerConfigHolder.h"
//#include "Config/CacheServerConfigHolder.h"
#include <fstream>
using namespace std;

CacheServer g_app;

/////////////////////////////////////////////////////////////////
void
CacheServer::initialize()
{
    //initialize application here:
    //...

    addServant<CacheImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".CacheObj");
	addConfig("time_pass.conf");
	

	ConfigHolderFactory::Initialize(g_app);
	const CacheServerConfigHolder *cfg = ConfigHolderFactory::getCfgHolder<CacheServerConfigHolder>();

	if (cfg == NULL) {
		TLOGDEBUG ("Config reload faild !" << std::endl);
		return ;
	}

	ofstream ofile;
	ofile.open("./Mylog.logfile");

	ofile << "ServerConfig::BasePath: " << ServerConfig::BasePath << endl;
	ofile << "ServerConfig::ServerName: " << ServerConfig::ServerName << endl;
	ofile << "CacheServerConfigHolder->hostName: " << cfg->hostName << endl;
	ofile << "CacheServerConfigHolder->port: " << cfg->port << endl;
	ofile << "CacheServerConfigHolder->userName: " << cfg->userName << endl;
	ofile << "CacheServerConfigHolder->cachePassWd: " << cfg->cachePassWd << endl;

	ofile.close();

	TLOGDEBUG("hostName: " << cfg->hostName << std::endl);
	TLOGDEBUG("port: " << cfg->port << std::endl);
	TLOGDEBUG("userName: " << cfg->userName << std::endl);
	TLOGDEBUG("cachePassWd: " << cfg->cachePassWd << std::endl);

}
/////////////////////////////////////////////////////////////////
void
CacheServer::destroyApp()
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
