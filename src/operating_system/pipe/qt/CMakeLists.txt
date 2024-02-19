cmake_minimum_required(VERSION 3.10) # 最低版本要求

project(qt_pipe LANGUAGES CXX) # 项目名称


set(CMAKE_AUTOUIC ON) # 自动生成 ui 文件
set(CMAKE_AUTOMOC ON) # 自动处理 moc 文件
set(CMAKE_AUTORCC ON) # 自动处理 rcc 文件
set(CMAKE_INCLUDE_CURRENT_DIR ON) # 包含当前目录

set(CMAKE_CXX_STANDARD 17) # c++ 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON) # c++ 标准要求
set(QT_VERSION_MAJOR 5)
set(QT_VERSION_MINOR 9.9)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets) # 查找 Qt库
include_directories(Qt${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}/include REQUIRED COMPONTS Core) # 包含 Qt头文件

aux_source_directory(. DIR_SRCS) # 遍历当前目录下的所有源文件
add_executable(qt_pipe ${DIR_SRCS}) # 添加可执行文件

target_link_libraries(qt_pipe Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets) # 链接 Qt库

install(TARGETS qt_pipe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}) # 安装库文件
