#include "MChat.h"
#include "ui_MChat.h"
#include <QJsonDocument>
#include <QJsonObject>

MChat::MChat(MChatArg *arg) :
    QWidget(nullptr),
    ui(new Ui::MChat)
{
    ui->setupUi(this);
    ui->label_id->setVisible(false);

    this->arg = new MChatArg();
    this->arg->grid = arg->grid;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;
    this->arg->tcpSocket = arg->tcpSocket;

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pu_name()));
    connect(arg->tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

MChat::~MChat()
{
    delete ui;
}

void MChat::request_ban()
{
    arg->manager->setInterface(arg->interface);
    QByteArray postData;
    postData.append("talkid=" + ui->label_id->text());
    arg->manager->setStatus(arg->status);
    arg->manager->postData(postData);
}

void MChat::responsed_ban(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    QLabel *label = new QLabel();
    label->setStyleSheet("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;");
    label->setMaximumSize(100,50);
    if(status == 1){
        label->setText("禁言成功");
    }
    else{
        label->setText("禁言失败");
    }
    arg->grid->addWidget(label);
}

void MChat::pu_name()
{
    request_ban();
}

void MChat::readMessage()
{
    // 解析包的格式
    int length = 0;
    int seq = 0;

    qint8 cmd = 0;
    qint8 version = 0;
    qint8 flag = 0;
    qint8 kong = 0;

    qint64 sendid = 0;
    qint64 receiveid = 0;

    QByteArray block = arg->tcpSocket->readAll();
    QDataStream in(block);
    in.setVersion(QDataStream::Qt_5_14);
    in >> length;
    in >> seq;
    in >> cmd;
    in >> version;
    in >> flag;
    in >> kong;
    in >> sendid;
    in >> receiveid;

    int strsize = length - sizeof(qint64) * 2;

    char* p = new char[strsize];

    in.readRawData(p, strsize);

    QByteArray receivedata(p,strsize);

    delete[] p;
    qDebug() << receivedata;

    QJsonObject json = QJsonDocument::fromJson(receivedata).object();
    QString text = json.value("text").toString();
    QJsonObject user = json.value("user").toObject();
    QString username = user.value("username").toString();
    QString talkid = user.value("userid").toString();

    Ui::MChat *new_ui = new Ui::MChat();
    new_ui->setupUi(this);
    new_ui->pushButton->setText(username);
    new_ui->label->setText(text);
    new_ui->label_id->setText(talkid);
}

