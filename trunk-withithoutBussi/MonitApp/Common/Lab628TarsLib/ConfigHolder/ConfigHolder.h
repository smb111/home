#ifndef ConfigHolderFactory_H__
#define ConfigHolderFactory_H__

#include <servant/Application.h>
#include <util/tc_autoptr.h>
#include <util/tc_dyn_object.h>
#include <iostream>
#include <string>
#include <map>
#include <exception>

#define DECLARE_CONFHOLDER_DYNCREATE(class_name) \
public: \
	static TC_DYN_RuntimeClass class##class_name; \
	static TC_DYN_Object *createObject(); \
	static TC_DYN_RuntimeClass *GetRuntimeClass0(); \
	virtual TC_DYN_RuntimeClass *GetRuntimeClass() const; \

#define IMPLEMENT_CONFHOLDER_DYNCREATE(class_name, base_class_name) \
	static TC_DYN_Init _init_##class_name(&class_name::class##class_name); \
	TC_DYN_Object *class_name::createObject() \
		{return new class_name;} \
	TC_DYN_RuntimeClass class_name::class##class_name = { \
		#class_name, \
		sizeof(class_name), \
		&class_name::createObject, \
		RUNTIME_CLASS(base_class_name), \
		NULL \
	}; \
	TC_DYN_RuntimeClass *class_name::GetRuntimeClass0() \
		{ return RUNTIME_CLASS(class_name); } \
	TC_DYN_RuntimeClass *class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }


/**
 * 保存 tars 服务的基本型信息，提供给指定服务的  ServiceFactory 类调用
 * 和 ConfigHolder 自动加载类是独立分开的，这个类只 解析存储 tars-config.conf 配置文件
 */

/* Obj 类的配置文件 */
class TarsObjectConfig {
public:
	static const int DEFAULT_TIME_OUT = 500;
	TarsObjectConfig();
	TarsObjectConfig &parse(const std::map<string, std::string> & confMap, const std::string &setName, int timeOut);
	std::string objName;
	std::string setName;
	int timeOut;
};

class TarsObjectConfigHolder : public tars::TC_AutoPtr {
public:
	TarsObjectConfigHolder();
	void parse(tars::TC_Config &conf);
	void getConfig(const std::string &name, const std::string &defObjName, std::string &objName, std::string &setName, int &timeOut);
	template <typename T>
	T getProxy(const std::string &name, const std::string &defObjName = "") {
		int timeOut = 0;
		string setName, objName;
		getConfig(name, defObjName, objName, setName, timeOut);
		T proxy;
		try {
			proxy = m_comm->stringToProxy<T>(objName, setName);
		}
		catch (std::exception &ex) {
			cerr << "std::exception: " << ex.what() << std::endl;
		}
		catch (...) {
			cerr << "unknown exception." << std::endl;
		}

		try {
			if (proxy._ptr) {
				proxy->tars_timeout(timeOut);
				proxy->tars_async_timeout(timeOut);
			}
		}
		catch (std::exception &ex) {
			cerr << "std::exception: " << ex.what() << std::endl;
		}
		catch (...) {
			cerr << "unknown exception." << std::endl;
		}
		return proxy;
	}


private:
	TarsObjectConfig m_defConf;
	std::map<std::string, TarsObjectConfig> m_confMap;
	tars::CommunicatorPtr m_comm;
	
};


class ConfigHolder : public tars::TC_DYN_Object {
public:
	virtual ~ConfigHolder(){

	}
	virtual bool reload(std::string configName="*"){
		if(configName=="*" || configName==_configName){
			return reloadImp();
		}
		else{
			return true;
		}
	}
	virtual bool reloadImp() = 0;
	// virtual std::string toString()=0; // for check the config state
protected:
	std::string _configName;
	friend class ConfigHolderFactory; // 需要访问 _configName 以便拉取到配置文件到本地
};

class ConfigHolderFactory {
	ConfigHolderFactory();
	~ConfigHolderFactory();
	static std::map<std::string, ConfigHolder *> CFG_HOLDERS;
	static tars::TC_AutoPtr<TarsObjectConfigHolder> TARS_CFG_HOLDER;
	static tars::Application *app;
public:
	static void Initialize(tars::Application &application);
	static void Destory();
	static bool reloadConfig(std::string command="*"); // 自动加载 自己实现的 ConfigHolder 结尾的 继承自 ConfigHolder 的配置类
	static bool reloadTarsObjectConfig();  // 加载 tars-config.conf 配置文件中 定义的 其他服务的 Object， 这个类非自动加载类。 
	
	template<typename CfgHolder>
	// 保存在函数的内部变量中，避免查找
	static const CfgHolder *getCfgHolder(){
		static const CfgHolder * _holder = getCfgHolderFromMap<CfgHolder>();
		return _holder;
	}
	static tars::TC_AutoPtr<TarsObjectConfigHolder> getTarsCfgHolder();


	template<typename CfgHolder>
	static const CfgHolder *getCfgHolderFromMap() {
		std::map<std::string, ConfigHolder*>::const_iterator iter = CFG_HOLDERS.find(CfgHolder::GetRuntimeClass0()->m_lpszClassName);  // 根据 类名字(继承自 ConfigHolder，类名字以 ConfigHolder 结尾)
		return iter != CFG_HOLDERS.end() ? dynamic_cast<const CfgHolder *>(iter->second) : NULL;
	}
};
	

#endif
