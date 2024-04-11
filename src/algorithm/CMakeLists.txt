cmake_minimum_required (VERSION 3.8)
project(algorithm LANGUAGES CXX) # 定义项目名称和语言

set(CMAKE_CXX_STANDARD 14) # 设置C++语言的标准

# 设置源代码路径
# aux_source_directory(./sort, sort_srcs)
# aux_source_directory(./sort, search_srcs)

# 将源代码添加到此项目的可执行文件。
add_executable (
    algorithm
    "main.cpp"
    "sort/Sort_Bubble.h"
    # ${sort_srcs}
    # ${search_srcs}
)
