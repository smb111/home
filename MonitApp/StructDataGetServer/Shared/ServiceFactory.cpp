/*
 * ServiceFactory.cpp
 *
 * Created on: 2019年1月21日
 *     Author: smbzhang
 */
#include "ServiceFactory.h"
#include "/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder/ConfigHolder.h"

using namespace std;
using namespace tars;
using namespace MonitApp;

ServiceFactory() {

}

~ServiceFactory() {

}
MonitApp::DataBasePrx ServiceFactory::getDataBasePrx() {
	//T getProxy(const std::string &name, const std::string &defObjName &defObjName = "")
	return ConfigHolderFactory::getTarsCfgHolder()->getProxy<DataBasePrx>("DBServer", "MonitApp.DBServer.DataBaseObj@tcp -h 10.20.4.111 -t 60000 -p 10011");
}

MonitApp::CachePrx ServiceFactory::getCachePrx() {
	return ConfigHolderFactory::getTarsCfgHolder()->getProxy<CachePrx>("CacheServer", "MonitApp.CacheServer.CacheObj@tcp -h 10.20.4.111 -t 60000 -p 10012");
}

MonitApp::StructDataGetPrx ServiceFactory::getStructDataGetPrx() {
	return ConfigHolderFactory::getTarsCfgHolder()->getProxy<StructDataGetPrx>("StructDataGetServer", "MonitApp.StructDataGetServer.StructDataGetObj@tcp -h 10.20.4.111 -t 60000 -p 10010");
}

