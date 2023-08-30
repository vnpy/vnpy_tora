void ToraMdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void ToraMdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = int(nReason);
	this->task_queue.push(task);
};

void ToraMdApi::OnRspGetConnectionInfo(CTORATstpConnectionInfoField *pConnectionInfoField, CTORATstpRspInfoField *pRspInfoField, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPGETCONNECTIONINFO;
	if (pConnectionInfoField)
	{
		CTORATstpConnectionInfoField *task_data = new CTORATstpConnectionInfoField();
		*task_data = *pConnectionInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLoginField, CTORATstpRspInfoField *pRspInfoField, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLoginField)
	{
		CTORATstpRspUserLoginField *task_data = new CTORATstpRspUserLoginField();
		*task_data = *pRspUserLoginField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogoutField, CTORATstpRspInfoField *pRspInfoField, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogoutField)
	{
		CTORATstpUserLogoutField *task_data = new CTORATstpUserLogoutField();
		*task_data = *pUserLogoutField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubPHMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBPHMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBPHMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSPECIALMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPECIALMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSimplifyMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSimplifyMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSecurityStatus(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSecurityStatus(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubMarketStatus(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubMarketStatus(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubImcParams(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBIMCPARAMS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubImcParams(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBIMCPARAMS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspInquiryMarketDataMirror(CTORATstpMarketDataField *pMarketDataField, CTORATstpRspInfoField *pRspInfoField, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField *task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraMdApi::OnRspInquiryPHMarketDataMirror(CTORATstpPHMarketDataField *pPHMarketDataField, CTORATstpRspInfoField *pRspInfoField, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYPHMARKETDATAMIRROR;
	if (pPHMarketDataField)
	{
		CTORATstpPHMarketDataField *task_data = new CTORATstpPHMarketDataField();
		*task_data = *pPHMarketDataField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraMdApi::OnRspInquirySpecialMarketDataMirror(CTORATstpSpecialMarketDataField *pMarketDataField, CTORATstpRspInfoField *pRspInfoField, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPECIALMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpSpecialMarketDataField *task_data = new CTORATstpSpecialMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSPMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSPMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSPSimplifyMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSPSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSPSimplifyMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPSIMPLIFYMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSPSecurityStatus(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSPSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSPSecurityStatus(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPSECURITYSTATUS;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubSPMarketStatus(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBSPMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubSPMarketStatus(CTORATstpSpecificMarketField *pSpecificMarketField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSPMARKETSTATUS;
	if (pSpecificMarketField)
	{
		CTORATstpSpecificMarketField *task_data = new CTORATstpSpecificMarketField();
		*task_data = *pSpecificMarketField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspInquirySPMarketDataMirror(CTORATstpMarketDataField *pMarketDataField, CTORATstpRspInfoField *pRspInfoField, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPMARKETDATAMIRROR;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField *task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnMarketData(CTORATstpMarketDataField *pMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNMARKETDATA;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField *task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnPHMarketData(CTORATstpPHMarketDataField *pPHMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNPHMARKETDATA;
	if (pPHMarketDataField)
	{
		CTORATstpPHMarketDataField *task_data = new CTORATstpPHMarketDataField();
		*task_data = *pPHMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField *pSpecialMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNSPECIALMARKETDATA;
	if (pSpecialMarketDataField)
	{
		CTORATstpSpecialMarketDataField *task_data = new CTORATstpSpecialMarketDataField();
		*task_data = *pSpecialMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSimplifyMarketData(CTORATstpSimplifyMarketDataField *pSimplifyMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNSIMPLIFYMARKETDATA;
	if (pSimplifyMarketDataField)
	{
		CTORATstpSimplifyMarketDataField *task_data = new CTORATstpSimplifyMarketDataField();
		*task_data = *pSimplifyMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSecurityStatus(CTORATstpSecurityStatusField *pSecurityStatusField) 
{
	Task task = Task();
	task.task_name = ONRTNSECURITYSTATUS;
	if (pSecurityStatusField)
	{
		CTORATstpSecurityStatusField *task_data = new CTORATstpSecurityStatusField();
		*task_data = *pSecurityStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnMarketStatus(CTORATstpMarketStatusField *pMarketStatusField) 
{
	Task task = Task();
	task.task_name = ONRTNMARKETSTATUS;
	if (pMarketStatusField)
	{
		CTORATstpMarketStatusField *task_data = new CTORATstpMarketStatusField();
		*task_data = *pMarketStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnImcParams(CTORATstpImcParamsField *pImcParamsField) 
{
	Task task = Task();
	task.task_name = ONRTNIMCPARAMS;
	if (pImcParamsField)
	{
		CTORATstpImcParamsField *task_data = new CTORATstpImcParamsField();
		*task_data = *pImcParamsField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSPMarketData(CTORATstpMarketDataField *pMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNSPMARKETDATA;
	if (pMarketDataField)
	{
		CTORATstpMarketDataField *task_data = new CTORATstpMarketDataField();
		*task_data = *pMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSPSimplifyMarketData(CTORATstpSimplifyMarketDataField *pSimplifyMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNSPSIMPLIFYMARKETDATA;
	if (pSimplifyMarketDataField)
	{
		CTORATstpSimplifyMarketDataField *task_data = new CTORATstpSimplifyMarketDataField();
		*task_data = *pSimplifyMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSPSecurityStatus(CTORATstpSecurityStatusField *pSecurityStatusField) 
{
	Task task = Task();
	task.task_name = ONRTNSPSECURITYSTATUS;
	if (pSecurityStatusField)
	{
		CTORATstpSecurityStatusField *task_data = new CTORATstpSecurityStatusField();
		*task_data = *pSecurityStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnSPMarketStatus(CTORATstpMarketStatusField *pMarketStatusField) 
{
	Task task = Task();
	task.task_name = ONRTNSPMARKETSTATUS;
	if (pMarketStatusField)
	{
		CTORATstpMarketStatusField *task_data = new CTORATstpMarketStatusField();
		*task_data = *pMarketStatusField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspSubRapidMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPSUBRAPIDMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRspUnSubRapidMarketData(CTORATstpSpecificSecurityField *pSpecificSecurityField, CTORATstpRspInfoField *pRspInfoField) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBRAPIDMARKETDATA;
	if (pSpecificSecurityField)
	{
		CTORATstpSpecificSecurityField *task_data = new CTORATstpSpecificSecurityField();
		*task_data = *pSpecificSecurityField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpRspInfoField *task_error = new CTORATstpRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void ToraMdApi::OnRtnRapidMarketData(CTORATstpRapidMarketDataField *pRapidMarketDataField) 
{
	Task task = Task();
	task.task_name = ONRTNRAPIDMARKETDATA;
	if (pRapidMarketDataField)
	{
		CTORATstpRapidMarketDataField *task_data = new CTORATstpRapidMarketDataField();
		*task_data = *pRapidMarketDataField;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

