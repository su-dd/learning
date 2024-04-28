# ���c++11��֧��
QMAKE_CXXFLAGS += -std=c++11

# Qtģ������
QT += core gui widgets

# ָ��ģ������
TARGET = Yard

# ָ�����ɵ���app
TEMPLATE = app

# ָ������·��
DESTDIR = $$PWD/../Bin

# ���������
include($$PWD/../Common/Common.pri)

# ����Ӧ�ò�
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
