/********************************************************************************
** Form generated from reading UI file 'MDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIALOG_H
#define UI_MDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label;
    QPushButton *pu_yes;
    QPushButton *pu_no;

    void setupUi(QDialog *MDialog)
    {
        if (MDialog->objectName().isEmpty())
            MDialog->setObjectName(QString::fromUtf8("MDialog"));
        MDialog->resize(400, 300);
        MDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        verticalLayout = new QVBoxLayout(MDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 250);border:1px solid grey; border-radius: 25px;"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 382, 138));
        QFont font;
        font.setPointSize(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-color: transparent;"));
        label->setAlignment(Qt::AlignCenter);
        pu_yes = new QPushButton(widget);
        pu_yes->setObjectName(QString::fromUtf8("pu_yes"));
        pu_yes->setGeometry(QRect(50, 210, 101, 51));
        pu_yes->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));border:1px solid grey; border-radius: 25px;}\n"
"QPushButton:pressed{border:1px solid grey; border-radius: 25px;\n"
"background-color: rgb(148, 148, 148);}\n"
""));
        pu_no = new QPushButton(widget);
        pu_no->setObjectName(QString::fromUtf8("pu_no"));
        pu_no->setGeometry(QRect(250, 210, 101, 51));
        pu_no->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));border:1px solid grey; border-radius: 25px;}\n"
"QPushButton:pressed{border:1px solid grey; border-radius: 25px;\n"
"background-color: rgb(148, 148, 148);}\n"
""));

        verticalLayout->addWidget(widget);


        retranslateUi(MDialog);

        QMetaObject::connectSlotsByName(MDialog);
    } // setupUi

    void retranslateUi(QDialog *MDialog)
    {
        MDialog->setWindowTitle(QCoreApplication::translate("MDialog", "Dialog", nullptr));
        label->setText(QString());
        pu_yes->setText(QCoreApplication::translate("MDialog", "\347\241\256\345\256\232", nullptr));
        pu_no->setText(QCoreApplication::translate("MDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MDialog: public Ui_MDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIALOG_H
