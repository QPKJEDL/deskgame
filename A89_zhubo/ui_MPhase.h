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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MPhase
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *MPhase)
    {
        if (MPhase->objectName().isEmpty())
            MPhase->setObjectName(QString::fromUtf8("MPhase"));
        MPhase->resize(427, 291);
        MPhase->setMinimumSize(QSize(427, 291));
        MPhase->setMaximumSize(QSize(427, 291));
        MPhase->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        verticalLayout = new QVBoxLayout(MPhase);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MPhase);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 200));
        label->setMaximumSize(QSize(438, 287));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(200);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);


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
