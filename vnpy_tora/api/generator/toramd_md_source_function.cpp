int MdApi::reqGetConnectionInfo(int nRequestID)
{
	int i = this->api->ReqGetConnectionInfo(nRequestID);
	return i;
};

int MdApi::reqUserLogin(const dict &req, int nRequestID)
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

int MdApi::reqUserLogout(const dict &req, int nRequestID)
{
	CTORATstpUserLogoutField myreq = CTORATstpUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, nRequestID);
	return i;
};

int MdApi::subscribeMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribePHMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribePHMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribePHMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribePHMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribeSpecialMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeSpecialMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSpecialMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSpecialMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribeSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeSimplifyMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSimplifyMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribeSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeSecurityStatus((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSecurityStatus((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
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

int MdApi::reqInquiryMarketDataMirror(const dict &req, int nRequestID)
{
	CTORATstpInquiryMarketDataField myreq = CTORATstpInquiryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::reqInquiryPHMarketDataMirror(const dict &req, int nRequestID)
{
	CTORATstpInquiryMarketDataField myreq = CTORATstpInquiryMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "SecurityID", myreq.SecurityID);
	int i = this->api->ReqInquiryPHMarketDataMirror(&myreq, nRequestID);
	return i;
};

int MdApi::reqInquirySpecialMarketDataMirror(const dict &req, int nRequestID)
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
	int i = this->api->SubscribeSPMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSPMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSPMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribeSPSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeSPSimplifyMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSPSimplifyMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSPSimplifyMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::subscribeSPSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->SubscribeSPSecurityStatus((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeSPSecurityStatus(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeSPSecurityStatus((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
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

int MdApi::reqInquirySPMarketDataMirror(const dict &req, int nRequestID)
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
	int i = this->api->SubscribeRapidMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

int MdApi::unSubscribeRapidMarketData(string ppSecurityID, int nCount, string ExchangeID)
{
	int i = this->api->UnSubscribeRapidMarketData((char**)ppSecurityID.c_str(), nCount, (char)ExchangeID.c_str());
	return i;
};

