project(
  'vnpy_tora',
  'cpp',
  version: '2025.04.16',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
extra_cpp_args = []
extra_link_args = []

# 初始化库变量
xmdapi_lib = []
sptraderapi_lib = []
traderapi_lib = []

# 初始化其他编译选项
install_rpath_value = ''

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_tora/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_tora/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_tora/api/include',
    'vnpy_tora/api/include/tora',
    'vnpy_tora/api/vntora',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  xmdapi_lib = cpp.find_library('xmdapi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  sptraderapi_lib = cpp.find_library('sptraderapi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  traderapi_lib = cpp.find_library('traderapi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
    '-Wl,-rpath,' + install_rpath_value,
  ]
  install_rpath_value = '$ORIGIN'
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_tora/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_tora/api/include',
    'vnpy_tora/api/include/tora',
    'vnpy_tora/api/vntora',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  xmdapi_lib = cpp.find_library('xmdapi', 
                                       dirs: [lib_dir],
                                       required: true)
  sptraderapi_lib = cpp.find_library('sptraderapi', 
                                       dirs: [lib_dir],
                                       required: true)
  traderapi_lib = cpp.find_library('traderapi', 
                                       dirs: [lib_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vntoramd',
  sources: ['vnpy_tora/api/vntora/vntoramd/vntoramd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, xmdapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  install_rpath: install_rpath_value,
  subdir: 'vnpy_tora/api'
)

# 创建期权模块扩展
option_module = py.extension_module(
  'vntoraoption',
  sources: ['vnpy_tora/api/vntora/vntoraoption/vntoraoption.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, sptraderapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  install_rpath: install_rpath_value,
  subdir: 'vnpy_tora/api'
)

# 创建股票模块扩展
stock_module = py.extension_module(
  'vntorastock',
  sources: ['vnpy_tora/api/vntora/vntorastock/vntorastock.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, traderapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  install_rpath: install_rpath_value,
  subdir: 'vnpy_tora/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_tora/__init__.py', 'vnpy_tora'],
  ['vnpy_tora/api/__init__.py', 'vnpy_tora/api'],
  ['vnpy_tora/api/tora_constant.py', 'vnpy_tora/api'],
  ['vnpy_tora/gateway/__init__.py', 'vnpy_tora/gateway'],
  ['vnpy_tora/gateway/tora_option_gateway.py', 'vnpy_tora/gateway'],
  ['vnpy_tora/gateway/tora_stock_gateway.py', 'vnpy_tora/gateway'],
  ['vnpy_tora/gateway/terminal_info_windows.py', 'vnpy_tora/gateway'],
  ['vnpy_tora/gateway/terminal_info_linux.py', 'vnpy_tora/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_tora/api/xmdapi.dll',
    'vnpy_tora/api/sptraderapi.dll',
    'vnpy_tora/api/traderapi.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_tora/api'
  )
else  # Linux
  api_libs = [
    'vnpy_tora/api/libxmdapi.so',
    'vnpy_tora/api/libsptraderapi.so',
    'vnpy_tora/api/libtraderapi.so',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_tora/api'
  )
endif
