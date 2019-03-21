/**
 * DBServerLogic.cpp
 *
 * Created on: 2019年1月23号
 *     Author: smbzhang
 */
#include "DBServerLogic.h"
#include "ServiceFactory.h"
#include <exception>
#include <vector>

using namespace std;
using namespace tars;
using namespace MonitApp;

DBServerLogic::DBServerLogic() {

}

DBServerLogic::~DBServerLogic() {
	
}

promise::Futrue<vector<ImageInfo> > getImageListParallel(tars::TC_AutoPtr<StructImageGetCtx> ctx) {
	try {
		return ServiceFactory::getDataBasePrx()->promise_async_getDBImage(ctx->getImageListReq, TARS_CONTEXT()).then(bind(&handleImageList, ctx));
	} catch(const std::exception &ex) {
		TLOGERROR("DBServerLogic::getImageListParallel failed : " << ex.what() << endl);
	} catch(...) {
		TLOGERROR("Unkown error in DBServerLogic !" << std::endl);	
	}
	return makeFuture<vector<ImageInfo> > (vector<ImageInfo>());
}

promise::Futrue<vector<ImageInfo> > handleImageList(tars::TC_AutoPtr<StructImageGetCtx> ctx, \
		const promise::Futrue<DataBasePrxCallbackPromise::PromisegetDBImagePtr> &dbImageF) {
	try {
		DataBasePrxCallbackPromise::PromisegetDBImagePtr dbImageFv = dbImageF.get();
		std::vector<ImageInfo> imagesListResp = dbImageFv.resp.images;
		int ret = dbImageFv._ret;
		// 将 DBServer 请求返回的 图片数据 填入 ctx 中
		if (ret == 0 && imageListResp.size() > 0) {
			for (int i = 0; i < imageListResp.size(); ++i) {
				ctx->m_imageVec.push_back(imageListResp[i]);
			}
		}
	} catch(const std::exception &ex) {
		TLOGERROR("DBServerLogic::handleImageList failed : " << ex.what() << endl);
	} catch(...) {
		TLOGERROR("Unkown error in DBServerLogic !" << std::endl);
	}
	return makeFuture<vector<ImageInfo> > (vector<ImageInfo>());
}

