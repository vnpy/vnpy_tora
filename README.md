# VeighNa框架的华鑫奇点柜台接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-2022.2.21-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.7-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于华鑫奇点的Python API开发，支持股票和期权交易。

股票API的版本为：

- Level1行情：API_Python3.7_行情_v1.0.0_20210924
- Level2行情：API_Python3.7_v4.0.0_20210426
- 交易：API_Python3.7_交易_v4.0.2_20211103

期权的API版本为：
- API_Python3.7_v1.3.2_20211201

API版本的详细信息，请参考[奇点官网](https://n-sight.com.cn/)。

## 安装

安装环境推荐基于3.0.0版本以上的【[**VeighNa Studio**](https://www.vnpy.com)】。

直接使用pip命令：

```
pip install vnpy_tora
```

或者下载源代码后，解压后在cmd中运行：

```
pip install .
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
