#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QByteArray>
#include <QGraphicsOpacityEffect>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <vector>
#include <QMessageBox>
// 账号 a19
using namespace std;
//QString URL = "129.211.114.135:8210";

enum {START,ROOMINFO,RECORD,ROOMCARD,LOCATE,FAPAI,SUMMIT,USELESS,INIT,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_edit_last("")
    , m_fapai(false)
{
    ui->setupUi(this);
    // 输入牌型用的 lineedit
    ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    // 初始化 焦点 不断更新到 lineedit
    timer_focus = new QTimer(this);
    connect(timer_focus, SIGNAL(timeout()), this, SLOT(update()));
    // 设置焦点到 定位按钮
    ui->button_locate->setFocus();
    // 初始化限红

    // 初始化透明度相关
    timer_opacity = new QTimer(this);
    timer_date = new QTimer(this);
    m_graphiceffect = new QGraphicsOpacityEffect;
    m_light = false;
    n_graphiceffect = new QGraphicsOpacityEffect;
    connect(timer_date,SIGNAL(timeout()),this,SLOT(update_date()));
    timer_date->start(200);

    connect(timer_opacity, SIGNAL(timeout()), this, SLOT(on_timeout()));
    connect(ui->button_locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
    connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(line_finish()));
    connect(ui->button_summit,SIGNAL(clicked()),this,SLOT(Request_summit()));
    connect(ui->pu_exit,SIGNAL(clicked()),this,SLOT(on_exit()));
    connect(ui->button_useless,SIGNAL(clicked()),this,SLOT(Request_useless()));
    //connect(ui->pu_end,SIGNAL(clicked()),this,SLOT(pu_end()));

    // 开始按钮
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(Request_start()));
    // 倒计时计数器
    timer_Countdown = new QTimer(this);
    connect(timer_Countdown,SIGNAL(timeout()),this,SLOT(on_count_down()));

    // 初始化按钮
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(Request_initialize()));

    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(ROOMCARD,&MainWindow::responsed_roomcard);
    _map.insert(LOCATE,&MainWindow::responsed_locate);
    _map.insert(FAPAI,&MainWindow::responsed_fapai);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);

    _map.insert(LOGIN);
    _map_insert(SECONDLOGIN);

    manager = new MNetManager;
    manager->setIp("129.211.114.135:8210");
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

   request_game_record();

  //M
  //闲家一
  head = new players;
  head->num = 0;
  head->data[0].label = ui->one_one_pic;
  head->data[1].label = ui->one_two_pic;
  head->data[2].label = ui->one_three_pic;
  //闲家二
  players *er = new players;
  er->num = 1;
  er->data[0].label = ui->two_one_pic;
  er->data[1].label = ui->two_two_pic;
  er->data[2].label = ui->two_three_pic;
  head->next = er;
  //闲家三
  players *san = new players;
  san->num = 2;
  san->data[0].label = ui->three_one_pic;
  san->data[1].label = ui->three_two_pic;
  san->data[2].label = ui->three_three_pic;
  er->next = san;
  // 闲家4
  players *si = new players;
  si->num = 3;
  si->data[0].label = ui->one_one_pic_3;
  si->data[1].label = ui->one_two_pic_3;
  si->data[2].label = ui->one_three_pic_3;
  san->next = si;
  // 闲家5
  players *wu = new players;
  wu->num = 4;
  wu->data[0].label = ui->one_one_pic_4;
  wu->data[1].label = ui->one_two_pic_4;
  wu->data[2].label = ui->one_three_pic_4;
  si->next = wu;
  // 闲家6
  players *liu = new players;
  liu->num = 5;
  liu->data[0].label = ui->one_one_pic_5;
  liu->data[1].label = ui->one_two_pic_5;
  liu->data[2].label = ui->one_three_pic_5;
  wu->next = liu;
  //庄家
  players *zhuang = new players;
  zhuang->num = 6;
  zhuang->data[0].label = ui->zhuang_one_pic;
  zhuang->data[1].label = ui->zhuang_two_pic;
  zhuang->data[2].label = ui->zhuang_three_pic;
  liu->next = zhuang;
  zhuang->next = head;
  //M
  //初始化结果列表，80 个QLabel
}

//判断是否是大三公12，小三公11，混三公10
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

//牛几 ,10 为 牛 10
int BullCount(CARD player[]){
    int m = (player[0].num + player[1].num + player[2].num) % 10;

    return m;
}

//该函数的作用是将 face 转换成 点数
int dianShu(string str){
    string Cards[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i = 0;i < 13;i++){
        if(Cards[i] == str){
            return i + 1;
        }
    }
    return 0;
}

//按理说排序以后就不必寻找最大点数的牌了，因为player[4]
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

PAIRESULT PaiXing(CARD player[]){
    paixu(player);
    PAIRESULT r;
    r.biggest = player[2];//由于paixu() 函数已经将最大的牌放到最后一个了，所以直接获取就行
    r.huaNum = 0;
    qDebug() << "biggest : " << r.biggest.color << " - " << QString::fromStdString(r.biggest.face);
    r.paiXing = FiveBull(player);
    if(r.paiXing == 0){
        r.paiXing = BullCount(player);
    }

    for ( int i =0; i <= 2; i++ ) {
        if (player[i].hua)
            r.huaNum++;
    }
    return r;
}

//void MainWindow::locate(){
//    // 定位到定位到的玩家
//    for(int j = 2;j <= location;j++){
//      head = head->next;
//    }
//}

string PaiXingToStr(int paixing){
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
}

void MainWindow::Request_faPai(CARD card){
    manager->setInterface("SgGameCard");

    QJsonObject json_object;
    QJsonObject json_object2;
    json_object2.insert("Player",QString::number(head->num + 1 > 6 ? 0 : head->num + 1));
    json_object2.insert("NumCard",QString::number(number.num + 1));//CardPosition
    json_object2.insert("Color",QString::number(card.color));//hua se
    json_object2.insert("Num",QString::number(dianShu(card.face)));//点数
    json_object2.insert("Cardnum",m_edit_last);//CardAllNum

    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());postData.append("&");
    postData.append("pave_num=");postData.append(ui->pu_times->text());postData.append("&");
    postData.append("Card=");postData.append(QString(QJsonDocument(json_object2).toJson()));
    manager->postData(postData);
    m_fapai = false;
}

void MainWindow::wait(CARD card){
    // 将 card 保存到当前玩家的缓存中
    head->data[number.num].hua = card.hua;
    head->data[number.num].num = card.num;
    head->data[number.num].face = card.face;
    head->data[number.num].color = card.color;
    // 显示牌的图片
    head->data[number.num].label->setStyleSheet("image: url(:/image/pukepai/" + m_edit_last +".png)");

    if(number.num == 2){
        // 如果是第三张牌，则显示牌型
        switch (head->num) {
        case(0):
            ui->xian1_result->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(1):
            ui->xian2_result->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(2):
            ui->xian3_result->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(3):
            ui->xian1_result_2->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(4):
            ui->xian1_result_3->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(5):
            ui->xian1_result_4->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        case(6):
            ui->zhuang_result->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        }
    }

    // 前进到下一个玩家
    head = head->next;
    number.increase();

    // 如果所有牌都发完了
    if(number.num == 3){
        // 启用提交按钮
        ui->button_summit->setEnabled(true);
        ui->button_summit->setFocus();

        // 不再焦点到扫码机
        timer_focus->stop();
        n_graphiceffect->setOpacity(1);
        label_name->setGraphicsEffect(n_graphiceffect);

        // 恢复定位到的玩家的身份的颜色，庄家为红，闲家为白
        if(location % 4 == 0){
            label_name->setStyleSheet("color: rgb(255, 0, 0)");
        }
        else{
            label_name->setStyleSheet("color: rgb(255, 255, 255)");
        }
    }

    // 将扫码机设置为空字符串，等待下一张牌
    ui->lineEdit->setText(QString(""));
}

MainWindow::~MainWindow()
{


    delete ui;
}

string intToFace(int str){
    vector<string> Cards = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    return Cards[str - 1];
}

CARD strToCard(string str){
    string color = str.substr(0,1);
    string face = str.substr(1,2);
    CARD card;
    card.color = stoi(color);
    card.num = stoi(face) > 10 ? 10 : stoi(face);
    card.hua = stoi(face) > 10 ? true : false;
    card.face = intToFace(stoi(face));
    return card;
}

void MainWindow::keyPressEvent(QKeyEvent *keyValue)
{
    if(keyValue->key() == 16777220)//enter
    {
       QString str = ui->lineEdit->text();
       if (m_edit_last != str) {
            //发送数据
           m_edit_last = str;

           if(number.num == 3){
               return;
           }
           if((m_edit_last.size() == 3) && m_fapai){
               manager->setStatus(FAPAI);
               //M 先发送发牌请求，如果收到成功回复再显示，如果失败，系统自动重新发送
               qDebug() << "m_edit_last" << m_edit_last;
               Request_faPai(strToCard(m_edit_last.toStdString()));
           }
       }
       //M
       ui->lineEdit->setText(QString(""));
    }
}

// 若前者大，则返回true，否则返回false
bool Bigger(PAIRESULT player_1,PAIRESULT player_2){
    if(player_1.paiXing > player_2.paiXing){
        return true;
    }
    if(player_1.paiXing == player_2.paiXing){
        if (player_1.huaNum > player_2.huaNum)
            return true;

        if (player_1.huaNum == player_2.huaNum) {
            if(dianShu(player_1.biggest.face) > dianShu(player_2.biggest.face))
                return true;

            if(dianShu(player_1.biggest.face) == dianShu(player_2.biggest.face)){
                return player_1.biggest.color < player_2.biggest.color ? true : false;
            }
            return false;
        }
        return false;
    }
    return false;
}

QString PaixingToResult(int i){
    if(i <= 0){
        return "N";
    }
    if(i == 10){
        return "B";
    }
    if(i > 0){
        return QString::fromStdString(to_string(i));
    }

    return QString("");
}

void MainWindow::result(){
    PAIRESULT zhuang;
    PAIRESULT vec[6] = {};
    QString result = "";

    for(int i = 0;i < 7;i++){
        PAIRESULT result = PaiXing(head->data);
        if(head->num == 6){
            zhuang = result;
        }
        else{
            vec[head->num] = result;
            qDebug() << "head->num : " << head->num;
        }
        head = head->next;
    }

    //所有牌型收集完毕，开始比较

    for(int i = 0;i < 6;i++){
        if(!Bigger(zhuang,vec[i])){
            switch (i) {
            case(0):{
                //闲家1 赢
                result += "闲1 ";
                int j = stoi(ui->one_win_times->text().toStdString());
                ui->one_win_times->setText(QString::fromStdString(to_string(j+1)));

                break;
            }
            case(1):{
                //闲家2 赢
                result += "闲2 ";
                int j = stoi(ui->two_win_times->text().toStdString());
                ui->two_win_times->setText(QString::fromStdString(to_string(j+1)));

                break;
            }
            case(2):{
                //闲家3 赢
                result += "闲3 ";
                int j = stoi(ui->three_win_times->text().toStdString());
                ui->three_win_times->setText(QString::fromStdString(to_string(j+1)));

                break;
            }
            case(3):{
                // 闲家4 赢
                result += "闲4 ";

                break;
            }
            case(4):{
                // 闲家5 赢
                result += "闲5 ";

                break;
            }
            case(5):{
                // 闲家6 赢
                result += "闲6 ";

                break;
            }
            }
        }
        else{
            switch (i) {
            case(0):{
                //闲家1 输

                break;
            }
            case(1):{
                //闲家2 输

                break;
            }
            case(2):{
                //闲家3 输

                break;
            }
            case(3):{
                //闲家4 输

                break;
            }
            case(4):{
                //闲家5 输

                break;
            }
            case(5):{
                //闲家6 输
                break;
            }
            }
        }
    }
    if(result == ""){
        ui->pu_result->setText(QString("庄赢"));
        ui->who_win->setText("庄赢");
    }
    else{
        ui->pu_result->setText(result);
        ui->who_win->setText(result);
    }

    quarter_increase();
}

void MainWindow::update()
{
    ui->lineEdit->setFocus();
}

void MainWindow::on_timeout()
{
    qreal i = m_graphiceffect->opacity();
    if(number.num == 3){
        i = 1;
        m_graphiceffect->setOpacity(i);
        head->data[2].label->setGraphicsEffect(m_graphiceffect);
        timer_opacity->stop();
        return;
    }
    head->data[number.num].label->setStyleSheet("border-radius:5px;background-color: rgb(255, 0, 0)");
    if (i < 0.1)
        this->m_light = true;

    if (i == 1)
        this->m_light = false;

    if (!m_light)
        i -= 0.05;
    else
        i += 0.05;

    m_graphiceffect->setOpacity(i);
    head->data[number.num].label->setGraphicsEffect(m_graphiceffect);

    n_graphiceffect->setOpacity(i);
    label_name->setGraphicsEffect(n_graphiceffect);
}

void MainWindow::pu_stop()
{

}

void MainWindow::pu_locate()
{
    //timer_focus->stop();//应该stop了两遍
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setVisible(true);
    // 禁用定位按钮
    ui->button_locate->setEnabled(false);
    ui->lineEdit_2->setFocus();
    manager->setStatus(LOCATE);
}

void MainWindow::LabelPaixu(players *head){
    //闲家一
    head->data[0].label = ui->one_one_pic;
    head->data[1].label = ui->one_two_pic;
    head->data[2].label = ui->one_three_pic;
    head = head->next;
    //闲家二
    head->data[0].label = ui->two_one_pic;
    head->data[1].label = ui->two_two_pic;
    head->data[2].label = ui->two_three_pic;
    head = head->next;
    //闲家三
    head->data[0].label = ui->three_one_pic;
    head->data[1].label = ui->three_two_pic;
    head->data[2].label = ui->three_three_pic;
    head = head->next;
    //闲家四
    head->data[0].label = ui->one_one_pic_3;
    head->data[1].label = ui->one_two_pic_3;
    head->data[2].label = ui->one_three_pic_3;
    head = head->next;
    //闲家五
    head->data[0].label = ui->one_one_pic_4;
    head->data[1].label = ui->one_two_pic_4;
    head->data[2].label = ui->one_three_pic_4;
    head = head->next;
    //闲家六
    head->data[0].label = ui->one_one_pic_5;
    head->data[1].label = ui->one_two_pic_5;
    head->data[2].label = ui->one_three_pic_5;
    head = head->next;
    //庄家
    head->data[0].label = ui->zhuang_one_pic;
    head->data[1].label = ui->zhuang_two_pic;
    head->data[2].label = ui->zhuang_three_pic;
    head = head->next;
}

void MainWindow::request_game_record()
{
    manager->setInterface("SgHeGuanSgGameRecord");
    manager->setStatus(RECORD);
    manager->postData(QByteArray());
}

void MainWindow::request_room_card()
{
    manager->setInterface("SgHeGuanSgRoomCard");
    manager->setStatus(ROOMCARD);
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());
    manager->postData(postData);
}

void MainWindow::apply_locate()
{
    // 刷新焦点
    ui->lineEdit->setFocus();
    timer_focus->start(200);

    // 更新定位显示
    QString str = ui->lineEdit_2->text();
    ui->label_locate->setText(str);
    ui->lineEdit_2->setVisible(false);

    // 定位到定位到的玩家
    for(int j = 2;j <= location;j++){
      head = head->next;
    }

    // 定位到的玩家开始闪烁
    timer_opacity->start(10);

    ui->button_locate->setEnabled(false);
    ui->button_useless->setEnabled(true);

    // 谁的名字开始闪烁
    switch (location % 7) {
    case(0):
        //庄家
        ui->label_zhuang->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_zhuang;
        break;
    case(1):
        ui->label_xian1->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1;
        break;
    case(2):
        ui->label_xian2->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian2;
        break;
    case(3):
        ui->label_xian3->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian3;
        break;
    case(4):
        ui->label_xian1_2->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_2;
        break;
    case(5):
        ui->label_xian1_3->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_3;
        break;
    case(6):
        ui->label_xian1_4->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_4;
        break;
    }

    //显示停止下注
    ui->opration_show->setText("停止下注");
}

void MainWindow::apply_game_record(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    for(int i = array.count() - 1;i >= 0;i--){
        unsigned int status = array.at(i)["status"].toInt();
        if(status == 2){
            // 该把作废了
        }
        else{
        }
        quarter_increase();
    }
}

void MainWindow::apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three, QJsonArray four, QJsonArray five, QJsonArray six)
{
    // 定位
    for(int i = 1;i < location;i++){
        head = head->next;
    }

    // 谁的名字开始闪烁
    switch (location % 7) {
    case(0):
        //庄家
        ui->label_zhuang->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_zhuang;
        break;
    case(1):
        ui->label_xian1->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1;
        break;
    case(2):
        ui->label_xian2->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian2;
        break;
    case(3):
        ui->label_xian3->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian3;
        break;
    case(4):
        // 闲家4
        ui->label_xian1_2->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_2;
        break;
    case(5):
        ui->label_xian1_3->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_3;
        break;
    case(6):
        ui->label_xian1_4->setStyleSheet("color: rgb(200, 140, 0)");
        label_name = ui->label_xian1_4;
        break;
    }

    timer_opacity->start(10);

    m_fapai = true;
    bool loop = true;
    while (loop){
        switch (head->num){
            case 0:{
                // 闲家1
                if(number.num < one.count()){
                    m_edit_last = QString::fromStdString(to_string(one.at(number.num)["Cardnum"].toInt()));
                    wait(strToCard(m_edit_last.toStdString()));
                }
                else{
                    loop = false;
                }
                break;
            }
            case 1:{
                // 闲家2
                if(number.num < two.count()){
                    m_edit_last = QString::fromStdString(to_string(two.at(number.num)["Cardnum"].toInt()));
                    wait(strToCard(m_edit_last.toStdString()));
                }
                else{
                    loop = false;
                }
                break;
            }
            case 2:{
                // 闲家3
                if(number.num < three.count()){
                    m_edit_last = QString::fromStdString(to_string(three.at(number.num)["Cardnum"].toInt()));
                    wait(strToCard(m_edit_last.toStdString()));
                }
                else{
                    loop = false;
                }
                break;
            }
            case 6:{
                // 庄家
                if(number.num < zhuang.count()){
                    m_edit_last = QString::fromStdString(to_string(zhuang.at(number.num)["Cardnum"].toInt()));
                    wait(strToCard(m_edit_last.toStdString()));
                }
                else{
                    loop = false;
                }
                break;
            }
        case 3:{
            // 闲家4
            if(number.num < four.count()){
                m_edit_last = QString::fromStdString(to_string(four.at(number.num)["Cardnum"].toInt()));
                wait(strToCard(m_edit_last.toStdString()));
            }
            else{
                loop = false;
            }
            break;
        }
        case 4:{
            // 闲家4
            if(number.num < five.count()){
                m_edit_last = QString::fromStdString(to_string(five.at(number.num)["Cardnum"].toInt()));
                wait(strToCard(m_edit_last.toStdString()));
            }
            else{
                loop = false;
            }
            break;
        }
        case 5:{
            // 闲家4
            if(number.num < six.count()){
                m_edit_last = QString::fromStdString(to_string(six.at(number.num)["Cardnum"].toInt()));
                wait(strToCard(m_edit_last.toStdString()));
            }
            else{
                loop = false;
            }
            break;
        }
        }
    }
    ui->lineEdit->setFocus();
}

void MainWindow::request_room_info()
{
    manager->setStatus(ROOMINFO);
    manager->setInterface("HeGuanRoominfo");
    manager->postData(QByteArray());
}

void MainWindow::phase_zero()
{
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    // 倒计时中
    unsigned int time = end - start;
    count_down = 30 - time;
    timer_Countdown->start(1000);
}

void MainWindow::phase_kaiPai()
{
    // 开牌中
    request_room_card();
}

void MainWindow::phase_finish()
{
    // 结算完成
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::responsed_start(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    QJsonObject data = json.value("data").toObject();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();
        ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
        ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));

        ui->pu_start->setEnabled(false);
        ui->who_win->setText(QString(""));
        count_down = 30;
        timer_Countdown->start(1000);
    }
    else{
        ui->pu_start->setEnabled(true);

        QMessageBox box;
        box.setText("三公请求开局失败");
        box.exec();
    }
}

void MainWindow::responsed_roominfo(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        unsigned int BootNum = data.at(0)["BootNum"].toInt();
        unsigned int PaveNum = data.at(0)["PaveNum"].toInt();
        QString DeskName = data.at(0)["DeskName"].toString();
        ui->xue_times->setText(QString::number(BootNum));
        ui->pu_times->setText(QString::number(PaveNum));
        ui->desk_num->setText(DeskName);

        unsigned int phase = data.at(0)["Phase"].toInt();
        switch (phase) {
        case 0:{
            phase_zero();
            break;
        }
        case 1:{
            unsigned int startTime = data.at(0)["GameStarTime"].toInt();
            unsigned int sysTime = data.at(0)["Systime"].toInt();

            phase_countDown(startTime,sysTime);
            break;
        }
        case 2:{
            phase_kaiPai();
            break;
        }
        case 3:{
            phase_finish();
            break;
        }
        }
    }
    else{
        QMessageBox box;
        box.setText("三公获取房间信息失败");
        box.exec();
    }
}

void MainWindow::responsed_record(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();

        unsigned int one = data.at(0)["x1wincount"].toInt();
        unsigned int two = data.at(0)["x2wincount"].toInt();
        unsigned int three = data.at(0)["x3wincount"].toInt();
        unsigned int four = data.at(0)["x4wincount"].toInt();
        unsigned int five = data.at(0)["x5wincount"].toInt();
        unsigned int six = data.at(0)["x6wincount"].toInt();

        ui->one_win_times->setText(QString::number(one));
        ui->two_win_times->setText(QString::number(two));
        ui->three_win_times->setText(QString::number(three));
        ui->one_win_times->setText(QString::number(four));
        ui->two_win_times->setText(QString::number(five));
        ui->three_win_times->setText(QString::number(six));

        QJsonArray list = data.at(0)["list"].toArray();
        apply_game_record(list);
        request_room_info();
    }
    else{
        QMessageBox box;
        box.setText("三公游戏记录请求失败");
        box.exec();
    }
}

void MainWindow::responsed_roomcard(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    QJsonObject data = json.value("data").toObject();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QString l = data.value("LocationNum").toString();
        qDebug() << "location : " << l;
        location = l.toInt();
        ui->label_locate->setText(l);
        if(location == 0){
            ui->button_locate->setEnabled(true);
        }
        else{
            QJsonArray zhuang = data.value("BankerCard").toArray();
            QJsonArray one = data.value("IdleOneCard").toArray();
            QJsonArray two = data.value("IdleTwoCard").toArray();
            QJsonArray three = data.value("IdleThreeCard").toArray();
            QJsonArray four = data.value("IdleFourCard").toArray();
            QJsonArray five = data.value("IdleFiveCard").toArray();
            QJsonArray six = data.value("IdleSixCard").toArray();
            apply_room_card(zhuang,one,two,three,four,five,six);
            ui->button_useless->setEnabled(true);
        }
    }
    else{
        // 游戏记录信息请求失败
        QMessageBox box;
        box.setText("本局三公游戏信息请求失败");
        box.exec();
    }
}

void MainWindow::responsed_locate(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        // 定位请求成功
        m_fapai = true;
        this->apply_locate();
    }
    else{
        // 定位请求失败
        // 启用定位按钮
        ui->button_locate->setEnabled(true);

        // 提示错误
        QMessageBox box;
        box.setText("三公定位请求失败");
        box.exec();
    }
}

void MainWindow::responsed_fapai(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        m_fapai = true;
        wait(strToCard(m_edit_last.toStdString()));
    }
    else{
        m_edit_last = "";
        QMessageBox box;
        box.setText("三公刷牌失败");
        box.exec();
    }
}

void MainWindow::responsed_summit(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        this->apply_summit();
    }
    else{
        ui->button_summit->setEnabled(true);
        QMessageBox box;
        box.setText("三公提交请求失败");
        box.exec();
    }
}

void MainWindow::responsed_useless(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        this->apply_useless();
    }
    else{
        ui->button_useless->setEnabled(true);

        QMessageBox box;
        box.setText("三公作废失败");
        box.exec();
    }
}

void MainWindow::responsed_init(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    QJsonObject data = json.value("data").toObject();

    unsigned int status = json.value("status").toInt();
    if(status == 1){
        unsigned int boot_num = json.value("boot_num").toInt();
        unsigned int pave_num = json.value("pave_num").toInt();
        ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
        ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));
        ui->one_win_times->setText("");
        ui->two_win_times->setText("");
        ui->three_win_times->setText("");
        ui->four_win_times->setText("");
        ui->five_win_times->setText("");
        ui->six_win_times->setText("");
    }
    else{
        QMessageBox box;
        box.setText("三公初始化失败");
        box.exec();
    }
}




void MainWindow::line_finish()
{
    bool ok = false;
    location = ui->lineEdit_2->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        //提示
        ui->lineEdit_2->setText("");
        QMessageBox box;
        box.setText("三公输入的定位无效");
        box.exec();
        return;
    }
    manager->setInterface("SgOrientation");
    manager->setStatus(LOCATE);
    QByteArray Data;
    Data.append("location_num=");
    Data.append(QString::number(location));

    manager->postData(Data);
}

void MainWindow::Request_summit(){
    //发送提交请求
    //提交按钮作废
    ui->button_summit->setEnabled(false);

    manager->setStatus(SUMMIT);
    manager->setInterface("SgGetGameOver");

    QByteArray Data;
    Data.append("bootNum=");Data.append(ui->xue_times->text());
    Data.append("&paveNum=");Data.append(ui->pu_times->text());
    manager->postData(Data);
}



void MainWindow::apply_summit()
{
    // 提交成功
    // 不再闪烁
    timer_opacity->stop();

    //遍历清空节点
    players *node = head;
    do{
        for(int i = 0;i < 3;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    while(head->num != 0){
        head = head->next;
    }

    // 钟表归零
    number.man = 0;
    number.num = 0;

    // 禁用提交
    ui->button_summit->setEnabled(false);

    //牌型清空
    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));
    ui->xian1_result_2->setText(QString(""));
    ui->xian1_result_3->setText(QString(""));
    ui->xian1_result_4->setText(QString(""));
    result();

    // 重新排序每个玩家的 label
    LabelPaixu(head);

    // 清空上张牌的数据，避免 54 分之一 的几率出错
    m_edit_last = QString("");

    //显示已完结
    ui->opration_show->setText(QString("已完结"));
    ui->label_locate->setText(QString(""));
    ui->pu_start->setEnabled(true);
    ui->button_useless->setEnabled(false);
}

void MainWindow::on_exit(){
    ui->pu_start->setDown(true);
    this->close();
}

void MainWindow::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MainWindow::Request_useless(){
    // 请求作废
    // 禁用作废按钮
    ui->button_useless->setEnabled(false);

    manager->setStatus(USELESS);
    manager->setInterface("SgAbolish");

    QByteArray Data;
    Data.append("boot_num=");Data.append(ui->xue_times->text());
    Data.append("&pave_num=");Data.append(ui->pu_times->text());

    manager->postData(Data);
}

void MainWindow::apply_useless(){
    // 开始进行作废
    // 焦点到定位
    timer_focus->stop();
    ui->button_locate->setFocus();
    // 启用定位，禁用提交
    ui->button_summit->setEnabled(false);

    // 停止闪烁
    timer_opacity->stop();

    // 该把作废了

    quarter_increase();
    // 停止闪烁
    timer_opacity->stop();

    // 恢复透明度
    if(number.num < 5){
        m_graphiceffect->setOpacity(1);
        head->data[number.num].label->setGraphicsEffect(m_graphiceffect);
    }
    if(location % 4 == 0){
        label_name->setStyleSheet("color: rgb(255, 0, 0)");
    }
    else{
        label_name->setStyleSheet("color: rgb(255, 255, 255)");
    }
    n_graphiceffect->setOpacity(1);
    label_name->setGraphicsEffect(n_graphiceffect);

    //遍历清空节点,清空扑克图片
    players *node = head;
    do{
        for(int i = 0;i < 3;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    while (head->num != 0) {
        head = head->next;
    }

    number.man = 0;
    number.num = 0;

    // 4名玩家的牌型清空
    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->xian1_result_2->setText(QString(""));
    ui->xian1_result_3->setText(QString(""));
    ui->xian1_result_4->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    LabelPaixu(head);
    m_edit_last = QString("");

    // 禁用作废按钮
    ui->button_useless->setEnabled(false);
    // 启用开始按钮
    ui->pu_start->setEnabled(true);
}

void MainWindow::Request_start(){
    // 请求开始
    // 禁用开始按钮
    ui->pu_start->setEnabled(false);

    manager->setStatus(START);
    manager->setInterface("SgRoomProcess");

    manager->postData(QByteArray());
}

void MainWindow::Request_initialize()
{
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        // 请求初始化
        manager->setStatus(INIT);
        manager->setInterface("SgRonmInitialize");
        manager->postData(QByteArray());
    }
}

void MainWindow::on_count_down()
{
    // 刷新倒计时
    ui->who_win->setText(QString::number(count_down));
    count_down--;

    // 如果倒计时为 -1
    if(count_down == -1){
        // 停止倒计时
        timer_Countdown->stop();
        ui->who_win->setText(QString(""));
        // 启用定位
        ui->button_locate->setEnabled(true);
    }
}

