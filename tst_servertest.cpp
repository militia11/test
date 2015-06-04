#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include"AndroidArchiwizator/server.h"
#include"AndroidArchiwizator/SrvThread.h"
#include<QString>
#include<QDate>
class ServerTest : public QObject
{
    Q_OBJECT

public:
    ServerTest();
    Server* s;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testServer_data();
    void testServer();
    void testServerConnectionToServer();
    void testServerConnectionToServer_data();
    void testSrvThread();
    void testSrvThread_data();
};

ServerTest::ServerTest()
{
    s= new Server;
    s->run();
   // zobaczyc czy tu da sie puscic i wiola ale RACZEJ NIE
}

void ServerTest::testServer_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void ServerTest::testServer()
{
//    QFETCH(QString, data);
//    QVERIFY2(true, "Failure");
//    s = new Server;
//    s->run();
}
void ServerTest::testServerConnectionToServer()
{



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //TO NARAZIE NIE WAZNE INACZEJ TO TESTUJE PRZEZ INNY PROGRAM WPIERW APLIKACJE SERWEROWA ROBIE
    // POZNIEJ TO MOZNA ZMIENIC NA KONIEC PODPINAJAC KLIENTA ANDROIDA LUB INNEGO NA POTRZEBY TESTU


    // IMITACJA aplikacji KLIENckiej I POLACZENIA z serwerem CZY BEDZIE ODZEW SERWERA
    // taki jak powinie i pokolei czy spelni warunki
    QString s1 ("Server nasluchuje...");
    QString s2 ("Server nasluchuje..."); // to banalne inne wazniejsze
    //jakies przeslanie czegos do servera ale to inna metoda testowa
    QCOMPARE(s1,s2);  //output,"Server nasluchuje";
    // pozniej tamte
}

void ServerTest::testServerConnectionToServer_data()
{

}

void ServerTest::testSrvThread()
{
    //SrvThread* th = new SrvThread();
    QFETCH(int,year);
    QFETCH(int,month);
    QFETCH(int,day);

    QDate date(year,month,day);
    QTEST(date.isValid(),"valid"); // porównuje z kolumną valid
}

void ServerTest::testSrvThread_data()
{
    QTest::addColumn<int>( "year" );
    QTest::addColumn<int>( "month" );
    QTest::addColumn<int>( "day" );
    QTest::addColumn<bool>( "valid" );
    QTest::newRow( "Valid, normal" ) << 1973 << 8 << 16 << true;
    QTest::newRow( "Invalid, normal" ) << 1973 << 9 << 31 << false;
    QTest::newRow( "Valid, leap-year" ) << 1980 << 2 << 29 << true;
    QTest::newRow( "Invalid, leap-year" ) << 1981 << 2 << 29 << false;
}
void ServerTest::initTestCase()
{

}

void ServerTest::cleanupTestCase()
{
}
QTEST_APPLESS_MAIN(ServerTest)

#include "tst_servertest.moc"
