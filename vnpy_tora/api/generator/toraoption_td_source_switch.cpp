case ONFRONTCONNECTED:
{
	this->processFrontConnected(&task);
	break;
}

case ONFRONTDISCONNECTED:
{
	this->processFrontDisconnected(&task);
	break;
}

case ONRSPERROR:
{
	this->processRspError(&task);
	break;
}

case ONRSPGETCONNECTIONINFO:
{
	this->processRspGetConnectionInfo(&task);
	break;
}

case ONRSPUSERLOGIN:
{
	this->processRspUserLogin(&task);
	break;
}

case ONRSPUSERLOGOUT:
{
	this->processRspUserLogout(&task);
	break;
}

case ONRSPUSERPASSWORDUPDATE:
{
	this->processRspUserPasswordUpdate(&task);
	break;
}

case ONRSPINPUTDEVICESERIAL:
{
	this->processRspInputDeviceSerial(&task);
	break;
}

case ONRSPORDERINSERT:
{
	this->processRspOrderInsert(&task);
	break;
}

case ONRTNORDER:
{
	this->processRtnOrder(&task);
	break;
}

case ONERRRTNORDERINSERT:
{
	this->processErrRtnOrderInsert(&task);
	break;
}

case ONRSPORDERACTION:
{
	this->processRspOrderAction(&task);
	break;
}

case ONERRRTNORDERACTION:
{
	this->processErrRtnOrderAction(&task);
	break;
}

case ONRTNTRADE:
{
	this->processRtnTrade(&task);
	break;
}

case ONRSPEXERCISEINSERT:
{
	this->processRspExerciseInsert(&task);
	break;
}

case ONRTNEXERCISE:
{
	this->processRtnExercise(&task);
	break;
}

case ONERRRTNEXERCISEINSERT:
{
	this->processErrRtnExerciseInsert(&task);
	break;
}

case ONRSPEXERCISEACTION:
{
	this->processRspExerciseAction(&task);
	break;
}

case ONERRRTNEXERCISEACTION:
{
	this->processErrRtnExerciseAction(&task);
	break;
}

case ONRSPLOCKINSERT:
{
	this->processRspLockInsert(&task);
	break;
}

case ONRTNLOCK:
{
	this->processRtnLock(&task);
	break;
}

case ONERRRTNLOCKINSERT:
{
	this->processErrRtnLockInsert(&task);
	break;
}

case ONRSPLOCKACTION:
{
	this->processRspLockAction(&task);
	break;
}

case ONERRRTNLOCKACTION:
{
	this->processErrRtnLockAction(&task);
	break;
}

case ONRTNSTOCKDISPOSAL:
{
	this->processRtnStockDisposal(&task);
	break;
}

case ONRSPCOMBORDERINSERT:
{
	this->processRspCombOrderInsert(&task);
	break;
}

case ONRTNCOMBORDER:
{
	this->processRtnCombOrder(&task);
	break;
}

case ONERRRTNCOMBORDERINSERT:
{
	this->processErrRtnCombOrderInsert(&task);
	break;
}

case ONRSPCOMBORDERACTION:
{
	this->processRspCombOrderAction(&task);
	break;
}

case ONERRRTNCOMBORDERACTION:
{
	this->processErrRtnCombOrderAction(&task);
	break;
}

case ONRSPCONDORDERINSERT:
{
	this->processRspCondOrderInsert(&task);
	break;
}

case ONRTNCONDORDER:
{
	this->processRtnCondOrder(&task);
	break;
}

case ONERRRTNCONDORDERINSERT:
{
	this->processErrRtnCondOrderInsert(&task);
	break;
}

case ONRSPCONDORDERACTION:
{
	this->processRspCondOrderAction(&task);
	break;
}

case ONERRRTNCONDORDERACTION:
{
	this->processErrRtnCondOrderAction(&task);
	break;
}

case ONRSPCOMBEXERCISEINSERT:
{
	this->processRspCombExerciseInsert(&task);
	break;
}

case ONRTNCOMBEXERCISE:
{
	this->processRtnCombExercise(&task);
	break;
}

case ONERRRTNCOMBEXERCISEINSERT:
{
	this->processErrRtnCombExerciseInsert(&task);
	break;
}

case ONRSPCOMBEXERCISEACTION:
{
	this->processRspCombExerciseAction(&task);
	break;
}

case ONERRRTNCOMBEXERCISEACTION:
{
	this->processErrRtnCombExerciseAction(&task);
	break;
}

case ONRSPINQUIRYMAXLOCKVOLUME:
{
	this->processRspInquiryMaxLockVolume(&task);
	break;
}

case ONRSPINQUIRYMAXCOVERVOLUME:
{
	this->processRspInquiryMaxCoverVolume(&task);
	break;
}

case ONRSPINQUIRYSPLITCOMBMARGINDIFFERENCE:
{
	this->processRspInquirySplitCombMarginDifference(&task);
	break;
}

case ONRSPTRANSFERFUND:
{
	this->processRspTransferFund(&task);
	break;
}

case ONRTNTRANSFERFUND:
{
	this->processRtnTransferFund(&task);
	break;
}

case ONERRRTNTRANSFERFUND:
{
	this->processErrRtnTransferFund(&task);
	break;
}

case ONRTNTRANSFERPOSITION:
{
	this->processRtnTransferPosition(&task);
	break;
}

case ONERRRTNTRANSFERPOSITION:
{
	this->processErrRtnTransferPosition(&task);
	break;
}

case ONRSPTRANSFERSTOCKPOSITION:
{
	this->processRspTransferStockPosition(&task);
	break;
}

case ONRTNTRANSFERSTOCKPOSITION:
{
	this->processRtnTransferStockPosition(&task);
	break;
}

case ONERRRTNTRANSFERSTOCKPOSITION:
{
	this->processErrRtnTransferStockPosition(&task);
	break;
}

case ONRSPINQUIRYJZFUND:
{
	this->processRspInquiryJZFund(&task);
	break;
}

case ONRSPINQUIRYBANKACCOUNTFUND:
{
	this->processRspInquiryBankAccountFund(&task);
	break;
}

case ONRSPINQUIRYSTOCKPOSITION:
{
	this->processRspInquiryStockPosition(&task);
	break;
}

case ONRTNMARKETSTATUS:
{
	this->processRtnMarketStatus(&task);
	break;
}

case ONRTNTRADINGNOTICE:
{
	this->processRtnTradingNotice(&task);
	break;
}

case ONRSPQRYEXCHANGE:
{
	this->processRspQryExchange(&task);
	break;
}

case ONRSPQRYMARKETDATA:
{
	this->processRspQryMarketData(&task);
	break;
}

case ONRSPQRYSECURITY:
{
	this->processRspQrySecurity(&task);
	break;
}

case ONRSPQRYBUPROXY:
{
	this->processRspQryBUProxy(&task);
	break;
}

case ONRSPQRYUSER:
{
	this->processRspQryUser(&task);
	break;
}

case ONRSPQRYINVESTOR:
{
	this->processRspQryInvestor(&task);
	break;
}

case ONRSPQRYSHAREHOLDERACCOUNT:
{
	this->processRspQryShareholderAccount(&task);
	break;
}

case ONRSPQRYTRADINGACCOUNT:
{
	this->processRspQryTradingAccount(&task);
	break;
}

case ONRSPQRYORDER:
{
	this->processRspQryOrder(&task);
	break;
}

case ONRSPQRYTRADE:
{
	this->processRspQryTrade(&task);
	break;
}

case ONRSPQRYPOSITION:
{
	this->processRspQryPosition(&task);
	break;
}

case ONRSPQRYTRADINGFEE:
{
	this->processRspQryTradingFee(&task);
	break;
}

case ONRSPQRYINVESTORTRADINGFEE:
{
	this->processRspQryInvestorTradingFee(&task);
	break;
}

case ONRSPQRYINVESTORMARGINFEE:
{
	this->processRspQryInvestorMarginFee(&task);
	break;
}

case ONRSPQRYORDERFUNDDETAIL:
{
	this->processRspQryOrderFundDetail(&task);
	break;
}

case ONRSPQRYFUNDTRANSFERDETAIL:
{
	this->processRspQryFundTransferDetail(&task);
	break;
}

case ONRSPQRYPOSITIONTRANSFERDETAIL:
{
	this->processRspQryPositionTransferDetail(&task);
	break;
}

case ONRSPQRYORDERACTION:
{
	this->processRspQryOrderAction(&task);
	break;
}

case ONRSPQRYSTOCKPOSITION:
{
	this->processRspQryStockPosition(&task);
	break;
}

case ONRSPQRYLOCK:
{
	this->processRspQryLock(&task);
	break;
}

case ONRSPQRYEXERCISE:
{
	this->processRspQryExercise(&task);
	break;
}

case ONRSPQRYLOCKPOSITION:
{
	this->processRspQryLockPosition(&task);
	break;
}

case ONRSPQRYEXERCISEACTION:
{
	this->processRspQryExerciseAction(&task);
	break;
}

case ONRSPQRYLOCKACTION:
{
	this->processRspQryLockAction(&task);
	break;
}

case ONRSPQRYSTOCKPOSITIONTRANSFERDETAIL:
{
	this->processRspQryStockPositionTransferDetail(&task);
	break;
}

case ONRSPQRYTRADINGNOTICE:
{
	this->processRspQryTradingNotice(&task);
	break;
}

case ONRSPQRYSTOCKDISPOSAL:
{
	this->processRspQryStockDisposal(&task);
	break;
}

case ONRSPQRYSTOCKDISPOSALACTION:
{
	this->processRspQryStockDisposalAction(&task);
	break;
}

case ONRSPQRYCONDORDER:
{
	this->processRspQryCondOrder(&task);
	break;
}

case ONRSPQRYCONDORDERACTION:
{
	this->processRspQryCondOrderAction(&task);
	break;
}

case ONRSPQRYINVESTORLIMITPOSITION:
{
	this->processRspQryInvestorLimitPosition(&task);
	break;
}

case ONRSPQRYINVESTORLIMITAMOUNT:
{
	this->processRspQryInvestorLimitAmount(&task);
	break;
}

case ONRSPQRYCOMBORDERACTION:
{
	this->processRspQryCombOrderAction(&task);
	break;
}

case ONRSPQRYCOMBORDER:
{
	this->processRspQryCombOrder(&task);
	break;
}

case ONRSPQRYCOMBPOSITION:
{
	this->processRspQryCombPosition(&task);
	break;
}

case ONRSPQRYCOMBPOSDETAIL:
{
	this->processRspQryCombPosDetail(&task);
	break;
}

case ONRSPQRYEXERCISEAPPOINTMENT:
{
	this->processRspQryExerciseAppointment(&task);
	break;
}

case ONRSPQRYINSUFFICIENTCOVEREDSTOCKPOSITION:
{
	this->processRspQryInsufficientCoveredStockPosition(&task);
	break;
}

case ONRSPQRYCOMBSECURITY:
{
	this->processRspQryCombSecurity(&task);
	break;
}

case ONRSPQRYCOMBEXERCISE:
{
	this->processRspQryCombExercise(&task);
	break;
}

case ONRSPQRYCOMBEXERCISEACTION:
{
	this->processRspQryCombExerciseAction(&task);
	break;
}

