#ifndef _DataBaseImp_H_
#define _DataBaseImp_H_

#include "servant/Application.h"
#include "DataBase.h"
#include <vector>
#include <string>
#include "util/tc_mysql.h"
#include <map>
extern TC_Mysql mysql;

using namespace std;

/**
 *
 *
 */
class DataBaseImp : public MonitApp::DataBase
{
public:
    /**
     *
     */
    virtual ~DataBaseImp() {}

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

	/*
	 * 从数据库查询符合条件的 图像返回给调用者 
	 */
	int getDBImage(const MonitApp::GetImageListReq &req, MonitApp::GetImageListRsp &resp, tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
