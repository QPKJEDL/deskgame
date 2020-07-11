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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQChat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *QQChat)
    {
        if (QQChat->objectName().isEmpty())
            QQChat->setObjectName(QString::fromUtf8("QQChat"));
        QQChat->resize(1450, 60);
        QQChat->setMinimumSize(QSize(1450, 60));
        QQChat->setMaximumSize(QSize(1450, 60));
        verticalLayout = new QVBoxLayout(QQChat);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(QQChat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(QQChat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 40));
        label->setMaximumSize(QSize(16777215, 40));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);border:1px solid ; border-radius: 8px;\n"
"background-color: rgb(204, 168, 89);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


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
