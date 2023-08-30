void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onFrontConnected);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFrontDisconnected(int nReason) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onFrontDisconnected, nReason);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspError(const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspError, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspGetConnectionInfo(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspGetConnectionInfo, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogin(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspUserLogin, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogout(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspUserLogout, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserPasswordUpdate(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspUserPasswordUpdate, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInputDeviceSerial(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInputDeviceSerial, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTrade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCondOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspCondOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCondOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnCondOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCondOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnCondOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCondOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspCondOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCondOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnCondOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspNegoOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspNegoOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnNegoOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnNegoOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnNegoOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnNegoOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnNegoTrade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnNegoTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspNegoOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspNegoOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnNegoOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnNegoOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderInsertEx(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspOrderInsertEx, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderActionEx(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspOrderActionEx, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnMarketStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnMarketStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspTransferFund(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspTransferFund, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnTransferFund(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnTransferFund, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTransferFund(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnTransferFund, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspTransferPosition(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspTransferPosition, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnTransferPosition(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onErrRtnTransferPosition, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTransferPosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnTransferPosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPeripheryTransferPosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnPeripheryTransferPosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPeripheryTransferFund(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnPeripheryTransferFund, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryJZFund(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInquiryJZFund, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryBankAccountFund(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInquiryBankAccountFund, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTradingNotice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRtnTradingNotice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryMaxOrderVolume(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInquiryMaxOrderVolume, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryTradeConcentration(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInquiryTradeConcentration, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspModifyOpenPosCost(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspModifyOpenPosCost, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInputNodeFundAssignment(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInputNodeFundAssignment, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryNodeFundAssignment(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspInquiryNodeFundAssignment, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchange(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryExchange, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySecurity(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQrySecurity, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPOInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryIPOInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryUser(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryUser, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestor(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryInvestor, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryShareholderAccount(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryShareholderAccount, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryRationalInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryRationalInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryOrder, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrderAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTrade(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryTrade, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingAccount(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryTradingAccount, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingFee(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryTradingFee, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorTradingFee(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryInvestorTradingFee, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPOQuota(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryIPOQuota, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrderFundDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryOrderFundDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryFundTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryFundTransferDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPositionTransferDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPeripheryPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPeripheryPositionTransferDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPeripheryFundTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPeripheryFundTransferDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBondConversionInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryBondConversionInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBondPutbackInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryBondPutbackInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorCondOrderLimitParam(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryInvestorCondOrderLimitParam, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryConditionOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryConditionOrder, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCondOrderAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryCondOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingNotice(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryTradingNotice, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPONumberResult(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryIPONumberResult, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPOMatchNumberResult(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryIPOMatchNumberResult, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryShareholderSpecPrivilege(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryShareholderSpecPrivilege, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryMarket(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryMarket, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryETFFile(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryETFFile, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryETFBasket(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryETFBasket, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorPositionLimit(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryInvestorPositionLimit, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySZSEImcParams(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQrySZSEImcParams, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySZSEImcExchangeRate(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQrySZSEImcExchangeRate, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySZSEHKPriceTickInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQrySZSEHKPriceTickInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryLofFundInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryLofFundInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPledgePosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPledgePosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPledgeInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPledgeInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySystemNodeInfo(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQrySystemNodeInfo, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryStandardBondPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryStandardBondPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPrematurityRepoOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryPrematurityRepoOrder, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryNegoOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryNegoOrder, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryNegoOrderAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryNegoOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryNegoTrade(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryNegoTrade, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryNegotiationParam(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraStockApi, onRspQryNegotiationParam, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

