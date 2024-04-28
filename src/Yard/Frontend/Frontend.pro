# 添加c++11的支持
QMAKE_CXXFLAGS += -std=c++11

# Qt模块引用
QT += core gui widgets

# 指定模块名称
TARGET = Yard

# 指定生成的是app
TEMPLATE = app

# 指定生成路径
DESTDIR = $$PWD/../Bin

# 关联共享层
include($$PWD/../Common/Common.pri)

# 关联应用层
#include($$PWD/../Application/Application.pri)

INCLUDEPATH += \
    $$PWD/editor \
    $$PWD/document \

HEADERS += \
    $$PWD/document/YardDocument.h \
    $$PWD/editor/YardEditor.h \
    editor/YardDraws.h

SOURCES += \
    $$PWD/document/YardDocument.cpp \
    $$PWD/editor/YardEditor.cpp \
    editor/YardDraws.cpp \
    main.cpp
