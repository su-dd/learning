# 添加C++11要求
QMAKE_CXXFLAGS += -std=c++11

TARGET = Common

# 指定生成的是lib
TEMPLATE = lib
# 指定生成的是静态库
CONFIG += staticlib

DEFINES += COMMON_LIBRARY

# 指定生成路径
DESTDIR = $$PWD/../Bin


# 头文件 {文件夹} 路径
INCLUDEPATH += \
    $$PWD/Thread \
    $$PWD/Signal \

# 头文件
HEADERS += \
    $$PWD/Thread/ThreadPool.h \
    Signal/Signal.h

# 源文件
SOURCES += \
