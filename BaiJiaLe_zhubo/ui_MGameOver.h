/********************************************************************************
** Form generated from reading UI file 'MGameOver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MGAMEOVER_H
#define UI_MGAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MGameOver
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_desk_id;
    QLabel *label_3;
    QLabel *label_boot;
    QLabel *label_4;
    QLabel *label_pave;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_result;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pu_yes;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pu_no;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *MGameOver)
    {
        if (MGameOver->objectName().isEmpty())
            MGameOver->setObjectName(QString::fromUtf8("MGameOver"));
        MGameOver->resize(537, 282);
        MGameOver->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 39);"));
        verticalLayout = new QVBoxLayout(MGameOver);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(MGameOver);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);

        label_desk_id = new QLabel(MGameOver);
        label_desk_id->setObjectName(QString::fromUtf8("label_desk_id"));
        label_desk_id->setFont(font);
        label_desk_id->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_desk_id);

        label_3 = new QLabel(MGameOver);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        label_boot = new QLabel(MGameOver);
        label_boot->setObjectName(QString::fromUtf8("label_boot"));
        label_boot->setFont(font);
        label_boot->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_boot);

        label_4 = new QLabel(MGameOver);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_4);

        label_pave = new QLabel(MGameOver);
        label_pave->setObjectName(QString::fromUtf8("label_pave"));
        label_pave->setFont(font);
        label_pave->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(label_pave);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_result = new QLabel(MGameOver);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setMinimumSize(QSize(400, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(40);
        label_result->setFont(font1);
        label_result->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(170, 0, 0);"));
        label_result->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_result);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pu_yes = new QPushButton(MGameOver);
        pu_yes->setObjectName(QString::fromUtf8("pu_yes"));
        pu_yes->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 197, 132);"));

        horizontalLayout_4->addWidget(pu_yes);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pu_no = new QPushButton(MGameOver);
        pu_no->setObjectName(QString::fromUtf8("pu_no"));
        pu_no->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 197, 132);"));

        horizontalLayout_4->addWidget(pu_no);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(MGameOver);

        QMetaObject::connectSlotsByName(MGameOver);
    } // setupUi

    void retranslateUi(QWidget *MGameOver)
    {
        MGameOver->setWindowTitle(QCoreApplication::translate("MGameOver", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("MGameOver", "\345\217\260\346\241\214\345\217\267", nullptr));
        label_desk_id->setText(QString());
        label_3->setText(QCoreApplication::translate("MGameOver", "\351\235\264\346\254\241", nullptr));
        label_boot->setText(QString());
        label_4->setText(QCoreApplication::translate("MGameOver", "\351\223\272\346\254\241", nullptr));
        label_pave->setText(QString());
        label_result->setText(QCoreApplication::translate("MGameOver", "\345\272\204\350\265\242", nullptr));
        pu_yes->setText(QCoreApplication::translate("MGameOver", "\347\241\256\345\256\232", nullptr));
        pu_no->setText(QCoreApplication::translate("MGameOver", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MGameOver: public Ui_MGameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MGAMEOVER_H
