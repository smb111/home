#include "CacheImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void CacheImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void CacheImp::destroy()
{
    //destroy servant here:
    //...
}

int CacheImp::getPermission(const std::string &name, bool &permission, tars::TarsCurrentPtr current)
{
	// step1: judge the name permission from redis
	
	permission = true;

	return 0;
}
