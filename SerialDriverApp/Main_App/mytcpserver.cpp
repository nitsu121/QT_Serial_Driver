#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    GotConnection = 0;
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    QHostAddress hostadd("127.0.0.1");
    if(!server->listen(hostadd, 9797))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

}

MyTcpServer::~MyTcpServer()
{
    if(1 == GotConnection)
    {
        socket->close();
    }
    else
    {
    }
}

void MyTcpServer::newConnection()
{
    GotConnection = 1;
    // need to grab the socket
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(DataAvailable()));
    socket->write("Hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    //socket->close();
}

void MyTcpServer::WriteTCPData(quint8 * ArrayOut, quint8 ArrayLength)
{
    socket->write((const char *) ArrayOut, ArrayLength);
    socket->flush();
    socket->waitForBytesWritten(3000);
}


void MyTcpServer::DataAvailable()
{
    quint8 ArrayOut[] = "I got your data yo!";
    qDebug() << "MyTcpServer::DataAvailable() Got some data.";
    //delayMs();
    //QThread::sleep(3);
    // read the data from the socket
    qDebug() << socket->readAll();
    WriteTCPData(ArrayOut, sizeof(ArrayOut));
}
