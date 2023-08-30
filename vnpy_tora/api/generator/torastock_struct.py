CTORATstpReqUserLoginField = {
    "UserRequestID": "int",
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
    "NodeRef": "int",
}

CTORATstpRspUserLoginField = {
    "UserRequestID": "int",
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
    "NodeRef": "int",
}

CTORATstpRspInfoField = {
    "ErrorID": "int",
    "ErrorMsg": "string",
}

CTORATstpUserLogoutField = {
    "UserRequestID": "int",
    "UserID": "string",
}

CTORATstpUserPasswordUpdateField = {
    "UserID": "string",
    "OldPassword": "string",
    "NewPassword": "string",
    "UserRequestID": "int",
}

CTORATstpReqInputDeviceSerialField = {
    "UserRequestID": "int",
    "UserID": "string",
    "DeviceID": "string",
    "CertSerial": "string",
    "DeviceType": "char",
}

CTORATstpRspInputDeviceSerialField = {
    "UserRequestID": "int",
    "UserID": "string",
}

CTORATstpInputOrderField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "Operway": "char",
    "OrderRef": "int",
    "LotType": "char",
    "OrderSysID": "string",
    "CondCheck": "char",
    "GTDate": "string",
    "ForceCloseReason": "char",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
    "DiscountCouponID": "int",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "LotType": "char",
    "GTDate": "string",
    "Operway": "char",
    "CondCheck": "char",
    "SInfo": "string",
    "IInfo": "int",
    "RequestID": "int",
    "FrontID": "int",
    "SessionID": "int",
    "OrderRef": "int",
    "OrderLocalID": "string",
    "OrderSysID": "string",
    "OrderStatus": "char",
    "OrderSubmitStatus": "char",
    "StatusMsg": "string",
    "VolumeTraded": "int",
    "VolumeCanceled": "int",
    "TradingDay": "string",
    "InsertUser": "string",
    "InsertDate": "string",
    "InsertTime": "string",
    "AcceptTime": "string",
    "CancelUser": "string",
    "CancelTime": "string",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "PbuID": "string",
    "Turnover": "double",
    "OrderType": "char",
    "UserProductInfo": "string",
    "ForceCloseReason": "char",
    "CreditQuotaID": "string",
    "CreditQuotaType": "char",
    "CreditDebtID": "string",
    "IPAddress": "string",
    "MacAddress": "string",
    "RtnFloatInfo": "double",
    "RtnIntInfo": "int",
    "RtnFloatInfo1": "double",
    "RtnFloatInfo2": "double",
    "RtnFloatInfo3": "double",
}

CTORATstpUserRefField = {
    "UserID": "string",
}

CTORATstpTradeField = {
    "ExchangeID": "char",
    "DepartmentID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TradeID": "string",
    "Direction": "char",
    "OrderSysID": "string",
    "OrderLocalID": "string",
    "Price": "double",
    "Volume": "int",
    "TradeDate": "string",
    "TradeTime": "string",
    "TradingDay": "string",
    "PbuID": "string",
    "OrderRef": "int",
    "AccountID": "string",
    "CurrencyID": "char",
}

CTORATstpInputOrderActionField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "FrontID": "int",
    "SessionID": "int",
    "OrderRef": "int",
    "OrderSysID": "string",
    "ActionFlag": "char",
    "OrderActionRef": "int",
    "CancelOrderSysID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpInputCondOrderField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "Operway": "char",
    "LotType": "char",
    "CondCheck": "char",
    "GTDate": "string",
    "ForceCloseReason": "char",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
    "DiscountCouponID": "int",
    "CondOrderRef": "int",
    "CondOrderID": "int",
    "SInfo": "string",
    "IInfo": "int",
    "TriggerOrderVolumeType": "char",
    "TriggerOrderPriceType": "char",
    "ContingentCondition": "char",
    "ConditionPrice": "double",
    "PriceTicks": "int",
    "VolumeMultiple": "int",
    "RelativeFrontID": "int",
    "RelativeSessionID": "int",
    "RelativeParam": "string",
    "AppendContingentCondition": "char",
    "AppendConditionPrice": "double",
    "AppendRelativeFrontID": "int",
    "AppendRelativeSessionID": "int",
    "AppendRelativeParam": "string",
}

CTORATstpConditionOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "Operway": "char",
    "LotType": "char",
    "CondCheck": "char",
    "GTDate": "string",
    "ForceCloseReason": "char",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
    "DiscountCouponID": "int",
    "CondOrderRef": "int",
    "CondOrderID": "int",
    "SInfo": "string",
    "IInfo": "int",
    "TriggerOrderVolumeType": "char",
    "TriggerOrderPriceType": "char",
    "ContingentCondition": "char",
    "ConditionPrice": "double",
    "PriceTicks": "int",
    "VolumeMultiple": "int",
    "RelativeFrontID": "int",
    "RelativeSessionID": "int",
    "RelativeParam": "string",
    "AppendContingentCondition": "char",
    "AppendConditionPrice": "double",
    "AppendRelativeFrontID": "int",
    "AppendRelativeSessionID": "int",
    "AppendRelativeParam": "string",
    "RequestID": "int",
    "TradingDay": "string",
    "CondOrderStatus": "char",
    "StatusMsg": "string",
    "InsertUser": "string",
    "InsertDate": "string",
    "InsertTime": "string",
    "ActiveDate": "string",
    "ActiveTime": "string",
    "CancelUser": "string",
    "CancelTime": "string",
    "FrontID": "int",
    "SessionID": "int",
    "DepartmentID": "string",
    "UserProductInfo": "string",
    "IPAddress": "string",
    "MacAddress": "string",
}

CTORATstpInputCondOrderActionField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "FrontID": "int",
    "SessionID": "int",
    "CondOrderRef": "int",
    "CondOrderID": "int",
    "ActionFlag": "char",
    "Operway": "char",
    "CondOrderActionRef": "int",
    "CancelCondOrderID": "int",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpInputNegoOrderField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "Contractor": "string",
    "ContractorInfo": "string",
    "ConfirmID": "string",
    "CounterpartyPbuID": "string",
    "OrderSysID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpNegoOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "Contractor": "string",
    "ContractorInfo": "string",
    "ConfirmID": "string",
    "CounterpartyPbuID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
    "RequestID": "int",
    "FrontID": "int",
    "SessionID": "int",
    "OrderLocalID": "string",
    "OrderSysID": "string",
    "OrderStatus": "char",
    "OrderSubmitStatus": "char",
    "StatusMsg": "string",
    "VolumeTraded": "int",
    "VolumeCanceled": "int",
    "TradingDay": "string",
    "InsertUser": "string",
    "InsertDate": "string",
    "InsertTime": "string",
    "AcceptTime": "string",
    "CancelUser": "string",
    "CancelTime": "string",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "PbuID": "string",
    "UserProductInfo": "string",
    "IPAddress": "string",
    "MacAddress": "string",
}

CTORATstpNegoTradeField = {
    "ExchangeID": "char",
    "DepartmentID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TradeID": "string",
    "Direction": "char",
    "OrderSysID": "string",
    "OrderLocalID": "string",
    "Price": "double",
    "Volume": "int",
    "TradeDate": "string",
    "TradeTime": "string",
    "TradingDay": "string",
    "PbuID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "CounterpartyPbuID": "string",
    "CounterpartyShareholderID": "string",
}

CTORATstpInputNegoOrderActionField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "OrderSysID": "string",
    "ActionFlag": "char",
    "CancelOrderSysID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpInputOrderExField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "Direction": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "Operway": "char",
    "OrderRef": "int",
    "LotType": "char",
    "OrderSysID": "string",
    "CondCheck": "char",
    "GTDate": "string",
    "ForceCloseReason": "char",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
    "DiscountCouponID": "int",
    "SInfo": "string",
    "IInfo": "int",
    "NodeRef": "int",
}

CTORATstpInputOrderActionExField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "FrontID": "int",
    "SessionID": "int",
    "OrderRef": "int",
    "OrderSysID": "string",
    "ActionFlag": "char",
    "OrderActionRef": "int",
    "CancelOrderSysID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
    "SecurityID": "string",
}

CTORATstpMarketStatusField = {
    "MarketID": "char",
    "MarketStatus": "char",
}

CTORATstpInputTransferFundField = {
    "UserRequestID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "ApplySerial": "int",
    "TransferDirection": "char",
    "Amount": "double",
    "BankID": "char",
    "AccountPassword": "string",
    "BankPassword": "string",
    "ExternalNodeID": "int",
    "CreditDebtID": "string",
    "ForceCloseReason": "char",
    "RealAmount": "double",
    "ForceFlag": "int",
}

CTORATstpTransferFundField = {
    "FundSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "TransferDirection": "char",
    "Amount": "double",
    "TransferStatus": "char",
    "OperatorID": "string",
    "OperateDate": "string",
    "OperateTime": "string",
    "BankAccountID": "string",
    "BankID": "char",
    "InvestorID": "string",
    "ExternalNodeID": "int",
    "ForceCloseReason": "char",
    "IPAddress": "string",
    "MacAddress": "string",
    "BusinessUnitID": "string",
}

CTORATstpInputTransferPositionField = {
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "SecurityID": "string",
    "ApplySerial": "int",
    "TransferDirection": "char",
    "Volume": "int",
    "TransferPositionType": "char",
    "UserRequestID": "int",
    "MarketID": "char",
    "ExternalNodeID": "int",
}

CTORATstpTransferPositionField = {
    "PositionSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "MarketID": "char",
    "SecurityID": "string",
    "TradingDay": "string",
    "TransferDirection": "char",
    "TransferPositionType": "char",
    "HistoryVolume": "int",
    "TodayBSVolume": "int",
    "TodayPRVolume": "int",
    "TodaySMVolume": "int",
    "TransferStatus": "char",
    "OperatorID": "string",
    "OperateDate": "string",
    "OperateTime": "string",
    "IPAddress": "string",
    "MacAddress": "string",
    "ExternalNodeID": "int",
}

CTORATstpPeripheryTransferPositionField = {
    "PositionSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "TransferDirection": "char",
    "ExchangeID": "char",
    "MarketID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TodayBSPos": "int",
    "TodayPRPos": "int",
    "HistoryPos": "int",
    "TradingDay": "string",
    "TransferReason": "string",
    "TransferStatus": "char",
    "OperateDate": "string",
    "OperateTime": "string",
    "RepealDate": "string",
    "RepealTime": "string",
    "RepealReason": "string",
    "StatusMsg": "string",
    "TodaySMPos": "int",
}

CTORATstpPeripheryTransferFundField = {
    "FundSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "TransferDirection": "char",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "Amount": "double",
    "InvestorID": "string",
    "TransferReason": "string",
    "TransferStatus": "char",
    "OperateDate": "string",
    "OperateTime": "string",
    "RepealDate": "string",
    "RepealTime": "string",
    "RepealReason": "string",
    "StatusMsg": "string",
    "BusinessUnitID": "string",
}

CTORATstpReqInquiryJZFundField = {
    "AccountID": "string",
    "CurrencyID": "char",
    "UserRequestID": "int",
    "DepartmentID": "string",
}

CTORATstpRspInquiryJZFundField = {
    "AccountID": "string",
    "CurrencyID": "char",
    "UsefulMoney": "double",
    "FetchLimit": "double",
    "UserRequestID": "int",
    "DepartmentID": "string",
}

CTORATstpReqInquiryBankAccountFundField = {
    "UserRequestID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "BankID": "char",
    "BankPassword": "string",
}

CTORATstpRspInquiryBankAccountFundField = {
    "UserRequestID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "BankID": "char",
    "BankAccountID": "string",
    "Balance": "double",
}

CTORATstpTradingNoticeField = {
    "NoticeSerial": "int",
    "InsertDate": "string",
    "InsertTime": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "Content": "string",
    "OperatorID": "string",
}

CTORATstpReqInquiryMaxOrderVolumeField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "SecurityID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "Direction": "char",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "LimitPrice": "double",
    "LotType": "char",
    "MaxVolume": "int",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
}

CTORATstpRspInquiryMaxOrderVolumeField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "SecurityID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "Direction": "char",
    "OrderPriceType": "char",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "LimitPrice": "double",
    "LotType": "char",
    "MaxVolume": "int",
    "CreditDebtID": "string",
    "CreditQuotaType": "char",
}

CTORATstpInquiryTradeConcentrationField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "MarketID": "char",
    "SecurityID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "AccountID": "string",
    "ShareholderID": "string",
    "ConcentrationRatio1": "double",
    "ConcentrationRatio2": "double",
}

CTORATstpReqModifyOpenPosCostField = {
    "UserRequestID": "int",
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "OpenPosCost": "double",
}

CTORATstpInputNodeFundAssignmentField = {
    "UserRequestID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "InvestorID": "string",
    "NodeID1": "int",
    "AmtRatio1": "double",
    "NodeID2": "int",
    "AmtRatio2": "double",
    "NodeID3": "int",
    "AmtRatio3": "double",
    "NodeID4": "int",
    "AmtRatio4": "double",
    "NodeID5": "int",
    "AmtRatio5": "double",
}

CTORATstpReqInquiryNodeFundAssignmentField = {
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "NodeID": "int",
    "UserRequestID": "int",
}

CTORATstpRspInquiryNodeFundAssignmentField = {
    "UserRequestID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "InvestorID": "string",
    "NodeID1": "int",
    "AmtRatio1": "double",
    "NodeID2": "int",
    "AmtRatio2": "double",
    "NodeID3": "int",
    "AmtRatio3": "double",
    "NodeID4": "int",
    "AmtRatio4": "double",
    "NodeID5": "int",
    "AmtRatio5": "double",
}

CTORATstpQryExchangeField = {
    "ExchangeID": "char",
}

CTORATstpExchangeField = {
    "ExchangeID": "char",
    "ExchangeName": "string",
    "TradingDay": "string",
    "DataSyncStatus": "char",
}

CTORATstpQrySecurityField = {
    "ExchangeID": "char",
    "SecurityID": "string",
    "ProductID": "char",
}

CTORATstpSecurityField = {
    "TradingDay": "string",
    "ExchangeID": "char",
    "SecurityID": "string",
    "SecurityName": "string",
    "ShortSecurityName": "string",
    "UnderlyingSecurityID": "string",
    "MarketID": "char",
    "ProductID": "char",
    "SecurityType": "char",
    "OrderUnit": "char",
    "LimitBuyTradingUnit": "int",
    "MaxLimitOrderBuyVolume": "int",
    "MinLimitOrderBuyVolume": "int",
    "LimitSellTradingUnit": "int",
    "MaxLimitOrderSellVolume": "int",
    "MinLimitOrderSellVolume": "int",
    "MarketBuyTradingUnit": "int",
    "MaxMarketOrderBuyVolume": "int",
    "MinMarketOrderBuyVolume": "int",
    "MarketSellTradingUnit": "int",
    "MaxMarketOrderSellVolume": "int",
    "MinMarketOrderSellVolume": "int",
    "FixPriceBuyTradingUnit": "int",
    "MaxFixPriceOrderBuyVolume": "int",
    "MinFixPriceOrderBuyVolume": "int",
    "FixPriceSellTradingUnit": "int",
    "MaxFixPriceOrderSellVolume": "int",
    "MinFixPriceOrderSellVolume": "int",
    "VolumeMultiple": "int",
    "PriceTick": "double",
    "OpenDate": "string",
    "ParValue": "double",
    "SecurityStatus": "long long",
    "BondInterest": "double",
    "ConversionRate": "double",
    "TotalEquity": "double",
    "CirculationEquity": "double",
    "bPriceLimit": "int",
    "PreClosePrice": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
}

CTORATstpQryIPOInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpIPOInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
    "MarketID": "char",
    "ProductID": "char",
    "SecurityType": "char",
    "MinPrice": "double",
    "CurrencyID": "char",
    "SecurityName": "string",
    "UnderlyingSecurityID": "string",
    "UnderlyingSecurityName": "string",
    "MinVolume": "int",
    "MaxVolume": "int",
    "VolumeUnit": "int",
    "IssueMode": "char",
    "TradingDay": "string",
    "MaxPrice": "double",
}

CTORATstpQryUserField = {
    "UserID": "string",
    "UserType": "char",
}

CTORATstpUserField = {
    "UserID": "string",
    "UserName": "string",
    "UserType": "char",
    "DepartmentID": "string",
    "LoginLimit": "int",
    "LoginStatus": "char",
    "OpenDate": "string",
    "CloseDate": "string",
    "OrderInsertCommFlux": "int",
    "OrderActionCommFlux": "int",
}

CTORATstpQryInvestorField = {
    "InvestorID": "string",
}

CTORATstpInvestorField = {
    "InvestorID": "string",
    "InvestorType": "char",
    "InvestorName": "string",
    "IdCardType": "char",
    "IdCardNo": "string",
    "OpenDate": "string",
    "CloseDate": "string",
    "TradingStatus": "char",
    "Operways": "string",
    "Mobile": "string",
    "Telephone": "string",
    "Email": "string",
    "Fax": "string",
    "Address": "string",
    "ZipCode": "string",
    "ProfInvestorType": "char",
    "PlanType": "char",
    "AllowSelfSwitchPlan": "int",
    "Remark": "string",
}

CTORATstpQryShareholderAccountField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "ShareholderIDType": "char",
}

CTORATstpShareholderAccountField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "ShareholderIDType": "char",
    "MarketID": "char",
    "BSWhiteListCtl": "int",
    "MainFlag": "int",
}

CTORATstpQryRationalInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpRationalInfoField = {
    "TradingDay": "string",
    "ExchangeID": "char",
    "SecurityID": "string",
    "Price": "double",
    "MarketID": "char",
    "ProductID": "char",
    "SecurityType": "char",
    "SecurityName": "string",
    "UnderlyingSecurityID": "string",
    "UnderlyingSecurityName": "string",
    "MinVolume": "int",
    "MaxVolume": "int",
    "VolumeUnit": "int",
}

CTORATstpQryOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
    "OrderSysID": "string",
    "InsertTimeStart": "string",
    "InsertTimeEnd": "string",
    "SInfo": "string",
    "IInfo": "int",
    "IsCancel": "int",
}

CTORATstpQryOrderActionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "OrderLocalID": "string",
    "CancelOrderLocalID": "string",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpOrderActionField = {
    "ExchangeID": "char",
    "FrontID": "int",
    "SessionID": "int",
    "OrderRef": "int",
    "OrderSysID": "string",
    "ActionFlag": "char",
    "CancelOrderLocalID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
    "DepartmentID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "OrderLocalID": "string",
    "ActionUser": "string",
    "TradingDay": "string",
    "ActionDate": "string",
    "ActionTime": "string",
    "CancelOrderStatus": "char",
    "StatusMsg": "string",
    "RequestID": "int",
    "ActionFrontID": "int",
    "ActionSessionID": "int",
    "OrderActionRef": "int",
    "CancelOrderSysID": "string",
    "CancelOrderType": "char",
    "PbuID": "string",
    "IPAddress": "string",
    "MacAddress": "string",
}

CTORATstpQryTradeField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
    "TradeID": "string",
    "TradeTimeStart": "string",
    "TradeTimeEnd": "string",
}

CTORATstpQryTradingAccountField = {
    "InvestorID": "string",
    "CurrencyID": "char",
    "AccountID": "string",
    "AccountType": "char",
    "DepartmentID": "string",
}

CTORATstpTradingAccountField = {
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "PreDeposit": "double",
    "UsefulMoney": "double",
    "FetchLimit": "double",
    "PreUnDeliveredMoney": "double",
    "UnDeliveredMoney": "double",
    "Deposit": "double",
    "Withdraw": "double",
    "FrozenCash": "double",
    "UnDeliveredFrozenCash": "double",
    "FrozenCommission": "double",
    "UnDeliveredFrozenCommission": "double",
    "Commission": "double",
    "UnDeliveredCommission": "double",
    "AccountType": "char",
    "InvestorID": "string",
    "BankID": "char",
    "BankAccountID": "string",
    "RoyaltyIn": "double",
    "RoyaltyOut": "double",
    "CreditSellAmount": "double",
    "CreditSellUseAmount": "double",
    "VirtualAssets": "double",
    "CreditSellFrozenAmount": "double",
    "OwnerUnit": "string",
}

CTORATstpQryPositionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
}

CTORATstpPositionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "MarketID": "char",
    "ShareholderID": "string",
    "TradingDay": "string",
    "SecurityID": "string",
    "SecurityName": "string",
    "HistoryPos": "int",
    "HistoryPosFrozen": "int",
    "TodayBSPos": "int",
    "TodayBSPosFrozen": "int",
    "TodayPRPos": "int",
    "TodayPRPosFrozen": "int",
    "TodaySMPos": "int",
    "TodaySMPosFrozen": "int",
    "HistoryPosPrice": "double",
    "TotalPosCost": "double",
    "PrePosition": "int",
    "AvailablePosition": "int",
    "CurrentPosition": "int",
    "OpenPosCost": "double",
    "CreditBuyPos": "int",
    "CreditSellPos": "int",
    "TodayCreditSellPos": "int",
    "CollateralOutPos": "int",
    "RepayUntradeVolume": "int",
    "RepayTransferUntradeVolume": "int",
    "CollateralBuyUntradeAmount": "double",
    "CollateralBuyUntradeVolume": "int",
    "CreditBuyAmount": "double",
    "CreditBuyUntradeAmount": "double",
    "CreditBuyFrozenMargin": "double",
    "CreditBuyInterestFee": "double",
    "CreditBuyUntradeVolume": "int",
    "CreditSellAmount": "double",
    "CreditSellUntradeAmount": "double",
    "CreditSellFrozenMargin": "double",
    "CreditSellInterestFee": "double",
    "CreditSellUntradeVolume": "int",
    "CollateralInPos": "int",
    "CreditBuyFrozenCirculateMargin": "double",
    "CreditSellFrozenCirculateMargin": "double",
    "CloseProfit": "double",
    "TodayTotalOpenVolume": "int",
    "TodayCommission": "double",
    "TodayTotalBuyAmount": "double",
    "TodayTotalSellAmount": "double",
    "PreFrozen": "int",
}

CTORATstpQryTradingFeeField = {
    "ExchangeID": "char",
}

CTORATstpTradingFeeField = {
    "ExchangeID": "char",
    "ProductID": "char",
    "SecurityType": "char",
    "SecurityID": "string",
    "BizClass": "char",
    "StampTaxRatioByAmt": "double",
    "StampTaxRatioByPar": "double",
    "StampTaxFeePerOrder": "double",
    "StampTaxFeeByVolume": "double",
    "StampTaxFeeMin": "double",
    "StampTaxFeeMax": "double",
    "TransferRatioByAmt": "double",
    "TransferRatioByPar": "double",
    "TransferFeePerOrder": "double",
    "TransferFeeByVolume": "double",
    "TransferFeeMin": "double",
    "TransferFeeMax": "double",
    "HandlingRatioByAmt": "double",
    "HandlingRatioByPar": "double",
    "HandlingFeePerOrder": "double",
    "HandlingFeeByVolume": "double",
    "HandlingFeeMin": "double",
    "HandlingFeeMax": "double",
    "RegulateRatioByAmt": "double",
    "RegulateRatioByPar": "double",
    "RegulateFeePerOrder": "double",
    "RegulateFeeByVolume": "double",
    "RegulateFeeMin": "double",
    "RegulateFeeMax": "double",
    "SettlementRatioByAmt": "double",
    "SettlementRatioByPar": "double",
    "SettlementFeePerOrder": "double",
    "SettlementFeeByVolume": "double",
    "SettlementFeeMin": "double",
    "SettlementFeeMax": "double",
}

CTORATstpQryInvestorTradingFeeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "DepartmentID": "string",
}

CTORATstpInvestorTradingFeeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "ProductID": "char",
    "SecurityType": "char",
    "SecurityID": "string",
    "BizClass": "char",
    "BrokerageType": "char",
    "RatioByAmt": "double",
    "RatioByPar": "double",
    "FeePerOrder": "double",
    "FeeMin": "double",
    "FeeMax": "double",
    "FeeByVolume": "double",
    "DepartmentID": "string",
    "OrderType": "char",
}

CTORATstpQryIPOQuotaField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
}

CTORATstpIPOQuotaField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "MaxVolume": "long long",
    "KCMaxVolume": "long long",
}

CTORATstpQryOrderFundDetailField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "OrderSysID": "string",
}

CTORATstpOrderFundDetailField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "TradingDay": "string",
    "OrderSysID": "string",
    "PbuID": "string",
    "OrderLocalID": "string",
    "BusinessUnitID": "string",
    "AccountID": "string",
    "OrderAmount": "double",
    "Turnover": "double",
    "StampTaxFee": "double",
    "HandlingFee": "double",
    "TransferFee": "double",
    "RegulateFee": "double",
    "SettlementFee": "double",
    "BrokerageFee": "double",
    "TotalFee": "double",
    "OrderCashFrozen": "double",
    "EstimateCashFrozen": "double",
    "TotalFeeFrozen": "double",
    "TotalFrozen": "double",
    "Margin": "double",
    "RepayAmount": "double",
    "RepayVolume": "int",
    "MarginFrozen": "double",
    "CirculateMarginFrozen": "double",
}

CTORATstpQryFundTransferDetailField = {
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "InvestorID": "string",
    "TransferDirection": "char",
}

CTORATstpFundTransferDetailField = {
    "FundSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "AccountID": "string",
    "CurrencyID": "char",
    "TransferDirection": "char",
    "Amount": "double",
    "TransferStatus": "char",
    "OperateSource": "char",
    "OperatorID": "string",
    "OperateDate": "string",
    "OperateTime": "string",
    "StatusMsg": "string",
    "DepartmentID": "string",
    "BankID": "char",
    "BankAccountID": "string",
    "IPAddress": "string",
    "MacAddress": "string",
    "InvestorID": "string",
    "ExternalSerial": "string",
    "ExternalNodeID": "int",
    "ForceCloseReason": "char",
    "CreditDebtID": "string",
    "BusinessUnitID": "string",
    "BizRef": "string",
    "ExchangeRef": "char",
}

CTORATstpQryPositionTransferDetailField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TransferDirection": "char",
    "BusinessUnitID": "string",
}

CTORATstpPositionTransferDetailField = {
    "PositionSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "InvestorID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "MarketID": "char",
    "SecurityID": "string",
    "TradingDay": "string",
    "TransferDirection": "char",
    "TransferPositionType": "char",
    "TransferStatus": "char",
    "HistoryVolume": "int",
    "TodayBSVolume": "int",
    "TodayPRVolume": "int",
    "TodaySMVolume": "int",
    "OperatorID": "string",
    "OperateDate": "string",
    "OperateTime": "string",
    "BusinessUnitID": "string",
    "StatusMsg": "string",
    "IPAddress": "string",
    "MacAddress": "string",
    "ExternalNodeID": "int",
}

CTORATstpQryPeripheryPositionTransferDetailField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TransferDirection": "char",
    "BusinessUnitID": "string",
}

CTORATstpPeripheryPositionTransferDetailField = {
    "PositionSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "TransferDirection": "char",
    "ExchangeID": "char",
    "MarketID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "SecurityID": "string",
    "TodayBSPos": "int",
    "TodayPRPos": "int",
    "TodaySMPos": "int",
    "HistoryPos": "int",
    "TradingDay": "string",
    "TransferReason": "string",
    "TransferStatus": "char",
    "OperateDate": "string",
    "OperateTime": "string",
    "RepealDate": "string",
    "RepealTime": "string",
    "RepealReason": "string",
    "StatusMsg": "string",
}

CTORATstpQryPeripheryFundTransferDetailField = {
    "InvestorID": "string",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "TransferDirection": "char",
}

CTORATstpPeripheryFundTransferDetailField = {
    "FundSerial": "int",
    "ApplySerial": "int",
    "FrontID": "int",
    "SessionID": "int",
    "DepartmentID": "string",
    "AccountID": "string",
    "CurrencyID": "char",
    "TransferDirection": "char",
    "Amount": "double",
    "InvestorID": "string",
    "TransferStatus": "char",
    "TransferReason": "string",
    "OperateDate": "string",
    "OperateTime": "string",
    "RepealDate": "string",
    "RepealTime": "string",
    "RepealReason": "string",
    "StatusMsg": "string",
    "BusinessUnitID": "string",
}

CTORATstpQryBondConversionInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpBondConversionInfoField = {
    "ExchangeID": "char",
    "MarketID": "char",
    "SecurityID": "string",
    "ConvertOrderID": "string",
    "ConvertPrice": "double",
    "ConvertVolUnit": "int",
    "ConvertVolMax": "int",
    "ConvertVolMin": "int",
    "BeginDate": "string",
    "EndDate": "string",
    "ConvertName": "string",
}

CTORATstpQryBondPutbackInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpBondPutbackInfoField = {
    "ExchangeID": "char",
    "MarketID": "char",
    "SecurityID": "string",
    "PutbackOrderID": "string",
    "PutbackName": "string",
    "PutbackPrice": "double",
    "PutbackVolUnit": "int",
    "PutbackVolMax": "int",
    "PutbackVolMin": "int",
    "PutbackBeginDate": "string",
    "PutbackEndDate": "string",
    "RelieveBeginDate": "string",
    "RelieveEndDate": "string",
}

CTORATstpQryInvestorCondOrderLimitParamField = {
    "InvestorID": "string",
}

CTORATstpInvestorCondOrderLimitParamField = {
    "InvestorID": "string",
    "MaxCondOrderLimitCnt": "int",
    "CurrCondOrderCnt": "int",
}

CTORATstpQryConditionOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
    "CondOrderID": "int",
    "InsertTimeStart": "string",
    "InsertTimeEnd": "string",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpQryCondOrderActionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "CondOrderID": "int",
    "CancelCondOrderID": "int",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpCondOrderActionField = {
    "ExchangeID": "char",
    "FrontID": "int",
    "SessionID": "int",
    "CondOrderRef": "int",
    "CondOrderID": "int",
    "ActionFlag": "char",
    "Operway": "char",
    "CondOrderActionRef": "int",
    "CancelCondOrderID": "int",
    "SInfo": "string",
    "IInfo": "int",
    "RequestID": "int",
    "ActionFrontID": "int",
    "ActionSessionID": "int",
    "DepartmentID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "ActionUser": "string",
    "ActionDate": "string",
    "ActionTime": "string",
    "IPAddress": "string",
    "MacAddress": "string",
}

CTORATstpQryTradingNoticeField = {
    "InvestorID": "string",
    "InsertDateStart": "string",
    "InsertDateEnd": "string",
    "InsertTimeStart": "string",
    "InsertTimeEnd": "string",
}

CTORATstpQryIPONumberResultField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
}

CTORATstpIPONumberResultField = {
    "SecurityID": "string",
    "MarketID": "char",
    "ShareholderID": "string",
    "ExchangeID": "char",
    "Day": "string",
    "SecurityName": "string",
    "SecurityType": "char",
    "BeginNumberID": "string",
    "Volume": "int",
    "InvestorID": "string",
}

CTORATstpQryIPOMatchNumberResultField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "MatchNumberID": "string",
}

CTORATstpIPOMatchNumberResultField = {
    "SecurityID": "string",
    "MarketID": "char",
    "ShareholderID": "string",
    "MatchNumberID": "string",
    "ExchangeID": "char",
    "Day": "string",
    "SecurityName": "string",
    "SecurityType": "char",
    "Volume": "int",
    "Price": "double",
    "Amout": "double",
    "InvestorID": "string",
}

CTORATstpQryShareholderSpecPrivilegeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "ShareholderID": "string",
    "SpecPrivilegeType": "char",
    "Direction": "char",
    "MarketID": "char",
}

CTORATstpShareholderSpecPrivilegeField = {
    "ExchangeID": "char",
    "ShareholderID": "string",
    "MarketID": "char",
    "SpecPrivilegeType": "char",
    "Direction": "char",
    "bForbidden": "int",
    "InvestorID": "string",
}

CTORATstpQryMarketField = {
    "ExchangeID": "char",
    "MarketID": "char",
}

CTORATstpMarketField = {
    "MarketID": "char",
    "MarketName": "string",
    "ExchangeID": "char",
    "MarketStatus": "char",
}

CTORATstpQryETFFileField = {
    "ExchangeID": "char",
    "ETFSecurityID": "string",
    "ETFCreRedSecurityID": "string",
}

CTORATstpETFFileField = {
    "TradingDay": "string",
    "ExchangeID": "char",
    "ETFSecurityID": "string",
    "ETFCreRedSecurityID": "string",
    "CreationRedemptionUnit": "int",
    "Maxcashratio": "double",
    "EstimateCashComponent": "double",
    "CashComponent": "double",
    "NAV": "double",
    "NAVperCU": "double",
    "DividendPerCU": "double",
    "ETFCreRedType": "char",
    "ETFSecurityName": "string",
}

CTORATstpQryETFBasketField = {
    "ExchangeID": "char",
    "ETFSecurityID": "string",
    "SecurityID": "string",
}

CTORATstpETFBasketField = {
    "TradingDay": "string",
    "ExchangeID": "char",
    "ETFSecurityID": "string",
    "SecurityID": "string",
    "SecurityName": "string",
    "Volume": "int",
    "ETFCurrenceReplaceStatus": "char",
    "Premium": "double",
    "CreationReplaceAmount": "double",
    "RedemptionReplaceAmount": "double",
    "MarketID": "char",
    "ETFCreRedType": "char",
}

CTORATstpQryInvestorPositionLimitField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "SecurityID": "string",
}

CTORATstpInvestorPositionLimitField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "SecurityID": "string",
    "BuyLimit": "int",
    "BuyFrozen": "int",
    "SellLimit": "int",
    "SellFrozen": "int",
    "PurchaseLimit": "int",
    "PurchaseFrozen": "int",
    "RedeemLimit": "int",
    "RedeemFrozen": "int",
    "PledgeInLimit": "int",
    "PledgeInFrozen": "int",
    "PledgeOutLimit": "int",
    "PledgeOutFrozen": "int",
    "ConvertLimit": "int",
    "ConvertFrozen": "int",
    "PutbackLimit": "int",
    "PutbackFrozen": "int",
    "RationalLimit": "int",
    "RationalFrozen": "int",
    "TotalPositionLimit": "int",
    "TotalPositionFrozen": "int",
    "SplitLimit": "int",
    "SplitFrozen": "int",
    "MergeLimit": "int",
    "MergeFrozen": "int",
    "UUPIC": "string",
}

CTORATstpQrySZSEImcParamsField = {
    "MarketID": "char",
}

CTORATstpSZSEImcParamsField = {
    "MarketID": "char",
    "OpenFlag": "int",
    "ThresholdAmount": "double",
    "PosAmt": "double",
    "AmountStatus": "int",
}

CTORATstpQrySZSEImcExchangeRateField = {
    "FromCurrency": "char",
    "ToCurrency": "char",
}

CTORATstpSZSEImcExchangeRateField = {
    "FromCurrency": "char",
    "ToCurrency": "char",
    "BidRate": "double",
    "OfferRate": "double",
    "MidPointRate": "double",
}

CTORATstpQrySZSEHKPriceTickInfoField = {
    "PriceTickID": "char",
}

CTORATstpSZSEHKPriceTickInfoField = {
    "PriceTickID": "char",
    "PriceTickGroupID": "int",
    "PriceTickType": "char",
    "BeginPrice": "double",
    "EndPrice": "double",
    "PriceTick": "double",
}

CTORATstpQryLofFundInfoField = {
    "ExchangeID": "char",
    "FundID": "string",
    "MainFundID": "string",
}

CTORATstpLofFundInfoField = {
    "ExchangeID": "char",
    "FundID": "string",
    "MainFundID": "string",
    "FundType": "char",
    "SplitUnit": "int",
    "SplitMinVol": "int",
    "MergeUnit": "int",
    "MergeMinVol": "int",
    "FundRatio": "double",
}

CTORATstpQryPledgePositionField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "BusinessUnitID": "string",
}

CTORATstpPledgePositionField = {
    "SecurityID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "TradingDay": "string",
    "HisPledgePos": "int",
    "HisPledgePosFrozen": "int",
    "TodayPledgePos": "int",
    "TodayPledgePosFrozen": "int",
    "PreTotalPledgePos": "int",
    "PreAvailablePledgePos": "int",
}

CTORATstpQryPledgeInfoField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpPledgeInfoField = {
    "ExchangeID": "char",
    "MarketID": "char",
    "SecurityID": "string",
    "PledgeOrderID": "string",
    "PledgeName": "string",
    "StandardBondID": "string",
    "ConversionRate": "double",
    "PledgeInTradingUnit": "int",
    "PledgeOutTradingUnit": "int",
    "PledgeInVolMax": "int",
    "PledgeInVolMin": "int",
    "PledgeOutVolMax": "int",
    "PledgeOutVolMin": "int",
}

CTORATstpQrySystemNodeInfoField = {
    "NodeID": "int",
}

CTORATstpSystemNodeInfoField = {
    "NodeID": "int",
    "NodeInfo": "string",
    "bCurrent": "int",
}

CTORATstpQryStandardBondPositionField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "BusinessUnitID": "string",
}

CTORATstpStandardBondPositionField = {
    "SecurityID": "string",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "TradingDay": "string",
    "AvailablePosition": "int",
    "AvailablePosFrozen": "int",
    "TotalPosition": "int",
}

CTORATstpQryPrematurityRepoOrderField = {
    "InvestorID": "string",
    "SecurityID": "string",
    "ExchangeID": "char",
    "MarketID": "char",
    "ShareholderID": "string",
    "BusinessUnitID": "string",
    "OrderLocalID": "string",
    "ProductID": "char",
    "SecurityType": "char",
    "Direction": "char",
    "TradeID": "string",
}

CTORATstpPrematurityRepoOrderField = {
    "ExchangeID": "char",
    "MarketID": "char",
    "InvestorID": "string",
    "ShareholderID": "string",
    "BusinessUnitID": "string",
    "TradeDay": "string",
    "ExpireDay": "string",
    "OrderLocalID": "string",
    "SecurityID": "string",
    "SecurityName": "string",
    "ProductID": "char",
    "SecurityType": "char",
    "Direction": "char",
    "VolumeTraded": "int",
    "Price": "double",
    "Turnover": "double",
    "TradeID": "string",
    "RepoTotalMoney": "double",
    "InterestAmount": "double",
}

CTORATstpQryNegoOrderField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
    "OrderSysID": "string",
    "InsertTimeStart": "string",
    "InsertTimeEnd": "string",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpQryNegoOrderActionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "OrderLocalID": "string",
    "CancelOrderLocalID": "string",
    "SInfo": "string",
    "IInfo": "int",
}

CTORATstpNegoOrderActionField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "ShareholderID": "string",
    "ActionFlag": "char",
    "CancelOrderLocalID": "string",
    "CancelOrderSysID": "string",
    "OrderSysID": "string",
    "OrderLocalID": "string",
    "Operway": "char",
    "SInfo": "string",
    "IInfo": "int",
    "DepartmentID": "string",
    "ActionUser": "string",
    "TradingDay": "string",
    "ActionDate": "string",
    "ActionTime": "string",
    "CancelOrderStatus": "char",
    "StatusMsg": "string",
    "RequestID": "int",
    "ActionFrontID": "int",
    "ActionSessionID": "int",
    "PbuID": "string",
    "IPAddress": "string",
    "MacAddress": "string",
}

CTORATstpQryNegoTradeField = {
    "ExchangeID": "char",
    "InvestorID": "string",
    "BusinessUnitID": "string",
    "SecurityID": "string",
    "ShareholderID": "string",
    "TradeID": "string",
    "TradeTimeStart": "string",
    "TradeTimeEnd": "string",
}

CTORATstpQryNegotiationParamField = {
    "ExchangeID": "char",
    "SecurityID": "string",
}

CTORATstpNegotiationParamField = {
    "ExchangeID": "char",
    "SecurityID": "string",
    "BuyTradingUnit": "int",
    "SellTradingUnit": "int",
    "MinOrderVolume": "int",
    "MinOrderAmt": "double",
    "PriceTick": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "bMarketMaker": "int",
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
    "UserRequestID": "int",
    "InnerIPAddress": "string",
    "InnerPort": "int",
    "OuterIPAddress": "string",
    "OuterPort": "int",
    "MacAddress": "string",
}

