#include "mod/mod_changeBoot/MChangeBoot.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "mod/mod_dialog/MDialog.h"

MChangeBoot::MChangeBoot(MChangeBootArg *arg,QWidget *parent) : QWidget(parent)
{
    this->arg = new MChangeBootArg();
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;

    _map.insert(arg->status,&MChangeBoot::responsed_changeBoot);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

MChangeBoot::~MChangeBoot()
{
    if(arg)
        delete arg;
}

void MChangeBoot::pu_changeBoot(){
    MDialog dlg;
    dlg.setWindowFlag(Qt::FramelessWindowHint);
    dlg.set_message("是否换靴?");
    dlg.setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg.exec();
    if(ret == QDialog::Accepted){
        request_changeBoot();
    }
}

void MChangeBoot::request_changeBoot()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->interface);
    arg->manager->postData(QByteArray());
}

void MChangeBoot::responsed_changeBoot(QNetworkReply *reply)
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
        emit changed();
    }
    else{
        QMessageBox box;
        box.setText("换靴失败");
        box.exec();
    }
}

void MChangeBoot::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

