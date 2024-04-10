set(CMAKE_CXX_STANDARD 11)
aux_source_directory(. PooL_SRC_LIST)
add_library(ThreadPool ${PooL_SRC_LIST})
# add pthread library for multi-threading support
target_link_libraries(ThreadPool PUBLIC pthread) 