cmake_minimum_required(VERSION 3.10)
project(SpinLock)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_LIST)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(SpinLock ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} pthread)
