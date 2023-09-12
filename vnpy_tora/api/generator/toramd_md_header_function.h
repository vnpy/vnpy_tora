int join();

int reqGetConnectionInfo(int nrequestid);

int reqUserLogin(const dict &req, int nrequestid);

int reqUserLogout(const dict &req, int nrequestid);

int subscribeMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribePHMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribePHMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribeSpecialMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSpecialMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribeSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribeSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

int subscribeMarketStatus(string marketid);

int unSubscribeMarketStatus(string marketid);

int subscribeImcParams(string marketid);

int unSubscribeImcParams(string marketid);

int reqInquiryMarketDataMirror(const dict &req, int nrequestid);

int reqInquiryPHMarketDataMirror(const dict &req, int nrequestid);

int reqInquirySpecialMarketDataMirror(const dict &req, int nrequestid);

int subscribeSPMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSPMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribeSPSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSPSimplifyMarketData(string ppsecurityid, int ncount, string exchangeid);

int subscribeSPSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeSPSecurityStatus(string ppsecurityid, int ncount, string exchangeid);

int subscribeSPMarketStatus(string marketid);

int unSubscribeSPMarketStatus(string marketid);

int reqInquirySPMarketDataMirror(const dict &req, int nrequestid);

int subscribeRapidMarketData(string ppsecurityid, int ncount, string exchangeid);

int unSubscribeRapidMarketData(string ppsecurityid, int ncount, string exchangeid);

