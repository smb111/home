/*
 * StructDataGetServerConfigHolder.h
 *
 * Creat on : 2019年1月18号
 *   Author : smbzhang
 */

#ifndef STRUCTDATAGETSERVERCONFIGHOLDER_H_
#define STRUCTDATAGETSERVERCONFIGHOLDER_H_

#include "ConfigHolder.h"
#include "servant/Application.h"
#include <string>
#include "StructDataGet.h"
#include "/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder/ConfigHolder.h"

class StructDataGetServerConfigHolder : public ConfigHolder {
	DECLARE_CONFHOLDER_DYNCREATE(StructDataGetServerConfigHolder)
public:
	StructDataGetServerConfigHolder() {
		this->_configName = "StructDataGetServer.conf";
	}
	virtual bool reloadImp();

	std::string host_ip;
};

#endif

