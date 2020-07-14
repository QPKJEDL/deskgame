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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pu_init;
    QPushButton *pu_start;
    QPushButton *pu_changeXue;
    QPushButton *pu_stop;
    QPushButton *pu_leave;
    QPushButton *pu_useless;
    QPushButton *pu_zhuang;
    QPushButton *pu_xian;
    QPushButton *pu_same;
    QPushButton *pu_zhuangdui;
    QPushButton *pu_xiandui;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_143;
    QPushButton *pu_cancel;
    QLabel *label_126;
    QLabel *label_desk_id;
    QPushButton *pu_enter;
    QLabel *label_result;
    QGridLayout *gridLayout_3;
    QLabel *label_minLimit;
    QLabel *label_123;
    QLabel *label_tieMinLimit;
    QLabel *label_pairMaxLimit;
    QLabel *label_maxLimit;
    QLabel *label_127;
    QLabel *label_122;
    QLabel *label_tieMaxLimit;
    QLabel *label_128;
    QLabel *label_pairMinLimit;
    QLabel *label_129;
    QGridLayout *gridLayout_6;
    QLabel *label_140;
    QLabel *label_result_zhuangDui;
    QLabel *label_137;
    QLabel *label_result_xian;
    QLabel *label_result_xianDui;
    QLabel *label_result_same;
    QLabel *label_139;
    QLabel *label_136;
    QLabel *label_times_pu;
    QLabel *label_times_xue;
    QLabel *label_134;
    QLabel *label_138;
    QLabel *label_result_zhuang;
    QLabel *label_135;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_zwl_one;
    QLabel *label_zwl_two;
    QLabel *label_zwl_three;
    QLabel *label_2;
    QLabel *label_xwl_one;
    QLabel *label_xwl_two;
    QLabel *label_xwl_three;
    QLabel *label_up_pave;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1373, 892);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 40, 50);"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pu_init = new QPushButton(groupBox);
        pu_init->setObjectName(QString::fromUtf8("pu_init"));
        pu_init->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(11);
        pu_init->setFont(font);
        pu_init->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_init);

        pu_start = new QPushButton(groupBox);
        pu_start->setObjectName(QString::fromUtf8("pu_start"));
        pu_start->setEnabled(false);
        pu_start->setFont(font);
        pu_start->setAcceptDrops(true);
        pu_start->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_start);

        pu_changeXue = new QPushButton(groupBox);
        pu_changeXue->setObjectName(QString::fromUtf8("pu_changeXue"));
        pu_changeXue->setEnabled(false);
        pu_changeXue->setFont(font);
        pu_changeXue->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_changeXue);

        pu_stop = new QPushButton(groupBox);
        pu_stop->setObjectName(QString::fromUtf8("pu_stop"));
        pu_stop->setEnabled(false);
        pu_stop->setFont(font);
        pu_stop->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_stop);

        pu_leave = new QPushButton(groupBox);
        pu_leave->setObjectName(QString::fromUtf8("pu_leave"));
        pu_leave->setEnabled(false);
        pu_leave->setFont(font);
        pu_leave->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_leave);

        pu_useless = new QPushButton(groupBox);
        pu_useless->setObjectName(QString::fromUtf8("pu_useless"));
        pu_useless->setEnabled(false);
        pu_useless->setFont(font);
        pu_useless->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        horizontalLayout->addWidget(pu_useless);

        pu_zhuang = new QPushButton(groupBox);
        pu_zhuang->setObjectName(QString::fromUtf8("pu_zhuang"));
        pu_zhuang->setEnabled(false);
        pu_zhuang->setFont(font);
        pu_zhuang->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_zhuang);

        pu_xian = new QPushButton(groupBox);
        pu_xian->setObjectName(QString::fromUtf8("pu_xian"));
        pu_xian->setEnabled(false);
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

        horizontalLayout->addWidget(pu_xian);

        pu_same = new QPushButton(groupBox);
        pu_same->setObjectName(QString::fromUtf8("pu_same"));
        pu_same->setEnabled(false);
        pu_same->setFont(font);
        pu_same->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(60, 160, 74);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(39, 78, 55);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_same);

        pu_zhuangdui = new QPushButton(groupBox);
        pu_zhuangdui->setObjectName(QString::fromUtf8("pu_zhuangdui"));
        pu_zhuangdui->setEnabled(false);
        pu_zhuangdui->setFont(font);
        pu_zhuangdui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color: rgb(114, 58, 62);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_zhuangdui);

        pu_xiandui = new QPushButton(groupBox);
        pu_xiandui->setObjectName(QString::fromUtf8("pu_xiandui"));
        pu_xiandui->setEnabled(false);
        pu_xiandui->setFont(font);
        pu_xiandui->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(255, 255, 255);background:rgb(50, 73, 138);border:1px solid grey; border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(139,170,105)}\n"
"QPushButton:pressed{border-color:gray;background-color:rgb(54, 65, 97);}\n"
"QPushButton:disabled{border-color:gray;background-color: rgb(99, 99, 99);\n"
"}"));

        horizontalLayout->addWidget(pu_xiandui);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout->addLayout(gridLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_143 = new QLabel(groupBox_2);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        label_143->setFont(font);
        label_143->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        gridLayout->addWidget(label_143, 0, 2, 1, 1);

        pu_cancel = new QPushButton(groupBox_2);
        pu_cancel->setObjectName(QString::fromUtf8("pu_cancel"));
        pu_cancel->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(20);
        pu_cancel->setFont(font1);
        pu_cancel->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        gridLayout->addWidget(pu_cancel, 0, 5, 1, 1);

        label_126 = new QLabel(groupBox_2);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setFont(font);
        label_126->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        gridLayout->addWidget(label_126, 0, 0, 1, 1);

        label_desk_id = new QLabel(groupBox_2);
        label_desk_id->setObjectName(QString::fromUtf8("label_desk_id"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font2.setPointSize(9);
        label_desk_id->setFont(font2);
        label_desk_id->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        gridLayout->addWidget(label_desk_id, 0, 1, 1, 1);

        pu_enter = new QPushButton(groupBox_2);
        pu_enter->setObjectName(QString::fromUtf8("pu_enter"));
        pu_enter->setEnabled(false);
        pu_enter->setFont(font1);
        pu_enter->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(0, 0, 0);background-image: url(:/button/images/button/pu_yellow.png);}\n"
"QPushButton:pressed{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}\n"
"QPushButton:disabled{border-color:gray;background-image: url(:/button/images/button/pu_yellow_an.png);\n"
"}"));

        gridLayout->addWidget(pu_enter, 0, 4, 1, 1);

        label_result = new QLabel(groupBox_2);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setFont(font2);
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_result, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_minLimit = new QLabel(groupBox_2);
        label_minLimit->setObjectName(QString::fromUtf8("label_minLimit"));
        label_minLimit->setFont(font1);
        label_minLimit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 41, 80);"));
        label_minLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_minLimit, 1, 1, 1, 1);

        label_123 = new QLabel(groupBox_2);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font3.setPointSize(15);
        label_123->setFont(font3);
        label_123->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_123->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_123, 1, 0, 1, 1);

        label_tieMinLimit = new QLabel(groupBox_2);
        label_tieMinLimit->setObjectName(QString::fromUtf8("label_tieMinLimit"));
        label_tieMinLimit->setFont(font1);
        label_tieMinLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 80);color: rgb(255, 255, 255);"));
        label_tieMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_tieMinLimit, 1, 2, 1, 1);

        label_pairMaxLimit = new QLabel(groupBox_2);
        label_pairMaxLimit->setObjectName(QString::fromUtf8("label_pairMaxLimit"));
        label_pairMaxLimit->setFont(font1);
        label_pairMaxLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 80);color: rgb(255, 255, 255);"));
        label_pairMaxLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pairMaxLimit, 2, 3, 1, 1);

        label_maxLimit = new QLabel(groupBox_2);
        label_maxLimit->setObjectName(QString::fromUtf8("label_maxLimit"));
        label_maxLimit->setFont(font1);
        label_maxLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 80);color: rgb(255, 255, 255);"));
        label_maxLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_maxLimit, 2, 1, 1, 1);

        label_127 = new QLabel(groupBox_2);
        label_127->setObjectName(QString::fromUtf8("label_127"));
        label_127->setFont(font3);
        label_127->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_127->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_127, 2, 0, 1, 1);

        label_122 = new QLabel(groupBox_2);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setFont(font3);
        label_122->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        label_122->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_122, 0, 1, 1, 1);

        label_tieMaxLimit = new QLabel(groupBox_2);
        label_tieMaxLimit->setObjectName(QString::fromUtf8("label_tieMaxLimit"));
        label_tieMaxLimit->setFont(font1);
        label_tieMaxLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 80);color: rgb(255, 255, 255);"));
        label_tieMaxLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_tieMaxLimit, 2, 2, 1, 1);

        label_128 = new QLabel(groupBox_2);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setFont(font3);
        label_128->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_128->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_128, 0, 2, 1, 1);

        label_pairMinLimit = new QLabel(groupBox_2);
        label_pairMinLimit->setObjectName(QString::fromUtf8("label_pairMinLimit"));
        label_pairMinLimit->setFont(font1);
        label_pairMinLimit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 80);color: rgb(255, 255, 255);"));
        label_pairMinLimit->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pairMinLimit, 1, 3, 1, 1);

        label_129 = new QLabel(groupBox_2);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setFont(font3);
        label_129->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        label_129->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_129, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_140 = new QLabel(groupBox_2);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        label_140->setFont(font3);
        label_140->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(255, 255, 0);"));
        label_140->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_140, 0, 6, 1, 1);

        label_result_zhuangDui = new QLabel(groupBox_2);
        label_result_zhuangDui->setObjectName(QString::fromUtf8("label_result_zhuangDui"));
        label_result_zhuangDui->setFont(font1);
        label_result_zhuangDui->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_result_zhuangDui->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_result_zhuangDui, 1, 3, 1, 1);

        label_137 = new QLabel(groupBox_2);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setFont(font3);
        label_137->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(170, 0, 0);"));
        label_137->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_137, 0, 3, 1, 1);

        label_result_xian = new QLabel(groupBox_2);
        label_result_xian->setObjectName(QString::fromUtf8("label_result_xian"));
        label_result_xian->setFont(font1);
        label_result_xian->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_result_xian->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_result_xian, 1, 1, 1, 1);

        label_result_xianDui = new QLabel(groupBox_2);
        label_result_xianDui->setObjectName(QString::fromUtf8("label_result_xianDui"));
        label_result_xianDui->setFont(font1);
        label_result_xianDui->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_result_xianDui->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_result_xianDui, 1, 4, 1, 1);

        label_result_same = new QLabel(groupBox_2);
        label_result_same->setObjectName(QString::fromUtf8("label_result_same"));
        label_result_same->setFont(font1);
        label_result_same->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_result_same->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_result_same, 1, 2, 1, 1);

        label_139 = new QLabel(groupBox_2);
        label_139->setObjectName(QString::fromUtf8("label_139"));
        label_139->setFont(font3);
        label_139->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(255, 255, 0);"));
        label_139->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_139, 0, 5, 1, 1);

        label_136 = new QLabel(groupBox_2);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        label_136->setFont(font3);
        label_136->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(0, 170, 0);"));
        label_136->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_136, 0, 2, 1, 1);

        label_times_pu = new QLabel(groupBox_2);
        label_times_pu->setObjectName(QString::fromUtf8("label_times_pu"));
        label_times_pu->setFont(font1);
        label_times_pu->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_times_pu->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_times_pu, 1, 6, 1, 1);

        label_times_xue = new QLabel(groupBox_2);
        label_times_xue->setObjectName(QString::fromUtf8("label_times_xue"));
        label_times_xue->setFont(font1);
        label_times_xue->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_times_xue->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_times_xue, 1, 5, 1, 1);

        label_134 = new QLabel(groupBox_2);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setFont(font3);
        label_134->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));"));
        label_134->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_134, 0, 0, 1, 1);

        label_138 = new QLabel(groupBox_2);
        label_138->setObjectName(QString::fromUtf8("label_138"));
        label_138->setFont(font3);
        label_138->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(170, 255, 255);"));
        label_138->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_138, 0, 4, 1, 1);

        label_result_zhuang = new QLabel(groupBox_2);
        label_result_zhuang->setObjectName(QString::fromUtf8("label_result_zhuang"));
        label_result_zhuang->setFont(font1);
        label_result_zhuang->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_result_zhuang->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_result_zhuang, 1, 0, 1, 1);

        label_135 = new QLabel(groupBox_2);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        label_135->setFont(font3);
        label_135->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 41, 80, 255), stop:1 rgba(63, 80, 155, 255));color: rgb(170, 255, 255);"));
        label_135->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_135, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(170, 0, 0);"));

        horizontalLayout_2->addWidget(label);

        label_zwl_one = new QLabel(groupBox_2);
        label_zwl_one->setObjectName(QString::fromUtf8("label_zwl_one"));
        label_zwl_one->setMaximumSize(QSize(50, 16777215));
        label_zwl_one->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_zwl_one);

        label_zwl_two = new QLabel(groupBox_2);
        label_zwl_two->setObjectName(QString::fromUtf8("label_zwl_two"));
        label_zwl_two->setMaximumSize(QSize(50, 16777215));
        label_zwl_two->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_zwl_two);

        label_zwl_three = new QLabel(groupBox_2);
        label_zwl_three->setObjectName(QString::fromUtf8("label_zwl_three"));
        label_zwl_three->setMaximumSize(QSize(50, 16777215));
        label_zwl_three->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_zwl_three);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_2->addWidget(label_2);

        label_xwl_one = new QLabel(groupBox_2);
        label_xwl_one->setObjectName(QString::fromUtf8("label_xwl_one"));
        label_xwl_one->setMaximumSize(QSize(50, 16777215));
        label_xwl_one->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_xwl_one);

        label_xwl_two = new QLabel(groupBox_2);
        label_xwl_two->setObjectName(QString::fromUtf8("label_xwl_two"));
        label_xwl_two->setMaximumSize(QSize(50, 16777215));
        label_xwl_two->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_xwl_two);

        label_xwl_three = new QLabel(groupBox_2);
        label_xwl_three->setObjectName(QString::fromUtf8("label_xwl_three"));
        label_xwl_three->setMaximumSize(QSize(50, 16777215));
        label_xwl_three->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_xwl_three);

        label_up_pave = new QLabel(groupBox_2);
        label_up_pave->setObjectName(QString::fromUtf8("label_up_pave"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font4.setPointSize(25);
        label_up_pave->setFont(font4);
        label_up_pave->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 8px;"));

        horizontalLayout_2->addWidget(label_up_pave);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 1);
        horizontalLayout_2->setStretch(6, 1);
        horizontalLayout_2->setStretch(7, 1);
        horizontalLayout_2->setStretch(8, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 2);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_3->addWidget(groupBox_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);\n"
""));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        verticalLayout_4->addLayout(gridLayout_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);\n"
""));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        verticalLayout_5->addLayout(gridLayout_5);


        verticalLayout_3->addWidget(groupBox_4);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

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
        groupBox_2->setTitle(QString());
        label_143->setText(QCoreApplication::translate("MainWindow", "   \347\273\223\346\236\234", nullptr));
        pu_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
#if QT_CONFIG(shortcut)
        pu_cancel->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        label_126->setText(QCoreApplication::translate("MainWindow", "\347\231\276\345\256\266\344\271\220", nullptr));
        label_desk_id->setText(QString());
        pu_enter->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
#if QT_CONFIG(shortcut)
        pu_enter->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        label_result->setText(QString());
        label_minLimit->setText(QString());
        label_123->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\351\231\220\347\272\242", nullptr));
        label_tieMinLimit->setText(QString());
        label_pairMaxLimit->setText(QString());
        label_maxLimit->setText(QString());
        label_127->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\351\231\220\347\272\242", nullptr));
        label_122->setText(QCoreApplication::translate("MainWindow", "\345\272\204\351\227\262", nullptr));
        label_tieMaxLimit->setText(QString());
        label_128->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
        label_pairMinLimit->setText(QString());
        label_129->setText(QCoreApplication::translate("MainWindow", "\345\257\271\345\255\220", nullptr));
        label_140->setText(QCoreApplication::translate("MainWindow", "\351\223\272\346\254\241", nullptr));
        label_result_zhuangDui->setText(QString());
        label_137->setText(QCoreApplication::translate("MainWindow", "\345\272\204\345\257\271", nullptr));
        label_result_xian->setText(QString());
        label_result_xianDui->setText(QString());
        label_result_same->setText(QString());
        label_139->setText(QCoreApplication::translate("MainWindow", "\351\235\264\346\254\241", nullptr));
        label_136->setText(QCoreApplication::translate("MainWindow", "\345\222\214", nullptr));
        label_times_pu->setText(QString());
        label_times_xue->setText(QString());
        label_134->setText(QCoreApplication::translate("MainWindow", "\345\272\204", nullptr));
        label_138->setText(QCoreApplication::translate("MainWindow", "\351\227\262\345\257\271", nullptr));
        label_result_zhuang->setText(QString());
        label_135->setText(QCoreApplication::translate("MainWindow", "\351\227\262", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\272\204\351\227\256\350\267\257", nullptr));
        label_zwl_one->setText(QString());
        label_zwl_two->setText(QString());
        label_zwl_three->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\227\262\351\227\256\350\267\257", nullptr));
        label_xwl_one->setText(QString());
        label_xwl_two->setText(QString());
        label_xwl_three->setText(QString());
        label_up_pave->setText(QString());
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
