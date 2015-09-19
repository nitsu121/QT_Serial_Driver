#ifndef COMSETUPMENUE_H
#define COMSETUPMENUE_H

#include <QWidget>
#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include "slavethread.h"
#include <QObject>

#include "ui_comsetupmenue.h"

#include <com_port_driver.h>

#define DEBUG_PRINT 0

namespace Ui
{
    class ComSetUpMenue;
}

class ComSetUpMenue : public QWidget
{
    Q_OBJECT
signals:

public:
    explicit ComSetUpMenue(QWidget *parent = 0);
    ~ComSetUpMenue();
    void PassUartPointer(UART_t * pMainWindowUart);
private slots:
    void on_SetConfigPushButton_clicked();
    void on_BaudRateComboBox_currentIndexChanged(int index);
    void on_ParityComboBox_currentIndexChanged(int index);
    void on_DataBitsComboBox_currentIndexChanged(int index);
    void on_StopBitsComboBox_currentIndexChanged(int index);
    void on_FlowControlComboBox_currentIndexChanged(int index);
    void on_ComSetUpMenue_destroyed();

private:
    UART_t * pComSetUpUart;
    quint32 DefaultBaudRate;
    quint8 DefaultDataBits;
    quint8 DefaultStopBits;
    quint8 DefaultParity;
    quint8 DefaultFlowControl;

    Ui::ComSetUpMenue *ui;
};

#endif // COMSETUPMENUE_H
