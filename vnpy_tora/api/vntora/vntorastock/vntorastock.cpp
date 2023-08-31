// vntorastock.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vntorastock.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void StockApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void StockApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = int(nReason);
	this->task_queue.push(task);
};

void StockApi::OnRspError(CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPGETCONNECTIONINFO;
	if (pConnectionInfoField)
	{
		CTORATstpConnectionInfoField* task_data = new CTORATstpConnectionInfoField();
		*task_data = *pConnectionInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLoginField)
	{
		CTORATstpRspUserLoginField* task_data = new CTORATstpRspUserLoginField();
		*task_data = *pRspUserLoginField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogoutField)
	{
		CTORATstpUserLogoutField* task_data = new CTORATstpUserLogoutField();
		*task_data = *pUserLogoutField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspUserPasswordUpdate(CTORATstpUserPasswordUpdateField* pUserPasswordUpdateField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;
	if (pUserPasswordUpdateField)
	{
		CTORATstpUserPasswordUpdateField* task_data = new CTORATstpUserPasswordUpdateField();
		*task_data = *pUserPasswordUpdateField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspInputDeviceSerial(CTORATstpRspInputDeviceSerialField* pRspInputDeviceSerialField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINPUTDEVICESERIAL;
	if (pRspInputDeviceSerialField)
	{
		CTORATstpRspInputDeviceSerialField* task_data = new CTORATstpRspInputDeviceSerialField();
		*task_data = *pRspInputDeviceSerialField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;
	if (pInputOrderField)
	{
		CTORATstpInputOrderField* task_data = new CTORATstpInputOrderField();
		*task_data = *pInputOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnOrder(CTORATstpOrderField* pOrderField)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pOrderField)
	{
		CTORATstpOrderField* task_data = new CTORATstpOrderField();
		*task_data = *pOrderField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnErrRtnOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNORDERINSERT;
	if (pInputOrderField)
	{
		CTORATstpInputOrderField* task_data = new CTORATstpInputOrderField();
		*task_data = *pInputOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnTrade(CTORATstpTradeField* pTradeField)
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pTradeField)
	{
		CTORATstpTradeField* task_data = new CTORATstpTradeField();
		*task_data = *pTradeField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pInputOrderActionField)
	{
		CTORATstpInputOrderActionField* task_data = new CTORATstpInputOrderActionField();
		*task_data = *pInputOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnErrRtnOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;
	if (pInputOrderActionField)
	{
		CTORATstpInputOrderActionField* task_data = new CTORATstpInputOrderActionField();
		*task_data = *pInputOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERINSERT;
	if (pInputCondOrderField)
	{
		CTORATstpInputCondOrderField* task_data = new CTORATstpInputCondOrderField();
		*task_data = *pInputCondOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnCondOrder(CTORATstpConditionOrderField* pConditionOrderField)
{
	Task task = Task();
	task.task_name = ONRTNCONDORDER;
	if (pConditionOrderField)
	{
		CTORATstpConditionOrderField* task_data = new CTORATstpConditionOrderField();
		*task_data = *pConditionOrderField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnErrRtnCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERINSERT;
	if (pInputCondOrderField)
	{
		CTORATstpInputCondOrderField* task_data = new CTORATstpInputCondOrderField();
		*task_data = *pInputCondOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERACTION;
	if (pInputCondOrderActionField)
	{
		CTORATstpInputCondOrderActionField* task_data = new CTORATstpInputCondOrderActionField();
		*task_data = *pInputCondOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnErrRtnCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERACTION;
	if (pInputCondOrderActionField)
	{
		CTORATstpInputCondOrderActionField* task_data = new CTORATstpInputCondOrderActionField();
		*task_data = *pInputCondOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPNEGOORDERINSERT;
	if (pInputNegoOrderField)
	{
		CTORATstpInputNegoOrderField* task_data = new CTORATstpInputNegoOrderField();
		*task_data = *pInputNegoOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnNegoOrder(CTORATstpNegoOrderField* pNegoOrderField)
{
	Task task = Task();
	task.task_name = ONRTNNEGOORDER;
	if (pNegoOrderField)
	{
		CTORATstpNegoOrderField* task_data = new CTORATstpNegoOrderField();
		*task_data = *pNegoOrderField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnErrRtnNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNNEGOORDERINSERT;
	if (pInputNegoOrderField)
	{
		CTORATstpInputNegoOrderField* task_data = new CTORATstpInputNegoOrderField();
		*task_data = *pInputNegoOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnNegoTrade(CTORATstpNegoTradeField* pNegoTradeField)
{
	Task task = Task();
	task.task_name = ONRTNNEGOTRADE;
	if (pNegoTradeField)
	{
		CTORATstpNegoTradeField* task_data = new CTORATstpNegoTradeField();
		*task_data = *pNegoTradeField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPNEGOORDERACTION;
	if (pInputNegoOrderActionField)
	{
		CTORATstpInputNegoOrderActionField* task_data = new CTORATstpInputNegoOrderActionField();
		*task_data = *pInputNegoOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnErrRtnNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNNEGOORDERACTION;
	if (pInputNegoOrderActionField)
	{
		CTORATstpInputNegoOrderActionField* task_data = new CTORATstpInputNegoOrderActionField();
		*task_data = *pInputNegoOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspOrderInsertEx(CTORATstpInputOrderExField* pInputOrderExField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERTEX;
	if (pInputOrderExField)
	{
		CTORATstpInputOrderExField* task_data = new CTORATstpInputOrderExField();
		*task_data = *pInputOrderExField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspOrderActionEx(CTORATstpInputOrderActionExField* pInputOrderActionExField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTIONEX;
	if (pInputOrderActionExField)
	{
		CTORATstpInputOrderActionExField* task_data = new CTORATstpInputOrderActionExField();
		*task_data = *pInputOrderActionExField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField)
{
	Task task = Task();
	task.task_name = ONRTNMARKETSTATUS;
	if (pMarketStatusField)
	{
		CTORATstpMarketStatusField* task_data = new CTORATstpMarketStatusField();
		*task_data = *pMarketStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERFUND;
	if (pInputTransferFundField)
	{
		CTORATstpInputTransferFundField* task_data = new CTORATstpInputTransferFundField();
		*task_data = *pInputTransferFundField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnErrRtnTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERFUND;
	if (pInputTransferFundField)
	{
		CTORATstpInputTransferFundField* task_data = new CTORATstpInputTransferFundField();
		*task_data = *pInputTransferFundField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnTransferFund(CTORATstpTransferFundField* pTransferFundField)
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERFUND;
	if (pTransferFundField)
	{
		CTORATstpTransferFundField* task_data = new CTORATstpTransferFundField();
		*task_data = *pTransferFundField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERPOSITION;
	if (pInputTransferPositionField)
	{
		CTORATstpInputTransferPositionField* task_data = new CTORATstpInputTransferPositionField();
		*task_data = *pInputTransferPositionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnErrRtnTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERPOSITION;
	if (pInputTransferPositionField)
	{
		CTORATstpInputTransferPositionField* task_data = new CTORATstpInputTransferPositionField();
		*task_data = *pInputTransferPositionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnTransferPosition(CTORATstpTransferPositionField* pTransferPositionField)
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERPOSITION;
	if (pTransferPositionField)
	{
		CTORATstpTransferPositionField* task_data = new CTORATstpTransferPositionField();
		*task_data = *pTransferPositionField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRtnPeripheryTransferPosition(CTORATstpPeripheryTransferPositionField* pPeripheryTransferPositionField)
{
	Task task = Task();
	task.task_name = ONRTNPERIPHERYTRANSFERPOSITION;
	if (pPeripheryTransferPositionField)
	{
		CTORATstpPeripheryTransferPositionField* task_data = new CTORATstpPeripheryTransferPositionField();
		*task_data = *pPeripheryTransferPositionField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRtnPeripheryTransferFund(CTORATstpPeripheryTransferFundField* pPeripheryTransferFundField)
{
	Task task = Task();
	task.task_name = ONRTNPERIPHERYTRANSFERFUND;
	if (pPeripheryTransferFundField)
	{
		CTORATstpPeripheryTransferFundField* task_data = new CTORATstpPeripheryTransferFundField();
		*task_data = *pPeripheryTransferFundField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspInquiryJZFund(CTORATstpRspInquiryJZFundField* pRspInquiryJZFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYJZFUND;
	if (pRspInquiryJZFundField)
	{
		CTORATstpRspInquiryJZFundField* task_data = new CTORATstpRspInquiryJZFundField();
		*task_data = *pRspInquiryJZFundField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspInquiryBankAccountFund(CTORATstpRspInquiryBankAccountFundField* pRspInquiryBankAccountFundField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYBANKACCOUNTFUND;
	if (pRspInquiryBankAccountFundField)
	{
		CTORATstpRspInquiryBankAccountFundField* task_data = new CTORATstpRspInquiryBankAccountFundField();
		*task_data = *pRspInquiryBankAccountFundField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRtnTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField)
{
	Task task = Task();
	task.task_name = ONRTNTRADINGNOTICE;
	if (pTradingNoticeField)
	{
		CTORATstpTradingNoticeField* task_data = new CTORATstpTradingNoticeField();
		*task_data = *pTradingNoticeField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void StockApi::OnRspInquiryMaxOrderVolume(CTORATstpRspInquiryMaxOrderVolumeField* pRspInquiryMaxOrderVolumeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMAXORDERVOLUME;
	if (pRspInquiryMaxOrderVolumeField)
	{
		CTORATstpRspInquiryMaxOrderVolumeField* task_data = new CTORATstpRspInquiryMaxOrderVolumeField();
		*task_data = *pRspInquiryMaxOrderVolumeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspInquiryTradeConcentration(CTORATstpInquiryTradeConcentrationField* pInquiryTradeConcentrationField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYTRADECONCENTRATION;
	if (pInquiryTradeConcentrationField)
	{
		CTORATstpInquiryTradeConcentrationField* task_data = new CTORATstpInquiryTradeConcentrationField();
		*task_data = *pInquiryTradeConcentrationField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspModifyOpenPosCost(CTORATstpReqModifyOpenPosCostField* pReqModifyOpenPosCostField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPMODIFYOPENPOSCOST;
	if (pReqModifyOpenPosCostField)
	{
		CTORATstpReqModifyOpenPosCostField* task_data = new CTORATstpReqModifyOpenPosCostField();
		*task_data = *pReqModifyOpenPosCostField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspInputNodeFundAssignment(CTORATstpInputNodeFundAssignmentField* pInputNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINPUTNODEFUNDASSIGNMENT;
	if (pInputNodeFundAssignmentField)
	{
		CTORATstpInputNodeFundAssignmentField* task_data = new CTORATstpInputNodeFundAssignmentField();
		*task_data = *pInputNodeFundAssignmentField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspInquiryNodeFundAssignment(CTORATstpRspInquiryNodeFundAssignmentField* pRspInquiryNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYNODEFUNDASSIGNMENT;
	if (pRspInquiryNodeFundAssignmentField)
	{
		CTORATstpRspInquiryNodeFundAssignmentField* task_data = new CTORATstpRspInquiryNodeFundAssignmentField();
		*task_data = *pRspInquiryNodeFundAssignmentField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void StockApi::OnRspQryExchange(CTORATstpExchangeField* pExchangeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	if (pExchangeField)
	{
		CTORATstpExchangeField* task_data = new CTORATstpExchangeField();
		*task_data = *pExchangeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQrySecurity(CTORATstpSecurityField* pSecurityField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSECURITY;
	if (pSecurityField)
	{
		CTORATstpSecurityField* task_data = new CTORATstpSecurityField();
		*task_data = *pSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryIPOInfo(CTORATstpIPOInfoField* pIPOInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOINFO;
	if (pIPOInfoField)
	{
		CTORATstpIPOInfoField* task_data = new CTORATstpIPOInfoField();
		*task_data = *pIPOInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryUser(CTORATstpUserField* pUserField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYUSER;
	if (pUserField)
	{
		CTORATstpUserField* task_data = new CTORATstpUserField();
		*task_data = *pUserField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryInvestor(CTORATstpInvestorField* pInvestorField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTOR;
	if (pInvestorField)
	{
		CTORATstpInvestorField* task_data = new CTORATstpInvestorField();
		*task_data = *pInvestorField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryShareholderAccount(CTORATstpShareholderAccountField* pShareholderAccountField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSHAREHOLDERACCOUNT;
	if (pShareholderAccountField)
	{
		CTORATstpShareholderAccountField* task_data = new CTORATstpShareholderAccountField();
		*task_data = *pShareholderAccountField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryRationalInfo(CTORATstpRationalInfoField* pRationalInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYRATIONALINFO;
	if (pRationalInfoField)
	{
		CTORATstpRationalInfoField* task_data = new CTORATstpRationalInfoField();
		*task_data = *pRationalInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryOrder(CTORATstpOrderField* pOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	if (pOrderField)
	{
		CTORATstpOrderField* task_data = new CTORATstpOrderField();
		*task_data = *pOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryOrderAction(CTORATstpOrderActionField* pOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERACTION;
	if (pOrderActionField)
	{
		CTORATstpOrderActionField* task_data = new CTORATstpOrderActionField();
		*task_data = *pOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryTrade(CTORATstpTradeField* pTradeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;
	if (pTradeField)
	{
		CTORATstpTradeField* task_data = new CTORATstpTradeField();
		*task_data = *pTradeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryTradingAccount(CTORATstpTradingAccountField* pTradingAccountField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGACCOUNT;
	if (pTradingAccountField)
	{
		CTORATstpTradingAccountField* task_data = new CTORATstpTradingAccountField();
		*task_data = *pTradingAccountField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPosition(CTORATstpPositionField* pPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	if (pPositionField)
	{
		CTORATstpPositionField* task_data = new CTORATstpPositionField();
		*task_data = *pPositionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryTradingFee(CTORATstpTradingFeeField* pTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGFEE;
	if (pTradingFeeField)
	{
		CTORATstpTradingFeeField* task_data = new CTORATstpTradingFeeField();
		*task_data = *pTradingFeeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryInvestorTradingFee(CTORATstpInvestorTradingFeeField* pInvestorTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORTRADINGFEE;
	if (pInvestorTradingFeeField)
	{
		CTORATstpInvestorTradingFeeField* task_data = new CTORATstpInvestorTradingFeeField();
		*task_data = *pInvestorTradingFeeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryIPOQuota(CTORATstpIPOQuotaField* pIPOQuotaField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOQUOTA;
	if (pIPOQuotaField)
	{
		CTORATstpIPOQuotaField* task_data = new CTORATstpIPOQuotaField();
		*task_data = *pIPOQuotaField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryOrderFundDetail(CTORATstpOrderFundDetailField* pOrderFundDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERFUNDDETAIL;
	if (pOrderFundDetailField)
	{
		CTORATstpOrderFundDetailField* task_data = new CTORATstpOrderFundDetailField();
		*task_data = *pOrderFundDetailField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryFundTransferDetail(CTORATstpFundTransferDetailField* pFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUNDTRANSFERDETAIL;
	if (pFundTransferDetailField)
	{
		CTORATstpFundTransferDetailField* task_data = new CTORATstpFundTransferDetailField();
		*task_data = *pFundTransferDetailField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPositionTransferDetail(CTORATstpPositionTransferDetailField* pPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONTRANSFERDETAIL;
	if (pPositionTransferDetailField)
	{
		CTORATstpPositionTransferDetailField* task_data = new CTORATstpPositionTransferDetailField();
		*task_data = *pPositionTransferDetailField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPeripheryPositionTransferDetail(CTORATstpPeripheryPositionTransferDetailField* pPeripheryPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPERIPHERYPOSITIONTRANSFERDETAIL;
	if (pPeripheryPositionTransferDetailField)
	{
		CTORATstpPeripheryPositionTransferDetailField* task_data = new CTORATstpPeripheryPositionTransferDetailField();
		*task_data = *pPeripheryPositionTransferDetailField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPeripheryFundTransferDetail(CTORATstpPeripheryFundTransferDetailField* pPeripheryFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPERIPHERYFUNDTRANSFERDETAIL;
	if (pPeripheryFundTransferDetailField)
	{
		CTORATstpPeripheryFundTransferDetailField* task_data = new CTORATstpPeripheryFundTransferDetailField();
		*task_data = *pPeripheryFundTransferDetailField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryBondConversionInfo(CTORATstpBondConversionInfoField* pBondConversionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYBONDCONVERSIONINFO;
	if (pBondConversionInfoField)
	{
		CTORATstpBondConversionInfoField* task_data = new CTORATstpBondConversionInfoField();
		*task_data = *pBondConversionInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryBondPutbackInfo(CTORATstpBondPutbackInfoField* pBondPutbackInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYBONDPUTBACKINFO;
	if (pBondPutbackInfoField)
	{
		CTORATstpBondPutbackInfoField* task_data = new CTORATstpBondPutbackInfoField();
		*task_data = *pBondPutbackInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryInvestorCondOrderLimitParam(CTORATstpInvestorCondOrderLimitParamField* pInvestorCondOrderLimitParamField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORCONDORDERLIMITPARAM;
	if (pInvestorCondOrderLimitParamField)
	{
		CTORATstpInvestorCondOrderLimitParamField* task_data = new CTORATstpInvestorCondOrderLimitParamField();
		*task_data = *pInvestorCondOrderLimitParamField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryConditionOrder(CTORATstpConditionOrderField* pConditionOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDITIONORDER;
	if (pConditionOrderField)
	{
		CTORATstpConditionOrderField* task_data = new CTORATstpConditionOrderField();
		*task_data = *pConditionOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryCondOrderAction(CTORATstpCondOrderActionField* pCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDORDERACTION;
	if (pCondOrderActionField)
	{
		CTORATstpCondOrderActionField* task_data = new CTORATstpCondOrderActionField();
		*task_data = *pCondOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGNOTICE;
	if (pTradingNoticeField)
	{
		CTORATstpTradingNoticeField* task_data = new CTORATstpTradingNoticeField();
		*task_data = *pTradingNoticeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryIPONumberResult(CTORATstpIPONumberResultField* pIPONumberResultField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPONUMBERRESULT;
	if (pIPONumberResultField)
	{
		CTORATstpIPONumberResultField* task_data = new CTORATstpIPONumberResultField();
		*task_data = *pIPONumberResultField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryIPOMatchNumberResult(CTORATstpIPOMatchNumberResultField* pIPOMatchNumberResultField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOMATCHNUMBERRESULT;
	if (pIPOMatchNumberResultField)
	{
		CTORATstpIPOMatchNumberResultField* task_data = new CTORATstpIPOMatchNumberResultField();
		*task_data = *pIPOMatchNumberResultField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryShareholderSpecPrivilege(CTORATstpShareholderSpecPrivilegeField* pShareholderSpecPrivilegeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSHAREHOLDERSPECPRIVILEGE;
	if (pShareholderSpecPrivilegeField)
	{
		CTORATstpShareholderSpecPrivilegeField* task_data = new CTORATstpShareholderSpecPrivilegeField();
		*task_data = *pShareholderSpecPrivilegeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryMarket(CTORATstpMarketField* pMarketField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKET;
	if (pMarketField)
	{
		CTORATstpMarketField* task_data = new CTORATstpMarketField();
		*task_data = *pMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryETFFile(CTORATstpETFFileField* pETFFileField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYETFFILE;
	if (pETFFileField)
	{
		CTORATstpETFFileField* task_data = new CTORATstpETFFileField();
		*task_data = *pETFFileField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryETFBasket(CTORATstpETFBasketField* pETFBasketField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYETFBASKET;
	if (pETFBasketField)
	{
		CTORATstpETFBasketField* task_data = new CTORATstpETFBasketField();
		*task_data = *pETFBasketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryInvestorPositionLimit(CTORATstpInvestorPositionLimitField* pInvestorPositionLimitField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORPOSITIONLIMIT;
	if (pInvestorPositionLimitField)
	{
		CTORATstpInvestorPositionLimitField* task_data = new CTORATstpInvestorPositionLimitField();
		*task_data = *pInvestorPositionLimitField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQrySZSEImcParams(CTORATstpSZSEImcParamsField* pSZSEImcParamsField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSZSEIMCPARAMS;
	if (pSZSEImcParamsField)
	{
		CTORATstpSZSEImcParamsField* task_data = new CTORATstpSZSEImcParamsField();
		*task_data = *pSZSEImcParamsField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQrySZSEImcExchangeRate(CTORATstpSZSEImcExchangeRateField* pSZSEImcExchangeRateField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSZSEIMCEXCHANGERATE;
	if (pSZSEImcExchangeRateField)
	{
		CTORATstpSZSEImcExchangeRateField* task_data = new CTORATstpSZSEImcExchangeRateField();
		*task_data = *pSZSEImcExchangeRateField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQrySZSEHKPriceTickInfo(CTORATstpSZSEHKPriceTickInfoField* pSZSEHKPriceTickInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSZSEHKPRICETICKINFO;
	if (pSZSEHKPriceTickInfoField)
	{
		CTORATstpSZSEHKPriceTickInfoField* task_data = new CTORATstpSZSEHKPriceTickInfoField();
		*task_data = *pSZSEHKPriceTickInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryLofFundInfo(CTORATstpLofFundInfoField* pLofFundInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOFFUNDINFO;
	if (pLofFundInfoField)
	{
		CTORATstpLofFundInfoField* task_data = new CTORATstpLofFundInfoField();
		*task_data = *pLofFundInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPledgePosition(CTORATstpPledgePositionField* pPledgePositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPLEDGEPOSITION;
	if (pPledgePositionField)
	{
		CTORATstpPledgePositionField* task_data = new CTORATstpPledgePositionField();
		*task_data = *pPledgePositionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPledgeInfo(CTORATstpPledgeInfoField* pPledgeInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPLEDGEINFO;
	if (pPledgeInfoField)
	{
		CTORATstpPledgeInfoField* task_data = new CTORATstpPledgeInfoField();
		*task_data = *pPledgeInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQrySystemNodeInfo(CTORATstpSystemNodeInfoField* pSystemNodeInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSYSTEMNODEINFO;
	if (pSystemNodeInfoField)
	{
		CTORATstpSystemNodeInfoField* task_data = new CTORATstpSystemNodeInfoField();
		*task_data = *pSystemNodeInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryStandardBondPosition(CTORATstpStandardBondPositionField* pStandardBondPositionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSTANDARDBONDPOSITION;
	if (pStandardBondPositionField)
	{
		CTORATstpStandardBondPositionField* task_data = new CTORATstpStandardBondPositionField();
		*task_data = *pStandardBondPositionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryPrematurityRepoOrder(CTORATstpPrematurityRepoOrderField* pPrematurityRepoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPREMATURITYREPOORDER;
	if (pPrematurityRepoOrderField)
	{
		CTORATstpPrematurityRepoOrderField* task_data = new CTORATstpPrematurityRepoOrderField();
		*task_data = *pPrematurityRepoOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryNegoOrder(CTORATstpNegoOrderField* pNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYNEGOORDER;
	if (pNegoOrderField)
	{
		CTORATstpNegoOrderField* task_data = new CTORATstpNegoOrderField();
		*task_data = *pNegoOrderField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryNegoOrderAction(CTORATstpNegoOrderActionField* pNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYNEGOORDERACTION;
	if (pNegoOrderActionField)
	{
		CTORATstpNegoOrderActionField* task_data = new CTORATstpNegoOrderActionField();
		*task_data = *pNegoOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryNegoTrade(CTORATstpNegoTradeField* pNegoTradeField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYNEGOTRADE;
	if (pNegoTradeField)
	{
		CTORATstpNegoTradeField* task_data = new CTORATstpNegoTradeField();
		*task_data = *pNegoTradeField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void StockApi::OnRspQryNegotiationParam(CTORATstpNegotiationParamField* pNegotiationParamField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYNEGOTIATIONPARAM;
	if (pNegotiationParamField)
	{
		CTORATstpNegotiationParamField* task_data = new CTORATstpNegotiationParamField();
		*task_data = *pNegotiationParamField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void StockApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRSPERROR:
			{
				this->processRspError(&task);
				break;
			}

			case ONRSPGETCONNECTIONINFO:
			{
				this->processRspGetConnectionInfo(&task);
				break;
			}

			case ONRSPUSERLOGIN:
			{
				this->processRspUserLogin(&task);
				break;
			}

			case ONRSPUSERLOGOUT:
			{
				this->processRspUserLogout(&task);
				break;
			}

			case ONRSPUSERPASSWORDUPDATE:
			{
				this->processRspUserPasswordUpdate(&task);
				break;
			}

			case ONRSPINPUTDEVICESERIAL:
			{
				this->processRspInputDeviceSerial(&task);
				break;
			}

			case ONRSPORDERINSERT:
			{
				this->processRspOrderInsert(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONERRRTNORDERINSERT:
			{
				this->processErrRtnOrderInsert(&task);
				break;
			}

			case ONRTNTRADE:
			{
				this->processRtnTrade(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONERRRTNORDERACTION:
			{
				this->processErrRtnOrderAction(&task);
				break;
			}

			case ONRSPCONDORDERINSERT:
			{
				this->processRspCondOrderInsert(&task);
				break;
			}

			case ONRTNCONDORDER:
			{
				this->processRtnCondOrder(&task);
				break;
			}

			case ONERRRTNCONDORDERINSERT:
			{
				this->processErrRtnCondOrderInsert(&task);
				break;
			}

			case ONRSPCONDORDERACTION:
			{
				this->processRspCondOrderAction(&task);
				break;
			}

			case ONERRRTNCONDORDERACTION:
			{
				this->processErrRtnCondOrderAction(&task);
				break;
			}

			case ONRSPNEGOORDERINSERT:
			{
				this->processRspNegoOrderInsert(&task);
				break;
			}

			case ONRTNNEGOORDER:
			{
				this->processRtnNegoOrder(&task);
				break;
			}

			case ONERRRTNNEGOORDERINSERT:
			{
				this->processErrRtnNegoOrderInsert(&task);
				break;
			}

			case ONRTNNEGOTRADE:
			{
				this->processRtnNegoTrade(&task);
				break;
			}

			case ONRSPNEGOORDERACTION:
			{
				this->processRspNegoOrderAction(&task);
				break;
			}

			case ONERRRTNNEGOORDERACTION:
			{
				this->processErrRtnNegoOrderAction(&task);
				break;
			}

			case ONRSPORDERINSERTEX:
			{
				this->processRspOrderInsertEx(&task);
				break;
			}

			case ONRSPORDERACTIONEX:
			{
				this->processRspOrderActionEx(&task);
				break;
			}

			case ONRTNMARKETSTATUS:
			{
				this->processRtnMarketStatus(&task);
				break;
			}

			case ONRSPTRANSFERFUND:
			{
				this->processRspTransferFund(&task);
				break;
			}

			case ONERRRTNTRANSFERFUND:
			{
				this->processErrRtnTransferFund(&task);
				break;
			}

			case ONRTNTRANSFERFUND:
			{
				this->processRtnTransferFund(&task);
				break;
			}

			case ONRSPTRANSFERPOSITION:
			{
				this->processRspTransferPosition(&task);
				break;
			}

			case ONERRRTNTRANSFERPOSITION:
			{
				this->processErrRtnTransferPosition(&task);
				break;
			}

			case ONRTNTRANSFERPOSITION:
			{
				this->processRtnTransferPosition(&task);
				break;
			}

			case ONRTNPERIPHERYTRANSFERPOSITION:
			{
				this->processRtnPeripheryTransferPosition(&task);
				break;
			}

			case ONRTNPERIPHERYTRANSFERFUND:
			{
				this->processRtnPeripheryTransferFund(&task);
				break;
			}

			case ONRSPINQUIRYJZFUND:
			{
				this->processRspInquiryJZFund(&task);
				break;
			}

			case ONRSPINQUIRYBANKACCOUNTFUND:
			{
				this->processRspInquiryBankAccountFund(&task);
				break;
			}

			case ONRTNTRADINGNOTICE:
			{
				this->processRtnTradingNotice(&task);
				break;
			}

			case ONRSPINQUIRYMAXORDERVOLUME:
			{
				this->processRspInquiryMaxOrderVolume(&task);
				break;
			}

			case ONRSPINQUIRYTRADECONCENTRATION:
			{
				this->processRspInquiryTradeConcentration(&task);
				break;
			}

			case ONRSPMODIFYOPENPOSCOST:
			{
				this->processRspModifyOpenPosCost(&task);
				break;
			}

			case ONRSPINPUTNODEFUNDASSIGNMENT:
			{
				this->processRspInputNodeFundAssignment(&task);
				break;
			}

			case ONRSPINQUIRYNODEFUNDASSIGNMENT:
			{
				this->processRspInquiryNodeFundAssignment(&task);
				break;
			}

			case ONRSPQRYEXCHANGE:
			{
				this->processRspQryExchange(&task);
				break;
			}

			case ONRSPQRYSECURITY:
			{
				this->processRspQrySecurity(&task);
				break;
			}

			case ONRSPQRYIPOINFO:
			{
				this->processRspQryIPOInfo(&task);
				break;
			}

			case ONRSPQRYUSER:
			{
				this->processRspQryUser(&task);
				break;
			}

			case ONRSPQRYINVESTOR:
			{
				this->processRspQryInvestor(&task);
				break;
			}

			case ONRSPQRYSHAREHOLDERACCOUNT:
			{
				this->processRspQryShareholderAccount(&task);
				break;
			}

			case ONRSPQRYRATIONALINFO:
			{
				this->processRspQryRationalInfo(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYORDERACTION:
			{
				this->processRspQryOrderAction(&task);
				break;
			}

			case ONRSPQRYTRADE:
			{
				this->processRspQryTrade(&task);
				break;
			}

			case ONRSPQRYTRADINGACCOUNT:
			{
				this->processRspQryTradingAccount(&task);
				break;
			}

			case ONRSPQRYPOSITION:
			{
				this->processRspQryPosition(&task);
				break;
			}

			case ONRSPQRYTRADINGFEE:
			{
				this->processRspQryTradingFee(&task);
				break;
			}

			case ONRSPQRYINVESTORTRADINGFEE:
			{
				this->processRspQryInvestorTradingFee(&task);
				break;
			}

			case ONRSPQRYIPOQUOTA:
			{
				this->processRspQryIPOQuota(&task);
				break;
			}

			case ONRSPQRYORDERFUNDDETAIL:
			{
				this->processRspQryOrderFundDetail(&task);
				break;
			}

			case ONRSPQRYFUNDTRANSFERDETAIL:
			{
				this->processRspQryFundTransferDetail(&task);
				break;
			}

			case ONRSPQRYPOSITIONTRANSFERDETAIL:
			{
				this->processRspQryPositionTransferDetail(&task);
				break;
			}

			case ONRSPQRYPERIPHERYPOSITIONTRANSFERDETAIL:
			{
				this->processRspQryPeripheryPositionTransferDetail(&task);
				break;
			}

			case ONRSPQRYPERIPHERYFUNDTRANSFERDETAIL:
			{
				this->processRspQryPeripheryFundTransferDetail(&task);
				break;
			}

			case ONRSPQRYBONDCONVERSIONINFO:
			{
				this->processRspQryBondConversionInfo(&task);
				break;
			}

			case ONRSPQRYBONDPUTBACKINFO:
			{
				this->processRspQryBondPutbackInfo(&task);
				break;
			}

			case ONRSPQRYINVESTORCONDORDERLIMITPARAM:
			{
				this->processRspQryInvestorCondOrderLimitParam(&task);
				break;
			}

			case ONRSPQRYCONDITIONORDER:
			{
				this->processRspQryConditionOrder(&task);
				break;
			}

			case ONRSPQRYCONDORDERACTION:
			{
				this->processRspQryCondOrderAction(&task);
				break;
			}

			case ONRSPQRYTRADINGNOTICE:
			{
				this->processRspQryTradingNotice(&task);
				break;
			}

			case ONRSPQRYIPONUMBERRESULT:
			{
				this->processRspQryIPONumberResult(&task);
				break;
			}

			case ONRSPQRYIPOMATCHNUMBERRESULT:
			{
				this->processRspQryIPOMatchNumberResult(&task);
				break;
			}

			case ONRSPQRYSHAREHOLDERSPECPRIVILEGE:
			{
				this->processRspQryShareholderSpecPrivilege(&task);
				break;
			}

			case ONRSPQRYMARKET:
			{
				this->processRspQryMarket(&task);
				break;
			}

			case ONRSPQRYETFFILE:
			{
				this->processRspQryETFFile(&task);
				break;
			}

			case ONRSPQRYETFBASKET:
			{
				this->processRspQryETFBasket(&task);
				break;
			}

			case ONRSPQRYINVESTORPOSITIONLIMIT:
			{
				this->processRspQryInvestorPositionLimit(&task);
				break;
			}

			case ONRSPQRYSZSEIMCPARAMS:
			{
				this->processRspQrySZSEImcParams(&task);
				break;
			}

			case ONRSPQRYSZSEIMCEXCHANGERATE:
			{
				this->processRspQrySZSEImcExchangeRate(&task);
				break;
			}

			case ONRSPQRYSZSEHKPRICETICKINFO:
			{
				this->processRspQrySZSEHKPriceTickInfo(&task);
				break;
			}

			case ONRSPQRYLOFFUNDINFO:
			{
				this->processRspQryLofFundInfo(&task);
				break;
			}

			case ONRSPQRYPLEDGEPOSITION:
			{
				this->processRspQryPledgePosition(&task);
				break;
			}

			case ONRSPQRYPLEDGEINFO:
			{
				this->processRspQryPledgeInfo(&task);
				break;
			}

			case ONRSPQRYSYSTEMNODEINFO:
			{
				this->processRspQrySystemNodeInfo(&task);
				break;
			}

			case ONRSPQRYSTANDARDBONDPOSITION:
			{
				this->processRspQryStandardBondPosition(&task);
				break;
			}

			case ONRSPQRYPREMATURITYREPOORDER:
			{
				this->processRspQryPrematurityRepoOrder(&task);
				break;
			}

			case ONRSPQRYNEGOORDER:
			{
				this->processRspQryNegoOrder(&task);
				break;
			}

			case ONRSPQRYNEGOORDERACTION:
			{
				this->processRspQryNegoOrderAction(&task);
				break;
			}

			case ONRSPQRYNEGOTRADE:
			{
				this->processRspQryNegoTrade(&task);
				break;
			}

			case ONRSPQRYNEGOTIATIONPARAM:
			{
				this->processRspQryNegotiationParam(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void StockApi::processFrontConnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void StockApi::processFrontDisconnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void StockApi::processRspError(Task* task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void StockApi::processRspGetConnectionInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConnectionInfoField* task_data = (CTORATstpConnectionInfoField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["InnerPort"] = task_data->InnerPort;
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGetConnectionInfo(data, error, task->task_id);
};

void StockApi::processRspUserLogin(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspUserLoginField* task_data = (CTORATstpRspUserLoginField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["LogInAccount"] = toUtf(task_data->LogInAccount);
		data["LogInAccountType"] = task_data->LogInAccountType;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["MaxOrderRef"] = task_data->MaxOrderRef;
		data["PrivateFlowCount"] = task_data->PrivateFlowCount;
		data["PublicFlowCount"] = task_data->PublicFlowCount;
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["SystemName"] = toUtf(task_data->SystemName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["UserID"] = toUtf(task_data->UserID);
		data["UserName"] = toUtf(task_data->UserName);
		data["UserType"] = task_data->UserType;
		data["OrderInsertCommFlux"] = task_data->OrderInsertCommFlux;
		data["OrderActionCommFlux"] = task_data->OrderActionCommFlux;
		data["PasswordExpiryDate"] = toUtf(task_data->PasswordExpiryDate);
		data["NeedUpdatePassword"] = task_data->NeedUpdatePassword;
		data["CertSerial"] = toUtf(task_data->CertSerial);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["NodeRef"] = task_data->NodeRef;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id);
};

void StockApi::processRspUserLogout(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserLogoutField* task_data = (CTORATstpUserLogoutField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id);
};

void StockApi::processRspUserPasswordUpdate(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserPasswordUpdateField* task_data = (CTORATstpUserPasswordUpdateField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		data["UserRequestID"] = task_data->UserRequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id);
};

void StockApi::processRspInputDeviceSerial(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInputDeviceSerialField* task_data = (CTORATstpRspInputDeviceSerialField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputDeviceSerial(data, error, task->task_id);
};

void StockApi::processRspOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderField* task_data = (CTORATstpInputOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["Operway"] = task_data->Operway;
		data["OrderRef"] = task_data->OrderRef;
		data["LotType"] = task_data->LotType;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderField* task_data = (CTORATstpOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["LotType"] = task_data->LotType;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["Operway"] = task_data->Operway;
		data["CondCheck"] = task_data->CondCheck;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["Turnover"] = task_data->Turnover;
		data["OrderType"] = task_data->OrderType;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditQuotaID"] = toUtf(task_data->CreditQuotaID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RtnFloatInfo"] = task_data->RtnFloatInfo;
		data["RtnIntInfo"] = task_data->RtnIntInfo;
		data["RtnFloatInfo1"] = task_data->RtnFloatInfo1;
		data["RtnFloatInfo2"] = task_data->RtnFloatInfo2;
		data["RtnFloatInfo3"] = task_data->RtnFloatInfo3;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void StockApi::processErrRtnOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderField* task_data = (CTORATstpInputOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["Operway"] = task_data->Operway;
		data["OrderRef"] = task_data->OrderRef;
		data["LotType"] = task_data->LotType;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradeField* task_data = (CTORATstpTradeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderRef"] = task_data->OrderRef;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		delete task_data;
	}
	this->onRtnTrade(data);
};

void StockApi::processRspOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionField* task_data = (CTORATstpInputOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionField* task_data = (CTORATstpInputOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderAction(data, error, task->task_id);
};

void StockApi::processRspCondOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderField* task_data = (CTORATstpInputCondOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Operway"] = task_data->Operway;
		data["LotType"] = task_data->LotType;
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["TriggerOrderVolumeType"] = task_data->TriggerOrderVolumeType;
		data["TriggerOrderPriceType"] = task_data->TriggerOrderPriceType;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["ConditionPrice"] = task_data->ConditionPrice;
		data["PriceTicks"] = task_data->PriceTicks;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["RelativeFrontID"] = task_data->RelativeFrontID;
		data["RelativeSessionID"] = task_data->RelativeSessionID;
		data["RelativeParam"] = toUtf(task_data->RelativeParam);
		data["AppendContingentCondition"] = task_data->AppendContingentCondition;
		data["AppendConditionPrice"] = task_data->AppendConditionPrice;
		data["AppendRelativeFrontID"] = task_data->AppendRelativeFrontID;
		data["AppendRelativeSessionID"] = task_data->AppendRelativeSessionID;
		data["AppendRelativeParam"] = toUtf(task_data->AppendRelativeParam);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnCondOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConditionOrderField* task_data = (CTORATstpConditionOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Operway"] = task_data->Operway;
		data["LotType"] = task_data->LotType;
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["TriggerOrderVolumeType"] = task_data->TriggerOrderVolumeType;
		data["TriggerOrderPriceType"] = task_data->TriggerOrderPriceType;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["ConditionPrice"] = task_data->ConditionPrice;
		data["PriceTicks"] = task_data->PriceTicks;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["RelativeFrontID"] = task_data->RelativeFrontID;
		data["RelativeSessionID"] = task_data->RelativeSessionID;
		data["RelativeParam"] = toUtf(task_data->RelativeParam);
		data["AppendContingentCondition"] = task_data->AppendContingentCondition;
		data["AppendConditionPrice"] = task_data->AppendConditionPrice;
		data["AppendRelativeFrontID"] = task_data->AppendRelativeFrontID;
		data["AppendRelativeSessionID"] = task_data->AppendRelativeSessionID;
		data["AppendRelativeParam"] = toUtf(task_data->AppendRelativeParam);
		data["RequestID"] = task_data->RequestID;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["CondOrderStatus"] = task_data->CondOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ActiveDate"] = toUtf(task_data->ActiveDate);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	this->onRtnCondOrder(data);
};

void StockApi::processErrRtnCondOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderField* task_data = (CTORATstpInputCondOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Operway"] = task_data->Operway;
		data["LotType"] = task_data->LotType;
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["TriggerOrderVolumeType"] = task_data->TriggerOrderVolumeType;
		data["TriggerOrderPriceType"] = task_data->TriggerOrderPriceType;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["ConditionPrice"] = task_data->ConditionPrice;
		data["PriceTicks"] = task_data->PriceTicks;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["RelativeFrontID"] = task_data->RelativeFrontID;
		data["RelativeSessionID"] = task_data->RelativeSessionID;
		data["RelativeParam"] = toUtf(task_data->RelativeParam);
		data["AppendContingentCondition"] = task_data->AppendContingentCondition;
		data["AppendConditionPrice"] = task_data->AppendConditionPrice;
		data["AppendRelativeFrontID"] = task_data->AppendRelativeFrontID;
		data["AppendRelativeSessionID"] = task_data->AppendRelativeSessionID;
		data["AppendRelativeParam"] = toUtf(task_data->AppendRelativeParam);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderInsert(data, error, task->task_id);
};

void StockApi::processRspCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderActionField* task_data = (CTORATstpInputCondOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["ActionFlag"] = task_data->ActionFlag;
		data["Operway"] = task_data->Operway;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderActionField* task_data = (CTORATstpInputCondOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["ActionFlag"] = task_data->ActionFlag;
		data["Operway"] = task_data->Operway;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderAction(data, error, task->task_id);
};

void StockApi::processRspNegoOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderField* task_data = (CTORATstpInputNegoOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Contractor"] = toUtf(task_data->Contractor);
		data["ContractorInfo"] = toUtf(task_data->ContractorInfo);
		data["ConfirmID"] = toUtf(task_data->ConfirmID);
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspNegoOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnNegoOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderField* task_data = (CTORATstpNegoOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Contractor"] = toUtf(task_data->Contractor);
		data["ContractorInfo"] = toUtf(task_data->ContractorInfo);
		data["ConfirmID"] = toUtf(task_data->ConfirmID);
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	this->onRtnNegoOrder(data);
};

void StockApi::processErrRtnNegoOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderField* task_data = (CTORATstpInputNegoOrderField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Contractor"] = toUtf(task_data->Contractor);
		data["ContractorInfo"] = toUtf(task_data->ContractorInfo);
		data["ConfirmID"] = toUtf(task_data->ConfirmID);
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnNegoOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnNegoTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoTradeField* task_data = (CTORATstpNegoTradeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["CounterpartyShareholderID"] = toUtf(task_data->CounterpartyShareholderID);
		delete task_data;
	}
	this->onRtnNegoTrade(data);
};

void StockApi::processRspNegoOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderActionField* task_data = (CTORATstpInputNegoOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspNegoOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnNegoOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderActionField* task_data = (CTORATstpInputNegoOrderActionField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnNegoOrderAction(data, error, task->task_id);
};

void StockApi::processRspOrderInsertEx(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderExField* task_data = (CTORATstpInputOrderExField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["Operway"] = task_data->Operway;
		data["OrderRef"] = task_data->OrderRef;
		data["LotType"] = task_data->LotType;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["NodeRef"] = task_data->NodeRef;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsertEx(data, error, task->task_id);
};

void StockApi::processRspOrderActionEx(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionExField* task_data = (CTORATstpInputOrderActionExField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderActionEx(data, error, task->task_id);
};

void StockApi::processRtnMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketStatusField* task_data = (CTORATstpMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnMarketStatus(data);
};

void StockApi::processRspTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferFundField* task_data = (CTORATstpInputTransferFundField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ApplySerial"] = task_data->ApplySerial;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["BankID"] = task_data->BankID;
		data["AccountPassword"] = toUtf(task_data->AccountPassword);
		data["BankPassword"] = toUtf(task_data->BankPassword);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["RealAmount"] = task_data->RealAmount;
		data["ForceFlag"] = task_data->ForceFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferFund(data, error, task->task_id);
};

void StockApi::processErrRtnTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferFundField* task_data = (CTORATstpInputTransferFundField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ApplySerial"] = task_data->ApplySerial;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["BankID"] = task_data->BankID;
		data["AccountPassword"] = toUtf(task_data->AccountPassword);
		data["BankPassword"] = toUtf(task_data->BankPassword);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["RealAmount"] = task_data->RealAmount;
		data["ForceFlag"] = task_data->ForceFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferFund(data, error, task->task_id);
};

void StockApi::processRtnTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTransferFundField* task_data = (CTORATstpTransferFundField*)task->task_data;
		data["FundSerial"] = task_data->FundSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["BankID"] = task_data->BankID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		delete task_data;
	}
	this->onRtnTransferFund(data);
};

void StockApi::processRspTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferPositionField* task_data = (CTORATstpInputTransferPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ApplySerial"] = task_data->ApplySerial;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Volume"] = task_data->Volume;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["UserRequestID"] = task_data->UserRequestID;
		data["MarketID"] = task_data->MarketID;
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferPosition(data, error, task->task_id);
};

void StockApi::processErrRtnTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferPositionField* task_data = (CTORATstpInputTransferPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ApplySerial"] = task_data->ApplySerial;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Volume"] = task_data->Volume;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["UserRequestID"] = task_data->UserRequestID;
		data["MarketID"] = task_data->MarketID;
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferPosition(data, error, task->task_id);
};

void StockApi::processRtnTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTransferPositionField* task_data = (CTORATstpTransferPositionField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferDirection"] = task_data->TransferDirection;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayBSVolume"] = task_data->TodayBSVolume;
		data["TodayPRVolume"] = task_data->TodayPRVolume;
		data["TodaySMVolume"] = task_data->TodaySMVolume;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		delete task_data;
	}
	this->onRtnTransferPosition(data);
};

void StockApi::processRtnPeripheryTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryTransferPositionField* task_data = (CTORATstpPeripheryTransferPositionField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayPRPos"] = task_data->TodayPRPos;
		data["HistoryPos"] = task_data->HistoryPos;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferReason"] = toUtf(task_data->TransferReason);
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["RepealDate"] = toUtf(task_data->RepealDate);
		data["RepealTime"] = toUtf(task_data->RepealTime);
		data["RepealReason"] = toUtf(task_data->RepealReason);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["TodaySMPos"] = task_data->TodaySMPos;
		delete task_data;
	}
	this->onRtnPeripheryTransferPosition(data);
};

void StockApi::processRtnPeripheryTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryTransferFundField* task_data = (CTORATstpPeripheryTransferFundField*)task->task_data;
		data["FundSerial"] = task_data->FundSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["Amount"] = task_data->Amount;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TransferReason"] = toUtf(task_data->TransferReason);
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["RepealDate"] = toUtf(task_data->RepealDate);
		data["RepealTime"] = toUtf(task_data->RepealTime);
		data["RepealReason"] = toUtf(task_data->RepealReason);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		delete task_data;
	}
	this->onRtnPeripheryTransferFund(data);
};

void StockApi::processRspInquiryJZFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryJZFundField* task_data = (CTORATstpRspInquiryJZFundField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["UsefulMoney"] = task_data->UsefulMoney;
		data["FetchLimit"] = task_data->FetchLimit;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryJZFund(data, error, task->task_id);
};

void StockApi::processRspInquiryBankAccountFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryBankAccountFundField* task_data = (CTORATstpRspInquiryBankAccountFundField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["BankID"] = task_data->BankID;
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["Balance"] = task_data->Balance;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryBankAccountFund(data, error, task->task_id);
};

void StockApi::processRtnTradingNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingNoticeField* task_data = (CTORATstpTradingNoticeField*)task->task_data;
		data["NoticeSerial"] = task_data->NoticeSerial;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Content"] = toUtf(task_data->Content);
		data["OperatorID"] = toUtf(task_data->OperatorID);
		delete task_data;
	}
	this->onRtnTradingNotice(data);
};

void StockApi::processRspInquiryMaxOrderVolume(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryMaxOrderVolumeField* task_data = (CTORATstpRspInquiryMaxOrderVolumeField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["LotType"] = task_data->LotType;
		data["MaxVolume"] = task_data->MaxVolume;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxOrderVolume(data, error, task->task_id);
};

void StockApi::processRspInquiryTradeConcentration(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInquiryTradeConcentrationField* task_data = (CTORATstpInquiryTradeConcentrationField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ConcentrationRatio1"] = task_data->ConcentrationRatio1;
		data["ConcentrationRatio2"] = task_data->ConcentrationRatio2;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryTradeConcentration(data, error, task->task_id);
};

void StockApi::processRspModifyOpenPosCost(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpReqModifyOpenPosCostField* task_data = (CTORATstpReqModifyOpenPosCostField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["OpenPosCost"] = task_data->OpenPosCost;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspModifyOpenPosCost(data, error, task->task_id);
};

void StockApi::processRspInputNodeFundAssignment(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNodeFundAssignmentField* task_data = (CTORATstpInputNodeFundAssignmentField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["NodeID1"] = task_data->NodeID1;
		data["AmtRatio1"] = task_data->AmtRatio1;
		data["NodeID2"] = task_data->NodeID2;
		data["AmtRatio2"] = task_data->AmtRatio2;
		data["NodeID3"] = task_data->NodeID3;
		data["AmtRatio3"] = task_data->AmtRatio3;
		data["NodeID4"] = task_data->NodeID4;
		data["AmtRatio4"] = task_data->AmtRatio4;
		data["NodeID5"] = task_data->NodeID5;
		data["AmtRatio5"] = task_data->AmtRatio5;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputNodeFundAssignment(data, error, task->task_id);
};

void StockApi::processRspInquiryNodeFundAssignment(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryNodeFundAssignmentField* task_data = (CTORATstpRspInquiryNodeFundAssignmentField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["NodeID1"] = task_data->NodeID1;
		data["AmtRatio1"] = task_data->AmtRatio1;
		data["NodeID2"] = task_data->NodeID2;
		data["AmtRatio2"] = task_data->AmtRatio2;
		data["NodeID3"] = task_data->NodeID3;
		data["AmtRatio3"] = task_data->AmtRatio3;
		data["NodeID4"] = task_data->NodeID4;
		data["AmtRatio4"] = task_data->AmtRatio4;
		data["NodeID5"] = task_data->NodeID5;
		data["AmtRatio5"] = task_data->AmtRatio5;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryNodeFundAssignment(data, error, task->task_id);
};

void StockApi::processRspQryExchange(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpExchangeField* task_data = (CTORATstpExchangeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["DataSyncStatus"] = task_data->DataSyncStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchange(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySecurity(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityField* task_data = (CTORATstpSecurityField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["ShortSecurityName"] = toUtf(task_data->ShortSecurityName);
		data["UnderlyingSecurityID"] = toUtf(task_data->UnderlyingSecurityID);
		data["MarketID"] = task_data->MarketID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["OrderUnit"] = task_data->OrderUnit;
		data["LimitBuyTradingUnit"] = task_data->LimitBuyTradingUnit;
		data["MaxLimitOrderBuyVolume"] = task_data->MaxLimitOrderBuyVolume;
		data["MinLimitOrderBuyVolume"] = task_data->MinLimitOrderBuyVolume;
		data["LimitSellTradingUnit"] = task_data->LimitSellTradingUnit;
		data["MaxLimitOrderSellVolume"] = task_data->MaxLimitOrderSellVolume;
		data["MinLimitOrderSellVolume"] = task_data->MinLimitOrderSellVolume;
		data["MarketBuyTradingUnit"] = task_data->MarketBuyTradingUnit;
		data["MaxMarketOrderBuyVolume"] = task_data->MaxMarketOrderBuyVolume;
		data["MinMarketOrderBuyVolume"] = task_data->MinMarketOrderBuyVolume;
		data["MarketSellTradingUnit"] = task_data->MarketSellTradingUnit;
		data["MaxMarketOrderSellVolume"] = task_data->MaxMarketOrderSellVolume;
		data["MinMarketOrderSellVolume"] = task_data->MinMarketOrderSellVolume;
		data["FixPriceBuyTradingUnit"] = task_data->FixPriceBuyTradingUnit;
		data["MaxFixPriceOrderBuyVolume"] = task_data->MaxFixPriceOrderBuyVolume;
		data["MinFixPriceOrderBuyVolume"] = task_data->MinFixPriceOrderBuyVolume;
		data["FixPriceSellTradingUnit"] = task_data->FixPriceSellTradingUnit;
		data["MaxFixPriceOrderSellVolume"] = task_data->MaxFixPriceOrderSellVolume;
		data["MinFixPriceOrderSellVolume"] = task_data->MinFixPriceOrderSellVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["ParValue"] = task_data->ParValue;
		data["SecurityStatus"] = task_data->SecurityStatus;
		data["BondInterest"] = task_data->BondInterest;
		data["ConversionRate"] = task_data->ConversionRate;
		data["TotalEquity"] = task_data->TotalEquity;
		data["CirculationEquity"] = task_data->CirculationEquity;
		data["bPriceLimit"] = task_data->bPriceLimit;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecurity(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOInfoField* task_data = (CTORATstpIPOInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["MarketID"] = task_data->MarketID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["MinPrice"] = task_data->MinPrice;
		data["CurrencyID"] = task_data->CurrencyID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["UnderlyingSecurityID"] = toUtf(task_data->UnderlyingSecurityID);
		data["UnderlyingSecurityName"] = toUtf(task_data->UnderlyingSecurityName);
		data["MinVolume"] = task_data->MinVolume;
		data["MaxVolume"] = task_data->MaxVolume;
		data["VolumeUnit"] = task_data->VolumeUnit;
		data["IssueMode"] = task_data->IssueMode;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["MaxPrice"] = task_data->MaxPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryUser(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserField* task_data = (CTORATstpUserField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["UserName"] = toUtf(task_data->UserName);
		data["UserType"] = task_data->UserType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["LoginLimit"] = task_data->LoginLimit;
		data["LoginStatus"] = task_data->LoginStatus;
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["CloseDate"] = toUtf(task_data->CloseDate);
		data["OrderInsertCommFlux"] = task_data->OrderInsertCommFlux;
		data["OrderActionCommFlux"] = task_data->OrderActionCommFlux;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryUser(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestor(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorField* task_data = (CTORATstpInvestorField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InvestorType"] = task_data->InvestorType;
		data["InvestorName"] = toUtf(task_data->InvestorName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdCardNo"] = toUtf(task_data->IdCardNo);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["CloseDate"] = toUtf(task_data->CloseDate);
		data["TradingStatus"] = task_data->TradingStatus;
		data["Operways"] = toUtf(task_data->Operways);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["Email"] = toUtf(task_data->Email);
		data["Fax"] = toUtf(task_data->Fax);
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["ProfInvestorType"] = task_data->ProfInvestorType;
		data["PlanType"] = task_data->PlanType;
		data["AllowSelfSwitchPlan"] = task_data->AllowSelfSwitchPlan;
		data["Remark"] = toUtf(task_data->Remark);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryShareholderAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpShareholderAccountField* task_data = (CTORATstpShareholderAccountField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["MarketID"] = task_data->MarketID;
		data["BSWhiteListCtl"] = task_data->BSWhiteListCtl;
		data["MainFlag"] = task_data->MainFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderAccount(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryRationalInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRationalInfoField* task_data = (CTORATstpRationalInfoField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Price"] = task_data->Price;
		data["MarketID"] = task_data->MarketID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["UnderlyingSecurityID"] = toUtf(task_data->UnderlyingSecurityID);
		data["UnderlyingSecurityName"] = toUtf(task_data->UnderlyingSecurityName);
		data["MinVolume"] = task_data->MinVolume;
		data["MaxVolume"] = task_data->MaxVolume;
		data["VolumeUnit"] = task_data->VolumeUnit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRationalInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderField* task_data = (CTORATstpOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["LotType"] = task_data->LotType;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["Operway"] = task_data->Operway;
		data["CondCheck"] = task_data->CondCheck;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["Turnover"] = task_data->Turnover;
		data["OrderType"] = task_data->OrderType;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditQuotaID"] = toUtf(task_data->CreditQuotaID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RtnFloatInfo"] = task_data->RtnFloatInfo;
		data["RtnIntInfo"] = task_data->RtnIntInfo;
		data["RtnFloatInfo1"] = task_data->RtnFloatInfo1;
		data["RtnFloatInfo2"] = task_data->RtnFloatInfo2;
		data["RtnFloatInfo3"] = task_data->RtnFloatInfo3;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderActionField* task_data = (CTORATstpOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["CancelOrderLocalID"] = toUtf(task_data->CancelOrderLocalID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ActionUser"] = toUtf(task_data->ActionUser);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["RequestID"] = task_data->RequestID;
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["CancelOrderType"] = task_data->CancelOrderType;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradeField* task_data = (CTORATstpTradeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderRef"] = task_data->OrderRef;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingAccountField* task_data = (CTORATstpTradingAccountField*)task->task_data;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["PreDeposit"] = task_data->PreDeposit;
		data["UsefulMoney"] = task_data->UsefulMoney;
		data["FetchLimit"] = task_data->FetchLimit;
		data["PreUnDeliveredMoney"] = task_data->PreUnDeliveredMoney;
		data["UnDeliveredMoney"] = task_data->UnDeliveredMoney;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FrozenCash"] = task_data->FrozenCash;
		data["UnDeliveredFrozenCash"] = task_data->UnDeliveredFrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["UnDeliveredFrozenCommission"] = task_data->UnDeliveredFrozenCommission;
		data["Commission"] = task_data->Commission;
		data["UnDeliveredCommission"] = task_data->UnDeliveredCommission;
		data["AccountType"] = task_data->AccountType;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BankID"] = task_data->BankID;
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["RoyaltyIn"] = task_data->RoyaltyIn;
		data["RoyaltyOut"] = task_data->RoyaltyOut;
		data["CreditSellAmount"] = task_data->CreditSellAmount;
		data["CreditSellUseAmount"] = task_data->CreditSellUseAmount;
		data["VirtualAssets"] = task_data->VirtualAssets;
		data["CreditSellFrozenAmount"] = task_data->CreditSellFrozenAmount;
		data["OwnerUnit"] = toUtf(task_data->OwnerUnit);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPositionField* task_data = (CTORATstpPositionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["HistoryPos"] = task_data->HistoryPos;
		data["HistoryPosFrozen"] = task_data->HistoryPosFrozen;
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayBSPosFrozen"] = task_data->TodayBSPosFrozen;
		data["TodayPRPos"] = task_data->TodayPRPos;
		data["TodayPRPosFrozen"] = task_data->TodayPRPosFrozen;
		data["TodaySMPos"] = task_data->TodaySMPos;
		data["TodaySMPosFrozen"] = task_data->TodaySMPosFrozen;
		data["HistoryPosPrice"] = task_data->HistoryPosPrice;
		data["TotalPosCost"] = task_data->TotalPosCost;
		data["PrePosition"] = task_data->PrePosition;
		data["AvailablePosition"] = task_data->AvailablePosition;
		data["CurrentPosition"] = task_data->CurrentPosition;
		data["OpenPosCost"] = task_data->OpenPosCost;
		data["CreditBuyPos"] = task_data->CreditBuyPos;
		data["CreditSellPos"] = task_data->CreditSellPos;
		data["TodayCreditSellPos"] = task_data->TodayCreditSellPos;
		data["CollateralOutPos"] = task_data->CollateralOutPos;
		data["RepayUntradeVolume"] = task_data->RepayUntradeVolume;
		data["RepayTransferUntradeVolume"] = task_data->RepayTransferUntradeVolume;
		data["CollateralBuyUntradeAmount"] = task_data->CollateralBuyUntradeAmount;
		data["CollateralBuyUntradeVolume"] = task_data->CollateralBuyUntradeVolume;
		data["CreditBuyAmount"] = task_data->CreditBuyAmount;
		data["CreditBuyUntradeAmount"] = task_data->CreditBuyUntradeAmount;
		data["CreditBuyFrozenMargin"] = task_data->CreditBuyFrozenMargin;
		data["CreditBuyInterestFee"] = task_data->CreditBuyInterestFee;
		data["CreditBuyUntradeVolume"] = task_data->CreditBuyUntradeVolume;
		data["CreditSellAmount"] = task_data->CreditSellAmount;
		data["CreditSellUntradeAmount"] = task_data->CreditSellUntradeAmount;
		data["CreditSellFrozenMargin"] = task_data->CreditSellFrozenMargin;
		data["CreditSellInterestFee"] = task_data->CreditSellInterestFee;
		data["CreditSellUntradeVolume"] = task_data->CreditSellUntradeVolume;
		data["CollateralInPos"] = task_data->CollateralInPos;
		data["CreditBuyFrozenCirculateMargin"] = task_data->CreditBuyFrozenCirculateMargin;
		data["CreditSellFrozenCirculateMargin"] = task_data->CreditSellFrozenCirculateMargin;
		data["CloseProfit"] = task_data->CloseProfit;
		data["TodayTotalOpenVolume"] = task_data->TodayTotalOpenVolume;
		data["TodayCommission"] = task_data->TodayCommission;
		data["TodayTotalBuyAmount"] = task_data->TodayTotalBuyAmount;
		data["TodayTotalSellAmount"] = task_data->TodayTotalSellAmount;
		data["PreFrozen"] = task_data->PreFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingFee(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingFeeField* task_data = (CTORATstpTradingFeeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BizClass"] = task_data->BizClass;
		data["StampTaxRatioByAmt"] = task_data->StampTaxRatioByAmt;
		data["StampTaxRatioByPar"] = task_data->StampTaxRatioByPar;
		data["StampTaxFeePerOrder"] = task_data->StampTaxFeePerOrder;
		data["StampTaxFeeByVolume"] = task_data->StampTaxFeeByVolume;
		data["StampTaxFeeMin"] = task_data->StampTaxFeeMin;
		data["StampTaxFeeMax"] = task_data->StampTaxFeeMax;
		data["TransferRatioByAmt"] = task_data->TransferRatioByAmt;
		data["TransferRatioByPar"] = task_data->TransferRatioByPar;
		data["TransferFeePerOrder"] = task_data->TransferFeePerOrder;
		data["TransferFeeByVolume"] = task_data->TransferFeeByVolume;
		data["TransferFeeMin"] = task_data->TransferFeeMin;
		data["TransferFeeMax"] = task_data->TransferFeeMax;
		data["HandlingRatioByAmt"] = task_data->HandlingRatioByAmt;
		data["HandlingRatioByPar"] = task_data->HandlingRatioByPar;
		data["HandlingFeePerOrder"] = task_data->HandlingFeePerOrder;
		data["HandlingFeeByVolume"] = task_data->HandlingFeeByVolume;
		data["HandlingFeeMin"] = task_data->HandlingFeeMin;
		data["HandlingFeeMax"] = task_data->HandlingFeeMax;
		data["RegulateRatioByAmt"] = task_data->RegulateRatioByAmt;
		data["RegulateRatioByPar"] = task_data->RegulateRatioByPar;
		data["RegulateFeePerOrder"] = task_data->RegulateFeePerOrder;
		data["RegulateFeeByVolume"] = task_data->RegulateFeeByVolume;
		data["RegulateFeeMin"] = task_data->RegulateFeeMin;
		data["RegulateFeeMax"] = task_data->RegulateFeeMax;
		data["SettlementRatioByAmt"] = task_data->SettlementRatioByAmt;
		data["SettlementRatioByPar"] = task_data->SettlementRatioByPar;
		data["SettlementFeePerOrder"] = task_data->SettlementFeePerOrder;
		data["SettlementFeeByVolume"] = task_data->SettlementFeeByVolume;
		data["SettlementFeeMin"] = task_data->SettlementFeeMin;
		data["SettlementFeeMax"] = task_data->SettlementFeeMax;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingFee(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorTradingFee(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorTradingFeeField* task_data = (CTORATstpInvestorTradingFeeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BizClass"] = task_data->BizClass;
		data["BrokerageType"] = task_data->BrokerageType;
		data["RatioByAmt"] = task_data->RatioByAmt;
		data["RatioByPar"] = task_data->RatioByPar;
		data["FeePerOrder"] = task_data->FeePerOrder;
		data["FeeMin"] = task_data->FeeMin;
		data["FeeMax"] = task_data->FeeMax;
		data["FeeByVolume"] = task_data->FeeByVolume;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["OrderType"] = task_data->OrderType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorTradingFee(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOQuota(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOQuotaField* task_data = (CTORATstpIPOQuotaField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MaxVolume"] = task_data->MaxVolume;
		data["KCMaxVolume"] = task_data->KCMaxVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOQuota(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrderFundDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderFundDetailField* task_data = (CTORATstpOrderFundDetailField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderAmount"] = task_data->OrderAmount;
		data["Turnover"] = task_data->Turnover;
		data["StampTaxFee"] = task_data->StampTaxFee;
		data["HandlingFee"] = task_data->HandlingFee;
		data["TransferFee"] = task_data->TransferFee;
		data["RegulateFee"] = task_data->RegulateFee;
		data["SettlementFee"] = task_data->SettlementFee;
		data["BrokerageFee"] = task_data->BrokerageFee;
		data["TotalFee"] = task_data->TotalFee;
		data["OrderCashFrozen"] = task_data->OrderCashFrozen;
		data["EstimateCashFrozen"] = task_data->EstimateCashFrozen;
		data["TotalFeeFrozen"] = task_data->TotalFeeFrozen;
		data["TotalFrozen"] = task_data->TotalFrozen;
		data["Margin"] = task_data->Margin;
		data["RepayAmount"] = task_data->RepayAmount;
		data["RepayVolume"] = task_data->RepayVolume;
		data["MarginFrozen"] = task_data->MarginFrozen;
		data["CirculateMarginFrozen"] = task_data->CirculateMarginFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderFundDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryFundTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpFundTransferDetailField* task_data = (CTORATstpFundTransferDetailField*)task->task_data;
		data["FundSerial"] = task_data->FundSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperateSource"] = task_data->OperateSource;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["BankID"] = task_data->BankID;
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExternalSerial"] = toUtf(task_data->ExternalSerial);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["BizRef"] = toUtf(task_data->BizRef);
		data["ExchangeRef"] = task_data->ExchangeRef;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPositionTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPositionTransferDetailField* task_data = (CTORATstpPositionTransferDetailField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferDirection"] = task_data->TransferDirection;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["TransferStatus"] = task_data->TransferStatus;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayBSVolume"] = task_data->TodayBSVolume;
		data["TodayPRVolume"] = task_data->TodayPRVolume;
		data["TodaySMVolume"] = task_data->TodaySMVolume;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExternalNodeID"] = task_data->ExternalNodeID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPeripheryPositionTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryPositionTransferDetailField* task_data = (CTORATstpPeripheryPositionTransferDetailField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayPRPos"] = task_data->TodayPRPos;
		data["TodaySMPos"] = task_data->TodaySMPos;
		data["HistoryPos"] = task_data->HistoryPos;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferReason"] = toUtf(task_data->TransferReason);
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["RepealDate"] = toUtf(task_data->RepealDate);
		data["RepealTime"] = toUtf(task_data->RepealTime);
		data["RepealReason"] = toUtf(task_data->RepealReason);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPeripheryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPeripheryFundTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryFundTransferDetailField* task_data = (CTORATstpPeripheryFundTransferDetailField*)task->task_data;
		data["FundSerial"] = task_data->FundSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TransferStatus"] = task_data->TransferStatus;
		data["TransferReason"] = toUtf(task_data->TransferReason);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["RepealDate"] = toUtf(task_data->RepealDate);
		data["RepealTime"] = toUtf(task_data->RepealTime);
		data["RepealReason"] = toUtf(task_data->RepealReason);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPeripheryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryBondConversionInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpBondConversionInfoField* task_data = (CTORATstpBondConversionInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ConvertOrderID"] = toUtf(task_data->ConvertOrderID);
		data["ConvertPrice"] = task_data->ConvertPrice;
		data["ConvertVolUnit"] = task_data->ConvertVolUnit;
		data["ConvertVolMax"] = task_data->ConvertVolMax;
		data["ConvertVolMin"] = task_data->ConvertVolMin;
		data["BeginDate"] = toUtf(task_data->BeginDate);
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ConvertName"] = toUtf(task_data->ConvertName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBondConversionInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryBondPutbackInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpBondPutbackInfoField* task_data = (CTORATstpBondPutbackInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["PutbackOrderID"] = toUtf(task_data->PutbackOrderID);
		data["PutbackName"] = toUtf(task_data->PutbackName);
		data["PutbackPrice"] = task_data->PutbackPrice;
		data["PutbackVolUnit"] = task_data->PutbackVolUnit;
		data["PutbackVolMax"] = task_data->PutbackVolMax;
		data["PutbackVolMin"] = task_data->PutbackVolMin;
		data["PutbackBeginDate"] = toUtf(task_data->PutbackBeginDate);
		data["PutbackEndDate"] = toUtf(task_data->PutbackEndDate);
		data["RelieveBeginDate"] = toUtf(task_data->RelieveBeginDate);
		data["RelieveEndDate"] = toUtf(task_data->RelieveEndDate);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBondPutbackInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorCondOrderLimitParam(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorCondOrderLimitParamField* task_data = (CTORATstpInvestorCondOrderLimitParamField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["MaxCondOrderLimitCnt"] = task_data->MaxCondOrderLimitCnt;
		data["CurrCondOrderCnt"] = task_data->CurrCondOrderCnt;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorCondOrderLimitParam(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryConditionOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConditionOrderField* task_data = (CTORATstpConditionOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Operway"] = task_data->Operway;
		data["LotType"] = task_data->LotType;
		data["CondCheck"] = task_data->CondCheck;
		data["GTDate"] = toUtf(task_data->GTDate);
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["CreditDebtID"] = toUtf(task_data->CreditDebtID);
		data["CreditQuotaType"] = task_data->CreditQuotaType;
		data["DiscountCouponID"] = task_data->DiscountCouponID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["TriggerOrderVolumeType"] = task_data->TriggerOrderVolumeType;
		data["TriggerOrderPriceType"] = task_data->TriggerOrderPriceType;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["ConditionPrice"] = task_data->ConditionPrice;
		data["PriceTicks"] = task_data->PriceTicks;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["RelativeFrontID"] = task_data->RelativeFrontID;
		data["RelativeSessionID"] = task_data->RelativeSessionID;
		data["RelativeParam"] = toUtf(task_data->RelativeParam);
		data["AppendContingentCondition"] = task_data->AppendContingentCondition;
		data["AppendConditionPrice"] = task_data->AppendConditionPrice;
		data["AppendRelativeFrontID"] = task_data->AppendRelativeFrontID;
		data["AppendRelativeSessionID"] = task_data->AppendRelativeSessionID;
		data["AppendRelativeParam"] = toUtf(task_data->AppendRelativeParam);
		data["RequestID"] = task_data->RequestID;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["CondOrderStatus"] = task_data->CondOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ActiveDate"] = toUtf(task_data->ActiveDate);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryConditionOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpCondOrderActionField* task_data = (CTORATstpCondOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["CondOrderID"] = task_data->CondOrderID;
		data["ActionFlag"] = task_data->ActionFlag;
		data["Operway"] = task_data->Operway;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RequestID"] = task_data->RequestID;
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ActionUser"] = toUtf(task_data->ActionUser);
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingNoticeField* task_data = (CTORATstpTradingNoticeField*)task->task_data;
		data["NoticeSerial"] = task_data->NoticeSerial;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Content"] = toUtf(task_data->Content);
		data["OperatorID"] = toUtf(task_data->OperatorID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingNotice(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPONumberResult(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPONumberResultField* task_data = (CTORATstpIPONumberResultField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["Day"] = toUtf(task_data->Day);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["SecurityType"] = task_data->SecurityType;
		data["BeginNumberID"] = toUtf(task_data->BeginNumberID);
		data["Volume"] = task_data->Volume;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPONumberResult(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOMatchNumberResult(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOMatchNumberResultField* task_data = (CTORATstpIPOMatchNumberResultField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MatchNumberID"] = toUtf(task_data->MatchNumberID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["Day"] = toUtf(task_data->Day);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["SecurityType"] = task_data->SecurityType;
		data["Volume"] = task_data->Volume;
		data["Price"] = task_data->Price;
		data["Amout"] = task_data->Amout;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOMatchNumberResult(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryShareholderSpecPrivilege(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpShareholderSpecPrivilegeField* task_data = (CTORATstpShareholderSpecPrivilegeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MarketID"] = task_data->MarketID;
		data["SpecPrivilegeType"] = task_data->SpecPrivilegeType;
		data["Direction"] = task_data->Direction;
		data["bForbidden"] = task_data->bForbidden;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderSpecPrivilege(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryMarket(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketField* task_data = (CTORATstpMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketName"] = toUtf(task_data->MarketName);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMarket(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryETFFile(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpETFFileField* task_data = (CTORATstpETFFileField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ETFSecurityID"] = toUtf(task_data->ETFSecurityID);
		data["ETFCreRedSecurityID"] = toUtf(task_data->ETFCreRedSecurityID);
		data["CreationRedemptionUnit"] = task_data->CreationRedemptionUnit;
		data["Maxcashratio"] = task_data->Maxcashratio;
		data["EstimateCashComponent"] = task_data->EstimateCashComponent;
		data["CashComponent"] = task_data->CashComponent;
		data["NAV"] = task_data->NAV;
		data["NAVperCU"] = task_data->NAVperCU;
		data["DividendPerCU"] = task_data->DividendPerCU;
		data["ETFCreRedType"] = task_data->ETFCreRedType;
		data["ETFSecurityName"] = toUtf(task_data->ETFSecurityName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFFile(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryETFBasket(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpETFBasketField* task_data = (CTORATstpETFBasketField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ETFSecurityID"] = toUtf(task_data->ETFSecurityID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["Volume"] = task_data->Volume;
		data["ETFCurrenceReplaceStatus"] = task_data->ETFCurrenceReplaceStatus;
		data["Premium"] = task_data->Premium;
		data["CreationReplaceAmount"] = task_data->CreationReplaceAmount;
		data["RedemptionReplaceAmount"] = task_data->RedemptionReplaceAmount;
		data["MarketID"] = task_data->MarketID;
		data["ETFCreRedType"] = task_data->ETFCreRedType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFBasket(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorPositionLimit(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorPositionLimitField* task_data = (CTORATstpInvestorPositionLimitField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BuyLimit"] = task_data->BuyLimit;
		data["BuyFrozen"] = task_data->BuyFrozen;
		data["SellLimit"] = task_data->SellLimit;
		data["SellFrozen"] = task_data->SellFrozen;
		data["PurchaseLimit"] = task_data->PurchaseLimit;
		data["PurchaseFrozen"] = task_data->PurchaseFrozen;
		data["RedeemLimit"] = task_data->RedeemLimit;
		data["RedeemFrozen"] = task_data->RedeemFrozen;
		data["PledgeInLimit"] = task_data->PledgeInLimit;
		data["PledgeInFrozen"] = task_data->PledgeInFrozen;
		data["PledgeOutLimit"] = task_data->PledgeOutLimit;
		data["PledgeOutFrozen"] = task_data->PledgeOutFrozen;
		data["ConvertLimit"] = task_data->ConvertLimit;
		data["ConvertFrozen"] = task_data->ConvertFrozen;
		data["PutbackLimit"] = task_data->PutbackLimit;
		data["PutbackFrozen"] = task_data->PutbackFrozen;
		data["RationalLimit"] = task_data->RationalLimit;
		data["RationalFrozen"] = task_data->RationalFrozen;
		data["TotalPositionLimit"] = task_data->TotalPositionLimit;
		data["TotalPositionFrozen"] = task_data->TotalPositionFrozen;
		data["SplitLimit"] = task_data->SplitLimit;
		data["SplitFrozen"] = task_data->SplitFrozen;
		data["MergeLimit"] = task_data->MergeLimit;
		data["MergeFrozen"] = task_data->MergeFrozen;
		data["UUPIC"] = toUtf(task_data->UUPIC);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPositionLimit(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEImcParams(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEImcParamsField* task_data = (CTORATstpSZSEImcParamsField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["OpenFlag"] = task_data->OpenFlag;
		data["ThresholdAmount"] = task_data->ThresholdAmount;
		data["PosAmt"] = task_data->PosAmt;
		data["AmountStatus"] = task_data->AmountStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEImcParams(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEImcExchangeRate(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEImcExchangeRateField* task_data = (CTORATstpSZSEImcExchangeRateField*)task->task_data;
		data["FromCurrency"] = task_data->FromCurrency;
		data["ToCurrency"] = task_data->ToCurrency;
		data["BidRate"] = task_data->BidRate;
		data["OfferRate"] = task_data->OfferRate;
		data["MidPointRate"] = task_data->MidPointRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEImcExchangeRate(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEHKPriceTickInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEHKPriceTickInfoField* task_data = (CTORATstpSZSEHKPriceTickInfoField*)task->task_data;
		data["PriceTickID"] = task_data->PriceTickID;
		data["PriceTickGroupID"] = task_data->PriceTickGroupID;
		data["PriceTickType"] = task_data->PriceTickType;
		data["BeginPrice"] = task_data->BeginPrice;
		data["EndPrice"] = task_data->EndPrice;
		data["PriceTick"] = task_data->PriceTick;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEHKPriceTickInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryLofFundInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpLofFundInfoField* task_data = (CTORATstpLofFundInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["FundID"] = toUtf(task_data->FundID);
		data["MainFundID"] = toUtf(task_data->MainFundID);
		data["FundType"] = task_data->FundType;
		data["SplitUnit"] = task_data->SplitUnit;
		data["SplitMinVol"] = task_data->SplitMinVol;
		data["MergeUnit"] = task_data->MergeUnit;
		data["MergeMinVol"] = task_data->MergeMinVol;
		data["FundRatio"] = task_data->FundRatio;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLofFundInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPledgePosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPledgePositionField* task_data = (CTORATstpPledgePositionField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["HisPledgePos"] = task_data->HisPledgePos;
		data["HisPledgePosFrozen"] = task_data->HisPledgePosFrozen;
		data["TodayPledgePos"] = task_data->TodayPledgePos;
		data["TodayPledgePosFrozen"] = task_data->TodayPledgePosFrozen;
		data["PreTotalPledgePos"] = task_data->PreTotalPledgePos;
		data["PreAvailablePledgePos"] = task_data->PreAvailablePledgePos;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPledgePosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPledgeInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPledgeInfoField* task_data = (CTORATstpPledgeInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["PledgeOrderID"] = toUtf(task_data->PledgeOrderID);
		data["PledgeName"] = toUtf(task_data->PledgeName);
		data["StandardBondID"] = toUtf(task_data->StandardBondID);
		data["ConversionRate"] = task_data->ConversionRate;
		data["PledgeInTradingUnit"] = task_data->PledgeInTradingUnit;
		data["PledgeOutTradingUnit"] = task_data->PledgeOutTradingUnit;
		data["PledgeInVolMax"] = task_data->PledgeInVolMax;
		data["PledgeInVolMin"] = task_data->PledgeInVolMin;
		data["PledgeOutVolMax"] = task_data->PledgeOutVolMax;
		data["PledgeOutVolMin"] = task_data->PledgeOutVolMin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPledgeInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySystemNodeInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSystemNodeInfoField* task_data = (CTORATstpSystemNodeInfoField*)task->task_data;
		data["NodeID"] = task_data->NodeID;
		data["NodeInfo"] = toUtf(task_data->NodeInfo);
		data["bCurrent"] = task_data->bCurrent;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySystemNodeInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryStandardBondPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpStandardBondPositionField* task_data = (CTORATstpStandardBondPositionField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["AvailablePosition"] = task_data->AvailablePosition;
		data["AvailablePosFrozen"] = task_data->AvailablePosFrozen;
		data["TotalPosition"] = task_data->TotalPosition;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStandardBondPosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPrematurityRepoOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPrematurityRepoOrderField* task_data = (CTORATstpPrematurityRepoOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["TradeDay"] = toUtf(task_data->TradeDay);
		data["ExpireDay"] = toUtf(task_data->ExpireDay);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["Direction"] = task_data->Direction;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["Price"] = task_data->Price;
		data["Turnover"] = task_data->Turnover;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["RepoTotalMoney"] = task_data->RepoTotalMoney;
		data["InterestAmount"] = task_data->InterestAmount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPrematurityRepoOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderField* task_data = (CTORATstpNegoOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["Contractor"] = toUtf(task_data->Contractor);
		data["ContractorInfo"] = toUtf(task_data->ContractorInfo);
		data["ConfirmID"] = toUtf(task_data->ConfirmID);
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InsertUser"] = toUtf(task_data->InsertUser);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelUser"] = toUtf(task_data->CancelUser);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderActionField* task_data = (CTORATstpNegoOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["CancelOrderLocalID"] = toUtf(task_data->CancelOrderLocalID);
		data["CancelOrderSysID"] = toUtf(task_data->CancelOrderSysID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["Operway"] = task_data->Operway;
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["ActionUser"] = toUtf(task_data->ActionUser);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["RequestID"] = task_data->RequestID;
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["PbuID"] = toUtf(task_data->PbuID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoTradeField* task_data = (CTORATstpNegoTradeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["CounterpartyPbuID"] = toUtf(task_data->CounterpartyPbuID);
		data["CounterpartyShareholderID"] = toUtf(task_data->CounterpartyShareholderID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoTrade(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegotiationParam(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegotiationParamField* task_data = (CTORATstpNegotiationParamField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BuyTradingUnit"] = task_data->BuyTradingUnit;
		data["SellTradingUnit"] = task_data->SellTradingUnit;
		data["MinOrderVolume"] = task_data->MinOrderVolume;
		data["MinOrderAmt"] = task_data->MinOrderAmt;
		data["PriceTick"] = task_data->PriceTick;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["bMarketMaker"] = task_data->bMarketMaker;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField* task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegotiationParam(data, error, task->task_id, task->task_last);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void StockApi::createTstpTraderApi(string pszFlowPath, bool bEncrypt)
{
	this->api = CTORATstpTraderApi::CreateTstpTraderApi(pszFlowPath.c_str(), bEncrypt);
	this->api->RegisterSpi(this);

	this->active = true;
	this->task_thread = thread(&StockApi::processTask, this);
};

void StockApi::init()
{
	this->api->Init();
};

void StockApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

int StockApi::join()
{
	int i = this->api->Join();
	return i;
};

void StockApi::release()
{
	this->api->Release();
};

string StockApi::getApiVersion()
{
	return this->api->GetApiVersion();
};

int StockApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

void StockApi::registerNameServer(string pszNsAddress)
{
	this->api->RegisterNameServer((char*)pszNsAddress.c_str());
}

void StockApi::registerFensUserInfo(const dict& req)
{
	CTORATstpFensUserInfoField myreq = CTORATstpFensUserInfoField();
	getShort(req, "FensVer", &myreq.FensVer);
	getString(req, "FensEnvID", myreq.FensEnvID);
	getString(req, "FensNodeID", myreq.FensNodeID);
	getString(req, "FensUserID", myreq.FensUserID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ClientInfo", myreq.ClientInfo);
	memset(&myreq, 0, sizeof(myreq));
	this->api->RegisterFensUserInfo(&myreq);
}

void StockApi::subscribePrivateTopic(int type)
{
	this->api->SubscribePrivateTopic((TORA_TE_RESUME_TYPE)type);
}

void StockApi::subscribePublicTopic(int type)
{
	this->api->SubscribePublicTopic((TORA_TE_RESUME_TYPE)type);
}

int StockApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int StockApi::reqUserLogin(const dict& req, int nRequestID)
{
	CTORATstpReqUserLoginField myreq = CTORATstpReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "LogInAccount", myreq.LogInAccount);
	getChar(req, "LogInAccountType", &myreq.LogInAccountType);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getChar(req, "AuthMode", &myreq.AuthMode);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getChar(req, "Lang", &myreq.Lang);
	getString(req, "DynamicPassword", myreq.DynamicPassword);
	getString(req, "DeviceID", myreq.DeviceID);
	getString(req, "CertSerial", myreq.CertSerial);
	getChar(req, "DeviceType", &myreq.DeviceType);
	getInt(req, "NodeRef", &myreq.NodeRef);
	int i = this->api->ReqUserLogin(&myreq, nRequestID);
	return i;
};

int StockApi::reqUserLogout(const dict& req, int nRequestID)
{
	CTORATstpUserLogoutField myreq = CTORATstpUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int StockApi::reqUserPasswordUpdate(const dict& req, int nRequestID)
{
	CTORATstpUserPasswordUpdateField myreq = CTORATstpUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	int i = this->api->ReqUserPasswordUpdate(&myreq, nRequestID);
	return i;
};

int StockApi::reqInputDeviceSerial(const dict& req, int nRequestID)
{
	CTORATstpReqInputDeviceSerialField myreq = CTORATstpReqInputDeviceSerialField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "DeviceID", myreq.DeviceID);
	getString(req, "CertSerial", myreq.CertSerial);
	getChar(req, "DeviceType", &myreq.DeviceType);
	int i = this->api->ReqInputDeviceSerial(&myreq, nRequestID);
	return i;
};

int StockApi::reqOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpInputOrderField myreq = CTORATstpInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "Direction", &myreq.Direction);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getChar(req, "Operway", &myreq.Operway);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getChar(req, "LotType", &myreq.LotType);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "CondCheck", &myreq.CondCheck);
	getString(req, "GTDate", myreq.GTDate);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getString(req, "CreditDebtID", myreq.CreditDebtID);
	getChar(req, "CreditQuotaType", &myreq.CreditQuotaType);
	getInt(req, "DiscountCouponID", &myreq.DiscountCouponID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqOrderInsert(&myreq, nRequestID);
	return i;
};

int StockApi::reqOrderAction(const dict& req, int nRequestID)
{
	CTORATstpInputOrderActionField myreq = CTORATstpInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getString(req, "CancelOrderSysID", myreq.CancelOrderSysID);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqCondOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpInputCondOrderField myreq = CTORATstpInputCondOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "Operway", &myreq.Operway);
	getChar(req, "LotType", &myreq.LotType);
	getChar(req, "CondCheck", &myreq.CondCheck);
	getString(req, "GTDate", myreq.GTDate);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getString(req, "CreditDebtID", myreq.CreditDebtID);
	getChar(req, "CreditQuotaType", &myreq.CreditQuotaType);
	getInt(req, "DiscountCouponID", &myreq.DiscountCouponID);
	getInt(req, "CondOrderRef", &myreq.CondOrderRef);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "TriggerOrderVolumeType", &myreq.TriggerOrderVolumeType);
	getChar(req, "TriggerOrderPriceType", &myreq.TriggerOrderPriceType);
	getChar(req, "ContingentCondition", &myreq.ContingentCondition);
	getDouble(req, "ConditionPrice", &myreq.ConditionPrice);
	getInt(req, "PriceTicks", &myreq.PriceTicks);
	getInt(req, "VolumeMultiple", &myreq.VolumeMultiple);
	getInt(req, "RelativeFrontID", &myreq.RelativeFrontID);
	getInt(req, "RelativeSessionID", &myreq.RelativeSessionID);
	getString(req, "RelativeParam", myreq.RelativeParam);
	getChar(req, "AppendContingentCondition", &myreq.AppendContingentCondition);
	getDouble(req, "AppendConditionPrice", &myreq.AppendConditionPrice);
	getInt(req, "AppendRelativeFrontID", &myreq.AppendRelativeFrontID);
	getInt(req, "AppendRelativeSessionID", &myreq.AppendRelativeSessionID);
	getString(req, "AppendRelativeParam", myreq.AppendRelativeParam);
	int i = this->api->ReqCondOrderInsert(&myreq, nRequestID);
	return i;
};

int StockApi::reqCondOrderAction(const dict& req, int nRequestID)
{
	CTORATstpInputCondOrderActionField myreq = CTORATstpInputCondOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getInt(req, "CondOrderRef", &myreq.CondOrderRef);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getChar(req, "Operway", &myreq.Operway);
	getInt(req, "CondOrderActionRef", &myreq.CondOrderActionRef);
	getInt(req, "CancelCondOrderID", &myreq.CancelCondOrderID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqCondOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqNegoOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpInputNegoOrderField myreq = CTORATstpInputNegoOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "Direction", &myreq.Direction);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getString(req, "Contractor", myreq.Contractor);
	getString(req, "ContractorInfo", myreq.ContractorInfo);
	getString(req, "ConfirmID", myreq.ConfirmID);
	getString(req, "CounterpartyPbuID", myreq.CounterpartyPbuID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqNegoOrderInsert(&myreq, nRequestID);
	return i;
};

int StockApi::reqNegoOrderAction(const dict& req, int nRequestID)
{
	CTORATstpInputNegoOrderActionField myreq = CTORATstpInputNegoOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "CancelOrderSysID", myreq.CancelOrderSysID);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqNegoOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqOrderInsertEx(const dict& req, int nRequestID)
{
	CTORATstpInputOrderExField myreq = CTORATstpInputOrderExField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "Direction", &myreq.Direction);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getChar(req, "Operway", &myreq.Operway);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getChar(req, "LotType", &myreq.LotType);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "CondCheck", &myreq.CondCheck);
	getString(req, "GTDate", myreq.GTDate);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getString(req, "CreditDebtID", myreq.CreditDebtID);
	getChar(req, "CreditQuotaType", &myreq.CreditQuotaType);
	getInt(req, "DiscountCouponID", &myreq.DiscountCouponID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getInt(req, "NodeRef", &myreq.NodeRef);
	int i = this->api->ReqOrderInsertEx(&myreq, nRequestID);
	return i;
};

int StockApi::reqOrderActionEx(const dict& req, int nRequestID)
{
	CTORATstpInputOrderActionExField myreq = CTORATstpInputOrderActionExField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getString(req, "CancelOrderSysID", myreq.CancelOrderSysID);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqOrderActionEx(&myreq, nRequestID);
	return i;
};

int StockApi::reqTransferFund(const dict& req, int nRequestID)
{
	CTORATstpInputTransferFundField myreq = CTORATstpInputTransferFundField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getInt(req, "ApplySerial", &myreq.ApplySerial);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getDouble(req, "Amount", &myreq.Amount);
	getChar(req, "BankID", &myreq.BankID);
	getString(req, "AccountPassword", myreq.AccountPassword);
	getString(req, "BankPassword", myreq.BankPassword);
	getInt(req, "ExternalNodeID", &myreq.ExternalNodeID);
	getString(req, "CreditDebtID", myreq.CreditDebtID);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getDouble(req, "RealAmount", &myreq.RealAmount);
	getInt(req, "ForceFlag", &myreq.ForceFlag);
	int i = this->api->ReqTransferFund(&myreq, nRequestID);
	return i;
};

int StockApi::reqTransferPosition(const dict& req, int nRequestID)
{
	CTORATstpInputTransferPositionField myreq = CTORATstpInputTransferPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "ApplySerial", &myreq.ApplySerial);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "TransferPositionType", &myreq.TransferPositionType);
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "MarketID", &myreq.MarketID);
	getInt(req, "ExternalNodeID", &myreq.ExternalNodeID);
	int i = this->api->ReqTransferPosition(&myreq, nRequestID);
	return i;
};

int StockApi::reqInquiryJZFund(const dict& req, int nRequestID)
{
	CTORATstpReqInquiryJZFundField myreq = CTORATstpReqInquiryJZFundField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqInquiryJZFund(&myreq, nRequestID);
	return i;
};

int StockApi::reqInquiryBankAccountFund(const dict& req, int nRequestID)
{
	CTORATstpReqInquiryBankAccountFundField myreq = CTORATstpReqInquiryBankAccountFundField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getChar(req, "BankID", &myreq.BankID);
	getString(req, "BankPassword", myreq.BankPassword);
	int i = this->api->ReqInquiryBankAccountFund(&myreq, nRequestID);
	return i;
};

int StockApi::reqInquiryMaxOrderVolume(const dict& req, int nRequestID)
{
	CTORATstpReqInquiryMaxOrderVolumeField myreq = CTORATstpReqInquiryMaxOrderVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getChar(req, "LotType", &myreq.LotType);
	getInt(req, "MaxVolume", &myreq.MaxVolume);
	getString(req, "CreditDebtID", myreq.CreditDebtID);
	getChar(req, "CreditQuotaType", &myreq.CreditQuotaType);
	int i = this->api->ReqInquiryMaxOrderVolume(&myreq, nRequestID);
	return i;
};

int StockApi::reqInquiryTradeConcentration(const dict& req, int nRequestID)
{
	CTORATstpInquiryTradeConcentrationField myreq = CTORATstpInquiryTradeConcentrationField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getDouble(req, "ConcentrationRatio1", &myreq.ConcentrationRatio1);
	getDouble(req, "ConcentrationRatio2", &myreq.ConcentrationRatio2);
	int i = this->api->ReqInquiryTradeConcentration(&myreq, nRequestID);
	return i;
};

int StockApi::reqModifyOpenPosCost(const dict& req, int nRequestID)
{
	CTORATstpReqModifyOpenPosCostField myreq = CTORATstpReqModifyOpenPosCostField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getDouble(req, "OpenPosCost", &myreq.OpenPosCost);
	int i = this->api->ReqModifyOpenPosCost(&myreq, nRequestID);
	return i;
};

int StockApi::reqInputNodeFundAssignment(const dict& req, int nRequestID)
{
	CTORATstpInputNodeFundAssignmentField myreq = CTORATstpInputNodeFundAssignmentField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "NodeID1", &myreq.NodeID1);
	getDouble(req, "AmtRatio1", &myreq.AmtRatio1);
	getInt(req, "NodeID2", &myreq.NodeID2);
	getDouble(req, "AmtRatio2", &myreq.AmtRatio2);
	getInt(req, "NodeID3", &myreq.NodeID3);
	getDouble(req, "AmtRatio3", &myreq.AmtRatio3);
	getInt(req, "NodeID4", &myreq.NodeID4);
	getDouble(req, "AmtRatio4", &myreq.AmtRatio4);
	getInt(req, "NodeID5", &myreq.NodeID5);
	getDouble(req, "AmtRatio5", &myreq.AmtRatio5);
	int i = this->api->ReqInputNodeFundAssignment(&myreq, nRequestID);
	return i;
};

int StockApi::reqInquiryNodeFundAssignment(const dict& req, int nRequestID)
{
	CTORATstpReqInquiryNodeFundAssignmentField myreq = CTORATstpReqInquiryNodeFundAssignmentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getInt(req, "NodeID", &myreq.NodeID);
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	int i = this->api->ReqInquiryNodeFundAssignment(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryExchange(const dict& req, int nRequestID)
{
	CTORATstpQryExchangeField myreq = CTORATstpQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySecurity(const dict& req, int nRequestID)
{
	CTORATstpQrySecurityField myreq = CTORATstpQrySecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ProductID", &myreq.ProductID);
	int i = this->api->ReqQrySecurity(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPOInfo(const dict& req, int nRequestID)
{
	CTORATstpQryIPOInfoField myreq = CTORATstpQryIPOInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryIPOInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryUser(const dict& req, int nRequestID)
{
	CTORATstpQryUserField myreq = CTORATstpQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getChar(req, "UserType", &myreq.UserType);
	int i = this->api->ReqQryUser(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestor(const dict& req, int nRequestID)
{
	CTORATstpQryInvestorField myreq = CTORATstpQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryShareholderAccount(const dict& req, int nRequestID)
{
	CTORATstpQryShareholderAccountField myreq = CTORATstpQryShareholderAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "ShareholderIDType", &myreq.ShareholderIDType);
	int i = this->api->ReqQryShareholderAccount(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryRationalInfo(const dict& req, int nRequestID)
{
	CTORATstpQryRationalInfoField myreq = CTORATstpQryRationalInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryRationalInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryOrder(const dict& req, int nRequestID)
{
	CTORATstpQryOrderField myreq = CTORATstpQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getInt(req, "IsCancel", &myreq.IsCancel);
	int i = this->api->ReqQryOrder(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryOrderAction(const dict& req, int nRequestID)
{
	CTORATstpQryOrderActionField myreq = CTORATstpQryOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "OrderLocalID", myreq.OrderLocalID);
	getString(req, "CancelOrderLocalID", myreq.CancelOrderLocalID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryTrade(const dict& req, int nRequestID)
{
	CTORATstpQryTradeField myreq = CTORATstpQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "TradeID", myreq.TradeID);
	getString(req, "TradeTimeStart", myreq.TradeTimeStart);
	getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
	int i = this->api->ReqQryTrade(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryTradingAccount(const dict& req, int nRequestID)
{
	CTORATstpQryTradingAccountField myreq = CTORATstpQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "AccountType", &myreq.AccountType);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryTradingAccount(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPosition(const dict& req, int nRequestID)
{
	CTORATstpQryPositionField myreq = CTORATstpQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	int i = this->api->ReqQryPosition(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryTradingFee(const dict& req, int nRequestID)
{
	CTORATstpQryTradingFeeField myreq = CTORATstpQryTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryTradingFee(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorTradingFee(const dict& req, int nRequestID)
{
	CTORATstpQryInvestorTradingFeeField myreq = CTORATstpQryInvestorTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryInvestorTradingFee(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPOQuota(const dict& req, int nRequestID)
{
	CTORATstpQryIPOQuotaField myreq = CTORATstpQryIPOQuotaField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	int i = this->api->ReqQryIPOQuota(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryOrderFundDetail(const dict& req, int nRequestID)
{
	CTORATstpQryOrderFundDetailField myreq = CTORATstpQryOrderFundDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	int i = this->api->ReqQryOrderFundDetail(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryFundTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpQryFundTransferDetailField myreq = CTORATstpQryFundTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	int i = this->api->ReqQryFundTransferDetail(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPositionTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpQryPositionTransferDetailField myreq = CTORATstpQryPositionTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryPositionTransferDetail(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPeripheryPositionTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpQryPeripheryPositionTransferDetailField myreq = CTORATstpQryPeripheryPositionTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryPeripheryPositionTransferDetail(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPeripheryFundTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpQryPeripheryFundTransferDetailField myreq = CTORATstpQryPeripheryFundTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	int i = this->api->ReqQryPeripheryFundTransferDetail(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryBondConversionInfo(const dict& req, int nRequestID)
{
	CTORATstpQryBondConversionInfoField myreq = CTORATstpQryBondConversionInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryBondConversionInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryBondPutbackInfo(const dict& req, int nRequestID)
{
	CTORATstpQryBondPutbackInfoField myreq = CTORATstpQryBondPutbackInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryBondPutbackInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorCondOrderLimitParam(const dict& req, int nRequestID)
{
	CTORATstpQryInvestorCondOrderLimitParamField myreq = CTORATstpQryInvestorCondOrderLimitParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestorCondOrderLimitParam(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryConditionOrder(const dict& req, int nRequestID)
{
	CTORATstpQryConditionOrderField myreq = CTORATstpQryConditionOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryConditionOrder(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryCondOrderAction(const dict& req, int nRequestID)
{
	CTORATstpQryCondOrderActionField myreq = CTORATstpQryCondOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getInt(req, "CancelCondOrderID", &myreq.CancelCondOrderID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCondOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryTradingNotice(const dict& req, int nRequestID)
{
	CTORATstpQryTradingNoticeField myreq = CTORATstpQryTradingNoticeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InsertDateStart", myreq.InsertDateStart);
	getString(req, "InsertDateEnd", myreq.InsertDateEnd);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryTradingNotice(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPONumberResult(const dict& req, int nRequestID)
{
	CTORATstpQryIPONumberResultField myreq = CTORATstpQryIPONumberResultField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	int i = this->api->ReqQryIPONumberResult(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPOMatchNumberResult(const dict& req, int nRequestID)
{
	CTORATstpQryIPOMatchNumberResultField myreq = CTORATstpQryIPOMatchNumberResultField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "MatchNumberID", myreq.MatchNumberID);
	int i = this->api->ReqQryIPOMatchNumberResult(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryShareholderSpecPrivilege(const dict& req, int nRequestID)
{
	CTORATstpQryShareholderSpecPrivilegeField myreq = CTORATstpQryShareholderSpecPrivilegeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "SpecPrivilegeType", &myreq.SpecPrivilegeType);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "MarketID", &myreq.MarketID);
	int i = this->api->ReqQryShareholderSpecPrivilege(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryMarket(const dict& req, int nRequestID)
{
	CTORATstpQryMarketField myreq = CTORATstpQryMarketField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	int i = this->api->ReqQryMarket(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryETFFile(const dict& req, int nRequestID)
{
	CTORATstpQryETFFileField myreq = CTORATstpQryETFFileField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ETFSecurityID", myreq.ETFSecurityID);
	getString(req, "ETFCreRedSecurityID", myreq.ETFCreRedSecurityID);
	int i = this->api->ReqQryETFFile(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryETFBasket(const dict& req, int nRequestID)
{
	CTORATstpQryETFBasketField myreq = CTORATstpQryETFBasketField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ETFSecurityID", myreq.ETFSecurityID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryETFBasket(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorPositionLimit(const dict& req, int nRequestID)
{
	CTORATstpQryInvestorPositionLimitField myreq = CTORATstpQryInvestorPositionLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryInvestorPositionLimit(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEImcParams(const dict& req, int nRequestID)
{
	CTORATstpQrySZSEImcParamsField myreq = CTORATstpQrySZSEImcParamsField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "MarketID", &myreq.MarketID);
	int i = this->api->ReqQrySZSEImcParams(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEImcExchangeRate(const dict& req, int nRequestID)
{
	CTORATstpQrySZSEImcExchangeRateField myreq = CTORATstpQrySZSEImcExchangeRateField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "FromCurrency", &myreq.FromCurrency);
	getChar(req, "ToCurrency", &myreq.ToCurrency);
	int i = this->api->ReqQrySZSEImcExchangeRate(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEHKPriceTickInfo(const dict& req, int nRequestID)
{
	CTORATstpQrySZSEHKPriceTickInfoField myreq = CTORATstpQrySZSEHKPriceTickInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "PriceTickID", &myreq.PriceTickID);
	int i = this->api->ReqQrySZSEHKPriceTickInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryLofFundInfo(const dict& req, int nRequestID)
{
	CTORATstpQryLofFundInfoField myreq = CTORATstpQryLofFundInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "FundID", myreq.FundID);
	getString(req, "MainFundID", myreq.MainFundID);
	int i = this->api->ReqQryLofFundInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPledgePosition(const dict& req, int nRequestID)
{
	CTORATstpQryPledgePositionField myreq = CTORATstpQryPledgePositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryPledgePosition(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPledgeInfo(const dict& req, int nRequestID)
{
	CTORATstpQryPledgeInfoField myreq = CTORATstpQryPledgeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryPledgeInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySystemNodeInfo(const dict& req, int nRequestID)
{
	CTORATstpQrySystemNodeInfoField myreq = CTORATstpQrySystemNodeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "NodeID", &myreq.NodeID);
	int i = this->api->ReqQrySystemNodeInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryStandardBondPosition(const dict& req, int nRequestID)
{
	CTORATstpQryStandardBondPositionField myreq = CTORATstpQryStandardBondPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryStandardBondPosition(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPrematurityRepoOrder(const dict& req, int nRequestID)
{
	CTORATstpQryPrematurityRepoOrderField myreq = CTORATstpQryPrematurityRepoOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "OrderLocalID", myreq.OrderLocalID);
	getChar(req, "ProductID", &myreq.ProductID);
	getChar(req, "SecurityType", &myreq.SecurityType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "TradeID", myreq.TradeID);
	int i = this->api->ReqQryPrematurityRepoOrder(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryNegoOrder(const dict& req, int nRequestID)
{
	CTORATstpQryNegoOrderField myreq = CTORATstpQryNegoOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryNegoOrder(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryNegoOrderAction(const dict& req, int nRequestID)
{
	CTORATstpQryNegoOrderActionField myreq = CTORATstpQryNegoOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "OrderLocalID", myreq.OrderLocalID);
	getString(req, "CancelOrderLocalID", myreq.CancelOrderLocalID);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryNegoOrderAction(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryNegoTrade(const dict& req, int nRequestID)
{
	CTORATstpQryNegoTradeField myreq = CTORATstpQryNegoTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "TradeID", myreq.TradeID);
	getString(req, "TradeTimeStart", myreq.TradeTimeStart);
	getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
	int i = this->api->ReqQryNegoTrade(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryNegotiationParam(const dict& req, int nRequestID)
{
	CTORATstpQryNegotiationParamField myreq = CTORATstpQryNegotiationParamField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryNegotiationParam(&myreq, nRequestID);
	return i;
};

///-------------------------------------------------------------------------------------
///pybind11封装
///-------------------------------------------------------------------------------------

class PyStockApi : public StockApi
{
public:
	using StockApi::StockApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onFrontConnected);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int nReason) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onFrontDisconnected, nReason);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspError(const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspError, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspGetConnectionInfo(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspGetConnectionInfo, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogin(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspUserLogin, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogout(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspUserLogout, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserPasswordUpdate(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspUserPasswordUpdate, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInputDeviceSerial(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInputDeviceSerial, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTrade(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnTrade, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCondOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspCondOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnCondOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnCondOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCondOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnCondOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCondOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspCondOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCondOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnCondOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspNegoOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspNegoOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnNegoOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnNegoOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnNegoOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnNegoOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnNegoTrade(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnNegoTrade, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspNegoOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspNegoOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnNegoOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnNegoOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderInsertEx(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspOrderInsertEx, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderActionEx(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspOrderActionEx, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnMarketStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnMarketStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspTransferFund(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspTransferFund, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnTransferFund(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnTransferFund, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTransferFund(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnTransferFund, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspTransferPosition(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspTransferPosition, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnTransferPosition(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onErrRtnTransferPosition, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTransferPosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnTransferPosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPeripheryTransferPosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnPeripheryTransferPosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPeripheryTransferFund(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnPeripheryTransferFund, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryJZFund(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInquiryJZFund, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryBankAccountFund(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInquiryBankAccountFund, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTradingNotice(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRtnTradingNotice, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryMaxOrderVolume(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInquiryMaxOrderVolume, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryTradeConcentration(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInquiryTradeConcentration, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspModifyOpenPosCost(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspModifyOpenPosCost, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInputNodeFundAssignment(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInputNodeFundAssignment, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryNodeFundAssignment(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspInquiryNodeFundAssignment, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExchange(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryExchange, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySecurity(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQrySecurity, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryIPOInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryUser(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryUser, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestor(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestor, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryShareholderAccount(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryShareholderAccount, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryRationalInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryRationalInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryOrder, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrderAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTrade(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryTrade, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingAccount(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingAccount, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingFee(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingFee, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorTradingFee(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorTradingFee, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryIPOQuota(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOQuota, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrderFundDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryOrderFundDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFundTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryFundTransferDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPositionTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPositionTransferDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPeripheryPositionTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPeripheryPositionTransferDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPeripheryFundTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPeripheryFundTransferDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryBondConversionInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryBondConversionInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryBondPutbackInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryBondPutbackInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorCondOrderLimitParam(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorCondOrderLimitParam, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryConditionOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryConditionOrder, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCondOrderAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryCondOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingNotice(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingNotice, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryIPONumberResult(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryIPONumberResult, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryIPOMatchNumberResult(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOMatchNumberResult, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryShareholderSpecPrivilege(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryShareholderSpecPrivilege, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryMarket(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryMarket, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryETFFile(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryETFFile, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryETFBasket(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryETFBasket, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorPositionLimit(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorPositionLimit, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySZSEImcParams(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEImcParams, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySZSEImcExchangeRate(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEImcExchangeRate, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySZSEHKPriceTickInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEHKPriceTickInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLofFundInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryLofFundInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPledgePosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPledgePosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPledgeInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPledgeInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySystemNodeInfo(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQrySystemNodeInfo, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStandardBondPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryStandardBondPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPrematurityRepoOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryPrematurityRepoOrder, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryNegoOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoOrder, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryNegoOrderAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryNegoTrade(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoTrade, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryNegotiationParam(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, StockApi, onRspQryNegotiationParam, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vntorastock, m)
{
	class_<StockApi, PyStockApi> StockApi(m, "StockApi", module_local());
	StockApi
		.def(init<>())
		.def("createTstpTraderApi", &StockApi::createTstpTraderApi)
		.def("registerFront", &StockApi::registerFront)
		.def("init", &StockApi::init)
		.def("join", &StockApi::join)
		.def("release", &StockApi::release)
		.def("getApiVersion", &StockApi::getApiVersion)
		.def("exit", &StockApi::exit)
		.def("registerNameServer", &StockApi::registerNameServer)
		.def("registerFensUserInfo", &StockApi::registerFensUserInfo)
		.def("subscribePrivateTopic", &StockApi::subscribePrivateTopic)
		.def("subscribePublicTopic", &StockApi::subscribePublicTopic)
		.def("reqGetConnectionInfo", &StockApi::reqGetConnectionInfo)
		.def("reqUserLogin", &StockApi::reqUserLogin)
		.def("reqUserLogout", &StockApi::reqUserLogout)
		.def("reqUserPasswordUpdate", &StockApi::reqUserPasswordUpdate)
		.def("reqInputDeviceSerial", &StockApi::reqInputDeviceSerial)
		.def("reqOrderInsert", &StockApi::reqOrderInsert)
		.def("reqOrderAction", &StockApi::reqOrderAction)
		.def("reqCondOrderInsert", &StockApi::reqCondOrderInsert)
		.def("reqCondOrderAction", &StockApi::reqCondOrderAction)
		.def("reqNegoOrderInsert", &StockApi::reqNegoOrderInsert)
		.def("reqNegoOrderAction", &StockApi::reqNegoOrderAction)
		.def("reqOrderInsertEx", &StockApi::reqOrderInsertEx)
		.def("reqOrderActionEx", &StockApi::reqOrderActionEx)
		.def("reqTransferFund", &StockApi::reqTransferFund)
		.def("reqTransferPosition", &StockApi::reqTransferPosition)
		.def("reqInquiryJZFund", &StockApi::reqInquiryJZFund)
		.def("reqInquiryBankAccountFund", &StockApi::reqInquiryBankAccountFund)
		.def("reqInquiryMaxOrderVolume", &StockApi::reqInquiryMaxOrderVolume)
		.def("reqInquiryTradeConcentration", &StockApi::reqInquiryTradeConcentration)
		.def("reqModifyOpenPosCost", &StockApi::reqModifyOpenPosCost)
		.def("reqInputNodeFundAssignment", &StockApi::reqInputNodeFundAssignment)
		.def("reqInquiryNodeFundAssignment", &StockApi::reqInquiryNodeFundAssignment)
		.def("reqQryExchange", &StockApi::reqQryExchange)
		.def("reqQrySecurity", &StockApi::reqQrySecurity)
		.def("reqQryIPOInfo", &StockApi::reqQryIPOInfo)
		.def("reqQryUser", &StockApi::reqQryUser)
		.def("reqQryInvestor", &StockApi::reqQryInvestor)
		.def("reqQryShareholderAccount", &StockApi::reqQryShareholderAccount)
		.def("reqQryRationalInfo", &StockApi::reqQryRationalInfo)
		.def("reqQryOrder", &StockApi::reqQryOrder)
		.def("reqQryOrderAction", &StockApi::reqQryOrderAction)
		.def("reqQryTrade", &StockApi::reqQryTrade)
		.def("reqQryTradingAccount", &StockApi::reqQryTradingAccount)
		.def("reqQryPosition", &StockApi::reqQryPosition)
		.def("reqQryTradingFee", &StockApi::reqQryTradingFee)
		.def("reqQryInvestorTradingFee", &StockApi::reqQryInvestorTradingFee)
		.def("reqQryIPOQuota", &StockApi::reqQryIPOQuota)
		.def("reqQryOrderFundDetail", &StockApi::reqQryOrderFundDetail)
		.def("reqQryFundTransferDetail", &StockApi::reqQryFundTransferDetail)
		.def("reqQryPositionTransferDetail", &StockApi::reqQryPositionTransferDetail)
		.def("reqQryPeripheryPositionTransferDetail", &StockApi::reqQryPeripheryPositionTransferDetail)
		.def("reqQryPeripheryFundTransferDetail", &StockApi::reqQryPeripheryFundTransferDetail)
		.def("reqQryBondConversionInfo", &StockApi::reqQryBondConversionInfo)
		.def("reqQryBondPutbackInfo", &StockApi::reqQryBondPutbackInfo)
		.def("reqQryInvestorCondOrderLimitParam", &StockApi::reqQryInvestorCondOrderLimitParam)
		.def("reqQryConditionOrder", &StockApi::reqQryConditionOrder)
		.def("reqQryCondOrderAction", &StockApi::reqQryCondOrderAction)
		.def("reqQryTradingNotice", &StockApi::reqQryTradingNotice)
		.def("reqQryIPONumberResult", &StockApi::reqQryIPONumberResult)
		.def("reqQryIPOMatchNumberResult", &StockApi::reqQryIPOMatchNumberResult)
		.def("reqQryShareholderSpecPrivilege", &StockApi::reqQryShareholderSpecPrivilege)
		.def("reqQryMarket", &StockApi::reqQryMarket)
		.def("reqQryETFFile", &StockApi::reqQryETFFile)
		.def("reqQryETFBasket", &StockApi::reqQryETFBasket)
		.def("reqQryInvestorPositionLimit", &StockApi::reqQryInvestorPositionLimit)
		.def("reqQrySZSEImcParams", &StockApi::reqQrySZSEImcParams)
		.def("reqQrySZSEImcExchangeRate", &StockApi::reqQrySZSEImcExchangeRate)
		.def("reqQrySZSEHKPriceTickInfo", &StockApi::reqQrySZSEHKPriceTickInfo)
		.def("reqQryLofFundInfo", &StockApi::reqQryLofFundInfo)
		.def("reqQryPledgePosition", &StockApi::reqQryPledgePosition)
		.def("reqQryPledgeInfo", &StockApi::reqQryPledgeInfo)
		.def("reqQrySystemNodeInfo", &StockApi::reqQrySystemNodeInfo)
		.def("reqQryStandardBondPosition", &StockApi::reqQryStandardBondPosition)
		.def("reqQryPrematurityRepoOrder", &StockApi::reqQryPrematurityRepoOrder)
		.def("reqQryNegoOrder", &StockApi::reqQryNegoOrder)
		.def("reqQryNegoOrderAction", &StockApi::reqQryNegoOrderAction)
		.def("reqQryNegoTrade", &StockApi::reqQryNegoTrade)
		.def("reqQryNegotiationParam", &StockApi::reqQryNegotiationParam)

		.def("onFrontConnected", &StockApi::onFrontConnected)
		.def("onFrontDisconnected", &StockApi::onFrontDisconnected)
		.def("onRspError", &StockApi::onRspError)
		.def("onRspGetConnectionInfo", &StockApi::onRspGetConnectionInfo)
		.def("onRspUserLogin", &StockApi::onRspUserLogin)
		.def("onRspUserLogout", &StockApi::onRspUserLogout)
		.def("onRspUserPasswordUpdate", &StockApi::onRspUserPasswordUpdate)
		.def("onRspInputDeviceSerial", &StockApi::onRspInputDeviceSerial)
		.def("onRspOrderInsert", &StockApi::onRspOrderInsert)
		.def("onRtnOrder", &StockApi::onRtnOrder)
		.def("onErrRtnOrderInsert", &StockApi::onErrRtnOrderInsert)
		.def("onRtnTrade", &StockApi::onRtnTrade)
		.def("onRspOrderAction", &StockApi::onRspOrderAction)
		.def("onErrRtnOrderAction", &StockApi::onErrRtnOrderAction)
		.def("onRspCondOrderInsert", &StockApi::onRspCondOrderInsert)
		.def("onRtnCondOrder", &StockApi::onRtnCondOrder)
		.def("onErrRtnCondOrderInsert", &StockApi::onErrRtnCondOrderInsert)
		.def("onRspCondOrderAction", &StockApi::onRspCondOrderAction)
		.def("onErrRtnCondOrderAction", &StockApi::onErrRtnCondOrderAction)
		.def("onRspNegoOrderInsert", &StockApi::onRspNegoOrderInsert)
		.def("onRtnNegoOrder", &StockApi::onRtnNegoOrder)
		.def("onErrRtnNegoOrderInsert", &StockApi::onErrRtnNegoOrderInsert)
		.def("onRtnNegoTrade", &StockApi::onRtnNegoTrade)
		.def("onRspNegoOrderAction", &StockApi::onRspNegoOrderAction)
		.def("onErrRtnNegoOrderAction", &StockApi::onErrRtnNegoOrderAction)
		.def("onRspOrderInsertEx", &StockApi::onRspOrderInsertEx)
		.def("onRspOrderActionEx", &StockApi::onRspOrderActionEx)
		.def("onRtnMarketStatus", &StockApi::onRtnMarketStatus)
		.def("onRspTransferFund", &StockApi::onRspTransferFund)
		.def("onErrRtnTransferFund", &StockApi::onErrRtnTransferFund)
		.def("onRtnTransferFund", &StockApi::onRtnTransferFund)
		.def("onRspTransferPosition", &StockApi::onRspTransferPosition)
		.def("onErrRtnTransferPosition", &StockApi::onErrRtnTransferPosition)
		.def("onRtnTransferPosition", &StockApi::onRtnTransferPosition)
		.def("onRtnPeripheryTransferPosition", &StockApi::onRtnPeripheryTransferPosition)
		.def("onRtnPeripheryTransferFund", &StockApi::onRtnPeripheryTransferFund)
		.def("onRspInquiryJZFund", &StockApi::onRspInquiryJZFund)
		.def("onRspInquiryBankAccountFund", &StockApi::onRspInquiryBankAccountFund)
		.def("onRtnTradingNotice", &StockApi::onRtnTradingNotice)
		.def("onRspInquiryMaxOrderVolume", &StockApi::onRspInquiryMaxOrderVolume)
		.def("onRspInquiryTradeConcentration", &StockApi::onRspInquiryTradeConcentration)
		.def("onRspModifyOpenPosCost", &StockApi::onRspModifyOpenPosCost)
		.def("onRspInputNodeFundAssignment", &StockApi::onRspInputNodeFundAssignment)
		.def("onRspInquiryNodeFundAssignment", &StockApi::onRspInquiryNodeFundAssignment)
		.def("onRspQryExchange", &StockApi::onRspQryExchange)
		.def("onRspQrySecurity", &StockApi::onRspQrySecurity)
		.def("onRspQryIPOInfo", &StockApi::onRspQryIPOInfo)
		.def("onRspQryUser", &StockApi::onRspQryUser)
		.def("onRspQryInvestor", &StockApi::onRspQryInvestor)
		.def("onRspQryShareholderAccount", &StockApi::onRspQryShareholderAccount)
		.def("onRspQryRationalInfo", &StockApi::onRspQryRationalInfo)
		.def("onRspQryOrder", &StockApi::onRspQryOrder)
		.def("onRspQryOrderAction", &StockApi::onRspQryOrderAction)
		.def("onRspQryTrade", &StockApi::onRspQryTrade)
		.def("onRspQryTradingAccount", &StockApi::onRspQryTradingAccount)
		.def("onRspQryPosition", &StockApi::onRspQryPosition)
		.def("onRspQryTradingFee", &StockApi::onRspQryTradingFee)
		.def("onRspQryInvestorTradingFee", &StockApi::onRspQryInvestorTradingFee)
		.def("onRspQryIPOQuota", &StockApi::onRspQryIPOQuota)
		.def("onRspQryOrderFundDetail", &StockApi::onRspQryOrderFundDetail)
		.def("onRspQryFundTransferDetail", &StockApi::onRspQryFundTransferDetail)
		.def("onRspQryPositionTransferDetail", &StockApi::onRspQryPositionTransferDetail)
		.def("onRspQryPeripheryPositionTransferDetail", &StockApi::onRspQryPeripheryPositionTransferDetail)
		.def("onRspQryPeripheryFundTransferDetail", &StockApi::onRspQryPeripheryFundTransferDetail)
		.def("onRspQryBondConversionInfo", &StockApi::onRspQryBondConversionInfo)
		.def("onRspQryBondPutbackInfo", &StockApi::onRspQryBondPutbackInfo)
		.def("onRspQryInvestorCondOrderLimitParam", &StockApi::onRspQryInvestorCondOrderLimitParam)
		.def("onRspQryConditionOrder", &StockApi::onRspQryConditionOrder)
		.def("onRspQryCondOrderAction", &StockApi::onRspQryCondOrderAction)
		.def("onRspQryTradingNotice", &StockApi::onRspQryTradingNotice)
		.def("onRspQryIPONumberResult", &StockApi::onRspQryIPONumberResult)
		.def("onRspQryIPOMatchNumberResult", &StockApi::onRspQryIPOMatchNumberResult)
		.def("onRspQryShareholderSpecPrivilege", &StockApi::onRspQryShareholderSpecPrivilege)
		.def("onRspQryMarket", &StockApi::onRspQryMarket)
		.def("onRspQryETFFile", &StockApi::onRspQryETFFile)
		.def("onRspQryETFBasket", &StockApi::onRspQryETFBasket)
		.def("onRspQryInvestorPositionLimit", &StockApi::onRspQryInvestorPositionLimit)
		.def("onRspQrySZSEImcParams", &StockApi::onRspQrySZSEImcParams)
		.def("onRspQrySZSEImcExchangeRate", &StockApi::onRspQrySZSEImcExchangeRate)
		.def("onRspQrySZSEHKPriceTickInfo", &StockApi::onRspQrySZSEHKPriceTickInfo)
		.def("onRspQryLofFundInfo", &StockApi::onRspQryLofFundInfo)
		.def("onRspQryPledgePosition", &StockApi::onRspQryPledgePosition)
		.def("onRspQryPledgeInfo", &StockApi::onRspQryPledgeInfo)
		.def("onRspQrySystemNodeInfo", &StockApi::onRspQrySystemNodeInfo)
		.def("onRspQryStandardBondPosition", &StockApi::onRspQryStandardBondPosition)
		.def("onRspQryPrematurityRepoOrder", &StockApi::onRspQryPrematurityRepoOrder)
		.def("onRspQryNegoOrder", &StockApi::onRspQryNegoOrder)
		.def("onRspQryNegoOrderAction", &StockApi::onRspQryNegoOrderAction)
		.def("onRspQryNegoTrade", &StockApi::onRspQryNegoTrade)
		.def("onRspQryNegotiationParam", &StockApi::onRspQryNegotiationParam)
		;

}
