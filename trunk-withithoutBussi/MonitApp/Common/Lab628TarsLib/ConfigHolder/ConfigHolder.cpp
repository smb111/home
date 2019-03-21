#include "ConfigHolder.h"
#include <string>
#include <exception>
#include <map>

using namespace tars;
using namespace std;

TarsObjectConfig::TarsObjectConfig() 
		: objName(),
		  setName(),
		  timeOut(DEFAULT_ASYNCTIMEOUT){
}

TarsObjectConfig &TarsObjectConfig::pasre(const map<string, string> &confMap, const std::string &setName0, int timeOut0) {
	std::map<std::string, std::string>::const_iterator iter, end = confMap.end();
	iter = confMap.find("Obj");
	if (iter != end) {
		this->objName = iter->second;
	}
	iter = confMap.find("Set");
	if (iter != end) {
		this->setName = iter->second;
	} else {
		this->setName = setName0;
	}
	iter = confMap.find("TimeOut");
	if (iter != end) {
		this->timeOut = TC_Common::strto<int>(iter->second);
	} else {
		this->timeOut = timeOut0;
	}

	return *this;
}

TarsObjectConfigHolder::TarsObjectConfigHolder() 
		: m_defConf(),
		  m_confMap(),
		  m_comm(Application::getCommunicator()){
}
// TarsObjectConfig m_defConf;
// Tars::CommunicatorPtr m_comm
// std::map<std::string, TarsObjectConfig> m_confMap;
void TarsObjectConfigHolder::parse(TC_Config &conf) {
	std::map<std::string, std::string> domainMap;
	if (conf.getDomainMap("/default", domainMap)) {
		this->m_defConf.parse(domainMap, "", TarsObjectConfig::DEFAULT_TIME_OUT);
		TLOGDEBUG("|def" << "|objName=" << this->m_defConf.objName << "|setName=" << this->m_defConf.setName << "|timeOut=" << this->m_defConf.timeOut);
	}
	if (!this->m_defConf.objName.empty()) {
		this->m_comm = new Communicator();
		this->m_comm->setProperty("locator",this-> m_defConf.objName);
	}
	// 下面 循环读取 tars-config.conf 配置文件中的每一个 服务的 配置行， 并且写入 this->m_confMap;
	vector<string> domainKeys = conf.getDomainVector("/");
	for (size_t i = 0, max = domainKeys.size(); i < max; ++i) {
		const std::string &key = domainKeys[i];
		TLOGDEBUG("|i=" << i << "|key" << key);
		if (key != "default" && conf.getDomainMap("/" + key, domainMap)) {
			TarsObjectConfig &tarsConf = this->m_confMap[Key];
			tarsConf.parse(domainMap, this->m_defConf.setName, this->m_defConf.timeOut);
			TLOGDEBUG( "|objName=" << tarsConf.objName << "|setName=" << tarsConf.setName << "|timeOut=" << tarsConf.timeOut);
		}
	}
	TLOGDEBUG(std::endl);
}

void TarsObjectConfigHolder::getConfig(const std::string &name, const std::string &defObjName, std::string &objName, std::string &setName, int &timeOut) {
	std::map<std::string, TarsObjectConfig>::const_ierator iter = this->m_confMap.find(name), end = this->m_confMap.end();
	if (iter != end) {
		objName = iter->second.objName.size() ? iter->second.objName : defObjName;
		setName = iter->second.setName;
		timeOut = iter->second.timeOut;
		TLOGDEBUG("|objName=" << objName << "|setName=" << setName << "|timeOut=" << timeOut << endl);
	} else {
		objName = defObjName;
		setName = this->m_defConf.setName;
		timeOut = this->m_defConf.timeOut;
		TLOGDEBUG("|objName=" << objName << "|setName=" << setName << "|timeOut=" << timeOut << ends);
	}
}

TC_AutoPtr<TarsObjectConfigHolder> ConfigHolderFactory::getTarsCfgHolder() {
	return TARS_CFG_HOLDER;
}

void ConfigHolderFactory::Initialize(tars::Application &application) {
	app = &application;
	app->addConfig("tarsConfig.conf");
	static const char * CONFIG_HOLDER = "ConfigHolder";
	static const int CFG_HOLDER_LEN = strnlen(CONFIG_HOLDER, 64);
	TC_DYN_RuntimeClass* pClass;
	// 从这个程序中，所有继承自 TC_DYN_Object 的类（有一个 TC_DYN_RuntimeClass 成员）中进行挑选，挑选出 结尾是 ConfigHolder 的类， 放入 ConfigHolderFactory 的 map 中
	for (pClass = TC_DYN_RuntimeClass::pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
	{
		const char * start = strstr(pClass->m_lpszClassName, "ConfigHolder");
		if (start != NULL && start != pClass->m_lpszClassName && !strncmp(start, CONFIG_HOLDER, CFG_HOLDER_LEN + 1))
		{
			TC_DYN_Object *dynObjPtr = pClass->createObject();
			ConfigHolder * cfgHolderPtr = dynamic_cast<ConfigHolder *>(dynObjPtr);
			if (cfgHolderPtr != NULL) {
				CFG_HOLDERS[pClass->m_lpszClassName] = cfgHolderPtr;
			}else {
				delete dynObjPtr;
			}
		}
	}
	ConfigHolderFactory::reloadConfig();
	ConfigHolderFactory::reloadTarsObjectConfig();
}

static bool reload(const string &command = "*", const std::string &params, std::string &result) {
	bool res = true;
	res = ConfigHolderFactory::reloadConfig(command) & res;
	res = ConfigHolderFactory::reloadTarsObjectConfig() & res;
	return res;
}

void ConfigHolderFactory::Destory() {
	std::map<std::string, ConfigHolder *>::const_iterator iter = CFG_HOLDERS.begin(), end = CFG_HOLDERS.end();
	for(; iter != end; ++iter) {
		delete  iter->second;
	}
}

bool ConfigHolderFactory::reloadConfig(std::string command) {
	bool result = true;
	std::map<std::string, ConfigHolder *>::const_iterator iter = CFG_HOLDERS.begin(), end = CFG_HOLDERS.end();
	for (; iter != end; ++iter) {
		try {
			app->addConfig(iter->second->_configName); // 先拉取配置文件，配置文件的名字不要写错
			result = iter->second->reload(command) && result;
		}catch (exception &ex) {
			TLOGDEBUG("configuration" << "load config[" << iter->first << "] error: " << ex.what() << std::endl);
			result = false;
		}catch (...) {
			TLOGINFO("configuration" << "load config[" << iter->first << "] error." << std::endl);
			result = false;
		}
	}
	return result;	
}

bool ConfigHolderFactory::reloadTarsObjectConfig() {
	try {
		TC_Config conf;
		conf.parseFile(ServerConfig::BasePath + "tars-config.conf");
		TC_AutoPtr<TarsObjectConfigHolder> holder = new TarsObjectConfigHolder();
		holder.parse(conf);   // 全部 服务信息 写入 holder->m_confMap (std::map<std::string, TarsObjectConfig>)
		TARS_CFG_HOLDER = holder;
		return true;
	} catch (std::exception &ex) {
		TLOGERROR("configuration") << "load config error:" << ex.what() << endl);
	} catch (...) {
		TLOGERROR("configuration") << "load config error." << endl)；
	}
	return false;
}
TC_AutoPtr<TarsObjectConfigHolder> ConfigHolderFactory::TARS_CFG_HOLDER = new TarsObjectConfigHolder();
std::map<std::string, ConfigHolder *> ConfigHolderFactory::CFG_HOLDERS;
tars::Application *ConfigHolderFactory::app;
