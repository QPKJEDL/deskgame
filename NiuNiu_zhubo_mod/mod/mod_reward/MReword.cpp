#include "MReword.h"
#include "ui_MReword.h"

MReword::MReword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MReword)
{
    ui->setupUi(this);
    this->move(600,300);
    this->hide();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_close()));
}

MReword::~MReword()
{
    delete ui;
}

void MReword::show_reword(QString user, int money)
{
    ui->money->setText(QString::number(money));
    ui->user->setText(user);
    this->show();
    timer->start(3000);
}

void MReword::timer_close()
{
    this->hide();
    timer->stop();
}
