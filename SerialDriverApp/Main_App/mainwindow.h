#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QComboBox.h>
#include <com_port_driver.h>
#include <QLineEdit>
#include "mytcpserver.h"
#include "comsetupmenue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QComboBox * myComboBox;

    QString currentPortName;
    quint32 DefaultBaudRate;
    quint8 DefaultDataBits;
    quint8 DefaultStopBits;
    quint8 DefaultParity;
    quint8 DefaultFlowControl;
    com_port_driver * ComPort;

    UART_t uart;
    UART_t DefaultUartConfig;
    QLineEdit * OutLineEdits[50];
    QLineEdit * InLineEdits[50];
    QLineEdit * InLineEditCombined;
    com_queue_item_t Temp;

    void InitMyLineEdits(void);
    bool ComPortAlive;
    MyTcpServer * pMyServer;
    ComSetUpMenue MyComPortSetUpMenu;
private slots:
    void on_ConnectPushButton_clicked();
    void on_SendPushButton_clicked();
    void got_response(quint8 *, quint8);

    void on_DataOutLineEdit0_textChanged(const QString &arg1);

    void on_actionSETUP_COM_PORT_triggered();

signals:
    void send_data_out(com_queue_item_t);

};

#endif // MAINWINDOW_H
