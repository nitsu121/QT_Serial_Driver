/********************************************************************************
** Form generated from reading UI file 'comsetupmenue.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMSETUPMENUE_H
#define UI_COMSETUPMENUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComSetUpMenue
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *ParityComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *DataBitsComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *FlowControlComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *StopBitsComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *BaudRateComboBox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SetConfigPushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ComSetUpMenue)
    {
        if (ComSetUpMenue->objectName().isEmpty())
            ComSetUpMenue->setObjectName(QStringLiteral("ComSetUpMenue"));
        ComSetUpMenue->resize(261, 235);
        verticalLayout_3 = new QVBoxLayout(ComSetUpMenue);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(ComSetUpMenue);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ParityComboBox = new QComboBox(ComSetUpMenue);
        ParityComboBox->setObjectName(QStringLiteral("ParityComboBox"));

        horizontalLayout_2->addWidget(ParityComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(ComSetUpMenue);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        DataBitsComboBox = new QComboBox(ComSetUpMenue);
        DataBitsComboBox->setObjectName(QStringLiteral("DataBitsComboBox"));

        horizontalLayout_3->addWidget(DataBitsComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(ComSetUpMenue);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        FlowControlComboBox = new QComboBox(ComSetUpMenue);
        FlowControlComboBox->setObjectName(QStringLiteral("FlowControlComboBox"));

        horizontalLayout_5->addWidget(FlowControlComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(ComSetUpMenue);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        StopBitsComboBox = new QComboBox(ComSetUpMenue);
        StopBitsComboBox->setObjectName(QStringLiteral("StopBitsComboBox"));

        horizontalLayout_4->addWidget(StopBitsComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ComSetUpMenue);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        BaudRateComboBox = new QComboBox(ComSetUpMenue);
        BaudRateComboBox->setObjectName(QStringLiteral("BaudRateComboBox"));

        horizontalLayout->addWidget(BaudRateComboBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        SetConfigPushButton = new QPushButton(ComSetUpMenue);
        SetConfigPushButton->setObjectName(QStringLiteral("SetConfigPushButton"));

        horizontalLayout_6->addWidget(SetConfigPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ComSetUpMenue);

        QMetaObject::connectSlotsByName(ComSetUpMenue);
    } // setupUi

    void retranslateUi(QWidget *ComSetUpMenue)
    {
        ComSetUpMenue->setWindowTitle(QApplication::translate("ComSetUpMenue", "Form", 0));
        label_2->setText(QApplication::translate("ComSetUpMenue", "PARITY:", 0));
        ParityComboBox->clear();
        ParityComboBox->insertItems(0, QStringList()
         << QApplication::translate("ComSetUpMenue", "NONE", 0)
         << QApplication::translate("ComSetUpMenue", "EVEN", 0)
         << QApplication::translate("ComSetUpMenue", "ODD", 0)
         << QApplication::translate("ComSetUpMenue", "SPACE", 0)
         << QApplication::translate("ComSetUpMenue", "MARK", 0)
        );
        label_3->setText(QApplication::translate("ComSetUpMenue", "DATA BITS:", 0));
        DataBitsComboBox->clear();
        DataBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("ComSetUpMenue", "7", 0)
         << QApplication::translate("ComSetUpMenue", "8", 0)
        );
        label_5->setText(QApplication::translate("ComSetUpMenue", "FLOW CONTROL:", 0));
        FlowControlComboBox->clear();
        FlowControlComboBox->insertItems(0, QStringList()
         << QApplication::translate("ComSetUpMenue", "NONE", 0)
         << QApplication::translate("ComSetUpMenue", "RTS/CTS", 0)
         << QApplication::translate("ComSetUpMenue", "XON/XOFF", 0)
        );
        label_4->setText(QApplication::translate("ComSetUpMenue", "STOP BITS:", 0));
        StopBitsComboBox->clear();
        StopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("ComSetUpMenue", "1", 0)
         << QApplication::translate("ComSetUpMenue", "2", 0)
         << QApplication::translate("ComSetUpMenue", "1.5", 0)
        );
        label->setText(QApplication::translate("ComSetUpMenue", "BAUD RATE:", 0));
        BaudRateComboBox->clear();
        BaudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("ComSetUpMenue", "1200", 0)
         << QApplication::translate("ComSetUpMenue", "2400", 0)
         << QApplication::translate("ComSetUpMenue", "4800", 0)
         << QApplication::translate("ComSetUpMenue", "9600", 0)
         << QApplication::translate("ComSetUpMenue", "19200", 0)
         << QApplication::translate("ComSetUpMenue", "38400", 0)
         << QApplication::translate("ComSetUpMenue", "57600", 0)
         << QApplication::translate("ComSetUpMenue", "115200", 0)
        );
        BaudRateComboBox->setCurrentText(QApplication::translate("ComSetUpMenue", "1200", 0));
        SetConfigPushButton->setText(QApplication::translate("ComSetUpMenue", "SET CONFIG", 0));
    } // retranslateUi

};

namespace Ui {
    class ComSetUpMenue: public Ui_ComSetUpMenue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMSETUPMENUE_H
