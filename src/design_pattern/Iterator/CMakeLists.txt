cmake_minimum_required (VERSION 3.8)

project(Iterator LANGUAGES CXX)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

include_directories(".")

add_executable (
 Iterator
 "main.cpp"
 "Iterator.h"
 "ConcreteIterator.h"
 "Aggregate.h"
 "ConcreteAggregate.h"
 
)