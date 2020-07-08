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
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pu_init;
    QPushButton *pu_start;
    QPushButton *pu_changeXue;
    QPushButton *pu_stop;
    QPushButton *pu_leave;
    QPushButton *pu_useless;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pu_long;
    QPushButton *pu_tiger;
    QPushButton *pu_same;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QGridLayout *gridLayout_3;
    QLabel *label_126;
    QLabel *label_same;
    QLabel *label_minLimit;
    QLabel *label_tieMinLimit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *ChatPanel;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label_result;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_xues;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_pus;
    QLabel *label_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_134;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *label_first_bet;
    QLabel *label_11;
    QLabel *label_first_name;
    QLabel *label_second_name;
    QLabel *label_first_money;
    QLabel *label_second_bet;
    QLabel *label_13;
    QLabel *label_second_money;
    QLabel *label_8;
    QLabel *label_16;
    QLabel *label_third_name;
    QLabel *label_18;
    QLabel *label_third_bet;
    QLabel *label_third_money;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_137;
    QGridLayout *gridLayout_5;
    QLabel *label_bingo_one;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_bingo_five;
    QLabel *label_bingo_three;
    QLabel *label_bingo_two;
    QLabel *label_bingo_four;
    QLabel *label_first_num;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
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
        MainWindow->resize(1691, 1088);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 40, 50);"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        horizontalLayout->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pu_init = new QPushButton(groupBox);
        pu_init->setObjectName(QString::fromUtf8("pu_init"));
        pu_init->setEnabled(false);
        pu_init->setMinimumSize(QSize(80, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(15);
        pu_init->setFont(font);
        pu_init->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_init);

        pu_start = new QPushButton(groupBox);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setMinimumSize(QSize(80, 50));
        pu_start->setFont(font);
        pu_start->setAcceptDrops(true);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_start);

        pu_changeXue = new QPushButton(groupBox);
        pu_changeXue->setObjectName(QString::fromUtf8("pu_changeXue"));
        pu_changeXue->setEnabled(false);
        pu_changeXue->setMinimumSize(QSize(80, 50));
        pu_changeXue->setFont(font);
        pu_changeXue->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_changeXue);

        pu_stop = new QPushButton(groupBox);
        pu_stop->setObjectName(QString::fromUtf8("pu_stop"));
        pu_stop->setEnabled(false);
        pu_stop->setMinimumSize(QSize(80, 50));
        pu_stop->setFont(font);
        pu_stop->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_stop);

        pu_leave = new QPushButton(groupBox);
        pu_leave->setObjectName(QString::fromUtf8("pu_leave"));
        pu_leave->setEnabled(false);
        pu_leave->setMinimumSize(QSize(80, 50));
        pu_leave->setFont(font);
        pu_leave->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_leave);

        pu_useless = new QPushButton(groupBox);
        pu_useless->setObjectName(QString::fromUtf8("pu_useless"));
        pu_useless->setEnabled(false);
        pu_useless->setMinimumSize(QSize(80, 50));
        pu_useless->setFont(font);
        pu_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/result/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/result/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_useless);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pu_long = new QPushButton(groupBox);
        pu_long->setObjectName(QString::fromUtf8("pu_long"));
        pu_long->setEnabled(false);
        pu_long->setMinimumSize(QSize(80, 50));
        pu_long->setFont(font);
        pu_long->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(pu_long);

        pu_tiger = new QPushButton(groupBox);
        pu_tiger->setObjectName(QString::fromUtf8("pu_tiger"));
        pu_tiger->setEnabled(false);
        pu_tiger->setMinimumSize(QSize(80, 50));
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
        pu_tiger->setFont(font);
        pu_tiger->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(pu_tiger);

        pu_same = new QPushButton(groupBox);
        pu_same->setObjectName(QString::fromUtf8("pu_same"));
        pu_same->setEnabled(false);
        pu_same->setMinimumSize(QSize(80, 50));
        pu_same->setFont(font);
        pu_same->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(pu_same);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(25);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(255, 255, 0);solid grey; border-radius: 8px;}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_126 = new QLabel(groupBox);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(20);
        label_126->setFont(font2);
        label_126->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);"));
        label_126->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_126, 0, 0, 1, 1);

        label_same = new QLabel(groupBox);
        label_same->setObjectName(QString::fromUtf8("label_same"));
        label_same->setFont(font2);
        label_same->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(85, 255, 0);"));
        label_same->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_same, 1, 0, 1, 1);

        label_minLimit = new QLabel(groupBox);
        label_minLimit->setObjectName(QString::fromUtf8("label_minLimit"));
        label_minLimit->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font3.setPointSize(18);
        label_minLimit->setFont(font3);
        label_minLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_minLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_minLimit, 0, 1, 1, 1);

        label_tieMinLimit = new QLabel(groupBox);
        label_tieMinLimit->setObjectName(QString::fromUtf8("label_tieMinLimit"));
        label_tieMinLimit->setFont(font3);
        label_tieMinLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 74, 123);\n"
"color: rgb(255, 255, 255);"));
        label_tieMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_tieMinLimit, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_9->addWidget(groupBox);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1383, 708));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        ChatPanel = new QGridLayout();
        ChatPanel->setObjectName(QString::fromUtf8("ChatPanel"));

        verticalLayout_10->addLayout(ChatPanel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_9->addWidget(scrollArea);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(1, 5);

        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(groupBox_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.254237 rgba(255, 118, 96, 255), stop:0.949153 rgba(167, 38, 35, 255), stop:1 rgba(167, 38, 35, 255));"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(223, 238, 118);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        label_result = new QLabel(widget_2);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setMaximumSize(QSize(16777215, 40));
        label_result->setFont(font2);
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 15, 12);\n"
"color: rgb(255, 255, 255);"));
        label_result->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_result);

        pu_enter = new QPushButton(widget_2);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setEnabled(false);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font4.setPointSize(16);
        pu_enter->setFont(font4);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(121, 61, 3);background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.153409 rgba(252, 238, 205, 255), stop:1 rgba(153, 118, 97, 255));border:1px solid grey; border-radius: 0px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.1875 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_4->addWidget(pu_enter);

        pu_cancel = new QPushButton(widget_2);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setEnabled(false);
        pu_cancel->setFont(font4);
        pu_cancel->setCursor(QCursor(Qt::ArrowCursor));
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(121, 61, 3);background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.153409 rgba(252, 238, 205, 255), stop:1 rgba(153, 118, 97, 255));border:1px solid grey; border-radius: 0px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0.1875 rgba(153, 118, 97, 255), stop:1 rgba(252, 238, 205, 255));}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_4->addWidget(pu_cancel);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 2);
        horizontalLayout_4->setStretch(3, 2);

        verticalLayout->addWidget(widget_2);

        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 15, 12);"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);

        label_xues = new QLabel(widget);
        label_xues->setObjectName(QString::fromUtf8("label_xues"));
        label_xues->setFont(font2);
        label_xues->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_xues->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_xues);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        label_pus = new QLabel(widget);
        label_pus->setObjectName(QString::fromUtf8("label_pus"));
        label_pus->setFont(font2);
        label_pus->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_pus->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_pus);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);solid grey; border-radius: 8px;}"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_134 = new QLabel(groupBox_4);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setFont(font2);
        label_134->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 101, 255);"));
        label_134->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_134);

        widget_3 = new QWidget(groupBox_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 57);"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(1);
        gridLayout_4->setContentsMargins(-1, 1, -1, 1);
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        label_first_bet = new QLabel(widget_3);
        label_first_bet->setObjectName(QString::fromUtf8("label_first_bet"));
        label_first_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_first_bet, 0, 3, 1, 1);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        label_first_name = new QLabel(widget_3);
        label_first_name->setObjectName(QString::fromUtf8("label_first_name"));
        label_first_name->setFont(font2);
        label_first_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_name->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_first_name, 0, 1, 1, 1);

        label_second_name = new QLabel(widget_3);
        label_second_name->setObjectName(QString::fromUtf8("label_second_name"));
        label_second_name->setFont(font2);
        label_second_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_name->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_second_name, 1, 1, 1, 1);

        label_first_money = new QLabel(widget_3);
        label_first_money->setObjectName(QString::fromUtf8("label_first_money"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(20);
        label_first_money->setFont(font5);
        label_first_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_first_money->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_first_money, 0, 4, 1, 1);

        label_second_bet = new QLabel(widget_3);
        label_second_bet->setObjectName(QString::fromUtf8("label_second_bet"));
        label_second_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_second_bet, 1, 3, 1, 1);

        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        label_13->setFont(font6);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(label_13, 1, 2, 1, 1);

        label_second_money = new QLabel(widget_3);
        label_second_money->setObjectName(QString::fromUtf8("label_second_money"));
        label_second_money->setFont(font5);
        label_second_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_second_money->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_second_money, 1, 4, 1, 1);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        label_8->setFont(font7);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_8, 0, 2, 1, 1);

        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_16, 2, 0, 1, 1);

        label_third_name = new QLabel(widget_3);
        label_third_name->setObjectName(QString::fromUtf8("label_third_name"));
        label_third_name->setFont(font2);
        label_third_name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_name->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_third_name, 2, 1, 1, 1);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font6);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(label_18, 2, 2, 1, 1);

        label_third_bet = new QLabel(widget_3);
        label_third_bet->setObjectName(QString::fromUtf8("label_third_bet"));
        label_third_bet->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(label_third_bet, 2, 3, 1, 1);

        label_third_money = new QLabel(widget_3);
        label_third_money->setObjectName(QString::fromUtf8("label_third_money"));
        label_third_money->setFont(font5);
        label_third_money->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_third_money->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_third_money, 2, 4, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 2);
        gridLayout_4->setColumnStretch(2, 1);
        gridLayout_4->setColumnStretch(3, 1);
        gridLayout_4->setColumnStretch(4, 2);

        verticalLayout_6->addWidget(widget_3);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 3);

        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 238, 205);"));
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, 2, 2, 2);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_137 = new QLabel(groupBox_5);
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
        label_bingo_one = new QLabel(groupBox_5);
        label_bingo_one->setObjectName(QString::fromUtf8("label_bingo_one"));
        label_bingo_one->setMaximumSize(QSize(319, 90));
        label_bingo_one->setFont(font2);
        label_bingo_one->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_one->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_one, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_14, 0, 3, 1, 1);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_10, 0, 1, 1, 1);

        label_bingo_five = new QLabel(groupBox_5);
        label_bingo_five->setObjectName(QString::fromUtf8("label_bingo_five"));
        label_bingo_five->setFont(font2);
        label_bingo_five->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_five->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_five, 4, 0, 1, 1);

        label_bingo_three = new QLabel(groupBox_5);
        label_bingo_three->setObjectName(QString::fromUtf8("label_bingo_three"));
        label_bingo_three->setFont(font2);
        label_bingo_three->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_three->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_three, 2, 0, 1, 1);

        label_bingo_two = new QLabel(groupBox_5);
        label_bingo_two->setObjectName(QString::fromUtf8("label_bingo_two"));
        label_bingo_two->setFont(font2);
        label_bingo_two->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_two->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_two, 1, 0, 1, 1);

        label_bingo_four = new QLabel(groupBox_5);
        label_bingo_four->setObjectName(QString::fromUtf8("label_bingo_four"));
        label_bingo_four->setFont(font2);
        label_bingo_four->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_bingo_four->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_bingo_four, 3, 0, 1, 1);

        label_first_num = new QLabel(groupBox_5);
        label_first_num->setObjectName(QString::fromUtf8("label_first_num"));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font8.setPointSize(30);
        label_first_num->setFont(font8);
        label_first_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_first_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_first_num, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_20, 1, 1, 1, 1);

        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_21, 2, 1, 1, 1);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_22, 3, 1, 1, 1);

        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font2);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_23, 4, 1, 1, 1);

        label_fourth_num = new QLabel(groupBox_5);
        label_fourth_num->setObjectName(QString::fromUtf8("label_fourth_num"));
        label_fourth_num->setFont(font8);
        label_fourth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fourth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fourth_num, 3, 2, 1, 1);

        label_fifth_num = new QLabel(groupBox_5);
        label_fifth_num->setObjectName(QString::fromUtf8("label_fifth_num"));
        label_fifth_num->setFont(font8);
        label_fifth_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_fifth_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_fifth_num, 4, 2, 1, 1);

        label_third_num = new QLabel(groupBox_5);
        label_third_num->setObjectName(QString::fromUtf8("label_third_num"));
        label_third_num->setFont(font8);
        label_third_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_third_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_third_num, 2, 2, 1, 1);

        label_second_num = new QLabel(groupBox_5);
        label_second_num->setObjectName(QString::fromUtf8("label_second_num"));
        label_second_num->setFont(font8);
        label_second_num->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_second_num->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_second_num, 1, 2, 1, 1);

        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_26, 1, 3, 1, 1);

        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_27, 2, 3, 1, 1);

        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(74, 15, 12);"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_28, 3, 3, 1, 1);

        label_29 = new QLabel(groupBox_5);
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


        verticalLayout_3->addWidget(groupBox_5);

        verticalLayout_3->setStretch(0, 222);
        verticalLayout_3->setStretch(1, 361);
        verticalLayout_3->setStretch(2, 482);

        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
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
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\260  \346\241\214  \351\231\220  \347\272\242", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "\351\276\231\350\231\216", nullptr));
        label_same->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
        label_minLimit->setText(QString());
        label_tieMinLimit->setText(QString());
        groupBox_3->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "AA", nullptr));
        label_result->setText(QString());
        pu_enter->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
#if QT_CONFIG(shortcut)
        pu_cancel->setShortcut(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_xues->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\351\235\264", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_pus->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        groupBox_4->setTitle(QString());
        label_134->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\261\200\346\212\225\346\263\250\346\234\200\345\244\247\345\211\215\344\270\211", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/1.png\"/></p></body></html>", nullptr));
        label_first_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/2.png\"/></p></body></html>", nullptr));
        label_first_name->setText(QString());
        label_second_name->setText(QString());
        label_first_money->setText(QString());
        label_second_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_second_money->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/icon/image/icon/3.png\"/></p></body></html>", nullptr));
        label_third_name->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\212\225\346\263\250", nullptr));
        label_third_bet->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_third_money->setText(QString());
        groupBox_5->setTitle(QString());
        label_137->setText(QCoreApplication::translate("MainWindow", "\346\234\254\351\235\264\350\277\236\347\273\255\344\270\255\346\263\250\344\270\211\351\223\272\344\273\245\344\270\212", nullptr));
        label_bingo_one->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_bingo_five->setText(QString());
        label_bingo_three->setText(QString());
        label_bingo_two->setText(QString());
        label_bingo_four->setText(QString());
        label_first_num->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\350\277\236\344\270\255", nullptr));
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
