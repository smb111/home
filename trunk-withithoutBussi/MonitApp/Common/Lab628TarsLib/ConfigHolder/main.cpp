#include "ConfigHolder.h"
#include <iostream>

using namespace std;
using namespace tars;

class MyConfigHolder : public ConfigHolder {
DECLARE_CONFHOLDER_DYNCREATE(MyConfigHolder)
public:
	std::string name;

	MyConfigHolder() {
		this->_configName = "config Name";
	}

	virtual bool reloadImp()
	{
		return true;
	}
};

IMPLEMENT_CONFHOLDER_DYNCREATE(MyConfigHolder, TC_DYN_Object)

class MyApp : public tars::Application {
public:
	virtual void initialize(){}
	virtual void destroyApp(){}
};

int main()
{
	MyApp app;
	ConfigHolderFactory::Initialize(app);
	const MyConfigHolder *cfg = ConfigHolderFactory::getCfgHolder<MyConfigHolder>();



	return 0;
}
