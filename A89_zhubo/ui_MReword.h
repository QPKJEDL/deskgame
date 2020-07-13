/********************************************************************************
** Form generated from reading UI file 'MReword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MREWORD_H
#define UI_MREWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MReword
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *money;
    QLabel *label_2;

    void setupUi(QWidget *MReword)
    {
        if (MReword->objectName().isEmpty())
            MReword->setObjectName(QString::fromUtf8("MReword"));
        MReword->resize(676, 470);
        MReword->setMinimumSize(QSize(676, 470));
        MReword->setMaximumSize(QSize(676, 470));
        MReword->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label = new QLabel(MReword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(20, 10, 611, 441));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/image/icon/reword.png);"));
        layoutWidget = new QWidget(MReword);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 80, 171, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        user = new QLabel(layoutWidget);
        user->setObjectName(QString::fromUtf8("user"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        user->setFont(font);
        user->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);"));
        user->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(user);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        layoutWidget1 = new QWidget(MReword);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 140, 131, 104));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        money = new QLabel(layoutWidget1);
        money->setObjectName(QString::fromUtf8("money"));
        QFont font1;
        font1.setPointSize(50);
        money->setFont(font1);
        money->setStyleSheet(QString::fromUtf8("color: rgb(250, 57, 57);"));
        money->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(money);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(250, 57, 57);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        retranslateUi(MReword);

        QMetaObject::connectSlotsByName(MReword);
    } // setupUi

    void retranslateUi(QWidget *MReword)
    {
        MReword->setWindowTitle(QCoreApplication::translate("MReword", "Form", nullptr));
        label->setText(QString());
        user->setText(QString());
        label_3->setText(QCoreApplication::translate("MReword", "\350\265\217\351\207\221", nullptr));
        money->setText(QString());
        label_2->setText(QCoreApplication::translate("MReword", "\345\205\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MReword: public Ui_MReword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MREWORD_H
