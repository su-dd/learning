#include <QApplication>
#include <QDebug>
#include "YardEditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    YardEditor oEditor;
//    oEditor.show();

    qDebug() << "hello qt !";
    return a.exec();
}
