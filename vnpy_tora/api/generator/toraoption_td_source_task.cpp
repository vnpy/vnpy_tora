void OptionApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void OptionApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = int(nReason);
	this->task_queue.push(task);
};

void OptionApi::OnRspError(CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspGetConnectionInfo(CTORATstpSPConnectionInfoField *pConnectionInfoField, CTORATstpSPRspInfoField *pRspInfoField, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPGETCONNECTIONINFO;
	if (pConnectionInfoField)
	{
		CTORATstpSPConnectionInfoField *task_data = new CTORATstpSPConnectionInfoField();
		*task_data = *pConnectionInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspUserLogin(CTORATstpSPRspUserLoginField *pRspUserLoginField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLoginField)
	{
		CTORATstpSPRspUserLoginField *task_data = new CTORATstpSPRspUserLoginField();
		*task_data = *pRspUserLoginField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspUserLogout(CTORATstpSPUserLogoutField *pUserLogoutField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogoutField)
	{
		CTORATstpSPUserLogoutField *task_data = new CTORATstpSPUserLogoutField();
		*task_data = *pUserLogoutField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspUserPasswordUpdate(CTORATstpSPUserPasswordUpdateField *pUserPasswordUpdateField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;
	if (pUserPasswordUpdateField)
	{
		CTORATstpSPUserPasswordUpdateField *task_data = new CTORATstpSPUserPasswordUpdateField();
		*task_data = *pUserPasswordUpdateField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInputDeviceSerial(CTORATstpSPRspInputDeviceSerialField *pRspInputDeviceSerialField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINPUTDEVICESERIAL;
	if (pRspInputDeviceSerialField)
	{
		CTORATstpSPRspInputDeviceSerialField *task_data = new CTORATstpSPRspInputDeviceSerialField();
		*task_data = *pRspInputDeviceSerialField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspOrderInsert(CTORATstpSPInputOrderField *pInputOrderField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;
	if (pInputOrderField)
	{
		CTORATstpSPInputOrderField *task_data = new CTORATstpSPInputOrderField();
		*task_data = *pInputOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnOrder(CTORATstpSPOrderField *pOrder) 
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pOrder)
	{
		CTORATstpSPOrderField *task_data = new CTORATstpSPOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnOrderInsert(CTORATstpSPInputOrderField *pInputOrder, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNORDERINSERT;
	if (pInputOrder)
	{
		CTORATstpSPInputOrderField *task_data = new CTORATstpSPInputOrderField();
		*task_data = *pInputOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspOrderAction(CTORATstpSPInputOrderActionField *pInputOrderActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pInputOrderActionField)
	{
		CTORATstpSPInputOrderActionField *task_data = new CTORATstpSPInputOrderActionField();
		*task_data = *pInputOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnOrderAction(CTORATstpSPInputOrderActionField *pInputOrderAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;
	if (pInputOrderAction)
	{
		CTORATstpSPInputOrderActionField *task_data = new CTORATstpSPInputOrderActionField();
		*task_data = *pInputOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnTrade(CTORATstpSPTradeField *pTrade) 
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pTrade)
	{
		CTORATstpSPTradeField *task_data = new CTORATstpSPTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnRspExerciseInsert(CTORATstpSPInputExerciseField *pInputExerciseField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPEXERCISEINSERT;
	if (pInputExerciseField)
	{
		CTORATstpSPInputExerciseField *task_data = new CTORATstpSPInputExerciseField();
		*task_data = *pInputExerciseField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnExercise(CTORATstpSPExerciseField *pExercise) 
{
	Task task = Task();
	task.task_name = ONRTNEXERCISE;
	if (pExercise)
	{
		CTORATstpSPExerciseField *task_data = new CTORATstpSPExerciseField();
		*task_data = *pExercise;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnExerciseInsert(CTORATstpSPInputExerciseField *pInputExercise, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNEXERCISEINSERT;
	if (pInputExercise)
	{
		CTORATstpSPInputExerciseField *task_data = new CTORATstpSPInputExerciseField();
		*task_data = *pInputExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspExerciseAction(CTORATstpSPInputExerciseActionField *pInputExerciseActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPEXERCISEACTION;
	if (pInputExerciseActionField)
	{
		CTORATstpSPInputExerciseActionField *task_data = new CTORATstpSPInputExerciseActionField();
		*task_data = *pInputExerciseActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnExerciseAction(CTORATstpSPInputExerciseActionField *pInputExerciseAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNEXERCISEACTION;
	if (pInputExerciseAction)
	{
		CTORATstpSPInputExerciseActionField *task_data = new CTORATstpSPInputExerciseActionField();
		*task_data = *pInputExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspLockInsert(CTORATstpSPInputLockField *pInputLockField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPLOCKINSERT;
	if (pInputLockField)
	{
		CTORATstpSPInputLockField *task_data = new CTORATstpSPInputLockField();
		*task_data = *pInputLockField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnLock(CTORATstpSPLockField *pLock) 
{
	Task task = Task();
	task.task_name = ONRTNLOCK;
	if (pLock)
	{
		CTORATstpSPLockField *task_data = new CTORATstpSPLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnLockInsert(CTORATstpSPInputLockField *pInputLock, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNLOCKINSERT;
	if (pInputLock)
	{
		CTORATstpSPInputLockField *task_data = new CTORATstpSPInputLockField();
		*task_data = *pInputLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspLockAction(CTORATstpSPInputLockActionField *pInputLockActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPLOCKACTION;
	if (pInputLockActionField)
	{
		CTORATstpSPInputLockActionField *task_data = new CTORATstpSPInputLockActionField();
		*task_data = *pInputLockActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnLockAction(CTORATstpSPInputLockActionField *pInputLockAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNLOCKACTION;
	if (pInputLockAction)
	{
		CTORATstpSPInputLockActionField *task_data = new CTORATstpSPInputLockActionField();
		*task_data = *pInputLockAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnStockDisposal(CTORATstpSPStockDisposalField *pStockDisposal) 
{
	Task task = Task();
	task.task_name = ONRTNSTOCKDISPOSAL;
	if (pStockDisposal)
	{
		CTORATstpSPStockDisposalField *task_data = new CTORATstpSPStockDisposalField();
		*task_data = *pStockDisposal;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnRspCombOrderInsert(CTORATstpSPInputCombOrderField *pInputCombOrderField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCOMBORDERINSERT;
	if (pInputCombOrderField)
	{
		CTORATstpSPInputCombOrderField *task_data = new CTORATstpSPInputCombOrderField();
		*task_data = *pInputCombOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnCombOrder(CTORATstpSPCombOrderField *pCombOrder) 
{
	Task task = Task();
	task.task_name = ONRTNCOMBORDER;
	if (pCombOrder)
	{
		CTORATstpSPCombOrderField *task_data = new CTORATstpSPCombOrderField();
		*task_data = *pCombOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCombOrderInsert(CTORATstpSPInputCombOrderField *pInputCombOrder, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBORDERINSERT;
	if (pInputCombOrder)
	{
		CTORATstpSPInputCombOrderField *task_data = new CTORATstpSPInputCombOrderField();
		*task_data = *pInputCombOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspCombOrderAction(CTORATstpSPInputCombOrderActionField *pInputCombOrderActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCOMBORDERACTION;
	if (pInputCombOrderActionField)
	{
		CTORATstpSPInputCombOrderActionField *task_data = new CTORATstpSPInputCombOrderActionField();
		*task_data = *pInputCombOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCombOrderAction(CTORATstpSPInputCombOrderActionField *pInputCombOrderAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBORDERACTION;
	if (pInputCombOrderAction)
	{
		CTORATstpSPInputCombOrderActionField *task_data = new CTORATstpSPInputCombOrderActionField();
		*task_data = *pInputCombOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspCondOrderInsert(CTORATstpSPInputCondOrderField *pInputCondOrderField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERINSERT;
	if (pInputCondOrderField)
	{
		CTORATstpSPInputCondOrderField *task_data = new CTORATstpSPInputCondOrderField();
		*task_data = *pInputCondOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnCondOrder(CTORATstpSPConditionOrderField *pConditionOrder) 
{
	Task task = Task();
	task.task_name = ONRTNCONDORDER;
	if (pConditionOrder)
	{
		CTORATstpSPConditionOrderField *task_data = new CTORATstpSPConditionOrderField();
		*task_data = *pConditionOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCondOrderInsert(CTORATstpSPInputCondOrderField *pInputCondOrder, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERINSERT;
	if (pInputCondOrder)
	{
		CTORATstpSPInputCondOrderField *task_data = new CTORATstpSPInputCondOrderField();
		*task_data = *pInputCondOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspCondOrderAction(CTORATstpSPInputCondOrderActionField *pInputCondOrderActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERACTION;
	if (pInputCondOrderActionField)
	{
		CTORATstpSPInputCondOrderActionField *task_data = new CTORATstpSPInputCondOrderActionField();
		*task_data = *pInputCondOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCondOrderAction(CTORATstpSPInputCondOrderActionField *pInputCondOrderAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERACTION;
	if (pInputCondOrderAction)
	{
		CTORATstpSPInputCondOrderActionField *task_data = new CTORATstpSPInputCondOrderActionField();
		*task_data = *pInputCondOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspCombExerciseInsert(CTORATstpSPInputCombExerciseField *pInputCombExerciseField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCOMBEXERCISEINSERT;
	if (pInputCombExerciseField)
	{
		CTORATstpSPInputCombExerciseField *task_data = new CTORATstpSPInputCombExerciseField();
		*task_data = *pInputCombExerciseField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnCombExercise(CTORATstpSPCombExerciseField *pCombExercise) 
{
	Task task = Task();
	task.task_name = ONRTNCOMBEXERCISE;
	if (pCombExercise)
	{
		CTORATstpSPCombExerciseField *task_data = new CTORATstpSPCombExerciseField();
		*task_data = *pCombExercise;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCombExerciseInsert(CTORATstpSPInputCombExerciseField *pInputCombExercise, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBEXERCISEINSERT;
	if (pInputCombExercise)
	{
		CTORATstpSPInputCombExerciseField *task_data = new CTORATstpSPInputCombExerciseField();
		*task_data = *pInputCombExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspCombExerciseAction(CTORATstpSPInputCombExerciseActionField *pInputCombExerciseActionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPCOMBEXERCISEACTION;
	if (pInputCombExerciseActionField)
	{
		CTORATstpSPInputCombExerciseActionField *task_data = new CTORATstpSPInputCombExerciseActionField();
		*task_data = *pInputCombExerciseActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnCombExerciseAction(CTORATstpSPInputCombExerciseActionField *pInputCombExerciseAction, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBEXERCISEACTION;
	if (pInputCombExerciseAction)
	{
		CTORATstpSPInputCombExerciseActionField *task_data = new CTORATstpSPInputCombExerciseActionField();
		*task_data = *pInputCombExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquiryMaxLockVolume(CTORATstpSPRspInquiryMaxLockVolumeField *pRspInquiryMaxLockVolumeField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMAXLOCKVOLUME;
	if (pRspInquiryMaxLockVolumeField)
	{
		CTORATstpSPRspInquiryMaxLockVolumeField *task_data = new CTORATstpSPRspInquiryMaxLockVolumeField();
		*task_data = *pRspInquiryMaxLockVolumeField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquiryMaxCoverVolume(CTORATstpSPRspInquiryMaxCoverVolumeField *pRspInquiryMaxCoverVolumeField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMAXCOVERVOLUME;
	if (pRspInquiryMaxCoverVolumeField)
	{
		CTORATstpSPRspInquiryMaxCoverVolumeField *task_data = new CTORATstpSPRspInquiryMaxCoverVolumeField();
		*task_data = *pRspInquiryMaxCoverVolumeField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquirySplitCombMarginDifference(CTORATstpSPRspInquirySplitCombMarginDifferenceField *pRspInquirySplitCombMarginDifferenceField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPLITCOMBMARGINDIFFERENCE;
	if (pRspInquirySplitCombMarginDifferenceField)
	{
		CTORATstpSPRspInquirySplitCombMarginDifferenceField *task_data = new CTORATstpSPRspInquirySplitCombMarginDifferenceField();
		*task_data = *pRspInquirySplitCombMarginDifferenceField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspTransferFund(CTORATstpSPInputTransferFundField *pInputTransferFundField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERFUND;
	if (pInputTransferFundField)
	{
		CTORATstpSPInputTransferFundField *task_data = new CTORATstpSPInputTransferFundField();
		*task_data = *pInputTransferFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnTransferFund(CTORATstpSPTransferFundField *pTransferFund) 
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERFUND;
	if (pTransferFund)
	{
		CTORATstpSPTransferFundField *task_data = new CTORATstpSPTransferFundField();
		*task_data = *pTransferFund;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnTransferFund(CTORATstpSPInputTransferFundField *pInputTransferFund, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERFUND;
	if (pInputTransferFund)
	{
		CTORATstpSPInputTransferFundField *task_data = new CTORATstpSPInputTransferFundField();
		*task_data = *pInputTransferFund;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnTransferPosition(CTORATstpSPTransferPositionField *pTransferPosition) 
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERPOSITION;
	if (pTransferPosition)
	{
		CTORATstpSPTransferPositionField *task_data = new CTORATstpSPTransferPositionField();
		*task_data = *pTransferPosition;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnTransferPosition(CTORATstpSPInputTransferPositionField *pInputTransferPosition, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERPOSITION;
	if (pInputTransferPosition)
	{
		CTORATstpSPInputTransferPositionField *task_data = new CTORATstpSPInputTransferPositionField();
		*task_data = *pInputTransferPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspTransferStockPosition(CTORATstpSPInputTransferStockPositionField *pInputTransferStockPositionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERSTOCKPOSITION;
	if (pInputTransferStockPositionField)
	{
		CTORATstpSPInputTransferStockPositionField *task_data = new CTORATstpSPInputTransferStockPositionField();
		*task_data = *pInputTransferStockPositionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnTransferStockPosition(CTORATstpSPTransferStockPositionField *pTransferStockPosition) 
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERSTOCKPOSITION;
	if (pTransferStockPosition)
	{
		CTORATstpSPTransferStockPositionField *task_data = new CTORATstpSPTransferStockPositionField();
		*task_data = *pTransferStockPosition;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnErrRtnTransferStockPosition(CTORATstpSPInputTransferStockPositionField *pInputTransferStockPosition, CTORATstpSPRspInfoField *pRspInfo,int nRequestID) 
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERSTOCKPOSITION;
	if (pInputTransferStockPosition)
	{
		CTORATstpSPInputTransferStockPositionField *task_data = new CTORATstpSPInputTransferStockPositionField();
		*task_data = *pInputTransferStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquiryJZFund(CTORATstpSPRspInquiryJZFundField *pRspInquiryJZFundField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYJZFUND;
	if (pRspInquiryJZFundField)
	{
		CTORATstpSPRspInquiryJZFundField *task_data = new CTORATstpSPRspInquiryJZFundField();
		*task_data = *pRspInquiryJZFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquiryBankAccountFund(CTORATstpSPRspInquiryBankAccountFundField *pRspInquiryBankAccountFundField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYBANKACCOUNTFUND;
	if (pRspInquiryBankAccountFundField)
	{
		CTORATstpSPRspInquiryBankAccountFundField *task_data = new CTORATstpSPRspInquiryBankAccountFundField();
		*task_data = *pRspInquiryBankAccountFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRspInquiryStockPosition(CTORATstpSPRspInquiryStockPositionField *pRspInquiryStockPositionField, CTORATstpSPRspInfoField *pRspInfo, int nRequestID) 
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSTOCKPOSITION;
	if (pRspInquiryStockPositionField)
	{
		CTORATstpSPRspInquiryStockPositionField *task_data = new CTORATstpSPRspInquiryStockPositionField();
		*task_data = *pRspInquiryStockPositionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void OptionApi::OnRtnMarketStatus(CTORATstpSPMarketStatusField *pMarketStatus) 
{
	Task task = Task();
	task.task_name = ONRTNMARKETSTATUS;
	if (pMarketStatus)
	{
		CTORATstpSPMarketStatusField *task_data = new CTORATstpSPMarketStatusField();
		*task_data = *pMarketStatus;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnRtnTradingNotice(CTORATstpSPTradingNoticeField *pTradingNotice) 
{
	Task task = Task();
	task.task_name = ONRTNTRADINGNOTICE;
	if (pTradingNotice)
	{
		CTORATstpSPTradingNoticeField *task_data = new CTORATstpSPTradingNoticeField();
		*task_data = *pTradingNotice;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void OptionApi::OnRspQryExchange(CTORATstpSPExchangeField *pExchange, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	if (pExchange)
	{
		CTORATstpSPExchangeField *task_data = new CTORATstpSPExchangeField();
		*task_data = *pExchange;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryMarketData(CTORATstpSPMarketDataField *pMarketData, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKETDATA;
	if (pMarketData)
	{
		CTORATstpSPMarketDataField *task_data = new CTORATstpSPMarketDataField();
		*task_data = *pMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQrySecurity(CTORATstpSPSecurityField *pSecurity, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSECURITY;
	if (pSecurity)
	{
		CTORATstpSPSecurityField *task_data = new CTORATstpSPSecurityField();
		*task_data = *pSecurity;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryBUProxy(CTORATstpSPBUProxyField *pBUProxy, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYBUPROXY;
	if (pBUProxy)
	{
		CTORATstpSPBUProxyField *task_data = new CTORATstpSPBUProxyField();
		*task_data = *pBUProxy;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryUser(CTORATstpSPUserField *pUser, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYUSER;
	if (pUser)
	{
		CTORATstpSPUserField *task_data = new CTORATstpSPUserField();
		*task_data = *pUser;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInvestor(CTORATstpSPInvestorField *pInvestor, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTOR;
	if (pInvestor)
	{
		CTORATstpSPInvestorField *task_data = new CTORATstpSPInvestorField();
		*task_data = *pInvestor;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryShareholderAccount(CTORATstpSPShareholderAccountField *pShareholderAccount, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSHAREHOLDERACCOUNT;
	if (pShareholderAccount)
	{
		CTORATstpSPShareholderAccountField *task_data = new CTORATstpSPShareholderAccountField();
		*task_data = *pShareholderAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryTradingAccount(CTORATstpSPTradingAccountField *pTradingAccount, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGACCOUNT;
	if (pTradingAccount)
	{
		CTORATstpSPTradingAccountField *task_data = new CTORATstpSPTradingAccountField();
		*task_data = *pTradingAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryOrder(CTORATstpSPOrderField *pOrder, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	if (pOrder)
	{
		CTORATstpSPOrderField *task_data = new CTORATstpSPOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryTrade(CTORATstpSPTradeField *pTrade, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;
	if (pTrade)
	{
		CTORATstpSPTradeField *task_data = new CTORATstpSPTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryPosition(CTORATstpSPPositionField *pPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	if (pPosition)
	{
		CTORATstpSPPositionField *task_data = new CTORATstpSPPositionField();
		*task_data = *pPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryTradingFee(CTORATstpSPTradingFeeField *pTradingFee, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGFEE;
	if (pTradingFee)
	{
		CTORATstpSPTradingFeeField *task_data = new CTORATstpSPTradingFeeField();
		*task_data = *pTradingFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInvestorTradingFee(CTORATstpSPInvestorTradingFeeField *pInvestorTradingFee, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORTRADINGFEE;
	if (pInvestorTradingFee)
	{
		CTORATstpSPInvestorTradingFeeField *task_data = new CTORATstpSPInvestorTradingFeeField();
		*task_data = *pInvestorTradingFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInvestorMarginFee(CTORATstpSPInvestorMarginFeeField *pInvestorMarginFee, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORMARGINFEE;
	if (pInvestorMarginFee)
	{
		CTORATstpSPInvestorMarginFeeField *task_data = new CTORATstpSPInvestorMarginFeeField();
		*task_data = *pInvestorMarginFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryOrderFundDetail(CTORATstpSPOrderFundDetailField *pOrderFundDetail, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERFUNDDETAIL;
	if (pOrderFundDetail)
	{
		CTORATstpSPOrderFundDetailField *task_data = new CTORATstpSPOrderFundDetailField();
		*task_data = *pOrderFundDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryFundTransferDetail(CTORATstpSPFundTransferDetailField *pFundTransferDetail, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYFUNDTRANSFERDETAIL;
	if (pFundTransferDetail)
	{
		CTORATstpSPFundTransferDetailField *task_data = new CTORATstpSPFundTransferDetailField();
		*task_data = *pFundTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryPositionTransferDetail(CTORATstpSPPositionTransferDetailField *pPositionTransferDetail, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONTRANSFERDETAIL;
	if (pPositionTransferDetail)
	{
		CTORATstpSPPositionTransferDetailField *task_data = new CTORATstpSPPositionTransferDetailField();
		*task_data = *pPositionTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryOrderAction(CTORATstpSPOrderActionField *pOrderAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERACTION;
	if (pOrderAction)
	{
		CTORATstpSPOrderActionField *task_data = new CTORATstpSPOrderActionField();
		*task_data = *pOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryStockPosition(CTORATstpSPStockPositionField *pStockPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKPOSITION;
	if (pStockPosition)
	{
		CTORATstpSPStockPositionField *task_data = new CTORATstpSPStockPositionField();
		*task_data = *pStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryLock(CTORATstpSPLockField *pLock, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCK;
	if (pLock)
	{
		CTORATstpSPLockField *task_data = new CTORATstpSPLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryExercise(CTORATstpSPExerciseField *pExercise, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISE;
	if (pExercise)
	{
		CTORATstpSPExerciseField *task_data = new CTORATstpSPExerciseField();
		*task_data = *pExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryLockPosition(CTORATstpSPLockPositionField *pLockPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKPOSITION;
	if (pLockPosition)
	{
		CTORATstpSPLockPositionField *task_data = new CTORATstpSPLockPositionField();
		*task_data = *pLockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryExerciseAction(CTORATstpSPExerciseActionField *pExerciseAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISEACTION;
	if (pExerciseAction)
	{
		CTORATstpSPExerciseActionField *task_data = new CTORATstpSPExerciseActionField();
		*task_data = *pExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryLockAction(CTORATstpSPLockActionField *pLockAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKACTION;
	if (pLockAction)
	{
		CTORATstpSPLockActionField *task_data = new CTORATstpSPLockActionField();
		*task_data = *pLockAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryStockPositionTransferDetail(CTORATstpSPStockPositionTransferDetailField *pStockPositionTransferDetail, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKPOSITIONTRANSFERDETAIL;
	if (pStockPositionTransferDetail)
	{
		CTORATstpSPStockPositionTransferDetailField *task_data = new CTORATstpSPStockPositionTransferDetailField();
		*task_data = *pStockPositionTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryTradingNotice(CTORATstpSPTradingNoticeField *pTradingNotice, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGNOTICE;
	if (pTradingNotice)
	{
		CTORATstpSPTradingNoticeField *task_data = new CTORATstpSPTradingNoticeField();
		*task_data = *pTradingNotice;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryStockDisposal(CTORATstpSPStockDisposalField *pStockDisposal, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKDISPOSAL;
	if (pStockDisposal)
	{
		CTORATstpSPStockDisposalField *task_data = new CTORATstpSPStockDisposalField();
		*task_data = *pStockDisposal;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryStockDisposalAction(CTORATstpSPStockDisposalActionField *pStockDisposalAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKDISPOSALACTION;
	if (pStockDisposalAction)
	{
		CTORATstpSPStockDisposalActionField *task_data = new CTORATstpSPStockDisposalActionField();
		*task_data = *pStockDisposalAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCondOrder(CTORATstpSPCondOrderField *pCondOrder, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDORDER;
	if (pCondOrder)
	{
		CTORATstpSPCondOrderField *task_data = new CTORATstpSPCondOrderField();
		*task_data = *pCondOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCondOrderAction(CTORATstpSPCondOrderActionField *pCondOrderAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDORDERACTION;
	if (pCondOrderAction)
	{
		CTORATstpSPCondOrderActionField *task_data = new CTORATstpSPCondOrderActionField();
		*task_data = *pCondOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInvestorLimitPosition(CTORATstpSPInvestorLimitPositionField *pInvestorLimitPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORLIMITPOSITION;
	if (pInvestorLimitPosition)
	{
		CTORATstpSPInvestorLimitPositionField *task_data = new CTORATstpSPInvestorLimitPositionField();
		*task_data = *pInvestorLimitPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInvestorLimitAmount(CTORATstpSPInvestorLimitAmountField *pInvestorLimitAmount, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORLIMITAMOUNT;
	if (pInvestorLimitAmount)
	{
		CTORATstpSPInvestorLimitAmountField *task_data = new CTORATstpSPInvestorLimitAmountField();
		*task_data = *pInvestorLimitAmount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombOrderAction(CTORATstpSPCombOrderActionField *pCombOrderAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBORDERACTION;
	if (pCombOrderAction)
	{
		CTORATstpSPCombOrderActionField *task_data = new CTORATstpSPCombOrderActionField();
		*task_data = *pCombOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombOrder(CTORATstpSPCombOrderField *pCombOrder, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBORDER;
	if (pCombOrder)
	{
		CTORATstpSPCombOrderField *task_data = new CTORATstpSPCombOrderField();
		*task_data = *pCombOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombPosition(CTORATstpSPCombPositionField *pCombPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBPOSITION;
	if (pCombPosition)
	{
		CTORATstpSPCombPositionField *task_data = new CTORATstpSPCombPositionField();
		*task_data = *pCombPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombPosDetail(CTORATstpSPCombPosDetailField *pCombPosDetail, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBPOSDETAIL;
	if (pCombPosDetail)
	{
		CTORATstpSPCombPosDetailField *task_data = new CTORATstpSPCombPosDetailField();
		*task_data = *pCombPosDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryExerciseAppointment(CTORATstpSPExerciseAppointmentField *pExerciseAppointment, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISEAPPOINTMENT;
	if (pExerciseAppointment)
	{
		CTORATstpSPExerciseAppointmentField *task_data = new CTORATstpSPExerciseAppointmentField();
		*task_data = *pExerciseAppointment;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryInsufficientCoveredStockPosition(CTORATstpSPInsufficientCoveredStockPositionField *pInsufficientCoveredStockPosition, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYINSUFFICIENTCOVEREDSTOCKPOSITION;
	if (pInsufficientCoveredStockPosition)
	{
		CTORATstpSPInsufficientCoveredStockPositionField *task_data = new CTORATstpSPInsufficientCoveredStockPositionField();
		*task_data = *pInsufficientCoveredStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombSecurity(CTORATstpSPCombSecurityField *pCombSecurity, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBSECURITY;
	if (pCombSecurity)
	{
		CTORATstpSPCombSecurityField *task_data = new CTORATstpSPCombSecurityField();
		*task_data = *pCombSecurity;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombExercise(CTORATstpSPCombExerciseField *pCombExercise, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBEXERCISE;
	if (pCombExercise)
	{
		CTORATstpSPCombExerciseField *task_data = new CTORATstpSPCombExerciseField();
		*task_data = *pCombExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void OptionApi::OnRspQryCombExerciseAction(CTORATstpSPCombExerciseActionField *pCombExerciseAction, CTORATstpSPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBEXERCISEACTION;
	if (pCombExerciseAction)
	{
		CTORATstpSPCombExerciseActionField *task_data = new CTORATstpSPCombExerciseActionField();
		*task_data = *pCombExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField *task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

