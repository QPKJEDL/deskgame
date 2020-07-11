/********************************************************************************
** Form generated from reading UI file 'MPhase.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPHASE_H
#define UI_MPHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MPhase
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *MPhase)
    {
        if (MPhase->objectName().isEmpty())
            MPhase->setObjectName(QString::fromUtf8("MPhase"));
        MPhase->resize(414, 313);
        MPhase->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 52, 91);"));
        verticalLayout = new QVBoxLayout(MPhase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(MPhase);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(200);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(MPhase);

        QMetaObject::connectSlotsByName(MPhase);
    } // setupUi

    void retranslateUi(QWidget *MPhase)
    {
        MPhase->setWindowTitle(QCoreApplication::translate("MPhase", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MPhase: public Ui_MPhase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPHASE_H
