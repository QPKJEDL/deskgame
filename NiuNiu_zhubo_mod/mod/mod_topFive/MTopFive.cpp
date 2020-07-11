#include "MTopFive.h"
#include "ui_MTopFive.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MTopFive::MTopFive(MTopFiveArg *arg) :
    QWidget(nullptr),
    ui(new Ui::MTopFive)
{
    ui->setupUi(this);

    this->arg = new MTopFiveArg();
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;
    this->arg->times_xue = arg->times_xue;
    this->arg->times_pu = arg->times_pu;

    _map.insert(arg->status,&MTopFive::responsed_top_five);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

MTopFive::~MTopFive()
{
    delete ui;
}

void MTopFive::request_top_five()
{
    arg->manager->setInterface(arg->interface);
    arg->manager->setStatus(arg->status);
    QByteArray postData;
    qDebug() << arg->times_xue->text();
    postData.append("boot_num=" + arg->times_xue->text());
    arg->manager->postData(postData);
}

void MTopFive::clear()
{
    ui->label_bingo_one->setText("");
    ui->label_bingo_two->setText("");
    ui->label_bingo_three->setText("");
    ui->label_bingo_four->setText("");
    ui->label_bingo_five->setText("");

    ui->label_first_num->setText("");
    ui->label_second_num->setText("");
    ui->label_third_num->setText("");
    ui->label_fourth_num->setText("");
    ui->label_fifth_num->setText("");
}

void MTopFive::responsed_top_five(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        update_panel(data);
    }
    else{
        QMessageBox box;
        box.setText("获取连续中铺记录失败");
        box.exec();
    }
}

void MTopFive::update_panel(QJsonObject data)
{
    QJsonArray topFive = data.value("top5").toArray();
    int i = topFive.count();
    int h = 0;
    auto f = [&](QLabel *n,QLabel *a){
        QJsonObject ob = topFive.at(h).toObject();
        QString NickName = ob.value("NickName").toString();
        double num = ob.value("Num").toInt();
        if(num != 0){
            n->setText(QString::number(num));
            a->setText(NickName);
        }
    };

    if(h < i){
        f(ui->label_first_num,ui->label_bingo_one);
        if(++h < i){
            f(ui->label_second_num,ui->label_bingo_two);
            if(++h < i){
                f(ui->label_third_num,ui->label_bingo_three);
                if(++h < i){
                    f(ui->label_fourth_num,ui->label_bingo_four);
                    if(++h < i){
                        f(ui->label_fifth_num,ui->label_bingo_five);
                    }
                }
            }
        }
    }
}

void MTopFive::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

