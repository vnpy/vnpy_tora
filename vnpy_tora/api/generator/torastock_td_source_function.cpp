int StockApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int StockApi::reqUserLogin(const dict &req, int nRequestID)
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

int StockApi::reqUserLogout(const dict &req, int nRequestID)
{
	CTORATstpUserLogoutField myreq = CTORATstpUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "UserRequestID", &myreq.UserRequestID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int StockApi::reqUserPasswordUpdate(const dict &req, int nRequestID)
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

int StockApi::reqInputDeviceSerial(const dict &req, int nRequestID)
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

int StockApi::reqOrderInsert(const dict &req, int nRequestID)
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

int StockApi::reqOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqCondOrderInsert(const dict &req, int nRequestID)
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

int StockApi::reqCondOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqNegoOrderInsert(const dict &req, int nRequestID)
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

int StockApi::reqNegoOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqOrderInsertEx(const dict &req, int nRequestID)
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

int StockApi::reqOrderActionEx(const dict &req, int nRequestID)
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

int StockApi::reqTransferFund(const dict &req, int nRequestID)
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

int StockApi::reqTransferPosition(const dict &req, int nRequestID)
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

int StockApi::reqInquiryJZFund(const dict &req, int nRequestID)
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

int StockApi::reqInquiryBankAccountFund(const dict &req, int nRequestID)
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

int StockApi::reqInquiryMaxOrderVolume(const dict &req, int nRequestID)
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

int StockApi::reqInquiryTradeConcentration(const dict &req, int nRequestID)
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

int StockApi::reqModifyOpenPosCost(const dict &req, int nRequestID)
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

int StockApi::reqInputNodeFundAssignment(const dict &req, int nRequestID)
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

int StockApi::reqInquiryNodeFundAssignment(const dict &req, int nRequestID)
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

int StockApi::reqQryExchange(const dict &req, int nRequestID)
{
	CTORATstpQryExchangeField myreq = CTORATstpQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySecurity(const dict &req, int nRequestID)
{
	CTORATstpQrySecurityField myreq = CTORATstpQrySecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ProductID", &myreq.ProductID);
	int i = this->api->ReqQrySecurity(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPOInfo(const dict &req, int nRequestID)
{
	CTORATstpQryIPOInfoField myreq = CTORATstpQryIPOInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryIPOInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryUser(const dict &req, int nRequestID)
{
	CTORATstpQryUserField myreq = CTORATstpQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getChar(req, "UserType", &myreq.UserType);
	int i = this->api->ReqQryUser(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestor(const dict &req, int nRequestID)
{
	CTORATstpQryInvestorField myreq = CTORATstpQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryShareholderAccount(const dict &req, int nRequestID)
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

int StockApi::reqQryRationalInfo(const dict &req, int nRequestID)
{
	CTORATstpQryRationalInfoField myreq = CTORATstpQryRationalInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryRationalInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryOrder(const dict &req, int nRequestID)
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

int StockApi::reqQryOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqQryTrade(const dict &req, int nRequestID)
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

int StockApi::reqQryTradingAccount(const dict &req, int nRequestID)
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

int StockApi::reqQryPosition(const dict &req, int nRequestID)
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

int StockApi::reqQryTradingFee(const dict &req, int nRequestID)
{
	CTORATstpQryTradingFeeField myreq = CTORATstpQryTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryTradingFee(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorTradingFee(const dict &req, int nRequestID)
{
	CTORATstpQryInvestorTradingFeeField myreq = CTORATstpQryInvestorTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryInvestorTradingFee(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryIPOQuota(const dict &req, int nRequestID)
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

int StockApi::reqQryOrderFundDetail(const dict &req, int nRequestID)
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

int StockApi::reqQryFundTransferDetail(const dict &req, int nRequestID)
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

int StockApi::reqQryPositionTransferDetail(const dict &req, int nRequestID)
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

int StockApi::reqQryPeripheryPositionTransferDetail(const dict &req, int nRequestID)
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

int StockApi::reqQryPeripheryFundTransferDetail(const dict &req, int nRequestID)
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

int StockApi::reqQryBondConversionInfo(const dict &req, int nRequestID)
{
	CTORATstpQryBondConversionInfoField myreq = CTORATstpQryBondConversionInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryBondConversionInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryBondPutbackInfo(const dict &req, int nRequestID)
{
	CTORATstpQryBondPutbackInfoField myreq = CTORATstpQryBondPutbackInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryBondPutbackInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorCondOrderLimitParam(const dict &req, int nRequestID)
{
	CTORATstpQryInvestorCondOrderLimitParamField myreq = CTORATstpQryInvestorCondOrderLimitParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestorCondOrderLimitParam(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryConditionOrder(const dict &req, int nRequestID)
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

int StockApi::reqQryCondOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqQryTradingNotice(const dict &req, int nRequestID)
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

int StockApi::reqQryIPONumberResult(const dict &req, int nRequestID)
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

int StockApi::reqQryIPOMatchNumberResult(const dict &req, int nRequestID)
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

int StockApi::reqQryShareholderSpecPrivilege(const dict &req, int nRequestID)
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

int StockApi::reqQryMarket(const dict &req, int nRequestID)
{
	CTORATstpQryMarketField myreq = CTORATstpQryMarketField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "MarketID", &myreq.MarketID);
	int i = this->api->ReqQryMarket(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryETFFile(const dict &req, int nRequestID)
{
	CTORATstpQryETFFileField myreq = CTORATstpQryETFFileField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ETFSecurityID", myreq.ETFSecurityID);
	getString(req, "ETFCreRedSecurityID", myreq.ETFCreRedSecurityID);
	int i = this->api->ReqQryETFFile(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryETFBasket(const dict &req, int nRequestID)
{
	CTORATstpQryETFBasketField myreq = CTORATstpQryETFBasketField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ETFSecurityID", myreq.ETFSecurityID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryETFBasket(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryInvestorPositionLimit(const dict &req, int nRequestID)
{
	CTORATstpQryInvestorPositionLimitField myreq = CTORATstpQryInvestorPositionLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryInvestorPositionLimit(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEImcParams(const dict &req, int nRequestID)
{
	CTORATstpQrySZSEImcParamsField myreq = CTORATstpQrySZSEImcParamsField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "MarketID", &myreq.MarketID);
	int i = this->api->ReqQrySZSEImcParams(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEImcExchangeRate(const dict &req, int nRequestID)
{
	CTORATstpQrySZSEImcExchangeRateField myreq = CTORATstpQrySZSEImcExchangeRateField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "FromCurrency", &myreq.FromCurrency);
	getChar(req, "ToCurrency", &myreq.ToCurrency);
	int i = this->api->ReqQrySZSEImcExchangeRate(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySZSEHKPriceTickInfo(const dict &req, int nRequestID)
{
	CTORATstpQrySZSEHKPriceTickInfoField myreq = CTORATstpQrySZSEHKPriceTickInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "PriceTickID", &myreq.PriceTickID);
	int i = this->api->ReqQrySZSEHKPriceTickInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryLofFundInfo(const dict &req, int nRequestID)
{
	CTORATstpQryLofFundInfoField myreq = CTORATstpQryLofFundInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "FundID", myreq.FundID);
	getString(req, "MainFundID", myreq.MainFundID);
	int i = this->api->ReqQryLofFundInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryPledgePosition(const dict &req, int nRequestID)
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

int StockApi::reqQryPledgeInfo(const dict &req, int nRequestID)
{
	CTORATstpQryPledgeInfoField myreq = CTORATstpQryPledgeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryPledgeInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQrySystemNodeInfo(const dict &req, int nRequestID)
{
	CTORATstpQrySystemNodeInfoField myreq = CTORATstpQrySystemNodeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "NodeID", &myreq.NodeID);
	int i = this->api->ReqQrySystemNodeInfo(&myreq, nRequestID);
	return i;
};

int StockApi::reqQryStandardBondPosition(const dict &req, int nRequestID)
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

int StockApi::reqQryPrematurityRepoOrder(const dict &req, int nRequestID)
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

int StockApi::reqQryNegoOrder(const dict &req, int nRequestID)
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

int StockApi::reqQryNegoOrderAction(const dict &req, int nRequestID)
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

int StockApi::reqQryNegoTrade(const dict &req, int nRequestID)
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

int StockApi::reqQryNegotiationParam(const dict &req, int nRequestID)
{
	CTORATstpQryNegotiationParamField myreq = CTORATstpQryNegotiationParamField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryNegotiationParam(&myreq, nRequestID);
	return i;
};

