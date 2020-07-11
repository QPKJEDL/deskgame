/********************************************************************************
** Form generated from reading UI file 'MSummit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSUMMIT_H
#define UI_MSUMMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MSummit
{
public:

    void setupUi(QWidget *MSummit)
    {
        if (MSummit->objectName().isEmpty())
            MSummit->setObjectName(QString::fromUtf8("MSummit"));
        MSummit->resize(742, 444);

        retranslateUi(MSummit);

        QMetaObject::connectSlotsByName(MSummit);
    } // setupUi

    void retranslateUi(QWidget *MSummit)
    {
        MSummit->setWindowTitle(QCoreApplication::translate("MSummit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MSummit: public Ui_MSummit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSUMMIT_H
