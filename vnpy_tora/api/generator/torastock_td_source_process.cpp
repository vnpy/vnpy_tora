void StockApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void StockApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void StockApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void StockApi::processRspGetConnectionInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConnectionInfoField *task_data = (CTORATstpConnectionInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGetConnectionInfo(data, error, task->task_id);
};

void StockApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspUserLoginField *task_data = (CTORATstpRspUserLoginField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id);
};

void StockApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserLogoutField *task_data = (CTORATstpUserLogoutField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id);
};

void StockApi::processRspUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserPasswordUpdateField *task_data = (CTORATstpUserPasswordUpdateField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		data["UserRequestID"] = task_data->UserRequestID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id);
};

void StockApi::processRspInputDeviceSerial(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInputDeviceSerialField *task_data = (CTORATstpRspInputDeviceSerialField*)task->task_data;
		data["UserRequestID"] = task_data->UserRequestID;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputDeviceSerial(data, error, task->task_id);
};

void StockApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderField *task_data = (CTORATstpInputOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderField *task_data = (CTORATstpOrderField*)task->task_data;
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

void StockApi::processErrRtnOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderField *task_data = (CTORATstpInputOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradeField *task_data = (CTORATstpTradeField*)task->task_data;
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

void StockApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionField *task_data = (CTORATstpInputOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionField *task_data = (CTORATstpInputOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderAction(data, error, task->task_id);
};

void StockApi::processRspCondOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderField *task_data = (CTORATstpInputCondOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnCondOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConditionOrderField *task_data = (CTORATstpConditionOrderField*)task->task_data;
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

void StockApi::processErrRtnCondOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderField *task_data = (CTORATstpInputCondOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderInsert(data, error, task->task_id);
};

void StockApi::processRspCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderActionField *task_data = (CTORATstpInputCondOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCondOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputCondOrderActionField *task_data = (CTORATstpInputCondOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCondOrderAction(data, error, task->task_id);
};

void StockApi::processRspNegoOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderField *task_data = (CTORATstpInputNegoOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspNegoOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnNegoOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderField *task_data = (CTORATstpNegoOrderField*)task->task_data;
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

void StockApi::processErrRtnNegoOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderField *task_data = (CTORATstpInputNegoOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnNegoOrderInsert(data, error, task->task_id);
};

void StockApi::processRtnNegoTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoTradeField *task_data = (CTORATstpNegoTradeField*)task->task_data;
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

void StockApi::processRspNegoOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderActionField *task_data = (CTORATstpInputNegoOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspNegoOrderAction(data, error, task->task_id);
};

void StockApi::processErrRtnNegoOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNegoOrderActionField *task_data = (CTORATstpInputNegoOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnNegoOrderAction(data, error, task->task_id);
};

void StockApi::processRspOrderInsertEx(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderExField *task_data = (CTORATstpInputOrderExField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsertEx(data, error, task->task_id);
};

void StockApi::processRspOrderActionEx(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputOrderActionExField *task_data = (CTORATstpInputOrderActionExField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderActionEx(data, error, task->task_id);
};

void StockApi::processRtnMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketStatusField *task_data = (CTORATstpMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnMarketStatus(data);
};

void StockApi::processRspTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferFundField *task_data = (CTORATstpInputTransferFundField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferFund(data, error, task->task_id);
};

void StockApi::processErrRtnTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferFundField *task_data = (CTORATstpInputTransferFundField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferFund(data, error, task->task_id);
};

void StockApi::processRtnTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTransferFundField *task_data = (CTORATstpTransferFundField*)task->task_data;
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

void StockApi::processRspTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferPositionField *task_data = (CTORATstpInputTransferPositionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferPosition(data, error, task->task_id);
};

void StockApi::processErrRtnTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputTransferPositionField *task_data = (CTORATstpInputTransferPositionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnTransferPosition(data, error, task->task_id);
};

void StockApi::processRtnTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTransferPositionField *task_data = (CTORATstpTransferPositionField*)task->task_data;
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

void StockApi::processRtnPeripheryTransferPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryTransferPositionField *task_data = (CTORATstpPeripheryTransferPositionField*)task->task_data;
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

void StockApi::processRtnPeripheryTransferFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryTransferFundField *task_data = (CTORATstpPeripheryTransferFundField*)task->task_data;
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

void StockApi::processRspInquiryJZFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryJZFundField *task_data = (CTORATstpRspInquiryJZFundField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryJZFund(data, error, task->task_id);
};

void StockApi::processRspInquiryBankAccountFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryBankAccountFundField *task_data = (CTORATstpRspInquiryBankAccountFundField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryBankAccountFund(data, error, task->task_id);
};

void StockApi::processRtnTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingNoticeField *task_data = (CTORATstpTradingNoticeField*)task->task_data;
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

void StockApi::processRspInquiryMaxOrderVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryMaxOrderVolumeField *task_data = (CTORATstpRspInquiryMaxOrderVolumeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMaxOrderVolume(data, error, task->task_id);
};

void StockApi::processRspInquiryTradeConcentration(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInquiryTradeConcentrationField *task_data = (CTORATstpInquiryTradeConcentrationField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryTradeConcentration(data, error, task->task_id);
};

void StockApi::processRspModifyOpenPosCost(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpReqModifyOpenPosCostField *task_data = (CTORATstpReqModifyOpenPosCostField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspModifyOpenPosCost(data, error, task->task_id);
};

void StockApi::processRspInputNodeFundAssignment(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInputNodeFundAssignmentField *task_data = (CTORATstpInputNodeFundAssignmentField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInputNodeFundAssignment(data, error, task->task_id);
};

void StockApi::processRspInquiryNodeFundAssignment(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspInquiryNodeFundAssignmentField *task_data = (CTORATstpRspInquiryNodeFundAssignmentField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryNodeFundAssignment(data, error, task->task_id);
};

void StockApi::processRspQryExchange(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpExchangeField *task_data = (CTORATstpExchangeField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["DataSyncStatus"] = task_data->DataSyncStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchange(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySecurity(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityField *task_data = (CTORATstpSecurityField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecurity(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOInfoField *task_data = (CTORATstpIPOInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryUser(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserField *task_data = (CTORATstpUserField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryUser(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestor(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorField *task_data = (CTORATstpInvestorField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryShareholderAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpShareholderAccountField *task_data = (CTORATstpShareholderAccountField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderAccount(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryRationalInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRationalInfoField *task_data = (CTORATstpRationalInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRationalInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderField *task_data = (CTORATstpOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderActionField *task_data = (CTORATstpOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradeField *task_data = (CTORATstpTradeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingAccountField *task_data = (CTORATstpTradingAccountField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPositionField *task_data = (CTORATstpPositionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingFeeField *task_data = (CTORATstpTradingFeeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingFee(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorTradingFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorTradingFeeField *task_data = (CTORATstpInvestorTradingFeeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorTradingFee(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOQuota(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOQuotaField *task_data = (CTORATstpIPOQuotaField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOQuota(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryOrderFundDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpOrderFundDetailField *task_data = (CTORATstpOrderFundDetailField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrderFundDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryFundTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpFundTransferDetailField *task_data = (CTORATstpFundTransferDetailField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPositionTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPositionTransferDetailField *task_data = (CTORATstpPositionTransferDetailField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPeripheryPositionTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryPositionTransferDetailField *task_data = (CTORATstpPeripheryPositionTransferDetailField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPeripheryPositionTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPeripheryFundTransferDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPeripheryFundTransferDetailField *task_data = (CTORATstpPeripheryFundTransferDetailField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPeripheryFundTransferDetail(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryBondConversionInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpBondConversionInfoField *task_data = (CTORATstpBondConversionInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBondConversionInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryBondPutbackInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpBondPutbackInfoField *task_data = (CTORATstpBondPutbackInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBondPutbackInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorCondOrderLimitParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorCondOrderLimitParamField *task_data = (CTORATstpInvestorCondOrderLimitParamField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["MaxCondOrderLimitCnt"] = task_data->MaxCondOrderLimitCnt;
		data["CurrCondOrderCnt"] = task_data->CurrCondOrderCnt;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorCondOrderLimitParam(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryConditionOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConditionOrderField *task_data = (CTORATstpConditionOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryConditionOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryCondOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpCondOrderActionField *task_data = (CTORATstpCondOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCondOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpTradingNoticeField *task_data = (CTORATstpTradingNoticeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingNotice(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPONumberResult(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPONumberResultField *task_data = (CTORATstpIPONumberResultField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPONumberResult(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryIPOMatchNumberResult(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpIPOMatchNumberResultField *task_data = (CTORATstpIPOMatchNumberResultField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryIPOMatchNumberResult(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryShareholderSpecPrivilege(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpShareholderSpecPrivilegeField *task_data = (CTORATstpShareholderSpecPrivilegeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryShareholderSpecPrivilege(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryMarket(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketField *task_data = (CTORATstpMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketName"] = toUtf(task_data->MarketName);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMarket(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryETFFile(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpETFFileField *task_data = (CTORATstpETFFileField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFFile(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryETFBasket(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpETFBasketField *task_data = (CTORATstpETFBasketField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFBasket(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryInvestorPositionLimit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpInvestorPositionLimitField *task_data = (CTORATstpInvestorPositionLimitField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPositionLimit(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEImcParams(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEImcParamsField *task_data = (CTORATstpSZSEImcParamsField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEImcParams(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEImcExchangeRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEImcExchangeRateField *task_data = (CTORATstpSZSEImcExchangeRateField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEImcExchangeRate(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySZSEHKPriceTickInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSZSEHKPriceTickInfoField *task_data = (CTORATstpSZSEHKPriceTickInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySZSEHKPriceTickInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryLofFundInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpLofFundInfoField *task_data = (CTORATstpLofFundInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLofFundInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPledgePosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPledgePositionField *task_data = (CTORATstpPledgePositionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPledgePosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPledgeInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPledgeInfoField *task_data = (CTORATstpPledgeInfoField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPledgeInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQrySystemNodeInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSystemNodeInfoField *task_data = (CTORATstpSystemNodeInfoField*)task->task_data;
		data["NodeID"] = task_data->NodeID;
		data["NodeInfo"] = toUtf(task_data->NodeInfo);
		data["bCurrent"] = task_data->bCurrent;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySystemNodeInfo(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryStandardBondPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpStandardBondPositionField *task_data = (CTORATstpStandardBondPositionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStandardBondPosition(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryPrematurityRepoOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPrematurityRepoOrderField *task_data = (CTORATstpPrematurityRepoOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPrematurityRepoOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderField *task_data = (CTORATstpNegoOrderField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoOrder(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoOrderActionField *task_data = (CTORATstpNegoOrderActionField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoOrderAction(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegoTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegoTradeField *task_data = (CTORATstpNegoTradeField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegoTrade(data, error, task->task_id, task->task_last);
};

void StockApi::processRspQryNegotiationParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpNegotiationParamField *task_data = (CTORATstpNegotiationParamField*)task->task_data;
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
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNegotiationParam(data, error, task->task_id, task->task_last);
};

