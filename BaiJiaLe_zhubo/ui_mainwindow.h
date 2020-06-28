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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_desk_id;
    QLabel *label_8;
    QPushButton *pu_enter;
    QPushButton *pu_cancel;
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_137;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pu_start;
    QPushButton *pu_changeXue;
    QPushButton *pu_stop;
    QPushButton *pu_leave;
    QPushButton *pu_useless;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pu_zhuang;
    QPushButton *pu_xian;
    QPushButton *pu_same;
    QPushButton *pu_zhuangdui;
    QPushButton *pu_xiandui;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_123;
    QGridLayout *gridLayout;
    QLabel *label_minLimit;
    QLabel *label_122;
    QLabel *label_pairMinLimit;
    QLabel *label_129;
    QLabel *label_128;
    QLabel *label_tieMinLimit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1917, 1085);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 40, 50);"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1550, 10, 341, 201));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_desk_id = new QLabel(groupBox_2);
        label_desk_id->setObjectName(QString::fromUtf8("label_desk_id"));
        label_desk_id->setMinimumSize(QSize(50, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(30);
        label_desk_id->setFont(font);
        label_desk_id->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_desk_id);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 40));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);"));

        horizontalLayout->addWidget(label_8);

        pu_enter = new QPushButton(groupBox_2);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(25);
        pu_enter->setFont(font1);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_enter);

        pu_cancel = new QPushButton(groupBox_2);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setEnabled(false);
        pu_cancel->setFont(font1);
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_cancel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_135 = new QLabel(groupBox_2);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(20);
        label_135->setFont(font2);
        label_135->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_135->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_135);

        label_times_xue = new QLabel(groupBox_2);
        label_times_xue->setObjectName(QString::fromUtf8("label_times_xue"));
        label_times_xue->setFont(font2);
        label_times_xue->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_times_xue->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_times_xue);

        label_139 = new QLabel(groupBox_2);
        label_139->setObjectName(QString::fromUtf8("label_139"));
        label_139->setFont(font2);
        label_139->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_139->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_139);

        label_136 = new QLabel(groupBox_2);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        label_136->setFont(font2);
        label_136->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_136->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_136);

        label_times_pu = new QLabel(groupBox_2);
        label_times_pu->setObjectName(QString::fromUtf8("label_times_pu"));
        label_times_pu->setFont(font2);
        label_times_pu->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_times_pu->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_times_pu);

        label_140 = new QLabel(groupBox_2);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        label_140->setFont(font2);
        label_140->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_140->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_140);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1550, 220, 341, 351));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);solid grey; border-radius: 8px;}"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_134 = new QLabel(groupBox_3);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setFont(font2);
        label_134->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));
        label_134->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_134);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_4->addWidget(label_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(1550, 580, 341, 461));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{color: rgb(0, 0, 0);background-image: url(:/button/pu_yellow.png);solid grey; border-radius: 8px;}"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_137 = new QLabel(groupBox_4);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setFont(font2);
        label_137->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));
        label_137->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_137);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_5->addWidget(label_4);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_5->addWidget(label_5);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));

        verticalLayout_5->addWidget(label_7);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 420, 1541, 621));
        QPalette palette;
        QBrush brush(QColor(255, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(30, 40, 50, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 212, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 85, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 113, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        textEdit->setPalette(palette);
        QFont font3;
        font3.setPointSize(40);
        textEdit->setFont(font3);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1541, 411));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 981, 391));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1000, 10, 111, 391));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pu_start = new QPushButton(layoutWidget1);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setMinimumSize(QSize(80, 50));
        pu_start->setMaximumSize(QSize(119, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font4.setPointSize(15);
        pu_start->setFont(font4);
        pu_start->setAcceptDrops(true);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);border-image: url(:/button/image/button/pu_yellow.png);;solid grey; border-radius: 8px;}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_start);

        pu_changeXue = new QPushButton(layoutWidget1);
        pu_changeXue->setObjectName(QString::fromUtf8("pu_changeXue"));
        pu_changeXue->setEnabled(false);
        pu_changeXue->setMinimumSize(QSize(80, 50));
        pu_changeXue->setMaximumSize(QSize(119, 50));
        pu_changeXue->setFont(font4);
        pu_changeXue->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);border-image: url(:/button/image/button/pu_yellow.png);;solid grey; border-radius: 8px;}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_changeXue);

        pu_stop = new QPushButton(layoutWidget1);
        pu_stop->setObjectName(QString::fromUtf8("pu_stop"));
        pu_stop->setEnabled(false);
        pu_stop->setMinimumSize(QSize(80, 50));
        pu_stop->setMaximumSize(QSize(119, 50));
        pu_stop->setFont(font4);
        pu_stop->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);border-image: url(:/button/image/button/pu_yellow.png);;solid grey; border-radius: 8px;}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_stop);

        pu_leave = new QPushButton(layoutWidget1);
        pu_leave->setObjectName(QString::fromUtf8("pu_leave"));
        pu_leave->setEnabled(false);
        pu_leave->setMinimumSize(QSize(80, 50));
        pu_leave->setMaximumSize(QSize(119, 50));
        pu_leave->setFont(font4);
        pu_leave->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);border-image: url(:/button/image/button/pu_yellow.png);;solid grey; border-radius: 8px;}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_leave);

        pu_useless = new QPushButton(layoutWidget1);
        pu_useless->setObjectName(QString::fromUtf8("pu_useless"));
        pu_useless->setEnabled(false);
        pu_useless->setMinimumSize(QSize(80, 50));
        pu_useless->setMaximumSize(QSize(119, 50));
        pu_useless->setFont(font4);
        pu_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);border-image: url(:/button/image/button/pu_yellow.png);;solid grey; border-radius: 8px;}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/pu_yellow_an.png);\n"
"}"));

        verticalLayout_2->addWidget(pu_useless);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1120, 10, 121, 391));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pu_zhuang = new QPushButton(layoutWidget2);
        pu_zhuang->setObjectName(QString::fromUtf8("pu_zhuang"));
        pu_zhuang->setEnabled(false);
        pu_zhuang->setMinimumSize(QSize(80, 50));
        pu_zhuang->setMaximumSize(QSize(119, 50));
        pu_zhuang->setFont(font4);
        pu_zhuang->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_zhuang);

        pu_xian = new QPushButton(layoutWidget2);
        pu_xian->setObjectName(QString::fromUtf8("pu_xian"));
        pu_xian->setEnabled(false);
        pu_xian->setMinimumSize(QSize(80, 50));
        pu_xian->setMaximumSize(QSize(119, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush9(QColor(50, 73, 138, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        QBrush brush11(QColor(255, 255, 255, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QBrush brush12(QColor(99, 99, 99, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        QBrush brush13(QColor(255, 255, 255, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pu_xian->setPalette(palette1);
        pu_xian->setFont(font4);
        pu_xian->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_xian);

        pu_same = new QPushButton(layoutWidget2);
        pu_same->setObjectName(QString::fromUtf8("pu_same"));
        pu_same->setEnabled(false);
        pu_same->setMinimumSize(QSize(80, 50));
        pu_same->setMaximumSize(QSize(119, 50));
        pu_same->setFont(font4);
        pu_same->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_same);

        pu_zhuangdui = new QPushButton(layoutWidget2);
        pu_zhuangdui->setObjectName(QString::fromUtf8("pu_zhuangdui"));
        pu_zhuangdui->setEnabled(false);
        pu_zhuangdui->setMinimumSize(QSize(80, 50));
        pu_zhuangdui->setMaximumSize(QSize(119, 50));
        pu_zhuangdui->setFont(font4);
        pu_zhuangdui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_zhuangdui);

        pu_xiandui = new QPushButton(layoutWidget2);
        pu_xiandui->setObjectName(QString::fromUtf8("pu_xiandui"));
        pu_xiandui->setEnabled(false);
        pu_xiandui->setMinimumSize(QSize(80, 50));
        pu_xiandui->setMaximumSize(QSize(119, 50));
        pu_xiandui->setFont(font4);
        pu_xiandui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_3->addWidget(pu_xiandui);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1250, 10, 280, 391));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_123 = new QLabel(layoutWidget3);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setMinimumSize(QSize(90, 60));
        label_123->setMaximumSize(QSize(279, 100));
        label_123->setFont(font1);
        label_123->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(255, 255, 0);solid grey; border-radius: 8px;}"));
        label_123->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_123);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_minLimit = new QLabel(layoutWidget3);
        label_minLimit->setObjectName(QString::fromUtf8("label_minLimit"));
        label_minLimit->setMinimumSize(QSize(180, 60));
        label_minLimit->setFont(font2);
        label_minLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_minLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_minLimit, 0, 1, 1, 1);

        label_122 = new QLabel(layoutWidget3);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setMinimumSize(QSize(90, 60));
        label_122->setFont(font2);
        label_122->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_122->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_122, 0, 0, 1, 1);

        label_pairMinLimit = new QLabel(layoutWidget3);
        label_pairMinLimit->setObjectName(QString::fromUtf8("label_pairMinLimit"));
        label_pairMinLimit->setMinimumSize(QSize(180, 60));
        label_pairMinLimit->setFont(font2);
        label_pairMinLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_pairMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_pairMinLimit, 2, 1, 1, 1);

        label_129 = new QLabel(layoutWidget3);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setMinimumSize(QSize(90, 60));
        label_129->setFont(font2);
        label_129->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        label_129->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_129, 2, 0, 1, 1);

        label_128 = new QLabel(layoutWidget3);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setMinimumSize(QSize(90, 60));
        label_128->setFont(font2);
        label_128->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_128->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_128, 1, 0, 1, 1);

        label_tieMinLimit = new QLabel(layoutWidget3);
        label_tieMinLimit->setObjectName(QString::fromUtf8("label_tieMinLimit"));
        label_tieMinLimit->setMinimumSize(QSize(180, 60));
        label_tieMinLimit->setFont(font2);
        label_tieMinLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_tieMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tieMinLimit, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

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
        groupBox_2->setTitle(QString());
        label_desk_id->setText(QString());
        label_8->setText(QString());
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
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        groupBox_4->setTitle(QString());
        label_137->setText(QCoreApplication::translate("MainWindow", "\346\234\254\351\235\264\350\277\236\347\273\255\344\270\255\346\263\250\344\270\211\351\223\272\344\273\245\344\270\212", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        groupBox->setTitle(QString());
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
