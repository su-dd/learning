cmake_minimum_required(VERSION 3.10)
project(Shared_Mutex_C17)
set(CMAKE_CXX_STANDARD 17)
aux_source_directory(. SRC_LIST)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SRC_LIST})
# pthread is not included by default in linux core, so we need to link it explicitly
target_link_libraries(${PROJECT_NAME} pthread) # link with pthread library, which is required by std::shared_mutex; 
