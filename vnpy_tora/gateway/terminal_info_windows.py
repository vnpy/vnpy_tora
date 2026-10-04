"""在 Windows 上采集华鑫奇点终端信息。"""

import wmi
import requests
import pythoncom


def get_iip() -> str:
    """查询公网 IP。"""
    f: requests.Response = requests.get("http://myip.dnsomatic.com")
    iip: str = f.text
    return iip


def get_lip() -> str:
    """读取本机 IP。"""
    c: wmi._wmi_namespace = wmi.WMI()

    lip: str = ""
    interface: wmi._wmi_object
    for interface in c.Win32_NetworkAdapterConfiguration(IPEnabled=1):
        lip = interface.IPAddress[0]

    return lip


def get_mac() -> str:
    """读取本机 MAC 地址。"""
    c: wmi._wmi_namespace = wmi.WMI()

    mac: str = ""
    interface: wmi._wmi_object
    for interface in c.Win32_NetworkAdapterConfiguration(IPEnabled=1):
        mac = interface.MACAddress

    return mac


def get_hd() -> str:
    """读取硬盘序列号。"""
    c: wmi._wmi_namespace = wmi.WMI()

    hd: str = ""
    disk: wmi._wmi_object
    for disk in c.Win32_DiskDrive():
        hd = disk.SerialNumber.strip()

    return hd


def get_terminal_info() -> str:
    """初始化 COM 并组装终端信息字符串。"""
    # Initialize COM object in this thread.
    pythoncom.CoInitialize()

    iip: str = ""
    iport: str = ""
    lip: str = get_lip()
    mac: str = get_mac()
    hd: str = get_hd()

    terminal_info: str = ";".join([
        "PC",
        f"IIP={iip}",
        f"IPORT={iport}",
        f"LIP={lip}",
        f"MAC={mac}",
        f"HD={hd}",
        "PCN=NA;CPU=NA;PI=NA;VOL=NA@NA"
    ])

    return terminal_info
