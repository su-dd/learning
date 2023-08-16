cmake_minimum_required(VERSION 3.5)

project(Command LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(
	Command
	main.cpp
	"IceCream.h"
	"Invoker.h"
	"Command.h"
	"IceFactoryReceiver.h"
	"StrawberryCommand.h"
	"VanillalceCommand.h"
)

