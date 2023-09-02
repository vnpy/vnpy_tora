void OptionApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void OptionApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void OptionApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void OptionApi::processRspGetConnectionInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPConnectionInfoField *task_data = (CTORATstpSPConnectionInfoField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGetConnectionInfo(data, error, task->task_id);
};

void OptionApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspUserLoginField *task_data = (CTORATstpSPRspUserLoginField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id);
};

void OptionApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserLogoutField *task_data = (CTORATstpSPUserLogoutField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id);
};

void OptionApi::processRspUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserPasswordUpdateField *task_data = (CTORATstpSPUserPasswordUpdateField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id);
};

void OptionApi::processRspInputDeviceSerial(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInputDeviceSerialField *task_data = (CTORATstpSPRspInputDeviceSerialField*)task->task_data;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputDeviceSerial(data, error, task->task_id);
};

void OptionApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderField *task_data = (CTORATstpSPInputOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id);
};

void OptionApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderField *task_data = (CTORATstpSPOrderField*)task->task_data;
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

void OptionApi::processErrRtnOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderField *task_data = (CTORATstpSPInputOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderInsert(data, error, task->task_id);
};

void OptionApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderActionField *task_data = (CTORATstpSPInputOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id);
};

void OptionApi::processErrRtnOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputOrderActionField *task_data = (CTORATstpSPInputOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderAction(data, error, task->task_id);
};

void OptionApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradeField *task_data = (CTORATstpSPTradeField*)task->task_data;
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

void OptionApi::processRspExerciseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseField *task_data = (CTORATstpSPInputExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExerciseInsert(data, error, task->task_id);
};

void OptionApi::processRtnExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseField *task_data = (CTORATstpSPExerciseField*)task->task_data;
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

void OptionApi::processErrRtnExerciseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseField *task_data = (CTORATstpSPInputExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExerciseInsert(data, error, task->task_id);
};

void OptionApi::processRspExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseActionField *task_data = (CTORATstpSPInputExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExerciseAction(data, error, task->task_id);
};

void OptionApi::processErrRtnExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputExerciseActionField *task_data = (CTORATstpSPInputExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExerciseAction(data, error, task->task_id);
};

void OptionApi::processRspLockInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockField *task_data = (CTORATstpSPInputLockField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLockInsert(data, error, task->task_id);
};

void OptionApi::processRtnLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockField *task_data = (CTORATstpSPLockField*)task->task_data;
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

void OptionApi::processErrRtnLockInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockField *task_data = (CTORATstpSPInputLockField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnLockInsert(data, error, task->task_id);
};

void OptionApi::processRspLockAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockActionField *task_data = (CTORATstpSPInputLockActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLockAction(data, error, task->task_id);
};

void OptionApi::processErrRtnLockAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputLockActionField *task_data = (CTORATstpSPInputLockActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnLockAction(data, error, task->task_id);
};

void OptionApi::processRtnStockDisposal(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalField *task_data = (CTORATstpSPStockDisposalField*)task->task_data;
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

void OptionApi::processRspCombOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderField *task_data = (CTORATstpSPInputCombOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombOrderInsert(data, error, task->task_id);
};

void OptionApi::processRtnCombOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderField *task_data = (CTORATstpSPCombOrderField*)task->task_data;
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

void OptionApi::processErrRtnCombOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderField *task_data = (CTORATstpSPInputCombOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombOrderInsert(data, error, task->task_id);
};

void OptionApi::processRspCombOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderActionField *task_data = (CTORATstpSPInputCombOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombOrderAction(data, error, task->task_id);
};

void OptionApi::processErrRtnCombOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombOrderActionField *task_data = (CTORATstpSPInputCombOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombOrderAction(data, error, task->task_id);
};

void OptionApi::processRspCondOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderField *task_data = (CTORATstpSPInputCondOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderInsert(data, error, task->task_id);
};

void OptionApi::processRtnCondOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPConditionOrderField *task_data = (CTORATstpSPConditionOrderField*)task->task_data;
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

void OptionApi::processErrRtnCondOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderField *task_data = (CTORATstpSPInputCondOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderInsert(data, error, task->task_id);
};

void OptionApi::processRspCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderActionField *task_data = (CTORATstpSPInputCondOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderAction(data, error, task->task_id);
};

void OptionApi::processErrRtnCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCondOrderActionField *task_data = (CTORATstpSPInputCondOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderAction(data, error, task->task_id);
};

void OptionApi::processRspCombExerciseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseField *task_data = (CTORATstpSPInputCombExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombExerciseInsert(data, error, task->task_id);
};

void OptionApi::processRtnCombExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseField *task_data = (CTORATstpSPCombExerciseField*)task->task_data;
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

void OptionApi::processErrRtnCombExerciseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseField *task_data = (CTORATstpSPInputCombExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombExerciseInsert(data, error, task->task_id);
};

void OptionApi::processRspCombExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseActionField *task_data = (CTORATstpSPInputCombExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombExerciseAction(data, error, task->task_id);
};

void OptionApi::processErrRtnCombExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputCombExerciseActionField *task_data = (CTORATstpSPInputCombExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombExerciseAction(data, error, task->task_id);
};

void OptionApi::processRspInquiryMaxLockVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryMaxLockVolumeField *task_data = (CTORATstpSPRspInquiryMaxLockVolumeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxLockVolume(data, error, task->task_id);
};

void OptionApi::processRspInquiryMaxCoverVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryMaxCoverVolumeField *task_data = (CTORATstpSPRspInquiryMaxCoverVolumeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxCoverVolume(data, error, task->task_id);
};

void OptionApi::processRspInquirySplitCombMarginDifference(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquirySplitCombMarginDifferenceField *task_data = (CTORATstpSPRspInquirySplitCombMarginDifferenceField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquirySplitCombMarginDifference(data, error, task->task_id);
};

void OptionApi::processRspTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferFundField *task_data = (CTORATstpSPInputTransferFundField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferFund(data, error, task->task_id);
};

void OptionApi::processRtnTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferFundField *task_data = (CTORATstpSPTransferFundField*)task->task_data;
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

void OptionApi::processErrRtnTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferFundField *task_data = (CTORATstpSPInputTransferFundField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferFund(data, error, task->task_id);
};

void OptionApi::processRtnTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferPositionField *task_data = (CTORATstpSPTransferPositionField*)task->task_data;
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

void OptionApi::processErrRtnTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferPositionField *task_data = (CTORATstpSPInputTransferPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferPosition(data, error, task->task_id);
};

void OptionApi::processRspTransferStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferStockPositionField *task_data = (CTORATstpSPInputTransferStockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferStockPosition(data, error, task->task_id);
};

void OptionApi::processRtnTransferStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTransferStockPositionField *task_data = (CTORATstpSPTransferStockPositionField*)task->task_data;
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

void OptionApi::processErrRtnTransferStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInputTransferStockPositionField *task_data = (CTORATstpSPInputTransferStockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferStockPosition(data, error, task->task_id);
};

void OptionApi::processRspInquiryJZFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryJZFundField *task_data = (CTORATstpSPRspInquiryJZFundField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryJZFund(data, error, task->task_id);
};

void OptionApi::processRspInquiryBankAccountFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryBankAccountFundField *task_data = (CTORATstpSPRspInquiryBankAccountFundField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryBankAccountFund(data, error, task->task_id);
};

void OptionApi::processRspInquiryStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPRspInquiryStockPositionField *task_data = (CTORATstpSPRspInquiryStockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryStockPosition(data, error, task->task_id);
};

void OptionApi::processRtnMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPMarketStatusField *task_data = (CTORATstpSPMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnMarketStatus(data);
};

void OptionApi::processRtnTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingNoticeField *task_data = (CTORATstpSPTradingNoticeField*)task->task_data;
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

void OptionApi::processRspQryExchange(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExchangeField *task_data = (CTORATstpSPExchangeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["DataSyncStatus"] = task_data->DataSyncStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchange(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPMarketDataField *task_data = (CTORATstpSPMarketDataField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMarketData(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQrySecurity(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPSecurityField *task_data = (CTORATstpSPSecurityField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecurity(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryBUProxy(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPBUProxyField *task_data = (CTORATstpSPBUProxyField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["UserID"] = toUtf(task_data->UserID);
		data["BusinessUnitID"] = toUtf(task_data->BusinessUnitID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBUProxy(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryUser(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPUserField *task_data = (CTORATstpSPUserField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryUser(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInvestor(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorField *task_data = (CTORATstpSPInvestorField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryShareholderAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPShareholderAccountField *task_data = (CTORATstpSPShareholderAccountField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderAccount(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingAccountField *task_data = (CTORATstpSPTradingAccountField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderField *task_data = (CTORATstpSPOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradeField *task_data = (CTORATstpSPTradeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPPositionField *task_data = (CTORATstpSPPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryTradingFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingFeeField *task_data = (CTORATstpSPTradingFeeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingFee(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInvestorTradingFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorTradingFeeField *task_data = (CTORATstpSPInvestorTradingFeeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorTradingFee(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInvestorMarginFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorMarginFeeField *task_data = (CTORATstpSPInvestorMarginFeeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorMarginFee(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryOrderFundDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderFundDetailField *task_data = (CTORATstpSPOrderFundDetailField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderFundDetail(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryFundTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPFundTransferDetailField *task_data = (CTORATstpSPFundTransferDetailField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryPositionTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPPositionTransferDetailField *task_data = (CTORATstpSPPositionTransferDetailField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPOrderActionField *task_data = (CTORATstpSPOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockPositionField *task_data = (CTORATstpSPStockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockField *task_data = (CTORATstpSPLockField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLock(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseField *task_data = (CTORATstpSPExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExercise(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryLockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockPositionField *task_data = (CTORATstpSPLockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseActionField *task_data = (CTORATstpSPExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExerciseAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryLockAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPLockActionField *task_data = (CTORATstpSPLockActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryStockPositionTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockPositionTransferDetailField *task_data = (CTORATstpSPStockPositionTransferDetailField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPTradingNoticeField *task_data = (CTORATstpSPTradingNoticeField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingNotice(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryStockDisposal(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalField *task_data = (CTORATstpSPStockDisposalField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockDisposal(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryStockDisposalAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPStockDisposalActionField *task_data = (CTORATstpSPStockDisposalActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockDisposalAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCondOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCondOrderField *task_data = (CTORATstpSPCondOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrder(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCondOrderActionField *task_data = (CTORATstpSPCondOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrderAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInvestorLimitPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorLimitPositionField *task_data = (CTORATstpSPInvestorLimitPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorLimitPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInvestorLimitAmount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInvestorLimitAmountField *task_data = (CTORATstpSPInvestorLimitAmountField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorLimitAmount(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderActionField *task_data = (CTORATstpSPCombOrderActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombOrderAction(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombOrderField *task_data = (CTORATstpSPCombOrderField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombOrder(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombPositionField *task_data = (CTORATstpSPCombPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombPosDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombPosDetailField *task_data = (CTORATstpSPCombPosDetailField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombPosDetail(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryExerciseAppointment(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPExerciseAppointmentField *task_data = (CTORATstpSPExerciseAppointmentField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExerciseAppointment(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryInsufficientCoveredStockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPInsufficientCoveredStockPositionField *task_data = (CTORATstpSPInsufficientCoveredStockPositionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInsufficientCoveredStockPosition(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombSecurity(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombSecurityField *task_data = (CTORATstpSPCombSecurityField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombSecurity(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseField *task_data = (CTORATstpSPCombExerciseField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombExercise(data, error, task->task_id, task->task_last);
};

void OptionApi::processRspQryCombExerciseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSPCombExerciseActionField *task_data = (CTORATstpSPCombExerciseActionField*)task->task_data;
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
		CTORATstpSPRspInfoField *task_error = (CTORATstpSPRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombExerciseAction(data, error, task->task_id, task->task_last);
};

