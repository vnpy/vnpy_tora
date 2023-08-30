void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onFrontConnected);
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
		PYBIND11_OVERLOAD(void, ToraMdApi, onFrontDisconnected, nReason);
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
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspGetConnectionInfo, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUserLogin, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUserLogout, data, error, nRequestID);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubPHMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubPHMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubPHMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubPHMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSpecialMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSpecialMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSpecialMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSpecialMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSimplifyMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSimplifyMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSimplifyMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSimplifyMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSecurityStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSecurityStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSecurityStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSecurityStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubMarketStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubMarketStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubMarketStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubMarketStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubImcParams(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubImcParams, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubImcParams(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubImcParams, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspInquiryMarketDataMirror, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquiryPHMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspInquiryPHMarketDataMirror, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquirySpecialMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspInquirySpecialMarketDataMirror, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSPMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSPMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSPMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSPMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSPSimplifyMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSPSimplifyMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSPSimplifyMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSPSimplifyMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSPSecurityStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSPSecurityStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSPSecurityStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSPSecurityStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubSPMarketStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubSPMarketStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubSPMarketStatus(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubSPMarketStatus, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspInquirySPMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspInquirySPMarketDataMirror, data, error, nRequestID, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPHMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnPHMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSpecialMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSpecialMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSimplifyMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSimplifyMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSecurityStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSecurityStatus, data);
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
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnMarketStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnImcParams(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnImcParams, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSPMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSPMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSPSimplifyMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSPSimplifyMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSPSecurityStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSPSecurityStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSPMarketStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnSPMarketStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubRapidMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspSubRapidMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubRapidMarketData(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRspUnSubRapidMarketData, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnRapidMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, ToraMdApi, onRtnRapidMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

