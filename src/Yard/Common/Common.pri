# 添加C++11要求
QMAKE_CXXFLAGS += -std=c++11

# 添加Common的lib链接
LIBS += -L$$PWD/../Bin -lCommon

# 头文件 {文件夹} 路径
INCLUDEPATH += \
    $$PWD/Thread \
    $$PWD/Signal
