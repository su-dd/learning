#include <QtTest>
#include <QString>
// add necessary includes here

class Test_Document : public QObject
{
    Q_OBJECT

public:
    Test_Document();
    ~Test_Document();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

Test_Document::Test_Document() {}

Test_Document::~Test_Document() {}

void Test_Document::initTestCase() {}

void Test_Document::cleanupTestCase() {}

void Test_Document::test_case1()
{
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(Test_Document)

#include "tst_test_document.moc"
