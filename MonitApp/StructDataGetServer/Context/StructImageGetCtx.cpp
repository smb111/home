#include "StructImageGetCtx.h"

using namespace std;
using namespace MonitApp;
using namespace tars;

StructImageGetCtx::StructImageGetCtx(const MonitApp::GetImageListReq &req, tars::TarsCurrentPtr &current) : BasicContext(current),
	getImageListReq(req),
	m_imageVec(std::vector<ImageInfo>())
{
	
}

StructImageGetCtx::~StructImageGetCtx() {
	
}


