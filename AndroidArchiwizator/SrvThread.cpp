#include "SrvThread.h"

SrvThread::SrvThread(int ID, QObject *parent) : QThread(parent)
{
    this->descriptor = ID;
}

void SrvThread::run()
{
    qDebug() << descriptor << "Wątek startuje";
    socket = new QTcpSocket();
    if( !socket->setSocketDescriptor(this->descriptor) ){
        emit error(socket->error());
        return;
    }
    connect( socket, SIGNAL( readyRead() ), this, SLOT( readyRead() ), Qt::DirectConnection);
    connect( socket, SIGNAL( disconnected() ), this, SLOT( connectionLosted() ), Qt::DirectConnection);
    qDebug() << descriptor << "Połączony... ";
    exec();
}

void SrvThread::readyRead()
{
    // klient przesle swoj nr to kazda komorka ma swoj - to gdzies bedzie w app klienckiej
    // moze w tym miejscu odczytanie nr klienta i wtedy dalej...

    QByteArray data = socket->readAll();
    if(!data.isEmpty()){ // nie wiem czy ten if ma sens?
        socket->write("Odebrano dane.\r\n");
    }
    qDebug() << descriptor << "Dane : " << data ;// sygnal wyslanie danych

    //qDebug() << data;
    emit readData(data);
    // tu zrobic data pobranie i zapisanie do narazie innej klasy pozniej bazy !!!!!!!!!!!
    //QByteArray data2 = dokument robić przerobić dobrze QByte i Array;
                                                 // tu zapis do klienta
    // ale jak sprawdzanie...
    //socket->waitForBytesWritten(3000);
    //socket->flush();

}
void SrvThread::connectionLosted()
{
    qDebug() << descriptor << "Rozlaczony: " ;
    socket->deleteLater();
    exit(0);
}
