CTORATstpReqUserLoginField = {
    "LogInAccount": "string",
    "LogInAccountType": "char",
    "DepartmentID": "string",
    "AuthMode": "char",
    "Password": "string",
    "UserProductInfo": "string",
    "InterfaceProductInfo": "string",
    "TerminalInfo": "string",
    "InnerIPAddress": "string",
    "OuterIPAddress": "string",
    "MacAddress": "string",
    "Lang": "char",
    "DynamicPassword": "string",
    "DeviceID": "string",
    "CertSerial": "string",
    "DeviceType": "char",
}

CTORATstpRspUserLoginField = {
    "DepartmentID": "string",
    "LogInAccount": "string",
    "LogInAccountType": "char",
    "FrontID": "int",
    "SessionID": "int",
    "MaxOrderRef": "int",
    "PrivateFlowCount": "int",
    "PublicFlowCount": "int",
    "LoginTime": "string",
    "SystemName": "string",
    "TradingDay": "string",
    "UserID": "string",
    "UserName": "string",
    "UserType": "char",
    "OrderInsertCommFlux": "int",
    "OrderActionCommFlux": "int",
    "PasswordExpiryDate": "string",
    "NeedUpdatePassword": "int",
    "CertSerial": "string",
    "InnerIPAddress": "string",
    "OuterIPAddress": "string",
    "MacAddress": "string",
}

CTORATstpRspInfoField = {
    "ErrorID": "int",
    "ErrorMsg": "string",
}

CTORATstpUserLogoutField = {
    "UserID": "string",
}

CTORATstpSpecificSecurityField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpSpecificMarketField = {
    "MarketID": "char",
}

CTORATstpInquiryMarketDataField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpMarketDataField = {
    "TradingDay": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "SecurityName": "string",
    "PreClosePrice": "double",
    "OpenPrice": "double",
    "Volume": "long long",
    "Turnover": "double",
    "TradingCount": "long long",
    "LastPrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "BidPrice1": "double",
    "AskPrice1": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "PERatio1": "double",
    "PERatio2": "double",
    "PriceUpDown1": "double",
    "PriceUpDown2": "double",
    "OpenInterest": "double",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
    "BidPrice2": "double",
    "BidVolume2": "long long",
    "AskPrice2": "double",
    "AskVolume2": "long long",
    "BidPrice3": "double",
    "BidVolume3": "long long",
    "AskPrice3": "double",
    "AskVolume3": "long long",
    "BidPrice4": "double",
    "BidVolume4": "long long",
    "AskPrice4": "double",
    "AskVolume4": "long long",
    "BidPrice5": "double",
    "BidVolume5": "long long",
    "AskPrice5": "double",
    "AskVolume5": "long long",
    "UpdateTime": "string",
    "UpdateMillisec": "int",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "MDSecurityStat": "char",
    "HWLevel": "int",
    "PreCloseIOPV": "double",
    "IOPV": "double",
}

CTORATstpQryRspInfoField = {
    "EndFlag": "char",
    "ErrorID": "int",
    "ErrorMsg": "string",
}

CTORATstpPHMarketDataField = {
    "TradingDay": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "SecurityName": "string",
    "Volume": "long long",
    "Turnover": "double",
    "ClosePrice": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "BidVolume": "long long",
    "AskVolume": "long long",
    "UpdateTime": "string",
    "UpdateMillisec": "int",
    "MDSecurityStat": "char",
    "HWLevel": "int",
}

CTORATstpInquirySpecialMarketDataField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpSpecialMarketDataField = {
    "TradingDay": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "SecurityName": "string",
    "MovingAvgPrice": "double",
    "MovingAvgPriceSamplingNum": "int",
    "UpdateTime": "string",
    "UpdateMillisec": "int",
}

CTORATstpSimplifyMarketDataField = {
    "ExchangeID": "char",
    "SecurityID": "string",
    "SecurityName": "string",
    "PreClosePrice": "double",
    "LastPrice": "double",
    "BidPrice1": "double",
    "AskPrice1": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "UpdateTime": "string",
}

CTORATstpSecurityStatusField = {
    "ExchangeID": "char",
    "SecurityID": "string",
    "IsSuspend": "int",
    "IsBreak": "int",
    "IsLongSuspend": "int",
    "IsCircuitBreak": "int",
    "IsSupportMarginBuy": "int",
    "IsSupportShortSell": "int",
    "IsSupportPur": "int",
    "IsSupportRed": "int",
    "IsSupportSplit": "int",
    "IsSupportMerge": "int",
    "IsSupportPleadgeIn": "int",
    "IsSupportPleadgeOut": "int",
    "IsSupportRoundLotBuy": "int",
    "IsSupportRoundLotSell": "int",
    "IsSupportOddLotBuy": "int",
    "IsSupportOddLotSell": "int",
    "IsSupportExercise": "int",
    "IsLimitBuy": "int",
    "IsLimitSell": "int",
    "IsLimitCover": "int",
    "IsLimitMarketMaker": "int",
}

CTORATstpMarketStatusField = {
    "MarketID": "char",
    "MarketStatus": "char",
}

CTORATstpImcParamsField = {
    "MarketID": "char",
    "OpenFlag": "int",
    "ThresholdAmount": "double",
    "PosAmt": "double",
    "AmountStatus": "int",
}

CTORATstpRapidMarketDataField = {
    "SecurityID": "string",
    "ExchangeID": "char",
    "DataTimeStamp": "int",
    "PreClosePrice": "double",
    "OpenPrice": "double",
    "NumTrades": "long long",
    "TotalVolumeTrade": "long long",
    "TotalValueTrade": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "LastPrice": "double",
    "BidPrice1": "double",
    "BidVolume1": "long long",
    "AskPrice1": "double",
    "AskVolume1": "long long",
    "AskPrice2": "double",
    "AskVolume2": "long long",
    "AskPrice3": "double",
    "AskVolume3": "long long",
    "BidPrice2": "double",
    "BidVolume2": "long long",
    "BidPrice3": "double",
    "BidVolume3": "long long",
    "AskPrice4": "double",
    "AskVolume4": "long long",
    "AskPrice5": "double",
    "AskVolume5": "long long",
    "BidPrice4": "double",
    "BidVolume4": "long long",
    "BidPrice5": "double",
    "BidVolume5": "long long",
    "AskPrice6": "double",
    "AskVolume6": "long long",
    "AskPrice7": "double",
    "AskVolume7": "long long",
    "BidPrice6": "double",
    "BidVolume6": "long long",
    "BidPrice7": "double",
    "BidVolume7": "long long",
    "AskPrice8": "double",
    "AskVolume8": "long long",
    "AskPrice9": "double",
    "AskVolume9": "long long",
    "BidPrice8": "double",
    "BidVolume8": "long long",
    "BidPrice9": "double",
    "BidVolume9": "long long",
    "BidPrice10": "double",
    "BidVolume10": "long long",
    "AskPrice10": "double",
    "AskVolume10": "long long",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "ClosePrice": "double",
    "MDSecurityStat": "char",
    "IOPV": "double",
    "InnerSell": "long long",
    "OuterBuy": "long long",
    "BidCount1": "int",
    "AskCount1": "int",
    "AskCount2": "int",
    "AskCount3": "int",
    "BidCount2": "int",
    "BidCount3": "int",
    "AskCount4": "int",
    "AskCount5": "int",
    "BidCount4": "int",
    "BidCount5": "int",
    "AskCount6": "int",
    "AskCount7": "int",
    "BidCount6": "int",
    "BidCount7": "int",
    "AskCount8": "int",
    "AskCount9": "int",
    "BidCount8": "int",
    "BidCount9": "int",
    "BidCount10": "int",
    "AskCount10": "int",
}

CTORATstpFensUserInfoField = {
    "FensVer": "int",
    "FensEnvID": "string",
    "FensNodeID": "string",
    "FensUserID": "string",
    "UserID": "string",
    "ClientInfo": "string",
}

CTORATstpConnectionInfoField = {
    "InnerIPAddress": "string",
    "InnerPort": "int",
    "OuterIPAddress": "string",
    "OuterPort": "int",
    "MacAddress": "string",
}
