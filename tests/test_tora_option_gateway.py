from collections.abc import Callable
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_tora.api", reason="缺少 TORA 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    Offset,
    OrderType,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    OrderData,
    OrderRequest,
    PositionData,
    TickData,
)

from vnpy_tora.api import (  # noqa: E402
    TORA_TSTP_SP_D_Buy,
    TORA_TSTP_SP_EXD_SSE,
    TORA_TSTP_SP_HF_Speculation,
    TORA_TSTP_SP_OF_Open,
    TORA_TSTP_SP_OPT_LimitPrice,
    TORA_TSTP_SP_OST_Accepted,
    TORA_TSTP_SP_OST_AllTraded,
    TORA_TSTP_SP_OST_Cancelled,
    TORA_TSTP_SP_OST_Failed,
    TORA_TSTP_SP_OST_Handled,
    TORA_TSTP_SP_OST_PartTraded,
    TORA_TSTP_SP_OST_PartTradedCancelled,
    TORA_TSTP_SP_PD_Long,
    TORA_TSTP_SP_TC_GFD,
    TORA_TSTP_SP_VC_AV,
)
from vnpy_tora.gateway import tora_option_gateway  # noqa: E402
from vnpy_tora.gateway.tora_option_gateway import (  # noqa: E402
    ACCOUNT_USERID,
    ADDRESS_FRONT,
    CHINA_TZ,
    ToraMdApi,
    ToraOptionGateway,
    ToraTdApi,
)


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.orders: list[OrderData] = []
        self.positions: list[PositionData] = []

    def attach(self, gateway: ToraOptionGateway) -> None:
        gateway.write_log = self.logs.append
        gateway.on_tick = self.ticks.append
        gateway.on_order = self.orders.append
        gateway.on_position = self.positions.append


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, Any]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., int]:
        def stub(*args: Any) -> int:
            self.calls.append((name, args[0] if args else None))
            return 0
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


TD_METHODS: list[str] = [
    "createTstpSPTraderApi",
    "registerFront",
    "registerNameServer",
    "subscribePrivateTopic",
    "subscribePublicTopic",
    "init",
    "exit",
    "reqUserLogin",
    "reqQrySecurity",
    "reqQryInvestor",
    "reqQryShareholderAccount",
    "reqQryTradingAccount",
    "reqQryPosition",
    "reqOrderInsert",
    "reqOrderAction",
]

MD_METHODS: list[str] = [
    "createTstpXMdApi",
    "registerFront",
    "registerNameServer",
    "init",
    "exit",
    "reqUserLogin",
    "subscribeSPMarketData",
]


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> ToraOptionGateway:
    engine: EventEngine = EventEngine()
    gateway: ToraOptionGateway = ToraOptionGateway(engine, "TORAOPTION")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.td_api, TD_METHODS)
    recorder.patch(monkeypatch, gateway.md_api, MD_METHODS)
    return gateway


@pytest.fixture
def td_api(gateway: ToraOptionGateway) -> ToraTdApi:
    return gateway.td_api


@pytest.fixture
def md_api(gateway: ToraOptionGateway) -> ToraMdApi:
    return gateway.md_api


def connect_setting(**overrides: str) -> dict[str, str]:
    data: dict[str, str] = {
        "账号": "u1",
        "密码": "p1",
        "行情服务器": "127.0.0.1:8888",
        "交易服务器": "127.0.0.1:9999",
        "产品标识": "prod",
        "动态密钥": "dyn",
        "账号类型": ACCOUNT_USERID,
        "地址类型": ADDRESS_FRONT,
    }
    data.update(overrides)
    return data


def order_request(order_type: OrderType = OrderType.LIMIT) -> OrderRequest:
    return OrderRequest(
        symbol="10001234",
        exchange=Exchange.SSE,
        direction=Direction.LONG,
        type=order_type,
        volume=2,
        price=0.05,
        offset=Offset.OPEN,
    )


def order_rtn(status: str) -> dict[str, Any]:
    return {
        "SecurityID": "10001234",
        "ExchangeID": TORA_TSTP_SP_EXD_SSE,
        "OrderRef": 42,
        "OrderSysID": "SYS1",
        "OrderPriceType": TORA_TSTP_SP_OPT_LimitPrice,
        "Direction": TORA_TSTP_SP_D_Buy,
        "CombOffsetFlag": TORA_TSTP_SP_OF_Open,
        "Price": 0.05,
        "VolumeTotalOriginal": 2,
        "VolumeTraded": 0,
        "OrderStatus": status,
        "InsertDate": "20250926",
        "InsertTime": "09:30:00",
    }


def test_connect_prefixes_bare_address(gateway: ToraOptionGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[2]))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[2]))

    gateway.connect(connect_setting())

    assert seen["md"] == "tcp://127.0.0.1:8888"
    assert seen["td"] == "tcp://127.0.0.1:9999"


def test_connect_keeps_tcp_prefix(gateway: ToraOptionGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[2]))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[2]))

    gateway.connect(connect_setting(
        行情服务器="tcp://127.0.0.1:8888",
        交易服务器="tcp://10.0.0.1:9999",
    ))

    assert seen["md"] == "tcp://127.0.0.1:8888"
    assert seen["td"] == "tcp://10.0.0.1:9999"


def test_send_order_builds_time_prefix(
    td_api: ToraTdApi,
    sink: Sink,
    recorder: CallRecorder,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    class FrozenDatetime(datetime):
        @classmethod
        def now(cls, tz: object = None) -> datetime:
            return datetime(2025, 9, 26, 9, 30, 15)

    monkeypatch.setattr(tora_option_gateway, "datetime", FrozenDatetime)
    td_api.shareholder_ids[Exchange.SSE] = "A0001"
    vt_orderid: str = td_api.send_order(order_request())

    assert vt_orderid == "TORAOPTION.93000001"
    request: dict[str, Any] = recorder.calls[0][1]
    assert recorder.names() == ["reqOrderInsert"]
    assert request["OrderRef"] == 93000001
    assert request["OrderPriceType"] == TORA_TSTP_SP_OPT_LimitPrice
    assert request["TimeCondition"] == TORA_TSTP_SP_TC_GFD
    assert request["VolumeCondition"] == TORA_TSTP_SP_VC_AV
    assert request["CombOffsetFlag"] == TORA_TSTP_SP_OF_Open
    assert request["CombHedgeFlag"] == TORA_TSTP_SP_HF_Speculation
    assert sink.orders[0].status == Status.SUBMITTING


def test_send_order_rejects_stop(td_api: ToraTdApi, sink: Sink, recorder: CallRecorder) -> None:
    td_api.shareholder_ids[Exchange.SSE] = "A0001"

    assert td_api.send_order(order_request(OrderType.STOP)) == ""
    assert recorder.calls == []
    assert "不支持的委托类型" in sink.logs[0]


@pytest.mark.parametrize(
    ("tora_status", "status"),
    [
        (TORA_TSTP_SP_OST_AllTraded, Status.ALLTRADED),
        (TORA_TSTP_SP_OST_PartTraded, Status.PARTTRADED),
        (TORA_TSTP_SP_OST_Accepted, Status.NOTTRADED),
        (TORA_TSTP_SP_OST_Cancelled, Status.CANCELLED),
        (TORA_TSTP_SP_OST_Handled, Status.NOTTRADED),
        (TORA_TSTP_SP_OST_Failed, Status.REJECTED),
        (TORA_TSTP_SP_OST_PartTradedCancelled, Status.CANCELLED),
    ],
)
def test_order_status_mapping(td_api: ToraTdApi, sink: Sink, tora_status: str, status: Status) -> None:
    td_api.onRtnOrder(order_rtn(tora_status))

    order: OrderData = sink.orders[0]
    assert order.orderid == "42"
    assert order.status == status
    assert order.offset == Offset.OPEN
    assert order.direction == Direction.LONG
    assert order.exchange == Exchange.SSE
    assert order.datetime == datetime(2025, 9, 26, 9, 30, tzinfo=CHINA_TZ)
    assert td_api.orderid_sysid_map["42"] == "SYS1"


def test_position_volume_sums_today_and_history(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.investor_id = "inv"
    td_api.onRspQryPosition({
        "InvestorID": "inv",
        "SecurityID": "10001234",
        "ExchangeID": TORA_TSTP_SP_EXD_SSE,
        "PosiDirection": TORA_TSTP_SP_PD_Long,
        "TodayPos": 3,
        "HistoryPos": 4,
        "TotalPosCost": 70,
        "LastPrice": 12,
        "HistoryPosFrozen": 1,
        "TodayPosFrozen": 1,
        "LongFrozen": 1,
        "ShortFrozen": 1,
    }, {}, 1, True)

    position: PositionData = sink.positions[0]
    assert position.symbol == "10001234"
    assert position.exchange == Exchange.SSE
    assert position.direction == Direction.LONG
    assert position.volume == 7
    assert position.yd_volume == 4
    assert position.price == 10
    assert position.frozen == 4
    assert position.pnl == 14


def test_other_investor_position_is_ignored(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.investor_id = "inv"
    td_api.onRspQryPosition({
        "InvestorID": "other",
        "SecurityID": "10001234",
        "ExchangeID": TORA_TSTP_SP_EXD_SSE,
        "PosiDirection": TORA_TSTP_SP_PD_Long,
        "TodayPos": 1,
        "HistoryPos": 1,
        "TotalPosCost": 2,
        "LastPrice": 1,
        "HistoryPosFrozen": 0,
        "TodayPosFrozen": 0,
        "LongFrozen": 0,
        "ShortFrozen": 0,
    }, {}, 1, True)

    assert sink.positions == []
    assert "其他账户" in sink.logs[0]


def test_empty_position_query_is_ignored(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.onRspQryPosition({}, {}, 1, True)

    assert sink.positions == []


def test_empty_security_tail_logs_without_contract(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.onRspQrySecurity({}, {}, 1, True)

    assert sink.logs == ["合约信息查询成功"]


def test_tick_datetime_uses_trading_day(md_api: ToraMdApi, sink: Sink) -> None:
    md_api.onRtnSPMarketData({
        "TradingDay": "20250926",
        "UpdateTime": "09:30:00",
        "SecurityID": "10001234",
        "SecurityName": "50ETF购9月",
        "ExchangeID": TORA_TSTP_SP_EXD_SSE,
        "OpenInterest": 20,
        "LastPrice": 0.05,
        "Volume": 30,
        "UpperLimitPrice": 0.2,
        "LowerLimitPrice": 0.001,
        "OpenPrice": 0.04,
        "HighestPrice": 0.06,
        "LowestPrice": 0.03,
        "PreClosePrice": 0.045,
        "BidPrice1": 0.049,
        "AskPrice1": 0.051,
        "BidVolume1": 1,
        "AskVolume1": 2,
        "BidVolume2": 3,
        "AskVolume2": 0,
        "BidPrice2": 0.048,
        "BidPrice3": 0.047,
        "BidPrice4": 0.046,
        "BidPrice5": 0.045,
        "AskPrice2": 0.052,
        "AskPrice3": 0.053,
        "AskPrice4": 0.054,
        "AskPrice5": 0.055,
        "BidVolume3": 0,
        "BidVolume4": 0,
        "BidVolume5": 0,
        "AskVolume3": 0,
        "AskVolume4": 0,
        "AskVolume5": 0,
    })

    tick: TickData = sink.ticks[0]
    assert tick.symbol == "10001234"
    assert tick.exchange == Exchange.SSE
    assert tick.datetime == datetime(2025, 9, 26, 9, 30, tzinfo=CHINA_TZ)
    assert tick.last_price == 0.05
    assert tick.bid_price_2 == 0.048


def test_close_without_connection_does_not_exit(md_api: ToraMdApi, recorder: CallRecorder) -> None:
    md_api.close()

    assert recorder.calls == []
