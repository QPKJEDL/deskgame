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
using namespace std;
//static QString URL = "192.168.0.111:8210";
static QString URL = "129.211.114.135:8210";
MainWindow::MainWindow(int id, QString token, QString limit,QString tieLimit,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_edit_last("")
    , desk_id(id)
    , desk_token(token)
    , m_post_type("login")
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
    ui->label_limit->setText(limit);
    ui->label_tieLimit->setText(tieLimit);

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
    connect(ui->pu_end,SIGNAL(clicked()),this,SLOT(pu_end()));

    // 开始按钮
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(Request_start()));
    // 倒计时计数器
    timer_Countdown = new QTimer(this);
    connect(timer_Countdown,SIGNAL(timeout()),this,SLOT(on_count_down()));

    // 初始化按钮
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(Request_initialize()));

   m_request = new QNetworkRequest;
   m_request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
   m_request->setRawHeader("desk_id",QString::number(id).toUtf8());
   m_request->setRawHeader("desk_token",token.toUtf8());
   //QString url = "http://" + URL + "/dutch_login";
   //m_request->setUrl(QUrl(url));

   //QByteArray postData;
   //postData.append("desk=A2&password=123456");

   // post
   m_accessManager = new QNetworkAccessManager(this);
   connect(m_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
   //m_accessManager->post(*m_request, postData);

   // 请求之前所有结果
   request_game_record();

  //M
  //闲家一
  head = new players;
  head->player = "ShunMen";
  head->data[0].label = ui->one_one_pic;
  head->data[1].label = ui->one_two_pic;
  //闲家二
  players *er = new players;
  er->player = "TianMen";
  er->data[0].label = ui->two_one_pic;
  er->data[1].label = ui->two_two_pic;
  head->next = er;
  //闲家三
  players *san = new players;
  san->player = "FanMen";
  san->data[0].label = ui->three_one_pic;
  san->data[1].label = ui->three_two_pic;
  er->next = san;
  //庄家
  players *zhuang = new players;
  zhuang->player = "Banker";
  zhuang->data[0].label = ui->zhuang_one_pic;
  zhuang->data[1].label = ui->zhuang_two_pic;
  san->next = zhuang;
  zhuang->next = head;
  //M
  //初始化结果列表，80 个QLabel
  quarter = 0;
  //第一局
  FOURLABELS *labels_one = new FOURLABELS;
  labels_one->zhuang = ui->zhuang_one;
  labels_one->one = ui->one_one;
  labels_one->two = ui->two_one;
  labels_one->three = ui->three_one;
  this->result_list.append(labels_one);
  //
  FOURLABELS *labels_two = new FOURLABELS;
  labels_two->zhuang = ui->zhuang_two;
  labels_two->one = ui->one_two;
  labels_two->two = ui->two_two;
  labels_two->three = ui->three_two;
  this->result_list.append(labels_two);
  //
  FOURLABELS *labels_three = new FOURLABELS;
  labels_three->zhuang = ui->zhuang_three;
  labels_three->one = ui->one_three;
  labels_three->two = ui->two_three;
  labels_three->three = ui->three_three;
  this->result_list.append(labels_three);
  //
  FOURLABELS *labels_four = new FOURLABELS;
  labels_four->zhuang = ui->zhuang_four;
  labels_four->one = ui->one_four;
  labels_four->two = ui->two_four;
  labels_four->three = ui->three_four;
  this->result_list.append(labels_four);
  //
  FOURLABELS *labels_five = new FOURLABELS;
  labels_five->zhuang = ui->zhuang_five;
  labels_five->one = ui->one_five;
  labels_five->two = ui->two_five;
  labels_five->three = ui->three_five;
  this->result_list.append(labels_five);
  //
  FOURLABELS *labels_six = new FOURLABELS;
  labels_six->zhuang = ui->zhuang_six;
  labels_six->one = ui->one_six;
  labels_six->two = ui->two_six;
  labels_six->three = ui->three_six;
  this->result_list.append(labels_six);
  //
  FOURLABELS *labels_seven = new FOURLABELS;
  labels_seven->zhuang = ui->zhuang_seven;
  labels_seven->one = ui->one_seven;
  labels_seven->two = ui->two_seven;
  labels_seven->three = ui->three_seven;
  this->result_list.append(labels_seven);
  //
  FOURLABELS *labels_eight = new FOURLABELS;
  labels_eight->zhuang = ui->zhuang_eight;
  labels_eight->one = ui->one_eight;
  labels_eight->two = ui->two_eight;
  labels_eight->three = ui->three_eight;
  this->result_list.append(labels_eight);
  //
  FOURLABELS *labels_nine = new FOURLABELS;
  labels_nine->zhuang = ui->zhuang_nine;
  labels_nine->one = ui->one_nine;
  labels_nine->two = ui->two_nine;
  labels_nine->three = ui->three_nine;
  this->result_list.append(labels_nine);
  //
  FOURLABELS *labels_ten = new FOURLABELS;
  labels_ten->zhuang = ui->zhuang_ten;
  labels_ten->one = ui->one_ten;
  labels_ten->two = ui->two_ten;
  labels_ten->three = ui->three_ten;
  this->result_list.append(labels_ten);
  //第十一局
  FOURLABELS *labels_eleven = new FOURLABELS;
  labels_eleven->zhuang = ui->zhuang_ele;
  labels_eleven->one = ui->one_ele;
  labels_eleven->two = ui->two_ele;
  labels_eleven->three = ui->three_ele;
  this->result_list.append(labels_eleven);
  //
  FOURLABELS *labels_twe = new FOURLABELS;
  labels_twe->zhuang = ui->zhuang_twe;
  labels_twe->one = ui->one_twe;
  labels_twe->two = ui->two_twe;
  labels_twe->three = ui->three_twe;
  this->result_list.append(labels_twe);
  //
  FOURLABELS *labels_thr = new FOURLABELS;
  labels_thr->zhuang = ui->zhuang_thr;
  labels_thr->one = ui->one_thr;
  labels_thr->two = ui->two_thr;
  labels_thr->three = ui->three_thr;
  this->result_list.append(labels_thr);
  //
  FOURLABELS *labels_fourteen = new FOURLABELS;
  labels_fourteen->zhuang = ui->zhuang_fourteen;
  labels_fourteen->one = ui->one_fourteen;
  labels_fourteen->two = ui->two_fourteen;
  labels_fourteen->three = ui->three_fourteen;
  this->result_list.append(labels_fourteen);
  //
  FOURLABELS *labels_fif = new FOURLABELS;
  labels_fif->zhuang = ui->zhuang_fif;
  labels_fif->one = ui->one_fif;
  labels_fif->two = ui->two_fif;
  labels_fif->three = ui->three_fif;
  this->result_list.append(labels_fif);
  //
  FOURLABELS *labels_sixteen = new FOURLABELS;
  labels_sixteen->zhuang = ui->zhuang_sixteen;
  labels_sixteen->one = ui->one_sixteen;
  labels_sixteen->two = ui->two_sixteen;
  labels_sixteen->three = ui->three_sixteen;
  this->result_list.append(labels_sixteen);
  //
  FOURLABELS *labels_seventeen = new FOURLABELS;
  labels_seventeen->zhuang = ui->zhuang_seventeen;
  labels_seventeen->one = ui->one_seventeen;
  labels_seventeen->two = ui->two_seventeen;
  labels_seventeen->three = ui->three_seventeen;
  this->result_list.append(labels_seventeen);
  //
  FOURLABELS *labels_eighteen = new FOURLABELS;
  labels_eighteen->zhuang = ui->zhuang_eighteen;
  labels_eighteen->one = ui->one_eighteen;
  labels_eighteen->two = ui->two_eighteen;
  labels_eighteen->three = ui->three_eighteen;
  this->result_list.append(labels_eighteen);
  //
  FOURLABELS *labels_ninteen = new FOURLABELS;
  labels_ninteen->zhuang = ui->zhuang_ninteen;
  labels_ninteen->one = ui->one_ninteen;
  labels_ninteen->two = ui->two_ninteen;
  labels_ninteen->three = ui->three_ninteen;
  this->result_list.append(labels_ninteen);
  //
  FOURLABELS *labels_twt = new FOURLABELS;
  labels_twt->zhuang = ui->zhuang_twt;
  labels_twt->one = ui->one_twt;
  labels_twt->two = ui->two_twt;
  labels_twt->three = ui->three_twt;
  this->result_list.append(labels_twt);
  //M
  ui->lineEdit_2->setVisible(false);
}

//判断是否是炸弹12，五花牛11
//int FiveBull(CARD player[]){
//    //炸弹判断
//    int shuLiang[5] = {0};
//    int count = 0,c = 0;
//    for(int i = 0;i < 5;i++){
//        for(int j = 0;j < 5;j++){
//            if(player[i].face == player[j].face){
//                shuLiang[i]++;
//                if(c < shuLiang[i]){
//                    c = shuLiang[i];
//                    //炸弹
//                    if(c == 4){
//                        return 12;
//                    }
//                }
//            }
//        }
//        if(player[i].hua){
//            count++;
//            //五花牛
//            if(count == 5){
//                return 11;
//            }
//        }
//    }
//    return -1;
//}

//牛几 ,10 为 牛 10
//int BullCount(CARD player[]){
//    for(int one = 0;one <= 2;one++){
//        for(int two = one + 1;two <= 3;two++){
//            for(int three = two + 1;three <= 4;three++){
//                if((player[one].num + player[two].num + player[three].num) % 10 == 0){
//                    vector<int> vec = {0,1,2,3,4};
//                    vec.erase(vec.begin() + one);
//                    vec.erase(vec.begin() + two - 1);
//                    vec.erase(vec.begin() + three - 2);
//                    int m = (player[vec[0]].num + player[vec[1]].num) % 10;
//                    if(m == 0){
//                        return 10;
//                    }
//                    return m;
//                }
//            }
//        }
//    }
//    return -1;
//}

//该函数的作用是将 face 转换成 点数
//int dianShu(string str){
//    string Cards[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
//    for(int i = 0;i < 13;i++){
//        if(Cards[i] == str){
//            return i + 1;
//        }
//    }
//    return 0;
//}

//按理说排序以后就不必寻找最大点数的牌了，因为player[4]
//void paixu(CARD player[]){
//    for(int i = 0;i < 4;i++){
//        for(int j = 0;j < 4-i;j++){
//            //先判断下一个牌的值是否大于这个牌的值
//            if(dianShu(player[j].face) > dianShu(player[j + 1].face)){
//                CARD temp = player[j];
//                player[j] = player[j + 1];
//                player[j + 1] = temp;
//            }
//            //如果上面的if语句执行了，则说明值不一样,那么下面这个if不会成立
//            if(dianShu(player[j].face) == dianShu(player[j + 1].face) && player[j].color < player[j + 1].color){
//                CARD temp = player[j];
//                player[j] = player[j + 1];
//                player[j + 1] = temp;
//            }
//        }
//    }
//}

//void MainWindow::locate(){
//    // 定位到定位到的玩家
//    for(int j = 2;j <= location;j++){
//      head = head->next;
//    }
//}

string PaiXingToStr(int paixing){
    if(paixing < 0){
        return "无牛";
    }
    else if(paixing > 0 && paixing < 10){
        return "牛 " + to_string(paixing);
    }
    else{
        switch (paixing) {
        case(10):
            return "牛牛";
            break;
        case(11):
            return "五花牛";
            break;
        case(12):
            return "炸弹";
            break;
        }
    }
    return "不可能";
}

void MainWindow::Request_faPai(CARD card){
    ////////////////////////////////////////////////////////////
    m_request->setUrl(QUrl("http://" + URL + "/A89GameCard"));

    QJsonObject json_object;
    QJsonObject json_object2;
    json_object2.insert("Player",head->player);
    json_object2.insert("NumCard",QString::number(number.num + 1)); // CardPosition
    json_object2.insert("Num",QString::number(card.num)); // 点数
    json_object2.insert("Cardnum",m_edit_last);//CardAllNum

    qDebug() << "head->player: " << head->player <<endl;
    qDebug() << "number.num: " << number.num <<endl;
    qDebug() << "card.color: " << card.color <<endl;
    qDebug() << "card.num: " << card.num <<endl;
    qDebug() << "m_edit_last: " << m_edit_last <<endl;

    //QJsonValue jsonValue(json_object2);
    QByteArray postData;

    qDebug() << ui->pu_times->text() <<endl;
    qDebug() << ui->xue_times->text() <<endl;
    postData.append("boot_num=");postData.append(ui->xue_times->text());postData.append("&");
    postData.append("pave_num=");postData.append(ui->pu_times->text());postData.append("&");
    postData.append("Card=");postData.append(QString(QJsonDocument(json_object2).toJson()));
     m_accessManager->post(*m_request, postData);
     m_fapai = false;
    //////////////////////////////////////////////////////////////
}

void MainWindow::wait(CARD card, string paixing){
    // 将 card 保存到当前玩家的缓存中
    head->data[number.num].num = card.num;
    head->data[number.num].face = card.face;
    head->data[number.num].color = card.color;
    // 显示牌的图片
    head->data[number.num].label->setStyleSheet("image: url(:/image/pukepai/" + m_edit_last +".png)");

    if(paixing != ""){
        // 如果是第二张牌，则显示牌型
        if(head->player == "ShunMen"){
            ShunMen = QString::fromStdString(paixing);
            ui->xian1_result->setText(QString::fromStdString(paixing));
        }
        else if(head->player == "TianMen"){
            TianMen = QString::fromStdString(paixing);
            ui->xian2_result->setText(QString::fromStdString(paixing));
        }
        else if(head->player == "FanMen"){
            FanMen = QString::fromStdString(paixing);
            ui->xian3_result->setText(QString::fromStdString(paixing));
        }
        else if(head->player == "Banker"){
            Banker = QString::fromStdString(paixing);
            ui->zhuang_result->setText(QString::fromStdString(paixing));
        }
    }

    qDebug() << "head->num : " << head->player;

    // 前进到下一个玩家
    head = head->next;
    number.increase();

    // 如果所有牌都发完了
    if(number.num == 2){
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
    qDebug() << QString::fromStdString(str);
    string color = str.substr(0,1);
    string face = str.substr(1,2);
    CARD card;
    card.color = stoi(color);
    card.num = stoi(face) == 1 ? 14 : stoi(face);
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

           if(number.num == 2){
               return;
           }
           if((m_edit_last.size() == 3) && m_fapai){
               m_post_type = QString("fapai");
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
//bool Bigger(PAIRESULT player_1,PAIRESULT player_2){
//    if(player_1.paiXing > player_2.paiXing){
//        return true;
//    }
//    if(player_1.paiXing == player_2.paiXing){
//        if(dianShu(player_1.biggest.face) > dianShu(player_2.biggest.face)){
//            return true;
//        }
//        if(dianShu(player_1.biggest.face) == dianShu(player_2.biggest.face)){
//            return player_1.biggest.color < player_2.biggest.color ? true : false;
//        }
//        return false;
//    }
//    return false;
//}

//QString PaixingToResult(int i){
//    if(i < 0){
//        return "N";
//    }
//    if(i == 10){
//        return "B";
//    }
//    if(i > 0){
//        return QString::fromStdString(to_string(i));
//    }

//    return QString("");
//}

//void MainWindow::result(){
//    PAIRESULT zhuang;
//    PAIRESULT vec[3] = {};
//    QString result = "";

//    for(int i = 0;i < 4;i++){
//        PAIRESULT result = PaiXing(head->data);
//        if(head->num == 3){
//            zhuang = result;
//        }
//        else{
//            vec[head->num] = result;
//        }
//        head = head->next;
//    }

//    //所有牌型收集完毕，开始比较
//    //庄家结果
//    if(quarter <= 19){
//        result_list[quarter]->zhuang->setText(PaixingToResult(zhuang.paiXing));
//    }
//    else{
//        for(int q = 0;q < 19;q++){
//            result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
//            result_list[q]->zhuang->setStyleSheet(result_list[q]->zhuang->styleSheet());
//        }
//        result_list[19]->zhuang->setText(PaixingToResult(zhuang.paiXing));
//        result_list[19]->zhuang->setStyleSheet("image: url(:/image/red.png)");
//    }

//    for(int i = 0;i < 3;i++){
//        if(!Bigger(zhuang,vec[i])){
//            switch (i) {
//            case(0):{
//                //闲家1 赢
//                result += "闲1 ";
//                int j = stoi(ui->one_win_times->text().toStdString());
//                ui->one_win_times->setText(QString::fromStdString(to_string(j+1)));

//                if(quarter <= 19){
//                    result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->one->setStyleSheet("image: url(:/image/blue.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->one->setText(result_list[q+1]->one->text());
//                        result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());
//                    }
//                    result_list[19]->one->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");
//                }

//                break;
//            }
//            case(1):{
//                //闲家2 赢
//                result += "闲2 ";
//                int j = stoi(ui->two_win_times->text().toStdString());
//                ui->two_win_times->setText(QString::fromStdString(to_string(j+1)));

//                if(quarter <= 19){
//                    result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->two->setStyleSheet("image: url(:/image/blue.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->two->setText(result_list[q+1]->two->text());
//                        result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());
//                    }
//                    result_list[19]->two->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");
//                }
//                break;
//            }
//            case(2):{
//                //闲家3 赢
//                result += "闲3 ";
//                int j = stoi(ui->three_win_times->text().toStdString());
//                ui->three_win_times->setText(QString::fromStdString(to_string(j+1)));

//                if(quarter <= 19){
//                    result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->three->setStyleSheet("image: url(:/image/blue.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->three->setText(result_list[q+1]->three->text());
//                        result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
//                    }
//                    result_list[19]->three->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
//                }

//                break;
//            }
//            }
//        }
//        else{
//            switch (i) {
//            case(0):{
//                //闲家1 输

//                if(quarter <= 19){
//                    result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->one->setStyleSheet("image: url(:/image/gray.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->one->setText(result_list[q+1]->one->text());
//                        result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());
//                    }
//                    result_list[19]->one->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->one->setStyleSheet("image: url(:/image/gray.png)");
//                }

//                break;
//            }
//            case(1):{
//                //闲家2 输
//                if(quarter <= 19){
//                    result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->two->setStyleSheet("image: url(:/image/gray.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->two->setText(result_list[q+1]->two->text());
//                        result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());
//                    }
//                    result_list[19]->two->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->two->setStyleSheet("image: url(:/image/gray.png)");
//                }


//                break;
//            }
//            case(2):{
//                //闲家3 输
//                if(quarter <= 19){
//                    result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[quarter]->three->setStyleSheet("image: url(:/image/gray.png)");
//                }
//                else{
//                    for(int q = 0;q < 19;q++){
//                        result_list[q]->three->setText(result_list[q+1]->three->text());
//                        result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
//                    }
//                    result_list[19]->three->setText(PaixingToResult(vec[i].paiXing));
//                    result_list[19]->three->setStyleSheet("image: url(:/image/gray.png)");
//                }
//                break;
//            }
//            }
//        }
//    }
//    if(result == ""){
//        ui->pu_result->setText(QString("庄赢"));
//        ui->who_win->setText("庄赢");
//    }
//    else{
//        ui->pu_result->setText(result);
//        ui->who_win->setText(result);
//    }

//    if(quarter < 20){
//        quarter++;
//    }
//}

int PaiXingToInt(QString str){
    qDebug() << "PaiXingToInt : " << str;
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

void MainWindow::result(){
    int zhuang = PaiXingToInt(Banker);
    int one = PaiXingToInt(ShunMen);
    int two = PaiXingToInt(TianMen);
    int three = PaiXingToInt(FanMen);
    // 庄结果
    result_list[quarter]->zhuang->setText(Banker);

    if(one > zhuang){
        // 顺门赢
        result_list[quarter]->one->setText(ShunMen);
        result_list[quarter]->one->setStyleSheet("image: url(:/image/blue.png)");
    }
    else{
        // 顺门输
        result_list[quarter]->one->setText(ShunMen);
        result_list[quarter]->one->setStyleSheet("image: url(:/image/gray.png)");
    }
    if(two > zhuang){
        // 天门赢
        result_list[quarter]->two->setText(TianMen);
        result_list[quarter]->two->setStyleSheet("image: url(:/image/blue.png)");
    }
    else{
        // 天门输
        result_list[quarter]->two->setText(TianMen);
        result_list[quarter]->two->setStyleSheet("image: url(:/image/gray.png)");
    }
    if(three > zhuang){
        // 反门赢
        result_list[quarter]->three->setText(FanMen);
        result_list[quarter]->three->setStyleSheet("image: url(:/image/blue.png)");
    }
    else{
        // 反门输
        result_list[quarter]->three->setText(FanMen);
        result_list[quarter]->three->setStyleSheet("image: url(:/image/gray.png)");
    }
    if(quarter < 19){
        quarter++;
    }
    else{
        for(int q = 0;q < 19;q++){
            result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
            result_list[q]->zhuang->setStyleSheet(result_list[q+1]->zhuang->styleSheet());

            result_list[q]->one->setText(result_list[q+1]->one->text());
            result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());

            result_list[q]->two->setText(result_list[q+1]->two->text());
            result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());

            result_list[q]->three->setText(result_list[q+1]->three->text());
            result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
        }
        result_list[19]->zhuang->setText("");
        result_list[19]->zhuang->setStyleSheet("image: url(:/image/red.png)");

        result_list[19]->one->setText("");
        result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");

        result_list[19]->two->setText("");
        result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");

        result_list[19]->three->setText("");
        result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
    }
}

void MainWindow::update()
{
    ui->lineEdit->setFocus();
}

void MainWindow::update_date(){
    ui->label_date->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd    dddd    hh:mm:ss"));
}

void MainWindow::on_timeout()
{
    qreal i = m_graphiceffect->opacity();
    if(number.num == 2){
        i = 1;
        m_graphiceffect->setOpacity(i);
        head->data[1].label->setGraphicsEffect(m_graphiceffect);
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

//void MainWindow::pu_start()
//{
//    m_post_type = QString("pu_start");

//    m_request->setUrl(QUrl("http://192.168.0.115:6667/RoomProcess"));
//    QByteArray postData;
//    //postData.append("desk=A2&password=123456");

//   //post
//   m_accessManager->post(*m_request, postData);
//}

void MainWindow::pu_stop()
{

}

void MainWindow::pu_end()
{
    // 请求终止
    int choose = QMessageBox::question(this,QString("终止"),QString("确认终止？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        // 发送请求
        m_post_type = QString("end");
        m_request->setUrl(QUrl("http://" + URL + "/GetGameOver"));
        QByteArray postData;
        postData.append("boot_num=");postData.append(ui->pu_times->text());
        m_accessManager->post(*m_request, postData);
    }
}

void MainWindow::pu_locate()
{
    //timer_focus->stop();//应该stop了两遍
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setVisible(true);
    // 禁用定位按钮
    ui->button_locate->setEnabled(false);
    m_post_type = QString("locate");
}

//void MainWindow::LabelPaixu(players *head){
//    //闲家一
//    head->data[0].label = ui->one_one_pic;
//    head->data[1].label = ui->one_two_pic;
//    head->data[2].label = ui->one_three_pic;
//    head->data[3].label = ui->one_four_pic;
//    head->data[4].label = ui->one_five_pic;
//    head = head->next;
//    //闲家二
//    head->data[0].label = ui->two_one_pic;
//    head->data[1].label = ui->two_two_pic;
//    head->data[2].label = ui->two_three_pic;
//    head->data[3].label = ui->two_four_pic;
//    head->data[4].label = ui->two_four_pic_2;//?
//    head = head->next;
//    //闲家三
//    head->data[0].label = ui->three_one_pic;
//    head->data[1].label = ui->three_two_pic;
//    head->data[2].label = ui->three_three_pic;
//    head->data[3].label = ui->three_four_pic;
//    head->data[4].label = ui->three_five_pic;
//    head = head->next;
//    //庄家
//    head->data[0].label = ui->zhuang_one_pic;
//    head->data[1].label = ui->zhuang_two_pic;
//    head->data[2].label = ui->zhuang_three_pic;
//    head->data[3].label = ui->zhuang_four_pic;
//    head->data[4].label = ui->zhuang_five_pic;
//    head = head->next;
//}

void MainWindow::locate_success(){
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

    // 禁用定位按钮
    ui->button_locate->setEnabled(false);
    // 启用定位按钮
    ui->button_useless->setEnabled(true);

    // 谁的名字开始闪烁
    switch (location % 4) {
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
    }

    //显示停止下注
    ui->opration_show->setText("停止下注");
}

void MainWindow::request_game_record()
{
    m_request->setUrl(QUrl("http://" + URL + "/HeGuanA89GameRecord"));
    m_post_type = "record";
    QByteArray postData;
    //post
    m_accessManager->post(*m_request, postData);
}

//QString JJtoNum(QString str){
//    qDebug() << str;
//    if(str == "没牛"){
//        return "N";
//    }
//    else if(str == "牛牛" || str == "炸弹牛" || str == "五花牛"){
//        return "B";
//    }
//    else if(str == "牛1"){
//        return "1";
//    }
//    else if(str == "牛2"){
//        return "2";
//    }
//    else if(str == "牛3"){
//        return "3";
//    }
//    else if(str == "牛4"){
//        return "4";
//    }
//    else if(str == "牛5"){
//        return "5";
//    }
//    else if(str == "牛6"){
//        return "6";
//    }
//    else if(str == "牛7"){
//        return "7";
//    }
//    else if(str == "牛8"){
//        return "8";
//    }
//    else if(str == "牛9"){
//        return "9";
//    }
//    return "";
//}

void MainWindow::on_game_record(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    for(int i = array.count() - 1;i >= 0;i--){
        unsigned int status = array.at(i)["status"].toInt();
        if(status == 2){
            // 该把作废了
            result_list.at(quarter)->zhuang->setStyleSheet("image: url(:/image/useless.png)");
            result_list.at(quarter)->one->setStyleSheet("image: url(:/image/useless.png)");
            result_list.at(quarter)->two->setStyleSheet("image: url(:/image/useless.png)");
            result_list.at(quarter)->three->setStyleSheet("image: url(:/image/useless.png)");
        }
        else{
            // 庄家点数
            QString PaiXing = array.at(i)["BankerNum"].toString();
            // 刷新显示
            result_list.at(quarter)->zhuang->setText(PaiXing);
            // 闲家1点数
            PaiXing = array.at(i)["ShunNum"].toString();
            result_list.at(quarter)->one->setText(PaiXing);
            if(array.at(i)["Shunresult"].toString() == "win"){
                result_list.at(quarter)->one->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->one->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家2点数
            PaiXing = array.at(i)["TianNum"].toString();
            result_list.at(quarter)->two->setText(PaiXing);
            if(array.at(i)["Tianresult"].toString() == "win"){
                result_list.at(quarter)->two->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->two->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家3点数
            PaiXing = array.at(i)["FanNum"].toString();
            result_list.at(quarter)->three->setText(PaiXing);
            if(array.at(i)["Fanresult"].toString() == "win"){
                result_list.at(quarter)->three->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->three->setStyleSheet("image: url(:/image/gray.png)");
            }

        }

        qDebug() << "quarter : " << quarter;

        if(quarter < 19){
            quarter++;
        }
        else{
            for(int q = 0;q < 19;q++){
                result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
                result_list[q]->zhuang->setStyleSheet(result_list[q+1]->zhuang->styleSheet());

                result_list[q]->one->setText(result_list[q+1]->one->text());
                result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());

                result_list[q]->two->setText(result_list[q+1]->two->text());
                result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());

                result_list[q]->three->setText(result_list[q+1]->three->text());
                result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
            }
            result_list[19]->zhuang->setText("");
            result_list[19]->zhuang->setStyleSheet("image: url(:/image/blue.png)");

            result_list[19]->one->setText("");
            result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");

            result_list[19]->two->setText("");
            result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");

            result_list[19]->three->setText("");
            result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
        }
    }
}

void MainWindow::request_room_card()
{
    m_request->setUrl(QUrl("http://" + URL + "/HeGuanA89RoomCard"));
    m_post_type = "room_card";
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());
    qDebug() << "room card postdate : " << postData.data();
    //post
    m_accessManager->post(*m_request, postData);
}

void MainWindow::on_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three,string zhuang_result,string one_result,string two_result,string three_result)
{
    qDebug() << "------------------------";
    qDebug() << "one count : " << one.count();
    qDebug() << "two count : " << two.count();
    qDebug() << "three count : " << three.count();
    qDebug() << "zhuang count : " << zhuang.count();

    // 定位
    for(int i = 1;i < location;i++){
        head = head->next;
    }

    // 谁的名字开始闪烁
    switch (location % 4) {
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
    }

    timer_opacity->start(10);

    m_fapai = true;
    bool loop = true;
    while (loop){
        if(head->player == "ShunMen"){
            // 闲家1
            if(number.num < one.count()){
                m_edit_last = QString::number(one.at(number.num)["Cardnum"].toInt());
                wait(strToCard(m_edit_last.toStdString()),one_result);
            }
            else{
                loop = false;
            }
        }
        else if(head->player == "TianMen"){
            // 闲家2
            if(number.num < two.count()){
                m_edit_last = QString::number(two.at(number.num)["Cardnum"].toInt());
                wait(strToCard(m_edit_last.toStdString()),two_result);
            }
            else{
                loop = false;
            }
        }
        else if(head->player == "FanMen"){
            // 闲家3
            if(number.num < three.count()){
                m_edit_last = QString::number(three.at(number.num)["Cardnum"].toInt());
                wait(strToCard(m_edit_last.toStdString()),three_result);
            }
            else{
                loop = false;
            }
        }
        else if(head->player == "Banker"){
            // 庄家
            if(number.num < zhuang.count()){
                m_edit_last = QString::number(zhuang.at(number.num)["Cardnum"].toInt());
                wait(strToCard(m_edit_last.toStdString()),zhuang_result);
            }
            else{
                loop = false;
            }
        }
    }
    ui->lineEdit->setFocus();
}

void MainWindow::request_room_info()
{
    m_post_type = "roominfo";
    QString url = "http://" + URL + "/HeGuanRoominfo";
    m_request->setUrl(QUrl(url));
    QByteArray postData;
    m_accessManager->post(*m_request,postData);
}

void MainWindow::phase_zero()
{
    // 洗牌中
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    // 倒计时中
    qDebug() << start << "  -time-   " << end;
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





void MainWindow::line_finish()
{
    bool ok = false;
    location = ui->lineEdit_2->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        //提示
        QMessageBox box;
        box.setText("输入的定位无效");
        box.exec();
        return;
    }

    m_request->setUrl(QUrl("http://" + URL + "/A89Orientation"));

    QByteArray postData;
    postData.append("location_num=");
    postData.append(QString::number(location));
    //post
    m_accessManager->post(*m_request, postData);
}

void MainWindow::Request_summit(){
    //发送提交请求
    //提交按钮作废
    ui->button_summit->setEnabled(false);
    //
    m_post_type = QString("summit");
    m_request->setUrl(QUrl("http://" + URL + "/A89GetGameResult"));

    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());
    m_accessManager->post(*m_request, postData);
}

void MainWindow::on_summit()
{
    // 提交成功
    // 不再闪烁
    timer_opacity->stop();

    //遍历清空节点
    players *node = head;
    do{
        for(int i = 0;i < 2;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    while(head->player != "ShunMen"){
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
    result();


    // 重新排序每个玩家的 label
    //LabelPaixu(head);

    // 清空上张牌的数据，避免 52 分之一 的几率出错
    m_edit_last = QString("");

    // 显示已完结
    ui->opration_show->setText(QString("已完结"));

    // 清空定位
    ui->label_locate->setText(QString(""));

    // 启用开始按钮
    ui->pu_start->setEnabled(true);

    // 禁用作废按钮
    ui->button_useless->setEnabled(false);
}

void MainWindow::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
            QByteArray bytes = reply->readAll();
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QJsonObject json_object2 = json_object.value("data").toObject();

            if (m_post_type == QString("start")) {
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();

                qDebug() << info  << endl;
                qDebug() << status  << endl;
                //M 应用靴次和铺次
                if(status == 1){
                    // 开始请求成功
                    // 应用靴次和铺次
                    unsigned int boot_num = json_object2.value("boot_num").toInt();
                    unsigned int pave_num = json_object2.value("pave_num").toInt();
                    ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
                    ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));

                    // 禁用开始按钮
                    ui->pu_start->setEnabled(false);
                    ui->who_win->setText(QString(""));
                    // 倒计时恢复为 30
                    count_down = 30;
                    timer_Countdown->start(1000);
                }
                else{
                    // 开始请求失败
                    // 启用开始按钮
                    ui->pu_start->setEnabled(true);

                    // 报告错误
                    QMessageBox box;
                    box.setText("请求开局失败");
                    box.exec();
                }
            }
            else if(m_post_type == QString("roominfo")){
                // 响应房间信息
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();

                if(status == 1){
                    QJsonArray json_array = json_object.value("data").toArray();
                    // 刷新靴次
                    unsigned int boot_num = json_array.at(0)["BootNum"].toInt(); //json_object2.value("BootNum").toInt();
                    qDebug() << "boot_room : " << boot_num;
                    ui->xue_times->setText(QString::number(boot_num));
                    // 刷新铺次
                    unsigned int PaveNum = json_array.at(0)["PaveNum"].toInt(); //json_object2.value("PaveNum").toInt();
                    ui->pu_times->setText(QString::number(PaveNum));
                    qDebug() << "PaveNum : " << PaveNum;
                    // 刷新台桌
                    QString DeskName = json_array.at(0)["DeskName"].toString(); //json_object2.value("DeskName").toString();
                    ui->desk_num->setText(DeskName);
                    qDebug() << "desk id : " << DeskName;
                    // 获取时间戳
                    unsigned int GameStarTime = json_array.at(0)["GameStarTime"].toInt(); //json_object2.value("GameStarTime").toInt();
                    unsigned int Systime = json_array.at(0)["Systime"].toInt();
                    // 获取房间状态
                    unsigned int phase = json_array.at(0)["Phase"].toInt();
                    qDebug() << "phase : " << phase;
                    switch (phase) {
                    case 0:
                        // 洗牌中
                        phase_zero();
                        break;
                    case 1:
                        // 倒计时
                        phase_countDown(GameStarTime,Systime);
                        break;
                    case 2:
                        // 开牌中
                        phase_kaiPai();
                        break;
                    case 3:
                        // 结算完成
                        phase_finish();
                        break;
                    }
                }
                else{
                    QMessageBox box;
                    box.setText("获取房间信息失败");
                    box.exec();
                }
            }
            else if(m_post_type == QString("record")){
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();

                if(status == 1){
                    QJsonArray json_array = json_object.value("data").toArray();
                    QJsonArray array = json_array.at(0)["list"].toArray();

                    // 应用赢得次数
                    // 闲家1
                    unsigned int x1wincount = json_array.at(0)["ShunWinCount"].toInt();
                    ui->one_win_times->setText(QString::number(x1wincount));
                    // 闲家2
                    unsigned int x2wincount = json_array.at(0)["TianWinCount"].toInt();
                    ui->two_win_times->setText(QString::number(x2wincount));
                    // 闲家3
                    unsigned int x3wincount = json_array.at(0)["FanWinCount"].toInt();
                    ui->three_win_times->setText(QString::number(x3wincount));

                    on_game_record(array);
                    request_room_info();
                }
                else{
                    // 游戏记录信息请求失败
                    QMessageBox box;
                    box.setText("游戏记录信息请求失败");
                    box.exec();
                }
            }
            else if(m_post_type == "room_card"){
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();
                qDebug() << "info : " << info << "  sttus : " << status;
                if(status == 1){
                    QString l = json_object2.value("LocationNum").toString();
                    qDebug() << "location : " << l;
                    location = l.toInt();
                    ui->label_locate->setText(l);
                    if(l == ""){
                        ui->button_locate->setEnabled(true);
                    }
                    else{
                        QJsonArray zhuang = json_object2.value("BankerCard").toArray();
                        QJsonArray one = json_object2.value("ShunCard").toArray();
                        QJsonArray two = json_object2.value("TianCard").toArray();
                        QJsonArray three = json_object2.value("FanCard").toArray();
                        QString zhuang_result = json_object2.value("Bankerresult").toString();
                        QString one_result = json_object2.value("Shunresult").toString();
                        QString two_result = json_object2.value("Tianresult").toString();
                        QString three_result = json_object2.value("Fanresult").toString();
                        on_room_card(zhuang,one,two,three,zhuang_result.toStdString(),one_result.toStdString(),two_result.toStdString(),three_result.toStdString());
                        ui->button_useless->setEnabled(true);
                    }
                }
                else{
                    // 游戏记录信息请求失败
                    QMessageBox box;
                    box.setText("本局游戏信息请求失败");
                    box.exec();
                }
            }
            else if (m_post_type == QString("locate")) {
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();

                if(status){
                    // 定位请求成功
                    m_fapai = true;
                    this->locate_success();
                }
                else{
                    // 定位请求失败
                    // 启用定位按钮
                    ui->button_locate->setEnabled(true);

                    // 提示错误
                    QMessageBox box;
                    box.setText("定位请求失败");
                    box.exec();
                }

            } else if (m_post_type == QString("fapai")) {                
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();

                if(status == 1){
                    QString b = json_object2.value("Cardresult").toString();
                    // M 更新荷官端显示牌
                    m_fapai = true;

                    // 更新牌
                    wait(strToCard(m_edit_last.toStdString()),b.toStdString());
                }
                else{
                    // 将扫码机设为空字符串，等待重新扫码
                    m_edit_last = "";
                    // 提示重新扫码
                    QMessageBox box;
                    box.setText("刷牌失败");
                    box.exec();
                }
            } else if (m_post_type == QString("summit")) {
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();
                qDebug() << "summit : " << info << " - " << status;
                if(status == 1){
                    // 提交请求成功
                    this->on_summit();
                }
                else{
                    // 提交请求失败
                    // 重新启用提交按钮
                    ui->button_summit->setEnabled(true);

                    // 提示重新提交
                    QMessageBox box;
                    box.setText("提交请求失败");
                    box.exec();
                }
            } else if (m_post_type == QString("useless")) {
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();
                if(status == 1){
                    // 作废请求成功
                    this->on_useless();
                }
                else{
                    ui->button_useless->setEnabled(true);

                    // 提示作废失败
                    QMessageBox box;
                    box.setText("作废失败");
                    box.exec();
                    return;
                }
            }else if(m_post_type == QString("end")){
                //? 终止的接口
                qDebug() << "endyes";
            }else if(m_post_type == QString("init")){
                QString info = json_object.value("info").toString();
                unsigned int status = json_object.value("status").toInt();
                if(status == 1){
                    // 初始化请求成功
                    // 应用靴次和铺次
                    unsigned int boot_num = json_object2.value("boot_num").toInt();
                    unsigned int pave_num = json_object2.value("pave_num").toInt();
                    ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
                    ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));
                }
                else{
                    // 初始化请求失败
                    QMessageBox box;
                    box.setText("初始化失败");
                    box.exec();
                }
            }
        }
         else
         {
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

void MainWindow::on_exit(){
    this->close();
}

void MainWindow::Request_useless(){
    // 请求作废
    // 禁用作废按钮
    ui->button_useless->setEnabled(false);

    m_post_type = QString("useless");
    m_request->setUrl(QUrl("http://" + URL + "/A89Abolish"));

    // 发送请求
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());

    m_accessManager->post(*m_request, postData);
}

void MainWindow::on_useless(){
    // 开始进行作废
    // 焦点到定位
    timer_focus->stop();
    ui->button_locate->setFocus();
    // 禁用提交
    ui->button_summit->setEnabled(false);

    // 该把作废了
    result_list.at(quarter)->zhuang->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->one->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->two->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->three->setStyleSheet("image: url(:/image/useless.png)");

    if(quarter <= 19){
        quarter++;
    }
    else{
        for(int q = 0;q < 19;q++){
            result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
            result_list[q]->zhuang->setStyleSheet(result_list[q+1]->zhuang->styleSheet());

            result_list[q]->one->setText(result_list[q+1]->one->text());
            result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());

            result_list[q]->two->setText(result_list[q+1]->two->text());
            result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());

            result_list[q]->three->setText(result_list[q+1]->three->text());
            result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
        }
        result_list[19]->zhuang->setText("");
        result_list[19]->zhuang->setStyleSheet("image: url(:/image/red.png)");

        result_list[19]->one->setText("");
        result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");

        result_list[19]->two->setText("");
        result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");

        result_list[19]->three->setText("");
        result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
    }

    // 停止闪烁
    timer_opacity->stop();

    // 恢复透明度
    if(number.num < 2){
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
        for(int i = 0;i < 2;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    while (head->player != "ShunMen") {
        head = head->next;
    }

    number.man = 0;
    number.num = 0;

    // 4名玩家的牌型清空
    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    //LabelPaixu(head);
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
    m_post_type = QString("start");

    m_request->setUrl(QUrl("http://" + URL + "/A89RoomProcess"));
    QByteArray postData;
    // 发送请求
    m_accessManager->post(*m_request, postData);
}

void MainWindow::Request_initialize()
{
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        // 请求初始化
        m_post_type = "init";
        // 发送请求
        QString url = "http://" + URL + "/A89RonmInitialize";
        m_request->setUrl(QUrl(url));
        QByteArray postData;
        m_accessManager->post(*m_request, postData);
    }
}

//void MainWindow::on_start()
//{
//    // 禁用开始按钮
//    ui->pu_start->setEnabled(false);
//    ui->who_win->setText(QString(""));
//    timer_Countdown->start(1000);
//    // 倒计时恢复为 30
//    count_down = 30;
//}

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

