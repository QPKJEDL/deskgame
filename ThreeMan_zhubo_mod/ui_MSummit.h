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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MSummit
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *MSummit)
    {
        if (MSummit->objectName().isEmpty())
            MSummit->setObjectName(QString::fromUtf8("MSummit"));
        MSummit->resize(742, 444);
        pushButton = new QPushButton(MSummit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 280, 91, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background: rgb(252, 238, 205);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(153, 118, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}\n"
"background-color: ;\n"
"color:;"));

        retranslateUi(MSummit);

        QMetaObject::connectSlotsByName(MSummit);
    } // setupUi

    void retranslateUi(QWidget *MSummit)
    {
        MSummit->setWindowTitle(QCoreApplication::translate("MSummit", "Form", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MSummit: public Ui_MSummit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSUMMIT_H
