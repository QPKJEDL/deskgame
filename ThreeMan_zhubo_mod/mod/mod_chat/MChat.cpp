#include "MChat.h"
#include "qqchat.h"
#include "ui_MChat.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include "mod/mod_dialog/MDialog.h"

MChat::MChat(MChatArg *arg) :
    QWidget(nullptr),
    ui(new Ui::MChat)
{
    ui->setupUi(this);
    ui->label_id->setVisible(false);

    this->arg = new MChatArg();
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->inter = arg->inter;
    this->arg->tcpSocket = arg->tcpSocket;

    this->arg->desk_id = arg->desk_id;
    this->arg->manager_clear = arg->manager_clear;

    _map.insert(arg->status,&MChat::responsed_ban);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(arg->tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

MChat::~MChat()
{
    if(ui)
        delete ui;
    if(arg)
        delete arg;
}

void MChat::request_ban(QString uid)
{
    arg->manager->setInterface(arg->inter);
    QByteArray postData;
    postData.append("talkid=" + uid);
    arg->manager->setStatus(arg->status);
    arg->manager->postData(postData);
}

void MChat::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MChat::clear()
{
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否清屏?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        arg->manager_clear->setInterface("clear_room_talk");
        arg->manager->setStatus(999);
        QByteArray postData;
        postData.append("desk_id=" + QString::number(*(arg->desk_id)));
        arg->manager->postData(postData);
        emit ban_finish("清屏成功");
    }
}

void MChat::pu_name(QString userid, QString name)
{
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否禁言:\n" + name + "?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_ban(userid);
    }
}

void MChat::responsed_ban(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    unsigned int info = json.value("info").toInt();
    qDebug() << info;
    QLabel *label = new QLabel();
    label->setStyleSheet("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;");
    label->setMaximumSize(100,50);
    if(status == 1){
        emit ban_finish("禁言成功");
    }
    else{
        emit ban_finish("禁言失败");
    }
}

void cmd_equal_twenty(QDataStream *in,int length);

void MChat::readMessage()
{
    // 解析包的格式
    int length = 0;
    int seq = 0;

    qint8 cmd = 0;
    qint8 version = 0;
    qint8 flag = 0;
    qint8 kong = 0;



    QByteArray block = arg->tcpSocket->readAll();
    QDataStream in(block);
    in.setVersion(QDataStream::Qt_5_14);
    in >> length;
    in >> seq;
    in >> cmd;
    in >> version;
    in >> flag;
    in >> kong;

    if(cmd == 20){
        cmd_equal_twenty(&in,length);
    }
    else if (cmd == 4){
        cmd_equal_four(&in,length);
    }
}

void MChat::cmd_equal_twenty(QDataStream *in,int length){
    qint64 sendid = 0;
    qint64 receiveid = 0;
    *in >> sendid;
    *in >> receiveid;

    int strsize = length - sizeof(qint64) * 2;
    char* p = new char[strsize];
    in->readRawData(p,strsize);
    QByteArray receivedata(p,strsize);
    QJsonObject json = QJsonDocument::fromJson(receivedata).object();
    qDebug() << json;
    unsigned int Cmd = json.value("Cmd").toInt();
    if(Cmd == 66){
        QString account = json.value("account").toString();
        QString uid = json.value("uid").toString();
        QString msg = json.value("msg").toString();
        qDebug() << msg;
        if(msg.left(6) == "emoji_"){
            msg = "<img src = " + msg + ".png>";
        }
        qDebug() << msg.left(6);
        emit showText(msg,account,uid);
    }
    else if(Cmd == 16){
        QJsonObject data = json.value("Top3").toObject();
        emit show_top_three(data);
    }
}

void MChat::cmd_equal_four(QDataStream *in,int length){
    qint64 sendid = 0;
    qint64 receiveid = 0;
    qint32 timestamp = 0;
    qint32 msgid = 0;
    *in >> sendid;
    *in >> receiveid;
    *in >> timestamp;
    *in >> msgid;

    int strsize = length - sizeof(qint64) * 3;
    char* p = new char[strsize];
    in->readRawData(p,strsize);
    QByteArray receivedata(p,strsize);
    QJsonObject json = QJsonDocument::fromJson(receivedata).object();
    qDebug() << json;
    unsigned int Cmd = json.value("Cmd").toInt();
    if(Cmd == 14){
        QString UserAccount = json.value("UserAccount").toString();
        unsigned int money = json.value("Money").toInt();
        emit show_reword(UserAccount,money);
    }
}



