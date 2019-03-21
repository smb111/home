#ifndef _CacheImp_H_
#define _CacheImp_H_

#include "servant/Application.h"
#include "Cache.h"
#include <string>

using namespace MonitApp;
using namespace std;

/**
 *
 *
 */
class CacheImp : public MonitApp::Cache
{
public:
    /**
     *
     */
    virtual ~CacheImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;};

	/**
	 * 用户权限获取 接口
	 */
	virtual int getPermission(const std::string &name, bool &permission, tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
