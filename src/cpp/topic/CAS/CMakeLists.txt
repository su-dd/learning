cmake_minimum_required(VERSION 3.8)
project(cas)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_LIST) # get all source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}) # include current directory
add_executable(cas ${SRC_LIST}) # create executable