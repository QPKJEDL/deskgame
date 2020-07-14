/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_result;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_desk_id;
    QLabel *label_3;
    QLabel *label_boot;
    QLabel *label_4;
    QLabel *label_pave;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(454, 297);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 39);"));
        label_result = new QLabel(Form);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setGeometry(QRect(10, 110, 431, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(40);
        label_result->setFont(font);
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(170, 0, 0);"));
        label_result->setAlignment(Qt::AlignCenter);
        pu_enter = new QPushButton(Form);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setGeometry(QRect(90, 240, 75, 31));
        pu_enter->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 197, 132);"));
        pu_cancel = new QPushButton(Form);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setGeometry(QRect(300, 240, 75, 31));
        pu_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 197, 132);"));
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 416, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);

        label_desk_id = new QLabel(layoutWidget);
        label_desk_id->setObjectName(QString::fromUtf8("label_desk_id"));
        label_desk_id->setFont(font1);
        label_desk_id->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_desk_id);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        label_boot = new QLabel(layoutWidget);
        label_boot->setObjectName(QString::fromUtf8("label_boot"));
        label_boot->setFont(font1);
        label_boot->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_boot);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_4);

        label_pave = new QLabel(layoutWidget);
        label_pave->setObjectName(QString::fromUtf8("label_pave"));
        label_pave->setFont(font1);
        label_pave->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_pave);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_result->setText(QCoreApplication::translate("Form", "\345\272\204\350\265\242", nullptr));
        pu_enter->setText(QCoreApplication::translate("Form", "\347\241\256\345\256\232", nullptr));
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("Form", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_cancel->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
#if QT_CONFIG(shortcut)
        pu_cancel->setShortcut(QCoreApplication::translate("Form", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("Form", "\345\217\260\346\241\214\345\217\267", nullptr));
        label_desk_id->setText(QString());
        label_3->setText(QCoreApplication::translate("Form", "\351\235\264\346\254\241", nullptr));
        label_boot->setText(QString());
        label_4->setText(QCoreApplication::translate("Form", "\351\223\272\346\254\241", nullptr));
        label_pave->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
