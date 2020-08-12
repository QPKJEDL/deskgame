#include "MRoomCard.h"
#include "ui_MRoomCard.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QTimer>

void MRoomCard::init_link()
{
    FOURMAN *node_one = new FOURMAN;
    node_one->player = "ShunMen";
    node_one->data[0].label = ui->one_one_pic;
    node_one->data[1].label = ui->one_two_pic;

    FOURMAN *node_two = new FOURMAN;
    node_two->player = "TianMen";
    node_two->data[0].label = ui->two_one_pic;
    node_two->data[1].label = ui->two_two_pic;
    node_one->next = node_two;

    FOURMAN *node_three = new FOURMAN;
    node_three->player = "FanMen";
    node_three->data[0].label = ui->three_one_pic;
    node_three->data[1].label = ui->three_two_pic;
    node_two->next = node_three;

    FOURMAN *zhuang = new FOURMAN;
    zhuang->player = "Banker";
    zhuang->data[0].label = ui->zhuang_one_pic;
    zhuang->data[1].label = ui->zhuang_two_pic;
    node_three->next = zhuang;
    zhuang->next = node_one;

    this->link = node_one;
}

void MRoomCard::apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three,QString zhuang_result,QString one_result,QString two_result,QString three_result)
{
    locate(location);
    bool loop = true;
    while(loop){
        QJsonArray player;
        QString result;
        if(link->player == "ShunMen"){
            player = one;
            result = one_result;
        }
        else if(link->player == "TianMen"){
            player = two;
            result = two_result;
        }
        else if(link->player == "FanMen"){
            player = three;
            result = three_result;
        }
        else if(link->player == "Banker"){
            player = zhuang;
            result = zhuang_result;
        }
        if(NUM.num < player.count()){
            last_input = QString::number(player.at(NUM.num)["Cardnum"].toInt());
            append(last_input.toStdString(),result);
        }
        else{
            loop = false;
        }
    }
}

void MRoomCard::request_roomCard()
{
    arg->manager->setInterface(arg->interface_roomcard);
    arg->manager->setStatus(arg->status_roomcard);

    QByteArray postData;
    postData.append("boot_num=" + arg->boot->text());
    postData.append("&pave_num=" + arg->pave->text());

    arg->manager->postData(postData);
}

PAIRESULT fun_paiXing(CARD player[]);

int PaiXingToInt(QString str){
    vector<QString> vec = {"0点","1点","2点","3点","4点","5点","6点","7点","8点","9点","对2","对3","对4","对5","对6","对7","对8","对9","对10","对J","对Q","对K","对A"};
    int i = 0;
    for(auto begin = vec.begin();begin != vec.end();begin++){
        if(*begin == str){
            return i;
        }
        i++;
    }
    return -1;
}

void MRoomCard::append(string c, QString paixing)
{
    auto toCard = [](string str)->CARD{
        string color = str.substr(0,1);
        string face = str.substr(1,2);
        CARD card;
        card.color = stoi(color);
        vector<string> Cards = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        qDebug() << stoi(face);
        card.face = Cards[stoi(face) - 1];
        card.num = stoi(face) == 1 ? 14 : stoi(face);
        return card;
    };
    qDebug() << QString::fromStdString(c);
    CARD card = toCard(c);
    link->data[NUM.num].num = card.num;
    link->data[NUM.num].face = card.face;
    link->data[NUM.num].color= card.color;

    link->data[NUM.num].label->setStyleSheet("image: url(:/image/pukepai/" + last_input +".png)");

    if(paixing != ""){
        if(link->player == "ShunMen"){
            ui->xian1_result->setText(paixing);
            one_paixing = PaiXingToInt(paixing);
        }
        else if(link->player == "TianMen"){
            ui->xian2_result->setText(paixing);
            two_paixing = PaiXingToInt(paixing);
        }
        else if(link->player == "FanMen"){
            ui->xian3_result->setText(paixing);
            three_paixing = PaiXingToInt(paixing);
        }
        else if(link->player == "Banker"){
            ui->zhuang_result->setText(paixing);
            zhuang_paixing = PaiXingToInt(paixing);
        }
    }

    link = link->next;
    NUM.increase();

    if(NUM.num == 2){
        emit finished(BiJiaoPaiXing());//-> 提交

        timer_focus->stop();
        graphiceffect->setOpacity(1);
        label_name->setGraphicsEffect(graphiceffect);
        if(location % 4 == 0){
            label_name->setStyleSheet("color: rgb(255, 0, 0)");
        }
        else{
            label_name->setStyleSheet("color: rgb(255, 255, 255)");
        }
    }

    arg->lineEdit->setText(QString(""));
}

QString MRoomCard::BiJiaoPaiXing()
{
    QString r = "";
    if(zhuang_paixing < one_paixing){
        r.append("顺门");
    }
    if(zhuang_paixing < two_paixing){
        r.append("天门");
    }
    if(zhuang_paixing < three_paixing){
        r.append("反门");
    }
    if(r == ""){
        return "庄赢";
    }
    else{
        return r;
    }
}

void MRoomCard::focus_lineedit()
{
    timer_focus->start(200);
}

void MRoomCard::while_timeout()
{
    qreal opacity = graphiceffect->opacity();
    if(NUM.num == 2){
        graphiceffect->setOpacity(1);
        link->data[1].label->setGraphicsEffect(graphiceffect);
        timer_opacity->stop();
        return;
    }
    link->data[NUM.num].label->setStyleSheet("border-radius:5px;background-color: rgb(255, 0, 0)");
    if(opacity < 0.1){
        this->light = true;
    }
    else if(opacity > 0.9){
        this->light = false;
    }
    if(light){
       opacity  += 0.05;
    }
    else{
        opacity -= 0.05;
    }
    graphiceffect->setOpacity(opacity);
    link->data[NUM.num].label->setGraphicsEffect(graphiceffect);

    graphiceffect_name->setOpacity(opacity);
    label_name->setGraphicsEffect(graphiceffect_name);
}

void MRoomCard::focus()
{
    arg->lineEdit->setFocus();
}

void MRoomCard::while_input()
{
    if(NUM.num == 5){
        return;
    }
    QString str = arg->lineEdit->text();
    if(last_input != str){
        last_input = str;
        if(last_input.size() == 3){
            auto toCard = [](string str)->CARD{
                string color = str.substr(0,1);
                string face = str.substr(1,2);
                CARD card;
                card.color = stoi(color);
                card.num = stoi(face) == 1 ? 14 : stoi(face);
                vector<string> Cards = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
                card.face = Cards[stoi(face) - 1];
                return card;
            };
            request_fapai(toCard(last_input.toStdString()));
        }
    }
    arg->lineEdit->setText(QString(""));
}

void MRoomCard::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MRoomCard::responsed_roomcard(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    QJsonObject data = json.value("data").toObject();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        location = data.value("LocationNum").toString().toInt();
        if(location != 0){
            arg->location->setText(QString::number(location));
            QJsonArray zhuang = data.value("BankerCard").toArray();
            QJsonArray one = data.value("ShunCard").toArray();
            QJsonArray two = data.value("TianCard").toArray();
            QJsonArray three = data.value("FanCard").toArray();
            QString zhuang_result = data.value("Bankerresult").toString();
            QString one_result = data.value("Shunresult").toString();
            QString two_result = data.value("Tianresult").toString();
            QString three_result = data.value("Fanresult").toString();
            apply_room_card(zhuang,one,two,three,zhuang_result,one_result,two_result,three_result);
        }
        else{
            emit locate_zero();
        }
        emit get_location(location);
    }
    else{
        QMessageBox box;
        box.setText("牛牛本局游戏信息请求失败");
        box.exec();
    }
}

int dianShu(string str);

void MRoomCard::request_fapai(CARD card)
{
    arg->manager->setInterface(arg->interface_fapai);
    arg->manager->setStatus(arg->status_fapai);

    QJsonObject object;
    object.insert("NumCard",QString::number(NUM.num + 1));
    object.insert("Num",QString::number(card.num));
    object.insert("Cardnum",last_input);
    object.insert("Player",link->player);

    QByteArray postData;
    postData.append("boot_num=");postData.append(arg->boot->text());postData.append("&");
    postData.append("pave_num=");postData.append(arg->pave->text());postData.append("&");
    postData.append("Card=");postData.append(QString(QJsonDocument(object).toJson()));
    arg->manager->postData(postData);
}

void MRoomCard::responsed_fapai(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        QString result = data.value("Cardresult").toString();
        append(last_input.toStdString(),result);
    }
    else{
        last_input = "";
        QMessageBox box;
        box.setText("牛牛刷牌失败");
        box.exec();
    }
}

void MRoomCard::locate(int loca)
{
    location = loca;
    for(int i = 1;i < loca;i++){
        link = link->next;
    }

    switch (loca % 4) {
    case(0):{
        label_name = ui->label_zhuang;
        break;
    }
    case(1):{
        label_name = ui->label_xian1;
        break;
    }
    case(2):{
        label_name = ui->label_xian2;
        break;
    }
    case(3):{
        label_name = ui->label_xian3;
        break;
    }
    }
    label_name->setStyleSheet("color: rgb(200, 140, 0)");
    timer_opacity->start(10);

    focus_lineedit();
}

void MRoomCard::clear()
{
    timer_focus->stop();
    timer_opacity->stop();

    if(NUM.num < 2){
        graphiceffect->setOpacity(1);
        link->data[NUM.num].label->setGraphicsEffect(graphiceffect);
    }
    if(location % 4 == 0){
        label_name->setStyleSheet("color: rgb(255, 0, 0)");
    }
    else{
        label_name->setStyleSheet("color: rgb(255, 255, 255)");
    }
    label_name->setGraphicsEffect(graphiceffect);

    FOURMAN *node = link;
    do{
        for(int i = 0;i < 2;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != link);

    NUM.man = 0;
    NUM.num = 0;

    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    init_link();
}

MRoomCard::MRoomCard(MRoomCardArg *arg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MRoomCard)
{
    ui->setupUi(this);

    this->arg = new MRoomCardArg();
    this->arg->boot = arg->boot;
    this->arg->pave = arg->pave;
    this->arg->locate = arg->locate;
    this->arg->status_roomcard = arg->status_roomcard;
    this->arg->manager = arg->manager;
    this->arg->lineEdit = arg->lineEdit;
    this->arg->location = arg->location;
    this->arg->interface_roomcard = arg->interface_roomcard;
    this->arg->status_fapai = arg->status_fapai;
    this->arg->interface_fapai = arg->interface_fapai;

    timer_opacity = new QTimer(this);
    timer_focus = new QTimer(this);

    graphiceffect = new QGraphicsOpacityEffect();
    graphiceffect_name = new QGraphicsOpacityEffect();
    timer_focus = new QTimer(this);
    timer_opacity = new QTimer(this);
    label_name = new QLabel();


    init_link();

    connect(timer_opacity,SIGNAL(timeout()),this,SLOT(while_timeout()));
    connect(timer_focus, SIGNAL(timeout()), this, SLOT(focus()));
    connect(arg->lineEdit,SIGNAL(returnPressed()),this,SLOT(while_input()));

    _map.insert(arg->status_fapai,&MRoomCard::responsed_fapai);
    _map.insert(arg->status_roomcard,&MRoomCard::responsed_roomcard);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

MRoomCard::~MRoomCard()
{
    delete ui;
}
