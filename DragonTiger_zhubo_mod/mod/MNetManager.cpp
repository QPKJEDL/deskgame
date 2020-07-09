#include <QNetworkReply>
#include <QDebug>
#include <QMessageBox>
#include "mod/MNetManager.h"

MNetManager::MNetManager(QObject *parent) : QObject(parent){
    _request = new QNetworkRequest;
    _manager = new QNetworkAccessManager(this);
    connect(_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
}

void MNetManager::setHeader(QString header)
{
    _request->setHeader(QNetworkRequest::ContentTypeHeader,header);
}

void MNetManager::setRawHeader(QByteArray name, QByteArray rawHeader)
{
    _request->setRawHeader(name,rawHeader);
}

void MNetManager::setIp(QString ip){
    _ip = ip;
}

void MNetManager::setStatus(int status)
{
    _status = status;
}

void MNetManager::setInterface(QString interface){
    _request->setUrl(QUrl("http://" + _ip + "/" + interface));
}

void MNetManager::postData(QByteArray data){
    _manager->post(*_request, data);
}

void MNetManager::onFinished(QNetworkReply * reply){
    if (reply->error() == QNetworkReply::NoError) {
        emit responsed(reply,_status);
    }
    else{
        qDebug() << "finishedSlot errors here";
        qDebug( "found error .... code: %d\n", (int)reply->error());
        qDebug() << reply->errorString();

        QMessageBox box;
        box.setText("网络连接错误");
        box.exec();
        return;
    }
    reply->deleteLater();
}
