cmake_minimum_required(VERSION 3.8)
project(MutexAndCAS)

# 添加子目录
add_subdirectory(SpinLock)
add_subdirectory(CAS)
add_subdirectory(Mutex)
add_subdirectory(Condition_Variable)
add_subdirectory(Shared_Mutex_C11)
add_subdirectory(Shared_Mutex_C17)
add_subdirectory(Semaphore)
