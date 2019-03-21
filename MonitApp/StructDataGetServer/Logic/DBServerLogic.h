/**
 * DBServerLogic.h
 *
 * Created on: 2019年1月22号
 *     Author: smbzhang
 */

#ifndef DBSERVERLOGIC_H_
#define DBSERVERLOGIC_H_

#include "DBServer.h"
#include "promise/promise.h"
#include "StructImageGetCtx.h"
#include "promise/tuple.h"
#include "imageInfo.h"
#include <vector>


using namespace std;
using namespace tars;
using namespace MonitApp;

class DBServerLogic {
public:
	DBServerLogic();
	virtual ~DBServerLogic();

	static promise::Futrue<vector<ImageInfo> > getImageListParallel(tars::TC_AutoPtr<StructImageGetCtx> ctx);
	static promise::Futrue<vector<ImageInfo> > handleImageList(tars::TC_AutoPtr<StructImageGetCtx> ctx, \ 
			const promise::Futrue<DataBasePrxCallbackPromise::PromisegetDBImagePtr> &dbImageF);

};

#endif
