#ifndef _StructDataGetServer_H_
#define _StructDataGetServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class StructDataGetServer : public Application
{
public:
    /**
     *
     **/
    virtual ~StructDataGetServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern StructDataGetServer g_app;

////////////////////////////////////////////
#endif
