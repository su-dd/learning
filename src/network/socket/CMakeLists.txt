# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
cmake_minimum_required(VERSION 3.4) # 设置 CMake 最低版本

project(socket) # 设置项目名称

set(CMAKE_CXX_STANDARD 11) # 设置 C++ 语言标准
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 设置 C++ 语言标准是否必须

add_subdirectory(client) # 添加子目录 client
add_subdirectory(server) # 添加子目录 server
