virtual void onFrontConnected() {};

virtual void onFrontDisconnected(int nReason) {};

virtual void onRspGetConnectionInfo(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspUserLogin(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspUserLogout(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspSubMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubMarketData(const dict &data, const dict &error) {};

virtual void onRspSubPHMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubPHMarketData(const dict &data, const dict &error) {};

virtual void onRspSubSpecialMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubSpecialMarketData(const dict &data, const dict &error) {};

virtual void onRspSubSimplifyMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubSimplifyMarketData(const dict &data, const dict &error) {};

virtual void onRspSubSecurityStatus(const dict &data, const dict &error) {};

virtual void onRspUnSubSecurityStatus(const dict &data, const dict &error) {};

virtual void onRspSubMarketStatus(const dict &data, const dict &error) {};

virtual void onRspUnSubMarketStatus(const dict &data, const dict &error) {};

virtual void onRspSubImcParams(const dict &data, const dict &error) {};

virtual void onRspUnSubImcParams(const dict &data, const dict &error) {};

virtual void onRspInquiryMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspInquiryPHMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspInquirySpecialMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspSubSPMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubSPMarketData(const dict &data, const dict &error) {};

virtual void onRspSubSPSimplifyMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubSPSimplifyMarketData(const dict &data, const dict &error) {};

virtual void onRspSubSPSecurityStatus(const dict &data, const dict &error) {};

virtual void onRspUnSubSPSecurityStatus(const dict &data, const dict &error) {};

virtual void onRspSubSPMarketStatus(const dict &data, const dict &error) {};

virtual void onRspUnSubSPMarketStatus(const dict &data, const dict &error) {};

virtual void onRspInquirySPMarketDataMirror(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRtnMarketData(const dict &data) {};

virtual void onRtnPHMarketData(const dict &data) {};

virtual void onRtnSpecialMarketData(const dict &data) {};

virtual void onRtnSimplifyMarketData(const dict &data) {};

virtual void onRtnSecurityStatus(const dict &data) {};

virtual void onRtnMarketStatus(const dict &data) {};

virtual void onRtnImcParams(const dict &data) {};

virtual void onRtnSPMarketData(const dict &data) {};

virtual void onRtnSPSimplifyMarketData(const dict &data) {};

virtual void onRtnSPSecurityStatus(const dict &data) {};

virtual void onRtnSPMarketStatus(const dict &data) {};

virtual void onRspSubRapidMarketData(const dict &data, const dict &error) {};

virtual void onRspUnSubRapidMarketData(const dict &data, const dict &error) {};

virtual void onRtnRapidMarketData(const dict &data) {};

