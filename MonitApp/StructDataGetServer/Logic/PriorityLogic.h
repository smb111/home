#ifndef PRIORITYLOGIC_H_
#define PRIORITYLOGIC_H_

#include "promise/promise.h"
#include "promise/tuple.h"
#include "StructDataGet.h"
#include "StructImageGetCtx.h"
#include "util/tc_autoptr.h"


class PriorityLogic {
public:
	typedef tars::TC_AutoPtr<StructImageGetCtx> T_StructImageGetCtxPtr;

	PriorityLogic();
	virtual ~PriorityLogic();
	
	// 虽然智能指针都是值传递，但是出作用域都会自动 atomic-1 不用手动释放
	static void async_getStructImage(T_StructImageGetCtxPtr ctx);

private:
	void handle(T_StructImageGetCtxPtr ctx, const promise::Future<promise::Tuple<promise::Future<bool>, promise::Future<vector<ImageInfo> > > > &f)
	void doResp(T_StructImageGetCtxPtr ctx, MonitApp::GetImageListRsp &resp);
};


#endif
