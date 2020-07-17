#include "MRoomCard.h"
#include "ui_MRoomCard.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QNetworkReply>

void MRoomCard::init_link()
{
    SEVENMAN *node_one = new SEVENMAN;
    node_one->num = 0;
    node_one->data[0].label = ui->one_one_pic;
    node_one->data[1].label = ui->one_two_pic;
    node_one->data[2].label = ui->one_three_pic;

    SEVENMAN *node_two = new SEVENMAN;
    node_two->num = 1;
    node_two->data[0].label = ui->two_one_pic;
    node_two->data[1].label = ui->two_two_pic;
    node_two->data[2].label = ui->two_three_pic;
    node_one->next = node_two;

    SEVENMAN *node_three = new SEVENMAN;
    node_three->num = 2;
    node_three->data[0].label = ui->three_one_pic;
    node_three->data[1].label = ui->three_two_pic;
    node_three->data[2].label = ui->three_three_pic;
    node_two->next = node_three;

    SEVENMAN *node_four = new SEVENMAN;
    node_four->num = 3;
    node_four->data[0].label = ui->one_one_pic_3;
    node_four->data[1].label = ui->one_two_pic_3;
    node_four->data[2].label = ui->one_three_pic_3;
    node_three->next = node_four;

    SEVENMAN *node_five = new SEVENMAN;
    node_five->num = 4;
    node_five->data[0].label = ui->one_one_pic_4;
    node_five->data[1].label = ui->one_two_pic_4;
    node_five->data[2].label = ui->one_three_pic_4;
    node_four->next = node_five;

    SEVENMAN *node_six = new SEVENMAN;
    node_six->num = 5;
    node_six->data[0].label = ui->one_one_pic_5;
    node_six->data[1].label = ui->one_two_pic_5;
    node_six->data[2].label = ui->one_three_pic_5;
    node_five->next = node_six;

    SEVENMAN *zhuang = new SEVENMAN;
    zhuang->num = 6;
    zhuang->data[0].label = ui->zhuang_one_pic;
    zhuang->data[1].label = ui->zhuang_two_pic;
    zhuang->data[2].label = ui->zhuang_three_pic;
    node_six->next = zhuang;
    zhuang->next = node_one;

    this->link = node_one;
}

void MRoomCard::apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three, QJsonArray four, QJsonArray five, QJsonArray six)
{
    locate(location);
    bool loop = true;
    while(loop){
        QJsonArray player;
        switch (link->num) {
        case 0:{
            player = one;
            break;
        }
        case 1:{
            player = two;
            break;
        }
        case 2:{
            player = three;
            break;
        }
        case 3:{
            player = four;
            break;
        }
        case 4:{
            player = five;
            break;
        }
        case 5:{
            player = six;
            break;
        }
        case 6:{
            player = zhuang;
            break;
        }
        }
        if(NUM.num < player.count()){
            last_input = QString::fromStdString(to_string(player.at(NUM.num)["Cardnum"].toInt()));
            append(last_input.toStdString());
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

void MRoomCard::append(string c)
{
    auto toCard = [](string str)->CARD{
        string color = str.substr(0,1);
        string face = str.substr(1,2);
        CARD card;
        card.color = stoi(color);
        card.num = stoi(face) > 10 ? 10 : stoi(face);
        card.hua = stoi(face) > 10 ? true : false;
        vector<string> Cards = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        card.face = Cards[stoi(face) - 1];
        return card;
    };
    CARD card = toCard(c);
    link->data[NUM.num].hua = card.hua;
    link->data[NUM.num].num = card.num;
    link->data[NUM.num].face = card.face;
    link->data[NUM.num].color= card.color;

    auto paixingToStr = [](int paixing)->string{
        if(paixing == 0){
            return "零";
        }
        else if(paixing > 0 && paixing < 10){
            return to_string(paixing);
        }
        else{
            switch (paixing) {
            case(10):
                return "混";
                break;
            case(11):
                return "小";
                break;
            case(12):
                return "大";
                break;
            }
        }
        return "非";
    };

    link->data[NUM.num].label->setStyleSheet("image: url(:/image/pukepai/" + last_input +".png)");
    if(NUM.num == 2){
        switch (link->num) {
        case(0):
            ui->xian1_result->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(1):
            ui->xian2_result->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(2):
            ui->xian3_result->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(3):
            ui->xian1_result_2->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(4):
            ui->xian1_result_3->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(5):
            ui->xian1_result_4->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        case(6):
            ui->zhuang_result->setText(QString::fromStdString(paixingToStr(fun_paiXing(link->data).paiXing)));
            break;
        }
    }

    link = link->next;
    NUM.increase();

    if(NUM.num == 3){
        emit finished();//-> 提交

        timer_focus->stop();
        graphiceffect->setOpacity(1);
        label_name->setGraphicsEffect(graphiceffect);
        if(location % 7 == 0){
            label_name->setStyleSheet("color: rgb(255, 0, 0)");
        }
        else{
            label_name->setStyleSheet("color: rgb(255, 255, 255)");
        }
    }

    arg->lineEdit->setText(QString(""));
}

void MRoomCard::focus_lineedit()
{
    timer_focus->start(200);
}

void MRoomCard::while_timeout()
{
    qreal opacity = graphiceffect->opacity();
    if(NUM.num == 3){
        graphiceffect->setOpacity(1);
        link->data[2].label->setGraphicsEffect(graphiceffect);
        graphiceffect_name->setOpacity(1);
        label_name->setGraphicsEffect(graphiceffect_name);
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
    graphiceffect_name = new QGraphicsOpacityEffect();
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
                card.num = stoi(face) > 10 ? 10 : stoi(face);
                card.hua = stoi(face) > 10 ? true : false;
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
            QJsonArray one = data.value("IdleOneCard").toArray();
            QJsonArray two = data.value("IdleTwoCard").toArray();
            QJsonArray three = data.value("IdleThreeCard").toArray();
            QJsonArray four = data.value("IdleFourCard").toArray();
            QJsonArray five = data.value("IdleFiveCard").toArray();
            QJsonArray six = data.value("IdleSixCard").toArray();
            apply_room_card(zhuang,one,two,three,four,five,six);
        }
        else{
            emit locate_zero();
        }
        //emit get_location(location);
    }
    else{
        QMessageBox box;
        box.setText("本局三公游戏信息请求失败");
        box.exec();
    }
}

int dianShu(string str);

void MRoomCard::request_fapai(CARD card)
{
    arg->manager->setInterface(arg->interface_fapai);
    arg->manager->setStatus(arg->status_fapai);

    QJsonObject object;
    object.insert("Player",QString::number(link->num + 1 > 6 ? 0 : link->num + 1));
    object.insert("NumCard",QString::number(NUM.num + 1));
    object.insert("Color",QString::number(card.color));
    object.insert("Num",QString::number(dianShu(card.face)));
    object.insert("Cardnum",last_input);

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
        append(last_input.toStdString());
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

    switch (loca % 7) {
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
    case(4):{
        label_name = ui->label_xian1_2;
        break;
    }
    case(5):{
        label_name = ui->label_xian1_3;
        break;
    }
    case(6):{
        label_name = ui->label_xian1_4;
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

    if(NUM.num < 3){
        graphiceffect->setOpacity(1);
        link->data[NUM.num].label->setGraphicsEffect(graphiceffect);
    }
    if(location % 7 == 0){
        label_name->setStyleSheet("color: rgb(255, 0, 0)");
    }
    else{
        label_name->setStyleSheet("color: rgb(255, 255, 255)");
    }
    label_name->setGraphicsEffect(graphiceffect);

    SEVENMAN *node = link;
    do{
        for(int i = 0;i < 3;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != link);

    while (link->num != 0) {
        link = link->next;
    }

    NUM.man = 0;
    NUM.num = 0;

    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->xian1_result_2->setText(QString(""));
    ui->xian1_result_3->setText(QString(""));
    ui->xian1_result_4->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    init_link();
    emit clear_finished();
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
    if(ui)
        delete ui;
    if(arg)
        delete arg;
}

///////////////////////////////////////////////////////////////////////////////

int FiveBull(CARD player[]){
    if(player[0].face == player[1].face && player[0].face == player[2].face) {
        if(player[0].hua)
            return 12;
        else
            return 11;
    }
    if(player[0].hua && player[1].hua && player[2].hua)//五花
        return 10;
    return 0;
}

int BullCount(CARD player[]){
    int m = (player[0].num + player[1].num + player[2].num) % 10;

    return m;
}

int dianShu(string str){
    string Cards[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i = 0;i < 13;i++){
        if(Cards[i] == str){
            return i + 1;
        }
    }
    return 0;
}

void paixu(CARD player[]){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2-i;j++){
            //先判断下一个牌的值是否大于这个牌的值
            if(dianShu(player[j].face) > dianShu(player[j + 1].face)){
                CARD temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
            //如果上面的if语句执行了，则说明值不一样,那么下面这个if不会成立
            if(dianShu(player[j].face) == dianShu(player[j + 1].face) && player[j].color < player[j + 1].color){
                CARD temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }
    }
}

PAIRESULT fun_paiXing(CARD player[]){
    paixu(player);
    PAIRESULT result;
    result.biggest = player[2];
    result.huaNum = 0;
    result.paiXing = FiveBull(player);
    if(result.paiXing == 0){
        result.paiXing = BullCount(player);
    }
    for ( int i =0; i <= 2; i++ ) {
        if (player[i].hua)
            result.huaNum++;
    }
    return result;
}
