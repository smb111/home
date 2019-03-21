/**
 * CacheServerLogic.h
 *
 * Created on: 2019年1月21号
 *     Author: smbzhang
 */

#ifndef CACHESERVERLOGIC_H_
#define CACHESERVERLOGIC_H_

#include "Cache.h"
#include "promise/promis.h"
#include "StructImageGetCtx.h"
#include "promise/tuple.h"

using namespace MonitApp;
using namespace tars;

class CacheServerLogic {
public:
	CacheServerLogic();
	virtual ~CacheServerLogic();
	// 这里是 并行的接口， 一般并行请求的时候，都会把请求到的数据放入， ctx 中， 也就是
	// 在 handle 处理函数中  向 ctx 中填入返回的结果，最后返回一个 默认初始化的相应 Futrue
	// 供 PriorityLogic.cpp 中的 whenall 函数使用 ！！！
	static promise::Future<bool> getPermissionFromCacheParallel(tars::TC_AutoPtr<StructImageGetCtx> ctx);
	// typedef tars::TC_AutoPtr< CachePrxCallbackPromise::PromisegetPermission > PromisegetPermissionPtr;
	static promise::Future<bool> handleCachePermission(tars::TC_AutoPtr<StructImageGetCtx> ctx, const promise::Future<CachePrxCallbackPromise::PromisegetPermissionPtr> &cacheF);
	
	// 下面是 tars 框架没有支持， promise_async 的接口自动生成的时候，Tencent MIG 部门自己实现的，所以功能和框架自动生成的 promise_async_getPermission 函数是一样的。 相应的 Callback 函数也是被 tars 框架集成了。我们可以直接 集成相应的 promise Callback 函数
	promise::Futrue<bool> getPermissionFromCache(tars::TC_AutoPtr<StructImageGetCtx> ctx);


};

#endif
