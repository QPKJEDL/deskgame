/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_tieMaxLimit;
    QLabel *label_score_tiger;
    QLabel *label_same;
    QLabel *label_long_score;
    QLabel *label_score_long;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;
    QLabel *label_min_red;
    QLabel *label_tiger_score;
    QLabel *label_126;
    QLabel *label_tieMinLimit;
    QLabel *label_longTiger;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_times_xue;
    QLabel *label_times_pu;
    QLabel *label_VIP_level;
    QLabel *label_same_score;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_xues;
    QLabel *label_pus;
    QLabel *label_max_red;
    QLabel *label_score_same;
    QLabel *label_up_pave;
    QLabel *label_result;
    QLabel *label_minLimit;
    QLabel *label_maxLimit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_143;
    QLabel *label_hwl_one;
    QLabel *label_hwl_two;
    QLabel *label_hwl_three;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_142;
    QLabel *label_lwl_one;
    QLabel *label_lwl_two;
    QLabel *label_lwl_three;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pu_init;
    QPushButton *pu_start;
    QPushButton *pu_changeXue;
    QPushButton *pu_stop;
    QPushButton *pu_leave;
    QPushButton *pu_useless;
    QPushButton *pu_long;
    QPushButton *pu_tiger;
    QPushButton *pu_same;
    QLabel *label_count_down;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1917, 1047);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 40, 50);"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 443, 1901, 271));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);\n"
""));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        verticalLayout_4->addLayout(gridLayout_4);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 720, 1901, 271));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);\n"
""));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        verticalLayout_5->addLayout(gridLayout_5);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1250, 0, 661, 441));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_tieMaxLimit = new QLabel(groupBox_2);
        label_tieMaxLimit->setObjectName(QString::fromUtf8("label_tieMaxLimit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(30);
        label_tieMaxLimit->setFont(font);
        label_tieMaxLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_tieMaxLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tieMaxLimit, 3, 3, 1, 1);

        label_score_tiger = new QLabel(groupBox_2);
        label_score_tiger->setObjectName(QString::fromUtf8("label_score_tiger"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(20);
        label_score_tiger->setFont(font1);
        label_score_tiger->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_score_tiger->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_score_tiger, 5, 3, 1, 1);

        label_same = new QLabel(groupBox_2);
        label_same->setObjectName(QString::fromUtf8("label_same"));
        label_same->setFont(font);
        label_same->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(85, 255, 0);"));
        label_same->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_same, 3, 2, 1, 1);

        label_long_score = new QLabel(groupBox_2);
        label_long_score->setObjectName(QString::fromUtf8("label_long_score"));
        label_long_score->setFont(font);
        label_long_score->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));\n"
"color: rgb(170, 0, 0);"));
        label_long_score->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_long_score, 4, 1, 1, 1);

        label_score_long = new QLabel(groupBox_2);
        label_score_long->setObjectName(QString::fromUtf8("label_score_long"));
        label_score_long->setFont(font1);
        label_score_long->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_score_long->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_score_long, 5, 1, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        pu_enter = new QPushButton(groupBox_2);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setEnabled(false);
        pu_enter->setFont(font1);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout_16->addWidget(pu_enter);

        pu_cancel = new QPushButton(groupBox_2);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setEnabled(false);
        pu_cancel->setFont(font1);
        pu_cancel->setCursor(QCursor(Qt::ArrowCursor));
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout_16->addWidget(pu_cancel);


        verticalLayout_9->addLayout(horizontalLayout_16);

        label_min_red = new QLabel(groupBox_2);
        label_min_red->setObjectName(QString::fromUtf8("label_min_red"));
        label_min_red->setMinimumSize(QSize(200, 0));
        label_min_red->setMaximumSize(QSize(210, 16777215));
        label_min_red->setFont(font1);
        label_min_red->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_min_red->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_min_red);


        gridLayout->addLayout(verticalLayout_9, 1, 1, 1, 1);

        label_tiger_score = new QLabel(groupBox_2);
        label_tiger_score->setObjectName(QString::fromUtf8("label_tiger_score"));
        label_tiger_score->setFont(font);
        label_tiger_score->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));\n"
"color: rgb(0, 170, 255);"));
        label_tiger_score->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tiger_score, 4, 3, 1, 1);

        label_126 = new QLabel(groupBox_2);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setMinimumSize(QSize(0, 0));
        label_126->setFont(font);
        label_126->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);"));
        label_126->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_126, 2, 2, 1, 1);

        label_tieMinLimit = new QLabel(groupBox_2);
        label_tieMinLimit->setObjectName(QString::fromUtf8("label_tieMinLimit"));
        label_tieMinLimit->setFont(font);
        label_tieMinLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_tieMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tieMinLimit, 3, 1, 1, 1);

        label_longTiger = new QLabel(groupBox_2);
        label_longTiger->setObjectName(QString::fromUtf8("label_longTiger"));
        label_longTiger->setFont(font1);
        label_longTiger->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_longTiger->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_longTiger, 0, 2, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_times_xue = new QLabel(groupBox_2);
        label_times_xue->setObjectName(QString::fromUtf8("label_times_xue"));
        label_times_xue->setFont(font1);
        label_times_xue->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_times_xue->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_times_xue);

        label_times_pu = new QLabel(groupBox_2);
        label_times_pu->setObjectName(QString::fromUtf8("label_times_pu"));
        label_times_pu->setFont(font1);
        label_times_pu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_times_pu->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_times_pu);


        gridLayout->addLayout(horizontalLayout_19, 0, 3, 1, 1);

        label_VIP_level = new QLabel(groupBox_2);
        label_VIP_level->setObjectName(QString::fromUtf8("label_VIP_level"));
        label_VIP_level->setMinimumSize(QSize(210, 100));
        label_VIP_level->setFont(font1);
        label_VIP_level->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 48, 84);\n"
"color: rgb(255, 255, 0);"));
        label_VIP_level->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_VIP_level, 1, 2, 1, 1);

        label_same_score = new QLabel(groupBox_2);
        label_same_score->setObjectName(QString::fromUtf8("label_same_score"));
        label_same_score->setFont(font);
        label_same_score->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));\n"
"color: rgb(85, 255, 0);"));
        label_same_score->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_same_score, 4, 2, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_xues = new QLabel(groupBox_2);
        label_xues->setObjectName(QString::fromUtf8("label_xues"));
        label_xues->setFont(font1);
        label_xues->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);"));
        label_xues->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_xues);

        label_pus = new QLabel(groupBox_2);
        label_pus->setObjectName(QString::fromUtf8("label_pus"));
        label_pus->setFont(font1);
        label_pus->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);"));
        label_pus->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_pus);


        verticalLayout_10->addLayout(horizontalLayout_17);

        label_max_red = new QLabel(groupBox_2);
        label_max_red->setObjectName(QString::fromUtf8("label_max_red"));
        label_max_red->setMinimumSize(QSize(210, 0));
        label_max_red->setFont(font1);
        label_max_red->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_max_red->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_max_red);


        gridLayout->addLayout(verticalLayout_10, 1, 3, 1, 1);

        label_score_same = new QLabel(groupBox_2);
        label_score_same->setObjectName(QString::fromUtf8("label_score_same"));
        label_score_same->setFont(font1);
        label_score_same->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_score_same->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_score_same, 5, 2, 1, 1);

        label_up_pave = new QLabel(groupBox_2);
        label_up_pave->setObjectName(QString::fromUtf8("label_up_pave"));
        label_up_pave->setMinimumSize(QSize(0, 0));
        label_up_pave->setFont(font1);
        label_up_pave->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 8px;"));
        label_up_pave->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_up_pave, 6, 3, 1, 1);

        label_result = new QLabel(groupBox_2);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setFont(font1);
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 0);"));
        label_result->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_result, 0, 1, 1, 1);

        label_minLimit = new QLabel(groupBox_2);
        label_minLimit->setObjectName(QString::fromUtf8("label_minLimit"));
        label_minLimit->setMinimumSize(QSize(0, 0));
        label_minLimit->setFont(font);
        label_minLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_minLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_minLimit, 2, 1, 1, 1);

        label_maxLimit = new QLabel(groupBox_2);
        label_maxLimit->setObjectName(QString::fromUtf8("label_maxLimit"));
        label_maxLimit->setFont(font);
        label_maxLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_maxLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_maxLimit, 2, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_143 = new QLabel(groupBox_2);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(15);
        label_143->setFont(font2);
        label_143->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));
        label_143->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_143);

        label_hwl_one = new QLabel(groupBox_2);
        label_hwl_one->setObjectName(QString::fromUtf8("label_hwl_one"));
        label_hwl_one->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_hwl_one);

        label_hwl_two = new QLabel(groupBox_2);
        label_hwl_two->setObjectName(QString::fromUtf8("label_hwl_two"));
        label_hwl_two->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_hwl_two);

        label_hwl_three = new QLabel(groupBox_2);
        label_hwl_three->setObjectName(QString::fromUtf8("label_hwl_three"));
        label_hwl_three->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_hwl_three);


        gridLayout->addLayout(horizontalLayout_3, 6, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_142 = new QLabel(groupBox_2);
        label_142->setObjectName(QString::fromUtf8("label_142"));
        label_142->setFont(font2);
        label_142->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));
        label_142->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_142);

        label_lwl_one = new QLabel(groupBox_2);
        label_lwl_one->setObjectName(QString::fromUtf8("label_lwl_one"));
        label_lwl_one->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_lwl_one);

        label_lwl_two = new QLabel(groupBox_2);
        label_lwl_two->setObjectName(QString::fromUtf8("label_lwl_two"));
        label_lwl_two->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_lwl_two);

        label_lwl_three = new QLabel(groupBox_2);
        label_lwl_three->setObjectName(QString::fromUtf8("label_lwl_three"));
        label_lwl_three->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_lwl_three);


        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 1241, 441));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 1221, 351));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 1221, 64));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pu_init = new QPushButton(layoutWidget2);
        pu_init->setObjectName(QString::fromUtf8("pu_init"));
        pu_init->setEnabled(false);
        pu_init->setMinimumSize(QSize(100, 62));
        pu_init->setFont(font2);
        pu_init->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_init);

        pu_start = new QPushButton(layoutWidget2);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setMinimumSize(QSize(100, 62));
        pu_start->setFont(font2);
        pu_start->setAcceptDrops(true);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_start);

        pu_changeXue = new QPushButton(layoutWidget2);
        pu_changeXue->setObjectName(QString::fromUtf8("pu_changeXue"));
        pu_changeXue->setEnabled(false);
        pu_changeXue->setMinimumSize(QSize(100, 62));
        pu_changeXue->setFont(font2);
        pu_changeXue->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_changeXue);

        pu_stop = new QPushButton(layoutWidget2);
        pu_stop->setObjectName(QString::fromUtf8("pu_stop"));
        pu_stop->setEnabled(false);
        pu_stop->setMinimumSize(QSize(100, 62));
        pu_stop->setFont(font2);
        pu_stop->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_stop);

        pu_leave = new QPushButton(layoutWidget2);
        pu_leave->setObjectName(QString::fromUtf8("pu_leave"));
        pu_leave->setEnabled(false);
        pu_leave->setMinimumSize(QSize(100, 62));
        pu_leave->setFont(font2);
        pu_leave->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_leave);

        pu_useless = new QPushButton(layoutWidget2);
        pu_useless->setObjectName(QString::fromUtf8("pu_useless"));
        pu_useless->setEnabled(false);
        pu_useless->setMinimumSize(QSize(100, 62));
        pu_useless->setFont(font2);
        pu_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_useless);

        pu_long = new QPushButton(layoutWidget2);
        pu_long->setObjectName(QString::fromUtf8("pu_long"));
        pu_long->setEnabled(false);
        pu_long->setMinimumSize(QSize(100, 62));
        pu_long->setFont(font2);
        pu_long->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_long);

        pu_tiger = new QPushButton(layoutWidget2);
        pu_tiger->setObjectName(QString::fromUtf8("pu_tiger"));
        pu_tiger->setEnabled(false);
        pu_tiger->setMinimumSize(QSize(100, 62));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 73, 138, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QBrush brush4(QColor(99, 99, 99, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pu_tiger->setPalette(palette);
        pu_tiger->setFont(font2);
        pu_tiger->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_tiger);

        pu_same = new QPushButton(layoutWidget2);
        pu_same->setObjectName(QString::fromUtf8("pu_same"));
        pu_same->setEnabled(false);
        pu_same->setMinimumSize(QSize(100, 62));
        pu_same->setFont(font2);
        pu_same->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_same);


        verticalLayout->addWidget(groupBox);

        label_count_down = new QLabel(centralwidget);
        label_count_down->setObjectName(QString::fromUtf8("label_count_down"));
        label_count_down->setGeometry(QRect(263, 449, 1521, 251));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font3.setPointSize(200);
        label_count_down->setFont(font3);
        label_count_down->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_count_down->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1917, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QString());
        groupBox_2->setTitle(QString());
        label_tieMaxLimit->setText(QString());
        label_score_tiger->setText(QString());
        label_same->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
#if QT_CONFIG(whatsthis)
        label_long_score->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa0000;\">\351\276\231</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_long_score->setText(QCoreApplication::translate("MainWindow", "\351\276\231", nullptr));
        label_score_long->setText(QString());
        pu_enter->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\357\274\210*\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_cancel->setShortcut(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        label_min_red->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\351\231\220\347\272\242", nullptr));
        label_tiger_score->setText(QCoreApplication::translate("MainWindow", "\350\231\216", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "\351\276\231\350\231\216", nullptr));
        label_tieMinLimit->setText(QString());
        label_longTiger->setText(QCoreApplication::translate("MainWindow", "\351\276\231\350\231\216", nullptr));
        label_times_xue->setText(QCoreApplication::translate("MainWindow", "\351\235\264\346\254\241", nullptr));
        label_times_pu->setText(QCoreApplication::translate("MainWindow", "\351\223\272\346\254\241", nullptr));
        label_VIP_level->setText(QString());
        label_same_score->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
        label_xues->setText(QString());
        label_pus->setText(QString());
        label_max_red->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\351\231\220\347\272\242", nullptr));
        label_score_same->setText(QString());
        label_up_pave->setText(QCoreApplication::translate("MainWindow", "\344\270\212\351\223\272\357\274\232", nullptr));
        label_result->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\236\234:", nullptr));
        label_minLimit->setText(QString());
        label_maxLimit->setText(QString());
        label_143->setText(QCoreApplication::translate("MainWindow", "\350\231\216\351\227\256\350\267\257", nullptr));
        label_hwl_one->setText(QString());
        label_hwl_two->setText(QString());
        label_hwl_three->setText(QString());
        label_142->setText(QCoreApplication::translate("MainWindow", "\351\276\231\351\227\256\350\267\257", nullptr));
        label_lwl_one->setText(QString());
        label_lwl_two->setText(QString());
        label_lwl_three->setText(QString());
        groupBox->setTitle(QString());
        pu_init->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        pu_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\261\200\357\274\2106\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_start->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_changeXue->setText(QCoreApplication::translate("MainWindow", "\346\215\242\351\235\264\357\274\210+\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_changeXue->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\357\274\210/\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_stop->setShortcut(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_leave->setText(QCoreApplication::translate("MainWindow", "\347\246\273\345\274\200\357\274\210.\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_leave->setShortcut(QCoreApplication::translate("MainWindow", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_useless->setText(QCoreApplication::translate("MainWindow", "\344\275\234\345\272\237\357\274\2100\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_useless->setShortcut(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_long->setText(QCoreApplication::translate("MainWindow", "\351\276\231\357\274\2107\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_long->setShortcut(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_tiger->setText(QCoreApplication::translate("MainWindow", "\350\231\216\357\274\2104\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_tiger->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_same->setText(QCoreApplication::translate("MainWindow", "\345\222\214\357\274\2101\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_same->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        label_count_down->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
