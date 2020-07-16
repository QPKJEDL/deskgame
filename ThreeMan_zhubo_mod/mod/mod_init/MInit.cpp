#include "mod/mod_init/MInit.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include "mod/mod_dialog/MDialog.h"

MInit::MInit(MInitArg *arg, QWidget *parent) : QWidget(parent)
{
    this->arg = new MInitArg();
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->init = arg->init;
    this->arg->inter = arg->inter;

    widget = parent;

    _map.insert(arg->status,&MInit::responsed_init);
    connect(arg->init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

void MInit::pu_init()
{
    MDialog *dlg = new MDialog(widget);
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否初始化?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_init();
    }
}

void MInit::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MInit::request_init()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->inter);
    arg->manager->postData(QByteArray());
}

void MInit::responsed_init(QNetworkReply *reply)
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

        emit inited();
    }
    else{
        QMessageBox box;
        box.setText("初始化失败");
        box.exec();
    }
}

