void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onFrontConnected);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onFrontDisconnected, nReason);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspError, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspGetConnectionInfo, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserLogin, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserLogout, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspUserPasswordUpdate, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInputDeviceSerial, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnOrder, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspExerciseInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspExerciseInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnExercise(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnExercise, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnExerciseInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnExerciseInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspExerciseAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspExerciseAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnExerciseAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnExerciseAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspLockInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspLockInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnLock(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnLock, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnLockInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnLockInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspLockAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspLockAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnLockAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnLockAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnStockDisposal(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnStockDisposal, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCombOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCombOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCombOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCombOrderInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombOrderInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCombOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCombOrderAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCondOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCondOrder, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCondOrderInsert, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCondOrderAction, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCondOrderAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCombExerciseInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombExerciseInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCombExercise(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnCombExercise, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCombExerciseInsert(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombExerciseInsert, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCombExerciseAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspCombExerciseAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnCombExerciseAction(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnCombExerciseAction, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryMaxLockVolume(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryMaxLockVolume, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryMaxCoverVolume(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryMaxCoverVolume, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquirySplitCombMarginDifference(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquirySplitCombMarginDifference, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspTransferFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferFund, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferPosition, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferPosition, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspTransferStockPosition(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspTransferStockPosition, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTransferStockPosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTransferStockPosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnTransferStockPosition(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onErrRtnTransferStockPosition, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryJZFund, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryBankAccountFund, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryStockPosition(const dict &data, const dict &error, int nRequestID) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspInquiryStockPosition, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnMarketStatus, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRtnTradingNotice, data);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExchange, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryMarketData(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryMarketData, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQrySecurity, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBUProxy(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryBUProxy, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryUser, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestor, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryShareholderAccount, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingAccount, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTrade, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryPosition, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingFee, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorTradingFee, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorMarginFee(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorMarginFee, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrderFundDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryFundTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryPositionTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryStockPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryLock(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLock, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExercise(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExercise, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryLockPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLockPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExerciseAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExerciseAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryLockAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryLockAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryStockPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockPositionTransferDetail, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryTradingNotice, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryStockDisposal(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockDisposal, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryStockDisposalAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryStockDisposalAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCondOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCondOrder, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCondOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorLimitPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorLimitPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorLimitAmount(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInvestorLimitAmount, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombOrderAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombOrderAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombOrder(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombOrder, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombPosDetail(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombPosDetail, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExerciseAppointment(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryExerciseAppointment, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInsufficientCoveredStockPosition(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryInsufficientCoveredStockPosition, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombSecurity(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombSecurity, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombExercise(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombExercise, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombExerciseAction(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraOptionApi, onRspQryCombExerciseAction, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

