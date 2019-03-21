#include <iostream>
#include "servant/Communicator.h"
#include "StructDataGet.h"

using namespace std;
using namespace tars;
using namespace MonitApp;

#define __TRY__ \
try {

#define __CATCH_EXCEPTION__ \
} \
catch (exception &ex) \
{ \
	cerr << "ex:" << ex.what() << endl; \
} \
catch(...) \
{ \
	cerr << "unknown exception." << endl; \
}

int main(int argc, char *argv[])
{
	Communicator comm;
	__TRY__
	
	MonitApp::GetImageListReq req;
	MonitApp::GetImageListRsp resp;
	std::string dateStart = "2017-11-27 20:32:35";
	std::string dateEnd = "2017-11-29 20:39:00";
	int idStart = 1;
	int idEnd = 500;
	StructDataGetPrx getImagePrx;
	comm.stringToProxy("MonitApp.StructDataGetServer.StructDataGetObj@tcp -h 10.20.4.111 -t 60000 -p 10010", getImagePrx);

	__TRY__

	req.idStart = idStart;
	req.idEnd = idEnd;
	req.dateStart = dateStart;
	req.dateEnd = dateEnd;
	int iRet = getImagePrx->getImage(req, resp);
	cout << "iRet: " << iRet << endl;
	for (int i = 0; i < resp.images.size(); i++)
	{
		cout << "No." << i+1 << " : " << resp.images[i].content << " Type : "  << resp.images[i].imageType << endl;	
	}
	__CATCH_EXCEPTION__

	__CATCH_EXCEPTION__


	return 0;
}
