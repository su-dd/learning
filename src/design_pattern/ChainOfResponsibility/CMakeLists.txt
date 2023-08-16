cmake_minimum_required(VERSION 3.5)

project(ChainOfResponsibility LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(
	ChainOfResponsibility
	"main.cpp"
	"Handler.h"
	"Request.h"
	"ConcreteHandler.h"
)

