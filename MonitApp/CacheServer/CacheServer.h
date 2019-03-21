#ifndef _CacheServer_H_
#define _CacheServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class CacheServer : public Application
{
public:
    /**
     *
     **/
    virtual ~CacheServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern CacheServer g_app;

////////////////////////////////////////////
#endif
