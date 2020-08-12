#include "mod/mod_phase/MPhase.h"
#include "ui_MPhase.h"
#include <QMessageBox>
#include <QJsonDocument>
#include "mod/mod_dialog/MDialog.h"

MPhase::MPhase(MPhaseArg *arg, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MPhase)
{
    ui->setupUi(this);

    this->arg = new MPhaseArg();
    this->arg->tie = arg->tie;
    this->arg->init = arg->init;
    this->arg->enter = arg->enter;
    this->arg->leave = arg->leave;
    this->arg->start = arg->start;
    this->arg->banker = arg->banker;
    this->arg->cancel = arg->cancel;
    this->arg->player = arg->player;
    this->arg->useless = arg->useless;
    this->arg->changeBoot = arg->changeBoot;
    this->arg->stop = arg->stop;
    this->arg->manager = arg->manager;
    this->arg->status_stop = arg->status_stop;
    this->arg->interface_stop = arg->interface_stop;
    this->move(800,400);

    this->timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));

    _map.insert(arg->status_stop,&MPhase::responsed_stop);
    connect(arg->stop,SIGNAL(clicked()),this,SLOT(pu_stop()));
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
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
            return;
        }
        timer->stop();
        this->hide();

        emit timeout();

        enabled({arg->enter,arg->cancel,arg->leave,arg->banker,arg->player,arg->tie,arg->useless});
    }
    else{
        ui->label->setText(QString::number(times--));
        this->show();
    }
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

void MPhase::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MPhase::to_phase(int phase, int start, int end, int countDown, int wait_down)
{
    count_down = countDown;
    WaitDown = wait_down;
    switch (phase) {
    case 0:{
        enabled({arg->start,arg->changeBoot,arg->leave});
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
        enabled({arg->leave,arg->banker,arg->player,arg->tie,arg->enter,arg->cancel,arg->useless});
        emit kaipaizhong();
        break;
    }
    case 3:{
        enabled({arg->start,arg->changeBoot,arg->leave,arg->init});
        break;
    }
    }
}

void MPhase::on_started()
{
    first = true;
    arg->stop->setEnabled(true);
    arg->changeBoot->setEnabled(false);
    arg->useless->setEnabled(false);
    to_phase(1,0,0,count_down,WaitDown);
}

void MPhase::on_finished()
{
    enabled({arg->start,arg->changeBoot});
    disabled({arg->useless});
}

void MPhase::on_useless()
{
    disabled({arg->enter,arg->cancel,arg->banker,arg->player,arg->tie,arg->useless});
    enabled({arg->start});
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
