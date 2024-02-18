cmake_minimum_required(VERSION 3.14)

project(DataStructure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    main.cpp
    Head.h
    SqList.cpp 
    SqStack.cpp 
    LinkList.cpp 
    LinkList_with_head.cpp 
    BinaryTree.cpp
    AVLTree.cpp
    RedBlackTree.cpp
    HashTable.cpp
    Graph.h
    Graph.cpp
    MiniSpanTree.cpp
    ShortestPath.cpp
)

add_executable(DataStructure
  ${SOURCE_FILES}
)

include(GNUInstallDirs)
install(TARGETS DataStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
