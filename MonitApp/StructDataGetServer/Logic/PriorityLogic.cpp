#include "PriorityLogic.h"
#include "../StructDataGet.h"
#include "CacheServerLogic.h"
#include "DBServerLogic.h"

using namespace std;
using namespace tars;
using namespace MonitApp;

void PriorityLogic::async_getStructImage(T_StructImageGetCtxPtr ctx)
{
	const MonitApp::GetImageListReq getImageListReq = ctx->getImageListReq;
	// 获取 结构化图片的接口， 涉及两个其他服务的请求， 数据库 DBServer 和 缓存服务 CacheServer
	// 因为 我在缓存服务里面 设计了，用户权限的接口， 这里采用串行的异步访问方式，先进行 CacheServer 的访问， 
	// 根据返回的结构，在进行 数据库 服务的访问。  
	
	// step1. 设置 异步回包 方式  ==> 也就是 设置不自动进行回包， 执行我们自己的 do_resp() 回包
	ctx->current->setResponse(false); 
	/* 下面是 并行的异步请求， 注意保护 ctx， 因为它是非线程安全的 */
	// step2. 从 Logic 文件夹中 选取对应的 Server Logic 进行异步请求接口的调用
	promise::Future<bool> permission_f = CacheServerLogic::getPermissionFromCacheParallel(ctx);
	promise::Future<vector<ImageInfo> > imageList_f = DBServerLogic::getImageListParallel(ctx);

	whenAll(permission_f, imageList_f).then(bind());


	/* 下面是串行的异步， 因为 ctx 会一直往下传递， 所以不用对 ctx 进行加锁保护*/
	// promise::Future<bool> permission_f CacheServerLogic::getPermissionFromCacheSerial(ctx);
	// permission_f
}

// 这个是 Cache 和 DB 两个服务的并行异步请求返回处理函数
void PriorityLogic::handle(T_StructImageGetCtxPtr ctx, const promise::Future<promise::Tuple<promise::Future<bool>, promise::Future<vector<ImageInfo> > > > &f) {
	bool permission = f.get().get<0>().get();
	vector<ImageInfo> imageInfoVec = f.get().get<1>().get();
    
	MonitApp::GetImageListRsp resp;
	for (int i = 0; i < ctx->m_imageVec.size(); i++) {
		resp.images.push_back(ctx->m_imageVec[i]);
	}
	doResp(ctx, resp);
}

void PriorityLogic::doResp(T_StructImageGetCtxPtr ctx, MonitApp::GetImageListRsp &resp) {
	MonitApp::async_response_getImage(ctx->m_current, 0, resp);
}
//  static void async_response_getImage(tars::TarsCurrentPtr current, tars::Int32 _ret, const MonitApp::GetImageListRsp &r
