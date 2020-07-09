/********************************************************************************
** Form generated from reading UI file 'MTopFive.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTOPFIVE_H
#define UI_MTOPFIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MTopFive
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_137;
    QGridLayout *gridLayout_5;
    QLabel *label_bingo_one;
    QLabel *label_14;
    QLabel *label_8;
    QLabel *label_bingo_five;
    QLabel *label_bingo_three;
    QLabel *label_bingo_two;
    QLabel *label_bingo_four;
    QLabel *label_first_num;
    QLabel *label_15;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_fourth_num;
    QLabel *label_fifth_num;
    QLabel *label_third_num;
    QLabel *label_second_num;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;

    void setupUi(QWidget *MTopFive)
    {
        if (MTopFive->objectName().isEmpty())
            MTopFive->setObjectName(QString::fromUtf8("MTopFive"));
        MTopFive->resize(332, 416);
        verticalLayout = new QVBoxLayout(MTopFive);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_137 = new QLabel(MTopFive);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(20);
        label_137->setFont(font);
        label_137->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0.523045, x2:1, y2:0, stop:0 rgba(193, 42, 40, 255), stop:1 rgba(167, 38, 35, 255));\n"
"color: rgb(255, 255, 255);"));
        label_137->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_137);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setVerticalSpacing(1);
        label_bingo_one = new QLabel(MTopFive);
        label_bingo_one->setObjectName(QString::fromUtf8("label_bingo_one"));
        label_bingo_one->setMaximumSize(QSize(319, 90));
        label_bingo_one->setFont(font);
        label_bingo_one->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_one->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_one, 0, 0, 1, 1);

        label_14 = new QLabel(MTopFive);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_14, 0, 3, 1, 1);

        label_8 = new QLabel(MTopFive);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_8, 0, 1, 1, 1);

        label_bingo_five = new QLabel(MTopFive);
        label_bingo_five->setObjectName(QString::fromUtf8("label_bingo_five"));
        label_bingo_five->setFont(font);
        label_bingo_five->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_five->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_five, 4, 0, 1, 1);

        label_bingo_three = new QLabel(MTopFive);
        label_bingo_three->setObjectName(QString::fromUtf8("label_bingo_three"));
        label_bingo_three->setFont(font);
        label_bingo_three->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_three->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_three, 2, 0, 1, 1);

        label_bingo_two = new QLabel(MTopFive);
        label_bingo_two->setObjectName(QString::fromUtf8("label_bingo_two"));
        label_bingo_two->setFont(font);
        label_bingo_two->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_two->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_two, 1, 0, 1, 1);

        label_bingo_four = new QLabel(MTopFive);
        label_bingo_four->setObjectName(QString::fromUtf8("label_bingo_four"));
        label_bingo_four->setFont(font);
        label_bingo_four->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_four->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_four, 3, 0, 1, 1);

        label_first_num = new QLabel(MTopFive);
        label_first_num->setObjectName(QString::fromUtf8("label_first_num"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(30);
        label_first_num->setFont(font1);
        label_first_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_first_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_first_num, 0, 2, 1, 1);

        label_15 = new QLabel(MTopFive);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_15, 1, 1, 1, 1);

        label_19 = new QLabel(MTopFive);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_19, 2, 1, 1, 1);

        label_20 = new QLabel(MTopFive);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_20, 3, 1, 1, 1);

        label_21 = new QLabel(MTopFive);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_21, 4, 1, 1, 1);

        label_fourth_num = new QLabel(MTopFive);
        label_fourth_num->setObjectName(QString::fromUtf8("label_fourth_num"));
        label_fourth_num->setFont(font1);
        label_fourth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fourth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fourth_num, 3, 2, 1, 1);

        label_fifth_num = new QLabel(MTopFive);
        label_fifth_num->setObjectName(QString::fromUtf8("label_fifth_num"));
        label_fifth_num->setFont(font1);
        label_fifth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fifth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fifth_num, 4, 2, 1, 1);

        label_third_num = new QLabel(MTopFive);
        label_third_num->setObjectName(QString::fromUtf8("label_third_num"));
        label_third_num->setFont(font1);
        label_third_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_third_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_third_num, 2, 2, 1, 1);

        label_second_num = new QLabel(MTopFive);
        label_second_num->setObjectName(QString::fromUtf8("label_second_num"));
        label_second_num->setFont(font1);
        label_second_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_second_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_second_num, 1, 2, 1, 1);

        label_26 = new QLabel(MTopFive);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_26, 1, 3, 1, 1);

        label_27 = new QLabel(MTopFive);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_27, 2, 3, 1, 1);

        label_28 = new QLabel(MTopFive);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_28, 3, 3, 1, 1);

        label_29 = new QLabel(MTopFive);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_29, 4, 3, 1, 1);

        gridLayout_5->setColumnStretch(0, 4);
        gridLayout_5->setColumnStretch(1, 2);
        gridLayout_5->setColumnStretch(2, 1);
        gridLayout_5->setColumnStretch(3, 1);

        verticalLayout_7->addLayout(gridLayout_5);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 6);

        verticalLayout->addLayout(verticalLayout_7);


        retranslateUi(MTopFive);

        QMetaObject::connectSlotsByName(MTopFive);
    } // setupUi

    void retranslateUi(QWidget *MTopFive)
    {
        MTopFive->setWindowTitle(QCoreApplication::translate("MTopFive", "Form", nullptr));
        label_137->setText(QCoreApplication::translate("MTopFive", "\346\234\254\351\235\264\350\277\236\347\273\255\344\270\255\346\263\250\344\270\211\351\223\272\344\273\245\344\270\212", nullptr));
        label_bingo_one->setText(QString());
        label_14->setText(QCoreApplication::translate("MTopFive", "\351\223\272", nullptr));
        label_8->setText(QCoreApplication::translate("MTopFive", "\350\277\236\344\270\255", nullptr));
        label_bingo_five->setText(QString());
        label_bingo_three->setText(QString());
        label_bingo_two->setText(QString());
        label_bingo_four->setText(QString());
        label_first_num->setText(QString());
        label_15->setText(QCoreApplication::translate("MTopFive", "\350\277\236\344\270\255", nullptr));
        label_19->setText(QCoreApplication::translate("MTopFive", "\350\277\236\344\270\255", nullptr));
        label_20->setText(QCoreApplication::translate("MTopFive", "\350\277\236\344\270\255", nullptr));
        label_21->setText(QCoreApplication::translate("MTopFive", "\350\277\236\344\270\255", nullptr));
        label_fourth_num->setText(QString());
        label_fifth_num->setText(QString());
        label_third_num->setText(QString());
        label_second_num->setText(QString());
        label_26->setText(QCoreApplication::translate("MTopFive", "\351\223\272", nullptr));
        label_27->setText(QCoreApplication::translate("MTopFive", "\351\223\272", nullptr));
        label_28->setText(QCoreApplication::translate("MTopFive", "\351\223\272", nullptr));
        label_29->setText(QCoreApplication::translate("MTopFive", "\351\223\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MTopFive: public Ui_MTopFive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTOPFIVE_H
