#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMyServer = new MyTcpServer(this); //MyTcpServer *
    ComPortAlive = 0;
    myComboBox = new QComboBox(this);
    ui->mainToolBar->addWidget(myComboBox);
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
    {
        myComboBox->addItem(info.portName());
    }

    uart.PORT_NAME = myComboBox->itemText(0);
    //uart.baud = QSerialPort::Baud57600;
    uart.baud = QSerialPort::Baud1200;
    DefaultDataBits = 8;
    uart.data_bits = QSerialPort::Data8;
    DefaultStopBits = QSerialPort::OneStop;
    uart.stop_bits = QSerialPort::OneStop;
    DefaultParity = 0;
    uart.parity = QSerialPort::NoParity;
    DefaultFlowControl = 0;
    uart.flow_control = QSerialPort::NoFlowControl;

    InitMyLineEdits();

    quint8 Count = 0;
#if 0
    while(50 > Count)
    {
        InLineEdits[Count]->setText("");
        InLineEdits[Count]->setEnabled(0);

        OutLineEdits[Count]->setText("");
        OutLineEdits[Count]->setEnabled(0);

        Count++;
    }

    OutLineEdits[0]->setEnabled(1);
#endif
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "were in the close event.";
    if(1 == ComPortAlive)
    {
        ComPort->Kill_Thread(); // /////////////////////////////////
        while(1 == ComPort->Running)
        {
            // dont exit untill the thread has closed.
        }
    }
    else
    {
    }

    delete ui;
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow";
}

void MainWindow::on_ConnectPushButton_clicked()
{
    uart.PORT_NAME = myComboBox->currentText();
    ComPort = new com_port_driver(&uart, this);

    connect(this,SIGNAL(send_data_out(com_queue_item_t)),
            ComPort, SLOT(enqueue(com_queue_item_t)));

    connect(ComPort, SIGNAL(com_response(quint8 *, quint8)),
            this, SLOT(got_response(quint8 *, quint8)));

    ComPort->start();
    ComPortAlive = 1;
}

void MainWindow::on_SendPushButton_clicked()
{
    quint8 Counter = 0;
    bool Done = 1;

    while(1 == Done)
    {
        if("" == OutLineEdits[Counter]->text())
        {
            Done = 0;
        }
        else
        {
            Temp.DataOut[Counter] = OutLineEdits[Counter]->text().toInt();
            Counter++;
        }
    }

    Temp.MyPriority = PRIORITY_HIGH;
    Temp.LengthOut = Counter;
    Temp.ResponceSizeExpected = Counter;

    emit(send_data_out(Temp));
}

void MainWindow::got_response(quint8 * DataBack, quint8 Length)
{
    quint8 Count = 0;
    quint8 Count2 = 0;
    quint16 DBArray[50];
    QString Temp;
    quint8 HalfCounter = Length/2;

    while(50 > Count)
    {
        InLineEdits[Count]->setText("");
        DBArray[Count] = 0;
        Count++;
    }

    Count = 0;

    while(Length > Count)
    {
        Temp = "";
        Temp.append(QString("%1").arg(DataBack[Count]));
        InLineEdits[Count]->setText(Temp);
        if(0 == (Count & 1))
        {
            DBArray[Count >> 1] = DataBack[Count] << 8;
        }
        else
        {
            DBArray[Count >> 1] += DataBack[Count];
        }

        Count++;
    }

    Temp = "";

    while(Count > Count2)
    {
        Temp.append(QString("%1").arg(DBArray[Count2]));
        Temp.append(",");
        InLineEditCombined->setText(Temp);
        Count2++;
    }



    //InLineEditCombined
}


void MainWindow::InitMyLineEdits()
{
    OutLineEdits[0] = ui->DataOutLineEdit0;
    OutLineEdits[1] = ui->DataOutLineEdit1;
    OutLineEdits[2] = ui->DataOutLineEdit2;
    OutLineEdits[3] = ui->DataOutLineEdit3;
    OutLineEdits[4] = ui->DataOutLineEdit4;
    OutLineEdits[5] = ui->DataOutLineEdit5;
    OutLineEdits[6] = ui->DataOutLineEdit6;
    OutLineEdits[7] = ui->DataOutLineEdit7;
    OutLineEdits[8] = ui->DataOutLineEdit8;
    OutLineEdits[9] = ui->DataOutLineEdit9;

    OutLineEdits[10] = ui->DataOutLineEdit10;
    OutLineEdits[11] = ui->DataOutLineEdit11;
    OutLineEdits[12] = ui->DataOutLineEdit12;
    OutLineEdits[13] = ui->DataOutLineEdit13;
    OutLineEdits[14] = ui->DataOutLineEdit14;
    OutLineEdits[15] = ui->DataOutLineEdit15;
    OutLineEdits[16] = ui->DataOutLineEdit16;
    OutLineEdits[17] = ui->DataOutLineEdit17;
    OutLineEdits[18] = ui->DataOutLineEdit18;
    OutLineEdits[19] = ui->DataOutLineEdit19;

    OutLineEdits[20] = ui->DataOutLineEdit20;
    OutLineEdits[21] = ui->DataOutLineEdit21;
    OutLineEdits[22] = ui->DataOutLineEdit22;
    OutLineEdits[23] = ui->DataOutLineEdit23;
    OutLineEdits[24] = ui->DataOutLineEdit24;
    OutLineEdits[25] = ui->DataOutLineEdit25;
    OutLineEdits[26] = ui->DataOutLineEdit26;
    OutLineEdits[27] = ui->DataOutLineEdit27;
    OutLineEdits[28] = ui->DataOutLineEdit28;
    OutLineEdits[29] = ui->DataOutLineEdit29;

    OutLineEdits[30] = ui->DataOutLineEdit30;
    OutLineEdits[31] = ui->DataOutLineEdit31;
    OutLineEdits[32] = ui->DataOutLineEdit32;
    OutLineEdits[33] = ui->DataOutLineEdit33;
    OutLineEdits[34] = ui->DataOutLineEdit34;
    OutLineEdits[35] = ui->DataOutLineEdit35;
    OutLineEdits[36] = ui->DataOutLineEdit36;
    OutLineEdits[37] = ui->DataOutLineEdit37;
    OutLineEdits[38] = ui->DataOutLineEdit38;
    OutLineEdits[39] = ui->DataOutLineEdit39;

    OutLineEdits[40] = ui->DataOutLineEdit40;
    OutLineEdits[41] = ui->DataOutLineEdit41;
    OutLineEdits[42] = ui->DataOutLineEdit42;
    OutLineEdits[43] = ui->DataOutLineEdit43;
    OutLineEdits[44] = ui->DataOutLineEdit44;
    OutLineEdits[45] = ui->DataOutLineEdit45;
    OutLineEdits[46] = ui->DataOutLineEdit46;
    OutLineEdits[47] = ui->DataOutLineEdit47;
    OutLineEdits[48] = ui->DataOutLineEdit48;
    OutLineEdits[49] = ui->DataOutLineEdit49;

//DataInLineEdit0_2
    InLineEdits[0] = ui->DataInLineEdit0;
    InLineEdits[10] = ui->DataInLineEdit0_2;
    InLineEdits[20] = ui->DataInLineEdit0_3;
    InLineEdits[30] = ui->DataInLineEdit0_4;
    InLineEdits[40] = ui->DataInLineEdit0_5;

    InLineEdits[1] = ui->DataInLineEdit1;
    InLineEdits[11] = ui->DataInLineEdit1_2;
    InLineEdits[21] = ui->DataInLineEdit1_3;
    InLineEdits[31] = ui->DataInLineEdit1_4;
    InLineEdits[41] = ui->DataInLineEdit1_5;

    InLineEdits[2] = ui->DataInLineEdit2;
    InLineEdits[12] = ui->DataInLineEdit2_2;
    InLineEdits[22] = ui->DataInLineEdit2_3;
    InLineEdits[32] = ui->DataInLineEdit2_4;
    InLineEdits[42] = ui->DataInLineEdit2_5;

    InLineEdits[3] = ui->DataInLineEdit3;
    InLineEdits[13] = ui->DataInLineEdit3_2;
    InLineEdits[23] = ui->DataInLineEdit3_3;
    InLineEdits[33] = ui->DataInLineEdit3_4;
    InLineEdits[43] = ui->DataInLineEdit3_5;

    InLineEdits[4] = ui->DataInLineEdit4;
    InLineEdits[14] = ui->DataInLineEdit4_2;
    InLineEdits[24] = ui->DataInLineEdit4_3;
    InLineEdits[34] = ui->DataInLineEdit4_4;
    InLineEdits[44] = ui->DataInLineEdit4_5;

    InLineEdits[5] = ui->DataInLineEdit5;
    InLineEdits[15] = ui->DataInLineEdit5_2;
    InLineEdits[25] = ui->DataInLineEdit5_3;
    InLineEdits[35] = ui->DataInLineEdit5_4;
    InLineEdits[45] = ui->DataInLineEdit5_5;

    InLineEdits[6] = ui->DataInLineEdit6;
    InLineEdits[16] = ui->DataInLineEdit6_2;
    InLineEdits[26] = ui->DataInLineEdit6_3;
    InLineEdits[36] = ui->DataInLineEdit6_4;
    InLineEdits[46] = ui->DataInLineEdit6_5;

    InLineEdits[7] = ui->DataInLineEdit7;
    InLineEdits[17] = ui->DataInLineEdit7_2;
    InLineEdits[27] = ui->DataInLineEdit7_3;
    InLineEdits[37] = ui->DataInLineEdit7_4;
    InLineEdits[47] = ui->DataInLineEdit7_5;

    InLineEdits[8] = ui->DataInLineEdit8;
    InLineEdits[18] = ui->DataInLineEdit8_2;
    InLineEdits[28] = ui->DataInLineEdit8_3;
    InLineEdits[38] = ui->DataInLineEdit8_4;
    InLineEdits[48] = ui->DataInLineEdit8_5;

    InLineEdits[9] = ui->DataInLineEdit9;
    InLineEdits[19] = ui->DataInLineEdit9_2;
    InLineEdits[29] = ui->DataInLineEdit9_3;
    InLineEdits[39] = ui->DataInLineEdit9_4;
    InLineEdits[49] = ui->DataInLineEdit9_5;

    InLineEditCombined = ui->DataInLineEditCombined;
}

void MainWindow::on_DataOutLineEdit0_textChanged(const QString &arg1)
{
#if 0
    bool ok = 0;
    int Temp = 0;

    if("" == arg1)
    {
        OutLineEdits[1]->setEnabled(0);
    }
    else if(" " == arg1)
    {
        OutLineEdits[0]->setText("");
    }
    else
    {
        Temp = arg1.toInt(&ok, 10);

        if(1 == ok)
        {
            OutLineEdits[1]->setEnabled(1);
        }
        else
        {
            OutLineEdits[0]->setText("");
        }
    }
#endif
}

void MainWindow::on_actionSETUP_COM_PORT_triggered()
{
    //MyComPortSetUpMenu = new ComSetUpMenue(this);
    //PassUartPointer(UART_t *pMainWindowUart)
    MyComPortSetUpMenu.PassUartPointer(&uart);
    MyComPortSetUpMenu.show();
}
