/**
 * CachePermissionCallback.h
 *
 * Created on: 2019年1月22号
 *     Author: smbzhang
 */

#include "Cache.h"

using namespace tars;

class CachePermissionCallback : public CachePrxCallback {
public:
	CachePermissionCallback();
	virtual ~CachePermissionCallback();

	virtual void callback_getPermission(tars::Int32 ret, tars::Bool permission);
	virtual void callback_getPermission_exception(tars::Int32 ret);

	virtual promise::Future<bool> getFuture();
private:
	promise::Promise<bool> m_promise;
};
