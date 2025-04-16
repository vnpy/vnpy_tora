import platform
from datetime import datetime
from pathlib import Path

from vnpy.event import EventEngine
from vnpy.trader.constant import (
    Direction,
    Exchange,
    OrderType,
    Product,
    Status,
    Offset,
    OptionType
)
from vnpy.trader.gateway import BaseGateway
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
from vnpy.trader.event import EVENT_TIMER
from vnpy.event.engine import Event
from vnpy.trader.utility import ZoneInfo, get_folder_path

from ..api import (
    MdApi,
    OptionApi,
    TORA_TSTP_LACT_AccountID,
    TORA_TSTP_SP_D_Buy,
    TORA_TSTP_SP_D_Sell,
    TORA_TSTP_SP_EXD_SSE,
    TORA_TSTP_SP_EXD_SZSE,
    TORA_TSTP_SP_OPT_LimitPrice,
    TORA_TSTP_SP_OST_AllTraded,
    TORA_TSTP_SP_OST_Cancelled,
    TORA_TSTP_SP_OST_Accepted,
    TORA_TSTP_SP_OST_PartTraded,
    TORA_TERT_RESTART,
    TORA_TSTP_SP_LACT_UserID,
    TORA_TSTP_SP_LACT_AccountID,
    TORA_TSTP_SP_PID_SHBond,
    TORA_TSTP_SP_PID_SHFund,
    TORA_TSTP_SP_PID_SHStock,
    TORA_TSTP_SP_PID_SZBond,
    TORA_TSTP_SP_PID_SZFund,
    TORA_TSTP_SP_PID_SZStock,
    TORA_TSTP_SP_TC_GFD,
    TORA_TSTP_SP_TC_IOC,
    TORA_TSTP_SP_VC_AV,
    TORA_TSTP_SP_OAF_Delete,
    TORA_TSTP_SP_HF_Speculation,
    TORA_TSTP_SP_OF_Open,
    TORA_TSTP_SP_OF_Close,
    TORA_TSTP_SP_PID_SHStockOption,
    TORA_TSTP_SP_PID_SZStockOption,
    TORA_TSTP_SP_OST_Handled,
    TORA_TSTP_SP_PD_Net,
    TORA_TSTP_SP_PD_Long,
    TORA_TSTP_SP_PD_Short,
    TORA_TSTP_SP_OST_Failed,
    TORA_TSTP_SP_CP_PutOptions,
    TORA_TSTP_SP_CP_CallOptions,
    TORA_TSTP_SP_OST_PartTradedCancelled
)
if platform.system() == "Linux":
    from .terminal_info_linux import get_terminal_info
else:
    from .terminal_info_windows import get_terminal_info


# 委托状态映射
ORDER_STATUS_TORA2VT: dict[str, Status] = {
    TORA_TSTP_SP_OST_AllTraded: Status.ALLTRADED,
    TORA_TSTP_SP_OST_PartTraded: Status.PARTTRADED,
    TORA_TSTP_SP_OST_Accepted: Status.NOTTRADED,
    TORA_TSTP_SP_OST_Cancelled: Status.CANCELLED,
    TORA_TSTP_SP_OST_Handled: Status.NOTTRADED,
    TORA_TSTP_SP_OST_Failed: Status.REJECTED,
    TORA_TSTP_SP_OST_PartTradedCancelled: Status.CANCELLED
}

# 委托类型映射
ORDER_TYPE_VT2TORA: dict[OrderType, tuple] = {
    OrderType.FOK: (
        TORA_TSTP_SP_OPT_LimitPrice, TORA_TSTP_SP_TC_IOC, TORA_TSTP_SP_VC_AV
    ),
    OrderType.FAK: (
        TORA_TSTP_SP_OPT_LimitPrice, TORA_TSTP_SP_TC_IOC, TORA_TSTP_SP_VC_AV
    ),
    OrderType.LIMIT: (
        TORA_TSTP_SP_OPT_LimitPrice, TORA_TSTP_SP_TC_GFD, TORA_TSTP_SP_VC_AV
    ),
}
ORDER_TYPE_TORA2VT: dict[tuple, OrderType] = {
    v: k for k, v in ORDER_TYPE_VT2TORA.items()
}
ORDERTYPE_TORA2VT: dict[str, OrderType] = {
    TORA_TSTP_SP_OPT_LimitPrice: OrderType.LIMIT
}

# 多空方向映射
DIRECTION_TORA2VT: dict[str, Direction] = {
    TORA_TSTP_SP_D_Buy: Direction.LONG,
    TORA_TSTP_SP_D_Sell: Direction.SHORT,
}
DIRECTION_VT2TORA: dict[Direction, str] = {v: k for k, v in DIRECTION_TORA2VT.items()}

# 交易所映射
EXCHANGE_TORA2VT: dict[str, Exchange] = {
    TORA_TSTP_SP_EXD_SSE: Exchange.SSE,
    TORA_TSTP_SP_EXD_SZSE: Exchange.SZSE,
}
EXCHANGE_VT2TORA: dict[Exchange, str] = {v: k for k, v in EXCHANGE_TORA2VT.items()}

# 产品类型映射
PRODUCT_TORA2VT: dict[str, Product] = {
    TORA_TSTP_SP_PID_SHStock: Product.EQUITY,
    TORA_TSTP_SP_PID_SHFund: Product.FUND,
    TORA_TSTP_SP_PID_SHBond: Product.BOND,
    TORA_TSTP_SP_PID_SZStock: Product.EQUITY,
    TORA_TSTP_SP_PID_SZFund: Product.FUND,
    TORA_TSTP_SP_PID_SZBond: Product.BOND,
    TORA_TSTP_SP_PID_SHStockOption: Product.OPTION,
    TORA_TSTP_SP_PID_SZStockOption: Product.OPTION,
}

# 持仓方向映射
POSITION_TORA2VT: dict[str, Direction] = {
    TORA_TSTP_SP_PD_Net: Direction.NET,
    TORA_TSTP_SP_PD_Long: Direction.LONG,
    TORA_TSTP_SP_PD_Short: Direction.SHORT,
}

# 开平方向映射
OFFSET_TORA2VT: dict[str, Offset] = {
    TORA_TSTP_SP_OF_Open: Offset.OPEN,
    TORA_TSTP_SP_OF_Close: Offset.CLOSE
}
OFFSET_VT2TORA: dict[Offset, str] = {v: k for k, v in OFFSET_TORA2VT.items()}

# 期权类型映射
OPTIONTYPE_TORA2VT: dict[str, OptionType] = {
    TORA_TSTP_SP_CP_CallOptions: OptionType.CALL,
    TORA_TSTP_SP_CP_PutOptions: OptionType.PUT
}

# 其他常量
CHINA_TZ = ZoneInfo("Asia/Shanghai")       # 中国时区


ACCOUNT_USERID: str = "用户代码"
ACCOUNT_ACCOUNTID: str = "资金账号"
ADDRESS_FRONT: str = "前置地址"
ADDRESS_FENS: str = "FENS地址"


class ToraOptionGateway(BaseGateway):
    """
    VeighNa用于对接华鑫奇点期权的交易接口。
    """

    default_name: str = "TORAOPTION"

    default_setting: dict = {
        "账号": "",
        "密码": "",
        "行情服务器": "",
        "交易服务器": "",
        "产品标识": "",
        "动态密钥": "",
        "账号类型": [ACCOUNT_USERID, ACCOUNT_ACCOUNTID],
        "地址类型": [ADDRESS_FRONT, ADDRESS_FENS]
    }

    exchanges: list[str] = list(EXCHANGE_VT2TORA.keys())

    def __init__(self, event_engine: EventEngine, gateway_name: str) -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.td_api: ToraTdApi = ToraTdApi(self)
        self.md_api: ToraMdApi = ToraMdApi(self)

        self.count: int = 0

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        username: str = setting['账号']
        password: str = setting['密码']
        product_info: str = setting["产品标识"]
        dynamic_password: str = setting["动态密钥"]
        td_address: str = setting["交易服务器"]
        md_address: str = setting["行情服务器"]

        if not td_address.startswith("tcp://"):
            td_address = "tcp://" + td_address
        if not md_address.startswith("tcp://"):
            md_address = "tcp://" + md_address

        account_type: str = setting["账号类型"]
        address_type: str = setting["地址类型"]

        self.md_api.connect(username, password, md_address, account_type, address_type, product_info)
        self.td_api.connect(username, password, td_address, account_type, address_type, product_info, dynamic_password)

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

    def write_error(self, msg: str, error: dict) -> None:
        """输出错误信息日志"""
        error_id: int = error["ErrorID"]
        error_msg: str = error["ErrorMsg"]
        msg = f"{msg}，代码：{error_id}，信息：{error_msg}"
        self.write_log(msg)

    def process_timer_event(self, event: Event) -> None:
        """定时事件处理"""
        self.count += 1
        if self.count < 2:
            return
        self.count = 0

        func = self.query_functions.pop(0)
        func()
        self.query_functions.append(func)

        self.md_api.update_date()

    def init_query(self) -> None:
        """初始化查询任务"""
        self.query_functions: list = [self.query_account, self.query_position]
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)


class ToraMdApi(MdApi):
    """"""

    def __init__(self, gateway: ToraOptionGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: ToraOptionGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0

        self.connect_status: bool = False
        self.login_status: bool = False
        self.subscribed: set = set()

        self.userid: str = ""
        self.password: str = ""
        self.account_type: str = ""
        self.product_info: str = ""

        self.current_date: str = datetime.now().strftime("%Y%m%d")

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("行情服务器连接成功")
        self.login()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"行情服务器连接断开，原因{reason}")

    def onRspUserLogin(self, data: dict, error: dict, reqid: int) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.login_status = True
            self.gateway.write_log("行情服务器登录成功")

        else:
            self.gateway.write_error("行情服务器登录失败", error)

    def onRspSubMarketData(
        self,
        data: dict,
        error: dict
    ) -> None:
        """订阅行情回报"""
        if not error or not error["ErrorID"]:
            return

        self.gateway.write_error("行情订阅失败", error)

    def onRtnSPMarketData(self, data: dict) -> None:
        """行情数据推送"""
        current_date: str = data["TradingDay"]
        current_time: str = data["UpdateTime"]
        dt: datetime = datetime.strptime(
            f'{current_date}-{current_time}', "%Y%m%d-%H:%M:%S"
        )
        dt = dt.replace(tzinfo=CHINA_TZ)

        tick: TickData = TickData(
            symbol=data["SecurityID"],
            exchange=EXCHANGE_TORA2VT[data["ExchangeID"]],
            datetime=dt,
            name=data["SecurityName"],
            open_interest=data["OpenInterest"],
            last_price=data["LastPrice"],
            last_volume=data["Volume"],
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
        address_type: str,
        product_info: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.account_type = account_type
        self.product_info = product_info

        # 禁止重复发起连接，会导致异常崩溃
        if not self.connect_status:
            self.createTstpXMdApi()

            if address_type == ADDRESS_FRONT:
                self.registerFront(address)
            else:
                self.registerNameServer(address)

            self.init()
            self.connect_status = True

        elif not self.login_status:
            self.login()

    def login(self) -> None:
        """用户登录"""
        tora_req: dict = {
            "LogInAccount": self.userid,
            "Password": self.password,
            "UserProductInfo": self.product_info,
            "TerminalInfo": get_terminal_info()
        }

        if self.account_type == ACCOUNT_USERID:
            tora_req["LogInAccountType"] = TORA_TSTP_SP_LACT_UserID
        else:
            tora_req["LogInAccountType"] = TORA_TSTP_SP_LACT_AccountID

        self.reqid += 1
        self.reqUserLogin(tora_req, self.reqid)

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        if self.login_status:
            exchange: Exchange = EXCHANGE_VT2TORA[req.exchange]
            self.subscribeSPMarketData(req.symbol, 1, exchange)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()

    def update_date(self) -> None:
        """更新当前日期"""
        self.current_date = datetime.now().strftime("%Y%m%d")


class ToraTdApi(OptionApi):
    """"""

    def __init__(self, gateway: ToraOptionGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: ToraOptionGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0

        self.connect_status: bool = False
        self.login_status: bool = False
        self.auth_status: bool = False
        self.login_failed: bool = False

        self.investor_id: str | None = None
        self.shareholder_ids: dict[Exchange, str] = {}
        self.account_id: str | None = None
        self.userid: str = ""
        self.password: str = ""
        self.account_type: str = ""
        self.product_info: str = ""

        self.sysid_orderid_map: dict[str, str] = {}
        self.orderid_sysid_map: dict[str, str] = {}

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")
        self.login()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"交易服务器连接断开，原因{reason}")

    def onRspUserLogin(
        self,
        data: dict,
        error: dict,
        reqid: int,
    ) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.login_status = True
            self.gateway.write_log("交易服务器登录成功")

            self.query_contracts()
            self.query_investors()
            self.query_shareholder_ids()

        else:
            self.login_failed = True

            self.gateway.write_error("交易服务器登录失败", error)

    def onRspOrderAction(
        self,
        data: dict,
        error: dict,
        reqid: int,
    ) -> None:
        """委托撤单失败回报"""
        error_id: int = error["ErrorID"]
        if error_id:
            self.gateway.write_error("交易撤单失败", error)

    def onRtnOrder(self, data: dict) -> None:
        """委托更新推送"""
        symbol: str = data["SecurityID"]
        exchange: Exchange = EXCHANGE_TORA2VT[data["ExchangeID"]]

        order_id: str = str(data["OrderRef"])

        timestamp: str = f"{data['InsertDate']} {data['InsertTime']}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt = dt.replace(tzinfo=CHINA_TZ)

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=exchange,
            orderid=order_id,
            type=ORDERTYPE_TORA2VT[data["OrderPriceType"]],
            direction=DIRECTION_TORA2VT[data["Direction"]],
            offset=OFFSET_TORA2VT[data["CombOffsetFlag"]],
            price=data["Price"],
            volume=data["VolumeTotalOriginal"],
            traded=data["VolumeTraded"],
            status=ORDER_STATUS_TORA2VT[data["OrderStatus"]],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.sysid_orderid_map[data["OrderSysID"]] = order_id
        self.orderid_sysid_map[order_id] = data["OrderSysID"]

    def onRtnTrade(self, data: dict) -> None:
        """成交数据推送"""
        symbol: str = data["SecurityID"]
        exchange: Exchange = EXCHANGE_TORA2VT[data["ExchangeID"]]

        orderid: str = self.sysid_orderid_map[data["OrderSysID"]]

        timestamp: str = f"{data['TradeDate']} {data['TradeTime']}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt = dt.replace(tzinfo=CHINA_TZ)

        trade: TradeData = TradeData(
            symbol=symbol,
            exchange=exchange,
            orderid=orderid,
            tradeid=data["TradeID"],
            direction=DIRECTION_TORA2VT[data["Direction"]],
            offset=OFFSET_TORA2VT[data["OffsetFlag"]],
            price=data["Price"],
            volume=data["Volume"],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def onRspQrySecurity(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """合约查询回报"""
        if last:
            self.gateway.write_log("合约信息查询成功")
        if not data:
            return

        contract: ContractData = ContractData(
            gateway_name=self.gateway_name,
            symbol=data["SecurityID"],
            exchange=EXCHANGE_TORA2VT[data["ExchangeID"]],
            name=data["SecurityName"],
            product=PRODUCT_TORA2VT.get(data["ProductID"], Product.EQUITY),
            size=data["UnderlyingMultiple"],  # 合约乘数错误
            pricetick=data["PriceTick"],
            min_volume=data["MinLimitOrderBuyVolume"],
        )

        contract.option_portfolio = data["UnderlyingSecurityID"] + "_O"
        contract.option_underlying = (
            data["UnderlyingSecurityID"]
            + "-"
            + str(data["LastDate"])
        )
        contract.option_type = OPTIONTYPE_TORA2VT[data["OptionsType"]]

        contract.option_strike = data["StrikePrice"]
        contract.option_expiry = datetime.strptime(
            str(data["LastDate"]), "%Y%m%d"
        )
        contract.option_index = get_option_index(
            contract.option_strike, data["ExchSecurityID"]
        )

        self.gateway.on_contract(contract)

    def onRspQryTradingAccount(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """资金查询回报"""
        if not data:
            return

        self.account_id = data["AccountID"]
        account_data: AccountData = AccountData(
            gateway_name=self.gateway_name,
            accountid=data["AccountID"],
            balance=data["UsefulMoney"],
            frozen=data["FrozenCash"] + data["FrozenMargin"] + data["FrozenCommission"]
        )
        self.gateway.on_account(account_data)

    def onRspQryShareholderAccount(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """客户号查询回报"""
        if not data:
            return

        exchange: Exchange = EXCHANGE_TORA2VT[data["ExchangeID"]]
        self.shareholder_ids[exchange] = data["ShareholderID"]

    def onRspQryInvestor(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """用户名查询回报"""
        if not data:
            return
        self.investor_id = data["InvestorID"]

    def onRspQryPosition(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """持仓查询回报"""
        if not data:
            return

        if data["InvestorID"] != self.investor_id:
            self.gateway.write_log("onRspQryPosition：收到其他账户的仓位信息")
            return

        volume: int = data["TodayPos"] + data["HistoryPos"]
        if volume == 0:
            price = 0
        else:
            price = data["TotalPosCost"] / volume

        frozen: int = data["HistoryPosFrozen"] + data["TodayPosFrozen"] + \
            data["LongFrozen"] + data["ShortFrozen"]

        position_data: PositionData = PositionData(
            gateway_name=self.gateway_name,
            symbol=data["SecurityID"],
            exchange=EXCHANGE_TORA2VT[data["ExchangeID"]],
            direction=POSITION_TORA2VT[data["PosiDirection"]],
            volume=volume,
            frozen=frozen,
            price=price,
            pnl=data["LastPrice"] * volume - data["TotalPosCost"],
            yd_volume=data["HistoryPos"],
        )
        self.gateway.on_position(position_data)

    def onErrRtnOrderInsert(self, data: dict, error: dict, reqid: int) -> None:
        """委托下单失败回报"""
        order_id: str = str(data["OrderRef"])
        dt: datetime = datetime.now()
        dt = dt.replace(tzinfo=CHINA_TZ)

        order: OrderData = OrderData(
            symbol=data["SecurityID"],
            exchange=EXCHANGE_TORA2VT[data["ExchangeID"]],
            orderid=order_id,
            type=ORDERTYPE_TORA2VT[data["OrderPriceType"]],
            direction=DIRECTION_TORA2VT[data["Direction"]],
            offset=OFFSET_TORA2VT[data["CombOffsetFlag"]],
            price=data["LimitPrice"],
            volume=data["VolumeTotalOriginal"],
            status=Status.REJECTED,
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.gateway.write_log(
            f"拒单({order_id}):"
            f"错误码:{error['ErrorID']}, 错误消息:{error['ErrorMsg']}"
        )

    def connect(
        self,
        userid: str,
        password: str,
        address: str,
        account_type: str,
        address_type: str,
        product_info: str,
        dynamic_password: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.account_type = account_type
        self.product_info = product_info
        self.dynamic_password = dynamic_password

        if not self.connect_status:
            path: Path = get_folder_path(self.gateway_name.lower())
            self.createTstpSPTraderApi((str(path) + "\\Opt").encode("GBK"), False)

            if address_type == ADDRESS_FRONT:
                self.registerFront(address)
            else:
                self.registerNameServer(address)

            self.subscribePrivateTopic(TORA_TERT_RESTART)
            self.subscribePublicTopic(TORA_TERT_RESTART)
            self.init()
            self.connect_status = True

    def login(self) -> None:
        """用户登录"""
        tora_req: dict = {
            "LogInAccount": self.userid,
            "Password": self.password,
            "UserProductInfo": self.product_info,
            "DynamicPassword": self.dynamic_password,
            "TerminalInfo": get_terminal_info()
        }

        if self.account_type == ACCOUNT_USERID:
            tora_req["LogInAccountType"] = TORA_TSTP_SP_LACT_UserID
        else:
            tora_req["LogInAccountType"] = TORA_TSTP_LACT_AccountID

        self.reqid += 1
        self.reqUserLogin(tora_req, self.reqid)

    def query_contracts(self) -> None:
        """查询合约"""
        self.reqid += 1
        self.reqQrySecurity({}, self.reqid)

    def query_investors(self) -> None:
        """查询用户名"""
        self.reqid += 1
        self.reqQryInvestor({}, self.reqid)

    def query_shareholder_ids(self) -> None:
        """查询客户号"""
        self.reqid += 1
        self.reqQryShareholderAccount({}, self.reqid)

    def query_accounts(self) -> None:
        """查询资金"""
        self.reqid += 1
        self.reqQryTradingAccount({}, self.reqid)

    def query_positions(self) -> None:
        """查询持仓"""
        self.reqid += 1
        self.reqQryPosition({}, self.reqid)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        if req.type not in ORDER_TYPE_VT2TORA:
            self.gateway.write_log(f"委托失败，不支持的委托类型{req.type.value}")
            return ""

        self.reqid += 1
        prefix: str = datetime.now().strftime("%H%M")
        suffix: str = str(self.reqid).rjust(5, "0")
        order_id: int = int(prefix + suffix)

        opt, tc, vc = ORDER_TYPE_VT2TORA[req.type]

        tora_req: dict = {
            "ShareholderID": self.shareholder_ids[req.exchange],
            "SecurityID": req.symbol,
            "ExchangeID": EXCHANGE_VT2TORA[req.exchange],
            "OrderRef": order_id,
            "OrderPriceType": opt,
            "Direction": DIRECTION_VT2TORA[req.direction],
            "CombOffsetFlag": OFFSET_VT2TORA[req.offset],
            "CombHedgeFlag": TORA_TSTP_SP_HF_Speculation,
            "LimitPrice": req.price,
            "VolumeTotalOriginal": int(req.volume),
            "TimeCondition": tc,
            "VolumeCondition": vc,
        }

        self.reqOrderInsert(tora_req, self.reqid)

        order: OrderData = req.create_order_data(str(order_id), self.gateway_name)
        self.gateway.on_order(order)

        return order.vt_orderid     # type: ignore

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        sysid: str | None= self.orderid_sysid_map.get(req.orderid, None)
        if not sysid:
            self.gateway.write_log(f"撤单失败，找不到{req.orderid}对应的系统委托号")
        self.reqid += 1

        tora_req: dict = {
            "InvestorID": self.investor_id,
            "ExchangeID": EXCHANGE_VT2TORA[req.exchange],
            "SecurityID": req.symbol,
            "OrderSysID": sysid,
            "OrderActionFlag": TORA_TSTP_SP_OAF_Delete,
        }

        self.reqOrderAction(tora_req, self.reqid)


def get_option_index(strike_price: float, exchange_instrument_id: str) -> str:
    """获取期权索引"""
    exchange_instrument_id = exchange_instrument_id.replace(" ", "")

    if "M" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("M")
    elif "A" in exchange_instrument_id:
        n = exchange_instrument_id.index("A")
    elif "B" in exchange_instrument_id:
        n = exchange_instrument_id.index("B")
    else:
        return str(strike_price)

    index: str = exchange_instrument_id[n:]
    option_index: str = f"{strike_price:.3f}-{index}"

    return option_index
