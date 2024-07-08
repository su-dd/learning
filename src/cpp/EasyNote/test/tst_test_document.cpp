#include <QCoreApplication>
#include <QtTest>
#include "Document.h"
#include <QString>

// add necessary includes here

class test_document : public QObject
{
    Q_OBJECT

public:
    test_document();
    ~test_document();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

test_document::test_document() {}

test_document::~test_document() {}

void test_document::initTestCase() {}

void test_document::cleanupTestCase() {}

void test_document::test_case1()
{
    QString sDoc =
        QStringLiteral("");

    Document oDocument;
    oDocument.init(sDoc);
}

QTEST_MAIN(test_document)

#include "tst_test_document.moc"
