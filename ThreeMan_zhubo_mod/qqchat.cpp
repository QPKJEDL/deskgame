#include <QMessageBox>
#include "qqchat.h"
#include "ui_qqchat.h"

QQChat::QQChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQChat)
{
    ui->setupUi(this);

    this->setMinimumSize(480,140);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pu_name()));
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

void QQChat::pu_name()
{
    int choose = QMessageBox::question(this,QString("禁言"),QString("确认禁言？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        emit banUser(talkid);
    }
}
