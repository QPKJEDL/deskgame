#include "MTopThree.h"
#include "ui_MTopThree.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MTopThree::MTopThree(MTopThreeArg *arg) :
    QWidget(nullptr),
    ui(new Ui::MTopThree)
{
    ui->setupUi(this);

    this->arg = new MTopThreeArg();
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;
    this->arg->times_xue = arg->times_xue;
    this->arg->times_pu = arg->times_pu;

    _map.insert(arg->status,&MTopThree::responsed_top_three);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

MTopThree::~MTopThree()
{
    if(ui)
        delete ui;
    if(arg)
        delete arg;
}

void MTopThree::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MTopThree::request_top_three()
{
    arg->manager->setInterface(arg->interface);
    arg->manager->setStatus(arg->status);
    QByteArray postData;
    qDebug() << arg->times_xue->text();
    postData.append("boot_num=" + arg->times_xue->text());
    postData.append("&pave_num=" + arg->times_pu->text());
    arg->manager->postData(postData);
}

void MTopThree::clear()
{
    ui->label_first_bet->setText("");
    ui->label_second_bet->setText("");
    ui->label_third_bet->setText("");

    ui->label_first_money->setText("");
    ui->label_second_money->setText("");
    ui->label_third_money->setText("");

    ui->label_first_name->setText("");
    ui->label_second_name->setText("");
    ui->label_third_name->setText("");
}

void MTopThree::responsed_top_three(QNetworkReply *reply)
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
        box.setText("获取下注前三失败");
        box.exec();
    }
}

void MTopThree::update_panel(QJsonObject data)
{
    QJsonArray topThree = data.value("top3").toArray();
    int i = topThree.count();
    int h = 0;
    auto f = [](QString bet,QLabel *label){
        QString path = ":/result/image/result/";
        if(bet == "player"){
            label->setText("<html><head/><body><p><img src=\":/bet/image/bet/player.png\"/></p></body></html>");
        }
        else if(bet == "banker"){
            label->setText("<html><head/><body><p><img src=\":/bet/image/bet/banker.png\"/></p></body></html>");
        }
        else if(bet == "tie"){
            label->setText("<html><head/><body><p><img src=\":/bet/image/bet/tie.png\"/></p></body></html>");
        }
        else if(bet == "playerPair"){
            label->setText("<html><head/><body><p><img src=\":/bet/image/bet/playerpair.png\"/></p></body></html>");
        }
        else if(bet == "bankerPair"){
            label->setText("<html><head/><body><p><img src=\":/bet/image/bet/bankerpair.png\"/></p></body></html>");
        }
    };
    auto f2 = [&](QLabel *m,QLabel *b,QLabel *n){
        QJsonObject ob = topThree.at(h).toObject();
        int money = ob.value("Money").toInt();
        QString bet = ob.value("Bet").toString();
        QString NickName = ob.value("NickName").toString();

        n->setText(NickName);
        m->setText(QString::number(money) + "元");
        f(bet,b);
    };

    if(h < i){
        f2(ui->label_first_money,ui->label_first_bet,ui->label_first_name);
        if(++h < i){
            f2(ui->label_second_money,ui->label_second_bet,ui->label_second_name);
            if(++h < i){
                f2(ui->label_third_money,ui->label_third_bet,ui->label_third_name);
            }
        }
    }
}
