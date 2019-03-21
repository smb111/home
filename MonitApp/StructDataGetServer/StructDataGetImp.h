#ifndef _StructDataGetImp_H_
#define _StructDataGetImp_H_

#include "StructDataGet.h"
#include "servant/Application.h"
#include <vector>
#include <string>
#include "StructDataGetServerConfigHolder.h"
#include "StructImageGetCtx.h"
#include "PriorityLogic.h"
#include "util/tc_autoptr.h"

using namespace std;
using namespace tars;

/**
 *
 *
 */
class StructDataGetImp : public MonitApp::StructDataGet
{
public:
    /**
     *
     */
    virtual ~StructDataGetImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;};
	
	/**
	 * 获取图像的接口， 根据传入的 sql 查询语句 需要的内容结构体 GetImageListReq, 查询数据库，并且填充 resp
	 */
	virtual int getImage(const MonitApp::GetImageListReq & req, MonitApp::GetImageListRsp &resp, tars::TarsCurrentPtr
					 current)
	{
		// 调用 主逻辑的 静态异步调用 方法 PriorityLogic::async_getStructImage
		tars::TC_AutoPtr<StructImageGetCtx> structImageGetCtxPtr = new StructImageGetCtx(req, current);
		PriorityLogic::async_getStructImage(structImageGetCtxPtr);

		TLOGDEBUG("MonitApp::GetImageListReq req : "  << req.dateStart <<endl << req.dateEnd << endl << req.idStart << endl << req.idEnd << endl);
		for (int i = 0; i < 3; i++)
		{
			std::string image = "image";
			char num = '0' + i;
			image += num;
			MonitApp::ImageType imageType = MonitApp::PNG;

			MonitApp::ImageInfo imageInfo;
			imageInfo.content = image;
			imageInfo.imageType = imageType;
			
			resp.images.push_back(imageInfo);
		}
		return 6;
	}
};
/////////////////////////////////////////////////////
#endif

