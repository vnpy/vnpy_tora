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

virtual void onRspOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTrade(const dict &data) {};

virtual void onRspExerciseInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnExercise(const dict &data) {};

virtual void onErrRtnExerciseInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspExerciseAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnExerciseAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspLockInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnLock(const dict &data) {};

virtual void onErrRtnLockInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspLockAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnLockAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnStockDisposal(const dict &data) {};

virtual void onRspCombOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnCombOrder(const dict &data) {};

virtual void onErrRtnCombOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCombOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnCombOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCondOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnCondOrder(const dict &data) {};

virtual void onErrRtnCondOrderInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCondOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnCondOrderAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCombExerciseInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnCombExercise(const dict &data) {};

virtual void onErrRtnCombExerciseInsert(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspCombExerciseAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onErrRtnCombExerciseAction(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryMaxLockVolume(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryMaxCoverVolume(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquirySplitCombMarginDifference(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspTransferFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTransferFund(const dict &data) {};

virtual void onErrRtnTransferFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTransferPosition(const dict &data) {};

virtual void onErrRtnTransferPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspTransferStockPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnTransferStockPosition(const dict &data) {};

virtual void onErrRtnTransferStockPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryJZFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryBankAccountFund(const dict &data, const dict &error, int nRequestID) {};

virtual void onRspInquiryStockPosition(const dict &data, const dict &error, int nRequestID) {};

virtual void onRtnMarketStatus(const dict &data) {};

virtual void onRtnTradingNotice(const dict &data) {};

virtual void onRspQryExchange(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryMarketData(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQrySecurity(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryBUProxy(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryUser(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestor(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryShareholderAccount(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingAccount(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTrade(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingFee(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorTradingFee(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorMarginFee(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrderFundDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryFundTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryStockPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryLock(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryExercise(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryLockPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryExerciseAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryLockAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryStockPositionTransferDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryTradingNotice(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryStockDisposal(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryStockDisposalAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCondOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCondOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorLimitPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInvestorLimitAmount(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombOrderAction(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombOrder(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombPosDetail(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryExerciseAppointment(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryInsufficientCoveredStockPosition(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombSecurity(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombExercise(const dict &data, const dict &error, int nRequestID, bool last) {};

virtual void onRspQryCombExerciseAction(const dict &data, const dict &error, int nRequestID, bool last) {};

