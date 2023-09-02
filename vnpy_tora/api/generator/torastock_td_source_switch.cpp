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

case ONRTNTRADE:
{
	this->processRtnTrade(&task);
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

case ONRSPNEGOORDERINSERT:
{
	this->processRspNegoOrderInsert(&task);
	break;
}

case ONRTNNEGOORDER:
{
	this->processRtnNegoOrder(&task);
	break;
}

case ONERRRTNNEGOORDERINSERT:
{
	this->processErrRtnNegoOrderInsert(&task);
	break;
}

case ONRTNNEGOTRADE:
{
	this->processRtnNegoTrade(&task);
	break;
}

case ONRSPNEGOORDERACTION:
{
	this->processRspNegoOrderAction(&task);
	break;
}

case ONERRRTNNEGOORDERACTION:
{
	this->processErrRtnNegoOrderAction(&task);
	break;
}

case ONRSPORDERINSERTEX:
{
	this->processRspOrderInsertEx(&task);
	break;
}

case ONRSPORDERACTIONEX:
{
	this->processRspOrderActionEx(&task);
	break;
}

case ONRTNMARKETSTATUS:
{
	this->processRtnMarketStatus(&task);
	break;
}

case ONRSPTRANSFERFUND:
{
	this->processRspTransferFund(&task);
	break;
}

case ONERRRTNTRANSFERFUND:
{
	this->processErrRtnTransferFund(&task);
	break;
}

case ONRTNTRANSFERFUND:
{
	this->processRtnTransferFund(&task);
	break;
}

case ONRSPTRANSFERPOSITION:
{
	this->processRspTransferPosition(&task);
	break;
}

case ONERRRTNTRANSFERPOSITION:
{
	this->processErrRtnTransferPosition(&task);
	break;
}

case ONRTNTRANSFERPOSITION:
{
	this->processRtnTransferPosition(&task);
	break;
}

case ONRTNPERIPHERYTRANSFERPOSITION:
{
	this->processRtnPeripheryTransferPosition(&task);
	break;
}

case ONRTNPERIPHERYTRANSFERFUND:
{
	this->processRtnPeripheryTransferFund(&task);
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

case ONRTNTRADINGNOTICE:
{
	this->processRtnTradingNotice(&task);
	break;
}

case ONRSPINQUIRYMAXORDERVOLUME:
{
	this->processRspInquiryMaxOrderVolume(&task);
	break;
}

case ONRSPINQUIRYTRADECONCENTRATION:
{
	this->processRspInquiryTradeConcentration(&task);
	break;
}

case ONRSPMODIFYOPENPOSCOST:
{
	this->processRspModifyOpenPosCost(&task);
	break;
}

case ONRSPINPUTNODEFUNDASSIGNMENT:
{
	this->processRspInputNodeFundAssignment(&task);
	break;
}

case ONRSPINQUIRYNODEFUNDASSIGNMENT:
{
	this->processRspInquiryNodeFundAssignment(&task);
	break;
}

case ONRSPQRYEXCHANGE:
{
	this->processRspQryExchange(&task);
	break;
}

case ONRSPQRYSECURITY:
{
	this->processRspQrySecurity(&task);
	break;
}

case ONRSPQRYIPOINFO:
{
	this->processRspQryIPOInfo(&task);
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

case ONRSPQRYRATIONALINFO:
{
	this->processRspQryRationalInfo(&task);
	break;
}

case ONRSPQRYORDER:
{
	this->processRspQryOrder(&task);
	break;
}

case ONRSPQRYORDERACTION:
{
	this->processRspQryOrderAction(&task);
	break;
}

case ONRSPQRYTRADE:
{
	this->processRspQryTrade(&task);
	break;
}

case ONRSPQRYTRADINGACCOUNT:
{
	this->processRspQryTradingAccount(&task);
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

case ONRSPQRYIPOQUOTA:
{
	this->processRspQryIPOQuota(&task);
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

case ONRSPQRYPERIPHERYPOSITIONTRANSFERDETAIL:
{
	this->processRspQryPeripheryPositionTransferDetail(&task);
	break;
}

case ONRSPQRYPERIPHERYFUNDTRANSFERDETAIL:
{
	this->processRspQryPeripheryFundTransferDetail(&task);
	break;
}

case ONRSPQRYBONDCONVERSIONINFO:
{
	this->processRspQryBondConversionInfo(&task);
	break;
}

case ONRSPQRYBONDPUTBACKINFO:
{
	this->processRspQryBondPutbackInfo(&task);
	break;
}

case ONRSPQRYINVESTORCONDORDERLIMITPARAM:
{
	this->processRspQryInvestorCondOrderLimitParam(&task);
	break;
}

case ONRSPQRYCONDITIONORDER:
{
	this->processRspQryConditionOrder(&task);
	break;
}

case ONRSPQRYCONDORDERACTION:
{
	this->processRspQryCondOrderAction(&task);
	break;
}

case ONRSPQRYTRADINGNOTICE:
{
	this->processRspQryTradingNotice(&task);
	break;
}

case ONRSPQRYIPONUMBERRESULT:
{
	this->processRspQryIPONumberResult(&task);
	break;
}

case ONRSPQRYIPOMATCHNUMBERRESULT:
{
	this->processRspQryIPOMatchNumberResult(&task);
	break;
}

case ONRSPQRYSHAREHOLDERSPECPRIVILEGE:
{
	this->processRspQryShareholderSpecPrivilege(&task);
	break;
}

case ONRSPQRYMARKET:
{
	this->processRspQryMarket(&task);
	break;
}

case ONRSPQRYETFFILE:
{
	this->processRspQryETFFile(&task);
	break;
}

case ONRSPQRYETFBASKET:
{
	this->processRspQryETFBasket(&task);
	break;
}

case ONRSPQRYINVESTORPOSITIONLIMIT:
{
	this->processRspQryInvestorPositionLimit(&task);
	break;
}

case ONRSPQRYSZSEIMCPARAMS:
{
	this->processRspQrySZSEImcParams(&task);
	break;
}

case ONRSPQRYSZSEIMCEXCHANGERATE:
{
	this->processRspQrySZSEImcExchangeRate(&task);
	break;
}

case ONRSPQRYSZSEHKPRICETICKINFO:
{
	this->processRspQrySZSEHKPriceTickInfo(&task);
	break;
}

case ONRSPQRYLOFFUNDINFO:
{
	this->processRspQryLofFundInfo(&task);
	break;
}

case ONRSPQRYPLEDGEPOSITION:
{
	this->processRspQryPledgePosition(&task);
	break;
}

case ONRSPQRYPLEDGEINFO:
{
	this->processRspQryPledgeInfo(&task);
	break;
}

case ONRSPQRYSYSTEMNODEINFO:
{
	this->processRspQrySystemNodeInfo(&task);
	break;
}

case ONRSPQRYSTANDARDBONDPOSITION:
{
	this->processRspQryStandardBondPosition(&task);
	break;
}

case ONRSPQRYPREMATURITYREPOORDER:
{
	this->processRspQryPrematurityRepoOrder(&task);
	break;
}

case ONRSPQRYNEGOORDER:
{
	this->processRspQryNegoOrder(&task);
	break;
}

case ONRSPQRYNEGOORDERACTION:
{
	this->processRspQryNegoOrderAction(&task);
	break;
}

case ONRSPQRYNEGOTRADE:
{
	this->processRspQryNegoTrade(&task);
	break;
}

case ONRSPQRYNEGOTIATIONPARAM:
{
	this->processRspQryNegotiationParam(&task);
	break;
}

