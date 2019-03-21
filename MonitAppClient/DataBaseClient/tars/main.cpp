#include <iostream>
#include "servant/Communicator.h"
#include "DataBase.h"

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

	tars::TC_AutoPtr<MonitApp::DataBaseProxy> dataBasePrx;
	comm.stringToProxy("MonitApp.DBServer.DataBaseObj@tcp -h 10.20.4.111 -t 60000 -p 10011", dataBasePrx);

	__TRY__
	
	req.idStart = idStart;
	req.idEnd = idEnd;
	req.dateStart = dateStart;
	req.dateEnd = dateEnd;
	int iRet = dataBasePrx->getDBImage(req, resp);
	cout << "iRet: " << iRet << endl;

	__CATCH_EXCEPTION__

	__CATCH_EXCEPTION__
	
	return 0;
}

