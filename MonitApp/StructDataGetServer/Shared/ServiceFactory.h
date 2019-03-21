/*
 * ServiceFactory.h
 * 
 * Created on: 2015年12月16日
 *     Author: oliverlwang
 */

#ifndef SERVICEFACTORY_H_
#define SERVICEFACTORY_H_

#include "Cache.h"
#include "DataBase.h"
#include "StructDataGet.h"

class ServiceFactory {
public:
	ServiceFactory();
	virtual ~ServiceFactory();
public:
	// 获取其他服务的 proxy 代理类的智能指针对象
	static MonitApp::DataBasePrx       getDataBasePrx();
	static MonitApp::CachePrx          getCachePrx();
	static MonitApp::StructDataGetPrx  getStructDataGetPrx();
};


#endif
