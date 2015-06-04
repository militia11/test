#ifndef SRVTHREAD_H
#define SRVTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class SrvThread : public QThread
{
    Q_OBJECT
public:
    explicit SrvThread(int ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError error);
    void readData(QByteArray data);

public slots:
    void readyRead();
    void connectionLosted();

private:
    QTcpSocket* socket;
    int descriptor;
};

#endif // SRVTHREAD_H
