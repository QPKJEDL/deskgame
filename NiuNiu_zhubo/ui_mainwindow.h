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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pu_init;
    QPushButton *xue_change;
    QPushButton *pu_start;
    QPushButton *pu_exit;
    QPushButton *pu_end;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *desk_num;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QLabel *pu_result;
    QLabel *opration_show;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *xue_times;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *pu_times;
    QHBoxLayout *horizontalLayout_19;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_locate;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *button_locate;
    QPushButton *button_useless;
    QPushButton *button_summit;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *textEdit;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1653, 1282);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 73, 148);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(0,32, 57);\n"
""));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pu_init = new QPushButton(groupBox_2);
        pu_init->setObjectName(QString::fromUtf8("pu_init"));
        pu_init->setEnabled(false);
        pu_init->setMinimumSize(QSize(120, 51));
        pu_init->setMaximumSize(QSize(140, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        pu_init->setFont(font1);
        pu_init->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        gridLayout_2->addWidget(pu_init, 0, 2, 1, 1);

        xue_change = new QPushButton(groupBox_2);
        xue_change->setObjectName(QString::fromUtf8("xue_change"));
        xue_change->setEnabled(false);
        xue_change->setMinimumSize(QSize(120, 51));
        xue_change->setMaximumSize(QSize(140, 60));
        xue_change->setFont(font1);
        xue_change->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        gridLayout_2->addWidget(xue_change, 0, 1, 1, 1);

        pu_start = new QPushButton(groupBox_2);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setMinimumSize(QSize(120, 51));
        pu_start->setMaximumSize(QSize(140, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(18);
        pu_start->setFont(font2);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));
        pu_start->setCheckable(true);
        pu_start->setChecked(false);
        pu_start->setAutoRepeat(false);

        gridLayout_2->addWidget(pu_start, 0, 0, 1, 1);

        pu_exit = new QPushButton(groupBox_2);
        pu_exit->setObjectName(QString::fromUtf8("pu_exit"));
        pu_exit->setEnabled(true);
        pu_exit->setMinimumSize(QSize(120, 51));
        pu_exit->setMaximumSize(QSize(140, 60));
        pu_exit->setFont(font1);
        pu_exit->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        gridLayout_2->addWidget(pu_exit, 0, 4, 1, 1);

        pu_end = new QPushButton(groupBox_2);
        pu_end->setObjectName(QString::fromUtf8("pu_end"));
        pu_end->setEnabled(false);
        pu_end->setMaximumSize(QSize(140, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font3.setPointSize(20);
        pu_end->setFont(font3);
        pu_end->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        gridLayout_2->addWidget(pu_end, 0, 3, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(632, 69));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 32, 57, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 170, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 127, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 42, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 56, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
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
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
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
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush9(QColor(0, 85, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        groupBox->setPalette(palette);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(0,32, 57);\n"
""));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        desk_num = new QLabel(groupBox);
        desk_num->setObjectName(QString::fromUtf8("desk_num"));
        desk_num->setMaximumSize(QSize(16777215, 73));
        QPalette palette1;
        QBrush brush10(QColor(255, 255, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        desk_num->setPalette(palette1);
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        desk_num->setFont(font4);
        desk_num->setStyleSheet(QString::fromUtf8(""));
        desk_num->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(desk_num, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush11(QColor(120, 120, 120, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_11->setPalette(palette2);
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        label_11->setFont(font5);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pu_result = new QLabel(groupBox);
        pu_result->setObjectName(QString::fromUtf8("pu_result"));
        QFont font6;
        font6.setPointSize(12);
        pu_result->setFont(font6);
        pu_result->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pu_result->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(pu_result);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        opration_show = new QLabel(groupBox);
        opration_show->setObjectName(QString::fromUtf8("opration_show"));
        opration_show->setMaximumSize(QSize(16777215, 73));
        QFont font7;
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setWeight(75);
        opration_show->setFont(font7);
        opration_show->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        opration_show->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(opration_show, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        xue_times = new QLabel(groupBox);
        xue_times->setObjectName(QString::fromUtf8("xue_times"));
        xue_times->setFont(font6);
        xue_times->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        xue_times->setLineWidth(1);
        xue_times->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(xue_times);


        gridLayout_3->addLayout(verticalLayout_2, 0, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        pu_times = new QLabel(groupBox);
        pu_times->setObjectName(QString::fromUtf8("pu_times"));
        pu_times->setFont(font6);
        pu_times->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pu_times->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(pu_times);


        gridLayout_3->addLayout(verticalLayout_3, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        verticalLayout_11->addLayout(gridLayout);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        QFont font8;
        font8.setPointSize(22);
        groupBox_4->setFont(font8);
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 48, 90);"));
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        horizontalLayout_19->addWidget(groupBox_4);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(0, 0));
        lineEdit->setCursor(QCursor(Qt::BlankCursor));

        horizontalLayout_19->addWidget(lineEdit);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 32, 57);"));
        groupBox_5->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_locate = new QLabel(groupBox_5);
        label_locate->setObjectName(QString::fromUtf8("label_locate"));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font9.setPointSize(90);
        label_locate->setFont(font9);
        label_locate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_locate->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_locate);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font10;
        font10.setPointSize(20);
        label->setFont(font10);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout_4->addWidget(label);

        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font10);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_2);

        button_locate = new QPushButton(groupBox_5);
        button_locate->setObjectName(QString::fromUtf8("button_locate"));
        button_locate->setEnabled(false);
        button_locate->setMinimumSize(QSize(0, 70));
        button_locate->setFont(font2);
        button_locate->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(button_locate);

        button_useless = new QPushButton(groupBox_5);
        button_useless->setObjectName(QString::fromUtf8("button_useless"));
        button_useless->setEnabled(false);
        button_useless->setMinimumSize(QSize(0, 70));
        button_useless->setFont(font1);
        button_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(button_useless);

        button_summit = new QPushButton(groupBox_5);
        button_summit->setObjectName(QString::fromUtf8("button_summit"));
        button_summit->setEnabled(false);
        button_summit->setMinimumSize(QSize(0, 70));
        button_summit->setFont(font2);
        button_summit->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        verticalLayout_4->addWidget(button_summit);


        horizontalLayout_19->addWidget(groupBox_5);

        horizontalLayout_19->setStretch(0, 4);
        horizontalLayout_19->setStretch(2, 1);

        verticalLayout_11->addLayout(horizontalLayout_19);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_10->addWidget(textEdit);


        horizontalLayout_24->addLayout(verticalLayout_10);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(2, 2, 2, 2);

        horizontalLayout_24->addWidget(groupBox_6);

        horizontalLayout_24->setStretch(0, 4);
        horizontalLayout_24->setStretch(1, 1);

        verticalLayout_11->addLayout(horizontalLayout_24);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 3);
        verticalLayout_11->setStretch(2, 6);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        pu_init->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        xue_change->setText(QCoreApplication::translate("MainWindow", "\346\215\242\351\235\264(+)", nullptr));
#if QT_CONFIG(shortcut)
        xue_change->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\261\200\357\274\2106\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_start->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\357\274\210.\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        pu_exit->setShortcut(QCoreApplication::translate("MainWindow", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        pu_end->setText(QCoreApplication::translate("MainWindow", "\347\273\210\346\255\242", nullptr));
        groupBox->setTitle(QString());
        desk_num->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\236\234", nullptr));
        pu_result->setText(QString());
        opration_show->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\347\273\223", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\235\264\346\254\241", nullptr));
        xue_times->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\351\223\272\346\254\241", nullptr));
        pu_times->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        label_locate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\256\232\344\275\215", nullptr));
        lineEdit_2->setText(QString());
        button_locate->setText(QCoreApplication::translate("MainWindow", "\345\256\232\344\275\215\357\274\210*\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        button_locate->setShortcut(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        button_useless->setText(QCoreApplication::translate("MainWindow", "\344\275\234\345\272\237\357\274\2100\357\274\211", nullptr));
#if QT_CONFIG(shortcut)
        button_useless->setShortcut(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        button_summit->setText(QCoreApplication::translate("MainWindow", "\346\217\220\344\272\244", nullptr));
#if QT_CONFIG(shortcut)
        button_summit->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_6->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
