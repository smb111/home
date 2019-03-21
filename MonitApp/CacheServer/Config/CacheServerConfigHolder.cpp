#include "CacheServerConfigHolder.h"
#include <string>
#include <exception>
#include "util/tc_config.h"
#include "util/tc_common.h"
#include "util/tc_encoder.h"
#include "util/tc_cgi.h"
#include <iostream>

using namespace std;
using namespace tars;

IMPLEMENT_CONFHOLDER_DYNCREATE(CacheServerConfigHolder, TC_DYN_Object)

bool CacheServerConfigHolder::reloadImp() {
	try {
		TC_Config conf;
		conf.parseFile(ServerConfig::BasePath + _configName);
		this->hostName = conf.get("/DB<Host>", "10.20.4.111");
		this->port = TC_Common::strto<int>(conf.get("/DB<Port>", "3307"));
		this->userName = conf.get("/DB<User>", "smbzhang");
		this->cachePassWd = conf.get("/DB<Pass>", "qiang95");

		TLOGDEBUG("CacheServerConfig Parse Result: " << hostName << "	" << \
				port << "	" << userName << "	" << cachePassWd << ";" << endl);
	}
	catch (std::exception &ex) {
		return false;
	}
	catch (...) {
		return false;
	}
	return true; 	
}
