import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """获取三方模块"""
    # Linux
    if platform.system() == "Linux":
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]
        libraries = [
            "xmdapi",
            "sptraderapi",
            "traderapi",
        ]
    # Windows
    elif platform.system() == "Windows":
        extra_compile_flags = ["-O2", "-MT"]
        extra_link_args = []
        runtime_library_dirs = []
        libraries = [
            "xmdapi",
            "sptraderapi",
            "traderapi",
        ]

    include_dirs = ["vnpy_tora/api/include", "vnpy_tora/api/include/tora", "vnpy_tora/api/vntora"]
    library_dirs = ["vnpy_tora/api/libs", "vnpy_tora/api"]

    vntoramd = Extension(
        "vnpy_tora.api.vntoramd",
        ["vnpy_tora/api/vntora/vntoramd/vntoramd.cpp"],
        include_dirs=include_dirs,
        define_macros=[],
        undef_macros=[],
        library_dirs=library_dirs,
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vntoraoption = Extension(
        "vnpy_tora.api.vntoraoption",
        ["vnpy_tora/api/vntora/vntoraoption/vntoraoption.cpp"],
        include_dirs=include_dirs,
        define_macros=[],
        undef_macros=[],
        library_dirs=library_dirs,
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vntorastock = Extension(
        "vnpy_tora.api.vntorastock",
        ["vnpy_tora/api/vntora/vntorastock/vntorastock.cpp"],
        include_dirs=include_dirs,
        define_macros=[],
        undef_macros=[],
        library_dirs=library_dirs,
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vntoramd, vntoraoption, vntorastock]


setup(
    ext_modules=get_ext_modules(),
)
