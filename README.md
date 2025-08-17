# VeighNa框架的华鑫奇点柜台接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-2025.08.17-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.10|3.11|3.12|3.13-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于华鑫奇点的C++ API开发，支持股票和期权交易。

股票API的版本为：

- Level1行情：v1.0.5_20230210
- 交易：v4.0.8_20230627

期权的API版本为：
- v1.3.3_20220908

API版本的详细信息，请参考[奇点官网](https://n-sight.com.cn/)。

## 安装

安装环境推荐基于4.0.0版本以上的【[**VeighNa Studio**](https://www.vnpy.com)】。

直接使用pip命令：

```
pip install vnpy_tora
```

或者下载源代码后，解压后在cmd中运行：

```
pip install .
```

如果需要以**开发模式**安装到当前Python环境，可以使用下述命令：

```
pip install -e . --no-build-isolation --config-settings=build-dir=.\vnpy_tora\api
```

## 使用

以脚本方式启动（script/run.py）：

```
from vnpy.event import EventEngine
from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp

from vnpy_tora import ToraOptionGateway, ToraStockGateway


def main():
    """主入口函数"""
    qapp = create_qapp()

    event_engine = EventEngine()
    main_engine = MainEngine(event_engine)
    main_engine.add_gateway(ToraOptionGateway)
    main_engine.add_gateway(ToraStockGateway)

    main_window = MainWindow(main_engine, event_engine)
    main_window.showMaximized()

    qapp.exec()


if __name__ == "__main__":
    main()
```
