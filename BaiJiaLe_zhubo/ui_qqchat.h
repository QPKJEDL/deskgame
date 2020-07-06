/********************************************************************************
** Form generated from reading UI file 'qqchat.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQCHAT_H
#define UI_QQCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQChat
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *QQChat)
    {
        if (QQChat->objectName().isEmpty())
            QQChat->setObjectName(QString::fromUtf8("QQChat"));
        QQChat->resize(480, 143);
        pushButton = new QPushButton(QQChat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;"));
        label = new QLabel(QQChat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 461, 71));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);border:1px solid ; border-radius: 8px;\n"
"background-color: rgb(170, 170, 127);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(QQChat);

        QMetaObject::connectSlotsByName(QQChat);
    } // setupUi

    void retranslateUi(QWidget *QQChat)
    {
        QQChat->setWindowTitle(QCoreApplication::translate("QQChat", "Form", nullptr));
        pushButton->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QQChat: public Ui_QQChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQCHAT_H
