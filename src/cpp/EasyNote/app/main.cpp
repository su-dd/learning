#include "Document.h"
#include "RichText.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RichTextFrame oFrame;
    oFrame.show();
    return a.exec();
}
