#include "mod/mod_phase/MPhase.h"
#include "ui_MPhase.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

MPhase::MPhase(MPhaseArg *arg, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MPhase)
{
    ui->setupUi(this);

    this->arg = new MPhaseArg();
    this->arg->init = arg->init;
    this->arg->leave = arg->leave;
    this->arg->start = arg->start;
    this->arg->useless = arg->useless;
    this->arg->changeBoot = arg->changeBoot;

    this->arg->locate = arg->locate;
    this->arg->location = arg->location;
    this->arg->input = arg->input;

    this->arg->status_locate = arg->status_locate;
    this->arg->manager = arg->manager;
    this->arg->interface_locate = arg->interface_locate;

    this->move(800,400);

    this->timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));

    _map.insert(arg->status_locate,&MPhase::responsed_locate);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(arg->input,SIGNAL(returnPressed()),this,SLOT(while_line_finish()));
    connect(arg->locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
}

void disabled(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(false);
    }
}

void enabled(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(true);
    }
}

void MPhase::on_timeout()
{
    ui->label->setText(QString::number(times));
    if(--times < 0){
        timer->stop();
        this->hide();
        emit timeout();
        enabled({arg->leave,arg->useless,arg->locate});
    }
}

void MPhase::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MPhase::pu_locate()
{
    arg->location->setText("");
    arg->location->setVisible(true);
    arg->locate->setEnabled(false);
    arg->input->setVisible(true);
    arg->input->setFocus();
}

void MPhase::to_phase(int phase, int start, int end, int countDown)
{
    count_down = countDown;
    switch (phase) {
    case 0:{
        enabled({arg->start,arg->changeBoot,arg->leave,arg->init});
        break;
    }
    case 1:{
        unsigned int time = end - start;
        times = count_down - time;
        timer->start(1000);
        this->setWindowFlags(Qt::FramelessWindowHint);
        this->show();
        break;
    }
    case 2:{
        enabled({arg->leave,arg->locate});
        emit phase_kaipai();
        break;
    }
    case 3:{
        enabled({arg->start,arg->changeBoot,arg->leave,arg->init});
        break;
    }
    }
}

void MPhase::on_finished()
{
    enabled({arg->start});
}

void MPhase::on_start()
{
    to_phase(1,0,0,count_down);
}

void MPhase::on_located()
{
    enabled({arg->locate});
}

void MPhase::while_line_finish()
{
    bool ok = false;
    location = arg->input->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        //提示
        arg->input->setText("");
        QMessageBox box;
        box.setText("输入的定位无效");
        box.exec();
        return;
    }

    request_locate(location);
}

void MPhase::request_locate(int location)
{
    arg->manager->setInterface(arg->interface_locate);
    arg->manager->setStatus(arg->status_locate);
    QByteArray postData;
    postData.append("location_num=");
    postData.append(QString::number(location));

    arg->manager->postData(postData);
}

void MPhase::responsed_locate(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        arg->location->setText(QString::number(location));
        arg->input->setVisible(false);
        emit located(location);
    }
    else{
        arg->locate->setEnabled(true);
        QMessageBox box;
        box.setText("牛牛定位请求失败");
        box.exec();
    }
}
