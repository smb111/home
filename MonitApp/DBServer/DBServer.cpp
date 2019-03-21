#include "DBServer.h"
#include "DataBaseImp.h"
#include "util/tc_mysql.h"
using namespace std;

DBServer g_app;
TC_Mysql mysql;
/////////////////////////////////////////////////////////////////
void
DBServer::initialize()
{
    //initialize application here:
    //...
	mysql.init("10.20.4.127","root","1174","aaa");
	mysql.connect();
    addServant<DataBaseImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".DataBaseObj");
}
/////////////////////////////////////////////////////////////////
void
DBServer::destroyApp()
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
