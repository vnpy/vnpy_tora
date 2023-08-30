// vntoraoption.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vntoraoption.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void ToraOptionApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void ToraOptionApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = int(nReason);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspError(CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspGetConnectionInfo(CTORATstpSPConnectionInfoField* pConnectionInfoField, CTORATstpSPRspInfoField* pRspInfoField, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPGETCONNECTIONINFO;
	if (pConnectionInfoField)
	{
		CTORATstpSPConnectionInfoField* task_data = new CTORATstpSPConnectionInfoField();
		*task_data = *pConnectionInfoField;
		task.task_data = task_data;
	}
	if (pRspInfoField)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfoField;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspUserLogin(CTORATstpSPRspUserLoginField* pRspUserLoginField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLoginField)
	{
		CTORATstpSPRspUserLoginField* task_data = new CTORATstpSPRspUserLoginField();
		*task_data = *pRspUserLoginField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspUserLogout(CTORATstpSPUserLogoutField* pUserLogoutField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogoutField)
	{
		CTORATstpSPUserLogoutField* task_data = new CTORATstpSPUserLogoutField();
		*task_data = *pUserLogoutField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspUserPasswordUpdate(CTORATstpSPUserPasswordUpdateField* pUserPasswordUpdateField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;
	if (pUserPasswordUpdateField)
	{
		CTORATstpSPUserPasswordUpdateField* task_data = new CTORATstpSPUserPasswordUpdateField();
		*task_data = *pUserPasswordUpdateField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInputDeviceSerial(CTORATstpSPRspInputDeviceSerialField* pRspInputDeviceSerialField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINPUTDEVICESERIAL;
	if (pRspInputDeviceSerialField)
	{
		CTORATstpSPRspInputDeviceSerialField* task_data = new CTORATstpSPRspInputDeviceSerialField();
		*task_data = *pRspInputDeviceSerialField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspOrderInsert(CTORATstpSPInputOrderField* pInputOrderField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;
	if (pInputOrderField)
	{
		CTORATstpSPInputOrderField* task_data = new CTORATstpSPInputOrderField();
		*task_data = *pInputOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnOrder(CTORATstpSPOrderField* pOrder)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pOrder)
	{
		CTORATstpSPOrderField* task_data = new CTORATstpSPOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnOrderInsert(CTORATstpSPInputOrderField* pInputOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNORDERINSERT;
	if (pInputOrder)
	{
		CTORATstpSPInputOrderField* task_data = new CTORATstpSPInputOrderField();
		*task_data = *pInputOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspOrderAction(CTORATstpSPInputOrderActionField* pInputOrderActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pInputOrderActionField)
	{
		CTORATstpSPInputOrderActionField* task_data = new CTORATstpSPInputOrderActionField();
		*task_data = *pInputOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnOrderAction(CTORATstpSPInputOrderActionField* pInputOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;
	if (pInputOrderAction)
	{
		CTORATstpSPInputOrderActionField* task_data = new CTORATstpSPInputOrderActionField();
		*task_data = *pInputOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnTrade(CTORATstpSPTradeField* pTrade)
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pTrade)
	{
		CTORATstpSPTradeField* task_data = new CTORATstpSPTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspExerciseInsert(CTORATstpSPInputExerciseField* pInputExerciseField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPEXERCISEINSERT;
	if (pInputExerciseField)
	{
		CTORATstpSPInputExerciseField* task_data = new CTORATstpSPInputExerciseField();
		*task_data = *pInputExerciseField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnExercise(CTORATstpSPExerciseField* pExercise)
{
	Task task = Task();
	task.task_name = ONRTNEXERCISE;
	if (pExercise)
	{
		CTORATstpSPExerciseField* task_data = new CTORATstpSPExerciseField();
		*task_data = *pExercise;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnExerciseInsert(CTORATstpSPInputExerciseField* pInputExercise, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNEXERCISEINSERT;
	if (pInputExercise)
	{
		CTORATstpSPInputExerciseField* task_data = new CTORATstpSPInputExerciseField();
		*task_data = *pInputExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspExerciseAction(CTORATstpSPInputExerciseActionField* pInputExerciseActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPEXERCISEACTION;
	if (pInputExerciseActionField)
	{
		CTORATstpSPInputExerciseActionField* task_data = new CTORATstpSPInputExerciseActionField();
		*task_data = *pInputExerciseActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnExerciseAction(CTORATstpSPInputExerciseActionField* pInputExerciseAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNEXERCISEACTION;
	if (pInputExerciseAction)
	{
		CTORATstpSPInputExerciseActionField* task_data = new CTORATstpSPInputExerciseActionField();
		*task_data = *pInputExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspLockInsert(CTORATstpSPInputLockField* pInputLockField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPLOCKINSERT;
	if (pInputLockField)
	{
		CTORATstpSPInputLockField* task_data = new CTORATstpSPInputLockField();
		*task_data = *pInputLockField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnLock(CTORATstpSPLockField* pLock)
{
	Task task = Task();
	task.task_name = ONRTNLOCK;
	if (pLock)
	{
		CTORATstpSPLockField* task_data = new CTORATstpSPLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnLockInsert(CTORATstpSPInputLockField* pInputLock, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNLOCKINSERT;
	if (pInputLock)
	{
		CTORATstpSPInputLockField* task_data = new CTORATstpSPInputLockField();
		*task_data = *pInputLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspLockAction(CTORATstpSPInputLockActionField* pInputLockActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPLOCKACTION;
	if (pInputLockActionField)
	{
		CTORATstpSPInputLockActionField* task_data = new CTORATstpSPInputLockActionField();
		*task_data = *pInputLockActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnLockAction(CTORATstpSPInputLockActionField* pInputLockAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNLOCKACTION;
	if (pInputLockAction)
	{
		CTORATstpSPInputLockActionField* task_data = new CTORATstpSPInputLockActionField();
		*task_data = *pInputLockAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnStockDisposal(CTORATstpSPStockDisposalField* pStockDisposal)
{
	Task task = Task();
	task.task_name = ONRTNSTOCKDISPOSAL;
	if (pStockDisposal)
	{
		CTORATstpSPStockDisposalField* task_data = new CTORATstpSPStockDisposalField();
		*task_data = *pStockDisposal;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCombOrderInsert(CTORATstpSPInputCombOrderField* pInputCombOrderField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCOMBORDERINSERT;
	if (pInputCombOrderField)
	{
		CTORATstpSPInputCombOrderField* task_data = new CTORATstpSPInputCombOrderField();
		*task_data = *pInputCombOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnCombOrder(CTORATstpSPCombOrderField* pCombOrder)
{
	Task task = Task();
	task.task_name = ONRTNCOMBORDER;
	if (pCombOrder)
	{
		CTORATstpSPCombOrderField* task_data = new CTORATstpSPCombOrderField();
		*task_data = *pCombOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCombOrderInsert(CTORATstpSPInputCombOrderField* pInputCombOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBORDERINSERT;
	if (pInputCombOrder)
	{
		CTORATstpSPInputCombOrderField* task_data = new CTORATstpSPInputCombOrderField();
		*task_data = *pInputCombOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCombOrderAction(CTORATstpSPInputCombOrderActionField* pInputCombOrderActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCOMBORDERACTION;
	if (pInputCombOrderActionField)
	{
		CTORATstpSPInputCombOrderActionField* task_data = new CTORATstpSPInputCombOrderActionField();
		*task_data = *pInputCombOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCombOrderAction(CTORATstpSPInputCombOrderActionField* pInputCombOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBORDERACTION;
	if (pInputCombOrderAction)
	{
		CTORATstpSPInputCombOrderActionField* task_data = new CTORATstpSPInputCombOrderActionField();
		*task_data = *pInputCombOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCondOrderInsert(CTORATstpSPInputCondOrderField* pInputCondOrderField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERINSERT;
	if (pInputCondOrderField)
	{
		CTORATstpSPInputCondOrderField* task_data = new CTORATstpSPInputCondOrderField();
		*task_data = *pInputCondOrderField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnCondOrder(CTORATstpSPConditionOrderField* pConditionOrder)
{
	Task task = Task();
	task.task_name = ONRTNCONDORDER;
	if (pConditionOrder)
	{
		CTORATstpSPConditionOrderField* task_data = new CTORATstpSPConditionOrderField();
		*task_data = *pConditionOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCondOrderInsert(CTORATstpSPInputCondOrderField* pInputCondOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERINSERT;
	if (pInputCondOrder)
	{
		CTORATstpSPInputCondOrderField* task_data = new CTORATstpSPInputCondOrderField();
		*task_data = *pInputCondOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCondOrderAction(CTORATstpSPInputCondOrderActionField* pInputCondOrderActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCONDORDERACTION;
	if (pInputCondOrderActionField)
	{
		CTORATstpSPInputCondOrderActionField* task_data = new CTORATstpSPInputCondOrderActionField();
		*task_data = *pInputCondOrderActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCondOrderAction(CTORATstpSPInputCondOrderActionField* pInputCondOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCONDORDERACTION;
	if (pInputCondOrderAction)
	{
		CTORATstpSPInputCondOrderActionField* task_data = new CTORATstpSPInputCondOrderActionField();
		*task_data = *pInputCondOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCombExerciseInsert(CTORATstpSPInputCombExerciseField* pInputCombExerciseField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCOMBEXERCISEINSERT;
	if (pInputCombExerciseField)
	{
		CTORATstpSPInputCombExerciseField* task_data = new CTORATstpSPInputCombExerciseField();
		*task_data = *pInputCombExerciseField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnCombExercise(CTORATstpSPCombExerciseField* pCombExercise)
{
	Task task = Task();
	task.task_name = ONRTNCOMBEXERCISE;
	if (pCombExercise)
	{
		CTORATstpSPCombExerciseField* task_data = new CTORATstpSPCombExerciseField();
		*task_data = *pCombExercise;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCombExerciseInsert(CTORATstpSPInputCombExerciseField* pInputCombExercise, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBEXERCISEINSERT;
	if (pInputCombExercise)
	{
		CTORATstpSPInputCombExerciseField* task_data = new CTORATstpSPInputCombExerciseField();
		*task_data = *pInputCombExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspCombExerciseAction(CTORATstpSPInputCombExerciseActionField* pInputCombExerciseActionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPCOMBEXERCISEACTION;
	if (pInputCombExerciseActionField)
	{
		CTORATstpSPInputCombExerciseActionField* task_data = new CTORATstpSPInputCombExerciseActionField();
		*task_data = *pInputCombExerciseActionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnCombExerciseAction(CTORATstpSPInputCombExerciseActionField* pInputCombExerciseAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNCOMBEXERCISEACTION;
	if (pInputCombExerciseAction)
	{
		CTORATstpSPInputCombExerciseActionField* task_data = new CTORATstpSPInputCombExerciseActionField();
		*task_data = *pInputCombExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquiryMaxLockVolume(CTORATstpSPRspInquiryMaxLockVolumeField* pRspInquiryMaxLockVolumeField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMAXLOCKVOLUME;
	if (pRspInquiryMaxLockVolumeField)
	{
		CTORATstpSPRspInquiryMaxLockVolumeField* task_data = new CTORATstpSPRspInquiryMaxLockVolumeField();
		*task_data = *pRspInquiryMaxLockVolumeField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquiryMaxCoverVolume(CTORATstpSPRspInquiryMaxCoverVolumeField* pRspInquiryMaxCoverVolumeField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYMAXCOVERVOLUME;
	if (pRspInquiryMaxCoverVolumeField)
	{
		CTORATstpSPRspInquiryMaxCoverVolumeField* task_data = new CTORATstpSPRspInquiryMaxCoverVolumeField();
		*task_data = *pRspInquiryMaxCoverVolumeField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquirySplitCombMarginDifference(CTORATstpSPRspInquirySplitCombMarginDifferenceField* pRspInquirySplitCombMarginDifferenceField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSPLITCOMBMARGINDIFFERENCE;
	if (pRspInquirySplitCombMarginDifferenceField)
	{
		CTORATstpSPRspInquirySplitCombMarginDifferenceField* task_data = new CTORATstpSPRspInquirySplitCombMarginDifferenceField();
		*task_data = *pRspInquirySplitCombMarginDifferenceField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspTransferFund(CTORATstpSPInputTransferFundField* pInputTransferFundField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERFUND;
	if (pInputTransferFundField)
	{
		CTORATstpSPInputTransferFundField* task_data = new CTORATstpSPInputTransferFundField();
		*task_data = *pInputTransferFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnTransferFund(CTORATstpSPTransferFundField* pTransferFund)
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERFUND;
	if (pTransferFund)
	{
		CTORATstpSPTransferFundField* task_data = new CTORATstpSPTransferFundField();
		*task_data = *pTransferFund;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnTransferFund(CTORATstpSPInputTransferFundField* pInputTransferFund, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERFUND;
	if (pInputTransferFund)
	{
		CTORATstpSPInputTransferFundField* task_data = new CTORATstpSPInputTransferFundField();
		*task_data = *pInputTransferFund;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnTransferPosition(CTORATstpSPTransferPositionField* pTransferPosition)
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERPOSITION;
	if (pTransferPosition)
	{
		CTORATstpSPTransferPositionField* task_data = new CTORATstpSPTransferPositionField();
		*task_data = *pTransferPosition;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnTransferPosition(CTORATstpSPInputTransferPositionField* pInputTransferPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERPOSITION;
	if (pInputTransferPosition)
	{
		CTORATstpSPInputTransferPositionField* task_data = new CTORATstpSPInputTransferPositionField();
		*task_data = *pInputTransferPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspTransferStockPosition(CTORATstpSPInputTransferStockPositionField* pInputTransferStockPositionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERSTOCKPOSITION;
	if (pInputTransferStockPositionField)
	{
		CTORATstpSPInputTransferStockPositionField* task_data = new CTORATstpSPInputTransferStockPositionField();
		*task_data = *pInputTransferStockPositionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnTransferStockPosition(CTORATstpSPTransferStockPositionField* pTransferStockPosition)
{
	Task task = Task();
	task.task_name = ONRTNTRANSFERSTOCKPOSITION;
	if (pTransferStockPosition)
	{
		CTORATstpSPTransferStockPositionField* task_data = new CTORATstpSPTransferStockPositionField();
		*task_data = *pTransferStockPosition;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnErrRtnTransferStockPosition(CTORATstpSPInputTransferStockPositionField* pInputTransferStockPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONERRRTNTRANSFERSTOCKPOSITION;
	if (pInputTransferStockPosition)
	{
		CTORATstpSPInputTransferStockPositionField* task_data = new CTORATstpSPInputTransferStockPositionField();
		*task_data = *pInputTransferStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquiryJZFund(CTORATstpSPRspInquiryJZFundField* pRspInquiryJZFundField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYJZFUND;
	if (pRspInquiryJZFundField)
	{
		CTORATstpSPRspInquiryJZFundField* task_data = new CTORATstpSPRspInquiryJZFundField();
		*task_data = *pRspInquiryJZFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquiryBankAccountFund(CTORATstpSPRspInquiryBankAccountFundField* pRspInquiryBankAccountFundField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYBANKACCOUNTFUND;
	if (pRspInquiryBankAccountFundField)
	{
		CTORATstpSPRspInquiryBankAccountFundField* task_data = new CTORATstpSPRspInquiryBankAccountFundField();
		*task_data = *pRspInquiryBankAccountFundField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspInquiryStockPosition(CTORATstpSPRspInquiryStockPositionField* pRspInquiryStockPositionField, CTORATstpSPRspInfoField* pRspInfo, int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPINQUIRYSTOCKPOSITION;
	if (pRspInquiryStockPositionField)
	{
		CTORATstpSPRspInquiryStockPositionField* task_data = new CTORATstpSPRspInquiryStockPositionField();
		*task_data = *pRspInquiryStockPositionField;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnMarketStatus(CTORATstpSPMarketStatusField* pMarketStatus)
{
	Task task = Task();
	task.task_name = ONRTNMARKETSTATUS;
	if (pMarketStatus)
	{
		CTORATstpSPMarketStatusField* task_data = new CTORATstpSPMarketStatusField();
		*task_data = *pMarketStatus;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnRtnTradingNotice(CTORATstpSPTradingNoticeField* pTradingNotice)
{
	Task task = Task();
	task.task_name = ONRTNTRADINGNOTICE;
	if (pTradingNotice)
	{
		CTORATstpSPTradingNoticeField* task_data = new CTORATstpSPTradingNoticeField();
		*task_data = *pTradingNotice;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryExchange(CTORATstpSPExchangeField* pExchange, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	if (pExchange)
	{
		CTORATstpSPExchangeField* task_data = new CTORATstpSPExchangeField();
		*task_data = *pExchange;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryMarketData(CTORATstpSPMarketDataField* pMarketData, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYMARKETDATA;
	if (pMarketData)
	{
		CTORATstpSPMarketDataField* task_data = new CTORATstpSPMarketDataField();
		*task_data = *pMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQrySecurity(CTORATstpSPSecurityField* pSecurity, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSECURITY;
	if (pSecurity)
	{
		CTORATstpSPSecurityField* task_data = new CTORATstpSPSecurityField();
		*task_data = *pSecurity;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryBUProxy(CTORATstpSPBUProxyField* pBUProxy, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYBUPROXY;
	if (pBUProxy)
	{
		CTORATstpSPBUProxyField* task_data = new CTORATstpSPBUProxyField();
		*task_data = *pBUProxy;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryUser(CTORATstpSPUserField* pUser, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYUSER;
	if (pUser)
	{
		CTORATstpSPUserField* task_data = new CTORATstpSPUserField();
		*task_data = *pUser;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInvestor(CTORATstpSPInvestorField* pInvestor, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTOR;
	if (pInvestor)
	{
		CTORATstpSPInvestorField* task_data = new CTORATstpSPInvestorField();
		*task_data = *pInvestor;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryShareholderAccount(CTORATstpSPShareholderAccountField* pShareholderAccount, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSHAREHOLDERACCOUNT;
	if (pShareholderAccount)
	{
		CTORATstpSPShareholderAccountField* task_data = new CTORATstpSPShareholderAccountField();
		*task_data = *pShareholderAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryTradingAccount(CTORATstpSPTradingAccountField* pTradingAccount, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGACCOUNT;
	if (pTradingAccount)
	{
		CTORATstpSPTradingAccountField* task_data = new CTORATstpSPTradingAccountField();
		*task_data = *pTradingAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryOrder(CTORATstpSPOrderField* pOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	if (pOrder)
	{
		CTORATstpSPOrderField* task_data = new CTORATstpSPOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryTrade(CTORATstpSPTradeField* pTrade, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;
	if (pTrade)
	{
		CTORATstpSPTradeField* task_data = new CTORATstpSPTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryPosition(CTORATstpSPPositionField* pPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	if (pPosition)
	{
		CTORATstpSPPositionField* task_data = new CTORATstpSPPositionField();
		*task_data = *pPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryTradingFee(CTORATstpSPTradingFeeField* pTradingFee, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGFEE;
	if (pTradingFee)
	{
		CTORATstpSPTradingFeeField* task_data = new CTORATstpSPTradingFeeField();
		*task_data = *pTradingFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInvestorTradingFee(CTORATstpSPInvestorTradingFeeField* pInvestorTradingFee, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORTRADINGFEE;
	if (pInvestorTradingFee)
	{
		CTORATstpSPInvestorTradingFeeField* task_data = new CTORATstpSPInvestorTradingFeeField();
		*task_data = *pInvestorTradingFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInvestorMarginFee(CTORATstpSPInvestorMarginFeeField* pInvestorMarginFee, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORMARGINFEE;
	if (pInvestorMarginFee)
	{
		CTORATstpSPInvestorMarginFeeField* task_data = new CTORATstpSPInvestorMarginFeeField();
		*task_data = *pInvestorMarginFee;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryOrderFundDetail(CTORATstpSPOrderFundDetailField* pOrderFundDetail, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERFUNDDETAIL;
	if (pOrderFundDetail)
	{
		CTORATstpSPOrderFundDetailField* task_data = new CTORATstpSPOrderFundDetailField();
		*task_data = *pOrderFundDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryFundTransferDetail(CTORATstpSPFundTransferDetailField* pFundTransferDetail, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUNDTRANSFERDETAIL;
	if (pFundTransferDetail)
	{
		CTORATstpSPFundTransferDetailField* task_data = new CTORATstpSPFundTransferDetailField();
		*task_data = *pFundTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryPositionTransferDetail(CTORATstpSPPositionTransferDetailField* pPositionTransferDetail, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONTRANSFERDETAIL;
	if (pPositionTransferDetail)
	{
		CTORATstpSPPositionTransferDetailField* task_data = new CTORATstpSPPositionTransferDetailField();
		*task_data = *pPositionTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryOrderAction(CTORATstpSPOrderActionField* pOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERACTION;
	if (pOrderAction)
	{
		CTORATstpSPOrderActionField* task_data = new CTORATstpSPOrderActionField();
		*task_data = *pOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryStockPosition(CTORATstpSPStockPositionField* pStockPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKPOSITION;
	if (pStockPosition)
	{
		CTORATstpSPStockPositionField* task_data = new CTORATstpSPStockPositionField();
		*task_data = *pStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryLock(CTORATstpSPLockField* pLock, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCK;
	if (pLock)
	{
		CTORATstpSPLockField* task_data = new CTORATstpSPLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryExercise(CTORATstpSPExerciseField* pExercise, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISE;
	if (pExercise)
	{
		CTORATstpSPExerciseField* task_data = new CTORATstpSPExerciseField();
		*task_data = *pExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryLockPosition(CTORATstpSPLockPositionField* pLockPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKPOSITION;
	if (pLockPosition)
	{
		CTORATstpSPLockPositionField* task_data = new CTORATstpSPLockPositionField();
		*task_data = *pLockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryExerciseAction(CTORATstpSPExerciseActionField* pExerciseAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISEACTION;
	if (pExerciseAction)
	{
		CTORATstpSPExerciseActionField* task_data = new CTORATstpSPExerciseActionField();
		*task_data = *pExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryLockAction(CTORATstpSPLockActionField* pLockAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKACTION;
	if (pLockAction)
	{
		CTORATstpSPLockActionField* task_data = new CTORATstpSPLockActionField();
		*task_data = *pLockAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryStockPositionTransferDetail(CTORATstpSPStockPositionTransferDetailField* pStockPositionTransferDetail, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKPOSITIONTRANSFERDETAIL;
	if (pStockPositionTransferDetail)
	{
		CTORATstpSPStockPositionTransferDetailField* task_data = new CTORATstpSPStockPositionTransferDetailField();
		*task_data = *pStockPositionTransferDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryTradingNotice(CTORATstpSPTradingNoticeField* pTradingNotice, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGNOTICE;
	if (pTradingNotice)
	{
		CTORATstpSPTradingNoticeField* task_data = new CTORATstpSPTradingNoticeField();
		*task_data = *pTradingNotice;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryStockDisposal(CTORATstpSPStockDisposalField* pStockDisposal, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKDISPOSAL;
	if (pStockDisposal)
	{
		CTORATstpSPStockDisposalField* task_data = new CTORATstpSPStockDisposalField();
		*task_data = *pStockDisposal;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryStockDisposalAction(CTORATstpSPStockDisposalActionField* pStockDisposalAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKDISPOSALACTION;
	if (pStockDisposalAction)
	{
		CTORATstpSPStockDisposalActionField* task_data = new CTORATstpSPStockDisposalActionField();
		*task_data = *pStockDisposalAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCondOrder(CTORATstpSPCondOrderField* pCondOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDORDER;
	if (pCondOrder)
	{
		CTORATstpSPCondOrderField* task_data = new CTORATstpSPCondOrderField();
		*task_data = *pCondOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCondOrderAction(CTORATstpSPCondOrderActionField* pCondOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONDORDERACTION;
	if (pCondOrderAction)
	{
		CTORATstpSPCondOrderActionField* task_data = new CTORATstpSPCondOrderActionField();
		*task_data = *pCondOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInvestorLimitPosition(CTORATstpSPInvestorLimitPositionField* pInvestorLimitPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORLIMITPOSITION;
	if (pInvestorLimitPosition)
	{
		CTORATstpSPInvestorLimitPositionField* task_data = new CTORATstpSPInvestorLimitPositionField();
		*task_data = *pInvestorLimitPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInvestorLimitAmount(CTORATstpSPInvestorLimitAmountField* pInvestorLimitAmount, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORLIMITAMOUNT;
	if (pInvestorLimitAmount)
	{
		CTORATstpSPInvestorLimitAmountField* task_data = new CTORATstpSPInvestorLimitAmountField();
		*task_data = *pInvestorLimitAmount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombOrderAction(CTORATstpSPCombOrderActionField* pCombOrderAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBORDERACTION;
	if (pCombOrderAction)
	{
		CTORATstpSPCombOrderActionField* task_data = new CTORATstpSPCombOrderActionField();
		*task_data = *pCombOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombOrder(CTORATstpSPCombOrderField* pCombOrder, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBORDER;
	if (pCombOrder)
	{
		CTORATstpSPCombOrderField* task_data = new CTORATstpSPCombOrderField();
		*task_data = *pCombOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombPosition(CTORATstpSPCombPositionField* pCombPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBPOSITION;
	if (pCombPosition)
	{
		CTORATstpSPCombPositionField* task_data = new CTORATstpSPCombPositionField();
		*task_data = *pCombPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombPosDetail(CTORATstpSPCombPosDetailField* pCombPosDetail, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBPOSDETAIL;
	if (pCombPosDetail)
	{
		CTORATstpSPCombPosDetailField* task_data = new CTORATstpSPCombPosDetailField();
		*task_data = *pCombPosDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryExerciseAppointment(CTORATstpSPExerciseAppointmentField* pExerciseAppointment, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISEAPPOINTMENT;
	if (pExerciseAppointment)
	{
		CTORATstpSPExerciseAppointmentField* task_data = new CTORATstpSPExerciseAppointmentField();
		*task_data = *pExerciseAppointment;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryInsufficientCoveredStockPosition(CTORATstpSPInsufficientCoveredStockPositionField* pInsufficientCoveredStockPosition, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINSUFFICIENTCOVEREDSTOCKPOSITION;
	if (pInsufficientCoveredStockPosition)
	{
		CTORATstpSPInsufficientCoveredStockPositionField* task_data = new CTORATstpSPInsufficientCoveredStockPositionField();
		*task_data = *pInsufficientCoveredStockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombSecurity(CTORATstpSPCombSecurityField* pCombSecurity, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBSECURITY;
	if (pCombSecurity)
	{
		CTORATstpSPCombSecurityField* task_data = new CTORATstpSPCombSecurityField();
		*task_data = *pCombSecurity;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombExercise(CTORATstpSPCombExerciseField* pCombExercise, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBEXERCISE;
	if (pCombExercise)
	{
		CTORATstpSPCombExerciseField* task_data = new CTORATstpSPCombExerciseField();
		*task_data = *pCombExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void ToraOptionApi::OnRspQryCombExerciseAction(CTORATstpSPCombExerciseActionField* pCombExerciseAction, CTORATstpSPRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBEXERCISEACTION;
	if (pCombExerciseAction)
	{
		CTORATstpSPCombExerciseActionField* task_data = new CTORATstpSPCombExerciseActionField();
		*task_data = *pCombExerciseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTORATstpSPRspInfoField* task_error = new CTORATstpSPRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = int(nRequestID);
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void ToraOptionApi::processTask()
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

			case ONRTNTRADE:
			{
				this->processRtnTrade(&task);
				break;
			}

			case ONRSPEXERCISEINSERT:
			{
				this->processRspExerciseInsert(&task);
				break;
			}

			case ONRTNEXERCISE:
			{
				this->processRtnExercise(&task);
				break;
			}

			case ONERRRTNEXERCISEINSERT:
			{
				this->processErrRtnExerciseInsert(&task);
				break;
			}

			case ONRSPEXERCISEACTION:
			{
				this->processRspExerciseAction(&task);
				break;
			}

			case ONERRRTNEXERCISEACTION:
			{
				this->processErrRtnExerciseAction(&task);
				break;
			}

			case ONRSPLOCKINSERT:
			{
				this->processRspLockInsert(&task);
				break;
			}

			case ONRTNLOCK:
			{
				this->processRtnLock(&task);
				break;
			}

			case ONERRRTNLOCKINSERT:
			{
				this->processErrRtnLockInsert(&task);
				break;
			}

			case ONRSPLOCKACTION:
			{
				this->processRspLockAction(&task);
				break;
			}

			case ONERRRTNLOCKACTION:
			{
				this->processErrRtnLockAction(&task);
				break;
			}

			case ONRTNSTOCKDISPOSAL:
			{
				this->processRtnStockDisposal(&task);
				break;
			}

			case ONRSPCOMBORDERINSERT:
			{
				this->processRspCombOrderInsert(&task);
				break;
			}

			case ONRTNCOMBORDER:
			{
				this->processRtnCombOrder(&task);
				break;
			}

			case ONERRRTNCOMBORDERINSERT:
			{
				this->processErrRtnCombOrderInsert(&task);
				break;
			}

			case ONRSPCOMBORDERACTION:
			{
				this->processRspCombOrderAction(&task);
				break;
			}

			case ONERRRTNCOMBORDERACTION:
			{
				this->processErrRtnCombOrderAction(&task);
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

			case ONRSPCOMBEXERCISEINSERT:
			{
				this->processRspCombExerciseInsert(&task);
				break;
			}

			case ONRTNCOMBEXERCISE:
			{
				this->processRtnCombExercise(&task);
				break;
			}

			case ONERRRTNCOMBEXERCISEINSERT:
			{
				this->processErrRtnCombExerciseInsert(&task);
				break;
			}

			case ONRSPCOMBEXERCISEACTION:
			{
				this->processRspCombExerciseAction(&task);
				break;
			}

			case ONERRRTNCOMBEXERCISEACTION:
			{
				this->processErrRtnCombExerciseAction(&task);
				break;
			}

			case ONRSPINQUIRYMAXLOCKVOLUME:
			{
				this->processRspInquiryMaxLockVolume(&task);
				break;
			}

			case ONRSPINQUIRYMAXCOVERVOLUME:
			{
				this->processRspInquiryMaxCoverVolume(&task);
				break;
			}

			case ONRSPINQUIRYSPLITCOMBMARGINDIFFERENCE:
			{
				this->processRspInquirySplitCombMarginDifference(&task);
				break;
			}

			case ONRSPTRANSFERFUND:
			{
				this->processRspTransferFund(&task);
				break;
			}

			case ONRTNTRANSFERFUND:
			{
				this->processRtnTransferFund(&task);
				break;
			}

			case ONERRRTNTRANSFERFUND:
			{
				this->processErrRtnTransferFund(&task);
				break;
			}

			case ONRTNTRANSFERPOSITION:
			{
				this->processRtnTransferPosition(&task);
				break;
			}

			case ONERRRTNTRANSFERPOSITION:
			{
				this->processErrRtnTransferPosition(&task);
				break;
			}

			case ONRSPTRANSFERSTOCKPOSITION:
			{
				this->processRspTransferStockPosition(&task);
				break;
			}

			case ONRTNTRANSFERSTOCKPOSITION:
			{
				this->processRtnTransferStockPosition(&task);
				break;
			}

			case ONERRRTNTRANSFERSTOCKPOSITION:
			{
				this->processErrRtnTransferStockPosition(&task);
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

			case ONRSPINQUIRYSTOCKPOSITION:
			{
				this->processRspInquiryStockPosition(&task);
				break;
			}

			case ONRTNMARKETSTATUS:
			{
				this->processRtnMarketStatus(&task);
				break;
			}

			case ONRTNTRADINGNOTICE:
			{
				this->processRtnTradingNotice(&task);
				break;
			}

			case ONRSPQRYEXCHANGE:
			{
				this->processRspQryExchange(&task);
				break;
			}

			case ONRSPQRYMARKETDATA:
			{
				this->processRspQryMarketData(&task);
				break;
			}

			case ONRSPQRYSECURITY:
			{
				this->processRspQrySecurity(&task);
				break;
			}

			case ONRSPQRYBUPROXY:
			{
				this->processRspQryBUProxy(&task);
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

			case ONRSPQRYTRADINGACCOUNT:
			{
				this->processRspQryTradingAccount(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYTRADE:
			{
				this->processRspQryTrade(&task);
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

			case ONRSPQRYINVESTORMARGINFEE:
			{
				this->processRspQryInvestorMarginFee(&task);
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

			case ONRSPQRYORDERACTION:
			{
				this->processRspQryOrderAction(&task);
				break;
			}

			case ONRSPQRYSTOCKPOSITION:
			{
				this->processRspQryStockPosition(&task);
				break;
			}

			case ONRSPQRYLOCK:
			{
				this->processRspQryLock(&task);
				break;
			}

			case ONRSPQRYEXERCISE:
			{
				this->processRspQryExercise(&task);
				break;
			}

			case ONRSPQRYLOCKPOSITION:
			{
				this->processRspQryLockPosition(&task);
				break;
			}

			case ONRSPQRYEXERCISEACTION:
			{
				this->processRspQryExerciseAction(&task);
				break;
			}

			case ONRSPQRYLOCKACTION:
			{
				this->processRspQryLockAction(&task);
				break;
			}

			case ONRSPQRYSTOCKPOSITIONTRANSFERDETAIL:
			{
				this->processRspQryStockPositionTransferDetail(&task);
				break;
			}

			case ONRSPQRYTRADINGNOTICE:
			{
				this->processRspQryTradingNotice(&task);
				break;
			}

			case ONRSPQRYSTOCKDISPOSAL:
			{
				this->processRspQryStockDisposal(&task);
				break;
			}

			case ONRSPQRYSTOCKDISPOSALACTION:
			{
				this->processRspQryStockDisposalAction(&task);
				break;
			}

			case ONRSPQRYCONDORDER:
			{
				this->processRspQryCondOrder(&task);
				break;
			}

			case ONRSPQRYCONDORDERACTION:
			{
				this->processRspQryCondOrderAction(&task);
				break;
			}

			case ONRSPQRYINVESTORLIMITPOSITION:
			{
				this->processRspQryInvestorLimitPosition(&task);
				break;
			}

			case ONRSPQRYINVESTORLIMITAMOUNT:
			{
				this->processRspQryInvestorLimitAmount(&task);
				break;
			}

			case ONRSPQRYCOMBORDERACTION:
			{
				this->processRspQryCombOrderAction(&task);
				break;
			}

			case ONRSPQRYCOMBORDER:
			{
				this->processRspQryCombOrder(&task);
				break;
			}

			case ONRSPQRYCOMBPOSITION:
			{
				this->processRspQryCombPosition(&task);
				break;
			}

			case ONRSPQRYCOMBPOSDETAIL:
			{
				this->processRspQryCombPosDetail(&task);
				break;
			}

			case ONRSPQRYEXERCISEAPPOINTMENT:
			{
				this->processRspQryExerciseAppointment(&task);
				break;
			}

			case ONRSPQRYINSUFFICIENTCOVEREDSTOCKPOSITION:
			{
				this->processRspQryInsufficientCoveredStockPosition(&task);
				break;
			}

			case ONRSPQRYCOMBSECURITY:
			{
				this->processRspQryCombSecurity(&task);
				break;
			}

			case ONRSPQRYCOMBEXERCISE:
			{
				this->processRspQryCombExercise(&task);
				break;
			}

			case ONRSPQRYCOMBEXERCISEACTION:
			{
				this->processRspQryCombExerciseAction(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void ToraOptionApi::processFrontConnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void ToraOptionApi::processFrontDisconnected(Task* task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void ToraOptionApi::processRspError(Task* task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspGetConnectionInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPConnectionInfoField* task_data = (CTORATstpSPConnectionInfoField*)task->task_data;
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
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGetConnectionInfo(data, error, task->task_id);
};

void ToraOptionApi::processRspUserLogin(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspUserLoginField* task_data = (CTORATstpSPRspUserLoginField*)task->task_data;
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["LogInAccount"] = toUtf(task_data->LogInAccount);
		data["LogInAccountType"] = task_data->LogInAccountType;
		data["SystemName"] = toUtf(task_data->SystemName);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["MaxOrderRef"] = task_data->MaxOrderRef;
		data["PrivateFlowCount"] = task_data->PrivateFlowCount;
		data["PublicFlowCount"] = task_data->PublicFlowCount;
		data["RequestID"] = task_data->RequestID;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["UserID"] = toUtf(task_data->UserID);
		data["UserName"] = toUtf(task_data->UserName);
		data["UserType"] = task_data->UserType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OrderInsertCommFlux"] = task_data->OrderInsertCommFlux;
		data["OrderActionCommFlux"] = task_data->OrderActionCommFlux;
		data["Mobile"] = toUtf(task_data->Mobile);
		data["PasswordUpdatePeriod"] = task_data->PasswordUpdatePeriod;
		data["PasswordRemainDays"] = task_data->PasswordRemainDays;
		data["NeedUpdatePassword"] = task_data->NeedUpdatePassword;
		data["SSEOrderInsertCommFlux"] = task_data->SSEOrderInsertCommFlux;
		data["SSEOrderActionCommFlux"] = task_data->SSEOrderActionCommFlux;
		data["SZSEOrderInsertCommFlux"] = task_data->SZSEOrderInsertCommFlux;
		data["SZSEOrderActionCommFlux"] = task_data->SZSEOrderActionCommFlux;
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		data["CertSerial"] = toUtf(task_data->CertSerial);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id);
};

void ToraOptionApi::processRspUserLogout(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserLogoutField* task_data = (CTORATstpSPUserLogoutField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id);
};

void ToraOptionApi::processRspUserPasswordUpdate(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserPasswordUpdateField* task_data = (CTORATstpSPUserPasswordUpdateField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id);
};

void ToraOptionApi::processRspInputDeviceSerial(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInputDeviceSerialField* task_data = (CTORATstpSPRspInputDeviceSerialField*)task->task_data;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputDeviceSerial(data, error, task->task_id);
};

void ToraOptionApi::processRspOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderField* task_data = (CTORATstpSPInputOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["OrderRef"] = task_data->OrderRef;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["UserForceClose"] = task_data->UserForceClose;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["CondCheck"] = task_data->CondCheck;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderField* task_data = (CTORATstpSPOrderField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["Price"] = task_data->Price;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OrderOperateStatus"] = task_data->OrderOperateStatus;
		data["OrderStatus"] = task_data->OrderStatus;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["UserForceClose"] = task_data->UserForceClose;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		data["TradeAmount"] = task_data->TradeAmount;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void ToraOptionApi::processErrRtnOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderField* task_data = (CTORATstpSPInputOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["OrderRef"] = task_data->OrderRef;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["UserForceClose"] = task_data->UserForceClose;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["CondCheck"] = task_data->CondCheck;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderActionField* task_data = (CTORATstpSPInputOrderActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = task_data->OrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelOrderLocalID"] = toUtf(task_data->CancelOrderLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderActionField* task_data = (CTORATstpSPInputOrderActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = task_data->OrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelOrderLocalID"] = toUtf(task_data->CancelOrderLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processRtnTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradeField* task_data = (CTORATstpSPTradeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["OrderRef"] = task_data->OrderRef;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	this->onRtnTrade(data);
};

void ToraOptionApi::processRspExerciseInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseField* task_data = (CTORATstpSPInputExerciseField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["Volume"] = task_data->Volume;
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExerciseType"] = task_data->ExerciseType;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExerciseInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnExercise(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseField* task_data = (CTORATstpSPExerciseField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["ExerciseLocalID"] = toUtf(task_data->ExerciseLocalID);
		data["ExerciseType"] = task_data->ExerciseType;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExerciseStatus"] = task_data->ExerciseStatus;
		data["ExerciseOperateStatus"] = task_data->ExerciseOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["StockPositionExerciseSerial"] = task_data->StockPositionExerciseSerial;
		data["StockPositionSerial"] = task_data->StockPositionSerial;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnExercise(data);
};

void ToraOptionApi::processErrRtnExerciseInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseField* task_data = (CTORATstpSPInputExerciseField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["Volume"] = task_data->Volume;
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExerciseType"] = task_data->ExerciseType;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExerciseInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseActionField* task_data = (CTORATstpSPInputExerciseActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExerciseActionRef"] = task_data->ExerciseActionRef;
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelExerciseLocalID"] = toUtf(task_data->CancelExerciseLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExerciseAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseActionField* task_data = (CTORATstpSPInputExerciseActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExerciseActionRef"] = task_data->ExerciseActionRef;
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelExerciseLocalID"] = toUtf(task_data->CancelExerciseLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExerciseAction(data, error, task->task_id);
};

void ToraOptionApi::processRspLockInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockField* task_data = (CTORATstpSPInputLockField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["LockRef"] = task_data->LockRef;
		data["LockType"] = task_data->LockType;
		data["Volume"] = task_data->Volume;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLockInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnLock(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockField* task_data = (CTORATstpSPLockField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["LockRef"] = task_data->LockRef;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["LockLocalID"] = toUtf(task_data->LockLocalID);
		data["LockType"] = task_data->LockType;
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["LockStatus"] = task_data->LockStatus;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ErrorID"] = task_data->ErrorID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["StockPositionLockSerial"] = task_data->StockPositionLockSerial;
		data["StockPositionSerial"] = task_data->StockPositionSerial;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RecordNumber"] = task_data->RecordNumber;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnLock(data);
};

void ToraOptionApi::processErrRtnLockInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockField* task_data = (CTORATstpSPInputLockField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["LockRef"] = task_data->LockRef;
		data["LockType"] = task_data->LockType;
		data["Volume"] = task_data->Volume;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnLockInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspLockAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockActionField* task_data = (CTORATstpSPInputLockActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["LockActionRef"] = task_data->LockActionRef;
		data["LockRef"] = task_data->LockRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["LockActionFlag"] = task_data->LockActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelLockLocalID"] = toUtf(task_data->CancelLockLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLockAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnLockAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockActionField* task_data = (CTORATstpSPInputLockActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["LockActionRef"] = task_data->LockActionRef;
		data["LockRef"] = task_data->LockRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["LockActionFlag"] = task_data->LockActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelLockLocalID"] = toUtf(task_data->CancelLockLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnLockAction(data, error, task->task_id);
};

void ToraOptionApi::processRtnStockDisposal(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalField* task_data = (CTORATstpSPStockDisposalField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StockDisposalRef"] = task_data->StockDisposalRef;
		data["StockDisposalSysID"] = toUtf(task_data->StockDisposalSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["StockDisposalLocalID"] = toUtf(task_data->StockDisposalLocalID);
		data["StockDisposalType"] = task_data->StockDisposalType;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["StockDisposalStatus"] = task_data->StockDisposalStatus;
		data["StockDisposalOperateStatus"] = task_data->StockDisposalOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnStockDisposal(data);
};

void ToraOptionApi::processRspCombOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderField* task_data = (CTORATstpSPInputCombOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["CombDirection"] = task_data->CombDirection;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["Volume"] = task_data->Volume;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnCombOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderField* task_data = (CTORATstpSPCombOrderField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["CombDirection"] = task_data->CombDirection;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CombOrderLocalID"] = toUtf(task_data->CombOrderLocalID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["CombOrderStatus"] = task_data->CombOrderStatus;
		data["CombOrderOperateStatus"] = task_data->CombOrderOperateStatus;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ErrorID"] = task_data->ErrorID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnCombOrder(data);
};

void ToraOptionApi::processErrRtnCombOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderField* task_data = (CTORATstpSPInputCombOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["CombDirection"] = task_data->CombDirection;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["Volume"] = task_data->Volume;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspCombOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderActionField* task_data = (CTORATstpSPInputCombOrderActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CombOrderActionRef"] = task_data->CombOrderActionRef;
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["CombOrderActionFlag"] = task_data->CombOrderActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCombOrderLocalID"] = toUtf(task_data->CancelCombOrderLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnCombOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderActionField* task_data = (CTORATstpSPInputCombOrderActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CombOrderActionRef"] = task_data->CombOrderActionRef;
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["CombOrderActionFlag"] = task_data->CombOrderActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCombOrderLocalID"] = toUtf(task_data->CancelCombOrderLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processRspCondOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderField* task_data = (CTORATstpSPInputCondOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["UserForceClose"] = task_data->UserForceClose;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CondOrderID"] = task_data->CondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["OrderVolumeType"] = task_data->OrderVolumeType;
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
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnCondOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPConditionOrderField* task_data = (CTORATstpSPConditionOrderField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["RequestID"] = task_data->RequestID;
		data["UserForceClose"] = task_data->UserForceClose;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CondOrderID"] = task_data->CondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["OrderVolumeType"] = task_data->OrderVolumeType;
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
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["CondOrderStatus"] = task_data->CondOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnCondOrder(data);
};

void ToraOptionApi::processErrRtnCondOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderField* task_data = (CTORATstpSPInputCondOrderField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["UserForceClose"] = task_data->UserForceClose;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CondOrderID"] = task_data->CondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["OrderVolumeType"] = task_data->OrderVolumeType;
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
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderActionField* task_data = (CTORATstpSPInputCondOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderID"] = task_data->CondOrderID;
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderActionField* task_data = (CTORATstpSPInputCondOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderID"] = task_data->CondOrderID;
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderAction(data, error, task->task_id);
};

void ToraOptionApi::processRspCombExerciseInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseField* task_data = (CTORATstpSPInputCombExerciseField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["Volume"] = task_data->Volume;
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombExerciseInsert(data, error, task->task_id);
};

void ToraOptionApi::processRtnCombExercise(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseField* task_data = (CTORATstpSPCombExerciseField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CombExerciseLocalID"] = toUtf(task_data->CombExerciseLocalID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExerciseStatus"] = task_data->ExerciseStatus;
		data["ExerciseOperateStatus"] = task_data->ExerciseOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	this->onRtnCombExercise(data);
};

void ToraOptionApi::processErrRtnCombExerciseInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseField* task_data = (CTORATstpSPInputCombExerciseField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["Volume"] = task_data->Volume;
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombExerciseInsert(data, error, task->task_id);
};

void ToraOptionApi::processRspCombExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseActionField* task_data = (CTORATstpSPInputCombExerciseActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CombExerciseActionRef"] = task_data->CombExerciseActionRef;
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCombExerciseLocalID"] = toUtf(task_data->CancelCombExerciseLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombExerciseAction(data, error, task->task_id);
};

void ToraOptionApi::processErrRtnCombExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseActionField* task_data = (CTORATstpSPInputCombExerciseActionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CombExerciseActionRef"] = task_data->CombExerciseActionRef;
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CancelCombExerciseLocalID"] = toUtf(task_data->CancelCombExerciseLocalID);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombExerciseAction(data, error, task->task_id);
};

void ToraOptionApi::processRspInquiryMaxLockVolume(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryMaxLockVolumeField* task_data = (CTORATstpSPRspInquiryMaxLockVolumeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxLockVolume(data, error, task->task_id);
};

void ToraOptionApi::processRspInquiryMaxCoverVolume(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryMaxCoverVolumeField* task_data = (CTORATstpSPRspInquiryMaxCoverVolumeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxCoverVolume(data, error, task->task_id);
};

void ToraOptionApi::processRspInquirySplitCombMarginDifference(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquirySplitCombMarginDifferenceField* task_data = (CTORATstpSPRspInquirySplitCombMarginDifferenceField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombSecurityID"] = toUtf(task_data->CombSecurityID);
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["LeftLegPosMargin"] = task_data->LeftLegPosMargin;
		data["LeftLegPosLiveMargin"] = task_data->LeftLegPosLiveMargin;
		data["RightLegPosMargin"] = task_data->RightLegPosMargin;
		data["RightLegPosLiveMargin"] = task_data->RightLegPosLiveMargin;
		data["CombPosMargin"] = task_data->CombPosMargin;
		data["CombPosLiveMargin"] = task_data->CombPosLiveMargin;
		data["MarginDifference"] = task_data->MarginDifference;
		data["LiveMarginDifference"] = task_data->LiveMarginDifference;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquirySplitCombMarginDifference(data, error, task->task_id);
};

void ToraOptionApi::processRspTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferFundField* task_data = (CTORATstpSPInputTransferFundField*)task->task_data;
		data["ApplySerial"] = task_data->ApplySerial;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["TradingAccountPassword"] = toUtf(task_data->TradingAccountPassword);
		data["BankID"] = task_data->BankID;
		data["BankAccountPassword"] = toUtf(task_data->BankAccountPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferFund(data, error, task->task_id);
};

void ToraOptionApi::processRtnTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferFundField* task_data = (CTORATstpSPTransferFundField*)task->task_data;
		data["FundSerial"] = task_data->FundSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["BankID"] = task_data->BankID;
		delete task_data;
	}
	this->onRtnTransferFund(data);
};

void ToraOptionApi::processErrRtnTransferFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferFundField* task_data = (CTORATstpSPInputTransferFundField*)task->task_data;
		data["ApplySerial"] = task_data->ApplySerial;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferDirection"] = task_data->TransferDirection;
		data["Amount"] = task_data->Amount;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["TradingAccountPassword"] = toUtf(task_data->TradingAccountPassword);
		data["BankID"] = task_data->BankID;
		data["BankAccountPassword"] = toUtf(task_data->BankAccountPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferFund(data, error, task->task_id);
};

void ToraOptionApi::processRtnTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferPositionField* task_data = (CTORATstpSPTransferPositionField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MarketID"] = task_data->MarketID;
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferDirection"] = task_data->TransferDirection;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayVolume"] = task_data->TodayVolume;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRtnTransferPosition(data);
};

void ToraOptionApi::processErrRtnTransferPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferPositionField* task_data = (CTORATstpSPInputTransferPositionField*)task->task_data;
		data["ApplySerial"] = task_data->ApplySerial;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TransferDirection"] = task_data->TransferDirection;
		data["Volume"] = task_data->Volume;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["RequestID"] = task_data->RequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferPosition(data, error, task->task_id);
};

void ToraOptionApi::processRspTransferStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferStockPositionField* task_data = (CTORATstpSPInputTransferStockPositionField*)task->task_data;
		data["ApplySerial"] = task_data->ApplySerial;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SPStockTransferReason"] = task_data->SPStockTransferReason;
		data["Volume"] = task_data->Volume;
		data["TransferPositionType"] = task_data->TransferPositionType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferStockPosition(data, error, task->task_id);
};

void ToraOptionApi::processRtnTransferStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferStockPositionField* task_data = (CTORATstpSPTransferStockPositionField*)task->task_data;
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
		data["SPStockTransferReason"] = task_data->SPStockTransferReason;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayBSVolume"] = task_data->TodayBSVolume;
		data["TodayPRVolume"] = task_data->TodayPRVolume;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRtnTransferStockPosition(data);
};

void ToraOptionApi::processErrRtnTransferStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferStockPositionField* task_data = (CTORATstpSPInputTransferStockPositionField*)task->task_data;
		data["ApplySerial"] = task_data->ApplySerial;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SPStockTransferReason"] = task_data->SPStockTransferReason;
		data["Volume"] = task_data->Volume;
		data["TransferPositionType"] = task_data->TransferPositionType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferStockPosition(data, error, task->task_id);
};

void ToraOptionApi::processRspInquiryJZFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryJZFundField* task_data = (CTORATstpSPRspInquiryJZFundField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["UsefulMoney"] = task_data->UsefulMoney;
		data["FetchLimit"] = task_data->FetchLimit;
		data["RequestID"] = task_data->RequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryJZFund(data, error, task->task_id);
};

void ToraOptionApi::processRspInquiryBankAccountFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryBankAccountFundField* task_data = (CTORATstpSPRspInquiryBankAccountFundField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["Balance"] = task_data->Balance;
		data["RequestID"] = task_data->RequestID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["BankID"] = task_data->BankID;
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryBankAccountFund(data, error, task->task_id);
};

void ToraOptionApi::processRspInquiryStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryStockPositionField* task_data = (CTORATstpSPRspInquiryStockPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["HistoryPos"] = task_data->HistoryPos;
		data["HistoryPosFrozen"] = task_data->HistoryPosFrozen;
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayBSPosFrozen"] = task_data->TodayBSPosFrozen;
		data["TodayPRPos"] = task_data->TodayPRPos;
		data["TodayPRPosFrozen"] = task_data->TodayPRPosFrozen;
		data["TodaySMPos"] = task_data->TodaySMPos;
		data["TodaySMPosFrozen"] = task_data->TodaySMPosFrozen;
		data["HistoryPosCost"] = task_data->HistoryPosCost;
		data["TotalPosCost"] = task_data->TotalPosCost;
		data["MarginBuyPos"] = task_data->MarginBuyPos;
		data["ShortSellPos"] = task_data->ShortSellPos;
		data["TodayShortSellPos"] = task_data->TodayShortSellPos;
		data["PrePosition"] = task_data->PrePosition;
		data["AvailablePosition"] = task_data->AvailablePosition;
		data["CurrentPosition"] = task_data->CurrentPosition;
		data["RequestID"] = task_data->RequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryStockPosition(data, error, task->task_id);
};

void ToraOptionApi::processRtnMarketStatus(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPMarketStatusField* task_data = (CTORATstpSPMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnMarketStatus(data);
};

void ToraOptionApi::processRtnTradingNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingNoticeField* task_data = (CTORATstpSPTradingNoticeField*)task->task_data;
		data["NoticeSerial"] = toUtf(task_data->NoticeSerial);
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

void ToraOptionApi::processRspQryExchange(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExchangeField* task_data = (CTORATstpSPExchangeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["DataSyncStatus"] = task_data->DataSyncStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchange(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryMarketData(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPMarketDataField* task_data = (CTORATstpSPMarketDataField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
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
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["SettlementPrice"] = task_data->SettlementPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMarketData(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQrySecurity(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPSecurityField* task_data = (CTORATstpSPSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchSecurityID"] = toUtf(task_data->ExchSecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["UnderlyingSecurityID"] = toUtf(task_data->UnderlyingSecurityID);
		data["UnderlyingSecurityName"] = toUtf(task_data->UnderlyingSecurityName);
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["StrikeMode"] = task_data->StrikeMode;
		data["OptionsType"] = task_data->OptionsType;
		data["MarketID"] = task_data->MarketID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["OrderUnit"] = task_data->OrderUnit;
		data["BuyTradingUnit"] = task_data->BuyTradingUnit;
		data["SellTradingUnit"] = task_data->SellTradingUnit;
		data["MaxMarketOrderBuyVolume"] = task_data->MaxMarketOrderBuyVolume;
		data["MinMarketOrderBuyVolume"] = task_data->MinMarketOrderBuyVolume;
		data["MaxLimitOrderBuyVolume"] = task_data->MaxLimitOrderBuyVolume;
		data["MinLimitOrderBuyVolume"] = task_data->MinLimitOrderBuyVolume;
		data["MaxMarketOrderSellVolume"] = task_data->MaxMarketOrderSellVolume;
		data["MinMarketOrderSellVolume"] = task_data->MinMarketOrderSellVolume;
		data["MaxLimitOrderSellVolume"] = task_data->MaxLimitOrderSellVolume;
		data["MinLimitOrderSellVolume"] = task_data->MinLimitOrderSellVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["PositionType"] = task_data->PositionType;
		data["SecurityStatus"] = task_data->SecurityStatus;
		data["StrikePrice"] = task_data->StrikePrice;
		data["FirstDate"] = toUtf(task_data->FirstDate);
		data["LastDate"] = toUtf(task_data->LastDate);
		data["StrikeDate"] = toUtf(task_data->StrikeDate);
		data["ExpireDate"] = toUtf(task_data->ExpireDate);
		data["DelivDate"] = toUtf(task_data->DelivDate);
		data["IsUpDownLimit"] = task_data->IsUpDownLimit;
		data["MarginUnit"] = task_data->MarginUnit;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["UnderlyingPreClosePrice"] = task_data->UnderlyingPreClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["MaxQuoteOrderBuyVolume"] = task_data->MaxQuoteOrderBuyVolume;
		data["MinQuoteOrderBuyVolume"] = task_data->MinQuoteOrderBuyVolume;
		data["MaxQuoteOrderSellVolume"] = task_data->MaxQuoteOrderSellVolume;
		data["MinQuoteOrderSellVolume"] = task_data->MinQuoteOrderSellVolume;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecurity(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryBUProxy(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPBUProxyField* task_data = (CTORATstpSPBUProxyField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["UserID"] = toUtf(task_data->UserID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBUProxy(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryUser(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserField* task_data = (CTORATstpSPUserField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["UserName"] = toUtf(task_data->UserName);
		data["UserType"] = task_data->UserType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["LoginLimit"] = task_data->LoginLimit;
		data["PasswordFailLimit"] = task_data->PasswordFailLimit;
		data["Status"] = task_data->Status;
		data["Contacter"] = toUtf(task_data->Contacter);
		data["Fax"] = toUtf(task_data->Fax);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["Email"] = toUtf(task_data->Email);
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["CloseDate"] = toUtf(task_data->CloseDate);
		data["OrderInsertCommFlux"] = task_data->OrderInsertCommFlux;
		data["OrderActionCommFlux"] = task_data->OrderActionCommFlux;
		data["SSEOrderInsertCommFlux"] = task_data->SSEOrderInsertCommFlux;
		data["SSEOrderActionCommFlux"] = task_data->SSEOrderActionCommFlux;
		data["SZSEOrderInsertCommFlux"] = task_data->SZSEOrderInsertCommFlux;
		data["SZSEOrderActionCommFlux"] = task_data->SZSEOrderActionCommFlux;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryUser(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInvestor(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorField* task_data = (CTORATstpSPInvestorField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorType"] = task_data->InvestorType;
		data["InvestorName"] = toUtf(task_data->InvestorName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdCardNo"] = toUtf(task_data->IdCardNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["CloseDate"] = toUtf(task_data->CloseDate);
		data["TradeStatus"] = task_data->TradeStatus;
		data["Reserve1"] = toUtf(task_data->Reserve1);
		data["InvestorLevel"] = task_data->InvestorLevel;
		data["Mobile"] = toUtf(task_data->Mobile);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["Email"] = toUtf(task_data->Email);
		data["Fax"] = toUtf(task_data->Fax);
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["Reserve2"] = toUtf(task_data->Reserve2);
		data["Operways"] = toUtf(task_data->Operways);
		data["ActiveStatus"] = task_data->ActiveStatus;
		data["LoginLimit"] = task_data->LoginLimit;
		data["MarginFetchRatio"] = task_data->MarginFetchRatio;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryShareholderAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPShareholderAccountField* task_data = (CTORATstpSPShareholderAccountField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderAccount(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryTradingAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingAccountField* task_data = (CTORATstpSPTradingAccountField*)task->task_data;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["AccountType"] = task_data->AccountType;
		data["PreDeposit"] = task_data->PreDeposit;
		data["PreFrozenCash"] = task_data->PreFrozenCash;
		data["UsefulMoney"] = task_data->UsefulMoney;
		data["FetchLimit"] = task_data->FetchLimit;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CurrMargin"] = task_data->CurrMargin;
		data["Commission"] = task_data->Commission;
		data["RoyaltyIn"] = task_data->RoyaltyIn;
		data["RoyaltyOut"] = task_data->RoyaltyOut;
		data["AccountOwner"] = toUtf(task_data->AccountOwner);
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["BankID"] = task_data->BankID;
		data["ExcerciseFrozen"] = task_data->ExcerciseFrozen;
		data["RiskLivePercent"] = task_data->RiskLivePercent;
		data["RiskLiveLevel"] = task_data->RiskLiveLevel;
		data["LiveUsefulMoney"] = task_data->LiveUsefulMoney;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderField* task_data = (CTORATstpSPOrderField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["Price"] = task_data->Price;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OrderOperateStatus"] = task_data->OrderOperateStatus;
		data["OrderStatus"] = task_data->OrderStatus;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["UserForceClose"] = task_data->UserForceClose;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		data["TradeAmount"] = task_data->TradeAmount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryTrade(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradeField* task_data = (CTORATstpSPTradeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["OrderRef"] = task_data->OrderRef;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPPositionField* task_data = (CTORATstpSPPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["HistoryPos"] = task_data->HistoryPos;
		data["HistoryPosFrozen"] = task_data->HistoryPosFrozen;
		data["TodayPos"] = task_data->TodayPos;
		data["TodayPosFrozen"] = task_data->TodayPosFrozen;
		data["TotalPosCost"] = task_data->TotalPosCost;
		data["LongFrozen"] = task_data->LongFrozen;
		data["ShortFrozen"] = task_data->ShortFrozen;
		data["LongFrozenAmount"] = task_data->LongFrozenAmount;
		data["ShortFrozenAmount"] = task_data->ShortFrozenAmount;
		data["OpenVolume"] = task_data->OpenVolume;
		data["CloseVolume"] = task_data->CloseVolume;
		data["OpenAmount"] = task_data->OpenAmount;
		data["CloseAmount"] = task_data->CloseAmount;
		data["Margin"] = task_data->Margin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["StrikeFrozen"] = task_data->StrikeFrozen;
		data["StrikeFrozenAmount"] = task_data->StrikeFrozenAmount;
		data["PrePosition"] = task_data->PrePosition;
		data["LastPrice"] = task_data->LastPrice;
		data["HistoryCombPos"] = task_data->HistoryCombPos;
		data["TodayCombPos"] = task_data->TodayCombPos;
		data["HistoryCombPosSplitFrozen"] = task_data->HistoryCombPosSplitFrozen;
		data["TodayCombPosSplitFrozen"] = task_data->TodayCombPosSplitFrozen;
		data["HistoryPosCombFrozen"] = task_data->HistoryPosCombFrozen;
		data["TodayPosCombFrozen"] = task_data->TodayPosCombFrozen;
		data["OpenPosCost"] = task_data->OpenPosCost;
		data["PreCloseProfit"] = task_data->PreCloseProfit;
		data["TodayCloseProfit"] = task_data->TodayCloseProfit;
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["BuyQuotaUsed"] = task_data->BuyQuotaUsed;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryTradingFee(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingFeeField* task_data = (CTORATstpSPTradingFeeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BusinessClass"] = task_data->BusinessClass;
		data["SystemFlag"] = task_data->SystemFlag;
		data["StampTaxRatioByAmt"] = task_data->StampTaxRatioByAmt;
		data["StampTaxRatioByPar"] = task_data->StampTaxRatioByPar;
		data["StampTaxFeeByVolume"] = task_data->StampTaxFeeByVolume;
		data["StampTaxFeePerOrder"] = task_data->StampTaxFeePerOrder;
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
		data["RegulateFeeByVolume"] = task_data->RegulateFeeByVolume;
		data["RegulateFeePerOrder"] = task_data->RegulateFeePerOrder;
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
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingFee(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInvestorTradingFee(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorTradingFeeField* task_data = (CTORATstpSPInvestorTradingFeeField*)task->task_data;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BusinessClass"] = task_data->BusinessClass;
		data["BrokerageType"] = task_data->BrokerageType;
		data["RatioByAmt"] = task_data->RatioByAmt;
		data["RatioByPar"] = task_data->RatioByPar;
		data["FeePerOrder"] = task_data->FeePerOrder;
		data["FeeMin"] = task_data->FeeMin;
		data["FeeMax"] = task_data->FeeMax;
		data["FeeByVolume"] = task_data->FeeByVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorTradingFee(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInvestorMarginFee(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorMarginFeeField* task_data = (CTORATstpSPInvestorMarginFeeField*)task->task_data;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ProductID"] = task_data->ProductID;
		data["SecurityType"] = task_data->SecurityType;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["BusinessClass"] = task_data->BusinessClass;
		data["FeeByVolume"] = task_data->FeeByVolume;
		data["UpperRatio"] = task_data->UpperRatio;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorMarginFee(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryOrderFundDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderFundDetailField* task_data = (CTORATstpSPOrderFundDetailField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["StampTaxFee"] = task_data->StampTaxFee;
		data["TransferFee"] = task_data->TransferFee;
		data["HandlingFee"] = task_data->HandlingFee;
		data["RegulateFee"] = task_data->RegulateFee;
		data["BrokerageFee"] = task_data->BrokerageFee;
		data["SettlementFee"] = task_data->SettlementFee;
		data["Margin"] = task_data->Margin;
		data["OrderCashFrozen"] = task_data->OrderCashFrozen;
		data["TotalFeeFrozen"] = task_data->TotalFeeFrozen;
		data["OrderAmount"] = task_data->OrderAmount;
		data["Direction"] = task_data->Direction;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderFundDetail(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryFundTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPFundTransferDetailField* task_data = (CTORATstpSPFundTransferDetailField*)task->task_data;
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
		data["OperateSource"] = task_data->OperateSource;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["BankID"] = task_data->BankID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryPositionTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPPositionTransferDetailField* task_data = (CTORATstpSPPositionTransferDetailField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["MarketID"] = task_data->MarketID;
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TransferDirection"] = task_data->TransferDirection;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayVolume"] = task_data->TodayVolume;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderActionField* task_data = (CTORATstpSPOrderActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["CancelOrderLocalID"] = toUtf(task_data->CancelOrderLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockPositionField* task_data = (CTORATstpSPStockPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["HistoryPos"] = task_data->HistoryPos;
		data["HistoryPosFrozen"] = task_data->HistoryPosFrozen;
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayBSPosFrozen"] = task_data->TodayBSPosFrozen;
		data["TodayPRPos"] = task_data->TodayPRPos;
		data["TodayPRPosFrozen"] = task_data->TodayPRPosFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryLock(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockField* task_data = (CTORATstpSPLockField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["LockRef"] = task_data->LockRef;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["LockLocalID"] = toUtf(task_data->LockLocalID);
		data["LockType"] = task_data->LockType;
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["LockStatus"] = task_data->LockStatus;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ErrorID"] = task_data->ErrorID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["StockPositionLockSerial"] = task_data->StockPositionLockSerial;
		data["StockPositionSerial"] = task_data->StockPositionSerial;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["RecordNumber"] = task_data->RecordNumber;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLock(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryExercise(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseField* task_data = (CTORATstpSPExerciseField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["ExerciseLocalID"] = toUtf(task_data->ExerciseLocalID);
		data["ExerciseType"] = task_data->ExerciseType;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExerciseStatus"] = task_data->ExerciseStatus;
		data["ExerciseOperateStatus"] = task_data->ExerciseOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["StockPositionExerciseSerial"] = task_data->StockPositionExerciseSerial;
		data["StockPositionSerial"] = task_data->StockPositionSerial;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExercise(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryLockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockPositionField* task_data = (CTORATstpSPLockPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Volume"] = task_data->Volume;
		data["FrozenVolume"] = task_data->FrozenVolume;
		data["HistoryPos"] = task_data->HistoryPos;
		data["TodayBSPos"] = task_data->TodayBSPos;
		data["TodayPRPos"] = task_data->TodayPRPos;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseActionField* task_data = (CTORATstpSPExerciseActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CancelExerciseLocalID"] = toUtf(task_data->CancelExerciseLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["ExerciseActionRef"] = task_data->ExerciseActionRef;
		data["ExerciseLocalID"] = toUtf(task_data->ExerciseLocalID);
		data["ExerciseSysID"] = toUtf(task_data->ExerciseSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExerciseRef"] = task_data->ExerciseRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExerciseAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryLockAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockActionField* task_data = (CTORATstpSPLockActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CancelLockLocalID"] = toUtf(task_data->CancelLockLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["LockActionRef"] = task_data->LockActionRef;
		data["LockLocalID"] = toUtf(task_data->LockLocalID);
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["LockRef"] = task_data->LockRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["LockActionFlag"] = task_data->LockActionFlag;
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryStockPositionTransferDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockPositionTransferDetailField* task_data = (CTORATstpSPStockPositionTransferDetailField*)task->task_data;
		data["PositionSerial"] = task_data->PositionSerial;
		data["ApplySerial"] = task_data->ApplySerial;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["OuterInvestorID"] = toUtf(task_data->OuterInvestorID);
		data["OuterBusinessUnitID"] = toUtf(task_data->OuterBusinessUnitID);
		data["OuterShareholderID"] = toUtf(task_data->OuterShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketID"] = task_data->MarketID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SPStockTransferReason"] = task_data->SPStockTransferReason;
		data["TransferPositionType"] = task_data->TransferPositionType;
		data["HistoryVolume"] = task_data->HistoryVolume;
		data["TodayBSVolume"] = task_data->TodayBSVolume;
		data["TodayPRVolume"] = task_data->TodayPRVolume;
		data["TransferStatus"] = task_data->TransferStatus;
		data["OperatorID"] = toUtf(task_data->OperatorID);
		data["OperateDate"] = toUtf(task_data->OperateDate);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["StockPositionSerial"] = task_data->StockPositionSerial;
		data["bRepeal"] = task_data->bRepeal;
		data["OriginPositionSerial"] = task_data->OriginPositionSerial;
		data["OperateSource"] = task_data->OperateSource;
		data["BizRef"] = toUtf(task_data->BizRef);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryTradingNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingNoticeField* task_data = (CTORATstpSPTradingNoticeField*)task->task_data;
		data["NoticeSerial"] = toUtf(task_data->NoticeSerial);
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
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingNotice(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryStockDisposal(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalField* task_data = (CTORATstpSPStockDisposalField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StockDisposalRef"] = task_data->StockDisposalRef;
		data["StockDisposalSysID"] = toUtf(task_data->StockDisposalSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["StockDisposalLocalID"] = toUtf(task_data->StockDisposalLocalID);
		data["StockDisposalType"] = task_data->StockDisposalType;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["StockDisposalStatus"] = task_data->StockDisposalStatus;
		data["StockDisposalOperateStatus"] = task_data->StockDisposalOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockDisposal(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryStockDisposalAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalActionField* task_data = (CTORATstpSPStockDisposalActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CancelStockDisposalLocalID"] = toUtf(task_data->CancelStockDisposalLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["StockDisposalActionRef"] = task_data->StockDisposalActionRef;
		data["StockDisposalLocalID"] = toUtf(task_data->StockDisposalLocalID);
		data["StockDisposalSysID"] = toUtf(task_data->StockDisposalSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StockDisposalRef"] = task_data->StockDisposalRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["StockDisposalActionFlag"] = task_data->StockDisposalActionFlag;
		data["CancelStockDisposalStatus"] = task_data->CancelStockDisposalStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockDisposalAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCondOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCondOrderField* task_data = (CTORATstpSPCondOrderField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["Direction"] = task_data->Direction;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["OrderVolumeType"] = task_data->OrderVolumeType;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["RequestID"] = task_data->RequestID;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["CondOrderID"] = task_data->CondOrderID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
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
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["CondOrderStatus"] = task_data->CondOrderStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrder(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCondOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCondOrderActionField* task_data = (CTORATstpSPCondOrderActionField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["RequestID"] = task_data->RequestID;
		data["CondOrderActionRef"] = task_data->CondOrderActionRef;
		data["CondOrderRef"] = task_data->CondOrderRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CondOrderID"] = task_data->CondOrderID;
		data["OrderActionFlag"] = task_data->OrderActionFlag;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CancelCondOrderID"] = task_data->CancelCondOrderID;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrderAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInvestorLimitPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorLimitPositionField* task_data = (CTORATstpSPInvestorLimitPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TotalPositionLimit"] = task_data->TotalPositionLimit;
		data["LongPositionLimit"] = task_data->LongPositionLimit;
		data["TodayBuyOpenLimit"] = task_data->TodayBuyOpenLimit;
		data["TodaySellOpenLimit"] = task_data->TodaySellOpenLimit;
		data["TodayCoveredOpenLimit"] = task_data->TodayCoveredOpenLimit;
		data["TodayOpenLimit"] = task_data->TodayOpenLimit;
		data["LongCallPositionLimit"] = task_data->LongCallPositionLimit;
		data["LongPutPositionLimit"] = task_data->LongPutPositionLimit;
		data["LongUnderlyingPositionLimit"] = task_data->LongUnderlyingPositionLimit;
		data["ShortUnderlyingPositionLimit"] = task_data->ShortUnderlyingPositionLimit;
		data["TotalPositionFrozen"] = task_data->TotalPositionFrozen;
		data["LongPositionFrozen"] = task_data->LongPositionFrozen;
		data["TodayBuyOpenFrozen"] = task_data->TodayBuyOpenFrozen;
		data["TodaySellOpenFrozen"] = task_data->TodaySellOpenFrozen;
		data["TodayCoveredOpenFrozen"] = task_data->TodayCoveredOpenFrozen;
		data["TodayOpenFrozen"] = task_data->TodayOpenFrozen;
		data["LongCallPositionFrozen"] = task_data->LongCallPositionFrozen;
		data["LongPutPositionFrozen"] = task_data->LongPutPositionFrozen;
		data["LongUnderlyingPositionFrozen"] = task_data->LongUnderlyingPositionFrozen;
		data["ShortUnderlyingPositionFrozen"] = task_data->ShortUnderlyingPositionFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorLimitPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInvestorLimitAmount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorLimitAmountField* task_data = (CTORATstpSPInvestorLimitAmountField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["LongAmountLimit"] = task_data->LongAmountLimit;
		data["LongAmountFrozen"] = task_data->LongAmountFrozen;
		data["MarketID"] = task_data->MarketID;
		data["ExchangeID"] = task_data->ExchangeID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorLimitAmount(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderActionField* task_data = (CTORATstpSPCombOrderActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CancelCombOrderLocalID"] = toUtf(task_data->CancelCombOrderLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["CombOrderActionRef"] = task_data->CombOrderActionRef;
		data["CombOrderLocalID"] = toUtf(task_data->CombOrderLocalID);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombOrderActionFlag"] = task_data->CombOrderActionFlag;
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombOrderAction(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderField* task_data = (CTORATstpSPCombOrderField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["CombDirection"] = task_data->CombDirection;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CombOrderRef"] = task_data->CombOrderRef;
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CombOrderLocalID"] = toUtf(task_data->CombOrderLocalID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["RequestID"] = task_data->RequestID;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["CombOrderStatus"] = task_data->CombOrderStatus;
		data["CombOrderOperateStatus"] = task_data->CombOrderOperateStatus;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ErrorID"] = task_data->ErrorID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombOrder(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombPositionField* task_data = (CTORATstpSPCombPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["HistoryPos"] = task_data->HistoryPos;
		data["HistoryPosFrozen"] = task_data->HistoryPosFrozen;
		data["TodayPos"] = task_data->TodayPos;
		data["TodayPosFrozen"] = task_data->TodayPosFrozen;
		data["Margin"] = task_data->Margin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["Commission"] = task_data->Commission;
		data["PrePosition"] = task_data->PrePosition;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombPosDetail(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombPosDetailField* task_data = (CTORATstpSPCombPosDetailField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeCombID"] = toUtf(task_data->ExchangeCombID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["CombSecurityID"] = toUtf(task_data->CombSecurityID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["HistoryPos"] = task_data->HistoryPos;
		data["TodayPos"] = task_data->TodayPos;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["CombinationStatus"] = task_data->CombinationStatus;
		data["NoLegs"] = task_data->NoLegs;
		data["Leg1SecurityID"] = toUtf(task_data->Leg1SecurityID);
		data["Leg1HistoryPos"] = task_data->Leg1HistoryPos;
		data["Leg1TodayPos"] = task_data->Leg1TodayPos;
		data["Leg1PosiDirection"] = task_data->Leg1PosiDirection;
		data["Leg1OptionsType"] = task_data->Leg1OptionsType;
		data["Leg2SecurityID"] = toUtf(task_data->Leg2SecurityID);
		data["Leg2HistoryPos"] = task_data->Leg2HistoryPos;
		data["Leg2TodayPos"] = task_data->Leg2TodayPos;
		data["Leg2PosiDirection"] = task_data->Leg2PosiDirection;
		data["Leg2OptionsType"] = task_data->Leg2OptionsType;
		data["HistoryPosSplitFrozen"] = task_data->HistoryPosSplitFrozen;
		data["TodayPosSplitFrozen"] = task_data->TodayPosSplitFrozen;
		data["Leg1HistoryPosSplitFrozen"] = task_data->Leg1HistoryPosSplitFrozen;
		data["Leg1TodayPosSplitFrozen"] = task_data->Leg1TodayPosSplitFrozen;
		data["Leg2HistoryPosSplitFrozen"] = task_data->Leg2HistoryPosSplitFrozen;
		data["Leg2TodayPosSplitFrozen"] = task_data->Leg2TodayPosSplitFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombPosDetail(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryExerciseAppointment(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseAppointmentField* task_data = (CTORATstpSPExerciseAppointmentField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExerciseDay"] = toUtf(task_data->ExerciseDay);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["OptionsType"] = task_data->OptionsType;
		data["OptionUnit"] = task_data->OptionUnit;
		data["UnderlyingSecurityID"] = toUtf(task_data->UnderlyingSecurityID);
		data["ExerciseVolume"] = task_data->ExerciseVolume;
		data["ExercisePrice"] = task_data->ExercisePrice;
		data["ExerciseDirection"] = task_data->ExerciseDirection;
		data["CoverFlag"] = task_data->CoverFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExerciseAppointment(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryInsufficientCoveredStockPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInsufficientCoveredStockPositionField* task_data = (CTORATstpSPInsufficientCoveredStockPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["TotalInsufficientVolume"] = task_data->TotalInsufficientVolume;
		data["PreFrozenVolume"] = task_data->PreFrozenVolume;
		data["RepaidVolume"] = task_data->RepaidVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInsufficientCoveredStockPosition(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombSecurity(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombSecurityField* task_data = (CTORATstpSPCombSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["CombSecurityID"] = toUtf(task_data->CombSecurityID);
		data["CombinationStrategy"] = task_data->CombinationStrategy;
		data["Leg1SecurityID"] = toUtf(task_data->Leg1SecurityID);
		data["Leg1SecurityName"] = toUtf(task_data->Leg1SecurityName);
		data["RequiredLeg1PosiDirection"] = task_data->RequiredLeg1PosiDirection;
		data["Leg2SecurityID"] = toUtf(task_data->Leg2SecurityID);
		data["Leg2SecurityName"] = toUtf(task_data->Leg2SecurityName);
		data["RequiredLeg2PosiDirection"] = task_data->RequiredLeg2PosiDirection;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombSecurity(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombExercise(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseField* task_data = (CTORATstpSPCombExerciseField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = task_data->ExchangeID;
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CombExerciseLocalID"] = toUtf(task_data->CombExerciseLocalID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["Volume"] = task_data->Volume;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ShareholderIDType"] = task_data->ShareholderIDType;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["ExerciseStatus"] = task_data->ExerciseStatus;
		data["ExerciseOperateStatus"] = task_data->ExerciseOperateStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["AcceptTime"] = toUtf(task_data->AcceptTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["CancelUserID"] = toUtf(task_data->CancelUserID);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["RecordNumber"] = task_data->RecordNumber;
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombExercise(data, error, task->task_id, task->task_last);
};

void ToraOptionApi::processRspQryCombExerciseAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseActionField* task_data = (CTORATstpSPCombExerciseActionField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PbuID"] = toUtf(task_data->PbuID);
		data["CancelCombExerciseLocalID"] = toUtf(task_data->CancelCombExerciseLocalID);
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["CombExerciseActionRef"] = task_data->CombExerciseActionRef;
		data["CombExerciseLocalID"] = toUtf(task_data->CombExerciseLocalID);
		data["CombExerciseSysID"] = toUtf(task_data->CombExerciseSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["CombExerciseRef"] = task_data->CombExerciseRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["MarketID"] = task_data->MarketID;
		data["ShareholderID"] = toUtf(task_data->ShareholderID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["CallSecurityID"] = toUtf(task_data->CallSecurityID);
		data["PutSecurityID"] = toUtf(task_data->PutSecurityID);
		data["ExerciseActionFlag"] = task_data->ExerciseActionFlag;
		data["CancelOrderStatus"] = task_data->CancelOrderStatus;
		data["VolumeCanceled"] = task_data->VolumeCanceled;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ErrorID"] = task_data->ErrorID;
		data["InsertUserID"] = toUtf(task_data->InsertUserID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["InsertMillisec"] = task_data->InsertMillisec;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["RequestID"] = task_data->RequestID;
		data["TerminalInfo"] = toUtf(task_data->TerminalInfo);
		data["BInfo"] = toUtf(task_data->BInfo);
		data["SInfo"] = toUtf(task_data->SInfo);
		data["IInfo"] = task_data->IInfo;
		data["Operway"] = task_data->Operway;
		data["HDSerial"] = toUtf(task_data->HDSerial);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField* task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombExerciseAction(data, error, task->task_id, task->task_last);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void ToraOptionApi::createTstpSPTraderApi(string pszFlowPath, bool bEncrypt)
{
	this->api = CTORATstpSPTraderApi::CreateTstpSPTraderApi(pszFlowPath.c_str(), bEncrypt);
	this->api->RegisterSpi(this);

	this->active = true;
	this->task_thread = thread(&ToraOptionApi::processTask, this);
};

void ToraOptionApi::init()
{
	this->api->Init();
};

void ToraOptionApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

int ToraOptionApi::join()
{
	int i = this->api->Join();
	return i;
};

void ToraOptionApi::release()
{
	this->api->Release();
};

string ToraOptionApi::getApiVersion()
{
	return this->api->GetApiVersion();
};

int ToraOptionApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

void ToraOptionApi::registerNameServer(string pszNsAddress)
{
	this->api->RegisterNameServer((char*)pszNsAddress.c_str());
}

void ToraOptionApi::subscribePrivateTopic(int type)
{
	this->api->SubscribePrivateTopic((TORA_TE_RESUME_TYPE)type);
}

void ToraOptionApi::subscribePublicTopic(int type)
{
	this->api->SubscribePublicTopic((TORA_TE_RESUME_TYPE)type);
}

int ToraOptionApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int ToraOptionApi::reqUserLogin(const dict& req, int nRequestID)
{
	CTORATstpSPReqUserLoginField myreq = CTORATstpSPReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "LogInAccount", myreq.LogInAccount);
	getChar(req, "LogInAccountType", &myreq.LogInAccountType);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getChar(req, "Lang", &myreq.Lang);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "GWMacAddress", myreq.GWMacAddress);
	getString(req, "GWInnerIPAddress", myreq.GWInnerIPAddress);
	getString(req, "GWOuterIPAddress", myreq.GWOuterIPAddress);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "HDSerial", myreq.HDSerial);
	getChar(req, "AuthMode", &myreq.AuthMode);
	getString(req, "DeviceID", myreq.DeviceID);
	getString(req, "CertSerial", myreq.CertSerial);
	getString(req, "Mobile", myreq.Mobile);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	getChar(req, "DeviceType", &myreq.DeviceType);
	int i = this->api->ReqUserLogin(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqUserLogout(const dict& req, int nRequestID)
{
	CTORATstpSPUserLogoutField myreq = CTORATstpSPUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqUserPasswordUpdate(const dict& req, int nRequestID)
{
	CTORATstpSPUserPasswordUpdateField myreq = CTORATstpSPUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInputDeviceSerial(const dict& req, int nRequestID)
{
	CTORATstpSPReqInputDeviceSerialField myreq = CTORATstpSPReqInputDeviceSerialField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "DeviceID", myreq.DeviceID);
	getString(req, "CertSerial", myreq.CertSerial);
	getChar(req, "DeviceType", &myreq.DeviceType);
	int i = this->api->ReqInputDeviceSerial(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputOrderField myreq = CTORATstpSPInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
	getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "UserForceClose", &myreq.UserForceClose);
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getChar(req, "CondCheck", &myreq.CondCheck);
	getString(req, "ExchangeCombID", myreq.ExchangeCombID);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqOrderInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputOrderActionField myreq = CTORATstpSPInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "OrderActionFlag", &myreq.OrderActionFlag);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CancelOrderLocalID", myreq.CancelOrderLocalID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqExerciseInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputExerciseField myreq = CTORATstpSPInputExerciseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "ExerciseRef", &myreq.ExerciseRef);
	getInt(req, "Volume", &myreq.Volume);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "ExerciseSysID", myreq.ExerciseSysID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqExerciseInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqExerciseAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputExerciseActionField myreq = CTORATstpSPInputExerciseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "ExerciseActionRef", &myreq.ExerciseActionRef);
	getInt(req, "ExerciseRef", &myreq.ExerciseRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ExerciseSysID", myreq.ExerciseSysID);
	getChar(req, "ExerciseActionFlag", &myreq.ExerciseActionFlag);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CancelExerciseLocalID", myreq.CancelExerciseLocalID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqExerciseAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqLockInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputLockField myreq = CTORATstpSPInputLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "LockRef", &myreq.LockRef);
	getChar(req, "LockType", &myreq.LockType);
	getInt(req, "Volume", &myreq.Volume);
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "LockSysID", myreq.LockSysID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqLockInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqLockAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputLockActionField myreq = CTORATstpSPInputLockActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "LockActionRef", &myreq.LockActionRef);
	getInt(req, "LockRef", &myreq.LockRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "LockSysID", myreq.LockSysID);
	getChar(req, "LockActionFlag", &myreq.LockActionFlag);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CancelLockLocalID", myreq.CancelLockLocalID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqLockAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCombOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputCombOrderField myreq = CTORATstpSPInputCombOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "CombOrderRef", &myreq.CombOrderRef);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	getChar(req, "CombDirection", &myreq.CombDirection);
	getString(req, "ExchangeCombID", myreq.ExchangeCombID);
	getInt(req, "Volume", &myreq.Volume);
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "CombOrderSysID", myreq.CombOrderSysID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCombOrderInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCombOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputCombOrderActionField myreq = CTORATstpSPInputCombOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "CombOrderActionRef", &myreq.CombOrderActionRef);
	getInt(req, "CombOrderRef", &myreq.CombOrderRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "CombOrderSysID", myreq.CombOrderSysID);
	getChar(req, "CombOrderActionFlag", &myreq.CombOrderActionFlag);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CancelCombOrderLocalID", myreq.CancelCombOrderLocalID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCombOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCondOrderInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputCondOrderField myreq = CTORATstpSPInputCondOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getInt(req, "CondOrderRef", &myreq.CondOrderRef);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
	getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "UserForceClose", &myreq.UserForceClose);
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "OrderVolumeType", &myreq.OrderVolumeType);
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
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCondOrderInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCondOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputCondOrderActionField myreq = CTORATstpSPInputCondOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getInt(req, "CondOrderActionRef", &myreq.CondOrderActionRef);
	getInt(req, "CondOrderRef", &myreq.CondOrderRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getChar(req, "OrderActionFlag", &myreq.OrderActionFlag);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getInt(req, "CancelCondOrderID", &myreq.CancelCondOrderID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCondOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCombExerciseInsert(const dict& req, int nRequestID)
{
	CTORATstpSPInputCombExerciseField myreq = CTORATstpSPInputCombExerciseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CallSecurityID", myreq.CallSecurityID);
	getString(req, "PutSecurityID", myreq.PutSecurityID);
	getInt(req, "CombExerciseRef", &myreq.CombExerciseRef);
	getInt(req, "Volume", &myreq.Volume);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CombExerciseSysID", myreq.CombExerciseSysID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCombExerciseInsert(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqCombExerciseAction(const dict& req, int nRequestID)
{
	CTORATstpSPInputCombExerciseActionField myreq = CTORATstpSPInputCombExerciseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "CombExerciseActionRef", &myreq.CombExerciseActionRef);
	getInt(req, "CombExerciseRef", &myreq.CombExerciseRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "CombExerciseSysID", myreq.CombExerciseSysID);
	getChar(req, "ExerciseActionFlag", &myreq.ExerciseActionFlag);
	getString(req, "CallSecurityID", myreq.CallSecurityID);
	getString(req, "PutSecurityID", myreq.PutSecurityID);
	getString(req, "InnerIPAddress", myreq.InnerIPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "CancelCombExerciseLocalID", myreq.CancelCombExerciseLocalID);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getChar(req, "Operway", &myreq.Operway);
	getString(req, "HDSerial", myreq.HDSerial);
	getString(req, "OuterIPAddress", myreq.OuterIPAddress);
	getInt(req, "OuterPort", &myreq.OuterPort);
	int i = this->api->ReqCombExerciseAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryMaxLockVolume(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquiryMaxLockVolumeField myreq = CTORATstpSPReqInquiryMaxLockVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryMaxLockVolume(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryMaxCoverVolume(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquiryMaxCoverVolumeField myreq = CTORATstpSPReqInquiryMaxCoverVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryMaxCoverVolume(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquirySplitCombMarginDifference(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquirySplitCombMarginDifferenceField myreq = CTORATstpSPReqInquirySplitCombMarginDifferenceField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "CombSecurityID", myreq.CombSecurityID);
	getString(req, "ExchangeCombID", myreq.ExchangeCombID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	getInt(req, "Volume", &myreq.Volume);
	int i = this->api->ReqInquirySplitCombMarginDifference(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqTransferFund(const dict& req, int nRequestID)
{
	CTORATstpSPInputTransferFundField myreq = CTORATstpSPInputTransferFundField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "ApplySerial", &myreq.ApplySerial);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getDouble(req, "Amount", &myreq.Amount);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "TradingAccountPassword", myreq.TradingAccountPassword);
	getChar(req, "BankID", &myreq.BankID);
	getString(req, "BankAccountPassword", myreq.BankAccountPassword);
	int i = this->api->ReqTransferFund(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqTransferStockPosition(const dict& req, int nRequestID)
{
	CTORATstpSPInputTransferStockPositionField myreq = CTORATstpSPInputTransferStockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "ApplySerial", &myreq.ApplySerial);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "SPStockTransferReason", &myreq.SPStockTransferReason);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "TransferPositionType", &myreq.TransferPositionType);
	int i = this->api->ReqTransferStockPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryJZFund(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquiryJZFundField myreq = CTORATstpSPReqInquiryJZFundField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqInquiryJZFund(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryBankAccountFund(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquiryBankAccountFundField myreq = CTORATstpSPReqInquiryBankAccountFundField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getString(req, "BankAccountPassword", myreq.BankAccountPassword);
	int i = this->api->ReqInquiryBankAccountFund(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryStockPosition(const dict& req, int nRequestID)
{
	CTORATstpSPReqInquiryStockPositionField myreq = CTORATstpSPReqInquiryStockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "TradingDay", myreq.TradingDay);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryStockPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryExchange(const dict& req, int nRequestID)
{
	CTORATstpSPQryExchangeField myreq = CTORATstpSPQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryMarketData(const dict& req, int nRequestID)
{
	CTORATstpSPQryMarketDataField myreq = CTORATstpSPQryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryMarketData(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQrySecurity(const dict& req, int nRequestID)
{
	CTORATstpSPQrySecurityField myreq = CTORATstpSPQrySecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQrySecurity(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryBUProxy(const dict& req, int nRequestID)
{
	CTORATstpSPQryBUProxyField myreq = CTORATstpSPQryBUProxyField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryBUProxy(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryUser(const dict& req, int nRequestID)
{
	CTORATstpSPQryUserField myreq = CTORATstpSPQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getChar(req, "UserType", &myreq.UserType);
	int i = this->api->ReqQryUser(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestor(const dict& req, int nRequestID)
{
	CTORATstpSPQryInvestorField myreq = CTORATstpSPQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryShareholderAccount(const dict& req, int nRequestID)
{
	CTORATstpSPQryShareholderAccountField myreq = CTORATstpSPQryShareholderAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getChar(req, "ShareholderIDType", &myreq.ShareholderIDType);
	int i = this->api->ReqQryShareholderAccount(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryTradingAccount(const dict& req, int nRequestID)
{
	CTORATstpSPQryTradingAccountField myreq = CTORATstpSPQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "AccountType", &myreq.AccountType);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryTradingAccount(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryOrder(const dict& req, int nRequestID)
{
	CTORATstpSPQryOrderField myreq = CTORATstpSPQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	getString(req, "ExchangeCombID", myreq.ExchangeCombID);
	int i = this->api->ReqQryOrder(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryTrade(const dict& req, int nRequestID)
{
	CTORATstpSPQryTradeField myreq = CTORATstpSPQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "TradeID", myreq.TradeID);
	getString(req, "TradeTimeStart", myreq.TradeTimeStart);
	getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryTrade(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryPositionField myreq = CTORATstpSPQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "PosiDirection", &myreq.PosiDirection);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryTradingFee(const dict& req, int nRequestID)
{
	CTORATstpSPQryTradingFeeField myreq = CTORATstpSPQryTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryTradingFee(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorTradingFee(const dict& req, int nRequestID)
{
	CTORATstpSPQryInvestorTradingFeeField myreq = CTORATstpSPQryInvestorTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryInvestorTradingFee(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorMarginFee(const dict& req, int nRequestID)
{
	CTORATstpSPQryInvestorMarginFeeField myreq = CTORATstpSPQryInvestorMarginFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	getChar(req, "ProductID", &myreq.ProductID);
	getChar(req, "SecurityType", &myreq.SecurityType);
	getChar(req, "BusinessClass", &myreq.BusinessClass);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryInvestorMarginFee(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryOrderFundDetail(const dict& req, int nRequestID)
{
	CTORATstpSPQryOrderFundDetailField myreq = CTORATstpSPQryOrderFundDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryOrderFundDetail(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryFundTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpSPQryFundTransferDetailField myreq = CTORATstpSPQryFundTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryFundTransferDetail(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryPositionTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpSPQryPositionTransferDetailField myreq = CTORATstpSPQryPositionTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "TransferDirection", &myreq.TransferDirection);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "PosiDirection", &myreq.PosiDirection);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryPositionTransferDetail(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryOrderActionField myreq = CTORATstpSPQryOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelOrderLocalID", myreq.CancelOrderLocalID);
	getString(req, "OrderLocalID", myreq.OrderLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryStockPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryStockPositionField myreq = CTORATstpSPQryStockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryStockPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryLock(const dict& req, int nRequestID)
{
	CTORATstpSPQryLockField myreq = CTORATstpSPQryLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "LockSysID", myreq.LockSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "LockType", &myreq.LockType);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryLock(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryExercise(const dict& req, int nRequestID)
{
	CTORATstpSPQryExerciseField myreq = CTORATstpSPQryExerciseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "ExerciseSysID", myreq.ExerciseSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryExercise(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryLockPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryLockPositionField myreq = CTORATstpSPQryLockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryLockPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryExerciseAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryExerciseActionField myreq = CTORATstpSPQryExerciseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelExerciseLocalID", myreq.CancelExerciseLocalID);
	getString(req, "ExerciseLocalID", myreq.ExerciseLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryExerciseAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryLockAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryLockActionField myreq = CTORATstpSPQryLockActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelLockLocalID", myreq.CancelLockLocalID);
	getString(req, "LockLocalID", myreq.LockLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryLockAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryStockPositionTransferDetail(const dict& req, int nRequestID)
{
	CTORATstpSPQryStockPositionTransferDetailField myreq = CTORATstpSPQryStockPositionTransferDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "SPStockTransferReason", &myreq.SPStockTransferReason);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "TransferPositionType", &myreq.TransferPositionType);
	int i = this->api->ReqQryStockPositionTransferDetail(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryTradingNotice(const dict& req, int nRequestID)
{
	CTORATstpSPQryTradingNoticeField myreq = CTORATstpSPQryTradingNoticeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "DateStart", myreq.DateStart);
	getString(req, "DateEnd", myreq.DateEnd);
	getString(req, "TimeStart", myreq.TimeStart);
	getString(req, "TimeEnd", myreq.TimeEnd);
	int i = this->api->ReqQryTradingNotice(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryStockDisposal(const dict& req, int nRequestID)
{
	CTORATstpSPQryStockDisposalField myreq = CTORATstpSPQryStockDisposalField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "StockDisposalSysID", myreq.StockDisposalSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryStockDisposal(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryStockDisposalAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryStockDisposalActionField myreq = CTORATstpSPQryStockDisposalActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelStockDisposalLocalID", myreq.CancelStockDisposalLocalID);
	getString(req, "StockDisposalLocalID", myreq.StockDisposalLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryStockDisposalAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCondOrder(const dict& req, int nRequestID)
{
	CTORATstpSPQryCondOrderField myreq = CTORATstpSPQryCondOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getInt(req, "CondOrderID", &myreq.CondOrderID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCondOrder(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCondOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryCondOrderActionField myreq = CTORATstpSPQryCondOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCondOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorLimitPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryInvestorLimitPositionField myreq = CTORATstpSPQryInvestorLimitPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryInvestorLimitPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorLimitAmount(const dict& req, int nRequestID)
{
	CTORATstpSPQryInvestorLimitAmountField myreq = CTORATstpSPQryInvestorLimitAmountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryInvestorLimitAmount(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombOrderAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombOrderActionField myreq = CTORATstpSPQryCombOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelCombOrderLocalID", myreq.CancelCombOrderLocalID);
	getString(req, "CombOrderLocalID", myreq.CombOrderLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCombOrderAction(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombOrder(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombOrderField myreq = CTORATstpSPQryCombOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "CombOrderSysID", myreq.CombOrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	getChar(req, "CombDirection", &myreq.CombDirection);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCombOrder(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombPositionField myreq = CTORATstpSPQryCombPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	int i = this->api->ReqQryCombPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombPosDetail(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombPosDetailField myreq = CTORATstpSPQryCombPosDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CombSecurityID", myreq.CombSecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	getString(req, "ExchangeCombID", myreq.ExchangeCombID);
	getChar(req, "CombinationStatus", &myreq.CombinationStatus);
	int i = this->api->ReqQryCombPosDetail(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryExerciseAppointment(const dict& req, int nRequestID)
{
	CTORATstpSPQryExerciseAppointmentField myreq = CTORATstpSPQryExerciseAppointmentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ExerciseDay", myreq.ExerciseDay);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryExerciseAppointment(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInsufficientCoveredStockPosition(const dict& req, int nRequestID)
{
	CTORATstpSPQryInsufficientCoveredStockPositionField myreq = CTORATstpSPQryInsufficientCoveredStockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryInsufficientCoveredStockPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombSecurity(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombSecurityField myreq = CTORATstpSPQryCombSecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "CombSecurityID", myreq.CombSecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	int i = this->api->ReqQryCombSecurity(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombExercise(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombExerciseField myreq = CTORATstpSPQryCombExerciseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CallSecurityID", myreq.CallSecurityID);
	getString(req, "PutSecurityID", myreq.PutSecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "CombExerciseSysID", myreq.CombExerciseSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCombExercise(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombExerciseAction(const dict& req, int nRequestID)
{
	CTORATstpSPQryCombExerciseActionField myreq = CTORATstpSPQryCombExerciseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	getString(req, "ShareholderID", myreq.ShareholderID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	getString(req, "PbuID", myreq.PbuID);
	getString(req, "CancelCombExerciseLocalID", myreq.CancelCombExerciseLocalID);
	getString(req, "CombExerciseLocalID", myreq.CombExerciseLocalID);
	getString(req, "BInfo", myreq.BInfo);
	getString(req, "SInfo", myreq.SInfo);
	getInt(req, "IInfo", &myreq.IInfo);
	int i = this->api->ReqQryCombExerciseAction(&myreq, nRequestID);
	return i;
};

///-------------------------------------------------------------------------------------
///pybind11封装
///-------------------------------------------------------------------------------------

class PyOptionApi : public ToraOptionApi
{
public:
	using ToraOptionApi::ToraOptionApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onFrontConnected);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onFrontDisconnected, nReason);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspError, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspGetConnectionInfo, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserLogin, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserLogout, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserPasswordUpdate, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInputDeviceSerial, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspOrderInsert, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnOrder, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnOrderInsert, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspOrderAction, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnOrderAction, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTrade, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspExerciseInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspExerciseInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnExercise(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnExercise, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnExerciseInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnExerciseInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspExerciseAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspExerciseAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnExerciseAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnExerciseAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLockInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspLockInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnLock(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnLock, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnLockInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnLockInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLockAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspLockAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnLockAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnLockAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnStockDisposal(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnStockDisposal, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCombOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnCombOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCombOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCombOrderInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombOrderInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCombOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCombOrderAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombOrderAction, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCondOrderInsert, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCondOrder, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCondOrderInsert, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCondOrderAction, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCondOrderAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCombExerciseInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombExerciseInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnCombExercise(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCombExercise, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCombExerciseInsert(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombExerciseInsert, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspCombExerciseAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombExerciseAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnCombExerciseAction(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombExerciseAction, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryMaxLockVolume(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryMaxLockVolume, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryMaxCoverVolume(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryMaxCoverVolume, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquirySplitCombMarginDifference(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquirySplitCombMarginDifference, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspTransferFund, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferFund, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferFund, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferPosition, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferPosition, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspTransferStockPosition(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspTransferStockPosition, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTransferStockPosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferStockPosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnTransferStockPosition(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferStockPosition, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryJZFund, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryBankAccountFund, data, error, nRequestID);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspInquiryStockPosition(const dict& data, const dict& error, int nRequestID) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryStockPosition, data, error, nRequestID);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnMarketStatus, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTradingNotice, data);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExchange, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryMarketData(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryMarketData, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQrySecurity, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryBUProxy(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryBUProxy, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryUser, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestor, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryShareholderAccount, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingAccount, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrder, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTrade, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryPosition, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingFee, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorTradingFee, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorMarginFee(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorMarginFee, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrderFundDetail, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryFundTransferDetail, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryPositionTransferDetail, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStockPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLock(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLock, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExercise(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExercise, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLockPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLockPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExerciseAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExerciseAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLockAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLockAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStockPositionTransferDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockPositionTransferDetail, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingNotice, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStockDisposal(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockDisposal, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStockDisposalAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockDisposalAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCondOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCondOrder, data, error, nRequestID, last);
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
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCondOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorLimitPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorLimitPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorLimitAmount(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorLimitAmount, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombOrderAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombOrderAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombOrder(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombOrder, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombPosDetail(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombPosDetail, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExerciseAppointment(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExerciseAppointment, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInsufficientCoveredStockPosition(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInsufficientCoveredStockPosition, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombSecurity(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombSecurity, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombExercise(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombExercise, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombExerciseAction(const dict& data, const dict& error, int nRequestID, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombExerciseAction, data, error, nRequestID, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vntoraoption, m)
{
	class_<ToraOptionApi, PyOptionApi> ToraOptionApi(m, "ToraOptionApi", module_local());
	ToraOptionApi
		.def(init<>())
		.def("createTstpXMdApi", &ToraOptionApi::createTstpSPTraderApi)
		.def("registerFront", &ToraOptionApi::registerFront)
		.def("init", &ToraOptionApi::init)
		.def("join", &ToraOptionApi::join)
		.def("release", &ToraOptionApi::release)
		.def("getApiVersion", &ToraOptionApi::getApiVersion)
		.def("exit", &ToraOptionApi::exit)
		.def("registerNameServer", &ToraOptionApi::registerNameServer)
		.def("subscribePrivateTopic", &ToraOptionApi::subscribePrivateTopic)
		.def("subscribePublicTopic", &ToraOptionApi::subscribePublicTopic)
		.def("reqGetConnectionInfo", &ToraOptionApi::reqGetConnectionInfo)
		.def("reqUserLogin", &ToraOptionApi::reqUserLogin)
		.def("reqUserLogout", &ToraOptionApi::reqUserLogout)
		.def("reqUserPasswordUpdate", &ToraOptionApi::reqUserPasswordUpdate)
		.def("reqInputDeviceSerial", &ToraOptionApi::reqInputDeviceSerial)
		.def("reqOrderInsert", &ToraOptionApi::reqOrderInsert)
		.def("reqOrderAction", &ToraOptionApi::reqOrderAction)
		.def("reqExerciseInsert", &ToraOptionApi::reqExerciseInsert)
		.def("reqExerciseAction", &ToraOptionApi::reqExerciseAction)
		.def("reqLockInsert", &ToraOptionApi::reqLockInsert)
		.def("reqLockAction", &ToraOptionApi::reqLockAction)
		.def("reqCombOrderInsert", &ToraOptionApi::reqCombOrderInsert)
		.def("reqCombOrderAction", &ToraOptionApi::reqCombOrderAction)
		.def("reqCondOrderInsert", &ToraOptionApi::reqCondOrderInsert)
		.def("reqCondOrderAction", &ToraOptionApi::reqCondOrderAction)
		.def("reqCombExerciseInsert", &ToraOptionApi::reqCombExerciseInsert)
		.def("reqCombExerciseAction", &ToraOptionApi::reqCombExerciseAction)
		.def("reqInquiryMaxLockVolume", &ToraOptionApi::reqInquiryMaxLockVolume)
		.def("reqInquiryMaxCoverVolume", &ToraOptionApi::reqInquiryMaxCoverVolume)
		.def("reqInquirySplitCombMarginDifference", &ToraOptionApi::reqInquirySplitCombMarginDifference)
		.def("reqTransferFund", &ToraOptionApi::reqTransferFund)
		.def("reqTransferStockPosition", &ToraOptionApi::reqTransferStockPosition)
		.def("reqInquiryJZFund", &ToraOptionApi::reqInquiryJZFund)
		.def("reqInquiryBankAccountFund", &ToraOptionApi::reqInquiryBankAccountFund)
		.def("reqInquiryStockPosition", &ToraOptionApi::reqInquiryStockPosition)
		.def("reqQryExchange", &ToraOptionApi::reqQryExchange)
		.def("reqQryMarketData", &ToraOptionApi::reqQryMarketData)
		.def("reqQrySecurity", &ToraOptionApi::reqQrySecurity)
		.def("reqQryBUProxy", &ToraOptionApi::reqQryBUProxy)
		.def("reqQryUser", &ToraOptionApi::reqQryUser)
		.def("reqQryInvestor", &ToraOptionApi::reqQryInvestor)
		.def("reqQryShareholderAccount", &ToraOptionApi::reqQryShareholderAccount)
		.def("reqQryTradingAccount", &ToraOptionApi::reqQryTradingAccount)
		.def("reqQryOrder", &ToraOptionApi::reqQryOrder)
		.def("reqQryTrade", &ToraOptionApi::reqQryTrade)
		.def("reqQryPosition", &ToraOptionApi::reqQryPosition)
		.def("reqQryTradingFee", &ToraOptionApi::reqQryTradingFee)
		.def("reqQryInvestorTradingFee", &ToraOptionApi::reqQryInvestorTradingFee)
		.def("reqQryInvestorMarginFee", &ToraOptionApi::reqQryInvestorMarginFee)
		.def("reqQryOrderFundDetail", &ToraOptionApi::reqQryOrderFundDetail)
		.def("reqQryFundTransferDetail", &ToraOptionApi::reqQryFundTransferDetail)
		.def("reqQryPositionTransferDetail", &ToraOptionApi::reqQryPositionTransferDetail)
		.def("reqQryOrderAction", &ToraOptionApi::reqQryOrderAction)
		.def("reqQryStockPosition", &ToraOptionApi::reqQryStockPosition)
		.def("reqQryLock", &ToraOptionApi::reqQryLock)
		.def("reqQryExercise", &ToraOptionApi::reqQryExercise)
		.def("reqQryLockPosition", &ToraOptionApi::reqQryLockPosition)
		.def("reqQryExerciseAction", &ToraOptionApi::reqQryExerciseAction)
		.def("reqQryLockAction", &ToraOptionApi::reqQryLockAction)
		.def("reqQryStockPositionTransferDetail", &ToraOptionApi::reqQryStockPositionTransferDetail)
		.def("reqQryTradingNotice", &ToraOptionApi::reqQryTradingNotice)
		.def("reqQryStockDisposal", &ToraOptionApi::reqQryStockDisposal)
		.def("reqQryStockDisposalAction", &ToraOptionApi::reqQryStockDisposalAction)
		.def("reqQryCondOrder", &ToraOptionApi::reqQryCondOrder)
		.def("reqQryCondOrderAction", &ToraOptionApi::reqQryCondOrderAction)
		.def("reqQryInvestorLimitPosition", &ToraOptionApi::reqQryInvestorLimitPosition)
		.def("reqQryInvestorLimitAmount", &ToraOptionApi::reqQryInvestorLimitAmount)
		.def("reqQryCombOrderAction", &ToraOptionApi::reqQryCombOrderAction)
		.def("reqQryCombOrder", &ToraOptionApi::reqQryCombOrder)
		.def("reqQryCombPosition", &ToraOptionApi::reqQryCombPosition)
		.def("reqQryCombPosDetail", &ToraOptionApi::reqQryCombPosDetail)
		.def("reqQryExerciseAppointment", &ToraOptionApi::reqQryExerciseAppointment)
		.def("reqQryInsufficientCoveredStockPosition", &ToraOptionApi::reqQryInsufficientCoveredStockPosition)
		.def("reqQryCombSecurity", &ToraOptionApi::reqQryCombSecurity)
		.def("reqQryCombExercise", &ToraOptionApi::reqQryCombExercise)
		.def("reqQryCombExerciseAction", &ToraOptionApi::reqQryCombExerciseAction)

		.def("onFrontConnected", &ToraOptionApi::onFrontConnected)
		.def("onFrontDisconnected", &ToraOptionApi::onFrontDisconnected)
		.def("onRspError", &ToraOptionApi::onRspError)
		.def("onRspGetConnectionInfo", &ToraOptionApi::onRspGetConnectionInfo)
		.def("onRspUserLogin", &ToraOptionApi::onRspUserLogin)
		.def("onRspUserLogout", &ToraOptionApi::onRspUserLogout)
		.def("onRspUserPasswordUpdate", &ToraOptionApi::onRspUserPasswordUpdate)
		.def("onRspInputDeviceSerial", &ToraOptionApi::onRspInputDeviceSerial)
		.def("onRspOrderInsert", &ToraOptionApi::onRspOrderInsert)
		.def("onRtnOrder", &ToraOptionApi::onRtnOrder)
		.def("onErrRtnOrderInsert", &ToraOptionApi::onErrRtnOrderInsert)
		.def("onRspOrderAction", &ToraOptionApi::onRspOrderAction)
		.def("onErrRtnOrderAction", &ToraOptionApi::onErrRtnOrderAction)
		.def("onRtnTrade", &ToraOptionApi::onRtnTrade)
		.def("onRspExerciseInsert", &ToraOptionApi::onRspExerciseInsert)
		.def("onRtnExercise", &ToraOptionApi::onRtnExercise)
		.def("onErrRtnExerciseInsert", &ToraOptionApi::onErrRtnExerciseInsert)
		.def("onRspExerciseAction", &ToraOptionApi::onRspExerciseAction)
		.def("onErrRtnExerciseAction", &ToraOptionApi::onErrRtnExerciseAction)
		.def("onRspLockInsert", &ToraOptionApi::onRspLockInsert)
		.def("onRtnLock", &ToraOptionApi::onRtnLock)
		.def("onErrRtnLockInsert", &ToraOptionApi::onErrRtnLockInsert)
		.def("onRspLockAction", &ToraOptionApi::onRspLockAction)
		.def("onErrRtnLockAction", &ToraOptionApi::onErrRtnLockAction)
		.def("onRtnStockDisposal", &ToraOptionApi::onRtnStockDisposal)
		.def("onRspCombOrderInsert", &ToraOptionApi::onRspCombOrderInsert)
		.def("onRtnCombOrder", &ToraOptionApi::onRtnCombOrder)
		.def("onErrRtnCombOrderInsert", &ToraOptionApi::onErrRtnCombOrderInsert)
		.def("onRspCombOrderAction", &ToraOptionApi::onRspCombOrderAction)
		.def("onErrRtnCombOrderAction", &ToraOptionApi::onErrRtnCombOrderAction)
		.def("onRspCondOrderInsert", &ToraOptionApi::onRspCondOrderInsert)
		.def("onRtnCondOrder", &ToraOptionApi::onRtnCondOrder)
		.def("onErrRtnCondOrderInsert", &ToraOptionApi::onErrRtnCondOrderInsert)
		.def("onRspCondOrderAction", &ToraOptionApi::onRspCondOrderAction)
		.def("onErrRtnCondOrderAction", &ToraOptionApi::onErrRtnCondOrderAction)
		.def("onRspCombExerciseInsert", &ToraOptionApi::onRspCombExerciseInsert)
		.def("onRtnCombExercise", &ToraOptionApi::onRtnCombExercise)
		.def("onErrRtnCombExerciseInsert", &ToraOptionApi::onErrRtnCombExerciseInsert)
		.def("onRspCombExerciseAction", &ToraOptionApi::onRspCombExerciseAction)
		.def("onErrRtnCombExerciseAction", &ToraOptionApi::onErrRtnCombExerciseAction)
		.def("onRspInquiryMaxLockVolume", &ToraOptionApi::onRspInquiryMaxLockVolume)
		.def("onRspInquiryMaxCoverVolume", &ToraOptionApi::onRspInquiryMaxCoverVolume)
		.def("onRspInquirySplitCombMarginDifference", &ToraOptionApi::onRspInquirySplitCombMarginDifference)
		.def("onRspTransferFund", &ToraOptionApi::onRspTransferFund)
		.def("onRtnTransferFund", &ToraOptionApi::onRtnTransferFund)
		.def("onErrRtnTransferFund", &ToraOptionApi::onErrRtnTransferFund)
		.def("onRtnTransferPosition", &ToraOptionApi::onRtnTransferPosition)
		.def("onErrRtnTransferPosition", &ToraOptionApi::onErrRtnTransferPosition)
		.def("onRspTransferStockPosition", &ToraOptionApi::onRspTransferStockPosition)
		.def("onRtnTransferStockPosition", &ToraOptionApi::onRtnTransferStockPosition)
		.def("onErrRtnTransferStockPosition", &ToraOptionApi::onErrRtnTransferStockPosition)
		.def("onRspInquiryJZFund", &ToraOptionApi::onRspInquiryJZFund)
		.def("onRspInquiryBankAccountFund", &ToraOptionApi::onRspInquiryBankAccountFund)
		.def("onRspInquiryStockPosition", &ToraOptionApi::onRspInquiryStockPosition)
		.def("onRtnMarketStatus", &ToraOptionApi::onRtnMarketStatus)
		.def("onRtnTradingNotice", &ToraOptionApi::onRtnTradingNotice)
		.def("onRspQryExchange", &ToraOptionApi::onRspQryExchange)
		.def("onRspQryMarketData", &ToraOptionApi::onRspQryMarketData)
		.def("onRspQrySecurity", &ToraOptionApi::onRspQrySecurity)
		.def("onRspQryBUProxy", &ToraOptionApi::onRspQryBUProxy)
		.def("onRspQryUser", &ToraOptionApi::onRspQryUser)
		.def("onRspQryInvestor", &ToraOptionApi::onRspQryInvestor)
		.def("onRspQryShareholderAccount", &ToraOptionApi::onRspQryShareholderAccount)
		.def("onRspQryTradingAccount", &ToraOptionApi::onRspQryTradingAccount)
		.def("onRspQryOrder", &ToraOptionApi::onRspQryOrder)
		.def("onRspQryTrade", &ToraOptionApi::onRspQryTrade)
		.def("onRspQryPosition", &ToraOptionApi::onRspQryPosition)
		.def("onRspQryTradingFee", &ToraOptionApi::onRspQryTradingFee)
		.def("onRspQryInvestorTradingFee", &ToraOptionApi::onRspQryInvestorTradingFee)
		.def("onRspQryInvestorMarginFee", &ToraOptionApi::onRspQryInvestorMarginFee)
		.def("onRspQryOrderFundDetail", &ToraOptionApi::onRspQryOrderFundDetail)
		.def("onRspQryFundTransferDetail", &ToraOptionApi::onRspQryFundTransferDetail)
		.def("onRspQryPositionTransferDetail", &ToraOptionApi::onRspQryPositionTransferDetail)
		.def("onRspQryOrderAction", &ToraOptionApi::onRspQryOrderAction)
		.def("onRspQryStockPosition", &ToraOptionApi::onRspQryStockPosition)
		.def("onRspQryLock", &ToraOptionApi::onRspQryLock)
		.def("onRspQryExercise", &ToraOptionApi::onRspQryExercise)
		.def("onRspQryLockPosition", &ToraOptionApi::onRspQryLockPosition)
		.def("onRspQryExerciseAction", &ToraOptionApi::onRspQryExerciseAction)
		.def("onRspQryLockAction", &ToraOptionApi::onRspQryLockAction)
		.def("onRspQryStockPositionTransferDetail", &ToraOptionApi::onRspQryStockPositionTransferDetail)
		.def("onRspQryTradingNotice", &ToraOptionApi::onRspQryTradingNotice)
		.def("onRspQryStockDisposal", &ToraOptionApi::onRspQryStockDisposal)
		.def("onRspQryStockDisposalAction", &ToraOptionApi::onRspQryStockDisposalAction)
		.def("onRspQryCondOrder", &ToraOptionApi::onRspQryCondOrder)
		.def("onRspQryCondOrderAction", &ToraOptionApi::onRspQryCondOrderAction)
		.def("onRspQryInvestorLimitPosition", &ToraOptionApi::onRspQryInvestorLimitPosition)
		.def("onRspQryInvestorLimitAmount", &ToraOptionApi::onRspQryInvestorLimitAmount)
		.def("onRspQryCombOrderAction", &ToraOptionApi::onRspQryCombOrderAction)
		.def("onRspQryCombOrder", &ToraOptionApi::onRspQryCombOrder)
		.def("onRspQryCombPosition", &ToraOptionApi::onRspQryCombPosition)
		.def("onRspQryCombPosDetail", &ToraOptionApi::onRspQryCombPosDetail)
		.def("onRspQryExerciseAppointment", &ToraOptionApi::onRspQryExerciseAppointment)
		.def("onRspQryInsufficientCoveredStockPosition", &ToraOptionApi::onRspQryInsufficientCoveredStockPosition)
		.def("onRspQryCombSecurity", &ToraOptionApi::onRspQryCombSecurity)
		.def("onRspQryCombExercise", &ToraOptionApi::onRspQryCombExercise)
		.def("onRspQryCombExerciseAction", &ToraOptionApi::onRspQryCombExerciseAction)
		;

}
