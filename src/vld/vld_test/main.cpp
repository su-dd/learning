#include "mainwindow.h"

#include <QApplication>
#define VLD_FORCE_ENABLE
#include "vld.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int *p = new int;
    MainWindow w;
    w.show();
    return a.exec();
}
