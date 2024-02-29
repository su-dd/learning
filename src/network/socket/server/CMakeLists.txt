# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
cmake_minimum_required(VERSION 3.4)
project(server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(server main.cpp)