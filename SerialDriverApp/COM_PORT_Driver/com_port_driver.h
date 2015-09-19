#ifndef COM_PORT_DRIVER_H
#define COM_PORT_DRIVER_H
//Hello
#include "com_port_driver_global.h"
#include <QThread>
#include <QMutex>
#include <QString>
#include <QQueue>
#include <qstring.h>
#include <stdint.h>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>


//#define DEBUG_PRINT 1
#define DEBUG_SEND 1
#define DEBUG_RECIEVE 1
#define READ_READY_WAIT_TIME 100

//serial port defines
typedef enum {
    PARITY_NONE,PARITY_EVEN,PARITY_ODD
} UART_PARITY_t;
typedef enum {
    FLOW_RTS_CTS, FLOW_NONE
} UART_FLOW_CONTROL_t;
typedef enum {
    DATABITS_7,DATABITS_8
} UART_DATABITS_t;
typedef enum {
    STOPBITS_0,STOPBITS_1
} UART_STOPBITS_t;
typedef struct {
    QSerialPort::BaudRate baud;
    QSerialPort::Parity parity;
    QSerialPort::FlowControl flow_control;
    QSerialPort::DataBits data_bits;
    QSerialPort::StopBits stop_bits;
    quint8 PORT_NUMBER;
    QString PORT_NAME;
    QSerialPort::Direction direction;
}UART_t;

typedef enum{
    PRIORITY_LOW,PRIORITY_HIGH
}COM_QUEUE_PRIORITY_t;

#define COM_QUEUE_MAX_LEN 50

typedef struct {
    quint8 DataOut[COM_QUEUE_MAX_LEN];
    quint8 DataIn[COM_QUEUE_MAX_LEN];
    quint8 LengthIn;
    quint8 ResponceSizeExpected;
    quint8 LengthOut;
    COM_QUEUE_PRIORITY_t MyPriority;
} com_queue_item_t;

const int COM_BUF_LEN = 65535;

class COM_PORT_DRIVERSHARED_EXPORT com_port_driver : public QThread {
    Q_OBJECT

public:
    explicit com_port_driver(const UART_t *uart_config,QObject *parent = 0);

    void run(void);
    bool printf_packets;
    ~com_port_driver();

    int getQueueLength();
    void Kill_Thread(void);
    void Change_Read_Wait_Time(quint16 maxWaitTime);

    bool Running;
private:
    QMutex *queue_lock;
    //QSerialPort *ports;
    typedef enum
    {
        mb_wk_idle,
        mb_wk_bulk_file_write_start,
        mb_wk_bulk_file_write_in_progress,
        mb_wk_bulk_file_read_in_progress,
        mb_wk_bulk_file_write_cleanup
    } modbusState;

    int Justins_Windows_configured_Modbus_Init(UART_t * uart);
    QQueue<com_queue_item_t> queue;
    bool initialized;
    UART_t uart;
    modbusState mb_machine;

    int send_query(unsigned char *query, size_t string_length); // //////
    int receive_response(unsigned char *received_string); // ////////

    bool ThreadActive;

    quint16 ReadReadyWaitTime;

    QSerialPort *pSerialPort;

signals:
    void error(com_queue_item_t);
    void pushqueue(com_queue_item_t);
    void com_response(quint8 *, quint8);
    void Com_Port_Not_Conneted(void);
    void Com_Port_Connected(void);
public slots:
    void enqueue(com_queue_item_t);
};

#endif // MODBUSMASTER_H
