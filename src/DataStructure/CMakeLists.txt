cmake_minimum_required(VERSION 3.14)

project(DataStructure LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DataStructure
  main.cpp
  SqHead.h
  SqStack.cpp
  SqList.cpp
  LinkList.cpp
  LinkList_with_head.cpp
  HashTable.cpp
)

include(GNUInstallDirs)
install(TARGETS DataStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
