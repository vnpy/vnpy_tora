//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vntora.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "TORATstpXMdApi.h"


using namespace pybind11;
using namespace TORALEV1API;
using namespace std;


#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPGETCONNECTIONINFO 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONRSPSUBMARKETDATA 5
#define ONRSPUNSUBMARKETDATA 6
#define ONRSPSUBPHMARKETDATA 7
#define ONRSPUNSUBPHMARKETDATA 8
#define ONRSPSUBSPECIALMARKETDATA 9
#define ONRSPUNSUBSPECIALMARKETDATA 10
#define ONRSPSUBSIMPLIFYMARKETDATA 11
#define ONRSPUNSUBSIMPLIFYMARKETDATA 12
#define ONRSPSUBSECURITYSTATUS 13
#define ONRSPUNSUBSECURITYSTATUS 14
#define ONRSPSUBMARKETSTATUS 15
#define ONRSPUNSUBMARKETSTATUS 16
#define ONRSPSUBIMCPARAMS 17
#define ONRSPUNSUBIMCPARAMS 18
#define ONRSPINQUIRYMARKETDATAMIRROR 19
#define ONRSPINQUIRYPHMARKETDATAMIRROR 20
#define ONRSPINQUIRYSPECIALMARKETDATAMIRROR 21
#define ONRSPSUBSPMARKETDATA 22
#define ONRSPUNSUBSPMARKETDATA 23
#define ONRSPSUBSPSIMPLIFYMARKETDATA 24
#define ONRSPUNSUBSPSIMPLIFYMARKETDATA 25
#define ONRSPSUBSPSECURITYSTATUS 26
#define ONRSPUNSUBSPSECURITYSTATUS 27
#define ONRSPSUBSPMARKETSTATUS 28
#define ONRSPUNSUBSPMARKETSTATUS 29
#define ONRSPINQUIRYSPMARKETDATAMIRROR 30
#define ONRTNMARKETDATA 31
#define ONRTNPHMARKETDATA 32
#define ONRTNSPECIALMARKETDATA 33
#define ONRTNSIMPLIFYMARKETDATA 34
#define ONRTNSECURITYSTATUS 35
#define ONRTNMARKETSTATUS 36
#define ONRTNIMCPARAMS 37
#define ONRTNSPMARKETDATA 38
#define ONRTNSPSIMPLIFYMARKETDATA 39
#define ONRTNSPSECURITYSTATUS 40
#define ONRTNSPMARKETSTATUS 41
#define ONRSPSUBRAPIDMARKETDATA 42
#define ONRSPUNSUBRAPIDMARKETDATA 43
#define ONRTNRAPIDMARKETDATA 44


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class ToraMdApi : public CTORATstpXMdSpi
{
private:
    XMD_API_DLL_EXPORT CTORATstpXMdApi* api;      //API对象
    bool active = false;                //工作状态
    thread task_thread;                    //工作线程指针（向python中推送数据）
    TaskQueue task_queue;                //任务队列
    bool logging = false;


public:
    ToraMdApi()
    {
    };

    ~ToraMdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };


    //-------------------------------------------------------------------------------------
    //API回调函数
    //-------------------------------------------------------------------------------------

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///        -3 连接已断开
	///        -4 网络读失败
	///        -5 网络写失败
	///        -6 订阅流错误
	///        -7 流序号错误
	///        -8 错误的心跳报文
	///        -9 错误的报文
	virtual void OnFrontDisconnected(int nReason);

	///获取连接信息应答
	virtual void OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///登录应答
	virtual void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///登出应答
	virtual void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///订阅行情应答
	virtual void OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订行情应答
	virtual void OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅盘后行情应答
	virtual void OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订盘后行情应答
	virtual void OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅特定行情应答
	virtual void OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订特定行情应答
	virtual void OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅简易行情应答（仅TCP模式下可用）
	virtual void OnRspSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订简易行情应答（仅TCP模式下可用）
	virtual void OnRspUnSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅合约状态应答
	virtual void OnRspSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订合约状态应答
	virtual void OnRspUnSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅市场状态应答
	virtual void OnRspSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///退订市场状态应答
	virtual void OnRspUnSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///订阅国际市场互联状态应答
	virtual void OnRspSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///退订国际市场互联状态应答
	virtual void OnRspUnSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///查询行情快照应答（仅TCP模式下可用）
	virtual void OnRspInquiryMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询盘后行情快照应答（仅TCP模式下可用）
	virtual void OnRspInquiryPHMarketDataMirror(CTORATstpPHMarketDataField* pPHMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询特定行情快照应答（仅TCP模式下可用）
	virtual void OnRspInquirySpecialMarketDataMirror(CTORATstpSpecialMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///订阅期权行情应答
	virtual void OnRspSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订期权行情应答
	virtual void OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅期权简易行情应答（仅TCP模式下可用）
	virtual void OnRspSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订期权简易行情应答（仅TCP模式下可用）
	virtual void OnRspUnSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅期权合约状态应答
	virtual void OnRspSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订期权合约状态应答
	virtual void OnRspUnSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///订阅期权市场状态应答
	virtual void OnRspSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///退订期权市场状态应答
	virtual void OnRspUnSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField);

	///查询期权行情快照应答（仅TCP模式下可用）
	virtual void OnRspInquirySPMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///行情通知
	virtual void OnRtnMarketData(CTORATstpMarketDataField* pMarketDataField);

	///盘后行情通知
	virtual void OnRtnPHMarketData(CTORATstpPHMarketDataField* pPHMarketDataField);

	///特定行情通知
	virtual void OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField* pSpecialMarketDataField);

	///简易行情通知（仅TCP模式下可用）
	virtual void OnRtnSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField);

	///合约状态
	virtual void OnRtnSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField);

	///市场状态
	virtual void OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField);

	///国际市场互联状态
	virtual void OnRtnImcParams(CTORATstpImcParamsField* pImcParamsField);

	///期权行情通知
	virtual void OnRtnSPMarketData(CTORATstpMarketDataField* pMarketDataField);

	///期权简易行情通知（仅TCP模式下可用）
	virtual void OnRtnSPSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField);

	///期权合约状态通知
	virtual void OnRtnSPSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField);

	///期权市场状态通知
	virtual void OnRtnSPMarketStatus(CTORATstpMarketStatusField* pMarketStatusField);


	///订阅合成快照应答（衍生服务）
	virtual void OnRspSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///退订合成快照应答（衍生服务）
	virtual void OnRspUnSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///合成快照通知（衍生服务）
	virtual void OnRtnRapidMarketData(CTORATstpRapidMarketDataField* pRapidMarketDataField);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int nReason) {};

	virtual void onRspGetConnectionInfo(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspUserLogin(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspUserLogout(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspSubMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubPHMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubPHMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubSpecialMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubSpecialMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubSimplifyMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubSimplifyMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubSecurityStatus(const dict& data, const dict& error) {};

	virtual void onRspUnSubSecurityStatus(const dict& data, const dict& error) {};

	virtual void onRspSubMarketStatus(const dict& data, const dict& error) {};

	virtual void onRspUnSubMarketStatus(const dict& data, const dict& error) {};

	virtual void onRspSubImcParams(const dict& data, const dict& error) {};

	virtual void onRspUnSubImcParams(const dict& data, const dict& error) {};

	virtual void onRspInquiryMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspInquiryPHMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspInquirySpecialMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspSubSPMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubSPMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubSPSimplifyMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubSPSimplifyMarketData(const dict& data, const dict& error) {};

	virtual void onRspSubSPSecurityStatus(const dict& data, const dict& error) {};

	virtual void onRspUnSubSPSecurityStatus(const dict& data, const dict& error) {};

	virtual void onRspSubSPMarketStatus(const dict& data, const dict& error) {};

	virtual void onRspUnSubSPMarketStatus(const dict& data, const dict& error) {};

	virtual void onRspInquirySPMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRtnMarketData(const dict& data) {};

	virtual void onRtnPHMarketData(const dict& data) {};

	virtual void onRtnSpecialMarketData(const dict& data) {};

	virtual void onRtnSimplifyMarketData(const dict& data) {};

	virtual void onRtnSecurityStatus(const dict& data) {};

	virtual void onRtnMarketStatus(const dict& data) {};

	virtual void onRtnImcParams(const dict& data) {};

	virtual void onRtnSPMarketData(const dict& data) {};

	virtual void onRtnSPSimplifyMarketData(const dict& data) {};

	virtual void onRtnSPSecurityStatus(const dict& data) {};

	virtual void onRtnSPMarketStatus(const dict& data) {};

	virtual void onRspSubRapidMarketData(const dict& data, const dict& error) {};

	virtual void onRspUnSubRapidMarketData(const dict& data, const dict& error) {};

	virtual void onRtnRapidMarketData(const dict& data) {};

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task* task);

	void processFrontDisconnected(Task* task);

	void processRspGetConnectionInfo(Task* task);

	void processRspUserLogin(Task* task);

	void processRspUserLogout(Task* task);

	void processRspSubMarketData(Task* task);

	void processRspUnSubMarketData(Task* task);

	void processRspSubPHMarketData(Task* task);

	void processRspUnSubPHMarketData(Task* task);

	void processRspSubSpecialMarketData(Task* task);

	void processRspUnSubSpecialMarketData(Task* task);

	void processRspSubSimplifyMarketData(Task* task);

	void processRspUnSubSimplifyMarketData(Task* task);

	void processRspSubSecurityStatus(Task* task);

	void processRspUnSubSecurityStatus(Task* task);

	void processRspSubMarketStatus(Task* task);

	void processRspUnSubMarketStatus(Task* task);

	void processRspSubImcParams(Task* task);

	void processRspUnSubImcParams(Task* task);

	void processRspInquiryMarketDataMirror(Task* task);

	void processRspInquiryPHMarketDataMirror(Task* task);

	void processRspInquirySpecialMarketDataMirror(Task* task);

	void processRspSubSPMarketData(Task* task);

	void processRspUnSubSPMarketData(Task* task);

	void processRspSubSPSimplifyMarketData(Task* task);

	void processRspUnSubSPSimplifyMarketData(Task* task);

	void processRspSubSPSecurityStatus(Task* task);

	void processRspUnSubSPSecurityStatus(Task* task);

	void processRspSubSPMarketStatus(Task* task);

	void processRspUnSubSPMarketStatus(Task* task);

	void processRspInquirySPMarketDataMirror(Task* task);

	void processRtnMarketData(Task* task);

	void processRtnPHMarketData(Task* task);

	void processRtnSpecialMarketData(Task* task);

	void processRtnSimplifyMarketData(Task* task);

	void processRtnSecurityStatus(Task* task);

	void processRtnMarketStatus(Task* task);

	void processRtnImcParams(Task* task);

	void processRtnSPMarketData(Task* task);

	void processRtnSPSimplifyMarketData(Task* task);

	void processRtnSPSecurityStatus(Task* task);

	void processRtnSPMarketStatus(Task* task);

	void processRspSubRapidMarketData(Task* task);

	void processRspUnSubRapidMarketData(Task* task);

	void processRtnRapidMarketData(Task* task);

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createTstpXMdApi();

	void registerFront(string pszFrontAddress);

	void init();

	int join();

	void release();

	string getApiVersion();

	int exit();

	void registerNameServer(string pszNsAddress);

	void registerFensUserInfo(const dict& req);

	void registerMulticast(string pszMulticastAddress, string pszInterfaceIP, string pszSourceIp);

	void registerDeriveServer(string pszDeriveAddress);

	void registerDeriveMulticast(string pszMulticastAddress, string pszInterfaceIP, string pszSourceIp);

	int reqGetConnectionInfo(int nrequestid);

	int reqUserLogin(const dict& req, int nrequestid);

	int reqUserLogout(const dict& req, int nrequestid);

	int subscribeMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribePHMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribePHMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSpecialMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSpecialMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

	int subscribeMarketStatus(string marketid);

	int unSubscribeMarketStatus(string marketid);

	int subscribeImcParams(string marketid);

	int unSubscribeImcParams(string marketid);

	int reqInquiryMarketDataMirror(const dict& req, int nrequestid);

	int reqInquiryPHMarketDataMirror(const dict& req, int nrequestid);

	int reqInquirySpecialMarketDataMirror(const dict& req, int nrequestid);

	int subscribeSPMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSPMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSPSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSPSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSPSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeSPSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

	int subscribeSPMarketStatus(string marketid);

	int unSubscribeSPMarketStatus(string marketid);

	int reqInquirySPMarketDataMirror(const dict& req, int nrequestid);

	int subscribeRapidMarketData(string ppsecurityid, int ncount, string exchangeid);

	int unSubscribeRapidMarketData(string ppsecurityid, int ncount, string exchangeid);
};
