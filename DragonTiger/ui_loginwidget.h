/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QComboBox *comboBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(600, 400);
        Form->setMinimumSize(QSize(600, 400));
        comboBox = new QComboBox(Form);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 50, 439, 79));
        comboBox->setMinimumSize(QSize(439, 79));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(30);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("background:rgba(39,39,57,1);\n"
"border-radius:5px;\n"
"color: rgb(255, 255, 255);"));
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 190, 389, 168));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pu_enter = new QPushButton(widget);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setMinimumSize(QSize(387, 80));
        pu_enter->setFont(font);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));

        verticalLayout->addWidget(pu_enter);

        pu_cancel = new QPushButton(widget);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setMinimumSize(QSize(387, 80));
        pu_cancel->setFont(font);
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(167, 38, 35, 255), stop:1 rgba(255, 118, 96, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;}\n"
"QPushButton::pressed{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 118, 96, 255), stop:1 rgba(167, 38, 35, 255));\n"
"box-shadow:0px 2px 9px 0px rgba(0, 0, 0, 0.77);\n"
"border-radius:16px;\n"
"}"));

        verticalLayout->addWidget(pu_cancel);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Form", "\347\231\276\345\256\266\344\271\220\357\274\210CS1\357\274\211", nullptr));

        pu_enter->setText(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
        pu_cancel->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
