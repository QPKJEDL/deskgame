#include "MSummit.h"
#include "ui_MSummit.h"
#include "QMessageBox"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "mod/mod_dialog/MDialog.h"

MSummit::MSummit(MSummitArg *arg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MSummit)
{
    ui->setupUi(this);

    this->arg = new MSummitArg;
    this->arg->button = arg->button;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;
    this->arg->status = arg->status;
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;

    connect(arg->button,SIGNAL(clicked()),this,SLOT(pu_summit()));
    _map.insert(arg->status,&MSummit::responsed_summit);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    connect(ui->yes,SIGNAL(clicked()),this,SLOT(pu_yes()));
    connect(ui->no,SIGNAL(clicked()),this,SLOT(pu_no()));
}

MSummit::~MSummit()
{
    delete ui;
}

void MSummit::request_summit()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->interface);
    QByteArray postData;
    postData.append("boot_num=");postData.append(arg->boot->text());
    postData.append("&pave_num=");postData.append(arg->pave->text());
    arg->manager->postData(postData);
}

void MSummit::responsed_summit(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        emit summited();
    }
    else{
        arg->button->setEnabled(true);
        QMessageBox box;
        box.setText("提交请求失败");
        box.exec();
    }
}

void MSummit::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MSummit::pu_summit()
{
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否提交?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_summit();
    }
}

void MSummit::cardFinished()
{
    arg->button->setEnabled(true);
}
