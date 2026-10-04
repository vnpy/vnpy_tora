from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_tora.api", reason="缺少 TORA 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    OrderType,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    ContractData,
    OrderData,
    OrderRequest,
    PositionData,
    TickData,
)

from vnpy_tora.api import (  # noqa: E402
    TORA_TSTP_D_Buy,
    TORA_TSTP_EXD_SSE,
    TORA_TSTP_OPT_LimitPrice,
    TORA_TSTP_OST_Accepted,
    TORA_TSTP_OST_AllCanceled,
    TORA_TSTP_OST_AllTraded,
    TORA_TSTP_OST_Cached,
    TORA_TSTP_OST_PartTradeCanceled,
    TORA_TSTP_OST_PartTraded,
    TORA_TSTP_OST_Rejected,
    TORA_TSTP_OST_Unknown,
    TORA_TSTP_TC_GFD,
    TORA_TSTP_VC_AV,
)
from vnpy_tora.gateway import tora_stock_gateway  # noqa: E402
from vnpy_tora.gateway.tora_stock_gateway import (  # noqa: E402
    ACCOUNT_USERID,
    ADDRESS_FRONT,
    CHINA_TZ,
    ToraMdApi,
    ToraStockGateway,
    ToraTdApi,
)


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.contracts: list[ContractData] = []
        self.orders: list[OrderData] = []
        self.positions: list[PositionData] = []

    def attach(self, gateway: ToraStockGateway) -> None:
        gateway.write_log = self.logs.append
        gateway.on_tick = self.ticks.append
        gateway.on_contract = self.contracts.append
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
    "createTstpTraderApi",
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
    "subscribeMarketData",
]


@pytest.fixture(autouse=True)
def clear_contracts() -> Iterator[None]:
    tora_stock_gateway.symbol_contract_map.clear()
    yield
    tora_stock_gateway.symbol_contract_map.clear()


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> ToraStockGateway:
    engine: EventEngine = EventEngine()
    gateway: ToraStockGateway = ToraStockGateway(engine, "TORASTOCK")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.td_api, TD_METHODS)
    recorder.patch(monkeypatch, gateway.md_api, MD_METHODS)
    return gateway


@pytest.fixture
def td_api(gateway: ToraStockGateway) -> ToraTdApi:
    return gateway.td_api


@pytest.fixture
def md_api(gateway: ToraStockGateway) -> ToraMdApi:
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
        symbol="600000",
        exchange=Exchange.SSE,
        direction=Direction.LONG,
        type=order_type,
        volume=200,
        price=10.5,
    )


def order_rtn(status: str, **overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "SecurityID": "600000",
        "ExchangeID": TORA_TSTP_EXD_SSE,
        "OrderRef": 42,
        "OrderSysID": "SYS1",
        "OrderPriceType": TORA_TSTP_OPT_LimitPrice,
        "Direction": TORA_TSTP_D_Buy,
        "LimitPrice": 10.5,
        "VolumeTotalOriginal": 200,
        "VolumeTraded": 10,
        "OrderStatus": status,
        "InsertDate": "20250926",
        "InsertTime": "09:30:00",
    }
    data.update(overrides)
    return data


def position_rtn(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "InvestorID": "inv",
        "SecurityID": "600000",
        "ExchangeID": TORA_TSTP_EXD_SSE,
        "CurrentPosition": 10,
        "TotalPosCost": 100,
        "HistoryPos": 4,
        "HistoryPosFrozen": 1,
        "TodayBSPosFrozen": 2,
        "TodayPRPosFrozen": 3,
    }
    data.update(overrides)
    return data


def market_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "TradingDay": "20250926",
        "UpdateTime": "09:30:00",
        "SecurityID": "600000",
        "SecurityName": "浦发银行",
        "ExchangeID": TORA_TSTP_EXD_SSE,
        "OpenInterest": 0,
        "LastPrice": 10.2,
        "Volume": 1000,
        "UpperLimitPrice": 11.2,
        "LowerLimitPrice": 9.2,
        "OpenPrice": 10.0,
        "HighestPrice": 10.4,
        "LowestPrice": 9.9,
        "PreClosePrice": 10.1,
        "BidPrice1": 10.19,
        "AskPrice1": 10.21,
        "BidVolume1": 100,
        "AskVolume1": 200,
        "BidPrice2": 10.18,
        "BidPrice3": 10.17,
        "BidPrice4": 10.16,
        "BidPrice5": 10.15,
        "AskPrice2": 10.22,
        "AskPrice3": 10.23,
        "AskPrice4": 10.24,
        "AskPrice5": 10.25,
        "BidVolume2": 3,
        "BidVolume3": 0,
        "BidVolume4": 0,
        "BidVolume5": 0,
        "AskVolume2": 0,
        "AskVolume3": 0,
        "AskVolume4": 0,
        "AskVolume5": 0,
        "IOPV": 1.01,
    }
    data.update(overrides)
    return data


def test_connect_prefixes_bare_address(gateway: ToraStockGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[2]))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[2]))

    gateway.connect(connect_setting())

    assert seen["md"] == "tcp://127.0.0.1:8888"
    assert seen["td"] == "tcp://127.0.0.1:9999"


def test_connect_keeps_tcp_prefix(gateway: ToraStockGateway, monkeypatch: pytest.MonkeyPatch) -> None:
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

    monkeypatch.setattr(tora_stock_gateway, "datetime", FrozenDatetime)
    td_api.shareholder_ids[Exchange.SSE] = "A0001"
    vt_orderid: str = td_api.send_order(order_request())

    assert vt_orderid == "TORASTOCK.93000001"
    request: dict[str, Any] = recorder.calls[0][1]
    assert recorder.names() == ["reqOrderInsert"]
    assert request["OrderRef"] == 93000001
    assert request["OrderPriceType"] == TORA_TSTP_OPT_LimitPrice
    assert request["TimeCondition"] == TORA_TSTP_TC_GFD
    assert request["VolumeCondition"] == TORA_TSTP_VC_AV
    assert request["Direction"] == TORA_TSTP_D_Buy
    assert request["ShareholderID"] == "A0001"
    assert sink.orders[0].status == Status.SUBMITTING


def test_send_order_rejects_stop(td_api: ToraTdApi, sink: Sink, recorder: CallRecorder) -> None:
    td_api.shareholder_ids[Exchange.SSE] = "A0001"

    assert td_api.send_order(order_request(OrderType.STOP)) == ""
    assert recorder.calls == []
    assert "不支持的委托类型" in sink.logs[0]


@pytest.mark.parametrize(
    ("tora_status", "status"),
    [
        (TORA_TSTP_OST_Cached, Status.SUBMITTING),
        (TORA_TSTP_OST_AllTraded, Status.ALLTRADED),
        (TORA_TSTP_OST_PartTraded, Status.PARTTRADED),
        (TORA_TSTP_OST_Accepted, Status.NOTTRADED),
        (TORA_TSTP_OST_AllCanceled, Status.CANCELLED),
        (TORA_TSTP_OST_PartTradeCanceled, Status.CANCELLED),
        (TORA_TSTP_OST_Unknown, Status.SUBMITTING),
        (TORA_TSTP_OST_Rejected, Status.REJECTED),
    ],
)
def test_order_status_mapping(td_api: ToraTdApi, sink: Sink, tora_status: str, status: Status) -> None:
    td_api.onRtnOrder(order_rtn(tora_status))

    order: OrderData = sink.orders[0]
    assert order.orderid == "42"
    assert order.status == status
    assert order.exchange == Exchange.SSE
    assert order.direction == Direction.LONG
    assert order.type == OrderType.LIMIT
    assert order.datetime == datetime(2025, 9, 26, 9, 30, tzinfo=CHINA_TZ)
    assert td_api.sysid_orderid_map["SYS1"] == "42"


def test_unknown_price_type_is_ignored(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.onRtnOrder(order_rtn(TORA_TSTP_OST_Accepted, OrderPriceType="Z"))

    assert sink.orders == []


def test_position_volume_uses_current_position(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.investor_id = "inv"
    td_api.onRspQryPosition(position_rtn(), {}, 1, True)

    position: PositionData = sink.positions[0]
    assert position.symbol == "600000"
    assert position.exchange == Exchange.SSE
    assert position.direction == Direction.NET
    assert position.volume == 10
    assert position.yd_volume == 4
    assert position.price == 10
    assert position.frozen == 6


def test_zero_position_price_is_zero(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.investor_id = "inv"
    td_api.onRspQryPosition(position_rtn(CurrentPosition=0, TotalPosCost=50, HistoryPos=0), {}, 1, True)

    assert sink.positions[0].volume == 0
    assert sink.positions[0].price == 0


def test_other_investor_position_is_ignored(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.investor_id = "inv"
    td_api.onRspQryPosition(position_rtn(InvestorID="other"), {}, 1, True)

    assert sink.positions == []
    assert "其他账户" in sink.logs[0]


def test_empty_position_query_is_ignored(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.onRspQryPosition({}, {}, 1, True)

    assert sink.positions == []


def test_empty_security_tail_logs_without_contract(td_api: ToraTdApi, sink: Sink) -> None:
    td_api.onRspQrySecurity({}, {}, 1, True)

    assert sink.contracts == []
    assert sink.logs == ["合约信息查询成功"]
    assert tora_stock_gateway.symbol_contract_map == {}


def test_tick_datetime_uses_trading_day(md_api: ToraMdApi, sink: Sink) -> None:
    md_api.onRtnMarketData(market_data())

    tick: TickData = sink.ticks[0]
    assert tick.symbol == "600000"
    assert tick.exchange == Exchange.SSE
    assert tick.datetime == datetime(2025, 9, 26, 9, 30, tzinfo=CHINA_TZ)
    assert tick.last_price == 10.2
    assert tick.bid_price_2 == 10.18


def test_close_without_connection_does_not_exit(md_api: ToraMdApi, recorder: CallRecorder) -> None:
    md_api.close()

    assert recorder.calls == []
