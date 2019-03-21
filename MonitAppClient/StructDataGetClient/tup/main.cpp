#include <vector>
#include <string>
#include <iostream>
#include "tup/tup.h"
#include "GetImage.h"
#include "util/tc_socket.h"
#include "util/tc_clientsocket.h"

using namespace std;
using namespace tup;


int main(int argc, char *argv[])
{
	TarsUniPacket<> encodePack;
	encodePack.setTarsVersion(3);
	encodePack.setRequestId(1);
	encodePack.setServantName("MonitApp.StructDataGetServer.GetImageObj");
	encodePack.setFuncName("getImage");

	// req
	MonitApp::GetImageListReq req;
	req.dateStart = "2017-11-27 20:32:35";
	req.dateEnd = "2017-11-29 20:39:00";
	req.idStart = 1;
	req.idEnd = 500;
	// put req - struct
	encodePack.put<MonitApp::GetImageListReq>("req", req);
	// resp
	MonitApp::GetImageListRsp resp;
	// put resp - struct  这个 out 参数也可以不 put ， 因为没有效果，需要使用下面指定的函数来进行 out 输出参数的获取 ！
	encodePack.put<MonitApp::GetImageListRsp> ("resp", resp);
	// encode
	std::string buffer = "";
	encodePack.encode(buffer);

	// tcp client - send tars_tup request
	TC_TCPClient client;
	client.init("10.20.4.111",10010, 60000);

	cout << buffer.size() << endl;

	if ( 0 != client.send(buffer.c_str(), buffer.size()) )
		std::cout << "client send failed !" << std::endl;	

	/*
	// tcp client recv tars_tup response
	string recvBuffer;
	if (client.recvAll(recvBuffer) < 0){
		cout << "client recv tars response failed !" << endl;
	}
	// tars_tup decode
	TarsUniPacket<> rsp;
	rsp.decode(recvBuffer.c_str(), recvBuffer.size());
	if (rsp.getTarsResultCode() == 0){
		int ret = rsp.get<int32_t>("");  // 获取 服务接口的返回值
		cout << "The ret value is : " << ret << endl;
		resp = rsp.get<MonitApp::GetImageListRsp>("resp"); // 获取 out 输出参数
	}
	else{
		cout << rsp.getTarsResultDesc() << endl;
	}
	*/

	// tcp client recv tars_tup response
	char* recvBuffer = new char[1024];
	size_t recvLen = 1024;
	if (client.recv(recvBuffer, recvLen) < 0){
		cout << "client recv tars response failed !" << endl;
	}
	// tars_tup decode
	TarsUniPacket<> rsp;
	rsp.decode(recvBuffer, recvLen);
	if (rsp.getTarsResultCode() == 0){
		int ret = rsp.get<int32_t>("");  // 获取 服务接口的返回值
		cout << "The ret value is : " << ret << endl;
		resp = rsp.get<MonitApp::GetImageListRsp>("resp"); // 获取 out 输出参数
	}
	else{
		cout << rsp.getTarsResultDesc() << endl;
	}
	for (int i = 0; i < resp.images.size(); i++){
		cout << "No." << i+1 << " : " << resp.images[i].content << " Type : "  << resp.images[i].imageType << endl;
	}


	return 0;
}
