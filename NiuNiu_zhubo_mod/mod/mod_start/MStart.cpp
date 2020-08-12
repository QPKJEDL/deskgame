#include "mod/mod_start/MStart.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

MStart::MStart(MStartArg *arg,QObject *parent) : QObject(parent)
{
    this->arg = new MStartArg;
    this->arg->button = arg->button;
    this->arg->manager = arg->manager;
    this->arg->inter = arg->inter;
    this->arg->status = arg->status;
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;

    connect(arg->button,SIGNAL(clicked()),this,SLOT(pu_start()));
    _map.insert(arg->status,&MStart::responsed_start);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

void MStart::request_start()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->inter);
    arg->manager->postData(QByteArray());
}

void MStart::responsed_start(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();

        arg->boot->setText(QString::number(boot_num));
        arg->pave->setText(QString::number(pave_num));

        emit successed();
    }
    else{
        arg->button->setEnabled(true);

        QMessageBox box;
        box.setText("开局失败");
        box.exec();
    }
}

void MStart::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MStart::pu_start()
{
    arg->button->setEnabled(false);
    request_start();
}
