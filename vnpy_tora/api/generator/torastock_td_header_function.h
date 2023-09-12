int join();

int reqGetConnectionInfo(int nrequestid);

int reqUserLogin(const dict &req, int nrequestid);

int reqUserLogout(const dict &req, int nrequestid);

int reqUserPasswordUpdate(const dict &req, int nrequestid);

int reqInputDeviceSerial(const dict &req, int nrequestid);

int reqOrderInsert(const dict &req, int nrequestid);

int reqOrderAction(const dict &req, int nrequestid);

int reqCondOrderInsert(const dict &req, int nrequestid);

int reqCondOrderAction(const dict &req, int nrequestid);

int reqNegoOrderInsert(const dict &req, int nrequestid);

int reqNegoOrderAction(const dict &req, int nrequestid);

int reqOrderInsertEx(const dict &req, int nrequestid);

int reqOrderActionEx(const dict &req, int nrequestid);

int reqTransferFund(const dict &req, int nrequestid);

int reqTransferPosition(const dict &req, int nrequestid);

int reqInquiryJZFund(const dict &req, int nrequestid);

int reqInquiryBankAccountFund(const dict &req, int nrequestid);

int reqInquiryMaxOrderVolume(const dict &req, int nrequestid);

int reqInquiryTradeConcentration(const dict &req, int nrequestid);

int reqModifyOpenPosCost(const dict &req, int nrequestid);

int reqInputNodeFundAssignment(const dict &req, int nrequestid);

int reqInquiryNodeFundAssignment(const dict &req, int nrequestid);

int reqQryExchange(const dict &req, int nrequestid);

int reqQrySecurity(const dict &req, int nrequestid);

int reqQryIPOInfo(const dict &req, int nrequestid);

int reqQryUser(const dict &req, int nrequestid);

int reqQryInvestor(const dict &req, int nrequestid);

int reqQryShareholderAccount(const dict &req, int nrequestid);

int reqQryRationalInfo(const dict &req, int nrequestid);

int reqQryOrder(const dict &req, int nrequestid);

int reqQryOrderAction(const dict &req, int nrequestid);

int reqQryTrade(const dict &req, int nrequestid);

int reqQryTradingAccount(const dict &req, int nrequestid);

int reqQryPosition(const dict &req, int nrequestid);

int reqQryTradingFee(const dict &req, int nrequestid);

int reqQryInvestorTradingFee(const dict &req, int nrequestid);

int reqQryIPOQuota(const dict &req, int nrequestid);

int reqQryOrderFundDetail(const dict &req, int nrequestid);

int reqQryFundTransferDetail(const dict &req, int nrequestid);

int reqQryPositionTransferDetail(const dict &req, int nrequestid);

int reqQryPeripheryPositionTransferDetail(const dict &req, int nrequestid);

int reqQryPeripheryFundTransferDetail(const dict &req, int nrequestid);

int reqQryBondConversionInfo(const dict &req, int nrequestid);

int reqQryBondPutbackInfo(const dict &req, int nrequestid);

int reqQryInvestorCondOrderLimitParam(const dict &req, int nrequestid);

int reqQryConditionOrder(const dict &req, int nrequestid);

int reqQryCondOrderAction(const dict &req, int nrequestid);

int reqQryTradingNotice(const dict &req, int nrequestid);

int reqQryIPONumberResult(const dict &req, int nrequestid);

int reqQryIPOMatchNumberResult(const dict &req, int nrequestid);

int reqQryShareholderSpecPrivilege(const dict &req, int nrequestid);

int reqQryMarket(const dict &req, int nrequestid);

int reqQryETFFile(const dict &req, int nrequestid);

int reqQryETFBasket(const dict &req, int nrequestid);

int reqQryInvestorPositionLimit(const dict &req, int nrequestid);

int reqQrySZSEImcParams(const dict &req, int nrequestid);

int reqQrySZSEImcExchangeRate(const dict &req, int nrequestid);

int reqQrySZSEHKPriceTickInfo(const dict &req, int nrequestid);

int reqQryLofFundInfo(const dict &req, int nrequestid);

int reqQryPledgePosition(const dict &req, int nrequestid);

int reqQryPledgeInfo(const dict &req, int nrequestid);

int reqQrySystemNodeInfo(const dict &req, int nrequestid);

int reqQryStandardBondPosition(const dict &req, int nrequestid);

int reqQryPrematurityRepoOrder(const dict &req, int nrequestid);

int reqQryNegoOrder(const dict &req, int nrequestid);

int reqQryNegoOrderAction(const dict &req, int nrequestid);

int reqQryNegoTrade(const dict &req, int nrequestid);

int reqQryNegotiationParam(const dict &req, int nrequestid);

