#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <qthread.h>


class MyTcpServer : public QObject
{
    Q_OBJECT

public:
    explicit MyTcpServer(QObject * parent = 0);
    ~MyTcpServer();
    void WriteTCPData(quint8 * ArrayOut, quint8 ArrayLength);



signals:

public slots:
    void newConnection();
    void DataAvailable();

private:
    QTcpServer * server;
    QTcpSocket * socket;
    bool GotConnection;
};

#endif // MYTCPSERVER_H
