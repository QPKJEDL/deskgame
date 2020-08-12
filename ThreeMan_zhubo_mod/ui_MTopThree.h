/********************************************************************************
** Form generated from reading UI file 'MTopThree.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTOPTHREE_H
#define UI_MTOPTHREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MTopThree
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_134;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_first_bet;
    QLabel *label_11;
    QLabel *label_first_name;
    QLabel *label_second_name;
    QLabel *label_first_money;
    QLabel *label_second_bet;
    QLabel *label_13;
    QLabel *label_second_money;
    QLabel *label_3;
    QLabel *label_16;
    QLabel *label_third_name;
    QLabel *label_18;
    QLabel *label_third_bet;
    QLabel *label_third_money;

    void setupUi(QWidget *MTopThree)
    {
        if (MTopThree->objectName().isEmpty())
            MTopThree->setObjectName(QString::fromUtf8("MTopThree"));
        MTopThree->setEnabled(true);
        MTopThree->resize(400, 300);
        MTopThree->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 238, 205);"));
        verticalLayout = new QVBoxLayout(MTopThree);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(MTopThree);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);solid grey; border-radius: 8px;}"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_134 = new QLabel(groupBox_3);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(20);
        label_134->setFont(font);
        label_134->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 101, 255);"));
        label_134->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_134);

        widget_3 = new QWidget(groupBox_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 57);"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setVerticalSpacing(1);
        gridLayout_3->setContentsMargins(-1, 1, -1, 1);
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_first_bet = new QLabel(widget_3);
        label_first_bet->setObjectName(QString::fromUtf8("label_first_bet"));
        label_first_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_first_bet, 0, 3, 1, 1);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        label_first_name = new QLabel(widget_3);
        label_first_name->setObjectName(QString::fromUtf8("label_first_name"));
        label_first_name->setFont(font);
        label_first_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_first_name, 0, 1, 1, 1);

        label_second_name = new QLabel(widget_3);
        label_second_name->setObjectName(QString::fromUtf8("label_second_name"));
        label_second_name->setFont(font);
        label_second_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_second_name, 1, 1, 1, 1);

        label_first_money = new QLabel(widget_3);
        label_first_money->setObjectName(QString::fromUtf8("label_first_money"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_first_money->setFont(font1);
        label_first_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_money->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_first_money, 0, 4, 1, 1);

        label_second_bet = new QLabel(widget_3);
        label_second_bet->setObjectName(QString::fromUtf8("label_second_bet"));
        label_second_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_second_bet, 1, 3, 1, 1);

        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 1, 2, 1, 1);

        label_second_money = new QLabel(widget_3);
        label_second_money->setObjectName(QString::fromUtf8("label_second_money"));
        label_second_money->setFont(font1);
        label_second_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_money->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_second_money, 1, 4, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        label_third_name = new QLabel(widget_3);
        label_third_name->setObjectName(QString::fromUtf8("label_third_name"));
        label_third_name->setFont(font);
        label_third_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_third_name, 2, 1, 1, 1);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 2, 2, 1, 1);

        label_third_bet = new QLabel(widget_3);
        label_third_bet->setObjectName(QString::fromUtf8("label_third_bet"));
        label_third_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_third_bet, 2, 3, 1, 1);

        label_third_money = new QLabel(widget_3);
        label_third_money->setObjectName(QString::fromUtf8("label_third_money"));
        label_third_money->setFont(font1);
        label_third_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_money->setAlignment(Qt::AlignCenter);
        label_third_money->setWordWrap(false);

        gridLayout_3->addWidget(label_third_money, 2, 4, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 1);
        gridLayout_3->setColumnStretch(4, 2);

        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);

        verticalLayout->addWidget(groupBox_3);


        retranslateUi(MTopThree);

        QMetaObject::connectSlotsByName(MTopThree);
    } // setupUi

    void retranslateUi(QWidget *MTopThree)
    {
        MTopThree->setWindowTitle(QCoreApplication::translate("MTopThree", "Form", nullptr));
        groupBox_3->setTitle(QString());
        label_134->setText(QCoreApplication::translate("MTopThree", "\346\234\254\345\261\200\346\212\225\346\263\250\346\234\200\345\244\247\345\211\215\344\270\211", nullptr));
        label->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><img src=\":/icon/image/icon/1.png\"/></p></body></html>", nullptr));
        label_first_bet->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><img src=\":/icon/image/icon/2.png\"/></p></body></html>", nullptr));
        label_first_name->setText(QString());
        label_second_name->setText(QString());
        label_first_money->setText(QString());
        label_second_bet->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MTopThree", "\346\212\225\346\263\250", nullptr));
        label_second_money->setText(QString());
        label_3->setText(QCoreApplication::translate("MTopThree", "\346\212\225\346\263\250", nullptr));
        label_16->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><img src=\":/icon/image/icon/3.png\"/></p></body></html>", nullptr));
        label_third_name->setText(QString());
        label_18->setText(QCoreApplication::translate("MTopThree", "\346\212\225\346\263\250", nullptr));
        label_third_bet->setText(QCoreApplication::translate("MTopThree", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_third_money->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MTopThree: public Ui_MTopThree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTOPTHREE_H
