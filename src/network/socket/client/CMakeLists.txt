# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
cmake_minimum_required(VERSION 3.4)
project(client)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(client main.cpp)