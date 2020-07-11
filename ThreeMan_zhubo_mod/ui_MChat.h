/********************************************************************************
** Form generated from reading UI file 'MChat.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCHAT_H
#define UI_MCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MChat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_id;

    void setupUi(QWidget *MChat)
    {
        if (MChat->objectName().isEmpty())
            MChat->setObjectName(QString::fromUtf8("MChat"));
        MChat->resize(973, 60);
        MChat->setMinimumSize(QSize(973, 60));
        MChat->setMaximumSize(QSize(973, 60));
        verticalLayout = new QVBoxLayout(MChat);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(MChat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(MChat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 40));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);border:1px solid ; border-radius: 8px;\n"
"background-color: rgb(170, 170, 127);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_id = new QLabel(MChat);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setEnabled(true);

        horizontalLayout->addWidget(label_id);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MChat);

        QMetaObject::connectSlotsByName(MChat);
    } // setupUi

    void retranslateUi(QWidget *MChat)
    {
        MChat->setWindowTitle(QCoreApplication::translate("MChat", "Form", nullptr));
        pushButton->setText(QString());
        label->setText(QString());
        label_id->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MChat: public Ui_MChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCHAT_H
