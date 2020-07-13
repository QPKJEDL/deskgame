#include "mod/mod_useless/MUseless.h"
#include "mod/mod_dialog/MDialog.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MUseless::MUseless(MUselessArg *arg, QWidget *parent) : QWidget(parent)
{
    this->arg = new MUselessArg();
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->useless = arg->useless;
    this->arg->interface = arg->interface;

    _map.insert(arg->status,&MUseless::responsed_useless);
    connect(arg->useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

void MUseless::pu_useless()
{
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否作废?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_useless();
    }
}

void MUseless::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MUseless::request_useless()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->interface);
    QByteArray postData;
    postData.append(QString("boot_num=") + arg->boot->text());
    postData.append((QString("&pave_num=")) + arg->pave->text());
    arg->manager->postData(postData);
    arg->useless->setEnabled(false);
}

void MUseless::responsed_useless(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        emit uselessed();
    }
    else{
        arg->useless->setEnabled(true);

        QMessageBox box;
        box.setText("作废失败");
        box.exec();
    }
}

