# CMakeList.txt: test 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(Builder LANGUAGES CXX)

# 简单建造者
add_subdirectory(SimpleBuilder)

# 一般建造者
add_subdirectory(NormalBuilder)
