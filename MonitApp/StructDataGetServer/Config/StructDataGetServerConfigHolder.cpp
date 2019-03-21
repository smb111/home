/*
 * StructDataGetServerConfigHolder.cpp
 *
 * Creat on : 2019年1月18号
 *   Author : smbzhang
 */
#include "StructDataGetServerConfigHolder.h"
#include <exception>
#include "util/tc_config.h"
#include "util/tc_common.h"
#include "util/tc_encoder.h"
#include <iostream>
#include "util/tc_cgi.h"

using namespace std;
using namespace tars;
using namespace MonitApp;

IMPLEMENT_CONFHOLDER_DYNCREATE(StructDataGetServerConfigHolder, TC_DYN_Object)

StructDataGetServerConfigHolder::reloadImp() {
	try {
		TC_Config conf;
		conf.parseFile(ServerConfig::BasePath + _configName);
		this->host_ip = conf.get("/Global<host_ip>","127.127.127.127");
		TLOGDEBUG("StructDataGetServerConfigHolder host_ip: " << this->host_ip << endl);
	}
	catch (std::exception &ex) {
		TLOGDEBUG("StructDataGetServerConfigHolder load config file failed !" << std::endl);
		return false;
	}
	catch (...) {
		TLOGDEBUG("StructDataGetServerConfigHolder load config file failed !" << std::endl);
		return false;
	}
	return true;
}
