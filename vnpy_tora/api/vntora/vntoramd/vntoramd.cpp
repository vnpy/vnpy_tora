// vntoramd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vntoramd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void MdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = int(nReason);
	this->task_queue.push(task);
};

void MdApi::OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
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

void MdApi::OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
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

void MdApi::OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int nRequestID)
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

void MdApi::OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBPHMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBPHMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSPECIALMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPECIALMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBIMCPARAMS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBIMCPARAMS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspInquiryMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField* task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
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

void MdApi::OnRspInquiryPHMarketDataMirror(CTORATstpPHMarketDataField* pPHMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYPHMARKETDATAMIRROR;
	if (pPHMarketDataField)
	{
		CTORATstpPHMarketDataField* task_data = new CTORATstpPHMarketDataField();
		*task_data = *pPHMarketDataField;
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

void MdApi::OnRspInquirySpecialMarketDataMirror(CTORATstpSpecialMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPECIALMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpSpecialMarketDataField* task_data = new CTORATstpSpecialMarketDataField();
		*task_data = *pMarketDataField;
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

void MdApi::OnRspSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSPMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSPSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSPSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBSPMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField* task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspInquirySPMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField* task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
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

void MdApi::OnRtnMarketData(CTORATstpMarketDataField* pMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNMARKETDATA;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField* task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnPHMarketData(CTORATstpPHMarketDataField* pPHMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNPHMARKETDATA;
	if (pPHMarketDataField)
	{
		CTORATstpPHMarketDataField* task_data = new CTORATstpPHMarketDataField();
		*task_data = *pPHMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField* pSpecialMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNSPECIALMARKETDATA;
	if (pSpecialMarketDataField)
	{
		CTORATstpSpecialMarketDataField* task_data = new CTORATstpSpecialMarketDataField();
		*task_data = *pSpecialMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNSIMPLIFYMARKETDATA;
	if (pSimplifyMarketDataField)
	{
		CTORATstpSimplifyMarketDataField* task_data = new CTORATstpSimplifyMarketDataField();
		*task_data = *pSimplifyMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField)
{
	Task task = Task();
	task.task_name = ONRTNSECURITYSTATUS;
	if (pSecurityStatusField)
	{
		CTORATstpSecurityStatusField* task_data = new CTORATstpSecurityStatusField();
		*task_data = *pSecurityStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField)
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

void MdApi::OnRtnImcParams(CTORATstpImcParamsField* pImcParamsField)
{
	Task task = Task();
	task.task_name = ONRTNIMCPARAMS;
	if (pImcParamsField)
	{
		CTORATstpImcParamsField* task_data = new CTORATstpImcParamsField();
		*task_data = *pImcParamsField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSPMarketData(CTORATstpMarketDataField* pMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNSPMARKETDATA;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField* task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSPSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNSPSIMPLIFYMARKETDATA;
	if (pSimplifyMarketDataField)
	{
		CTORATstpSimplifyMarketDataField* task_data = new CTORATstpSimplifyMarketDataField();
		*task_data = *pSimplifyMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSPSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField)
{
	Task task = Task();
	task.task_name = ONRTNSPSECURITYSTATUS;
	if (pSecurityStatusField)
	{
		CTORATstpSecurityStatusField* task_data = new CTORATstpSecurityStatusField();
		*task_data = *pSecurityStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSPMarketStatus(CTORATstpMarketStatusField* pMarketStatusField)
{
	Task task = Task();
	task.task_name = ONRTNSPMARKETSTATUS;
	if (pMarketStatusField)
	{
		CTORATstpMarketStatusField* task_data = new CTORATstpMarketStatusField();
		*task_data = *pMarketStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPSUBRAPIDMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBRAPIDMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField* task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField* task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnRapidMarketData(CTORATstpRapidMarketDataField* pRapidMarketDataField)
{
	Task task = Task();
	task.task_name = ONRTNRAPIDMARKETDATA;
	if (pRapidMarketDataField)
	{
		CTORATstpRapidMarketDataField* task_data = new CTORATstpRapidMarketDataField();
		*task_data = *pRapidMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void MdApi::processTask()
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

			case ONRSPSUBMARKETDATA:
			{
				this->processRspSubMarketData(&task);
				break;
			}

			case ONRSPUNSUBMARKETDATA:
			{
				this->processRspUnSubMarketData(&task);
				break;
			}

			case ONRSPSUBPHMARKETDATA:
			{
				this->processRspSubPHMarketData(&task);
				break;
			}

			case ONRSPUNSUBPHMARKETDATA:
			{
				this->processRspUnSubPHMarketData(&task);
				break;
			}

			case ONRSPSUBSPECIALMARKETDATA:
			{
				this->processRspSubSpecialMarketData(&task);
				break;
			}

			case ONRSPUNSUBSPECIALMARKETDATA:
			{
				this->processRspUnSubSpecialMarketData(&task);
				break;
			}

			case ONRSPSUBSIMPLIFYMARKETDATA:
			{
				this->processRspSubSimplifyMarketData(&task);
				break;
			}

			case ONRSPUNSUBSIMPLIFYMARKETDATA:
			{
				this->processRspUnSubSimplifyMarketData(&task);
				break;
			}

			case ONRSPSUBSECURITYSTATUS:
			{
				this->processRspSubSecurityStatus(&task);
				break;
			}

			case ONRSPUNSUBSECURITYSTATUS:
			{
				this->processRspUnSubSecurityStatus(&task);
				break;
			}

			case ONRSPSUBMARKETSTATUS:
			{
				this->processRspSubMarketStatus(&task);
				break;
			}

			case ONRSPUNSUBMARKETSTATUS:
			{
				this->processRspUnSubMarketStatus(&task);
				break;
			}

			case ONRSPSUBIMCPARAMS:
			{
				this->processRspSubImcParams(&task);
				break;
			}

			case ONRSPUNSUBIMCPARAMS:
			{
				this->processRspUnSubImcParams(&task);
				break;
			}

			case ONRSPINQUIRYMARKETDATAMIRROR:
			{
				this->processRspInquiryMarketDataMirror(&task);
				break;
			}

			case ONRSPINQUIRYPHMARKETDATAMIRROR:
			{
				this->processRspInquiryPHMarketDataMirror(&task);
				break;
			}

			case ONRSPINQUIRYSPECIALMARKETDATAMIRROR:
			{
				this->processRspInquirySpecialMarketDataMirror(&task);
				break;
			}

			case ONRSPSUBSPMARKETDATA:
			{
				this->processRspSubSPMarketData(&task);
				break;
			}

			case ONRSPUNSUBSPMARKETDATA:
			{
				this->processRspUnSubSPMarketData(&task);
				break;
			}

			case ONRSPSUBSPSIMPLIFYMARKETDATA:
			{
				this->processRspSubSPSimplifyMarketData(&task);
				break;
			}

			case ONRSPUNSUBSPSIMPLIFYMARKETDATA:
			{
				this->processRspUnSubSPSimplifyMarketData(&task);
				break;
			}

			case ONRSPSUBSPSECURITYSTATUS:
			{
				this->processRspSubSPSecurityStatus(&task);
				break;
			}

			case ONRSPUNSUBSPSECURITYSTATUS:
			{
				this->processRspUnSubSPSecurityStatus(&task);
				break;
			}

			case ONRSPSUBSPMARKETSTATUS:
			{
				this->processRspSubSPMarketStatus(&task);
				break;
			}

			case ONRSPUNSUBSPMARKETSTATUS:
			{
				this->processRspUnSubSPMarketStatus(&task);
				break;
			}

			case ONRSPINQUIRYSPMARKETDATAMIRROR:
			{
				this->processRspInquirySPMarketDataMirror(&task);
				break;
			}

			case ONRTNMARKETDATA:
			{
				this->processRtnMarketData(&task);
				break;
			}

			case ONRTNPHMARKETDATA:
			{
				this->processRtnPHMarketData(&task);
				break;
			}

			case ONRTNSPECIALMARKETDATA:
			{
				this->processRtnSpecialMarketData(&task);
				break;
			}

			case ONRTNSIMPLIFYMARKETDATA:
			{
				this->processRtnSimplifyMarketData(&task);
				break;
			}

			case ONRTNSECURITYSTATUS:
			{
				this->processRtnSecurityStatus(&task);
				break;
			}

			case ONRTNMARKETSTATUS:
			{
				this->processRtnMarketStatus(&task);
				break;
			}

			case ONRTNIMCPARAMS:
			{
				this->processRtnImcParams(&task);
				break;
			}

			case ONRTNSPMARKETDATA:
			{
				this->processRtnSPMarketData(&task);
				break;
			}

			case ONRTNSPSIMPLIFYMARKETDATA:
			{
				this->processRtnSPSimplifyMarketData(&task);
				break;
			}

			case ONRTNSPSECURITYSTATUS:
			{
				this->processRtnSPSecurityStatus(&task);
				break;
			}

			case ONRTNSPMARKETSTATUS:
			{
				this->processRtnSPMarketStatus(&task);
				break;
			}

			case ONRSPSUBRAPIDMARKETDATA:
			{
				this->processRspSubRapidMarketData(&task);
				break;
			}

			case ONRSPUNSUBRAPIDMARKETDATA:
			{
				this->processRspUnSubRapidMarketData(&task);
				break;
			}

			case ONRTNRAPIDMARKETDATA:
			{
				this->processRtnRapidMarketData(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void MdApi::processFrontConnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void MdApi::processFrontDisconnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void MdApi::processRspGetConnectionInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConnectionInfoField* task_data = (CTORATstpConnectionInfoField*)task->task_data;
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

void MdApi::processRspUserLogin(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspUserLoginField* task_data = (CTORATstpRspUserLoginField*)task->task_data;
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

void MdApi::processRspUserLogout(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserLogoutField* task_data = (CTORATstpUserLogoutField*)task->task_data;
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

void MdApi::processRspSubMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubMarketData(data, error);
};

void MdApi::processRspUnSubMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubMarketData(data, error);
};

void MdApi::processRspSubPHMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubPHMarketData(data, error);
};

void MdApi::processRspUnSubPHMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubPHMarketData(data, error);
};

void MdApi::processRspSubSpecialMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSpecialMarketData(data, error);
};

void MdApi::processRspUnSubSpecialMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSpecialMarketData(data, error);
};

void MdApi::processRspSubSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSimplifyMarketData(data, error);
};

void MdApi::processRspUnSubSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSimplifyMarketData(data, error);
};

void MdApi::processRspSubSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSecurityStatus(data, error);
};

void MdApi::processRspUnSubSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSecurityStatus(data, error);
};

void MdApi::processRspSubMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspSubMarketStatus(data, error);
};

void MdApi::processRspUnSubMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspUnSubMarketStatus(data, error);
};

void MdApi::processRspSubImcParams(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspSubImcParams(data, error);
};

void MdApi::processRspUnSubImcParams(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspUnSubImcParams(data, error);
};

void MdApi::processRspInquiryMarketDataMirror(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField* task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
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
	this->onRspInquiryMarketDataMirror(data, error, task->task_id, task->task_last);
};

void MdApi::processRspInquiryPHMarketDataMirror(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPHMarketDataField* task_data = (CTORATstpPHMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["BidVolume"] = task_data->BidVolume;
		data["AskVolume"] = task_data->AskVolume;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
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
	this->onRspInquiryPHMarketDataMirror(data, error, task->task_id, task->task_last);
};

void MdApi::processRspInquirySpecialMarketDataMirror(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecialMarketDataField* task_data = (CTORATstpSpecialMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["MovingAvgPrice"] = task_data->MovingAvgPrice;
		data["MovingAvgPriceSamplingNum"] = task_data->MovingAvgPriceSamplingNum;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
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
	this->onRspInquirySpecialMarketDataMirror(data, error, task->task_id, task->task_last);
};

void MdApi::processRspSubSPMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSPMarketData(data, error);
};

void MdApi::processRspUnSubSPMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSPMarketData(data, error);
};

void MdApi::processRspSubSPSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSPSimplifyMarketData(data, error);
};

void MdApi::processRspUnSubSPSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSPSimplifyMarketData(data, error);
};

void MdApi::processRspSubSPSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubSPSecurityStatus(data, error);
};

void MdApi::processRspUnSubSPSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubSPSecurityStatus(data, error);
};

void MdApi::processRspSubSPMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspSubSPMarketStatus(data, error);
};

void MdApi::processRspUnSubSPMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField* task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
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
	this->onRspUnSubSPMarketStatus(data, error);
};

void MdApi::processRspInquirySPMarketDataMirror(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField* task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
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
	this->onRspInquirySPMarketDataMirror(data, error, task->task_id, task->task_last);
};

void MdApi::processRtnMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField* task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	this->onRtnMarketData(data);
};

void MdApi::processRtnPHMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPHMarketDataField* task_data = (CTORATstpPHMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["BidVolume"] = task_data->BidVolume;
		data["AskVolume"] = task_data->AskVolume;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		delete task_data;
	}
	this->onRtnPHMarketData(data);
};

void MdApi::processRtnSpecialMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecialMarketDataField* task_data = (CTORATstpSpecialMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["MovingAvgPrice"] = task_data->MovingAvgPrice;
		data["MovingAvgPriceSamplingNum"] = task_data->MovingAvgPriceSamplingNum;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		delete task_data;
	}
	this->onRtnSpecialMarketData(data);
};

void MdApi::processRtnSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSimplifyMarketDataField* task_data = (CTORATstpSimplifyMarketDataField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		delete task_data;
	}
	this->onRtnSimplifyMarketData(data);
};

void MdApi::processRtnSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityStatusField* task_data = (CTORATstpSecurityStatusField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["IsSuspend"] = task_data->IsSuspend;
		data["IsBreak"] = task_data->IsBreak;
		data["IsLongSuspend"] = task_data->IsLongSuspend;
		data["IsCircuitBreak"] = task_data->IsCircuitBreak;
		data["IsSupportMarginBuy"] = task_data->IsSupportMarginBuy;
		data["IsSupportShortSell"] = task_data->IsSupportShortSell;
		data["IsSupportPur"] = task_data->IsSupportPur;
		data["IsSupportRed"] = task_data->IsSupportRed;
		data["IsSupportSplit"] = task_data->IsSupportSplit;
		data["IsSupportMerge"] = task_data->IsSupportMerge;
		data["IsSupportPleadgeIn"] = task_data->IsSupportPleadgeIn;
		data["IsSupportPleadgeOut"] = task_data->IsSupportPleadgeOut;
		data["IsSupportRoundLotBuy"] = task_data->IsSupportRoundLotBuy;
		data["IsSupportRoundLotSell"] = task_data->IsSupportRoundLotSell;
		data["IsSupportOddLotBuy"] = task_data->IsSupportOddLotBuy;
		data["IsSupportOddLotSell"] = task_data->IsSupportOddLotSell;
		data["IsSupportExercise"] = task_data->IsSupportExercise;
		data["IsLimitBuy"] = task_data->IsLimitBuy;
		data["IsLimitSell"] = task_data->IsLimitSell;
		data["IsLimitCover"] = task_data->IsLimitCover;
		data["IsLimitMarketMaker"] = task_data->IsLimitMarketMaker;
		delete task_data;
	}
	this->onRtnSecurityStatus(data);
};

void MdApi::processRtnMarketStatus(Task* task)
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

void MdApi::processRtnImcParams(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpImcParamsField* task_data = (CTORATstpImcParamsField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["OpenFlag"] = task_data->OpenFlag;
		data["ThresholdAmount"] = task_data->ThresholdAmount;
		data["PosAmt"] = task_data->PosAmt;
		data["AmountStatus"] = task_data->AmountStatus;
		delete task_data;
	}
	this->onRtnImcParams(data);
};

void MdApi::processRtnSPMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField* task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	this->onRtnSPMarketData(data);
};

void MdApi::processRtnSPSimplifyMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSimplifyMarketDataField* task_data = (CTORATstpSimplifyMarketDataField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		delete task_data;
	}
	this->onRtnSPSimplifyMarketData(data);
};

void MdApi::processRtnSPSecurityStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityStatusField* task_data = (CTORATstpSecurityStatusField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["IsSuspend"] = task_data->IsSuspend;
		data["IsBreak"] = task_data->IsBreak;
		data["IsLongSuspend"] = task_data->IsLongSuspend;
		data["IsCircuitBreak"] = task_data->IsCircuitBreak;
		data["IsSupportMarginBuy"] = task_data->IsSupportMarginBuy;
		data["IsSupportShortSell"] = task_data->IsSupportShortSell;
		data["IsSupportPur"] = task_data->IsSupportPur;
		data["IsSupportRed"] = task_data->IsSupportRed;
		data["IsSupportSplit"] = task_data->IsSupportSplit;
		data["IsSupportMerge"] = task_data->IsSupportMerge;
		data["IsSupportPleadgeIn"] = task_data->IsSupportPleadgeIn;
		data["IsSupportPleadgeOut"] = task_data->IsSupportPleadgeOut;
		data["IsSupportRoundLotBuy"] = task_data->IsSupportRoundLotBuy;
		data["IsSupportRoundLotSell"] = task_data->IsSupportRoundLotSell;
		data["IsSupportOddLotBuy"] = task_data->IsSupportOddLotBuy;
		data["IsSupportOddLotSell"] = task_data->IsSupportOddLotSell;
		data["IsSupportExercise"] = task_data->IsSupportExercise;
		data["IsLimitBuy"] = task_data->IsLimitBuy;
		data["IsLimitSell"] = task_data->IsLimitSell;
		data["IsLimitCover"] = task_data->IsLimitCover;
		data["IsLimitMarketMaker"] = task_data->IsLimitMarketMaker;
		delete task_data;
	}
	this->onRtnSPSecurityStatus(data);
};

void MdApi::processRtnSPMarketStatus(Task* task)
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
	this->onRtnSPMarketStatus(data);
};

void MdApi::processRspSubRapidMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspSubRapidMarketData(data, error);
};

void MdApi::processRspUnSubRapidMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField* task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
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
	this->onRspUnSubRapidMarketData(data, error);
};

void MdApi::processRtnRapidMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRapidMarketDataField* task_data = (CTORATstpRapidMarketDataField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["DataTimeStamp"] = task_data->DataTimeStamp;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["NumTrades"] = task_data->NumTrades;
		data["TotalVolumeTrade"] = task_data->TotalVolumeTrade;
		data["TotalValueTrade"] = task_data->TotalValueTrade;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice6"] = task_data->AskPrice6;
		data["AskVolume6"] = task_data->AskVolume6;
		data["AskPrice7"] = task_data->AskPrice7;
		data["AskVolume7"] = task_data->AskVolume7;
		data["BidPrice6"] = task_data->BidPrice6;
		data["BidVolume6"] = task_data->BidVolume6;
		data["BidPrice7"] = task_data->BidPrice7;
		data["BidVolume7"] = task_data->BidVolume7;
		data["AskPrice8"] = task_data->AskPrice8;
		data["AskVolume8"] = task_data->AskVolume8;
		data["AskPrice9"] = task_data->AskPrice9;
		data["AskVolume9"] = task_data->AskVolume9;
		data["BidPrice8"] = task_data->BidPrice8;
		data["BidVolume8"] = task_data->BidVolume8;
		data["BidPrice9"] = task_data->BidPrice9;
		data["BidVolume9"] = task_data->BidVolume9;
		data["BidPrice10"] = task_data->BidPrice10;
		data["BidVolume10"] = task_data->BidVolume10;
		data["AskPrice10"] = task_data->AskPrice10;
		data["AskVolume10"] = task_data->AskVolume10;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["IOPV"] = task_data->IOPV;
		data["InnerSell"] = task_data->InnerSell;
		data["OuterBuy"] = task_data->OuterBuy;
		data["BidCount1"] = task_data->BidCount1;
		data["AskCount1"] = task_data->AskCount1;
		data["AskCount2"] = task_data->AskCount2;
		data["AskCount3"] = task_data->AskCount3;
		data["BidCount2"] = task_data->BidCount2;
		data["BidCount3"] = task_data->BidCount3;
		data["AskCount4"] = task_data->AskCount4;
		data["AskCount5"] = task_data->AskCount5;
		data["BidCount4"] = task_data->BidCount4;
		data["BidCount5"] = task_data->BidCount5;
		data["AskCount6"] = task_data->AskCount6;
		data["AskCount7"] = task_data->AskCount7;
		data["BidCount6"] = task_data->BidCount6;
		data["BidCount7"] = task_data->BidCount7;
		data["AskCount8"] = task_data->AskCount8;
		data["AskCount9"] = task_data->AskCount9;
		data["BidCount8"] = task_data->BidCount8;
		data["BidCount9"] = task_data->BidCount9;
		data["BidCount10"] = task_data->BidCount10;
		data["AskCount10"] = task_data->AskCount10;
		delete task_data;
	}
	this->onRtnRapidMarketData(data);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void MdApi::createTstpXMdApi()
{
	this->api = CTORATstpXMdApi::CreateTstpXMdApi();
	this->api->RegisterSpi(this);

	this->active = true;
	this->task_thread = thread(&MdApi::processTask, this);

};

void MdApi::init()
{
	this->api->Init();
};

void MdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

int MdApi::join()
{
	int i = this->api->Join();
	return i;
};

void MdApi::release()
{
	this->api->Release();
};

string MdApi::getApiVersion()
{
	return this->api->GetApiVersion();
};

int MdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

void MdApi::registerNameServer(string pszNsAddress)
{
	this->api->RegisterNameServer((char*)pszNsAddress.c_str());
}

void MdApi::registerFensUserInfo(const dict& req)
{
	CTORATstpFensUserInfoField myreq = CTORATstpFensUserInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getShort(req, "FensVer", &myreq.FensVer);
	getString(req, "FensEnvID", myreq.FensEnvID);
	getString(req, "FensNodeID", myreq.FensNodeID);
	getString(req, "FensUserID", myreq.FensUserID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ClientInfo", myreq.ClientInfo);
	this->api->RegisterFensUserInfo(&myreq);
}

void MdApi::registerMulticast(string pszMulticastAddress, string pszInterfaceIP, string pszSourceIp)
{
	this->api->RegisterMulticast((char*)pszMulticastAddress.c_str(), (char*)pszInterfaceIP.c_str(), (char*)pszSourceIp.c_str());
}

void MdApi::registerDeriveServer(string pszDeriveAddress)
{
	this->api->RegisterDeriveServer((char*)pszDeriveAddress.c_str());
}

void MdApi::registerDeriveMulticast(string pszMulticastAddress, string pszInterfaceIP, string pszSourceIp)
{
	this->api->RegisterDeriveMulticast((char*)pszMulticastAddress.c_str(), (char*)pszInterfaceIP.c_str(), (char*)pszSourceIp.c_str());
}

int MdApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int MdApi::reqUserLogin(const dict& req, int nRequestID)
{
	CTORATstpReqUserLoginField myreq = CTORATstpReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
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
	int i = this->api->ReqUserLogin(&myreq, nRequestID);
	return i;
};

int MdApi::reqUserLogout(const dict& req, int nRequestID)
{
	CTORATstpUserLogoutField myreq = CTORATstpUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int MdApi::subscribeMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribePHMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribePHMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribePHMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribePHMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSpecialMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSpecialMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSpecialMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSpecialMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSimplifyMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSimplifyMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSecurityStatus(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSecurityStatus(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeMarketStatus(string MarketID)
{
	int i = this->api->SubscribeMarketStatus((char)MarketID.c_str());
	return i;
};

int MdApi::unSubscribeMarketStatus(string MarketID)
{
	int i = this->api->UnSubscribeMarketStatus((char)MarketID.c_str());
	return i;
};

int MdApi::subscribeImcParams(string MarketID)
{
	int i = this->api->SubscribeImcParams((char)MarketID.c_str());
	return i;
};

int MdApi::unSubscribeImcParams(string MarketID)
{
	int i = this->api->UnSubscribeImcParams((char)MarketID.c_str());
	return i;
};

int MdApi::reqInquiryMarketDataMirror(const dict& req, int nRequestID)
{
	CTORATstpInquiryMarketDataField myreq = CTORATstpInquiryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::reqInquiryPHMarketDataMirror(const dict& req, int nRequestID)
{
	CTORATstpInquiryMarketDataField myreq = CTORATstpInquiryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryPHMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::reqInquirySpecialMarketDataMirror(const dict& req, int nRequestID)
{
	CTORATstpInquirySpecialMarketDataField myreq = CTORATstpInquirySpecialMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquirySpecialMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::subscribeSPMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSPMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSPMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSPMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSPSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSPSimplifyMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSPSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSPSimplifyMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSPSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeSPSecurityStatus(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeSPSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeSPSecurityStatus(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::subscribeSPMarketStatus(string MarketID)
{
	int i = this->api->SubscribeSPMarketStatus((char)MarketID.c_str());
	return i;
};

int MdApi::unSubscribeSPMarketStatus(string MarketID)
{
	int i = this->api->UnSubscribeSPMarketStatus((char)MarketID.c_str());
	return i;
};

int MdApi::reqInquirySPMarketDataMirror(const dict& req, int nRequestID)
{
	CTORATstpInquiryMarketDataField myreq = CTORATstpInquiryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquirySPMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::subscribeRapidMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->SubscribeRapidMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

int MdApi::unSubscribeRapidMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	char* buffer = (char*)ppSecurityID.c_str();
	int i = this->api->UnSubscribeRapidMarketData(&buffer, nCount, ExchangeID.c_str()[0]);
	return i;
};

///-------------------------------------------------------------------------------------
///pybind11封装
///-------------------------------------------------------------------------------------

class PyMdApi : public MdApi
{
public:
	using MdApi::MdApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFrontConnected);
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
			PYBIND11_OVERLOAD(void, MdApi, onFrontDisconnected, nReason);
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
			PYBIND11_OVERLOAD(void, MdApi, onRspGetConnectionInfo, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, MdApi, onRspUserLogin, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, MdApi, onRspUserLogout, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubPHMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubPHMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubPHMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubPHMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSpecialMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSpecialMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSpecialMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSpecialMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSimplifyMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSimplifyMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSimplifyMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSimplifyMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSecurityStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSecurityStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSecurityStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSecurityStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubMarketStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubMarketStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubMarketStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubMarketStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubImcParams(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubImcParams, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubImcParams(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubImcParams, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspInquiryMarketDataMirror, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryPHMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspInquiryPHMarketDataMirror, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquirySpecialMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspInquirySpecialMarketDataMirror, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSPMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSPMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSPMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSPSimplifyMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSPSimplifyMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSPSimplifyMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPSimplifyMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSPSecurityStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSPSecurityStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSPSecurityStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPSecurityStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubSPMarketStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubSPMarketStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubSPMarketStatus(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPMarketStatus, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquirySPMarketDataMirror(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspInquirySPMarketDataMirror, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPHMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnPHMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSpecialMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSpecialMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSimplifyMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSimplifyMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecurityStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecurityStatus, data);
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
			PYBIND11_OVERLOAD(void, MdApi, onRtnMarketStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnImcParams(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnImcParams, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSPMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSPMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSPSimplifyMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSPSimplifyMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSPSecurityStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSPSecurityStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSPMarketStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSPMarketStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubRapidMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubRapidMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubRapidMarketData(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubRapidMarketData, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnRapidMarketData(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnRapidMarketData, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vntoramd, m)
{
	class_<MdApi, PyMdApi> MdApi(m, "MdApi", module_local());
	MdApi
		.def(init<>())
		.def("createTstpXMdApi", &MdApi::createTstpXMdApi)
		.def("registerFront", &MdApi::registerFront)
		.def("init", &MdApi::init)
		.def("join", &MdApi::join)
		.def("release", &MdApi::release)
		.def("getApiVersion", &MdApi::getApiVersion)
		.def("exit", &MdApi::exit)
		.def("registerNameServer", &MdApi::registerNameServer)
		.def("registerFensUserInfo", &MdApi::registerFensUserInfo)
		.def("registerMulticast", &MdApi::registerMulticast)
		.def("registerDeriveServer", &MdApi::registerDeriveServer)
		.def("registerDeriveMulticast", &MdApi::registerDeriveMulticast)
		.def("reqGetConnectionInfo", &MdApi::reqGetConnectionInfo)
		.def("reqUserLogin", &MdApi::reqUserLogin)
		.def("reqUserLogout", &MdApi::reqUserLogout)
		.def("subscribeMarketData", &MdApi::subscribeMarketData)
		.def("unSubscribeMarketData", &MdApi::unSubscribeMarketData)
		.def("subscribePHMarketData", &MdApi::subscribePHMarketData)
		.def("unSubscribePHMarketData", &MdApi::unSubscribePHMarketData)
		.def("subscribeSpecialMarketData", &MdApi::subscribeSpecialMarketData)
		.def("unSubscribeSpecialMarketData", &MdApi::unSubscribeSpecialMarketData)
		.def("subscribeSimplifyMarketData", &MdApi::subscribeSimplifyMarketData)
		.def("unSubscribeSimplifyMarketData", &MdApi::unSubscribeSimplifyMarketData)
		.def("subscribeSecurityStatus", &MdApi::subscribeSecurityStatus)
		.def("unSubscribeSecurityStatus", &MdApi::unSubscribeSecurityStatus)
		.def("subscribeMarketStatus", &MdApi::subscribeMarketStatus)
		.def("unSubscribeMarketStatus", &MdApi::unSubscribeMarketStatus)
		.def("subscribeImcParams", &MdApi::subscribeImcParams)
		.def("unSubscribeImcParams", &MdApi::unSubscribeImcParams)
		.def("reqInquiryMarketDataMirror", &MdApi::reqInquiryMarketDataMirror)
		.def("reqInquiryPHMarketDataMirror", &MdApi::reqInquiryPHMarketDataMirror)
		.def("reqInquirySpecialMarketDataMirror", &MdApi::reqInquirySpecialMarketDataMirror)
		.def("subscribeSPMarketData", &MdApi::subscribeSPMarketData)
		.def("unSubscribeSPMarketData", &MdApi::unSubscribeSPMarketData)
		.def("subscribeSPSimplifyMarketData", &MdApi::subscribeSPSimplifyMarketData)
		.def("unSubscribeSPSimplifyMarketData", &MdApi::unSubscribeSPSimplifyMarketData)
		.def("subscribeSPSecurityStatus", &MdApi::subscribeSPSecurityStatus)
		.def("unSubscribeSPSecurityStatus", &MdApi::unSubscribeSPSecurityStatus)
		.def("subscribeSPMarketStatus", &MdApi::subscribeSPMarketStatus)
		.def("unSubscribeSPMarketStatus", &MdApi::unSubscribeSPMarketStatus)
		.def("reqInquirySPMarketDataMirror", &MdApi::reqInquirySPMarketDataMirror)
		.def("subscribeRapidMarketData", &MdApi::subscribeRapidMarketData)
		.def("unSubscribeRapidMarketData", &MdApi::unSubscribeRapidMarketData)

		.def("onFrontConnected", &MdApi::onFrontConnected)
		.def("onFrontDisconnected", &MdApi::onFrontDisconnected)
		.def("onRspGetConnectionInfo", &MdApi::onRspGetConnectionInfo)
		.def("onRspUserLogin", &MdApi::onRspUserLogin)
		.def("onRspUserLogout", &MdApi::onRspUserLogout)
		.def("onRspSubMarketData", &MdApi::onRspSubMarketData)
		.def("onRspUnSubMarketData", &MdApi::onRspUnSubMarketData)
		.def("onRspSubPHMarketData", &MdApi::onRspSubPHMarketData)
		.def("onRspUnSubPHMarketData", &MdApi::onRspUnSubPHMarketData)
		.def("onRspSubSpecialMarketData", &MdApi::onRspSubSpecialMarketData)
		.def("onRspUnSubSpecialMarketData", &MdApi::onRspUnSubSpecialMarketData)
		.def("onRspSubSimplifyMarketData", &MdApi::onRspSubSimplifyMarketData)
		.def("onRspUnSubSimplifyMarketData", &MdApi::onRspUnSubSimplifyMarketData)
		.def("onRspSubSecurityStatus", &MdApi::onRspSubSecurityStatus)
		.def("onRspUnSubSecurityStatus", &MdApi::onRspUnSubSecurityStatus)
		.def("onRspSubMarketStatus", &MdApi::onRspSubMarketStatus)
		.def("onRspUnSubMarketStatus", &MdApi::onRspUnSubMarketStatus)
		.def("onRspSubImcParams", &MdApi::onRspSubImcParams)
		.def("onRspUnSubImcParams", &MdApi::onRspUnSubImcParams)
		.def("onRspInquiryMarketDataMirror", &MdApi::onRspInquiryMarketDataMirror)
		.def("onRspInquiryPHMarketDataMirror", &MdApi::onRspInquiryPHMarketDataMirror)
		.def("onRspInquirySpecialMarketDataMirror", &MdApi::onRspInquirySpecialMarketDataMirror)
		.def("onRspSubSPMarketData", &MdApi::onRspSubSPMarketData)
		.def("onRspUnSubSPMarketData", &MdApi::onRspUnSubSPMarketData)
		.def("onRspSubSPSimplifyMarketData", &MdApi::onRspSubSPSimplifyMarketData)
		.def("onRspUnSubSPSimplifyMarketData", &MdApi::onRspUnSubSPSimplifyMarketData)
		.def("onRspSubSPSecurityStatus", &MdApi::onRspSubSPSecurityStatus)
		.def("onRspUnSubSPSecurityStatus", &MdApi::onRspUnSubSPSecurityStatus)
		.def("onRspSubSPMarketStatus", &MdApi::onRspSubSPMarketStatus)
		.def("onRspUnSubSPMarketStatus", &MdApi::onRspUnSubSPMarketStatus)
		.def("onRspInquirySPMarketDataMirror", &MdApi::onRspInquirySPMarketDataMirror)
		.def("onRtnMarketData", &MdApi::onRtnMarketData)
		.def("onRtnPHMarketData", &MdApi::onRtnPHMarketData)
		.def("onRtnSpecialMarketData", &MdApi::onRtnSpecialMarketData)
		.def("onRtnSimplifyMarketData", &MdApi::onRtnSimplifyMarketData)
		.def("onRtnSecurityStatus", &MdApi::onRtnSecurityStatus)
		.def("onRtnMarketStatus", &MdApi::onRtnMarketStatus)
		.def("onRtnImcParams", &MdApi::onRtnImcParams)
		.def("onRtnSPMarketData", &MdApi::onRtnSPMarketData)
		.def("onRtnSPSimplifyMarketData", &MdApi::onRtnSPSimplifyMarketData)
		.def("onRtnSPSecurityStatus", &MdApi::onRtnSPSecurityStatus)
		.def("onRtnSPMarketStatus", &MdApi::onRtnSPMarketStatus)
		.def("onRspSubRapidMarketData", &MdApi::onRspSubRapidMarketData)
		.def("onRspUnSubRapidMarketData", &MdApi::onRspUnSubRapidMarketData)
		.def("onRtnRapidMarketData", &MdApi::onRtnRapidMarketData)
		;

}
