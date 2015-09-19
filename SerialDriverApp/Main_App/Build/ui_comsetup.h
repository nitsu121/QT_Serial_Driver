/********************************************************************************
** Form generated from reading UI file 'comsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMSETUP_H
#define UI_COMSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComSetup
{
public:

    void setupUi(QWidget *ComSetup)
    {
        if (ComSetup->objectName().isEmpty())
            ComSetup->setObjectName(QStringLiteral("ComSetup"));
        ComSetup->resize(400, 300);

        retranslateUi(ComSetup);

        QMetaObject::connectSlotsByName(ComSetup);
    } // setupUi

    void retranslateUi(QWidget *ComSetup)
    {
        ComSetup->setWindowTitle(QApplication::translate("ComSetup", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ComSetup: public Ui_ComSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMSETUP_H
