#ifndef SLAVETHREAD_H
#define SLAVETHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QtSerialPort/QSerialPort>
#include <QObject>
#include <QDebug>

#define DEBUG_PRINT 0

class SlaveThread : public QThread
{
    Q_OBJECT
    public:
        SlaveThread(QObject *parent = 0);
        ~SlaveThread();
        void startSlave(const QString &portName, int waitTimeout, const QString &response, QSerialPort * pCurrentSerialPort);
        void run();
    signals:
        void request(const QString &s);
        void error(const QString &s);
        void timeout(const QString &s);
    private:
        QString portName;
        QString response;
        int waitTimeout;
        QMutex mutex;
        bool quit;
        QSerialPort * serial;
};

#endif // SLAVETHREAD_H
