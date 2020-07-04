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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pu_init;
    QPushButton *pu_start;
    QPushButton *pu_changeXue;
    QPushButton *pu_stop;
    QPushButton *pu_leave;
    QPushButton *pu_useless;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pu_zhuang;
    QPushButton *pu_xian;
    QPushButton *pu_same;
    QPushButton *pu_zhuangdui;
    QPushButton *pu_xiandui;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_123;
    QGridLayout *gridLayout;
    QLabel *label_minLimit;
    QLabel *label_122;
    QLabel *label_pairMinLimit;
    QLabel *label_129;
    QLabel *label_128;
    QLabel *label_tieMinLimit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *ChatPanel;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_desk_id;
    QLabel *label_result;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_135;
    QLabel *label_times_xue;
    QLabel *label_139;
    QLabel *label_136;
    QLabel *label_times_pu;
    QLabel *label_140;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
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
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 613);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 40, 50);"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        horizontalLayout_2->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pu_init = new QPushButton(groupBox);
        pu_init->setObjectName(QString::fromUtf8("pu_init"));
        pu_init->setEnabled(false);
        pu_init->setMaximumSize(QSize(119, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(15);
        pu_init->setFont(font);
        pu_init->setAcceptDrops(true);
        pu_init->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_init);

        pu_start = new QPushButton(groupBox);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setMaximumSize(QSize(119, 50));
        pu_start->setFont(font);
        pu_start->setAcceptDrops(true);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_start);

        pu_changeXue = new QPushButton(groupBox);
        pu_changeXue->setObjectName(QString::fromUtf8("pu_changeXue"));
        pu_changeXue->setEnabled(false);
        pu_changeXue->setMaximumSize(QSize(119, 50));
        pu_changeXue->setFont(font);
        pu_changeXue->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_changeXue);

        pu_stop = new QPushButton(groupBox);
        pu_stop->setObjectName(QString::fromUtf8("pu_stop"));
        pu_stop->setEnabled(false);
        pu_stop->setMaximumSize(QSize(119, 50));
        pu_stop->setFont(font);
        pu_stop->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_stop);

        pu_leave = new QPushButton(groupBox);
        pu_leave->setObjectName(QString::fromUtf8("pu_leave"));
        pu_leave->setEnabled(false);
        pu_leave->setMaximumSize(QSize(119, 50));
        pu_leave->setFont(font);
        pu_leave->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_leave);

        pu_useless = new QPushButton(groupBox);
        pu_useless->setObjectName(QString::fromUtf8("pu_useless"));
        pu_useless->setEnabled(true);
        pu_useless->setMaximumSize(QSize(119, 50));
        pu_useless->setFont(font);
        pu_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_2->addWidget(pu_useless);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pu_zhuang = new QPushButton(groupBox);
        pu_zhuang->setObjectName(QString::fromUtf8("pu_zhuang"));
        pu_zhuang->setEnabled(false);
        pu_zhuang->setMaximumSize(QSize(119, 50));
        pu_zhuang->setFont(font);
        pu_zhuang->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_zhuang);

        pu_xian = new QPushButton(groupBox);
        pu_xian->setObjectName(QString::fromUtf8("pu_xian"));
        pu_xian->setEnabled(false);
        pu_xian->setMaximumSize(QSize(119, 50));
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
        pu_xian->setPalette(palette);
        pu_xian->setFont(font);
        pu_xian->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_xian);

        pu_same = new QPushButton(groupBox);
        pu_same->setObjectName(QString::fromUtf8("pu_same"));
        pu_same->setEnabled(false);
        pu_same->setMaximumSize(QSize(119, 50));
        pu_same->setFont(font);
        pu_same->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_same);

        pu_zhuangdui = new QPushButton(groupBox);
        pu_zhuangdui->setObjectName(QString::fromUtf8("pu_zhuangdui"));
        pu_zhuangdui->setEnabled(false);
        pu_zhuangdui->setMaximumSize(QSize(119, 50));
        pu_zhuangdui->setFont(font);
        pu_zhuangdui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_zhuangdui);

        pu_xiandui = new QPushButton(groupBox);
        pu_xiandui->setObjectName(QString::fromUtf8("pu_xiandui"));
        pu_xiandui->setEnabled(false);
        pu_xiandui->setMaximumSize(QSize(119, 50));
        pu_xiandui->setFont(font);
        pu_xiandui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_xiandui);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_123 = new QLabel(groupBox);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setMaximumSize(QSize(279, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(25);
        label_123->setFont(font1);
        label_123->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(255, 255, 0);solid grey; border-radius: 8px;}"));
        label_123->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_123);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_minLimit = new QLabel(groupBox);
        label_minLimit->setObjectName(QString::fromUtf8("label_minLimit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(20);
        label_minLimit->setFont(font2);
        label_minLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_minLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_minLimit, 0, 1, 1, 1);

        label_122 = new QLabel(groupBox);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setFont(font2);
        label_122->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_122->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_122, 0, 0, 1, 1);

        label_pairMinLimit = new QLabel(groupBox);
        label_pairMinLimit->setObjectName(QString::fromUtf8("label_pairMinLimit"));
        label_pairMinLimit->setFont(font2);
        label_pairMinLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_pairMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_pairMinLimit, 2, 1, 1, 1);

        label_129 = new QLabel(groupBox);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setFont(font2);
        label_129->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        label_129->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_129, 2, 0, 1, 1);

        label_128 = new QLabel(groupBox);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setFont(font2);
        label_128->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_128->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_128, 1, 0, 1, 1);

        label_tieMinLimit = new QLabel(groupBox);
        label_tieMinLimit->setObjectName(QString::fromUtf8("label_tieMinLimit"));
        label_tieMinLimit->setFont(font2);
        label_tieMinLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_tieMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tieMinLimit, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout_9->addWidget(groupBox);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 725, 371));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        ChatPanel = new QGridLayout();
        ChatPanel->setObjectName(QString::fromUtf8("ChatPanel"));

        verticalLayout_10->addLayout(ChatPanel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_9->addWidget(scrollArea);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(1, 5);

        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);\n"
""));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.254237 rgba(255, 118, 96, 255), stop:0.949153 rgba(167, 38, 35, 255), stop:1 rgba(167, 38, 35, 255));"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_desk_id = new QLabel(widget);
        label_desk_id->setObjectName(QString::fromUtf8("label_desk_id"));
        label_desk_id->setFont(font2);
        label_desk_id->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(223, 238, 118);"));
        label_desk_id->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_desk_id);

        label_result = new QLabel(widget);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setMaximumSize(QSize(16777215, 40));
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 15, 12);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_result);

        pu_enter = new QPushButton(widget);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setEnabled(true);
        pu_enter->setFont(font2);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(121, 61, 3);background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.153409 rgba(252, 238, 205, 255), stop:1 rgba(153, 118, 97, 255));border:1px solid grey; border-radius: 0px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.1875 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(pu_enter);

        pu_cancel = new QPushButton(widget);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setEnabled(true);
        pu_cancel->setFont(font2);
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(121, 61, 3);background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.153409 rgba(252, 238, 205, 255), stop:1 rgba(153, 118, 97, 255));border:1px solid grey; border-radius: 0px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.1875 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}\n"
""));

        horizontalLayout->addWidget(pu_cancel);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 15, 12);"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_135 = new QLabel(widget_2);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        label_135->setFont(font2);
        label_135->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_135->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_135);

        label_times_xue = new QLabel(widget_2);
        label_times_xue->setObjectName(QString::fromUtf8("label_times_xue"));
        label_times_xue->setFont(font2);
        label_times_xue->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_times_xue->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_times_xue);

        label_139 = new QLabel(widget_2);
        label_139->setObjectName(QString::fromUtf8("label_139"));
        label_139->setFont(font2);
        label_139->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_139->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_139);

        label_136 = new QLabel(widget_2);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        label_136->setFont(font2);
        label_136->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_136->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_136);

        label_times_pu = new QLabel(widget_2);
        label_times_pu->setObjectName(QString::fromUtf8("label_times_pu"));
        label_times_pu->setFont(font2);
        label_times_pu->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_times_pu->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_times_pu);

        label_140 = new QLabel(widget_2);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        label_140->setFont(font2);
        label_140->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_140->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_140);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 5);
        horizontalLayout_3->setStretch(3, 5);
        horizontalLayout_3->setStretch(4, 6);
        horizontalLayout_3->setStretch(5, 5);

        verticalLayout->addWidget(widget_2);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);solid grey; border-radius: 8px;}"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_134 = new QLabel(groupBox_3);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setFont(font2);
        label_134->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 101, 255);"));
        label_134->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_134);

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
        label_first_name->setFont(font2);
        label_first_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_first_name, 0, 1, 1, 1);

        label_second_name = new QLabel(widget_3);
        label_second_name->setObjectName(QString::fromUtf8("label_second_name"));
        label_second_name->setFont(font2);
        label_second_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_second_name, 1, 1, 1, 1);

        label_first_money = new QLabel(widget_3);
        label_first_money->setObjectName(QString::fromUtf8("label_first_money"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        label_first_money->setFont(font3);
        label_first_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_money->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_first_money, 0, 4, 1, 1);

        label_second_bet = new QLabel(widget_3);
        label_second_bet->setObjectName(QString::fromUtf8("label_second_bet"));
        label_second_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_second_bet, 1, 3, 1, 1);

        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_13->setFont(font4);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_13, 1, 2, 1, 1);

        label_second_money = new QLabel(widget_3);
        label_second_money->setObjectName(QString::fromUtf8("label_second_money"));
        label_second_money->setFont(font3);
        label_second_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_money->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_second_money, 1, 4, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        label_third_name = new QLabel(widget_3);
        label_third_name->setObjectName(QString::fromUtf8("label_third_name"));
        label_third_name->setFont(font2);
        label_third_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_name->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_third_name, 2, 1, 1, 1);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_18, 2, 2, 1, 1);

        label_third_bet = new QLabel(widget_3);
        label_third_bet->setObjectName(QString::fromUtf8("label_third_bet"));
        label_third_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_third_bet, 2, 3, 1, 1);

        label_third_money = new QLabel(widget_3);
        label_third_money->setObjectName(QString::fromUtf8("label_third_money"));
        label_third_money->setFont(font3);
        label_third_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_money->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_third_money, 2, 4, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 1);
        gridLayout_3->setColumnStretch(4, 2);

        verticalLayout_4->addWidget(widget_3);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 3);

        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 238, 205);"));
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, 2, 2, 2);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_137 = new QLabel(groupBox_4);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setFont(font2);
        label_137->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:1, y1:0.523045, x2:1, y2:0, stop:0 rgba(193, 42, 40, 255), stop:1 rgba(167, 38, 35, 255));\n"
"color: rgb(255, 255, 255);"));
        label_137->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_137);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setVerticalSpacing(1);
        label_bingo_one = new QLabel(groupBox_4);
        label_bingo_one->setObjectName(QString::fromUtf8("label_bingo_one"));
        label_bingo_one->setMaximumSize(QSize(319, 90));
        label_bingo_one->setFont(font2);
        label_bingo_one->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_one->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_one, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_14, 0, 3, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_8, 0, 1, 1, 1);

        label_bingo_five = new QLabel(groupBox_4);
        label_bingo_five->setObjectName(QString::fromUtf8("label_bingo_five"));
        label_bingo_five->setFont(font2);
        label_bingo_five->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_five->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_five, 4, 0, 1, 1);

        label_bingo_three = new QLabel(groupBox_4);
        label_bingo_three->setObjectName(QString::fromUtf8("label_bingo_three"));
        label_bingo_three->setFont(font2);
        label_bingo_three->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_three->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_three, 2, 0, 1, 1);

        label_bingo_two = new QLabel(groupBox_4);
        label_bingo_two->setObjectName(QString::fromUtf8("label_bingo_two"));
        label_bingo_two->setFont(font2);
        label_bingo_two->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_two->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_two, 1, 0, 1, 1);

        label_bingo_four = new QLabel(groupBox_4);
        label_bingo_four->setObjectName(QString::fromUtf8("label_bingo_four"));
        label_bingo_four->setFont(font2);
        label_bingo_four->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_four->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_four, 3, 0, 1, 1);

        label_first_num = new QLabel(groupBox_4);
        label_first_num->setObjectName(QString::fromUtf8("label_first_num"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font6.setPointSize(30);
        label_first_num->setFont(font6);
        label_first_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_first_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_first_num, 0, 2, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_15, 1, 1, 1, 1);

        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_19, 2, 1, 1, 1);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_20, 3, 1, 1, 1);

        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_21, 4, 1, 1, 1);

        label_fourth_num = new QLabel(groupBox_4);
        label_fourth_num->setObjectName(QString::fromUtf8("label_fourth_num"));
        label_fourth_num->setFont(font6);
        label_fourth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fourth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fourth_num, 3, 2, 1, 1);

        label_fifth_num = new QLabel(groupBox_4);
        label_fifth_num->setObjectName(QString::fromUtf8("label_fifth_num"));
        label_fifth_num->setFont(font6);
        label_fifth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fifth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fifth_num, 4, 2, 1, 1);

        label_third_num = new QLabel(groupBox_4);
        label_third_num->setObjectName(QString::fromUtf8("label_third_num"));
        label_third_num->setFont(font6);
        label_third_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_third_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_third_num, 2, 2, 1, 1);

        label_second_num = new QLabel(groupBox_4);
        label_second_num->setObjectName(QString::fromUtf8("label_second_num"));
        label_second_num->setFont(font6);
        label_second_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_second_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_second_num, 1, 2, 1, 1);

        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_26, 1, 3, 1, 1);

        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_27, 2, 3, 1, 1);

        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_28, 3, 3, 1, 1);

        label_29 = new QLabel(groupBox_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
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

        verticalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_5->addWidget(groupBox_4);

        verticalLayout_5->setStretch(0, 222);
        verticalLayout_5->setStretch(1, 361);
        verticalLayout_5->setStretch(2, 482);

        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pu_init->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        pu_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\261\200\357\274\2106\357\274\211", nullptr));
        pu_changeXue->setText(QCoreApplication::translate("MainWindow", "\346\215\242\351\235\264\357\274\210+\357\274\211", nullptr));
        pu_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\357\274\210/\357\274\211", nullptr));
        pu_leave->setText(QCoreApplication::translate("MainWindow", "\347\246\273\345\274\200\357\274\210.\357\274\211", nullptr));
        pu_useless->setText(QCoreApplication::translate("MainWindow", "\344\275\234\345\272\237\357\274\2100\357\274\211", nullptr));
        pu_zhuang->setText(QCoreApplication::translate("MainWindow", "\345\272\204\357\274\2107\357\274\211", nullptr));
        pu_xian->setText(QCoreApplication::translate("MainWindow", "\351\227\262\357\274\2104\357\274\211", nullptr));
        pu_same->setText(QCoreApplication::translate("MainWindow", "\345\222\214\357\274\2101\357\274\211", nullptr));
        pu_zhuangdui->setText(QCoreApplication::translate("MainWindow", "\345\272\204\345\257\271\357\274\2102\357\274\211", nullptr));
        pu_xiandui->setText(QCoreApplication::translate("MainWindow", "\351\227\262\345\257\271\357\274\2105\357\274\211", nullptr));
        label_123->setText(QCoreApplication::translate("MainWindow", "\345\217\260   \346\241\214   \351\231\220   \347\272\242", nullptr));
        label_minLimit->setText(QString());
        label_122->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\345\272\204</span><span style=\" color:#0055ff;\">\351\227\262</span></p></body></html>", nullptr));
        label_pairMinLimit->setText(QString());
        label_129->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">\345\257\271\345\255\220</span></p></body></html>", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
        label_tieMinLimit->setText(QString());
        groupBox_2->setTitle(QString());
        label_desk_id->setText(QCoreApplication::translate("MainWindow", "A5", nullptr));
        label_result->setText(QString());
        pu_enter->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        pu_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        label_135->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_times_xue->setText(QString());
        label_139->setText(QCoreApplication::translate("MainWindow", "\351\235\264", nullptr));
        label_136->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_times_pu->setText(QString());
        label_140->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        groupBox_3->setTitle(QString());
        label_134->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\261\200\346\212\225\346\263\250\346\234\200\345\244\247\345\211\215\344\270\211", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/1.png\"/></p></body></html>", nullptr));
        label_first_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/2.png\"/></p></body></html>", nullptr));
        label_first_name->setText(QString());
        label_second_name->setText(QString());
        label_first_money->setText(QString());
        label_second_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_second_money->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/3.png\"/></p></body></html>", nullptr));
        label_third_name->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_third_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_third_money->setText(QString());
        groupBox_4->setTitle(QString());
        label_137->setText(QCoreApplication::translate("MainWindow", "\346\234\254\351\235\264\350\277\236\347\273\255\344\270\255\346\263\250\344\270\211\351\223\272\344\273\245\344\270\212", nullptr));
        label_bingo_one->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_bingo_five->setText(QString());
        label_bingo_three->setText(QString());
        label_bingo_two->setText(QString());
        label_bingo_four->setText(QString());
        label_first_num->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_fourth_num->setText(QString());
        label_fifth_num->setText(QString());
        label_third_num->setText(QString());
        label_second_num->setText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
