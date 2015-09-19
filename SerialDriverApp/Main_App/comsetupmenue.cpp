#include "comsetupmenue.h"


ComSetUpMenue::ComSetUpMenue(QWidget *parent) :
QWidget(parent),
ui(new Ui::ComSetUpMenue)
{
    ui->setupUi(this);
}

void ComSetUpMenue::PassUartPointer(UART_t *pMainWindowUart)
{
    pComSetUpUart = pMainWindowUart;
    DefaultBaudRate = 9600;
    DefaultDataBits = 8;
    DefaultStopBits = 2;
    DefaultParity = 0;
    DefaultFlowControl = 0;
    //ui->setupUi(this);
}



ComSetUpMenue::~ComSetUpMenue()
{
    qDebug() << "ComSetUpMenue::~ComSetUpMenue";
    delete ui;
}

void ComSetUpMenue::on_SetConfigPushButton_clicked()
{
    qDebug() << "exiting setup x1";
    close();
    delete ui;
}

void ComSetUpMenue::on_BaudRateComboBox_currentIndexChanged(int index)
{
    qDebug() << "ComSetUpMenue::on_BaudRateComboBox_currentIndexChanged";

    quint32 qTempBaud;
    QSerialPort::BaudRate TempBaudRate;
    qTempBaud = (quint32) index;
    switch(qTempBaud)
    {
        case 0:
            qTempBaud = 1200;
            TempBaudRate = QSerialPort::Baud1200;
        break;

        case 1:
            qTempBaud = 2400;
            TempBaudRate = QSerialPort::Baud2400;
        break;

        case 2:
            qTempBaud = 4800;
            TempBaudRate = QSerialPort::Baud4800;
        break;

        case 3:
            qTempBaud = 9600;
            TempBaudRate = QSerialPort::Baud9600;
        break;

        case 4:
            qTempBaud = 19200;
            TempBaudRate = QSerialPort::Baud19200;
        break;

        case 5:
            qTempBaud = 38400;
            TempBaudRate = QSerialPort::Baud38400;
        break;

        case 6:
            qTempBaud = 57600;
            TempBaudRate = QSerialPort::Baud57600;
        break;

        case 7:
            qTempBaud = 115200;
            TempBaudRate = QSerialPort::Baud115200;
        break;

        default:
            qTempBaud = DefaultBaudRate;
            TempBaudRate = QSerialPort::Baud9600;
        break;
    }

    pComSetUpUart->baud = TempBaudRate;
    qDebug() << "current baud rate index is: " << qTempBaud;
}

void ComSetUpMenue::on_ParityComboBox_currentIndexChanged(int index)
{
    qDebug() << "ComSetUpMenue::on_ParityComboBox_currentIndexChanged";
    if(0 == index)
    {
        DefaultParity = (quint8) index;
        pComSetUpUart->parity = QSerialPort::NoParity;
    }
    else if(1 == index)
    {
        DefaultParity = (quint8) (index + 1);
        pComSetUpUart->parity = QSerialPort::EvenParity;
    }
    else if(2 == index)
    {
        pComSetUpUart->parity = QSerialPort::OddParity;
    }
}

void ComSetUpMenue::on_DataBitsComboBox_currentIndexChanged(int index)
{
    qDebug() << "ComSetUpMenue::on_DataBitsComboBox_currentIndexChanged";
    DefaultDataBits = (quint8) (index + 5);
    pComSetUpUart->data_bits = (QSerialPort::DataBits) index;
}

void ComSetUpMenue::on_StopBitsComboBox_currentIndexChanged(int index)
{
    qDebug() << "ComSetUpMenue::on_StopBitsComboBox_currentIndexChanged";
    DefaultStopBits = (quint8) (index + 1);

    if(0 == index)
    {
        pComSetUpUart->stop_bits = QSerialPort::OneStop;
    }
    else
    {
        pComSetUpUart->stop_bits = QSerialPort::TwoStop;
    }
}

void ComSetUpMenue::on_FlowControlComboBox_currentIndexChanged(int index)
{
    qDebug() << "ComSetUpMenue::on_FlowControlComboBox_currentIndexChanged";
    DefaultFlowControl = (quint8) index;

    if(0 == index)
    {
        pComSetUpUart->flow_control = QSerialPort::NoFlowControl;
    }
    else
    {
        pComSetUpUart->flow_control = QSerialPort::HardwareControl;
    }
}

void ComSetUpMenue::on_ComSetUpMenue_destroyed()
{
    qDebug() << "ComSetUpMenue::on_ComSetUpMenue_destroyed";
}
