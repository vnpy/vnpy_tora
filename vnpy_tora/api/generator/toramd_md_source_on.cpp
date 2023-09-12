void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onFrontConnected);
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
		PYBIND11_OVERLOAD(void, MdApi, onFrontDisconnected, nReason);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspGetConnectionInfo, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUserLogin, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUserLogout, data, error, nRequestID);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubPHMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubPHMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSpecialMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSpecialMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSimplifyMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSimplifyMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSecurityStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSecurityStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubMarketStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubMarketStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubImcParams, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubImcParams, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspInquiryMarketDataMirror, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspInquiryPHMarketDataMirror, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspInquirySpecialMarketDataMirror, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSPMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSPSimplifyMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPSimplifyMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSPSecurityStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPSecurityStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubSPMarketStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubSPMarketStatus, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspInquirySPMarketDataMirror, data, error, nRequestID, last);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnPHMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSpecialMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSimplifyMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSecurityStatus, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnMarketStatus, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnImcParams, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSPMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSPSimplifyMarketData, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSPSecurityStatus, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnSPMarketStatus, data);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspSubRapidMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubRapidMarketData, data, error);
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
		PYBIND11_OVERLOAD(void, MdApi, onRtnRapidMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

