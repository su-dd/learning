# ���C++11Ҫ��
QMAKE_CXXFLAGS += -std=c++11

# ���Common��lib����
LIBS += -L$$PWD/../Bin -lCommon

# ͷ�ļ� {�ļ���} ·��
INCLUDEPATH += \
    $$PWD/Thread \
    $$PWD/Signal
