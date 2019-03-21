/**
 * CacheServerLogic.cpp 
 *
 * Created on: 2019年1月21号
 *     Author: smbzhang
 */

#include "CacheServerLogic.h"
#include <exception>
#include "ServiceFactory.h"
#include "CachePermissionCallback.h"

using namespace std;
using namespace tars;
using namespace MonitApp;
using namespace promise;

CacheServerLogic::CacheServerLogic() {
}

CacheServerLogic::~CacheServerLogic() {
}

promise::Future<bool> CacheServerLogic::getPermissionFromCacheParallel(tars::TC_AutoPtr<StructImageGetCtx> ctx) {
	try {
		// 因为设计请求结构体的时候 没有 加入 请求的用户名， 所以这里直接使用 dateStart 作为用户名
		return ServiceFactory::getCachePrx()->promise_async_getPermission(ctx->getImageListReq.dateStart， TARS_CONTEXT()).then(bind(&handleCachePermission, ctx));
	}catch (const std::exception &ex) {
		TLOGERROR("CacheServerLogic::getPermissionFromCacheParallel failed : " << ex.what() << endl);
	}catch (...) {
		TLOGERROR("Unkown error in CacheServerLogic !" << std::endl);
	}
	return makeFuture<bool>(false);
}


promise::Future<bool> CacheServerLogic::handleCachePermission(tars::TC_AutoPtr<StructImageGetCtx> ctx, const promise::Future<CachePrxCallbackPromise::PromisegetPermissionPtr> &cacheF)
{
	try 
		CachePrxCallbackPromise::PromisegetPermissionPtr cacheFv = cacheF.get();
		bool permission = cacheFv->permission; // 并行结构的话 应该将拿到的 permission 放入 ctx 中进行传递
		int ret = cacheFv->_ret;
		// return makeFuture<int>(permission); 返回请求的结果 0 | 1
		TLOGDEBUG("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << permisiion << "	" << ret << endl);
	}catch (const std::exception &ex) {
		TLOGERROR("CacheServerLogic::handleCachePermission failed : " << ex.what() << endl);
	}catch (...) {
		TLOGERROR("Unkown error in CacheServerLogic::handleCachePermission !" << std::endl);
	}
	return makeFuture<bool>(false);  // 如果出错的话 返回 -1 非 0 非 -1

	/**
	 * 其实这个函数里面返回什么没什么关系，因为这是一个 并行异步调用接口， 它的返回结果并不会影响其他服务的异步调用
	 */
}

promise::Future<bool> CacheServerLogic::getPermissionFromCache(tars::TC_AutoPtr<StructImageGetCtx> ctx) {
	try {
		CachePrxCallbackPtr cb = new CachePermissionCallback();
		ServiceFactory::getCachePrx()->async_getPermission(cb, ctx->getImageListReq.dateStart);
		return (CachePermissionCallback *)(cb._ptr)->getFuture();
	}catch (const std::exception &ex) {
		TLOGERROR("CacheServerLogic::getPermissionFromCacheSerial failed : " << ex.what() << endl);
	}catch (...) {
		TLOGERROR("Unkown error in CacheServerLogic !" << std::endl);
	}
	return makeFuture<bool>(false);
}
