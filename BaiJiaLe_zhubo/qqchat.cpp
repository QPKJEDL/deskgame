#include "qqchat.h"
#include "ui_qqchat.h"

QQChat::QQChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQChat)
{
    ui->setupUi(this);

    this->setMinimumSize(480,140);
}

QQChat::~QQChat()
{
    delete ui;
}

void QQChat::update_input(QString str)
{
    ui->label->setText(str);
}

void QQChat::update_name(QString str)
{
    ui->pushButton->setText(str);
}
