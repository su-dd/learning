cmake_minimum_required(VERSION 3.5)

project(Template LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(
	Template
	"icecream.h"
	"factoryTemplate.h"
	"strawberryfactory.h"
	"vanillafactory.h"
	"main.cpp"
)

