virtual void onFrontConnected() {};

virtual void onFrontDisconnected(int nReason) {};

virtual void onRspError(const dict &error, int nRequestID, bool last) {};

virtual void onRspGetConnectionInfo(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspUserLogin(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspUserLogout(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInputDeviceSerial(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnOrder(const dict &data) {};

virtual void onErrRtnOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTrade(const dict &data) {};

virtual void onRspOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCondOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnCondOrder(const dict &data) {};

virtual void onErrRtnCondOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCondOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnCondOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspNegoOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnNegoOrder(const dict &data) {};

virtual void onErrRtnNegoOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnNegoTrade(const dict &data) {};

virtual void onRspNegoOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnNegoOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspOrderInsertEx(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspOrderActionEx(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnMarketStatus(const dict &data) {};

virtual void onRspTransferFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnTransferFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTransferFund(const dict &data) {};

virtual void onRspTransferPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnTransferPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTransferPosition(const dict &data) {};

virtual void onRtnPeripheryTransferPosition(const dict &data) {};

virtual void onRtnPeripheryTransferFund(const dict &data) {};

virtual void onRspInquiryJZFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryBankAccountFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTradingNotice(const dict &data) {};

virtual void onRspInquiryMaxOrderVolume(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryTradeConcentration(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspModifyOpenPosCost(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInputNodeFundAssignment(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryNodeFundAssignment(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspQryExchange(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySecurity(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryIPOInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryUser(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestor(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryShareholderAccount(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryRationalInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTrade(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingAccount(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingFee(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorTradingFee(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryIPOQuota(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrderFundDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryFundTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPeripheryPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPeripheryFundTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryBondConversionInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryBondPutbackInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorCondOrderLimitParam(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryConditionOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCondOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingNotice(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryIPONumberResult(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryIPOMatchNumberResult(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryShareholderSpecPrivilege(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryMarket(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryETFFile(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryETFBasket(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorPositionLimit(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySZSEImcParams(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySZSEImcExchangeRate(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySZSEHKPriceTickInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryLofFundInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPledgePosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPledgeInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySystemNodeInfo(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryStandardBondPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPrematurityRepoOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryNegoOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryNegoOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryNegoTrade(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryNegotiationParam(const dict &data, const dict &error, int nRequestID, bool last) {};

