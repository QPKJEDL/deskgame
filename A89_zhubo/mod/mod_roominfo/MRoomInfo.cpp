#include "mod/mod_roominfo/MRoomInfo.h"
#include <QJsonObject>
#include "QJsonArray"
#include <QJsonDocument>
#include <QMessageBox>

MRoomInfo::MRoomInfo(MRoomInfoArg *arg, QObject *parent) : QObject(parent)
{
    this->arg = new MRoomInfoArg();
    this->arg->deskId = arg->deskId;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->inter = arg->inter;
    this->arg->timesBoot = arg->timesBoot;
    this->arg->timesPave = arg->timesPave;

    _map.insert(this->arg->status,&MRoomInfo::responsed_room_info);
    connect(this->arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

MRoomInfo::~MRoomInfo()
{
    if(arg)
        delete arg;
}

void MRoomInfo::request_room_info()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->inter);
    arg->manager->postData(QByteArray());
}

void MRoomInfo::responsed_room_info(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();

        QString DeskName = data.at(0)["DeskName"].toString();
        unsigned int BootNum = data.at(0)["BootNum"].toInt();
        unsigned int PaveNum = data.at(0)["PaveNum"].toInt();


        arg->timesBoot->setText(QString::number(BootNum));
        arg->timesPave->setText(QString::number((PaveNum)));
        arg->deskId->setText(DeskName);

        unsigned int phase = data.at(0)["Phase"].toInt();
        unsigned int starTime = data.at(0)["GameStarTime"].toInt();
        unsigned int sysTime = data.at(0)["Systime"].toInt();
        unsigned int countDown = data.at(0)["CountDown"].toInt();
        unsigned int WaitDown = data.at(0)["WaitDown"].toInt();
        emit send_phase(phase,starTime,sysTime,countDown,WaitDown);
    }
    else{
        QMessageBox box;
        box.setText("获取房间信息失败");
        box.exec();
    }
}

void MRoomInfo::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}
