#include "Document.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("path/to/your/file.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return;
    }

    QString content = file.readAll();
    file.close();

    Document doc;
    doc.initWithJson(content);

    NodeEditorPtr ptr = doc.getEditor(nullptr);
    ptr->show();

    return a.exec();
}
