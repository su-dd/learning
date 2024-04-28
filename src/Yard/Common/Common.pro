# ���C++11Ҫ��
QMAKE_CXXFLAGS += -std=c++11

TARGET = Common

# ָ�����ɵ���lib
TEMPLATE = lib
# ָ�����ɵ��Ǿ�̬��
CONFIG += staticlib

DEFINES += COMMON_LIBRARY

# ָ������·��
DESTDIR = $$PWD/../Bin


# ͷ�ļ� {�ļ���} ·��
INCLUDEPATH += \
    $$PWD/Thread \
    $$PWD/Signal \

# ͷ�ļ�
HEADERS += \
    $$PWD/Thread/ThreadPool.h \
    Signal/Connect.h

# Դ�ļ�
SOURCES += \
    Signal/Connect.cpp
