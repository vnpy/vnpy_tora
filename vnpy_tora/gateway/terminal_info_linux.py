"""在 Linux 上采集华鑫奇点终端信息。"""

import subprocess
import socket
from uuid import getnode

import requests


def get_iip() -> str:
    """查询公网 IP。"""
    iip: str = ""

    try:
        r = requests.get("https://api.vnpy.com/ip", timeout=2)
        iip = r.json()["ip"]
    except Exception:
        pass

    return iip


def get_lip() -> str:
    """返回本机 IP。"""
    return socket.gethostbyname(socket.gethostname())


def get_mac() -> str:
    """返回本机 MAC 地址。"""
    node: int = getnode()
    hex_str = f"{node:012X}"
    mac: str = "".join(hex_str[i: i + 2] for i in range(0, 12, 2))
    return mac


def run_cmd(cmd: str) -> str:
    """运行命令"""
    with subprocess.Popen(
        cmd,
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT
    ) as proc:
        stdout, _ = proc.communicate()

        if proc.returncode > 0:
            return ""
        else:
            return stdout.decode()


def get_hd() -> str:
    """读取磁盘序列号。"""
    for name in ["vda", "sda"]:
        cmd: str = f"udevadm info --query=all --name=/dev/{name} | grep ID_SERIAL"
        result: str = run_cmd(cmd)

        if result:
            hd: str = result[(result.index("=") + 1):]
            return hd.replace("\n", "")

    return ""


def get_terminal_info() -> str:
    """组装终端信息字符串。"""
    iip = ""
    iport = ""
    lip = get_lip()
    mac = get_mac()
    hd = get_hd()

    terminal_info = ";".join([
        "PC",
        f"IIP={iip}",
        f"IPORT={iport}",
        f"LIP={lip}",
        f"MAC={mac}",
        f"HD={hd}",
        "PCN=NA;CPU=NA;PI=NA;VOL=NA@NA"
    ])

    return terminal_info
