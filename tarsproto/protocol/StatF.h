// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 1.1.0.
// **********************************************************************

#ifndef __STATF_H_
#define __STATF_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"


namespace tars
{
    struct StatMicMsgHead : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "tars.StatMicMsgHead";
        }
        static string MD5()
        {
            return "0128910389fa508b176d044a2aaa8a12";
        }
        StatMicMsgHead()
        :masterName(""),slaveName(""),interfaceName(""),masterIp(""),slaveIp(""),slavePort(0),returnValue(0),slaveSetName(""),slaveSetArea(""),slaveSetID(""),tarsVersion("")
        {
        }
        void resetDefautlt()
        {
            masterName = "";
            slaveName = "";
            interfaceName = "";
            masterIp = "";
            slaveIp = "";
            slavePort = 0;
            returnValue = 0;
            slaveSetName = "";
            slaveSetArea = "";
            slaveSetID = "";
            tarsVersion = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(masterName, 0);
            _os.write(slaveName, 1);
            _os.write(interfaceName, 2);
            _os.write(masterIp, 3);
            _os.write(slaveIp, 4);
            _os.write(slavePort, 5);
            _os.write(returnValue, 6);
            if (slaveSetName != "")
            {
                _os.write(slaveSetName, 7);
            }
            if (slaveSetArea != "")
            {
                _os.write(slaveSetArea, 8);
            }
            if (slaveSetID != "")
            {
                _os.write(slaveSetID, 9);
            }
            if (tarsVersion != "")
            {
                _os.write(tarsVersion, 10);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(masterName, 0, true);
            _is.read(slaveName, 1, true);
            _is.read(interfaceName, 2, true);
            _is.read(masterIp, 3, true);
            _is.read(slaveIp, 4, true);
            _is.read(slavePort, 5, true);
            _is.read(returnValue, 6, true);
            _is.read(slaveSetName, 7, false);
            _is.read(slaveSetArea, 8, false);
            _is.read(slaveSetID, 9, false);
            _is.read(tarsVersion, 10, false);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(masterName,"masterName");
            _ds.display(slaveName,"slaveName");
            _ds.display(interfaceName,"interfaceName");
            _ds.display(masterIp,"masterIp");
            _ds.display(slaveIp,"slaveIp");
            _ds.display(slavePort,"slavePort");
            _ds.display(returnValue,"returnValue");
            _ds.display(slaveSetName,"slaveSetName");
            _ds.display(slaveSetArea,"slaveSetArea");
            _ds.display(slaveSetID,"slaveSetID");
            _ds.display(tarsVersion,"tarsVersion");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(masterName, true);
            _ds.displaySimple(slaveName, true);
            _ds.displaySimple(interfaceName, true);
            _ds.displaySimple(masterIp, true);
            _ds.displaySimple(slaveIp, true);
            _ds.displaySimple(slavePort, true);
            _ds.displaySimple(returnValue, true);
            _ds.displaySimple(slaveSetName, true);
            _ds.displaySimple(slaveSetArea, true);
            _ds.displaySimple(slaveSetID, true);
            _ds.displaySimple(tarsVersion, false);
            return _os;
        }
    public:
        std::string masterName;
        std::string slaveName;
        std::string interfaceName;
        std::string masterIp;
        std::string slaveIp;
        tars::Int32 slavePort;
        tars::Int32 returnValue;
        std::string slaveSetName;
        std::string slaveSetArea;
        std::string slaveSetID;
        std::string tarsVersion;
    };
    inline bool operator==(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        return l.masterName == r.masterName && l.slaveName == r.slaveName && l.interfaceName == r.interfaceName && l.masterIp == r.masterIp && l.slaveIp == r.slaveIp && l.slavePort == r.slavePort && l.returnValue == r.returnValue && l.slaveSetName == r.slaveSetName && l.slaveSetArea == r.slaveSetArea && l.slaveSetID == r.slaveSetID && l.tarsVersion == r.tarsVersion;
    }
    inline bool operator!=(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        return !(l == r);
    }
    inline bool operator<(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        if(l.masterName != r.masterName)  return (l.masterName < r.masterName);
        if(l.slaveName != r.slaveName)  return (l.slaveName < r.slaveName);
        if(l.interfaceName != r.interfaceName)  return (l.interfaceName < r.interfaceName);
        if(l.masterIp != r.masterIp)  return (l.masterIp < r.masterIp);
        if(l.slaveIp != r.slaveIp)  return (l.slaveIp < r.slaveIp);
        if(l.slavePort != r.slavePort)  return (l.slavePort < r.slavePort);
        if(l.returnValue != r.returnValue)  return (l.returnValue < r.returnValue);
        if(l.slaveSetName != r.slaveSetName)  return (l.slaveSetName < r.slaveSetName);
        if(l.slaveSetArea != r.slaveSetArea)  return (l.slaveSetArea < r.slaveSetArea);
        if(l.slaveSetID != r.slaveSetID)  return (l.slaveSetID < r.slaveSetID);
        if(l.tarsVersion != r.tarsVersion)  return (l.tarsVersion < r.tarsVersion);
        return false;
    }
    inline bool operator<=(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        return !(r < l);
    }
    inline bool operator>(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        return r < l;
    }
    inline bool operator>=(const StatMicMsgHead&l, const StatMicMsgHead&r)
    {
        return !(l < r);
    }

    struct StatMicMsgBody : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "tars.StatMicMsgBody";
        }
        static string MD5()
        {
            return "8de4fb59ea3ed2b2697672a500533d67";
        }
        StatMicMsgBody()
        :count(0),timeoutCount(0),execCount(0),totalRspTime(0),maxRspTime(0),minRspTime(0)
        {
        }
        void resetDefautlt()
        {
            count = 0;
            timeoutCount = 0;
            execCount = 0;
            totalRspTime = 0;
            maxRspTime = 0;
            minRspTime = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(count, 0);
            _os.write(timeoutCount, 1);
            _os.write(execCount, 2);
            _os.write(intervalCount, 3);
            _os.write(totalRspTime, 4);
            _os.write(maxRspTime, 5);
            _os.write(minRspTime, 6);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(count, 0, true);
            _is.read(timeoutCount, 1, true);
            _is.read(execCount, 2, true);
            _is.read(intervalCount, 3, true);
            _is.read(totalRspTime, 4, true);
            _is.read(maxRspTime, 5, true);
            _is.read(minRspTime, 6, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(count,"count");
            _ds.display(timeoutCount,"timeoutCount");
            _ds.display(execCount,"execCount");
            _ds.display(intervalCount,"intervalCount");
            _ds.display(totalRspTime,"totalRspTime");
            _ds.display(maxRspTime,"maxRspTime");
            _ds.display(minRspTime,"minRspTime");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(count, true);
            _ds.displaySimple(timeoutCount, true);
            _ds.displaySimple(execCount, true);
            _ds.displaySimple(intervalCount, true);
            _ds.displaySimple(totalRspTime, true);
            _ds.displaySimple(maxRspTime, true);
            _ds.displaySimple(minRspTime, false);
            return _os;
        }
    public:
        tars::Int32 count;
        tars::Int32 timeoutCount;
        tars::Int32 execCount;
        map<tars::Int32, tars::Int32> intervalCount;
        tars::Int64 totalRspTime;
        tars::Int32 maxRspTime;
        tars::Int32 minRspTime;
    };
    inline bool operator==(const StatMicMsgBody&l, const StatMicMsgBody&r)
    {
        return l.count == r.count && l.timeoutCount == r.timeoutCount && l.execCount == r.execCount && l.intervalCount == r.intervalCount && l.totalRspTime == r.totalRspTime && l.maxRspTime == r.maxRspTime && l.minRspTime == r.minRspTime;
    }
    inline bool operator!=(const StatMicMsgBody&l, const StatMicMsgBody&r)
    {
        return !(l == r);
    }

    struct StatSampleMsg : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "tars.StatSampleMsg";
        }
        static string MD5()
        {
            return "974f999adca923a94a5e3b4d770e9b97";
        }
        StatSampleMsg()
        :unid(""),masterName(""),slaveName(""),interfaceName(""),masterIp(""),slaveIp(""),depth(0),width(0),parentWidth(0)
        {
        }
        void resetDefautlt()
        {
            unid = "";
            masterName = "";
            slaveName = "";
            interfaceName = "";
            masterIp = "";
            slaveIp = "";
            depth = 0;
            width = 0;
            parentWidth = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(unid, 0);
            _os.write(masterName, 1);
            _os.write(slaveName, 2);
            _os.write(interfaceName, 3);
            _os.write(masterIp, 4);
            _os.write(slaveIp, 5);
            _os.write(depth, 6);
            _os.write(width, 7);
            _os.write(parentWidth, 8);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(unid, 0, true);
            _is.read(masterName, 1, true);
            _is.read(slaveName, 2, true);
            _is.read(interfaceName, 3, true);
            _is.read(masterIp, 4, true);
            _is.read(slaveIp, 5, true);
            _is.read(depth, 6, true);
            _is.read(width, 7, true);
            _is.read(parentWidth, 8, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(unid,"unid");
            _ds.display(masterName,"masterName");
            _ds.display(slaveName,"slaveName");
            _ds.display(interfaceName,"interfaceName");
            _ds.display(masterIp,"masterIp");
            _ds.display(slaveIp,"slaveIp");
            _ds.display(depth,"depth");
            _ds.display(width,"width");
            _ds.display(parentWidth,"parentWidth");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(unid, true);
            _ds.displaySimple(masterName, true);
            _ds.displaySimple(slaveName, true);
            _ds.displaySimple(interfaceName, true);
            _ds.displaySimple(masterIp, true);
            _ds.displaySimple(slaveIp, true);
            _ds.displaySimple(depth, true);
            _ds.displaySimple(width, true);
            _ds.displaySimple(parentWidth, false);
            return _os;
        }
    public:
        std::string unid;
        std::string masterName;
        std::string slaveName;
        std::string interfaceName;
        std::string masterIp;
        std::string slaveIp;
        tars::Int32 depth;
        tars::Int32 width;
        tars::Int32 parentWidth;
    };
    inline bool operator==(const StatSampleMsg&l, const StatSampleMsg&r)
    {
        return l.unid == r.unid && l.masterName == r.masterName && l.slaveName == r.slaveName && l.interfaceName == r.interfaceName && l.masterIp == r.masterIp && l.slaveIp == r.slaveIp && l.depth == r.depth && l.width == r.width && l.parentWidth == r.parentWidth;
    }
    inline bool operator!=(const StatSampleMsg&l, const StatSampleMsg&r)
    {
        return !(l == r);
    }

    struct ProxyInfo : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "tars.ProxyInfo";
        }
        static string MD5()
        {
            return "e2c4c8305a9075ebd29458f561b1f204";
        }
        ProxyInfo()
        :bFromClient(true)
        {
        }
        void resetDefautlt()
        {
            bFromClient = true;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(bFromClient, 0);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(bFromClient, 0, true);
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(bFromClient,"bFromClient");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(bFromClient, false);
            return _os;
        }
    public:
        tars::Bool bFromClient;
    };
    inline bool operator==(const ProxyInfo&l, const ProxyInfo&r)
    {
        return l.bFromClient == r.bFromClient;
    }
    inline bool operator!=(const ProxyInfo&l, const ProxyInfo&r)
    {
        return !(l == r);
    }


    /* callback of async proxy for client */
    class StatFPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~StatFPrxCallback(){}
        virtual void callback_reportMicMsg(tars::Int32 ret)
        { throw std::runtime_error("callback_reportMicMsg() override incorrect."); }
        virtual void callback_reportMicMsg_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_reportMicMsg_exception() override incorrect."); }

        virtual void callback_reportSampleMsg(tars::Int32 ret)
        { throw std::runtime_error("callback_reportSampleMsg() override incorrect."); }
        virtual void callback_reportSampleMsg_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_reportSampleMsg_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __StatF_all[]=
            {
                "reportMicMsg",
                "reportSampleMsg"
            };
            pair<string*, string*> r = equal_range(__StatF_all, __StatF_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __StatF_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportMicMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response.context);

                    callback_reportMicMsg(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportSampleMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response.context);

                    callback_reportSampleMsg(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<StatFPrxCallback> StatFPrxCallbackPtr;

    /* callback of promise async proxy for client */
    class StatFPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~StatFPrxCallbackPromise(){}
    public:
        struct PromisereportMicMsg: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< StatFPrxCallbackPromise::PromisereportMicMsg > PromisereportMicMsgPtr;

        StatFPrxCallbackPromise(const promise::Promise< StatFPrxCallbackPromise::PromisereportMicMsgPtr > &promise)
        : _promise_reportMicMsg(promise)
        {}
        
        virtual void callback_reportMicMsg(const StatFPrxCallbackPromise::PromisereportMicMsgPtr &ptr)
        {
            _promise_reportMicMsg.setValue(ptr);
        }
        virtual void callback_reportMicMsg_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:reportMicMsg_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_reportMicMsg.setException(promise::copyException(str, ret));
        }

    protected:
        promise::Promise< StatFPrxCallbackPromise::PromisereportMicMsgPtr > _promise_reportMicMsg;

    public:
        struct PromisereportSampleMsg: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< StatFPrxCallbackPromise::PromisereportSampleMsg > PromisereportSampleMsgPtr;

        StatFPrxCallbackPromise(const promise::Promise< StatFPrxCallbackPromise::PromisereportSampleMsgPtr > &promise)
        : _promise_reportSampleMsg(promise)
        {}
        
        virtual void callback_reportSampleMsg(const StatFPrxCallbackPromise::PromisereportSampleMsgPtr &ptr)
        {
            _promise_reportSampleMsg.setValue(ptr);
        }
        virtual void callback_reportSampleMsg_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:reportSampleMsg_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_reportSampleMsg.setException(promise::copyException(str, ret));
        }

    protected:
        promise::Promise< StatFPrxCallbackPromise::PromisereportSampleMsgPtr > _promise_reportSampleMsg;

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __StatF_all[]=
            {
                "reportMicMsg",
                "reportSampleMsg"
            };

            pair<string*, string*> r = equal_range(__StatF_all, __StatF_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __StatF_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportMicMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);

                    StatFPrxCallbackPromise::PromisereportMicMsgPtr ptr = new StatFPrxCallbackPromise::PromisereportMicMsg();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                    }
                    catch(std::exception &ex)
                    {
                        callback_reportMicMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_reportMicMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response.context;

                    callback_reportMicMsg(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportSampleMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);

                    StatFPrxCallbackPromise::PromisereportSampleMsgPtr ptr = new StatFPrxCallbackPromise::PromisereportSampleMsg();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                    }
                    catch(std::exception &ex)
                    {
                        callback_reportSampleMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_reportSampleMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response.context;

                    callback_reportSampleMsg(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<StatFPrxCallbackPromise> StatFPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class StatFCoroPrxCallback: public StatFPrxCallback
    {
    public:
        virtual ~StatFCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __StatF_all[]=
            {
                "reportMicMsg",
                "reportSampleMsg"
            };

            pair<string*, string*> r = equal_range(__StatF_all, __StatF_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __StatF_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportMicMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response.context);

                        callback_reportMicMsg(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_reportMicMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_reportMicMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_reportSampleMsg_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response.context);

                        callback_reportSampleMsg(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_reportSampleMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_reportSampleMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<StatFCoroPrxCallback> StatFCoroPrxCallbackPtr;

    /* proxy for client */
    class StatFProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 reportMicMsg(const map<tars::StatMicMsgHead, tars::StatMicMsgBody> & msg,tars::Bool bFromClient,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            _os.write(bFromClient, 2);
            tars::ResponsePacket rep;
            std::map<string, string> _mStatus;
            tars_invoke(tars::TARSNORMAL,"reportMicMsg", _os.getByteBuffer(), context, _mStatus, rep);
            if(pResponseContext)
            {
                *pResponseContext = rep.context;
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep.sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_reportMicMsg(StatFPrxCallbackPtr callback,const map<tars::StatMicMsgHead, tars::StatMicMsgBody> &msg,tars::Bool bFromClient,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            _os.write(bFromClient, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportMicMsg", _os.getByteBuffer(), context, _mStatus, callback);
        }
        
        promise::Future< StatFPrxCallbackPromise::PromisereportMicMsgPtr > promise_async_reportMicMsg(const map<tars::StatMicMsgHead, tars::StatMicMsgBody> &msg,tars::Bool bFromClient,const map<string, string>& context)
        {
            promise::Promise< StatFPrxCallbackPromise::PromisereportMicMsgPtr > promise;
            StatFPrxCallbackPromisePtr callback = new StatFPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            _os.write(bFromClient, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportMicMsg", _os.getByteBuffer(), context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_reportMicMsg(StatFCoroPrxCallbackPtr callback,const map<tars::StatMicMsgHead, tars::StatMicMsgBody> &msg,tars::Bool bFromClient,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            _os.write(bFromClient, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportMicMsg", _os.getByteBuffer(), context, _mStatus, callback, true);
        }

        tars::Int32 reportSampleMsg(const vector<tars::StatSampleMsg> & msg,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            tars::ResponsePacket rep;
            std::map<string, string> _mStatus;
            tars_invoke(tars::TARSNORMAL,"reportSampleMsg", _os.getByteBuffer(), context, _mStatus, rep);
            if(pResponseContext)
            {
                *pResponseContext = rep.context;
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep.sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_reportSampleMsg(StatFPrxCallbackPtr callback,const vector<tars::StatSampleMsg> &msg,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportSampleMsg", _os.getByteBuffer(), context, _mStatus, callback);
        }
        
        promise::Future< StatFPrxCallbackPromise::PromisereportSampleMsgPtr > promise_async_reportSampleMsg(const vector<tars::StatSampleMsg> &msg,const map<string, string>& context)
        {
            promise::Promise< StatFPrxCallbackPromise::PromisereportSampleMsgPtr > promise;
            StatFPrxCallbackPromisePtr callback = new StatFPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportSampleMsg", _os.getByteBuffer(), context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_reportSampleMsg(StatFCoroPrxCallbackPtr callback,const vector<tars::StatSampleMsg> &msg,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(msg, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"reportSampleMsg", _os.getByteBuffer(), context, _mStatus, callback, true);
        }

        StatFProxy* tars_hash(int64_t key)
        {
            return (StatFProxy*)ServantProxy::tars_hash(key);
        }

        StatFProxy* tars_consistent_hash(int64_t key)
        {
            return (StatFProxy*)ServantProxy::tars_consistent_hash(key);
        }

        StatFProxy* tars_set_timeout(int msecond)
        {
            return (StatFProxy*)ServantProxy::tars_set_timeout(msecond);
        }

    };
    typedef tars::TC_AutoPtr<StatFProxy> StatFPrx;

    /* servant for server */
    class StatF : public tars::Servant
    {
    public:
        virtual ~StatF(){}
        virtual tars::Int32 reportMicMsg(const map<tars::StatMicMsgHead, tars::StatMicMsgBody> & msg,tars::Bool bFromClient,tars::TarsCurrentPtr current) = 0;
        static void async_response_reportMicMsg(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriter> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

        virtual tars::Int32 reportSampleMsg(const vector<tars::StatSampleMsg> & msg,tars::TarsCurrentPtr current) = 0;
        static void async_response_reportSampleMsg(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriter> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __tars__StatF_all[]=
            {
                "reportMicMsg",
                "reportSampleMsg"
            };

            pair<string*, string*> r = equal_range(__tars__StatF_all, __tars__StatF_all+2, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __tars__StatF_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    map<tars::StatMicMsgHead, tars::StatMicMsgBody> msg;
                    tars::Bool bFromClient = false;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("msg", msg);
                        tarsAttr.get("bFromClient", bFromClient);
                    }
                    else
                    {
                        _is.read(msg, 1, true);
                        _is.read(bFromClient, 2, true);
                    }
                    tars::Int32 _ret = reportMicMsg(msg,bFromClient, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriter> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    vector<tars::StatSampleMsg> msg;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("msg", msg);
                    }
                    else
                    {
                        _is.read(msg, 1, true);
                    }
                    tars::Int32 _ret = reportSampleMsg(msg, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriter> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
