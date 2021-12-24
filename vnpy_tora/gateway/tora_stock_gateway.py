from typing import Callable, Dict, Set, Tuple, Any, List
import pytz
from datetime import datetime
from vnpy.event.engine import Event

from vnpy.trader.gateway import BaseGateway
from vnpy.event import EventEngine
from vnpy.trader.event import EVENT_TIMER
from vnpy.trader.object import (
    TickData,
    OrderData,
    TradeData,
    PositionData,
    AccountData,
    ContractData,
    OrderRequest,
    CancelRequest,
    SubscribeRequest,
)

from vnpy.trader.constant import (
    Direction,
    Exchange,
    OrderType,
    Product,
    Status,
)

from vnpy_tora.api.stock import (
    traderapi,
    xmdapi,
    lev2mdapi,
    TORA_TSTP_D_Buy,
    TORA_TSTP_D_Sell,
    TORA_TSTP_EXD_SSE,
    TORA_TSTP_EXD_SZSE,
    TORA_TSTP_EXD_HK,
    TORA_TSTP_EXD_BSE,
    TORA_TSTP_OPT_LimitPrice,
    TORA_TSTP_OST_AllTraded,
    TORA_TSTP_OST_AllCanceled,
    TORA_TSTP_OST_Accepted,
    TORA_TSTP_OST_PartTradeCanceled,
    TORA_TSTP_OST_PartTraded,
    TORA_TSTP_OST_Rejected,
    TORA_TERT_RESTART,
    TORA_TSTP_LACT_UserID,
    TORA_TSTP_LACT_AccountID,
    TORA_TSTP_PID_SHBond,
    TORA_TSTP_PID_SHFund,
    TORA_TSTP_PID_SHStock,
    TORA_TSTP_PID_SZBond,
    TORA_TSTP_PID_SZFund,
    TORA_TSTP_PID_SZStock,
    TORA_TSTP_PID_BJStock,
    TORA_TSTP_TC_GFD,
    TORA_TSTP_VC_AV,
    TORA_TSTP_AF_Delete,
    CTORATstpQrySecurityField,
    CTORATstpQryInvestorField,
    CTORATstpQryShareholderAccountField,
    CTORATstpQryTradingAccountField,
    CTORATstpQryPositionField,
    CTORATstpQryOrderField,
    CTORATstpQryTradeField,
    CTORATstpInputOrderField,
    CTORATstpInputOrderActionField,
    CTORATstpRspUserLoginField,
    CTORATstpSpecificSecurityField,
    CTORATstpRspInfoField,
    CTORATstpMarketDataField,
    CTORATstpOrderField,
    CTORATstpTradeField,
    CTORATstpSecurityField,
    CTORATstpTradingAccountField,
    CTORATstpShareholderAccountField,
    CTORATstpInvestorField,
    CTORATstpPositionField,
    CTORATstpLev2MarketDataField,
    TORA_TSTP_PID_SHKC,
    TORA_TSTP_OST_Unknown
)
from .terminal_info import get_terminal_info


# 委托状态映射
ORDER_STATUS_TORA2VT: Dict[str, Status] = {
    TORA_TSTP_OST_AllTraded: Status.ALLTRADED,
    TORA_TSTP_OST_PartTraded: Status.PARTTRADED,
    TORA_TSTP_OST_Accepted: Status.NOTTRADED,
    TORA_TSTP_OST_AllCanceled: Status.CANCELLED,
    TORA_TSTP_OST_PartTradeCanceled: Status.CANCELLED,
    TORA_TSTP_OST_Unknown: Status.SUBMITTING,
    TORA_TSTP_OST_Rejected: Status.REJECTED,
}

# 委托类型映射
ORDER_TYPE_VT2TORA: Dict[OrderType, Tuple] = {
    OrderType.LIMIT: (TORA_TSTP_OPT_LimitPrice, TORA_TSTP_TC_GFD, TORA_TSTP_VC_AV),
}
ORDERTYPE_TORA2VT: Dict[str, OrderType] = {
    TORA_TSTP_OPT_LimitPrice: OrderType.LIMIT
}

# 交易所映射
EXCHANGE_TORA2VT: Dict[str, Exchange] = {
    TORA_TSTP_EXD_SSE: Exchange.SSE,
    TORA_TSTP_EXD_SZSE: Exchange.SZSE,
    TORA_TSTP_EXD_HK: Exchange.HKSE,
    TORA_TSTP_EXD_BSE: Exchange.BSE,
}
EXCHANGE_VT2TORA: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_TORA2VT.items()}

# 产品类型映射
PRODUCT_TORA2VT: Dict[str, Product] = {
    TORA_TSTP_PID_SHStock: Product.EQUITY,
    TORA_TSTP_PID_SHFund: Product.FUND,
    TORA_TSTP_PID_SHBond: Product.BOND,
    TORA_TSTP_PID_SZStock: Product.EQUITY,
    TORA_TSTP_PID_SZFund: Product.FUND,
    TORA_TSTP_PID_SZBond: Product.BOND,
    TORA_TSTP_PID_SHKC: Product.EQUITY,
    TORA_TSTP_PID_BJStock: Product.EQUITY,
}

# 多空方向映射
DIRECTION_TORA2VT: Dict[str, Direction] = {
    TORA_TSTP_D_Buy: Direction.LONG,
    TORA_TSTP_D_Sell: Direction.SHORT,
}
DIRECTION_VT2TORA: Dict[Direction, str] = {v: k for k, v in DIRECTION_TORA2VT.items()}


# 其他常量
CHINA_TZ = pytz.timezone("Asia/Shanghai")       # 中国时区


ACCOUNT_USERID = "用户代码"
ACCOUNT_ACCOUNTID = "资金账号"
ADDRESS_FRONT = "前置地址"
ADDRESS_FENS = "FENS地址"
LEVEL1 = "Level1"
LEVEL2 = "Level2"


class ToraStockGateway(BaseGateway):
    """
    vn.py用于对接华鑫奇点股票的交易接口。
    """

    default_setting: Dict[str, Any] = {
        "账号": "",
        "密码": "",
        "行情服务器": "",
        "交易服务器": "",
        "账号类型": [ACCOUNT_USERID, ACCOUNT_ACCOUNTID],
        "地址类型": [ADDRESS_FRONT, ADDRESS_FENS],
        "行情类型": [LEVEL1, LEVEL2]
    }

    exchanges: List[str] = list(EXCHANGE_VT2TORA.keys())

    def __init__(self, event_engine: EventEngine, gateway_name: str = "TORASTOCK") -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.td_api: "ToraTdApi" = ToraTdApi(self)
        self.md_api: "ToraL2Api / ToraMdApi" = None

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        if self.md_api:
            return

        mkt_type = setting["行情类型"]
        if mkt_type == LEVEL1:
            self.md_api: "ToraMdApi" = ToraMdApi(self)
        else:
            self.md_api: "ToraL2Api" = ToraL2Api(self)

        username: str = setting['账号']
        password: str = setting['密码']
        td_address: str = setting["交易服务器"]
        md_address: str = setting["行情服务器"]

        if not td_address.startswith("tcp://"):
            td_address = "tcp://" + td_address
        if not md_address.startswith("tcp://"):
            md_address = "tcp://" + md_address

        account_type: str = setting["账号类型"]
        address_type: str = setting["地址类型"]

        self.md_api.connect(username, password, md_address, account_type, address_type)
        self.td_api.connect(username, password, td_address, account_type, address_type)

        self.init_query()

    def close(self) -> None:
        """关闭接口"""
        pass

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscribe(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        return self.td_api.send_order(req)

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        self.td_api.query_accounts()

    def query_position(self) -> None:
        """查询持仓"""
        self.td_api.query_positions()

    def write_error(self, msg: str, error: CTORATstpRspInfoField):
        """输出错误信息日志"""
        error_id: int = error.ErrorID
        error_msg: str = error.ErrorMsg
        msg: str = f"{msg}，代码：{error_id}，信息：{error_msg}"
        self.write_log(msg)

    def process_timer_event(self, event: Event) -> None:
        """定时事件处理"""
        self.count += 1
        if self.count < 2:
            return
        self.count = 0

        func: Callable = self.query_functions.pop(0)
        func()
        self.query_functions.append(func)

        self.md_api.update_date()

    def init_query(self) -> None:
        """初始化查询任务"""
        self.count: int = 0
        self.query_functions: list = [self.query_account, self.query_position]
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)


class ToraMdApi(xmdapi.CTORATstpXMdSpi):

    def __init__(self, gateway: ToraStockGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: ToraStockGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0
        self.api: xmdapi.CTORATstpXMdApi_CreateTstpXMdApi = None

        self.connect_status: bool = False
        self.login_status: bool = False
        self.subscribed: Set = set()

        self.userid: str = ""
        self.password: str = ""
        self.address: str = ""

        self.current_date: str = datetime.now().strftime("%Y%m%d")

    def OnFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("行情服务器连接成功")
        self.login()

    def OnFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"行情服务器连接断开，原因{reason}")

    def OnRspUserLogin(
        self,
        data: CTORATstpRspUserLoginField,
        error: CTORATstpRspInfoField,
        reqid: int
    ) -> None:
        """用户登录请求回报"""
        if not error.ErrorID:
            self.login_status = True
            self.gateway.write_log("行情服务器登录成功")
        else:
            self.gateway.write_error("行情服务器登录失败", error)

    def OnRspSubMarketData(
        self,
        data: CTORATstpSpecificSecurityField,
        error: CTORATstpRspInfoField,
    ) -> None:
        """订阅行情回报"""
        if not error or not error.ErrorID:
            return

        self.gateway.write_error("行情订阅失败", error)

    def OnRtnMarketData(self, data: CTORATstpMarketDataField) -> None:
        """行情数据推送"""
        current_date: str = data.TradingDay
        current_time: str = data.UpdateTime
        dt: datetime = datetime.strptime(
            f'{current_date}-{current_time}', "%Y%m%d-%H:%M:%S"
        )
        dt: datetime = CHINA_TZ.localize(dt)
        tick: TickData = TickData(
            symbol=data.SecurityID,
            exchange=EXCHANGE_TORA2VT[data.ExchangeID],
            datetime=dt,
            name=data.SecurityName,
            turnover=data.Turnover,
            open_interest=data.OpenInterest,
            last_price=data.LastPrice,
            last_volume=data.Volume,
            limit_up=data.UpperLimitPrice,
            limit_down=data.LowerLimitPrice,
            open_price=data.OpenPrice,
            high_price=data.HighestPrice,
            low_price=data.LowestPrice,
            pre_close=data.PreClosePrice,
            bid_price_1=data.BidPrice1,
            ask_price_1=data.AskPrice1,
            bid_volume_1=data.BidVolume1,
            ask_volume_1=data.AskVolume1,
            gateway_name=self.gateway_name
        )

        if data.BidVolume2 or data.AskVolume2:
            tick.bid_price_2 = data.BidPrice2
            tick.bid_price_3 = data.BidPrice3
            tick.bid_price_4 = data.BidPrice4
            tick.bid_price_5 = data.BidPrice5
            tick.ask_price_2 = data.AskPrice2
            tick.ask_price_3 = data.AskPrice3
            tick.ask_price_4 = data.AskPrice4
            tick.ask_price_5 = data.AskPrice5

            tick.bid_volume_2 = data.BidVolume2
            tick.bid_volume_3 = data.BidVolume3
            tick.bid_volume_4 = data.BidVolume4
            tick.bid_volume_5 = data.BidVolume5

            tick.ask_volume_2 = data.AskVolume2
            tick.ask_volume_3 = data.AskVolume3
            tick.ask_volume_4 = data.AskVolume4
            tick.ask_volume_5 = data.AskVolume5

        self.gateway.on_tick(tick)

    def connect(
        self,
        userid: str,
        password: str,
        address: str,
        account_type: str,
        address_type: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.address = address
        self.account_type = account_type
        self.address_type = address_type

        # 禁止重复发起连接，会导致异常崩溃
        if not self.connect_status:
            self.api = xmdapi.CTORATstpXMdApi_CreateTstpXMdApi()
            self.api.RegisterSpi(self)

            if self.address_type == ADDRESS_FRONT:
                self.api.RegisterFront(address)
            else:
                self.api.RegisterNameServer(address)

            self.api.Init()
            self.connect_status = True

        elif not self.login_status:
            self.login()

    def login(self) -> None:
        """用户登录"""
        login_req = xmdapi.CTORATstpReqUserLoginField()

        self.reqid += 1
        self.api.ReqUserLogin(login_req, self.reqid)

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        if self.login_status:
            exchange: Exchange = EXCHANGE_VT2TORA[req.exchange]
            self.api.SubscribeMarketData([str.encode(req.symbol)], exchange)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()

    def update_date(self) -> None:
        """更新当前日期"""
        self.current_date: str = datetime.now().strftime("%Y%m%d")


class ToraL2Api(lev2mdapi.CTORATstpLev2MdSpi):
    """奇点Level2行情接口"""

    def __init__(self, gateway: ToraStockGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: ToraStockGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0
        self.api: lev2mdapi.CTORATstpLev2MdApi_CreateTstpLev2MdApi = None

        self.connect_status: bool = False
        self.login_status: bool = False
        self.subscribed: Set = set()

        self.userid: str = ""
        self.password: str = ""
        self.address: str = ""

        self.current_date: str = datetime.now().strftime("%Y%m%d")

    def OnFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("Level2行情服务器连接成功")
        self.login()

    def OnFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"Level2行情服务器连接断开，原因{reason}")

    def OnRspUserLogin(
        self,
        data: CTORATstpRspUserLoginField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.login_status = True
            self.gateway.write_log("Level2行情服务器登录成功")

        else:
            self.gateway.write_error("Level行情服务器登录失败", error)

    def OnRspSubMarketData(
        self,
        data: CTORATstpSpecificSecurityField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """订阅行情回报"""
        if not error or not error["ErrorID"]:
            return

        self.gateway.write_error("Level2行情订阅失败", error)

    def OnRtnMarketData(
        self,
        data: CTORATstpLev2MarketDataField,
        first_level_buy_num: int,
        first_level_buy_order_volumes: list,
        first_level_sell_num: int,
        first_level_sell_order_volumes: list
    ) -> None:
        """Level2行情数据推送"""
        current_date: datetime.date = datetime.today().strftime("%Y%m%d")
        current_datetime: str = str(data["DataTimeStamp"])
        if data["ExchangeID"] == TORA_TSTP_EXD_SSE:
            dt: datetime = datetime.strptime(
                f"{current_date}-{current_datetime[:2]}:{current_datetime[2:4]}:{current_datetime[4:6]}",
                "%Y%m%d-%H:%M:%S"
            )
        else:
            if current_datetime.startswith('1'):
                dt: datetime = datetime.strptime(
                    f"{current_date}-{current_datetime[:2]}:{current_datetime[2:4]}:{current_datetime[4:6]}",
                    "%Y%m%d-%H:%M:%S"
                )
            else:
                dt: datetime = datetime.strptime(
                    f"{current_date}-0{current_datetime[:1]}:{current_datetime[1:3]}:{current_datetime[3:5]}",
                    "%Y%m%d-%H:%M:%S"
                )
        dt: datetime = CHINA_TZ.localize(dt)

        tick: TickData = TickData(
            symbol=data["SecurityID"],
            exchange=EXCHANGE_TORA2VT[bytes.decode(data["ExchangeID"])],
            datetime=dt,
            name=data["SecurityID"],
            volume=data["TotalVolumeTrade"],
            turnover=data["TotalValueTrade"],
            last_price=data["LastPrice"],
            limit_up=data["UpperLimitPrice"],
            limit_down=data["LowerLimitPrice"],
            open_price=data["OpenPrice"],
            high_price=data["HighestPrice"],
            low_price=data["LowestPrice"],
            pre_close=data["PreClosePrice"],
            bid_price_1=data["BidPrice1"],
            ask_price_1=data["AskPrice1"],
            bid_volume_1=data["BidVolume1"],
            ask_volume_1=data["AskVolume1"],
            gateway_name=self.gateway_name
        )

        if data["BidVolume2"] or data["AskVolume2"]:
            tick.bid_price_2 = data["BidPrice2"]
            tick.bid_price_3 = data["BidPrice3"]
            tick.bid_price_4 = data["BidPrice4"]
            tick.bid_price_5 = data["BidPrice5"]

            tick.ask_price_2 = data["AskPrice2"]
            tick.ask_price_3 = data["AskPrice3"]
            tick.ask_price_4 = data["AskPrice4"]
            tick.ask_price_5 = data["AskPrice5"]

            tick.bid_volume_2 = data["BidVolume2"]
            tick.bid_volume_3 = data["BidVolume3"]
            tick.bid_volume_4 = data["BidVolume4"]
            tick.bid_volume_5 = data["BidVolume5"]

            tick.ask_volume_2 = data["AskVolume2"]
            tick.ask_volume_3 = data["AskVolume3"]
            tick.ask_volume_4 = data["AskVolume4"]
            tick.ask_volume_5 = data["AskVolume5"]

        self.gateway.on_tick(tick)

    def connect(
        self,
        userid: str,
        password: str,
        address: str,
        account_type: str,
        address_type: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.address = address
        self.account_type = account_type
        self.address_type = address_type

        # 禁止重复发起连接，否则会导致异常崩溃
        if not self.connect_status:
            self.api = lev2mdapi.CTORATstpLev2MdApi_CreateTstpLev2MdApi()
            self.api.RegisterSpi(self)

            if self.address_type == ADDRESS_FRONT:
                self.api.RegisterFront(address)
            else:
                self.api.RegisterNameServer

            self.api.Init()
            self.connect_status = True
        elif not self.login_status:
            self.login()

    def login(self) -> None:
        """用户登录"""
        login_reg = lev2mdapi.CTORATstpReqUserLoginField()

        self.reqid += 1
        self.api.ReqUserLogin(login_reg, self.reqid)

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        if self.login_status:
            exchange: Exchange = EXCHANGE_VT2TORA[req.exchange]
            self.api.SubscribeMarketData([str.encode(req.symbol)], exchange)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()

    def update_date(self) -> None:
        """更新当前日期"""
        self.current_date: str = datetime.now().strftime("%Y%m%d")


class ToraTdApi(traderapi.CTORATstpTraderSpi):
    """"""

    def __init__(self, gateway: ToraStockGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: ToraStockGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0
        self.order_ref: int = 0

        self.connect_status: bool = False
        self.login_status: bool = False
        self.auth_status: bool = False
        self.login_failed: bool = False

        self.investor_id: str = None
        self.shareholder_ids: Dict[Exchange, str] = {}
        self.account_id: str = None
        self.localid: int = 10000
        self.api: traderapi.CTORATstpTraderApi.CreateTstpTraderApi = None
        self.userid: str = ""
        self.password: str = ""
        self.frontid: int = 0
        self.sessionid: int = 0

        self.sysid_orderid_map: Dict[str, str] = {}

    def OnFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")
        self.login()

    def OnFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"交易服务器连接断开，原因{reason}")

    def OnRspUserLogin(
        self,
        data: CTORATstpRspUserLoginField,
        error: CTORATstpRspInfoField,
        reqid: int,
    ) -> None:
        """用户登录请求回报"""
        if not error.ErrorID:
            self.frontid = data.FrontID
            self.sessionid = data.SessionID
            self.login_status = True
            self.gateway.write_log("交易服务器登录成功")

            self.query_contracts()
            self.query_investors()
            self.query_shareholder_ids()
        else:
            self.login_failed = True

            self.gateway.write_error("交易服务器登录失败", error)

    def OnRspOrderAction(
        self,
        data: CTORATstpInputOrderActionField,
        error: CTORATstpRspInfoField,
        reqid: int,
    ) -> None:
        """委托撤单失败回报"""
        error_id: int = error.ErrorID
        if error_id:
            self.gateway.write_error("交易撤单失败", error)

    def OnRtnOrder(self, data: CTORATstpOrderField) -> None:
        """委托更新推送"""
        symbol: str = data.SecurityID
        exchange: Exchange = EXCHANGE_TORA2VT[data.ExchangeID]

        frontid: int = data.FrontID
        sessionid: int = data.SessionID
        order_ref: int = data.OrderRef
        order_id: str = f"{frontid}_{sessionid}_{order_ref}"

        timestamp: str = f"{data.InsertDate} {data.InsertTime}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt: datetime = CHINA_TZ.localize(dt)

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=exchange,
            orderid=order_id,
            type=ORDERTYPE_TORA2VT[data.OrderPriceType],
            direction=Direction.NET,
            price=data.LimitPrice,
            volume=data.VolumeTotalOriginal,
            traded=data.VolumeTraded,
            status=ORDER_STATUS_TORA2VT[data.OrderStatus],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.sysid_orderid_map[data.OrderSysID] = order_id

    def OnRtnTrade(self, data: CTORATstpTradeField) -> None:
        """成交数据推送"""
        symbol: str = data.SecurityID
        exchange: Exchange = EXCHANGE_TORA2VT[data.ExchangeID]

        orderid: str = self.sysid_orderid_map[data.OrderSysID]

        timestamp: str = f"{data.TradeDate} {data.TradeTime}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt: datetime = CHINA_TZ.localize(dt)

        trade: TradeData = TradeData(
            symbol=symbol,
            exchange=exchange,
            orderid=orderid,
            tradeid=data.TradeID,
            direction=Direction.NET,
            price=data.Price,
            volume=data.Volume,
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def OnRspQrySecurity(
        self,
        data: CTORATstpSecurityField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """合约查询回报"""
        if last:
            self.gateway.write_log("合约信息查询成功")
        if not data:
            return

        contract_data: ContractData = ContractData(
            gateway_name=self.gateway_name,
            symbol=data.SecurityID,
            exchange=EXCHANGE_TORA2VT[data.ExchangeID],
            name=data.SecurityName,
            product=PRODUCT_TORA2VT.get(data.ProductID, Product.EQUITY),
            size=data.VolumeMultiple,
            pricetick=data.PriceTick,
            min_volume=data.MinLimitOrderBuyVolume,
            net_position=True,
        )
        self.gateway.on_contract(contract_data)

    def OnRspQryTradingAccount(
        self,
        data: CTORATstpTradingAccountField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """资金查询回报"""
        if not data:
            return

        self.account_id: str = data.AccountID
        account_data: AccountData = AccountData(
            gateway_name=self.gateway_name,
            accountid=data.AccountID,
            balance=data.UsefulMoney,
            frozen=data.FrozenCash + data.FrozenCommission
        )
        self.gateway.on_account(account_data)

    def OnRspQryShareholderAccount(
        self,
        data: CTORATstpShareholderAccountField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """客户号查询回报"""
        if not data:
            return

        exchange: Exchange = EXCHANGE_TORA2VT[data.ExchangeID]
        self.shareholder_ids[exchange] = data.ShareholderID

    def OnRspQryInvestor(
        self,
        data: CTORATstpInvestorField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """用户名查询回报"""
        if not data:
            return
        self.investor_id: str = data.InvestorID

    def OnRspQryPosition(
        self,
        data: CTORATstpPositionField,
        error: CTORATstpRspInfoField,
        reqid: int,
        last: bool
    ) -> None:
        """持仓查询回报"""
        if not data:
            return

        if data.InvestorID != self.investor_id:
            self.gateway.write_log("OnRspQryPosition:收到其他账户的仓位信息")
            return

        volume: int = data.TodayBSPos
        if volume == 0:
            price = data.TotalPosCost / data.HistoryPos
        else:
            price = data.TotalPosCost / (volume + data.HistoryPos)

        frozen: int = data.HistoryPosFrozen + data.TodayBSPosFrozen + data.TodayPRPosFrozen
        position_data: PositionData = PositionData(
            gateway_name=self.gateway_name,
            symbol=data.SecurityID,
            exchange=EXCHANGE_TORA2VT[data.ExchangeID],
            direction=Direction.NET,
            volume=volume,
            frozen=frozen,
            price=price,
            yd_volume=data.HistoryPos,
        )
        self.gateway.on_position(position_data)

    def OnErrRtnOrderInsert(self, data: CTORATstpInputOrderField, error: CTORATstpRspInfoField, reason: int) -> None:
        """委托下单失败回报"""
        order_ref: int = data.OrderRef
        order_id: str = f"{self.frontid}_{self.sessionid}_{order_ref}"
        dt: datetime = datetime.now()
        dt: datetime = CHINA_TZ.localize(dt)

        order: OrderData = OrderData(
            symbol=data.SecurityID,
            exchange=EXCHANGE_TORA2VT[data.ExchangeID],
            orderid=order_id,
            type=ORDERTYPE_TORA2VT[data.OrderPriceType],
            direction=Direction.NET,
            price=data.LimitPrice,
            volume=data.VolumeTotalOriginal,
            status=Status.REJECTED,
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.gateway.write_log(
            f"拒单({order_id}):"
            f"错误码:{error.ErrorID}, 错误消息:{error.ErrorMsg}"
        )

    def connect(
        self,
        userid: str,
        password: str,
        address: str,
        account_type: str,
        address_type: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.address = address
        self.account_type = account_type
        self.address_type = address_type

        if not self.connect_status:
            self.api = traderapi.CTORATstpTraderApi.CreateTstpTraderApi()

            self.api.RegisterSpi(self)

            if self.address_type == ADDRESS_FRONT:
                self.api.RegisterFront(address)
            else:
                self.api.RegisterNameServer(address)

            self.api.SubscribePrivateTopic(TORA_TERT_RESTART)
            self.api.SubscribePublicTopic(TORA_TERT_RESTART)
            self.api.Init()
            self.connect_status = True

    def login(self) -> None:
        """用户登录"""
        login_req = traderapi.CTORATstpReqUserLoginField()
        login_req.LogInAccount = self.userid
        login_req.Password = self.password
        login_req.UserProductInfo = "vnpy_2.0"
        login_req.TerminalInfo = get_terminal_info()

        if self.account_type == ACCOUNT_USERID:
            login_req.LogInAccountType = TORA_TSTP_LACT_UserID
        else:
            login_req.LogInAccountType = TORA_TSTP_LACT_AccountID

        self.reqid += 1
        self.api.ReqUserLogin(login_req, self.reqid)

    def query_contracts(self) -> None:
        """查询合约"""
        req = CTORATstpQrySecurityField()
        self.reqid += 1
        self.api.ReqQrySecurity(req, self.reqid)

    def query_investors(self) -> None:
        """查询用户名"""
        req = CTORATstpQryInvestorField()
        self.reqid += 1
        self.api.ReqQryInvestor(req, self.reqid)

    def query_shareholder_ids(self) -> None:
        """查询客户号"""
        req = CTORATstpQryShareholderAccountField()
        self.reqid += 1
        self.api.ReqQryShareholderAccount(req, self.reqid)

    def query_accounts(self) -> None:
        """查询资金"""
        req = CTORATstpQryTradingAccountField()
        self.reqid += 1
        self.api.ReqQryTradingAccount(req, self.reqid)

    def query_positions(self) -> None:
        """查询持仓"""
        req = CTORATstpQryPositionField()
        self.reqid += 1
        self.api.ReqQryPosition(req, self.reqid)

    def query_orders(self) -> None:
        """查询未成交委托"""
        req = CTORATstpQryOrderField()
        self.reqid += 1
        self.api.ReqQryOrder(req, self.reqid)

    def query_trades(self) -> None:
        """查询成交"""
        req = CTORATstpQryTradeField()
        self.reqid += 1
        self.api.ReqQryTrade(req, self.reqid)

    def send_order(self, req: OrderRequest):
        """委托下单"""
        self.reqid += 1
        self.order_ref += 1

        opt, tc, vc = ORDER_TYPE_VT2TORA[req.type]

        info = CTORATstpInputOrderField()
        info.ShareholderID = self.shareholder_ids[req.exchange]
        info.SecurityID = req.symbol
        info.ExchangeID = EXCHANGE_VT2TORA[req.exchange]
        info.OrderRef = self.order_ref
        info.OrderPriceType = opt
        info.Direction = DIRECTION_VT2TORA[req.direction]
        info.LimitPrice = req.price
        info.VolumeTotalOriginal = int(req.volume)
        info.TimeCondition = tc
        info.VolumeCondition = vc

        self.api.ReqOrderInsert(info, self.reqid)

        order_id: str = f"{self.frontid}_{self.sessionid}_{self.order_ref}"
        order: OrderData = req.create_order_data(order_id, self.gateway_name)
        self.gateway.on_order(order)

        return f"{self.gateway_name}.{order_id}"

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.reqid += 1
        self.order_ref += 1

        info = CTORATstpInputOrderActionField()
        info.ExchangeID = EXCHANGE_VT2TORA[req.exchange]
        info.SecurityID = req.symbol

        frontid, sessionid, order_ref = req.orderid.split("_")
        info.OrderRef = int(order_ref)
        info.FrontID = int(frontid)
        info.SessionID = int(sessionid)
        info.ActionFlag = TORA_TSTP_AF_Delete
        info.OrderActionRef = self.order_ref

        self.api.ReqOrderAction(info, self.reqid)
