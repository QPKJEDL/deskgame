/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *userid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *passwd;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pu_enter;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pu_cancel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(975, 700);
        Login->setStyleSheet(QString::fromUtf8("width:585px;\n"
"height:394px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(81, 81, 118, 255), stop:1 rgba(46, 48, 74, 255));"));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        comboBox = new QComboBox(Login);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(16777215, 130));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(30);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("background:rgba(39,39,57,1);\n"
"border-radius:5px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(comboBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: transparent;"));

        horizontalLayout->addWidget(label_2);

        userid = new QLineEdit(Login);
        userid->setObjectName(QString::fromUtf8("userid"));
        userid->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(25);
        userid->setFont(font2);
        userid->setStyleSheet(QString::fromUtf8("width:305px;\n"
"height:43px;\n"
"background:rgba(255,255,255,1);\n"
"border-radius:4px;"));

        horizontalLayout->addWidget(userid);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: transparent;"));

        horizontalLayout_2->addWidget(label_3);

        passwd = new QLineEdit(Login);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setMaximumSize(QSize(16777215, 100));
        passwd->setFont(font2);
        passwd->setStyleSheet(QString::fromUtf8("width:305px;\n"
"height:43px;\n"
"background:rgba(255,255,255,1);\n"
"border-radius:4px;"));
        passwd->setEchoMode(QLineEdit::Password);
        passwd->setDragEnabled(true);

        horizontalLayout_2->addWidget(passwd);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pu_enter = new QPushButton(Login);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setMaximumSize(QSize(16777215, 100));
        pu_enter->setFont(font);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));

        horizontalLayout_3->addWidget(pu_enter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pu_cancel = new QPushButton(Login);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setMaximumSize(QSize(16777215, 100));
        pu_cancel->setFont(font);
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));

        horizontalLayout_4->addWidget(pu_cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Login", "\351\276\231\350\231\216\357\274\210CS2\357\274\211", nullptr));

        label_2->setText(QCoreApplication::translate("Login", "\344\270\273\346\222\255\350\215\267\345\256\230\350\264\246\345\217\267  ", nullptr));
        userid->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", "\344\270\273\346\222\255\350\215\267\345\256\230\345\257\206\347\240\201  ", nullptr));
        passwd->setText(QString());
        pu_enter->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("Login", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_cancel->setText(QCoreApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H