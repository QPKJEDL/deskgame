#include "MMoney.h"
#include "ui_MMoney.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>

MMoney::MMoney(MMoneyArg *arg):
    QDialog(nullptr),
    ui(new Ui::MMoney)
{
    ui->setupUi(this);

    this->arg = new MMoneyArg();
    this->arg->inter = arg->inter;
    this->arg->status = arg->status;
    this->arg->widget = arg->widget;
    this->arg->manager = arg->manager;

    button_money = new QPushButton(arg->widget);
    button_money->setMinimumSize(150,150);
    button_money->move(1400,400);
    button_money->setStyleSheet("background-color: transparent;border-image: url(:/icon/image/icon/money.png);");
    button_money->show();

    _map.insert(arg->status,&MMoney::responsed_money);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    connect(ui->pu_today,SIGNAL(clicked()),this,SLOT(pu_today()));
    connect(ui->pu_yesterday,SIGNAL(clicked()),this,SLOT(pu_yesterday()));
    connect(ui->pu_now_month,SIGNAL(clicked()),this,SLOT(pu_now_month()));
    connect(ui->pu_front_month,SIGNAL(clicked()),this,SLOT(pu_front_month()));
    connect(ui->pu_next_page,SIGNAL(clicked()),this,SLOT(pu_next_page()));
    connect(ui->pu_front_page,SIGNAL(clicked()),this,SLOT(pu_front_page()));
    connect(ui->pu_search,SIGNAL(clicked()),this,SLOT(pu_search()));
    connect(button_money,SIGNAL(clicked()),this,SLOT(pu_money()));
}

MMoney::~MMoney()
{
    delete ui;
}

void MMoney::update_panel(QJsonArray data)
{
    QJsonArray list = data.at(0)["list"].toArray();
    if(list.size() == 0){
        page--;
        return;
    }


    bool stop = false;
    auto fun = [list,&stop](int num,QLabel *creatime,QLabel *deskName,QLabel *money,QLabel *name,QLabel *type){
        QString num_creatime = list.at(num)["creatime"].toString();
        QString num_deskName = list.at(num)["deskName"].toString();
        QString account = list.at(num)["account"].toString();
        double num_money = list.at(num)["money"].toDouble();
        num_money /= 100.0;
        if(num_money == 0){
            stop = true;
        }
        if(stop){
            creatime->setText("");
            deskName->setText("");
            money->setText("");
            name->setText("");
            type->setText("");
            return;
        }
        creatime->setText(num_creatime);
        deskName->setText(num_deskName);
        money->setText(QString::number(num_money));
        name->setText(account);
        type->setText("用户打赏");
    };
    fun(0,ui->label_one_creatime,ui->label_one_deskNum,ui->label_one_money,ui->label_name_one,ui->label_type_one);
    fun(1,ui->label_two_creatime,ui->label_two_deskNum,ui->label_two_money,ui->label_name_two,ui->label_type_two);
    fun(2,ui->label_three_creatime,ui->label_three_deskNum,ui->label_three_money,ui->label_name_three,ui->label_type_three);
    fun(3,ui->label_four_creatime,ui->label_four_deskNum,ui->label_four_money,ui->label_name_four,ui->label_type_four);
    fun(4,ui->label_five_creatime,ui->label_five_deskNum,ui->label_five_money,ui->label_name_five,ui->label_type_five);
    fun(5,ui->label_six_creatime,ui->label_six_deskNum,ui->label_six_money,ui->label_name_six,ui->label_type_six);
    fun(6,ui->label_seven_creatime,ui->label_seven_deskNum,ui->label_seven_money,ui->label_name_seven,ui->label_type_seven);
}

void MMoney::clear()
{
    auto fun = [](QLabel *creatime,QLabel *deskName,QLabel *money,QLabel *name,QLabel*type){
        creatime->setText("");
        deskName->setText("");
        money->setText("");
        name->setText("");
        type->setText("");
    };
    fun(ui->label_one_creatime,ui->label_one_deskNum,ui->label_one_money,ui->label_name_one,ui->label_type_one);
    fun(ui->label_two_creatime,ui->label_two_deskNum,ui->label_two_money,ui->label_name_two,ui->label_type_two);
    fun(ui->label_three_creatime,ui->label_three_deskNum,ui->label_three_money,ui->label_name_three,ui->label_type_three);
    fun(ui->label_four_creatime,ui->label_four_deskNum,ui->label_four_money,ui->label_name_four,ui->label_type_four);
    fun(ui->label_five_creatime,ui->label_five_deskNum,ui->label_five_money,ui->label_name_five,ui->label_type_five);
    fun(ui->label_six_creatime,ui->label_six_deskNum,ui->label_six_money,ui->label_name_six,ui->label_type_six);
    fun(ui->label_seven_creatime,ui->label_seven_deskNum,ui->label_seven_money,ui->label_name_seven,ui->label_type_seven);
}

void MMoney::request_money()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->inter);
    QByteArray postData;
    postData.append("page=" + QString::number(page));
    postData.append("&type=" + QString::number(type));
    postData.append("&begin=" + ui->dateTimeEdit_begin->text());
    postData.append("&end=" + ui->dateTimeEdit_end->text());
    arg->manager->postData(postData);
}

void MMoney::responsed_money(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        if(page == 1){
            ui->pu_front_page->setEnabled(false);
        }
        else{
            ui->pu_front_page->setEnabled(true);
        }

        ui->label_45->setText(QString::number(data.at(0)["sum"].toInt() / 100));

        update_panel(data);
    }
    else{
        QMessageBox box;
        box.setText("获取打赏记录失败");
        box.exec();
    }
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

void MMoney::pu_today()
{
    clear();
    page = 1;
    type = 1;
    change_type(ui->pu_today,ui->pu_yesterday,ui->pu_now_month,ui->pu_front_month);
    request_money();
}

void MMoney::pu_yesterday()
{
    clear();
    page = 1;
    type = 2;
    change_type(ui->pu_yesterday,ui->pu_now_month,ui->pu_front_month,ui->pu_today);
    request_money();
}

void MMoney::pu_now_month()
{
    clear();
    page = 1;
    type = 3;
    change_type(ui->pu_now_month,ui->pu_front_month,ui->pu_today,ui->pu_yesterday);
    request_money();
}

void MMoney::pu_front_month()
{
    clear();
    page = 1;
    type = 4;
    change_type(ui->pu_front_month,ui->pu_today,ui->pu_yesterday,ui->pu_now_month);
    request_money();
}

void MMoney::pu_next_page()
{
    page++;
    request_money();
}

void MMoney::pu_front_page()
{
    page--;
    request_money();
}

void MMoney::pu_search()
{
    page = 1;
    type = 5;
    request_money();
}

void MMoney::pu_money()
{
    this->close();
    this->show();
    pu_today();
}

void MMoney::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

