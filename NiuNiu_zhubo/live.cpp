#include "live.h"
#include "ui_live.h"
#include <QJsonArray>
#include <QDebug>

Live::Live(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Live)
{
    ui->setupUi(this);

    connect(ui->pu_today,SIGNAL(clicked()),this,SLOT(pu_today()));
    connect(ui->pu_yesterday,SIGNAL(clicked()),this,SLOT(pu_yesterday()));
    connect(ui->pu_now_month,SIGNAL(clicked()),this,SLOT(pu_now_month()));
    connect(ui->pu_front_month,SIGNAL(clicked()),this,SLOT(pu_front_month()));
    connect(ui->pu_next_page,SIGNAL(clicked()),this,SLOT(pu_next_page()));
    connect(ui->pu_front_page,SIGNAL(clicked()),this,SLOT(pu_front_page()));
    connect(ui->pu_search,SIGNAL(clicked()),this,SLOT(pu_search()));
}

Live::~Live()
{
    delete ui;
}

void Live::update_panel(QJsonArray data)
{
    QJsonArray list = data.at(0)["list"].toArray();

    auto fun = [list](int num,QLabel *creatime,QLabel *deskName,QLabel *money){
        QString num_creatime = list.at(num)["creatime"].toString();
        QString num_deskName = list.at(num)["deskName"].toString();
        unsigned int num_money = list.at(num)["money"].toInt();

        creatime->setText(num_creatime);
        deskName->setText(num_deskName);
        money->setText(QString::number(num_money));
    };
    first_id = list.at(6)["id"].toInt();
    second_id = list.at(0)["id"].toInt();
    fun(0,ui->label_one_creatime,ui->label_one_deskNum,ui->label_one_money);
    fun(1,ui->label_two_creatime,ui->label_two_deskNum,ui->label_two_money);
    fun(2,ui->label_three_creatime,ui->label_three_deskNum,ui->label_three_money);
    fun(3,ui->label_four_creatime,ui->label_four_deskNum,ui->label_four_money);
    fun(4,ui->label_five_creatime,ui->label_five_deskNum,ui->label_five_money);
    fun(5,ui->label_six_creatime,ui->label_six_deskNum,ui->label_six_money);
    fun(6,ui->label_seven_creatime,ui->label_seven_deskNum,ui->label_seven_money);
}

QString Live::get_time_begin()
{
    QString str = ui->dateTimeEdit_begin->text();
    return str;
}

QString Live::get_time_end()
{
    QString str = ui->dateTimeEdit_end->text();
    return str;
}

void change_type(QPushButton* now,QPushButton *one,QPushButton *two,QPushButton *three){
    now->setStyleSheet("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(163, 129, 98, 255), stop:0.431818 rgba(252, 237, 203, 255), stop:0.590909 rgba(252, 237, 203, 255), stop:1 rgba(163, 129, 98, 255));\
                       border-radius: 8px; \
                       color: rgb(121, 61, 3);");
    QString styleSheet = "background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(35, 34, 51, 255), stop:0.4375 rgba(92, 107, 148, 255), stop:0.568182 rgba(92, 107, 148, 255), stop:0.971591 rgba(35, 34, 51, 255), stop:1 rgba(35, 34, 51, 255)); \
            border-radius: 8px; \
            color: rgb(255, 255, 255);";

    one->setStyleSheet(styleSheet);
    two->setStyleSheet(styleSheet);
    three->setStyleSheet(styleSheet);
}

void Live::pu_today()
{
    lastid = 0;
    type = 1;
    change_type(ui->pu_today,ui->pu_yesterday,ui->pu_now_month,ui->pu_front_month);
    emit request_money_list();
}

void Live::pu_yesterday()
{
    lastid = 0;
    type = 2;
    change_type(ui->pu_yesterday,ui->pu_now_month,ui->pu_front_month,ui->pu_today);
    emit request_money_list();
}

void Live::pu_now_month()
{
    lastid = 0;
    type = 3;
    change_type(ui->pu_now_month,ui->pu_front_month,ui->pu_today,ui->pu_yesterday);
    emit request_money_list();
}

void Live::pu_front_month()
{
    lastid = 0;
    type = 4;
    change_type(ui->pu_front_month,ui->pu_today,ui->pu_yesterday,ui->pu_now_month);
    emit request_money_list();
}

void Live::pu_next_page()
{
    lastid = second_id;
    emit request_money_list();
}

void Live::pu_front_page()
{
    lastid = first_id + 8;
    emit request_money_list();
}

void Live::pu_search()
{
    lastid = 0;
    type = 5;
    emit request_money_list();
}




