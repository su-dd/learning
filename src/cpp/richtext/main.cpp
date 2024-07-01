#include "RichText.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RichText text;
    text.show();
    return a.exec();
}
