cmake_minimum_required(VERSION 3.8)
project(MutexAndCAS)

# 添加子目录
add_subdirectory(SpinLock)
add_subdirectory(CAS)
add_subdirectory(Mutex)
add_subdirectory(Read_Write_Mutex)
