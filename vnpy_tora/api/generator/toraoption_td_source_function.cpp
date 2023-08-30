int ToraOptionApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int ToraOptionApi::reqUserLogin(const dict &req, int nRequestID)
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

int ToraOptionApi::reqUserLogout(const dict &req, int nRequestID)
{
	CTORATstpSPUserLogoutField myreq = CTORATstpSPUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqUserPasswordUpdate(const dict &req, int nRequestID)
{
	CTORATstpSPUserPasswordUpdateField myreq = CTORATstpSPUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInputDeviceSerial(const dict &req, int nRequestID)
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

int ToraOptionApi::reqOrderInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqExerciseInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqExerciseAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqLockInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqLockAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCombOrderInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCombOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCondOrderInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCondOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCombExerciseInsert(const dict &req, int nRequestID)
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

int ToraOptionApi::reqCombExerciseAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqInquiryMaxLockVolume(const dict &req, int nRequestID)
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

int ToraOptionApi::reqInquiryMaxCoverVolume(const dict &req, int nRequestID)
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

int ToraOptionApi::reqInquirySplitCombMarginDifference(const dict &req, int nRequestID)
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

int ToraOptionApi::reqTransferFund(const dict &req, int nRequestID)
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

int ToraOptionApi::reqTransferStockPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqInquiryJZFund(const dict &req, int nRequestID)
{
	CTORATstpSPReqInquiryJZFundField myreq = CTORATstpSPReqInquiryJZFundField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqInquiryJZFund(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqInquiryBankAccountFund(const dict &req, int nRequestID)
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

int ToraOptionApi::reqInquiryStockPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryExchange(const dict &req, int nRequestID)
{
	CTORATstpSPQryExchangeField myreq = CTORATstpSPQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryMarketData(const dict &req, int nRequestID)
{
	CTORATstpSPQryMarketDataField myreq = CTORATstpSPQryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryMarketData(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQrySecurity(const dict &req, int nRequestID)
{
	CTORATstpSPQrySecurityField myreq = CTORATstpSPQrySecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "SecurityID", myreq.SecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQrySecurity(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryBUProxy(const dict &req, int nRequestID)
{
	CTORATstpSPQryBUProxyField myreq = CTORATstpSPQryBUProxyField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "BusinessUnitID", myreq.BusinessUnitID);
	int i = this->api->ReqQryBUProxy(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryUser(const dict &req, int nRequestID)
{
	CTORATstpSPQryUserField myreq = CTORATstpSPQryUserField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getChar(req, "UserType", &myreq.UserType);
	int i = this->api->ReqQryUser(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestor(const dict &req, int nRequestID)
{
	CTORATstpSPQryInvestorField myreq = CTORATstpSPQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryShareholderAccount(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryTradingAccount(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryOrder(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryTrade(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryTradingFee(const dict &req, int nRequestID)
{
	CTORATstpSPQryTradingFeeField myreq = CTORATstpSPQryTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryTradingFee(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorTradingFee(const dict &req, int nRequestID)
{
	CTORATstpSPQryInvestorTradingFeeField myreq = CTORATstpSPQryInvestorTradingFeeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "DepartmentID", myreq.DepartmentID);
	int i = this->api->ReqQryInvestorTradingFee(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorMarginFee(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryOrderFundDetail(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryFundTransferDetail(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryPositionTransferDetail(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryStockPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryLock(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryExercise(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryLockPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryExerciseAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryLockAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryStockPositionTransferDetail(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryTradingNotice(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryStockDisposal(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryStockDisposalAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCondOrder(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCondOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryInvestorLimitPosition(const dict &req, int nRequestID)
{
	CTORATstpSPQryInvestorLimitPositionField myreq = CTORATstpSPQryInvestorLimitPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqQryInvestorLimitPosition(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryInvestorLimitAmount(const dict &req, int nRequestID)
{
	CTORATstpSPQryInvestorLimitAmountField myreq = CTORATstpSPQryInvestorLimitAmountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqQryInvestorLimitAmount(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombOrderAction(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCombOrder(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCombPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCombPosDetail(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryExerciseAppointment(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryInsufficientCoveredStockPosition(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCombSecurity(const dict &req, int nRequestID)
{
	CTORATstpSPQryCombSecurityField myreq = CTORATstpSPQryCombSecurityField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "CombSecurityID", myreq.CombSecurityID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getChar(req, "CombinationStrategy", &myreq.CombinationStrategy);
	int i = this->api->ReqQryCombSecurity(&myreq, nRequestID);
	return i;
};

int ToraOptionApi::reqQryCombExercise(const dict &req, int nRequestID)
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

int ToraOptionApi::reqQryCombExerciseAction(const dict &req, int nRequestID)
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

