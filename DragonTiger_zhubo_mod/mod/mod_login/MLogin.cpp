#include "MLogin.h"
#include "ui_MLogin.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

MLogin::MLogin(MLoginArg *arg) :
    QWidget(nullptr),
    ui(new Ui::MLogin)
{
    ui->setupUi(this);

    this->arg = new MLoginArg();

    this->arg->userid = arg->userid;
    this->arg->passwd = arg->passwd;
    this->arg->IP = arg->IP;
    this->arg->widget = arg->widget;
    this->arg->tcpsocket = arg->tcpsocket;
    this->arg->status_first = arg->status_first;
    this->arg->manager_first = arg->manager_first;
    this->arg->status_second = arg->status_second;
    this->arg->manager_second = arg->manager_second;
    this->arg->interface_first = arg->interface_first;
    this->arg->interface_second = arg->interface_second;

    _map.insert(arg->status_first,&MLogin::responsed_first_login);
    _map.insert(arg->status_second,&MLogin::responsed_second_login);
    connect(arg->manager_first,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(arg->manager_second,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    connect(ui->enter,SIGNAL(clicked()),this,SLOT(pu_login()));
    connect(ui->cancel,SIGNAL(clicked()),this,SLOT(pu_cancel()));

    connect(arg->tcpsocket,SIGNAL(connected()),this,SLOT(connectedServer()));
    connect(arg->tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

MLogin::~MLogin()
{
    delete ui;
}

void MLogin::pu_login()
{
    request_first_login();
}

void MLogin::pu_cancel()
{
    this->close();
}

void MLogin::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void printToSend(QDataStream &stream,QString id,QString token);

void MLogin::connectedServer()
{
    qDebug() << "connected server success......";
    QString string;
    QByteArray block;

    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);

    printToSend(out,_long_id,_long_token);

    arg->tcpsocket->write(block);
}

void sendLoginMsg(QDataStream &stream,QString id);

void MLogin::readMessage()
{
    int length = 0;
    int seq = 0;
    qint8 cmd = 0;
    qint8 version = 0;
    qint8 flag = 0;
    qint8 kong = 0;

    int mark = 0;
    QString string;
    QByteArray block = arg->tcpsocket->readAll();
    QDataStream in(block);
    in.setVersion(QDataStream::Qt_5_14);
    in >> length;
    in >> seq;
    in >> cmd;
    in >> version;
    in >> flag;
    in >> kong;
    in >> mark;

    if(mark == 0){
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_14);

        sendLoginMsg(out,_long_id);

        arg->tcpsocket->write(block);

        disconnect(arg->tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
        this->close();
        arg->widget->showFullScreen();
        emit successed();
    }
    else{
        QMessageBox box;
        box.setText("长连接登录失败");
        box.exec();
    }
}

void MLogin::responsed_first_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();

        unsigned int desk_id = data.value("desk_id").toInt();
        QString desk_token = data.value("desk_token").toString();
        arg->manager_first->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
        arg->manager_first->setRawHeader("desk_token",desk_token.toUtf8());

        limit_player = json.value("minLimit").toInt();
        limit_tie = json.value("tieMinLimit").toInt();
        limit_pair = json.value("pairMinLimit").toInt();

        request_second_login();
    }
    else{
        QMessageBox box;
        box.setText("荷官登录失败");
        box.exec();
    }
}

void MLogin::responsed_second_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();

        QString id = data.value("userid").toString();
        QString token = data.value("token").toString();
        _long_id = id;
        _long_token = token;

        arg->manager_second->setRawHeader("userid",_long_id.toUtf8());
        arg->manager_second->setRawHeader("token",_long_token.toUtf8());

        arg->tcpsocket->abort();
        arg->tcpsocket->connectToHost(QHostAddress(QString(arg->IP)),23001);
    }
    else{
        QMessageBox box;
        box.setText("主播登录失败");
        box.exec();
    }
}

void MLogin::request_first_login()
{
    QByteArray postData;
    QString str = "desk=" + arg->userid + "&password=" + arg->passwd;
    postData.append(str);
    qDebug() << arg->interface_first;
    arg->manager_first->setInterface(arg->interface_first);
    arg->manager_first->setStatus(arg->status_first);

    arg->manager_first->postData(postData);
}

void MLogin::request_second_login()
{
    arg->manager_second->setInterface(arg->interface_second);
    arg->manager_second->setStatus(arg->status_second);
    QByteArray postData;
    postData.append(QString("live_user=" + ui->userid->text()));
    postData.append(QString("&password=" + ui->passwd->text()));
    arg->manager_second->postData(postData);
}

void printToSend(QDataStream &stream,QString id,QString token){
    int length = 35 + id.length();

    int seq = 1;

    qint8 cmd = 15;
    qint8 version = 1;
    qint8 flag = 0;
    qint8 kong = 0;

    qint8 temp7 = 0;

    qint8 tokenSize = (qint8)token.length();
    qint8 idSize = (qint8)id.length();

    stream << length;
    stream << seq;
    stream << cmd;

    stream << version;
    stream << flag;
    stream << kong;

    stream << temp7;
    stream << tokenSize;

    stream.writeRawData(token.toLocal8Bit().constData(),tokenSize);
    stream << idSize;
    stream.writeRawData(id.toLocal8Bit().constData(),idSize);
}

void sendLoginMsg(QDataStream &stream,QString id){
    int length        = 8;


    int seq          = 2;
    qint8 cmd        = 18;
    qint8 vervion    = 1;
    qint8 flag       = 0;
    qint8 kong       = 0;

    qint64 temp7 = id.toLong();

    stream << length;
    stream << seq;
    stream << cmd;

    stream << vervion;
    stream << flag;
    stream << kong;

    stream << temp7;
}
