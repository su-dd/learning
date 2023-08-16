# CMakeList.txt: test 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(Adapter LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

include_directories(".")
include_directories("sdk")

add_executable (
	Adapter
	main.cpp
	"sdk/BrandIntf.h"
	"sdk/BrandImpl.hpp"
	"sdk/IceCreamIntf.h"
	"sdk/IceCreamImpl.hpp"
	"sdk/IceCreamFacade.hpp"
	"IceCreamFacadeClassAdapter.h"
	"IceCreamFacadeObjectAdapter.h"
)