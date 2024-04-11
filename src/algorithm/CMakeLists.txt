cmake_minimum_required (VERSION 3.8)
project(algorithm LANGUAGES CXX) # 定义项目名称和语言

set(CMAKE_CXX_STANDARD 14) # 设置C++语言的标准
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 要求使用C++14标准

# 将源代码添加到此项目的可执行文件。
add_executable (
    algorithm
    "main.cpp"
    "sort_algorithm.h"
)
