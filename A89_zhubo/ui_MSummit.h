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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MSummit
{
public:
    QPushButton *yes;
    QPushButton *no;
    QLabel *label;

    void setupUi(QWidget *MSummit)
    {
        if (MSummit->objectName().isEmpty())
            MSummit->setObjectName(QString::fromUtf8("MSummit"));
        MSummit->resize(481, 255);
        MSummit->setMinimumSize(QSize(481, 255));
        MSummit->setMaximumSize(QSize(481, 255));
        MSummit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 250);"));
        yes = new QPushButton(MSummit);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(70, 180, 111, 51));
        yes->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background:rgb(252, 238, 205);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(148, 148, 148);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));
        no = new QPushButton(MSummit);
        no->setObjectName(QString::fromUtf8("no"));
        no->setGeometry(QRect(290, 180, 101, 51));
        no->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background:rgb(252, 238, 205);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(148, 148, 148);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));
        label = new QLabel(MSummit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 70, 211, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(30);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(MSummit);

        QMetaObject::connectSlotsByName(MSummit);
    } // setupUi

    void retranslateUi(QWidget *MSummit)
    {
        MSummit->setWindowTitle(QCoreApplication::translate("MSummit", "Form", nullptr));
        yes->setText(QCoreApplication::translate("MSummit", "\347\241\256\350\256\244", nullptr));
        no->setText(QCoreApplication::translate("MSummit", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("MSummit", "\347\241\256\350\256\244\346\217\220\344\272\244\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MSummit: public Ui_MSummit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSUMMIT_H
