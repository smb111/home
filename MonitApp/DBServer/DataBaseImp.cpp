#include "DataBaseImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void DataBaseImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void DataBaseImp::destroy()
{
    //destroy servant here:
    //...
}


int DataBaseImp::getDBImage(const MonitApp::GetImageListReq &req, MonitApp::GetImageListRsp &resp, tars::TarsCurrentPtr current)
{
	std::map<string, std::pair<TC_Mysql::FT, std::string> > m;
	m["id"] 	= make_pair(TC_Mysql::DB_INT, "5");
	m["name"] 	= make_pair(TC_Mysql::DB_STR, "123dxh");
	mysql.insertRecord("`111`",m);


	return 123;
}

