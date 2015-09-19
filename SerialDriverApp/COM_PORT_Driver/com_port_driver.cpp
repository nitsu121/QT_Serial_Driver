#include "com_port_driver.h"
#include <errno.h>//errors
#include <string.h>//strn
#include <sys/time.h>
#include <sys/stat.h>

#include <QDataStream>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#define MODBUS_MASTER_DEBUG_PRINT 1
#define MODBUS_MASTER_DEBUG_PRINT_ON 1
#define MODBUS_MASTER_DEBUG_PRINT_ON_RUN 1
#define MODBUS "MODBUS "

com_port_driver::com_port_driver(const UART_t * uart_config,QObject *parent) :
    QThread(parent)
{
    Running = 0;
    #if MODBUS_MASTER_DEBUG_PRINT_ON
        qDebug("com_port_driver INIT NO QSERIAL");
    #endif
    ReadReadyWaitTime = READ_READY_WAIT_TIME;
    memcpy(&uart,uart_config,sizeof(UART_t)); //keep a local copy of the config
    this->printf_packets = false;
    mb_machine = mb_wk_idle;

    connect(this,SIGNAL(pushqueue(com_queue_item_t)),
            this,SLOT(enqueue(com_queue_item_t)),Qt::DirectConnection);
}

com_port_driver::~com_port_driver()
{
    #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("com_port_driver::~com_port_driver()");
    #endif
}

void com_port_driver::Kill_Thread(void)
{
#if MODBUS_MASTER_DEBUG_PRINT
    qDebug("com_port_driver::Kill_Thread");
#endif
    ThreadActive = 0;
}

void com_port_driver::run(void)
{
    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("run");
    #endif
    Running = 1;
    int status = 0;
    ThreadActive = 1;
    queue_lock = new QMutex;
    pSerialPort = new QSerialPort;

    status = Justins_Windows_configured_Modbus_Init(&uart);
    //MB_Portable_Uart_Init();    //init uart portable function
    //MB_Enable_Rx();             //start in rx mode

    if(status != 0)
    {
        #if MODBUS_MASTER_DEBUG_PRINT
            qDebug("com_port_driver::run got into: (status !=0) were good");
        #endif
    }
    else
    {
        #if MODBUS_MASTER_DEBUG_PRINT
            qDebug("com_port_driver::run got into: else were exiting.");
        #endif
        return;  //failed to open serial port
    }

    while(ThreadActive)
    {
        //read queue
        com_queue_item_t obj;
        if(!queue.isEmpty())
        {
            #if MODBUS_MASTER_DEBUG_PRINT
            qDebug("com_port_driver::run Queue is not empty");
            #endif
            queue_lock->lock();
            obj = queue.dequeue();
            queue_lock->unlock();

            //send_query(unsigned char *query, size_t string_length);
            send_query(obj.DataOut, obj.LengthOut);
            if(0 == obj.ResponceSizeExpected)
            {
                #if MODBUS_MASTER_DEBUG_PRINT
                qDebug("com_port_driver::run() Not going to check for recieved bytes.");
                #endif
            }
            else
            {
                #if MODBUS_MASTER_DEBUG_PRINT
                qDebug("com_port_driver::run() Are Going to check for recieved bytes.");
                #endif
                //receive_response(unsigned char *received_string);
                obj.LengthIn = receive_response(obj.DataIn);
                //quint8 *, quint8
                if(0 == obj.LengthIn)
                {
                    #if MODBUS_MASTER_DEBUG_PRINT
                    qDebug("com_port_driver::run() got 0 RX bytes");
                    #endif
                }
                else
                {
                    #if MODBUS_MASTER_DEBUG_PRINT
                    qDebug("com_port_driver::run() got some RX bytes");
                    qDebug() << "com_port_driver::run() got" << obj.LengthIn << "Data bytes.";
                    #endif
                    emit com_response(obj.DataIn, obj.LengthIn);
                }

            }
        }
        usleep(1000);
        //usleep(500);
    }

    #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("com_port_driver::run not in while");
    #endif
    #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("We are closing our port!!!!");
    #endif
    pSerialPort->close(); // c(QIODevice::ReadWrite)
    Running = 0;
    return;
}

//  Add an item to the modbus queue with passed parameters.
//
//  addr: address for the new request
//  priority: boolean
//  reg: holding/file/input register to read/write
//  (list) value: value/s to write/of read MUST HAVE LENGTH >= 1
//  id: callback id
//  type: modbus command type
//  fileName: name of file for modbus file transfers (read will create new file and write to it, write will
//      attempt to open file and write blocks to slave) defaults to ""
//
void com_port_driver::enqueue(com_queue_item_t ThisQueue)
{
    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    qDebug("enqueue");
    #endif
    int i;

    if(queue.length() >= COM_BUF_LEN)
    {
        //TODO:: emit error(/*this queue item*/);
        return; //fail hard? thats fucking silly.
    }

    com_queue_item_t obj;
    obj.LengthOut = ThisQueue.LengthOut;
    obj.ResponceSizeExpected = ThisQueue.ResponceSizeExpected;

    if(ThisQueue.LengthOut > COM_QUEUE_MAX_LEN)
        ThisQueue.LengthOut = COM_QUEUE_MAX_LEN;
    for(i=0;i<ThisQueue.LengthOut;i++) {
        obj.DataOut[i] = ThisQueue.DataOut[i];
    }
    if(ThisQueue.MyPriority)
    {
        int i=0;

        for(; i < queue.length(); i++)                //loop until queue item is !priority
            if(!queue[i].MyPriority)
                break;

        queue_lock->lock();
        queue.insert(i,obj);                        //insert item at first place that is not prioritized
        queue_lock->unlock();
    }else
    {
        queue_lock->lock();
        queue.append(obj);
        queue_lock->unlock();
    }
}


/***********************************************************************
 send_query( file_descriptor, query_string, query_length )
 Function to send a query out to a modbus slave.
 ************************************************************************/
int com_port_driver::send_query(unsigned char *query, size_t string_length)
{
    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("send_query");
    #endif
    int write_stat = 0;

    QDataStream stream(pSerialPort);

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug() << "String Length:" << string_length;
    #endif

    // This is the new version of flush.
    if(pSerialPort->clear(QSerialPort::AllDirections))
    {
    #if MODBUS_MASTER_DEBUG_PRINT
        qDebug() << "com_port_driver::send_query    Successfully cleared the in and out buffer";
    #endif

    }
    else
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug() << "com_port_driver::send_query    We DID NOT clear the in and out buffer";
        #endif
    }

#if 0
    if (this->printf_packets)
    {
        for (i = 0; i < (int)string_length; i++)
        {
#if MODBUS_MASTER_DEBUG_PRINT
            if(DEBUG_SEND)
            {
                qDebug() << "i" << i << "query[i]" << query[i];
            }
#endif
        }
    }
#endif

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("NowWriting");
    #endif
    stream.writeRawData((const char *)query, string_length);

    int TempOutputDataCounter = 0;
    while(string_length > TempOutputDataCounter)
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug() << "Sending: " << query[TempOutputDataCounter];
        #endif
        TempOutputDataCounter++;
    }

    if (pSerialPort->waitForBytesWritten(100))
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("We did not timeout");
        #endif
    }
    else
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("We DID timeout");
        #endif
    }

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("Just wrote some stuff");
    #endif

    return (write_stat);
}


/***********************************************************************
 receive_response( array_for_data )
 Function to monitor for the reply from the modbus slave.
 This function blocks for timeout seconds if there is no reply.

 Returns:	Total number of characters received.
 ***********************************************************************/
int com_port_driver::receive_response(unsigned char * received_string)
{
    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("receive_response");
    #endif
    unsigned char rxchar;
    int bytes_received = 0;

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug() << "Bytest recieved is:" << bytes_received;
    #endif

    QDataStream stream(pSerialPort);

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("We are going to wait read_ready for 100 ms");
    #endif

    bool AreWeDoneYet = 0;

    if (pSerialPort->waitForReadyRead(ReadReadyWaitTime))
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug() << "a Bytest recieved is:" << bytes_received;
        #endif
        while(0 == AreWeDoneYet)
        {
            #if MODBUS_MASTER_DEBUG_PRINT
            qDebug() << "B Bytest recieved is:" << bytes_received;
            #endif
            while(1 == stream.readRawData((char *)&rxchar, 1))
            {
            #if MODBUS_MASTER_DEBUG_PRINT
            qDebug() << "C Bytest recieved is:" << bytes_received;
            qDebug() << "we got a:" << rxchar << " At recieved byte number: " << bytes_received;
            #endif

         #if MODBUS_MASTER_DEBUG_PRINT
                if(MODBUS_MASTER_DEBUG_PRINT | DEBUG_RECIEVE)
                {
                    qDebug() << "we got a:" << rxchar << " At recieved byte number: " << bytes_received;
                }
         #endif
                received_string[bytes_received] = rxchar;
                bytes_received++;
            }

            if (pSerialPort->waitForReadyRead(ReadReadyWaitTime))
            {

            }
            else
            {
                AreWeDoneYet = 1;
            }
        }
    }
    else
    {
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug() << "Sad, we didn't read anything";
        #endif
    }
    #if MODBUS_MASTER_DEBUG_PRINT
    if (this->printf_packets)
    {
        printf("\n");
    }
    #endif

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug() << "Bytest recieved is:" << bytes_received;
    #endif

    return (bytes_received);
}

void com_port_driver::Change_Read_Wait_Time(quint16 maxWaitTime)
{
    ReadReadyWaitTime = maxWaitTime;
}

/*
 * initalize modbus uart
 * @param uart descriptor
 * @return: 0 success
 *          anything else error
 */
//int com_port_driver::MB_Init_Uart(LINUX_UART_t * uart)
int com_port_driver::Justins_Windows_configured_Modbus_Init(UART_t * uart)
{
    pSerialPort->setPortName(uart->PORT_NAME);

    #if MODBUS_MASTER_DEBUG_PRINT_ON
    qDebug("port name is:"); //<< "port name is:" << pSerial->portName();
    #endif
    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug(qPrintable(uart->PORT_NAME));
    #endif
    if (!pSerialPort->open(QIODevice::ReadWrite))
    {
       // emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial->error()));
        #if MODBUS_MASTER_DEBUG_PRINT
        qDebug("Can't open port");
        #endif

        return(0);
    }
    else
    {

    }

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("We got it open!");
    #endif

    uart->flow_control = QSerialPort::NoFlowControl;
    pSerialPort->setFlowControl(uart->flow_control);
    pSerialPort->setBaudRate(uart->baud);

    #if MODBUS_MASTER_DEBUG_PRINT
    qDebug("Here 3");
    #endif
    pSerialPort->setDataBits( uart->data_bits);
    pSerialPort->setStopBits((QSerialPort::StopBits) uart->stop_bits);
    pSerialPort->setParity((QSerialPort::Parity) uart->parity);
    #if MODBUS_MASTER_DEBUG_PRINT_ON
    qDebug("Here 2");
    #endif

    return (1);
}


