#include "ui_MGameOver.h"

#include <mod/mod_gameover/MGameOver.h>
#include <stdarg.h>
#include <initializer_list>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>

MGameOver::MGameOver(MGameOverArg *arg, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MGameOver)
{
    ui->setupUi(this);

    this->arg = new MGameOverArg();
    this->arg->tie = arg->tie;
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;
    this->arg->enter = arg->enter;
    this->arg->banker = arg->banker;
    this->arg->cancel = arg->cancel;
    this->arg->player = arg->player;
    this->arg->result = arg->result;
    this->arg->status = arg->status;
    this->arg->desk_id = arg->desk_id;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;

    _map.insert(this->arg->status,&MGameOver::responsed_gameover);
    connect(this->arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    connect(arg->tie,SIGNAL(clicked()),this,SLOT(pu_tie()));
    connect(arg->enter,SIGNAL(clicked()),this,SLOT(pu_enter()));
    connect(arg->banker,SIGNAL(clicked()),this,SLOT(pu_banker()));
    connect(arg->cancel,SIGNAL(clicked()),this,SLOT(clear()));
    connect(arg->player,SIGNAL(clicked()),this,SLOT(pu_player()));
    connect(ui->pu_yes,SIGNAL(clicked()),this,SLOT(pu_yes()));
    connect(ui->pu_no,SIGNAL(clicked()),this,SLOT(pu_no()));
}

void disable(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(false);
    }
}

void enable(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(true);
    }
}

void MGameOver::pu_banker()
{
    score_game = 7;
    arg->result->setText(arg->result->text().append("庄赢"));
    disable({arg->banker,arg->player,arg->tie});
    enable({arg->enter,arg->cancel});
}

void MGameOver::pu_player()
{
    score_game = 4;
    arg->result->setText(arg->result->text().append("闲赢"));
    disable({arg->banker,arg->player,arg->tie});
    enable({arg->enter,arg->cancel});
}

void MGameOver::pu_tie(){
    score_game = 1;
    arg->result->setText(arg->result->text().append("和"));
    disable({arg->banker,arg->player,arg->tie});
    enable({arg->enter,arg->cancel});
}

void MGameOver::pu_enter()
{
    disable({arg->enter,arg->cancel});

    ui->label_desk_id->setText(arg->desk_id->text());
    ui->label_boot->setText(arg->boot->text());
    ui->label_pave->setText(arg->pave->text());
    ui->label_result->setText(arg->result->text());
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
}

void MGameOver::clear()
{
    score_game = 0;
    score_playerPair = 0;
    score_bankerPair = 0;
    arg->result->setText("");

    enable({arg->banker,arg->player,arg->tie,arg->enter});
}

void MGameOver::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MGameOver::pu_yes()
{
    request_gameover();
}

void MGameOver::pu_no()
{
    enable({arg->enter,arg->cancel});
    this->hide();
}

void MGameOver::request_gameover()
{
    if(score_game == -1){
        QMessageBox box;
        box.setText("结果无效");
        box.exec();
    }
    else{
        arg->manager->setStatus(arg->status);
        arg->manager->setInterface(arg->interface);
        QByteArray postData;
        postData.append("boot_num=" + arg->boot->text());
        postData.append("&pave_num=" + arg->pave->text());
        QJsonObject json;
        json.insert("game",score_game);
        json.insert("playerPair",score_playerPair);
        json.insert("bankerPair",score_bankerPair);
        postData.append(QString("&game_num=" + QString(QJsonDocument(json).toJson())));
        qDebug() << postData;
        arg->manager->postData(postData);
    }
}

void MGameOver::responsed_gameover(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        auto f = [](int score)->QString{
            switch (score) {
            case 7:{
                return "龙";
            }
            case 4:{
                return "虎";
            }
            case 1:{
                return "和";
            }
            }
            return "";
        };

        emit gameOver(f(score_game));
        disable({arg->enter,arg->cancel,arg->banker,arg->player,arg->tie});
        arg->result->setText("");
        this->hide();
    }
    else{
        enable({arg->enter,arg->cancel});
        QMessageBox box;
        box.setText("结算失败");
        box.exec();
    }
}
