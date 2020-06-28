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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QComboBox *comboBox;
    QPushButton *enter;
    QPushButton *cancel;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *userid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *passwd;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(595, 400);
        Login->setMinimumSize(QSize(595, 400));
        Login->setStyleSheet(QString::fromUtf8("width:585px;\n"
"height:394px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(81, 81, 118, 255), stop:1 rgba(46, 48, 74, 255));"));
        comboBox = new QComboBox(Login);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 10, 439, 79));
        comboBox->setMinimumSize(QSize(439, 79));
        comboBox->setStyleSheet(QString::fromUtf8("background:rgba(39,39,57,1);\n"
"border-radius:5px;"));
        enter = new QPushButton(Login);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setEnabled(true);
        enter->setGeometry(QRect(100, 220, 387, 80));
        enter->setMinimumSize(QSize(387, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(30);
        enter->setFont(font);
        enter->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));
        cancel = new QPushButton(Login);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(100, 310, 387, 80));
        cancel->setMinimumSize(QSize(387, 80));
        cancel->setFont(font);
        cancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(628, 36, 54, 16));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 100, 493, 98));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: transparent;"));

        horizontalLayout->addWidget(label_2);

        userid = new QLineEdit(layoutWidget);
        userid->setObjectName(QString::fromUtf8("userid"));
        userid->setMinimumSize(QSize(300, 42));
        userid->setStyleSheet(QString::fromUtf8("width:305px;\n"
"height:43px;\n"
"background:rgba(255,255,255,1);\n"
"border-radius:4px;"));

        horizontalLayout->addWidget(userid);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: transparent;"));

        horizontalLayout_2->addWidget(label_3);

        passwd = new QLineEdit(layoutWidget);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setMinimumSize(QSize(300, 42));
        passwd->setStyleSheet(QString::fromUtf8("width:305px;\n"
"height:43px;\n"
"background:rgba(255,255,255,1);\n"
"border-radius:4px;"));

        horizontalLayout_2->addWidget(passwd);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Login", "A1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Login", "A2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Login", "A3", nullptr));

        enter->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        enter->setShortcut(QCoreApplication::translate("Login", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        cancel->setText(QCoreApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\344\270\273\346\222\255\350\215\267\345\256\230\350\264\246\345\217\267  ", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\344\270\273\346\222\255\350\215\267\345\256\230\345\257\206\347\240\201  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
