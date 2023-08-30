void ToraMdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void ToraMdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void ToraMdApi::processRspGetConnectionInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpConnectionInfoField *task_data = (CTORATstpConnectionInfoField*)task->task_data;
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["InnerPort"] = task_data->InnerPort;
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["OuterPort"] = task_data->OuterPort;
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGetConnectionInfo(data, error, task->task_id);
};

void ToraMdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRspUserLoginField *task_data = (CTORATstpRspUserLoginField*)task->task_data;
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["LogInAccount"] = toUtf(task_data->LogInAccount);
		data["LogInAccountType"] = task_data->LogInAccountType;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["MaxOrderRef"] = task_data->MaxOrderRef;
		data["PrivateFlowCount"] = task_data->PrivateFlowCount;
		data["PublicFlowCount"] = task_data->PublicFlowCount;
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["SystemName"] = toUtf(task_data->SystemName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["UserID"] = toUtf(task_data->UserID);
		data["UserName"] = toUtf(task_data->UserName);
		data["UserType"] = task_data->UserType;
		data["OrderInsertCommFlux"] = task_data->OrderInsertCommFlux;
		data["OrderActionCommFlux"] = task_data->OrderActionCommFlux;
		data["PasswordExpiryDate"] = toUtf(task_data->PasswordExpiryDate);
		data["NeedUpdatePassword"] = task_data->NeedUpdatePassword;
		data["CertSerial"] = toUtf(task_data->CertSerial);
		data["InnerIPAddress"] = toUtf(task_data->InnerIPAddress);
		data["OuterIPAddress"] = toUtf(task_data->OuterIPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id);
};

void ToraMdApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpUserLogoutField *task_data = (CTORATstpUserLogoutField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id);
};

void ToraMdApi::processRspSubMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubMarketData(data, error);
};

void ToraMdApi::processRspUnSubMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubMarketData(data, error);
};

void ToraMdApi::processRspSubPHMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubPHMarketData(data, error);
};

void ToraMdApi::processRspUnSubPHMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubPHMarketData(data, error);
};

void ToraMdApi::processRspSubSpecialMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSpecialMarketData(data, error);
};

void ToraMdApi::processRspUnSubSpecialMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSpecialMarketData(data, error);
};

void ToraMdApi::processRspSubSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSimplifyMarketData(data, error);
};

void ToraMdApi::processRspUnSubSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSimplifyMarketData(data, error);
};

void ToraMdApi::processRspSubSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSecurityStatus(data, error);
};

void ToraMdApi::processRspUnSubSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSecurityStatus(data, error);
};

void ToraMdApi::processRspSubMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubMarketStatus(data, error);
};

void ToraMdApi::processRspUnSubMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubMarketStatus(data, error);
};

void ToraMdApi::processRspSubImcParams(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubImcParams(data, error);
};

void ToraMdApi::processRspUnSubImcParams(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubImcParams(data, error);
};

void ToraMdApi::processRspInquiryMarketDataMirror(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField *task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryMarketDataMirror(data, error, task->task_id, task->task_last);
};

void ToraMdApi::processRspInquiryPHMarketDataMirror(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPHMarketDataField *task_data = (CTORATstpPHMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["BidVolume"] = task_data->BidVolume;
		data["AskVolume"] = task_data->AskVolume;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquiryPHMarketDataMirror(data, error, task->task_id, task->task_last);
};

void ToraMdApi::processRspInquirySpecialMarketDataMirror(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecialMarketDataField *task_data = (CTORATstpSpecialMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["MovingAvgPrice"] = task_data->MovingAvgPrice;
		data["MovingAvgPriceSamplingNum"] = task_data->MovingAvgPriceSamplingNum;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquirySpecialMarketDataMirror(data, error, task->task_id, task->task_last);
};

void ToraMdApi::processRspSubSPMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSPMarketData(data, error);
};

void ToraMdApi::processRspUnSubSPMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSPMarketData(data, error);
};

void ToraMdApi::processRspSubSPSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSPSimplifyMarketData(data, error);
};

void ToraMdApi::processRspUnSubSPSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSPSimplifyMarketData(data, error);
};

void ToraMdApi::processRspSubSPSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSPSecurityStatus(data, error);
};

void ToraMdApi::processRspUnSubSPSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSPSecurityStatus(data, error);
};

void ToraMdApi::processRspSubSPMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubSPMarketStatus(data, error);
};

void ToraMdApi::processRspUnSubSPMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificMarketField *task_data = (CTORATstpSpecificMarketField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubSPMarketStatus(data, error);
};

void ToraMdApi::processRspInquirySPMarketDataMirror(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField *task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspInquirySPMarketDataMirror(data, error, task->task_id, task->task_last);
};

void ToraMdApi::processRtnMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField *task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	this->onRtnMarketData(data);
};

void ToraMdApi::processRtnPHMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpPHMarketDataField *task_data = (CTORATstpPHMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["BidVolume"] = task_data->BidVolume;
		data["AskVolume"] = task_data->AskVolume;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		delete task_data;
	}
	this->onRtnPHMarketData(data);
};

void ToraMdApi::processRtnSpecialMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecialMarketDataField *task_data = (CTORATstpSpecialMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["MovingAvgPrice"] = task_data->MovingAvgPrice;
		data["MovingAvgPriceSamplingNum"] = task_data->MovingAvgPriceSamplingNum;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		delete task_data;
	}
	this->onRtnSpecialMarketData(data);
};

void ToraMdApi::processRtnSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSimplifyMarketDataField *task_data = (CTORATstpSimplifyMarketDataField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		delete task_data;
	}
	this->onRtnSimplifyMarketData(data);
};

void ToraMdApi::processRtnSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityStatusField *task_data = (CTORATstpSecurityStatusField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["IsSuspend"] = task_data->IsSuspend;
		data["IsBreak"] = task_data->IsBreak;
		data["IsLongSuspend"] = task_data->IsLongSuspend;
		data["IsCircuitBreak"] = task_data->IsCircuitBreak;
		data["IsSupportMarginBuy"] = task_data->IsSupportMarginBuy;
		data["IsSupportShortSell"] = task_data->IsSupportShortSell;
		data["IsSupportPur"] = task_data->IsSupportPur;
		data["IsSupportRed"] = task_data->IsSupportRed;
		data["IsSupportSplit"] = task_data->IsSupportSplit;
		data["IsSupportMerge"] = task_data->IsSupportMerge;
		data["IsSupportPleadgeIn"] = task_data->IsSupportPleadgeIn;
		data["IsSupportPleadgeOut"] = task_data->IsSupportPleadgeOut;
		data["IsSupportRoundLotBuy"] = task_data->IsSupportRoundLotBuy;
		data["IsSupportRoundLotSell"] = task_data->IsSupportRoundLotSell;
		data["IsSupportOddLotBuy"] = task_data->IsSupportOddLotBuy;
		data["IsSupportOddLotSell"] = task_data->IsSupportOddLotSell;
		data["IsSupportExercise"] = task_data->IsSupportExercise;
		data["IsLimitBuy"] = task_data->IsLimitBuy;
		data["IsLimitSell"] = task_data->IsLimitSell;
		data["IsLimitCover"] = task_data->IsLimitCover;
		data["IsLimitMarketMaker"] = task_data->IsLimitMarketMaker;
		delete task_data;
	}
	this->onRtnSecurityStatus(data);
};

void ToraMdApi::processRtnMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketStatusField *task_data = (CTORATstpMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnMarketStatus(data);
};

void ToraMdApi::processRtnImcParams(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpImcParamsField *task_data = (CTORATstpImcParamsField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["OpenFlag"] = task_data->OpenFlag;
		data["ThresholdAmount"] = task_data->ThresholdAmount;
		data["PosAmt"] = task_data->PosAmt;
		data["AmountStatus"] = task_data->AmountStatus;
		delete task_data;
	}
	this->onRtnImcParams(data);
};

void ToraMdApi::processRtnSPMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketDataField *task_data = (CTORATstpMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["TradingCount"] = task_data->TradingCount;
		data["LastPrice"] = task_data->LastPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PERatio1"] = task_data->PERatio1;
		data["PERatio2"] = task_data->PERatio2;
		data["PriceUpDown1"] = task_data->PriceUpDown1;
		data["PriceUpDown2"] = task_data->PriceUpDown2;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["HWLevel"] = task_data->HWLevel;
		data["PreCloseIOPV"] = task_data->PreCloseIOPV;
		data["IOPV"] = task_data->IOPV;
		delete task_data;
	}
	this->onRtnSPMarketData(data);
};

void ToraMdApi::processRtnSPSimplifyMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSimplifyMarketDataField *task_data = (CTORATstpSimplifyMarketDataField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["SecurityName"] = toUtf(task_data->SecurityName);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		delete task_data;
	}
	this->onRtnSPSimplifyMarketData(data);
};

void ToraMdApi::processRtnSPSecurityStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSecurityStatusField *task_data = (CTORATstpSecurityStatusField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["IsSuspend"] = task_data->IsSuspend;
		data["IsBreak"] = task_data->IsBreak;
		data["IsLongSuspend"] = task_data->IsLongSuspend;
		data["IsCircuitBreak"] = task_data->IsCircuitBreak;
		data["IsSupportMarginBuy"] = task_data->IsSupportMarginBuy;
		data["IsSupportShortSell"] = task_data->IsSupportShortSell;
		data["IsSupportPur"] = task_data->IsSupportPur;
		data["IsSupportRed"] = task_data->IsSupportRed;
		data["IsSupportSplit"] = task_data->IsSupportSplit;
		data["IsSupportMerge"] = task_data->IsSupportMerge;
		data["IsSupportPleadgeIn"] = task_data->IsSupportPleadgeIn;
		data["IsSupportPleadgeOut"] = task_data->IsSupportPleadgeOut;
		data["IsSupportRoundLotBuy"] = task_data->IsSupportRoundLotBuy;
		data["IsSupportRoundLotSell"] = task_data->IsSupportRoundLotSell;
		data["IsSupportOddLotBuy"] = task_data->IsSupportOddLotBuy;
		data["IsSupportOddLotSell"] = task_data->IsSupportOddLotSell;
		data["IsSupportExercise"] = task_data->IsSupportExercise;
		data["IsLimitBuy"] = task_data->IsLimitBuy;
		data["IsLimitSell"] = task_data->IsLimitSell;
		data["IsLimitCover"] = task_data->IsLimitCover;
		data["IsLimitMarketMaker"] = task_data->IsLimitMarketMaker;
		delete task_data;
	}
	this->onRtnSPSecurityStatus(data);
};

void ToraMdApi::processRtnSPMarketStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpMarketStatusField *task_data = (CTORATstpMarketStatusField*)task->task_data;
		data["MarketID"] = task_data->MarketID;
		data["MarketStatus"] = task_data->MarketStatus;
		delete task_data;
	}
	this->onRtnSPMarketStatus(data);
};

void ToraMdApi::processRspSubRapidMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubRapidMarketData(data, error);
};

void ToraMdApi::processRspUnSubRapidMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpSpecificSecurityField *task_data = (CTORATstpSpecificSecurityField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTORATstpRspInfoField *task_error = (CTORATstpRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUnSubRapidMarketData(data, error);
};

void ToraMdApi::processRtnRapidMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTORATstpRapidMarketDataField *task_data = (CTORATstpRapidMarketDataField*)task->task_data;
		data["SecurityID"] = toUtf(task_data->SecurityID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["DataTimeStamp"] = task_data->DataTimeStamp;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["NumTrades"] = task_data->NumTrades;
		data["TotalVolumeTrade"] = task_data->TotalVolumeTrade;
		data["TotalValueTrade"] = task_data->TotalValueTrade;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["LastPrice"] = task_data->LastPrice;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice6"] = task_data->AskPrice6;
		data["AskVolume6"] = task_data->AskVolume6;
		data["AskPrice7"] = task_data->AskPrice7;
		data["AskVolume7"] = task_data->AskVolume7;
		data["BidPrice6"] = task_data->BidPrice6;
		data["BidVolume6"] = task_data->BidVolume6;
		data["BidPrice7"] = task_data->BidPrice7;
		data["BidVolume7"] = task_data->BidVolume7;
		data["AskPrice8"] = task_data->AskPrice8;
		data["AskVolume8"] = task_data->AskVolume8;
		data["AskPrice9"] = task_data->AskPrice9;
		data["AskVolume9"] = task_data->AskVolume9;
		data["BidPrice8"] = task_data->BidPrice8;
		data["BidVolume8"] = task_data->BidVolume8;
		data["BidPrice9"] = task_data->BidPrice9;
		data["BidVolume9"] = task_data->BidVolume9;
		data["BidPrice10"] = task_data->BidPrice10;
		data["BidVolume10"] = task_data->BidVolume10;
		data["AskPrice10"] = task_data->AskPrice10;
		data["AskVolume10"] = task_data->AskVolume10;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["MDSecurityStat"] = task_data->MDSecurityStat;
		data["IOPV"] = task_data->IOPV;
		data["InnerSell"] = task_data->InnerSell;
		data["OuterBuy"] = task_data->OuterBuy;
		data["BidCount1"] = task_data->BidCount1;
		data["AskCount1"] = task_data->AskCount1;
		data["AskCount2"] = task_data->AskCount2;
		data["AskCount3"] = task_data->AskCount3;
		data["BidCount2"] = task_data->BidCount2;
		data["BidCount3"] = task_data->BidCount3;
		data["AskCount4"] = task_data->AskCount4;
		data["AskCount5"] = task_data->AskCount5;
		data["BidCount4"] = task_data->BidCount4;
		data["BidCount5"] = task_data->BidCount5;
		data["AskCount6"] = task_data->AskCount6;
		data["AskCount7"] = task_data->AskCount7;
		data["BidCount6"] = task_data->BidCount6;
		data["BidCount7"] = task_data->BidCount7;
		data["AskCount8"] = task_data->AskCount8;
		data["AskCount9"] = task_data->AskCount9;
		data["BidCount8"] = task_data->BidCount8;
		data["BidCount9"] = task_data->BidCount9;
		data["BidCount10"] = task_data->BidCount10;
		data["AskCount10"] = task_data->AskCount10;
		delete task_data;
	}
	this->onRtnRapidMarketData(data);
};

