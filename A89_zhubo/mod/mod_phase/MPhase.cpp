#include "mod/mod_phase/MPhase.h"
#include "ui_MPhase.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "mod/mod_dialog/MDialog.h"

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

    this->arg->changeboot = arg->changeboot;

    this->arg->locate = arg->locate;
    this->arg->location = arg->location;
    this->arg->input = arg->input;

    this->arg->status_locate = arg->status_locate;
    this->arg->manager = arg->manager;
    this->arg->interface_locate = arg->interface_locate;

    this->arg->stop = arg->stop;
    this->arg->status_stop = arg->status_stop;
    this->arg->interface_stop = arg->interface_stop;

    this->arg->opration_show = arg->opration_show;

    this->move(100,200);

    this->timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));

    _map.insert(arg->status_locate,&MPhase::responsed_locate);
    _map.insert(arg->status_stop,&MPhase::responsed_stop);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(arg->input,SIGNAL(returnPressed()),this,SLOT(while_line_finish()));
    connect(arg->locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
    connect(arg->stop,SIGNAL(clicked()),this,SLOT(pu_stop()));
}

MPhase::~MPhase()
{
    if(ui)
        delete ui;
    if(arg)
        delete arg;
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
    if(times == 0){
        if(first){
            first = false;
            times = WaitDown;
            arg->stop->setEnabled(false);
            arg->opration_show->setText("准备开牌");
            return;
        }
        timer->stop();
        this->hide();

        emit timeout();
        enabled({arg->leave,arg->useless,arg->locate});
        arg->locate->setFocus();
        arg->opration_show->setText("发牌中");
    }
    else{
        this->show();
        ui->label->setText(QString::number(times--));
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

void MPhase::pu_stop()
{
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否停止?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        arg->stop->setEnabled(false);
        request_stop();
    }
}

void MPhase::to_phase(int phase, int start, int end, int countDown,int wait_down)
{
    count_down = countDown;
    WaitDown = wait_down;
    switch (phase) {
    case 0:{
        enabled({arg->start,arg->leave,arg->init});
        break;
    }
    case 1:{
        unsigned int time = end - start;
        times = count_down - time;
        timer->start(1000);
        this->setWindowFlags(Qt::FramelessWindowHint);
        break;
    }
    case 2:{
        enabled({arg->useless});
        emit phase_kaipai();
        break;
    }
    case 3:{
        enabled({arg->start,arg->leave,arg->init});
        break;
    }
    }
}

void MPhase::on_finished(QString str)
{
    enabled({arg->start,arg->init});
    arg->start->setFocus();
    disabled({arg->locate,arg->useless});

    arg->input->setText("");
    arg->input->setVisible(false);
    enabled({arg->changeboot});
    arg->opration_show->setText("已完结");
    ui->label->setText(str);
    this->show();
}

void MPhase::on_start()
{
    to_phase(1,0,0,count_down,WaitDown);
    first = true;
    arg->stop->setEnabled(true);
    disabled({arg->changeboot});
    arg->opration_show->setText("倒计时中");
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

    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否定位到\n" + arg->input->text() + "?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_locate(location);
    }
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
        arg->input->setText("");
        emit located(location);
    }
    else{
        arg->locate->setEnabled(true);
        QMessageBox box;
        box.setText("定位请求失败");
        box.exec();
    }
}

void MPhase::request_stop()
{
    arg->manager->setInterface(arg->interface_stop);
    arg->manager->setStatus(arg->status_stop);
    arg->manager->postData(QByteArray());
}

void MPhase::responsed_stop(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        times = 0;

    }
    else{
        arg->stop->setEnabled(true);
        QMessageBox box;
        box.setText("停止失败");
        box.exec();
    }
}
