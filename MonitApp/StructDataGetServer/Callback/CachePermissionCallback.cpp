/**
 * CachePermissionCallback.cpp
 *
 * Created on: 2019年1月22号
 *     Author: smbzhang
 */

#include "Cache.h"
#include "promise/promise.h"
#include <iostream>

using namespace tars;
using namespace std;

CachePermissionCallback::CachePermissionCallback() {

}
1
CachePermissionCallback::~CachePermissionCallback() {

}

void CachePermissionCallback::callback_getPermission(tars::Int32 ret, tars::Bool permission) {
	if (ret == 0) {
		bool stPermission = permission;

		this->m_promise.setValue(stPermission);
	} else {
		callback_getPermission_exception(ret);
	}
}

void CachePermissionCallback::callback_getPermission_exception(tars::Int32 ret) {
	TLOGDEBUG("getPermission catch exception ret: " << ret << std::endl);

	bool stPermission = false;
	this->m_promise.setValue(stPermission);
}

promise::Promise<bool> getFuture() {
	return this->m_promise.getFuture();
}

