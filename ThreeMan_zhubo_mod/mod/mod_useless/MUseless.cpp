#include "mod/mod_useless/MUseless.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <mod/mod_dialog/MDialog.h>

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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    MDialog dlg(m_widget);
    dlg.setWindowFlag(Qt::FramelessWindowHint);
    dlg.set_message("是否作废?");
    dlg.setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg.exec();
=======
    MDialog *dlg = new MDialog();
=======
    MDialog *dlg = new MDialog(m_widget);
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
=======
    MDialog *dlg = new MDialog(m_widget);
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否作废?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 345f219... 0716
=======
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
=======
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
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

