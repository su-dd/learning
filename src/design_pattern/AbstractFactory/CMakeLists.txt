# CMakeList.txt: test 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(AbstractFactory LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

# 指定头文件的搜索路径
include_directories("factory")

include_directories("product")

# 将源代码添加到此项目的可执行文件。
add_executable (
AbstractFactory
"main.cpp"
"factoryproducer.h"
"factory/factoryinterface.h"
"factory/set1factoryimpl.h"
"factory/set2factoryimpl.h"
"product/BigChipsImpl.h"
"product/ChipsInterface.h"
"product/IceCreamInterface.h"
"product/LittleChipsImpl.h"
"product/StrawberryIceCreamImpl.hpp"
"product/VanillaIceCreamImpl.hpp"
)

# TODO: 如有需要，请添加测试并安装目标。
