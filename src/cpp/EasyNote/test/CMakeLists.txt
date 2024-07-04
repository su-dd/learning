cmake_minimum_required(VERSION 3.5)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

add_executable(Test_Document tst_test_document.cpp)
add_test(NAME Test_Document COMMAND Test_Document)

target_link_libraries(Test_Document PRIVATE Qt${QT_VERSION_MAJOR}::Test)

