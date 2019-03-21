/*
 * StructImageGetCtx.h
 *
 *  Created on: 2019年1月18日
 *      Author: smbzhang
 */

#ifndef STRUCTIMAGEGETCTX_H_
#define STRUCTIMAGEGETCTX_H_

#include "StructDataGet.h"
#include "BasicContext.h"
#include <vector>
/*
  StructImageGetCtx非线程安全
  Context只存储数据,不做任何逻辑
  在Imp里创建一个AutoPtr传入Logic的static方法,按照调用链一级一级往下传
  eg:
    int Imp() {
		TC_AutoPtr<TestPointer> testPointerPtr;
		XX_Logic1(testPointerPtr);
	}
	//总体逻辑
	static void XX_Logic1(TC_AutoPtr<TestPointer> ptr) {
		//任何方法内都可以直接通过ptr访问上下文数据
        f.then(bind(XX_Logic2, ptr)); 
	}
	static void XX_Logic2(TC_AutoPtr<TestPointer> ptr) {
		//智能指针每次都是值传递,会有参数拷贝,atomic+1
		//退出方法时析构,atomic-1
		//因此不需要手动管理内存
	}
	//异步回包
	static void do_resp(TC_AutoPtr<TestPointer> ptr) {
		MsgPush::async_response_getCmsPushList(ptr->m_current, 0, stRsp);
	}
 */
class StructImageGetCtx : virtual public BasicContext
{
public:
	StructImageGetCtx(const MonitApp::GetImageListReq &req, tars::TarsCurrentPtr &current);

	virtual ~StructImageGetCtx();
	// 不使用 锁， 串行的异步请求，按照调用链向下进行传递 Ctx， 如果是 并行的异步请求，需要在 handle 处理逻辑中，进行加锁， 保护 current 上下文。
public:
	const MonitApp::GetImageListReq getImageListReq;
	std::vector<ImageInfo> m_imageVec;
};

#endif /* STRUCTIMAGEGETCTX_H_ */
