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
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
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
    QGroupBox *groupBox_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1422, 828);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1161, 571));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        verticalLayout_4->addLayout(gridLayout_3);

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
        pu_enter->setEnabled(false);
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
        pu_cancel->setEnabled(false);
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

        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(groupBox_4);

        verticalLayout_5->setStretch(0, 222);
        verticalLayout_5->setStretch(1, 360);
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
        pu_zhuang->setText(QCoreApplication::translate("MainWindow", "\345\272\204\357\274\2107\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_zhuang->setShortcut(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_xian->setText(QCoreApplication::translate("MainWindow", "\351\227\262\357\274\2104\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_xian->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_same->setText(QCoreApplication::translate("MainWindow", "\345\222\214\357\274\2101\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_same->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_zhuangdui->setText(QCoreApplication::translate("MainWindow", "\345\272\204\345\257\271\357\274\2102\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_zhuangdui->setShortcut(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_xiandui->setText(QCoreApplication::translate("MainWindow", "\351\227\262\345\257\271\357\274\2105\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_xiandui->setShortcut(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
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
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
#if QT_CONFIG(shortcut)
        pu_cancel->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        label_135->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_times_xue->setText(QString());
        label_139->setText(QCoreApplication::translate("MainWindow", "\351\235\264", nullptr));
        label_136->setText(QCoreApplication::translate("MainWindow", "\347\254\254", nullptr));
        label_times_pu->setText(QString());
        label_140->setText(QCoreApplication::translate("MainWindow", "\351\223\272", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
