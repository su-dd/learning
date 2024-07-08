cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Test)

add_executable(test_document tst_test_document.cpp)
add_test(NAME test COMMAND test_document)

target_link_libraries(test_document PRIVATE Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_document PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs/editor)
target_link_libraries(test_document PUBLIC My_Editor)
