# CMakeList.txt: test 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(Singleton LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")


# 指定头文件的搜索路径
include_directories(".")
include_directories("Facade")
include_directories("Factory")
include_directories("IceCream")
include_directories("Singleton")

# 将源代码添加到此项目的可执行文件。
add_executable (
Singleton
"main.cpp"
"Facade/IceCreamFactoryFacade.hpp"
"Facade/IceCreamFactoryFacadeInterface.h"
"Factory/VanillaIceCreamFactory.hpp"
"Factory/IceCreamFactoryInterface.h"
"Factory/StrawberryIceCreamFactory.hpp"
"IceCream/VanillaIceCreamImpl.hpp"
"IceCream/IceCreamInterface.h"
"IceCream/StrawberryIceCreamImpl.hpp"
"Singleton/LazySingletonFactoryFacade.hpp"
"Singleton/EagerSingletonFactoryFacade.hpp"
)

# TODO: 如有需要，请添加测试并安装目标。
