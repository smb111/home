#ifndef CACHESERVERCONFIGHOLDER_H_
#define CACHESERVERCONFIGHOLDER_H_

#include "ConfigHolder.h"
//#include "/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder/ConfigHolder.h"
#include "servant/Application.h"
#include <string>

using namespace std;
using namespace tars;

/* ConfigHolderFactory 执行 initialize 函数的时候，已经执行了 reload("*") 函数 */
class CacheServerConfigHolder : public ConfigHolder {
	DECLARE_CONFHOLDER_DYNCREATE(CacheServerConfigHolder)
public:
	CacheServerConfigHolder() {
		this->_configName = "CacheServerConfig.conf";
	}
	virtual bool reloadImp(); // 重载 ConfigHolder 类的这个虚拟方法
	std::string hostName;
	unsigned int port;
	std::string userName;
	std::string cachePassWd;
};

#endif
