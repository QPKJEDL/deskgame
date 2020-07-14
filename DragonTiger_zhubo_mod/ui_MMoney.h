/********************************************************************************
** Form generated from reading UI file 'MMoney.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMONEY_H
#define UI_MMONEY_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MMoney
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
    QDateTimeEdit *dateTimeEdit_begin;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_end;
    QPushButton *pu_search;
    QGridLayout *gridLayout;
    QLabel *label_four_deskNum;
    QLabel *label_seven_creatime;
    QLabel *label_14;
    QLabel *label_three_creatime;
    QLabel *label_seven_deskNum;
    QLabel *label_26;
    QLabel *label_25;
    QLabel *label_one_deskNum;
    QLabel *label_30;
    QLabel *label_41;
    QLabel *label_four_money;
    QLabel *label_29;
    QLabel *label_one_money;
    QLabel *label_six_money;
    QLabel *label_34;
    QLabel *label_five_creatime;
    QLabel *label_33;
    QLabel *label_seven_money;
    QLabel *label_18;
    QLabel *label_three_money;
    QLabel *label_six_creatime;
    QLabel *label_12;
    QLabel *label_21;
    QLabel *label_six_deskNum;
    QLabel *label_42;
    QLabel *label_39;
    QLabel *label_four_creatime;
    QLabel *label_16;
    QLabel *label_two_deskNum;
    QLabel *label_five_deskNum;
    QLabel *label_37;
    QLabel *label_five_money;
    QLabel *label_three_deskNum;
    QLabel *label_31;
    QLabel *label_one_creatime;
    QLabel *label_two_creatime;
    QLabel *label_two_money;
    QLabel *label_38;
    QLabel *label_43;
    QLabel *label_40;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_44;
    QLabel *label_sum;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pu_front_page;
    QPushButton *pu_next_page;

    void setupUi(QWidget *MMoney)
    {
        if (MMoney->objectName().isEmpty())
            MMoney->setObjectName(QString::fromUtf8("MMoney"));
        MMoney->resize(870, 575);
        MMoney->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 67, 98);"));
        verticalLayout = new QVBoxLayout(MMoney);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(MMoney);
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
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pu_today = new QPushButton(MMoney);
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

        pu_yesterday = new QPushButton(MMoney);
        pu_yesterday->setObjectName(QString::fromUtf8("pu_yesterday"));
        pu_yesterday->setMinimumSize(QSize(0, 40));
        pu_yesterday->setFont(font1);
        pu_yesterday->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_yesterday);

        pu_now_month = new QPushButton(MMoney);
        pu_now_month->setObjectName(QString::fromUtf8("pu_now_month"));
        pu_now_month->setMinimumSize(QSize(0, 40));
        pu_now_month->setFont(font1);
        pu_now_month->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_now_month);

        pu_front_month = new QPushButton(MMoney);
        pu_front_month->setObjectName(QString::fromUtf8("pu_front_month"));
        pu_front_month->setMinimumSize(QSize(0, 40));
        pu_front_month->setFont(font1);
        pu_front_month->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pu_front_month);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(MMoney);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        dateTimeEdit_begin = new QDateTimeEdit(MMoney);
        dateTimeEdit_begin->setObjectName(QString::fromUtf8("dateTimeEdit_begin"));
        dateTimeEdit_begin->setMinimumSize(QSize(0, 40));
        dateTimeEdit_begin->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 34, 51);\n"
"border-radius: 5px;\n"
"border: 3px;\n"
"color: rgb(255, 255, 255);"));
        dateTimeEdit_begin->setDate(QDate(2000, 1, 1));
        dateTimeEdit_begin->setCurrentSection(QDateTimeEdit::YearSection);

        horizontalLayout_2->addWidget(dateTimeEdit_begin);

        label_3 = new QLabel(MMoney);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        dateTimeEdit_end = new QDateTimeEdit(MMoney);
        dateTimeEdit_end->setObjectName(QString::fromUtf8("dateTimeEdit_end"));
        dateTimeEdit_end->setMinimumSize(QSize(0, 40));
        dateTimeEdit_end->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 34, 51);\n"
"border-radius: 5px;\n"
"border: 3px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(dateTimeEdit_end);

        pu_search = new QPushButton(MMoney);
        pu_search->setObjectName(QString::fromUtf8("pu_search"));
        pu_search->setMinimumSize(QSize(0, 40));
        pu_search->setFont(font1);
        pu_search->setStyleSheet(QString::fromUtf8("color: rgb(61, 154, 61);\n"
"background-color: transparent;\n"
"border-radius: 1px;"));

        horizontalLayout_2->addWidget(pu_search);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 2);
        horizontalLayout_2->setStretch(5, 2);
        horizontalLayout_2->setStretch(7, 1);
        horizontalLayout_2->setStretch(9, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_four_deskNum = new QLabel(MMoney);
        label_four_deskNum->setObjectName(QString::fromUtf8("label_four_deskNum"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(18);
        label_four_deskNum->setFont(font2);
        label_four_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_four_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_four_deskNum, 5, 1, 1, 1);

        label_seven_creatime = new QLabel(MMoney);
        label_seven_creatime->setObjectName(QString::fromUtf8("label_seven_creatime"));
        label_seven_creatime->setFont(font2);
        label_seven_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_seven_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_seven_creatime, 8, 0, 1, 1);

        label_14 = new QLabel(MMoney);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 1, 4, 1, 1);

        label_three_creatime = new QLabel(MMoney);
        label_three_creatime->setObjectName(QString::fromUtf8("label_three_creatime"));
        label_three_creatime->setFont(font2);
        label_three_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);color: rgb(255, 255, 255);"));
        label_three_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_three_creatime, 4, 0, 1, 1);

        label_seven_deskNum = new QLabel(MMoney);
        label_seven_deskNum->setObjectName(QString::fromUtf8("label_seven_deskNum"));
        label_seven_deskNum->setFont(font2);
        label_seven_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_seven_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_seven_deskNum, 8, 1, 1, 1);

        label_26 = new QLabel(MMoney);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_26, 4, 2, 1, 1);

        label_25 = new QLabel(MMoney);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font2);
        label_25->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_25, 6, 2, 1, 1);

        label_one_deskNum = new QLabel(MMoney);
        label_one_deskNum->setObjectName(QString::fromUtf8("label_one_deskNum"));
        label_one_deskNum->setFont(font2);
        label_one_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_one_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_one_deskNum, 1, 1, 1, 1);

        label_30 = new QLabel(MMoney);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_30, 5, 4, 1, 1);

        label_41 = new QLabel(MMoney);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font3.setPointSize(20);
        label_41->setFont(font3);
        label_41->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_41->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_41, 0, 2, 1, 1);

        label_four_money = new QLabel(MMoney);
        label_four_money->setObjectName(QString::fromUtf8("label_four_money"));
        label_four_money->setFont(font2);
        label_four_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_four_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_four_money, 5, 3, 1, 1);

        label_29 = new QLabel(MMoney);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_29, 4, 4, 1, 1);

        label_one_money = new QLabel(MMoney);
        label_one_money->setObjectName(QString::fromUtf8("label_one_money"));
        label_one_money->setFont(font2);
        label_one_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_one_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_one_money, 1, 3, 1, 1);

        label_six_money = new QLabel(MMoney);
        label_six_money->setObjectName(QString::fromUtf8("label_six_money"));
        label_six_money->setFont(font2);
        label_six_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_six_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_six_money, 7, 3, 1, 1);

        label_34 = new QLabel(MMoney);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_34, 8, 2, 1, 1);

        label_five_creatime = new QLabel(MMoney);
        label_five_creatime->setObjectName(QString::fromUtf8("label_five_creatime"));
        label_five_creatime->setFont(font2);
        label_five_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);color: rgb(255, 255, 255);"));
        label_five_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_five_creatime, 6, 0, 1, 1);

        label_33 = new QLabel(MMoney);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_33, 7, 2, 1, 1);

        label_seven_money = new QLabel(MMoney);
        label_seven_money->setObjectName(QString::fromUtf8("label_seven_money"));
        label_seven_money->setFont(font2);
        label_seven_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_seven_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_seven_money, 8, 3, 1, 1);

        label_18 = new QLabel(MMoney);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 2, 4, 1, 1);

        label_three_money = new QLabel(MMoney);
        label_three_money->setObjectName(QString::fromUtf8("label_three_money"));
        label_three_money->setFont(font2);
        label_three_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_three_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_three_money, 4, 3, 1, 1);

        label_six_creatime = new QLabel(MMoney);
        label_six_creatime->setObjectName(QString::fromUtf8("label_six_creatime"));
        label_six_creatime->setFont(font2);
        label_six_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_six_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_six_creatime, 7, 0, 1, 1);

        label_12 = new QLabel(MMoney);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        label_21 = new QLabel(MMoney);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_21, 5, 2, 1, 1);

        label_six_deskNum = new QLabel(MMoney);
        label_six_deskNum->setObjectName(QString::fromUtf8("label_six_deskNum"));
        label_six_deskNum->setFont(font2);
        label_six_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_six_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_six_deskNum, 7, 1, 1, 1);

        label_42 = new QLabel(MMoney);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font3);
        label_42->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_42->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_42, 0, 3, 1, 1);

        label_39 = new QLabel(MMoney);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font3);
        label_39->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_39, 0, 0, 1, 1);

        label_four_creatime = new QLabel(MMoney);
        label_four_creatime->setObjectName(QString::fromUtf8("label_four_creatime"));
        label_four_creatime->setFont(font2);
        label_four_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_four_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_four_creatime, 5, 0, 1, 1);

        label_16 = new QLabel(MMoney);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 2, 2, 1, 1);

        label_two_deskNum = new QLabel(MMoney);
        label_two_deskNum->setObjectName(QString::fromUtf8("label_two_deskNum"));
        label_two_deskNum->setFont(font2);
        label_two_deskNum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_two_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_two_deskNum, 2, 1, 1, 1);

        label_five_deskNum = new QLabel(MMoney);
        label_five_deskNum->setObjectName(QString::fromUtf8("label_five_deskNum"));
        label_five_deskNum->setFont(font2);
        label_five_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_five_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_five_deskNum, 6, 1, 1, 1);

        label_37 = new QLabel(MMoney);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font2);
        label_37->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_37->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_37, 7, 4, 1, 1);

        label_five_money = new QLabel(MMoney);
        label_five_money->setObjectName(QString::fromUtf8("label_five_money"));
        label_five_money->setFont(font2);
        label_five_money->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_five_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_five_money, 6, 3, 1, 1);

        label_three_deskNum = new QLabel(MMoney);
        label_three_deskNum->setObjectName(QString::fromUtf8("label_three_deskNum"));
        label_three_deskNum->setFont(font2);
        label_three_deskNum->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_three_deskNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_three_deskNum, 4, 1, 1, 1);

        label_31 = new QLabel(MMoney);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_31, 6, 4, 1, 1);

        label_one_creatime = new QLabel(MMoney);
        label_one_creatime->setObjectName(QString::fromUtf8("label_one_creatime"));
        label_one_creatime->setFont(font2);
        label_one_creatime->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_one_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_one_creatime, 1, 0, 1, 1);

        label_two_creatime = new QLabel(MMoney);
        label_two_creatime->setObjectName(QString::fromUtf8("label_two_creatime"));
        label_two_creatime->setFont(font2);
        label_two_creatime->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_two_creatime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_two_creatime, 2, 0, 1, 1);

        label_two_money = new QLabel(MMoney);
        label_two_money->setObjectName(QString::fromUtf8("label_two_money"));
        label_two_money->setFont(font2);
        label_two_money->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_two_money->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_two_money, 2, 3, 1, 1);

        label_38 = new QLabel(MMoney);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font2);
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 71, 86);\n"
"color: rgb(255, 255, 255);"));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_38, 8, 4, 1, 1);

        label_43 = new QLabel(MMoney);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font3);
        label_43->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_43->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_43, 0, 4, 1, 1);

        label_40 = new QLabel(MMoney);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font3);
        label_40->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(251, 244, 207);"));
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_40, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_44 = new QLabel(MMoney);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_44->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_44);

        label_sum = new QLabel(MMoney);
        label_sum->setObjectName(QString::fromUtf8("label_sum"));
        label_sum->setFont(font1);
        label_sum->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_sum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_sum);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pu_front_page = new QPushButton(MMoney);
        pu_front_page->setObjectName(QString::fromUtf8("pu_front_page"));
        pu_front_page->setMinimumSize(QSize(0, 40));
        pu_front_page->setFont(font1);
        pu_front_page->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(163, 129, 98, 255), stop:0.431818 rgba(252, 237, 203, 255), stop:0.590909 rgba(252, 237, 203, 255), stop:1 rgba(163, 129, 98, 255));\n"
"border-radius: 8px;\n"
"color: rgb(121, 61, 3);"));

        horizontalLayout_3->addWidget(pu_front_page);

        pu_next_page = new QPushButton(MMoney);
        pu_next_page->setObjectName(QString::fromUtf8("pu_next_page"));
        pu_next_page->setMinimumSize(QSize(0, 40));
        pu_next_page->setFont(font1);
        pu_next_page->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255));\n"
"border-radius: 8px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pu_next_page);

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

        retranslateUi(MMoney);

        QMetaObject::connectSlotsByName(MMoney);
    } // setupUi

    void retranslateUi(QWidget *MMoney)
    {
        MMoney->setWindowTitle(QCoreApplication::translate("MMoney", "Form", nullptr));
        label->setText(QCoreApplication::translate("MMoney", "\350\215\267\345\256\230\344\270\273\346\222\255\346\211\223\350\265\217\346\230\216\347\273\206", nullptr));
        pu_today->setText(QCoreApplication::translate("MMoney", "\344\273\212\345\244\251", nullptr));
        pu_yesterday->setText(QCoreApplication::translate("MMoney", "\346\230\250\345\244\251", nullptr));
        pu_now_month->setText(QCoreApplication::translate("MMoney", "\346\234\254\346\234\210", nullptr));
        pu_front_month->setText(QCoreApplication::translate("MMoney", "\344\270\212\346\234\210", nullptr));
        label_2->setText(QCoreApplication::translate("MMoney", "\346\227\266\351\227\264", nullptr));
        dateTimeEdit_begin->setDisplayFormat(QCoreApplication::translate("MMoney", "yyyy-MM-dd", nullptr));
        label_3->setText(QCoreApplication::translate("MMoney", "\350\207\263", nullptr));
        dateTimeEdit_end->setDisplayFormat(QCoreApplication::translate("MMoney", "yyyy-MM-dd", nullptr));
        pu_search->setText(QCoreApplication::translate("MMoney", "\346\237\245\350\257\242", nullptr));
        label_four_deskNum->setText(QString());
        label_seven_creatime->setText(QString());
        label_14->setText(QString());
        label_three_creatime->setText(QString());
        label_seven_deskNum->setText(QString());
        label_26->setText(QString());
        label_25->setText(QString());
        label_one_deskNum->setText(QString());
        label_30->setText(QString());
        label_41->setText(QCoreApplication::translate("MMoney", "\344\274\232\345\221\230", nullptr));
        label_four_money->setText(QString());
        label_29->setText(QString());
        label_one_money->setText(QString());
        label_six_money->setText(QString());
        label_34->setText(QString());
        label_five_creatime->setText(QString());
        label_33->setText(QString());
        label_seven_money->setText(QString());
        label_18->setText(QString());
        label_three_money->setText(QString());
        label_six_creatime->setText(QString());
        label_12->setText(QString());
        label_21->setText(QString());
        label_six_deskNum->setText(QString());
        label_42->setText(QCoreApplication::translate("MMoney", "\346\211\223\350\265\217\351\207\221\351\242\235", nullptr));
        label_39->setText(QCoreApplication::translate("MMoney", "\346\227\266\351\227\264\346\227\245\346\234\237", nullptr));
        label_four_creatime->setText(QString());
        label_16->setText(QString());
        label_two_deskNum->setText(QString());
        label_five_deskNum->setText(QString());
        label_37->setText(QString());
        label_five_money->setText(QString());
        label_three_deskNum->setText(QString());
        label_31->setText(QString());
        label_one_creatime->setText(QString());
        label_two_creatime->setText(QString());
        label_two_money->setText(QString());
        label_38->setText(QString());
        label_43->setText(QCoreApplication::translate("MMoney", "\347\261\273\345\236\213", nullptr));
        label_40->setText(QCoreApplication::translate("MMoney", "\345\217\260\346\241\214", nullptr));
        label_44->setText(QCoreApplication::translate("MMoney", "\346\211\223\350\265\217\346\200\273\351\207\221\351\242\235\357\274\232", nullptr));
        label_sum->setText(QString());
        pu_front_page->setText(QCoreApplication::translate("MMoney", "\344\270\212\344\270\200\351\241\265", nullptr));
        pu_next_page->setText(QCoreApplication::translate("MMoney", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MMoney: public Ui_MMoney {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMONEY_H
