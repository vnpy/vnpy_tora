//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vntora.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "TORATstpTraderApi.h"


using namespace pybind11;
using namespace TORASTOCKAPI;
using namespace std;


#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPERROR 2
#define ONRSPGETCONNECTIONINFO 3
#define ONRSPUSERLOGIN 4
#define ONRSPUSERLOGOUT 5
#define ONRSPUSERPASSWORDUPDATE 6
#define ONRSPINPUTDEVICESERIAL 7
#define ONRSPORDERINSERT 8
#define ONRSPPUBLICOFFEREDFUNDORDERINSERT 9
#define ONRTNORDER 10
#define ONERRRTNORDERINSERT 11
#define ONRTNTRADE 12
#define ONRSPORDERACTION 13
#define ONERRRTNORDERACTION 14
#define ONRSPCONDORDERINSERT 15
#define ONRTNCONDORDER 16
#define ONERRRTNCONDORDERINSERT 17
#define ONRSPCONDORDERACTION 18
#define ONERRRTNCONDORDERACTION 19
#define ONRSPNEGOORDERINSERT 20
#define ONRTNNEGOORDER 21
#define ONERRRTNNEGOORDERINSERT 22
#define ONRTNNEGOTRADE 23
#define ONRSPNEGOORDERACTION 24
#define ONERRRTNNEGOORDERACTION 25
#define ONRSPORDERINSERTEX 26
#define ONRSPORDERACTIONEX 27
#define ONRTNMARKETSTATUS 28
#define ONRSPTRANSFERFUND 29
#define ONERRRTNTRANSFERFUND 30
#define ONRTNTRANSFERFUND 31
#define ONRSPTRANSFERPOSITION 32
#define ONERRRTNTRANSFERPOSITION 33
#define ONRTNTRANSFERPOSITION 34
#define ONRTNPERIPHERYTRANSFERPOSITION 35
#define ONRTNPERIPHERYTRANSFERFUND 36
#define ONRSPINQUIRYJZFUND 37
#define ONRSPINQUIRYBANKACCOUNTFUND 38
#define ONRTNTRADINGNOTICE 39
#define ONRSPINQUIRYMAXORDERVOLUME 40
#define ONRSPINQUIRYTRADECONCENTRATION 41
#define ONRSPMODIFYOPENPOSCOST 42
#define ONRSPINPUTNODEFUNDASSIGNMENT 43
#define ONRSPINQUIRYNODEFUNDASSIGNMENT 44
#define ONRSPQRYEXCHANGE 45
#define ONRSPQRYSECURITY 46
#define ONRSPQRYIPOINFO 47
#define ONRSPQRYUSER 48
#define ONRSPQRYINVESTOR 49
#define ONRSPQRYSHAREHOLDERACCOUNT 50
#define ONRSPQRYRATIONALINFO 51
#define ONRSPQRYORDER 52
#define ONRSPQRYORDERACTION 53
#define ONRSPQRYTRADE 54
#define ONRSPQRYTRADINGACCOUNT 55
#define ONRSPQRYPOSITION 56
#define ONRSPQRYTRADINGFEE 57
#define ONRSPQRYINVESTORTRADINGFEE 58
#define ONRSPQRYIPOQUOTA 59
#define ONRSPQRYORDERFUNDDETAIL 60
#define ONRSPQRYFUNDTRANSFERDETAIL 61
#define ONRSPQRYPOSITIONTRANSFERDETAIL 62
#define ONRSPQRYPERIPHERYPOSITIONTRANSFERDETAIL 63
#define ONRSPQRYPERIPHERYFUNDTRANSFERDETAIL 64
#define ONRSPQRYBONDCONVERSIONINFO 65
#define ONRSPQRYBONDPUTBACKINFO 66
#define ONRSPQRYINVESTORCONDORDERLIMITPARAM 67
#define ONRSPQRYCONDITIONORDER 68
#define ONRSPQRYCONDORDERACTION 69
#define ONRSPQRYTRADINGNOTICE 70
#define ONRSPQRYIPONUMBERRESULT 71
#define ONRSPQRYIPOMATCHNUMBERRESULT 72
#define ONRSPQRYSHAREHOLDERSPECPRIVILEGE 73
#define ONRSPQRYMARKET 74
#define ONRSPQRYETFFILE 75
#define ONRSPQRYETFBASKET 76
#define ONRSPQRYINVESTORPOSITIONLIMIT 77
#define ONRSPQRYIMCPARAMS 78
#define ONRSPQRYIMCEXCHANGERATE 79
#define ONRSPQRYHKPRICETICKINFO 80
#define ONRSPQRYLOFFUNDINFO 81
#define ONRSPQRYPLEDGEPOSITION 82
#define ONRSPQRYPLEDGEINFO 83
#define ONRSPQRYSYSTEMNODEINFO 84
#define ONRSPQRYSTANDARDBONDPOSITION 85
#define ONRSPQRYPREMATURITYREPOORDER 86
#define ONRSPQRYNEGOORDER 87
#define ONRSPQRYNEGOORDERACTION 88
#define ONRSPQRYNEGOTRADE 89
#define ONRSPQRYNEGOTIATIONPARAM 90
#define ONRSPQRYPUBLICOFFEREDFUNDINFO 91
#define ONRSPQRYPUBLICOFFEREDFUNDTRADEDETAIL 92
#define ONRSPQRYTENDERINFO 93
#define ONRSPQRYADDITIONALOFFERINGINFO 94
#define ONRSPQRYADDITIONALOFFERINGQUOTA 95


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class StockApi : public CTORATstpTraderSpi
{
private:
	TRADER_API_DLL_EXPORT CTORATstpTraderApi* api;      //API对象
	bool active = false;                //工作状态
	thread task_thread;                    //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool logging = false;


public:
	StockApi()
	{
	};

	~StockApi()
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
	///@param nReason 错误原因
	///        -3 连接已断开
	///        -4 网络读失败
	///        -5 网络写失败
	///        -6 订阅流错误
	///        -7 流序号错误
	///        -8 错误的心跳报文
	///        -9 错误的报文
	///		  -15 网络读失败
	///		  -16 网络写失败
	virtual void OnFrontDisconnected(int nReason);

	///错误应答
	virtual void OnRspError(CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///获取连接信息应答
	virtual void OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///登录响应
	virtual void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///登出响应
	virtual void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///修改密码响应
	virtual void OnRspUserPasswordUpdate(CTORATstpUserPasswordUpdateField* pUserPasswordUpdateField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///录入设备序列响应
	virtual void OnRspInputDeviceSerial(CTORATstpRspInputDeviceSerialField* pRspInputDeviceSerialField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///报单录入响应
	virtual void OnRspOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///公募基金管理人调仓报单响应
	virtual void OnRspPublicOfferedFundOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///报单回报
	virtual void OnRtnOrder(CTORATstpOrderField* pOrderField);

	///报单错误回报
	virtual void OnErrRtnOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///成交回报
	virtual void OnRtnTrade(CTORATstpTradeField* pTradeField);

	///撤单响应
	virtual void OnRspOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///撤单错误回报
	virtual void OnErrRtnOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///条件单录入响应
	virtual void OnRspCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///条件单回报
	virtual void OnRtnCondOrder(CTORATstpConditionOrderField* pConditionOrderField);

	///条件单录入错误回报
	virtual void OnErrRtnCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///条件单撤单响应
	virtual void OnRspCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///条件单撤单错误回报
	virtual void OnErrRtnCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///协议交易报单录入响应
	virtual void OnRspNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///协议交易报单回报
	virtual void OnRtnNegoOrder(CTORATstpNegoOrderField* pNegoOrderField);

	///协议交易报单错误回报
	virtual void OnErrRtnNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///协议交易成交回报
	virtual void OnRtnNegoTrade(CTORATstpNegoTradeField* pNegoTradeField);

	///协议交易报单操作录入响应
	virtual void OnRspNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///协议交易报单操作错误回报
	virtual void OnErrRtnNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///报单录入响应（扩展）
	virtual void OnRspOrderInsertEx(CTORATstpInputOrderExField* pInputOrderExField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///报单操作响应（扩展）
	virtual void OnRspOrderActionEx(CTORATstpInputOrderActionExField* pInputOrderActionExField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///市场状态回报
	virtual void OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField);

	///资金转移响应
	virtual void OnRspTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///资金转移错误回报
	virtual void OnErrRtnTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///资金转移回报
	virtual void OnRtnTransferFund(CTORATstpTransferFundField* pTransferFundField);

	///仓位转移响应
	virtual void OnRspTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///仓位转移错误回报
	virtual void OnErrRtnTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///仓位转移回报
	virtual void OnRtnTransferPosition(CTORATstpTransferPositionField* pTransferPositionField);

	///外围系统仓位转移回报
	virtual void OnRtnPeripheryTransferPosition(CTORATstpPeripheryTransferPositionField* pPeripheryTransferPositionField);

	///外围系统资金转移回报
	virtual void OnRtnPeripheryTransferFund(CTORATstpPeripheryTransferFundField* pPeripheryTransferFundField);

	///查询集中交易系统资金响应
	virtual void OnRspInquiryJZFund(CTORATstpRspInquiryJZFundField* pRspInquiryJZFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///查询银行账户余额响应
	virtual void OnRspInquiryBankAccountFund(CTORATstpRspInquiryBankAccountFundField* pRspInquiryBankAccountFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///交易通知回报
	virtual void OnRtnTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField);

	///查询最大报单量响应
	virtual void OnRspInquiryMaxOrderVolume(CTORATstpRspInquiryMaxOrderVolumeField* pRspInquiryMaxOrderVolumeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///交易成交集中度查询响应
	virtual void OnRspInquiryTradeConcentration(CTORATstpInquiryTradeConcentrationField* pInquiryTradeConcentrationField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///请求修改开仓成本响应
	virtual void OnRspModifyOpenPosCost(CTORATstpReqModifyOpenPosCostField* pReqModifyOpenPosCostField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///录入节点资金分配信息响应
	virtual void OnRspInputNodeFundAssignment(CTORATstpInputNodeFundAssignmentField* pInputNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///查询节点资金分配比例响应
	virtual void OnRspInquiryNodeFundAssignment(CTORATstpRspInquiryNodeFundAssignmentField* pRspInquiryNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	///查询交易所响应
	virtual void OnRspQryExchange(CTORATstpExchangeField* pExchangeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询证券信息响应
	virtual void OnRspQrySecurity(CTORATstpSecurityField* pSecurityField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询新股信息响应
	virtual void OnRspQryIPOInfo(CTORATstpIPOInfoField* pIPOInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询用户响应
	virtual void OnRspQryUser(CTORATstpUserField* pUserField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询投资者响应
	virtual void OnRspQryInvestor(CTORATstpInvestorField* pInvestorField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询股东账户响应
	virtual void OnRspQryShareholderAccount(CTORATstpShareholderAccountField* pShareholderAccountField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询配股配债信息响应
	virtual void OnRspQryRationalInfo(CTORATstpRationalInfoField* pRationalInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询报单响应
	virtual void OnRspQryOrder(CTORATstpOrderField* pOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询撤单请求
	virtual void OnRspQryOrderAction(CTORATstpOrderActionField* pOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询成交响应
	virtual void OnRspQryTrade(CTORATstpTradeField* pTradeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询资金账户响应
	virtual void OnRspQryTradingAccount(CTORATstpTradingAccountField* pTradingAccountField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询投资者持仓响应
	virtual void OnRspQryPosition(CTORATstpPositionField* pPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询基础交易费率响应
	virtual void OnRspQryTradingFee(CTORATstpTradingFeeField* pTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询佣金费率响应
	virtual void OnRspQryInvestorTradingFee(CTORATstpInvestorTradingFeeField* pInvestorTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询新股申购额度响应
	virtual void OnRspQryIPOQuota(CTORATstpIPOQuotaField* pIPOQuotaField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询报单明细资金响应
	virtual void OnRspQryOrderFundDetail(CTORATstpOrderFundDetailField* pOrderFundDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询资金转移流水响应
	virtual void OnRspQryFundTransferDetail(CTORATstpFundTransferDetailField* pFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询持仓转移流水响应
	virtual void OnRspQryPositionTransferDetail(CTORATstpPositionTransferDetailField* pPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询外围系统仓位调拨流水响应
	virtual void OnRspQryPeripheryPositionTransferDetail(CTORATstpPeripheryPositionTransferDetailField* pPeripheryPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询外围系统资金调拨流水响应
	virtual void OnRspQryPeripheryFundTransferDetail(CTORATstpPeripheryFundTransferDetailField* pPeripheryFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询债券转股信息响应
	virtual void OnRspQryBondConversionInfo(CTORATstpBondConversionInfoField* pBondConversionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询债券回售信息响应
	virtual void OnRspQryBondPutbackInfo(CTORATstpBondPutbackInfoField* pBondPutbackInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询投资者条件单限制参数响应
	virtual void OnRspQryInvestorCondOrderLimitParam(CTORATstpInvestorCondOrderLimitParamField* pInvestorCondOrderLimitParamField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询条件单响应
	virtual void OnRspQryConditionOrder(CTORATstpConditionOrderField* pConditionOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询条件单撤单响应
	virtual void OnRspQryCondOrderAction(CTORATstpCondOrderActionField* pCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询交易通知响应
	virtual void OnRspQryTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询新股申购配号结果响应
	virtual void OnRspQryIPONumberResult(CTORATstpIPONumberResultField* pIPONumberResultField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询新股申购中签结果响应
	virtual void OnRspQryIPOMatchNumberResult(CTORATstpIPOMatchNumberResultField* pIPOMatchNumberResultField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询交易协议响应
	virtual void OnRspQryShareholderSpecPrivilege(CTORATstpShareholderSpecPrivilegeField* pShareholderSpecPrivilegeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询市场响应
	virtual void OnRspQryMarket(CTORATstpMarketField* pMarketField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询ETF清单信息响应
	virtual void OnRspQryETFFile(CTORATstpETFFileField* pETFFileField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询ETF成份证券信息响应
	virtual void OnRspQryETFBasket(CTORATstpETFBasketField* pETFBasketField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询投资者限仓信息响应
	virtual void OnRspQryInvestorPositionLimit(CTORATstpInvestorPositionLimitField* pInvestorPositionLimitField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询国际市场互联状态信息响应
	virtual void OnRspQryImcParams(CTORATstpImcParamsField* pImcParamsField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询国际市场互联汇率信息响应
	virtual void OnRspQryImcExchangeRate(CTORATstpImcExchangeRateField* pImcExchangeRateField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询最小价差信息响应
	virtual void OnRspQryHKPriceTickInfo(CTORATstpHKPriceTickInfoField* pHKPriceTickInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询LOF基金信息响应
	virtual void OnRspQryLofFundInfo(CTORATstpLofFundInfoField* pLofFundInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询投资者质押持仓响应
	virtual void OnRspQryPledgePosition(CTORATstpPledgePositionField* pPledgePositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询证券质押信息响应
	virtual void OnRspQryPledgeInfo(CTORATstpPledgeInfoField* pPledgeInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询系统节点信息响应
	virtual void OnRspQrySystemNodeInfo(CTORATstpSystemNodeInfoField* pSystemNodeInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询标准券额度响应
	virtual void OnRspQryStandardBondPosition(CTORATstpStandardBondPositionField* pStandardBondPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询未到期债券质押回购委托响应
	virtual void OnRspQryPrematurityRepoOrder(CTORATstpPrematurityRepoOrderField* pPrematurityRepoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询协议交易报单响应
	virtual void OnRspQryNegoOrder(CTORATstpNegoOrderField* pNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询协议交易撤单响应
	virtual void OnRspQryNegoOrderAction(CTORATstpNegoOrderActionField* pNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询协议交易成交响应
	virtual void OnRspQryNegoTrade(CTORATstpNegoTradeField* pNegoTradeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询协议交易参数响应
	virtual void OnRspQryNegotiationParam(CTORATstpNegotiationParamField* pNegotiationParamField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询公募基金发行信息响应
	virtual void OnRspQryPublicOfferedFundInfo(CTORATstpPublicOfferedFundInfoField* pPublicOfferedFundInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询公募基金申赎成交明细响应
	virtual void OnRspQryPublicOfferedFundTradeDetail(CTORATstpPublicOfferedFundTradeDetailField* pPublicOfferedFundTradeDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询要约收购信息
	virtual void OnRspQryTenderInfo(CTORATstpTenderInfoField* pTenderInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询基础设施基金非定向扩募信息响应
	virtual void OnRspQryAdditionalOfferingInfo(CTORATstpAdditionalOfferingInfoField* pAdditionalOfferingInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	///查询基础设施基金非定向扩募配售额度响应
	virtual void OnRspQryAdditionalOfferingQuota(CTORATstpAdditionalOfferingQuotaField* pAdditionalOfferingQuotaField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//-------------------------------------------------------------------------------------
	
	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int nReason) {};

	virtual void onRspError(const dict& error, int nRequestID, bool last) {};

	virtual void onRspGetConnectionInfo(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspUserLogin(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspUserLogout(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspUserPasswordUpdate(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspInputDeviceSerial(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspPublicOfferedFundOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnOrder(const dict& data) {};

	virtual void onErrRtnOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnTrade(const dict& data) {};

	virtual void onRspOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onErrRtnOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspCondOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnCondOrder(const dict& data) {};

	virtual void onErrRtnCondOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspCondOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onErrRtnCondOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspNegoOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnNegoOrder(const dict& data) {};

	virtual void onErrRtnNegoOrderInsert(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnNegoTrade(const dict& data) {};

	virtual void onRspNegoOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onErrRtnNegoOrderAction(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspOrderInsertEx(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspOrderActionEx(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnMarketStatus(const dict& data) {};

	virtual void onRspTransferFund(const dict& data, const dict& error, int nRequestID) {};

	virtual void onErrRtnTransferFund(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnTransferFund(const dict& data) {};

	virtual void onRspTransferPosition(const dict& data, const dict& error, int nRequestID) {};

	virtual void onErrRtnTransferPosition(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnTransferPosition(const dict& data) {};

	virtual void onRtnPeripheryTransferPosition(const dict& data) {};

	virtual void onRtnPeripheryTransferFund(const dict& data) {};

	virtual void onRspInquiryJZFund(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspInquiryBankAccountFund(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRtnTradingNotice(const dict& data) {};

	virtual void onRspInquiryMaxOrderVolume(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspInquiryTradeConcentration(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspModifyOpenPosCost(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspInputNodeFundAssignment(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspInquiryNodeFundAssignment(const dict& data, const dict& error, int nRequestID) {};

	virtual void onRspQryExchange(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQrySecurity(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryIPOInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryUser(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryInvestor(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryShareholderAccount(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryRationalInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryOrder(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryOrderAction(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryTrade(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryTradingAccount(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPosition(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryTradingFee(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryInvestorTradingFee(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryIPOQuota(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryOrderFundDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryFundTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPositionTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPeripheryPositionTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPeripheryFundTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryBondConversionInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryBondPutbackInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryInvestorCondOrderLimitParam(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryConditionOrder(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryCondOrderAction(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryTradingNotice(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryIPONumberResult(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryIPOMatchNumberResult(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryShareholderSpecPrivilege(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryMarket(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryETFFile(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryETFBasket(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryInvestorPositionLimit(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryImcParams(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryImcExchangeRate(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryHKPriceTickInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryLofFundInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPledgePosition(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPledgeInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQrySystemNodeInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryStandardBondPosition(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPrematurityRepoOrder(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryNegoOrder(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryNegoOrderAction(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryNegoTrade(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryNegotiationParam(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPublicOfferedFundInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryPublicOfferedFundTradeDetail(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryTenderInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryAdditionalOfferingInfo(const dict& data, const dict& error, int nRequestID, bool last) {};

	virtual void onRspQryAdditionalOfferingQuota(const dict& data, const dict& error, int nRequestID, bool last) {};

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task* task);

	void processFrontDisconnected(Task* task);

	void processRspError(Task* task);

	void processRspGetConnectionInfo(Task* task);

	void processRspUserLogin(Task* task);

	void processRspUserLogout(Task* task);

	void processRspUserPasswordUpdate(Task* task);

	void processRspInputDeviceSerial(Task* task);

	void processRspOrderInsert(Task* task);

	void processRspPublicOfferedFundOrderInsert(Task* task);

	void processRtnOrder(Task* task);

	void processErrRtnOrderInsert(Task* task);

	void processRtnTrade(Task* task);

	void processRspOrderAction(Task* task);

	void processErrRtnOrderAction(Task* task);

	void processRspCondOrderInsert(Task* task);

	void processRtnCondOrder(Task* task);

	void processErrRtnCondOrderInsert(Task* task);

	void processRspCondOrderAction(Task* task);

	void processErrRtnCondOrderAction(Task* task);

	void processRspNegoOrderInsert(Task* task);

	void processRtnNegoOrder(Task* task);

	void processErrRtnNegoOrderInsert(Task* task);

	void processRtnNegoTrade(Task* task);

	void processRspNegoOrderAction(Task* task);

	void processErrRtnNegoOrderAction(Task* task);

	void processRspOrderInsertEx(Task* task);

	void processRspOrderActionEx(Task* task);

	void processRtnMarketStatus(Task* task);

	void processRspTransferFund(Task* task);

	void processErrRtnTransferFund(Task* task);

	void processRtnTransferFund(Task* task);

	void processRspTransferPosition(Task* task);

	void processErrRtnTransferPosition(Task* task);

	void processRtnTransferPosition(Task* task);

	void processRtnPeripheryTransferPosition(Task* task);

	void processRtnPeripheryTransferFund(Task* task);

	void processRspInquiryJZFund(Task* task);

	void processRspInquiryBankAccountFund(Task* task);

	void processRtnTradingNotice(Task* task);

	void processRspInquiryMaxOrderVolume(Task* task);

	void processRspInquiryTradeConcentration(Task* task);

	void processRspModifyOpenPosCost(Task* task);

	void processRspInputNodeFundAssignment(Task* task);

	void processRspInquiryNodeFundAssignment(Task* task);

	void processRspQryExchange(Task* task);

	void processRspQrySecurity(Task* task);

	void processRspQryIPOInfo(Task* task);

	void processRspQryUser(Task* task);

	void processRspQryInvestor(Task* task);

	void processRspQryShareholderAccount(Task* task);

	void processRspQryRationalInfo(Task* task);

	void processRspQryOrder(Task* task);

	void processRspQryOrderAction(Task* task);

	void processRspQryTrade(Task* task);

	void processRspQryTradingAccount(Task* task);

	void processRspQryPosition(Task* task);

	void processRspQryTradingFee(Task* task);

	void processRspQryInvestorTradingFee(Task* task);

	void processRspQryIPOQuota(Task* task);

	void processRspQryOrderFundDetail(Task* task);

	void processRspQryFundTransferDetail(Task* task);

	void processRspQryPositionTransferDetail(Task* task);

	void processRspQryPeripheryPositionTransferDetail(Task* task);

	void processRspQryPeripheryFundTransferDetail(Task* task);

	void processRspQryBondConversionInfo(Task* task);

	void processRspQryBondPutbackInfo(Task* task);

	void processRspQryInvestorCondOrderLimitParam(Task* task);

	void processRspQryConditionOrder(Task* task);

	void processRspQryCondOrderAction(Task* task);

	void processRspQryTradingNotice(Task* task);

	void processRspQryIPONumberResult(Task* task);

	void processRspQryIPOMatchNumberResult(Task* task);

	void processRspQryShareholderSpecPrivilege(Task* task);

	void processRspQryMarket(Task* task);

	void processRspQryETFFile(Task* task);

	void processRspQryETFBasket(Task* task);

	void processRspQryInvestorPositionLimit(Task* task);

	void processRspQryImcParams(Task* task);

	void processRspQryImcExchangeRate(Task* task);

	void processRspQryHKPriceTickInfo(Task* task);

	void processRspQryLofFundInfo(Task* task);

	void processRspQryPledgePosition(Task* task);

	void processRspQryPledgeInfo(Task* task);

	void processRspQrySystemNodeInfo(Task* task);

	void processRspQryStandardBondPosition(Task* task);

	void processRspQryPrematurityRepoOrder(Task* task);

	void processRspQryNegoOrder(Task* task);

	void processRspQryNegoOrderAction(Task* task);

	void processRspQryNegoTrade(Task* task);

	void processRspQryNegotiationParam(Task* task);

	void processRspQryPublicOfferedFundInfo(Task* task);

	void processRspQryPublicOfferedFundTradeDetail(Task* task);

	void processRspQryTenderInfo(Task* task);

	void processRspQryAdditionalOfferingInfo(Task* task);

	void processRspQryAdditionalOfferingQuota(Task* task);


	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createTstpTraderApi(string pszFlowPath, bool bEncrypt);

	void registerFront(string pszFrontAddress);

	void init();

	int join();

	void release();

	string getApiVersion();

	int exit();

	void registerNameServer(string pszNsAddress);

	void registerFensUserInfo(const dict& req);

	void subscribePrivateTopic(int type);

	void subscribePublicTopic(int type);

	int reqGetConnectionInfo(int nrequestid);

	int reqUserLogin(const dict& req, int nrequestid);

	int reqUserLogout(const dict& req, int nrequestid);

	int reqUserPasswordUpdate(const dict& req, int nrequestid);

	int reqInputDeviceSerial(const dict& req, int nrequestid);

	int reqOrderInsert(const dict& req, int nrequestid);

	int reqPublicOfferedFundOrderInsert(const dict& req, int nrequestid);

	int reqOrderAction(const dict& req, int nrequestid);

	int reqCondOrderInsert(const dict& req, int nrequestid);

	int reqCondOrderAction(const dict& req, int nrequestid);

	int reqNegoOrderInsert(const dict& req, int nrequestid);

	int reqNegoOrderAction(const dict& req, int nrequestid);

	int reqOrderInsertEx(const dict& req, int nrequestid);

	int reqOrderActionEx(const dict& req, int nrequestid);

	int reqTransferFund(const dict& req, int nrequestid);

	int reqTransferPosition(const dict& req, int nrequestid);

	int reqInquiryJZFund(const dict& req, int nrequestid);

	int reqInquiryBankAccountFund(const dict& req, int nrequestid);

	int reqInquiryMaxOrderVolume(const dict& req, int nrequestid);

	int reqInquiryTradeConcentration(const dict& req, int nrequestid);

	int reqModifyOpenPosCost(const dict& req, int nrequestid);

	int reqInputNodeFundAssignment(const dict& req, int nrequestid);

	int reqInquiryNodeFundAssignment(const dict& req, int nrequestid);

	int reqQryExchange(const dict& req, int nrequestid);

	int reqQrySecurity(const dict& req, int nrequestid);

	int reqQryIPOInfo(const dict& req, int nrequestid);

	int reqQryUser(const dict& req, int nrequestid);

	int reqQryInvestor(const dict& req, int nrequestid);

	int reqQryShareholderAccount(const dict& req, int nrequestid);

	int reqQryRationalInfo(const dict& req, int nrequestid);

	int reqQryOrder(const dict& req, int nrequestid);

	int reqQryOrderAction(const dict& req, int nrequestid);

	int reqQryTrade(const dict& req, int nrequestid);

	int reqQryTradingAccount(const dict& req, int nrequestid);

	int reqQryPosition(const dict& req, int nrequestid);

	int reqQryTradingFee(const dict& req, int nrequestid);

	int reqQryInvestorTradingFee(const dict& req, int nrequestid);

	int reqQryIPOQuota(const dict& req, int nrequestid);

	int reqQryOrderFundDetail(const dict& req, int nrequestid);

	int reqQryFundTransferDetail(const dict& req, int nrequestid);

	int reqQryPositionTransferDetail(const dict& req, int nrequestid);

	int reqQryPeripheryPositionTransferDetail(const dict& req, int nrequestid);

	int reqQryPeripheryFundTransferDetail(const dict& req, int nrequestid);

	int reqQryBondConversionInfo(const dict& req, int nrequestid);

	int reqQryBondPutbackInfo(const dict& req, int nrequestid);

	int reqQryInvestorCondOrderLimitParam(const dict& req, int nrequestid);

	int reqQryConditionOrder(const dict& req, int nrequestid);

	int reqQryCondOrderAction(const dict& req, int nrequestid);

	int reqQryTradingNotice(const dict& req, int nrequestid);

	int reqQryIPONumberResult(const dict& req, int nrequestid);

	int reqQryIPOMatchNumberResult(const dict& req, int nrequestid);

	int reqQryShareholderSpecPrivilege(const dict& req, int nrequestid);

	int reqQryMarket(const dict& req, int nrequestid);

	int reqQryETFFile(const dict& req, int nrequestid);

	int reqQryETFBasket(const dict& req, int nrequestid);

	int reqQryInvestorPositionLimit(const dict& req, int nrequestid);

	int reqQryImcParams(const dict& req, int nrequestid);

	int reqQryImcExchangeRate(const dict& req, int nrequestid);

	int reqQryHKPriceTickInfo(const dict& req, int nrequestid);

	int reqQryLofFundInfo(const dict& req, int nrequestid);

	int reqQryPledgePosition(const dict& req, int nrequestid);

	int reqQryPledgeInfo(const dict& req, int nrequestid);

	int reqQrySystemNodeInfo(const dict& req, int nrequestid);

	int reqQryStandardBondPosition(const dict& req, int nrequestid);

	int reqQryPrematurityRepoOrder(const dict& req, int nrequestid);

	int reqQryNegoOrder(const dict& req, int nrequestid);

	int reqQryNegoOrderAction(const dict& req, int nrequestid);

	int reqQryNegoTrade(const dict& req, int nrequestid);

	int reqQryNegotiationParam(const dict& req, int nrequestid);

	int reqQryPublicOfferedFundInfo(const dict& req, int nrequestid);

	int reqQryPublicOfferedFundTradeDetail(const dict& req, int nrequestid);

	int reqQryTenderInfo(const dict& req, int nrequestid);

	int reqQryAdditionalOfferingInfo(const dict& req, int nrequestid);

	int reqQryAdditionalOfferingQuota(const dict& req, int nrequestid);
};
