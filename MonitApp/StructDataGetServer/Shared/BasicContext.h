/*
 * BasicContext.h
 *
 * Created on: 2019年1月18日
 * 	   Author: smbzhang
 */

#ifndef BASICCONTEXT_H_
#define BASICCONTEXT_H_

#include <sstream>
#include "servant/Global.h"
#include "util/tc_autoptr.h"
#include "util/tc_timeprovider.h"

/**
 * 这个类 只存储数据， 作为基类
 */
// 非线程安全
class BasicContext : public tars::TC_HandleBase
{
public:
	BasicContext(tars::TarsCurrentPtr &current);
	virtual ~BasicContext();

public:
	virtual int getCostTimeMs();
	virtual int getNow();
// 	virtual bool isNeedLog(const char * func);
	virtual ostream &getLogger();

public:
	tars::TarsCurrentPtr m_current;

protected:
	timeval m_startTime;

private:
	bool m_bNeedLog;
	std::stringstream m_logger;
	
}

#endif
