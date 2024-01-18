# CMakeList.txt: algorithm 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("algorithm")

aux_source_directory(./sort, sort_srcs)
aux_source_directory(./sort, search_srcs)

# 将源代码添加到此项目的可执行文件。
add_executable (
	algorithm
	"algorithm.cpp" "algorithm.h" 
	${sort_srcs}
	${search_srcs}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET algorithm PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
