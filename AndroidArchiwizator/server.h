#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "SrvThread.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = 0);
    void run();

signals:
    void sendingToGUI(QByteArray data);

public slots:
    void receiveData(QByteArray data);


private:
    QTcpSocket* socket;

protected:
    void incomingConnection(int descriptor);
};

#endif // SERVER_H
