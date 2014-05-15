#include <QString>
#include <QtTest>



class RettaParserTest : public QObject
{
    Q_OBJECT

public:
    RettaParserTest();

private:
   Parser *col;
  signals:

private Q_SLOTS:
    void getM();
};

RettaParserTest::RettaParserTest()
{
}

void RettaParserTest::getM()
{
    col = new Parser("y = x")
    QVERIFY2(col->getM(), "1");
}

QTEST_APPLESS_MAIN(RettaParserTest)

#include "tst_rettaparsertest.moc"
