void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, StockApi, onFrontConnected);
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
		PYBIND11_OVERLOAD(void, StockApi, onFrontDisconnected, nReason);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspError, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspGetConnectionInfo, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspUserLogin, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspUserLogout, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspUserPasswordUpdate, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInputDeviceSerial, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnOrder, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnTrade, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspCondOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnCondOrder, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnCondOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspCondOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnCondOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspNegoOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnNegoOrder, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnNegoOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnNegoTrade, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspNegoOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnNegoOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspOrderInsertEx, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspOrderActionEx, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnMarketStatus, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspTransferFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnTransferFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnTransferFund, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspTransferPosition, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onErrRtnTransferPosition, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnTransferPosition, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnPeripheryTransferPosition, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnPeripheryTransferFund, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInquiryJZFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInquiryBankAccountFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRtnTradingNotice, data);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInquiryMaxOrderVolume, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInquiryTradeConcentration, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspModifyOpenPosCost, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInputNodeFundAssignment, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspInquiryNodeFundAssignment, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryExchange, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQrySecurity, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryUser, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestor, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryShareholderAccount, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryRationalInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryOrderAction, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryTrade, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingAccount, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPosition, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingFee, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorTradingFee, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOQuota, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryOrderFundDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryFundTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPositionTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPeripheryPositionTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPeripheryFundTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryBondConversionInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryBondPutbackInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorCondOrderLimitParam, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryConditionOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryCondOrderAction, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryTradingNotice, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryIPONumberResult, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryIPOMatchNumberResult, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryShareholderSpecPrivilege, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryMarket, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryETFFile, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryETFBasket, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryInvestorPositionLimit, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEImcParams, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEImcExchangeRate, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQrySZSEHKPriceTickInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryLofFundInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPledgePosition, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPledgeInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQrySystemNodeInfo, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryStandardBondPosition, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryPrematurityRepoOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoOrderAction, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryNegoTrade, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, StockApi, onRspQryNegotiationParam, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

