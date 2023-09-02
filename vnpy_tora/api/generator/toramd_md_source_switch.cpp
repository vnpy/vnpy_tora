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

case ONRSPSUBMARKETDATA:
{
	this->processRspSubMarketData(&task);
	break;
}

case ONRSPUNSUBMARKETDATA:
{
	this->processRspUnSubMarketData(&task);
	break;
}

case ONRSPSUBPHMARKETDATA:
{
	this->processRspSubPHMarketData(&task);
	break;
}

case ONRSPUNSUBPHMARKETDATA:
{
	this->processRspUnSubPHMarketData(&task);
	break;
}

case ONRSPSUBSPECIALMARKETDATA:
{
	this->processRspSubSpecialMarketData(&task);
	break;
}

case ONRSPUNSUBSPECIALMARKETDATA:
{
	this->processRspUnSubSpecialMarketData(&task);
	break;
}

case ONRSPSUBSIMPLIFYMARKETDATA:
{
	this->processRspSubSimplifyMarketData(&task);
	break;
}

case ONRSPUNSUBSIMPLIFYMARKETDATA:
{
	this->processRspUnSubSimplifyMarketData(&task);
	break;
}

case ONRSPSUBSECURITYSTATUS:
{
	this->processRspSubSecurityStatus(&task);
	break;
}

case ONRSPUNSUBSECURITYSTATUS:
{
	this->processRspUnSubSecurityStatus(&task);
	break;
}

case ONRSPSUBMARKETSTATUS:
{
	this->processRspSubMarketStatus(&task);
	break;
}

case ONRSPUNSUBMARKETSTATUS:
{
	this->processRspUnSubMarketStatus(&task);
	break;
}

case ONRSPSUBIMCPARAMS:
{
	this->processRspSubImcParams(&task);
	break;
}

case ONRSPUNSUBIMCPARAMS:
{
	this->processRspUnSubImcParams(&task);
	break;
}

case ONRSPINQUIRYMARKETDATAMIRROR:
{
	this->processRspInquiryMarketDataMirror(&task);
	break;
}

case ONRSPINQUIRYPHMARKETDATAMIRROR:
{
	this->processRspInquiryPHMarketDataMirror(&task);
	break;
}

case ONRSPINQUIRYSPECIALMARKETDATAMIRROR:
{
	this->processRspInquirySpecialMarketDataMirror(&task);
	break;
}

case ONRSPSUBSPMARKETDATA:
{
	this->processRspSubSPMarketData(&task);
	break;
}

case ONRSPUNSUBSPMARKETDATA:
{
	this->processRspUnSubSPMarketData(&task);
	break;
}

case ONRSPSUBSPSIMPLIFYMARKETDATA:
{
	this->processRspSubSPSimplifyMarketData(&task);
	break;
}

case ONRSPUNSUBSPSIMPLIFYMARKETDATA:
{
	this->processRspUnSubSPSimplifyMarketData(&task);
	break;
}

case ONRSPSUBSPSECURITYSTATUS:
{
	this->processRspSubSPSecurityStatus(&task);
	break;
}

case ONRSPUNSUBSPSECURITYSTATUS:
{
	this->processRspUnSubSPSecurityStatus(&task);
	break;
}

case ONRSPSUBSPMARKETSTATUS:
{
	this->processRspSubSPMarketStatus(&task);
	break;
}

case ONRSPUNSUBSPMARKETSTATUS:
{
	this->processRspUnSubSPMarketStatus(&task);
	break;
}

case ONRSPINQUIRYSPMARKETDATAMIRROR:
{
	this->processRspInquirySPMarketDataMirror(&task);
	break;
}

case ONRTNMARKETDATA:
{
	this->processRtnMarketData(&task);
	break;
}

case ONRTNPHMARKETDATA:
{
	this->processRtnPHMarketData(&task);
	break;
}

case ONRTNSPECIALMARKETDATA:
{
	this->processRtnSpecialMarketData(&task);
	break;
}

case ONRTNSIMPLIFYMARKETDATA:
{
	this->processRtnSimplifyMarketData(&task);
	break;
}

case ONRTNSECURITYSTATUS:
{
	this->processRtnSecurityStatus(&task);
	break;
}

case ONRTNMARKETSTATUS:
{
	this->processRtnMarketStatus(&task);
	break;
}

case ONRTNIMCPARAMS:
{
	this->processRtnImcParams(&task);
	break;
}

case ONRTNSPMARKETDATA:
{
	this->processRtnSPMarketData(&task);
	break;
}

case ONRTNSPSIMPLIFYMARKETDATA:
{
	this->processRtnSPSimplifyMarketData(&task);
	break;
}

case ONRTNSPSECURITYSTATUS:
{
	this->processRtnSPSecurityStatus(&task);
	break;
}

case ONRTNSPMARKETSTATUS:
{
	this->processRtnSPMarketStatus(&task);
	break;
}

case ONRSPSUBRAPIDMARKETDATA:
{
	this->processRspSubRapidMarketData(&task);
	break;
}

case ONRSPUNSUBRAPIDMARKETDATA:
{
	this->processRspUnSubRapidMarketData(&task);
	break;
}

case ONRTNRAPIDMARKETDATA:
{
	this->processRtnRapidMarketData(&task);
	break;
}

