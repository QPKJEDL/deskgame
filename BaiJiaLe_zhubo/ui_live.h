/********************************************************************************
** Form generated from reading UI file 'live.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVE_H
#define UI_LIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Live
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pu_today;
    QPushButton *pu_yesterday;
    QPushButton *pu_now_month;
    QPushButton *pu_front_month;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_5;
    QGridLayout *gridLayout;
    QLabel *label_seven_deskNum;
    QLabel *label_four_money;
    QLabel *label_seven_creatime;
    QLabel *label_one_creatime;
    QLabel *label_31;
    QLabel *label_14;
    QLabel *label_two_deskNum;
    QLabel *label_three_creatime;
    QLabel *label_30;
    QLabel *label_12;
    QLabel *label_two_creatime;
    QLabel *label_41;
    QLabel *label_38;
    QLabel *label_29;
    QLabel *label_one_money;
    QLabel *label_33;
    QLabel *label_five_creatime;
    QLabel *label_one_deskNum;
    QLabel *label_39;
    QLabel *label_16;
    QLabel *label_37;
    QLabel *label_40;
    QLabel *label_34;
    QLabel *label_42;
    QLabel *label_seven_money;
    QLabel *label_three_money;
    QLabel *label_six_creatime;
    QLabel *label_25;
    QLabel *label_43;
    QLabel *label_four_deskNum;
    QLabel *label_18;
    QLabel *label_five_deskNum;
    QLabel *label_two_money;
    QLabel *label_21;
    QLabel *label_three_deskNum;
    QLabel *label_five_money;
    QLabel *label_six_money;
    QLabel *label_26;
    QLabel *label_four_creatime;
    QLabel *label_six_deskNum;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_44;
    QLabel *label_45;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *Live)
    {
        if (Live->objectName().isEmpty())
            Live->setObjectName(QString::fromUtf8("Live"));
        Live->resize(844, 547);
        Live->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 67, 98);"));
        verticalLayout = new QVBoxLayout(Live);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Live);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(163, 129, 98, 255), stop:1 rgba(252, 237, 203, 255));"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pu_today = new QPushButton(Live);
        pu_today->setObjectName(QString::fromUtf8("pu_today"));
        pu_today->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(15);
        pu_today->setFont(font1);
        pu_today->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(163, 129, 98, 255), stop:0.431818 rgba(252, 237, 203, 255), stop:0.590909 rgba(252, 237, 203, 255), stop:1 rgba(163, 129, 98, 255));\n"
"border-radius: 8px;\n"
"color: rgb(121, 61, 3);"));

        horizontalLayout_2->addWidget(pu_today);

        pu_yesterday = new QPushButton(Live);
        pu_yesterday->setObjectName(QString::fromUtf8("pu_yesterday"));
        pu_yesterday->setMinimumSize(QSize(0, 40));
        pu_yesterday->setFont(font1);
        pu_yesterday->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_yesterday);

        pu_now_month = new QPushButton(Live);
        pu_now_month->setObjectName(QString::fromUtf8("pu_now_month"));
        pu_now_month->setMinimumSize(QSize(0, 40));
        pu_now_month->setFont(font1);
        pu_now_month->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_now_month);

        pu_front_month = new QPushButton(Live);
        pu_front_month->setObjectName(QString::fromUtf8("pu_front_month"));
        pu_front_month->setMinimumSize(QSize(0, 40));
        pu_front_month->setFont(font1);
        pu_front_month->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_front_month);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(Live);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(Live);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 34, 51);\n"
"border-radius: 5px;\n"
"border: 3px;\n"
"color: rgb(255, 255, 255);"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit);

        label_3 = new QLabel(Live);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(Live);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 40));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 34, 51);\n"
"border-radius: 5px;\n"
"border: 3px;\n"
"color: rgb(255, 255, 255);"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_2);

        pushButton_5 = new QPushButton(Live);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(61, 154, 61);\n"
"background-color: transparent;\n"
"border-radius: 1px;"));

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 2);
        horizontalLayout_2->setStretch(5, 2);
        horizontalLayout_2->setStretch(6, 4);
        horizontalLayout_2->setStretch(7, 1);
        horizontalLayout_2->setStretch(8, 4);
        horizontalLayout_2->setStretch(9, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_seven_deskNum = new QLabel(Live);
        label_seven_deskNum->setObjectName(QString::fromUtf8("label_seven_deskNum"));
        label_seven_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_seven_deskNum, 8, 1, 1, 1);

        label_four_money = new QLabel(Live);
        label_four_money->setObjectName(QString::fromUtf8("label_four_money"));
        label_four_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_four_money, 5, 3, 1, 1);

        label_seven_creatime = new QLabel(Live);
        label_seven_creatime->setObjectName(QString::fromUtf8("label_seven_creatime"));
        label_seven_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);"));

        gridLayout->addWidget(label_seven_creatime, 8, 0, 1, 1);

        label_one_creatime = new QLabel(Live);
        label_one_creatime->setObjectName(QString::fromUtf8("label_one_creatime"));
        label_one_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_one_creatime, 1, 0, 1, 1);

        label_31 = new QLabel(Live);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_31, 6, 4, 1, 1);

        label_14 = new QLabel(Live);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_14, 1, 4, 1, 1);

        label_two_deskNum = new QLabel(Live);
        label_two_deskNum->setObjectName(QString::fromUtf8("label_two_deskNum"));
        label_two_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_two_deskNum, 2, 1, 1, 1);

        label_three_creatime = new QLabel(Live);
        label_three_creatime->setObjectName(QString::fromUtf8("label_three_creatime"));
        label_three_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);"));

        gridLayout->addWidget(label_three_creatime, 4, 0, 1, 1);

        label_30 = new QLabel(Live);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_30, 5, 4, 1, 1);

        label_12 = new QLabel(Live);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        label_two_creatime = new QLabel(Live);
        label_two_creatime->setObjectName(QString::fromUtf8("label_two_creatime"));
        label_two_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_two_creatime, 2, 0, 1, 1);

        label_41 = new QLabel(Live);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(20);
        label_41->setFont(font2);
        label_41->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_41->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_41, 0, 2, 1, 1);

        label_38 = new QLabel(Live);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_38, 8, 4, 1, 1);

        label_29 = new QLabel(Live);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_29, 4, 4, 1, 1);

        label_one_money = new QLabel(Live);
        label_one_money->setObjectName(QString::fromUtf8("label_one_money"));
        label_one_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_one_money, 1, 3, 1, 1);

        label_33 = new QLabel(Live);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_33, 7, 2, 1, 1);

        label_five_creatime = new QLabel(Live);
        label_five_creatime->setObjectName(QString::fromUtf8("label_five_creatime"));
        label_five_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);"));

        gridLayout->addWidget(label_five_creatime, 6, 0, 1, 1);

        label_one_deskNum = new QLabel(Live);
        label_one_deskNum->setObjectName(QString::fromUtf8("label_one_deskNum"));
        label_one_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_one_deskNum, 1, 1, 1, 1);

        label_39 = new QLabel(Live);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font2);
        label_39->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_39, 0, 0, 1, 1);

        label_16 = new QLabel(Live);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_16, 2, 2, 1, 1);

        label_37 = new QLabel(Live);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_37, 7, 4, 1, 1);

        label_40 = new QLabel(Live);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font2);
        label_40->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_40, 0, 1, 1, 1);

        label_34 = new QLabel(Live);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_34, 8, 2, 1, 1);

        label_42 = new QLabel(Live);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font2);
        label_42->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_42->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_42, 0, 3, 1, 1);

        label_seven_money = new QLabel(Live);
        label_seven_money->setObjectName(QString::fromUtf8("label_seven_money"));
        label_seven_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_seven_money, 8, 3, 1, 1);

        label_three_money = new QLabel(Live);
        label_three_money->setObjectName(QString::fromUtf8("label_three_money"));
        label_three_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_three_money, 4, 3, 1, 1);

        label_six_creatime = new QLabel(Live);
        label_six_creatime->setObjectName(QString::fromUtf8("label_six_creatime"));
        label_six_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_six_creatime, 7, 0, 1, 1);

        label_25 = new QLabel(Live);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_25, 6, 2, 1, 1);

        label_43 = new QLabel(Live);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font2);
        label_43->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_43->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_43, 0, 4, 1, 1);

        label_four_deskNum = new QLabel(Live);
        label_four_deskNum->setObjectName(QString::fromUtf8("label_four_deskNum"));
        label_four_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_four_deskNum, 5, 1, 1, 1);

        label_18 = new QLabel(Live);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_18, 2, 4, 1, 1);

        label_five_deskNum = new QLabel(Live);
        label_five_deskNum->setObjectName(QString::fromUtf8("label_five_deskNum"));
        label_five_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_five_deskNum, 6, 1, 1, 1);

        label_two_money = new QLabel(Live);
        label_two_money->setObjectName(QString::fromUtf8("label_two_money"));
        label_two_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_two_money, 2, 3, 1, 1);

        label_21 = new QLabel(Live);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_21, 5, 2, 1, 1);

        label_three_deskNum = new QLabel(Live);
        label_three_deskNum->setObjectName(QString::fromUtf8("label_three_deskNum"));
        label_three_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_three_deskNum, 4, 1, 1, 1);

        label_five_money = new QLabel(Live);
        label_five_money->setObjectName(QString::fromUtf8("label_five_money"));
        label_five_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_five_money, 6, 3, 1, 1);

        label_six_money = new QLabel(Live);
        label_six_money->setObjectName(QString::fromUtf8("label_six_money"));
        label_six_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_six_money, 7, 3, 1, 1);

        label_26 = new QLabel(Live);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_26, 4, 2, 1, 1);

        label_four_creatime = new QLabel(Live);
        label_four_creatime->setObjectName(QString::fromUtf8("label_four_creatime"));
        label_four_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_four_creatime, 5, 0, 1, 1);

        label_six_deskNum = new QLabel(Live);
        label_six_deskNum->setObjectName(QString::fromUtf8("label_six_deskNum"));
        label_six_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_six_deskNum, 7, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_44 = new QLabel(Live);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_44->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_44);

        label_45 = new QLabel(Live);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_45->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_45);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_6 = new QPushButton(Live);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 40));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(163, 129, 98, 255), stop:0.431818 rgba(252, 237, 203, 255), stop:0.590909 rgba(252, 237, 203, 255), stop:1 rgba(163, 129, 98, 255));\n"
"border-radius: 8px;\n"
"color: rgb(121, 61, 3);"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(Live);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 40));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pushButton_7);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 5);
        verticalLayout->setStretch(3, 1);

        retranslateUi(Live);

        QMetaObject::connectSlotsByName(Live);
    } // setupUi

    void retranslateUi(QWidget *Live)
    {
        Live->setWindowTitle(QCoreApplication::translate("Live", "Form", nullptr));
        label->setText(QCoreApplication::translate("Live", "\350\215\267\345\256\230\344\270\273\346\222\255\346\211\223\350\265\217\346\230\216\347\273\206", nullptr));
        pu_today->setText(QCoreApplication::translate("Live", "\344\273\212\345\244\251", nullptr));
        pu_yesterday->setText(QCoreApplication::translate("Live", "\346\230\250\345\244\251", nullptr));
        pu_now_month->setText(QCoreApplication::translate("Live", "\346\234\254\346\234\210", nullptr));
        pu_front_month->setText(QCoreApplication::translate("Live", "\344\270\212\346\234\210", nullptr));
        label_2->setText(QCoreApplication::translate("Live", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("Live", "\350\207\263", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Live", "\346\237\245\350\257\242", nullptr));
        label_seven_deskNum->setText(QString());
        label_four_money->setText(QString());
        label_seven_creatime->setText(QString());
        label_one_creatime->setText(QString());
        label_31->setText(QString());
        label_14->setText(QString());
        label_two_deskNum->setText(QString());
        label_three_creatime->setText(QString());
        label_30->setText(QString());
        label_12->setText(QString());
        label_two_creatime->setText(QString());
        label_41->setText(QCoreApplication::translate("Live", "\344\274\232\345\221\230", nullptr));
        label_38->setText(QString());
        label_29->setText(QString());
        label_one_money->setText(QString());
        label_33->setText(QString());
        label_five_creatime->setText(QString());
        label_one_deskNum->setText(QString());
        label_39->setText(QCoreApplication::translate("Live", "\346\227\266\351\227\264\346\227\245\346\234\237", nullptr));
        label_16->setText(QString());
        label_37->setText(QString());
        label_40->setText(QCoreApplication::translate("Live", "\345\217\260\346\241\214", nullptr));
        label_34->setText(QString());
        label_42->setText(QCoreApplication::translate("Live", "\346\211\223\350\265\217\351\207\221\351\242\235", nullptr));
        label_seven_money->setText(QString());
        label_three_money->setText(QString());
        label_six_creatime->setText(QString());
        label_25->setText(QString());
        label_43->setText(QCoreApplication::translate("Live", "\347\261\273\345\236\213", nullptr));
        label_four_deskNum->setText(QString());
        label_18->setText(QString());
        label_five_deskNum->setText(QString());
        label_two_money->setText(QString());
        label_21->setText(QString());
        label_three_deskNum->setText(QString());
        label_five_money->setText(QString());
        label_six_money->setText(QString());
        label_26->setText(QString());
        label_four_creatime->setText(QString());
        label_six_deskNum->setText(QString());
        label_44->setText(QCoreApplication::translate("Live", "\346\211\223\350\265\217\346\200\273\351\207\221\351\242\235\357\274\232", nullptr));
        label_45->setText(QCoreApplication::translate("Live", "00", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Live", "\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Live", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Live: public Ui_Live {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVE_H
