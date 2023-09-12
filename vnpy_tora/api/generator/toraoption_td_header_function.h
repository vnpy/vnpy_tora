int join();

int reqGetConnectionInfo(int nrequestid);

int reqUserLogin(const dict &req, int nrequestid);

int reqUserLogout(const dict &req, int nrequestid);

int reqUserPasswordUpdate(const dict &req, int nrequestid);

int reqInputDeviceSerial(const dict &req, int nrequestid);

int reqOrderInsert(const dict &req, int nrequestid);

int reqOrderAction(const dict &req, int nrequestid);

int reqExerciseInsert(const dict &req, int nrequestid);

int reqExerciseAction(const dict &req, int nrequestid);

int reqLockInsert(const dict &req, int nrequestid);

int reqLockAction(const dict &req, int nrequestid);

int reqCombOrderInsert(const dict &req, int nrequestid);

int reqCombOrderAction(const dict &req, int nrequestid);

int reqCondOrderInsert(const dict &req, int nrequestid);

int reqCondOrderAction(const dict &req, int nrequestid);

int reqCombExerciseInsert(const dict &req, int nrequestid);

int reqCombExerciseAction(const dict &req, int nrequestid);

int reqInquiryMaxLockVolume(const dict &req, int nrequestid);

int reqInquiryMaxCoverVolume(const dict &req, int nrequestid);

int reqInquirySplitCombMarginDifference(const dict &req, int nrequestid);

int reqTransferFund(const dict &req, int nrequestid);

int reqTransferStockPosition(const dict &req, int nrequestid);

int reqInquiryJZFund(const dict &req, int nrequestid);

int reqInquiryBankAccountFund(const dict &req, int nrequestid);

int reqInquiryStockPosition(const dict &req, int nrequestid);

int reqQryExchange(const dict &req, int nrequestid);

int reqQryMarketData(const dict &req, int nrequestid);

int reqQrySecurity(const dict &req, int nrequestid);

int reqQryBUProxy(const dict &req, int nrequestid);

int reqQryUser(const dict &req, int nrequestid);

int reqQryInvestor(const dict &req, int nrequestid);

int reqQryShareholderAccount(const dict &req, int nrequestid);

int reqQryTradingAccount(const dict &req, int nrequestid);

int reqQryOrder(const dict &req, int nrequestid);

int reqQryTrade(const dict &req, int nrequestid);

int reqQryPosition(const dict &req, int nrequestid);

int reqQryTradingFee(const dict &req, int nrequestid);

int reqQryInvestorTradingFee(const dict &req, int nrequestid);

int reqQryInvestorMarginFee(const dict &req, int nrequestid);

int reqQryOrderFundDetail(const dict &req, int nrequestid);

int reqQryFundTransferDetail(const dict &req, int nrequestid);

int reqQryPositionTransferDetail(const dict &req, int nrequestid);

int reqQryOrderAction(const dict &req, int nrequestid);

int reqQryStockPosition(const dict &req, int nrequestid);

int reqQryLock(const dict &req, int nrequestid);

int reqQryExercise(const dict &req, int nrequestid);

int reqQryLockPosition(const dict &req, int nrequestid);

int reqQryExerciseAction(const dict &req, int nrequestid);

int reqQryLockAction(const dict &req, int nrequestid);

int reqQryStockPositionTransferDetail(const dict &req, int nrequestid);

int reqQryTradingNotice(const dict &req, int nrequestid);

int reqQryStockDisposal(const dict &req, int nrequestid);

int reqQryStockDisposalAction(const dict &req, int nrequestid);

int reqQryCondOrder(const dict &req, int nrequestid);

int reqQryCondOrderAction(const dict &req, int nrequestid);

int reqQryInvestorLimitPosition(const dict &req, int nrequestid);

int reqQryInvestorLimitAmount(const dict &req, int nrequestid);

int reqQryCombOrderAction(const dict &req, int nrequestid);

int reqQryCombOrder(const dict &req, int nrequestid);

int reqQryCombPosition(const dict &req, int nrequestid);

int reqQryCombPosDetail(const dict &req, int nrequestid);

int reqQryExerciseAppointment(const dict &req, int nrequestid);

int reqQryInsufficientCoveredStockPosition(const dict &req, int nrequestid);

int reqQryCombSecurity(const dict &req, int nrequestid);

int reqQryCombExercise(const dict &req, int nrequestid);

int reqQryCombExerciseAction(const dict &req, int nrequestid);

