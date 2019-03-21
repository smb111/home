#ifndef _StructDataGetImp_H_
#define _StructDataGetImp_H_

#include "servant/Application.h"
#include "StructDataGet.h"

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
};
/////////////////////////////////////////////////////
#endif
