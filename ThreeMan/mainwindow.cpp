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

enum {START,ROOMINFO,RECORD,ROOMCARD,LOCATE,FAPAI,SUMMIT,USELESS,INIT};

MainWindow::MainWindow(int id, QString token, QString limit,QString tieLimit,QWidget *parent)
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

    manager = new MNetManager;
    manager->setIp("129.211.114.135:8210");
    manager->InitRequest("application/x-www-form-urlencoded",QString::number(id),token);
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
  quarter = 0;
  //第一局
  FOURLABELS *labels_one = new FOURLABELS;
  labels_one->zhuang = ui->zhuang_one;
  labels_one->one = ui->one_one;
  labels_one->two = ui->two_one;
  labels_one->three = ui->three_one;
  labels_one->four = ui->one_one_2;
  labels_one->five = ui->one_one_3;
  labels_one->six = ui->one_one_4;
  this->result_list.append(labels_one);
  //
  FOURLABELS *labels_two = new FOURLABELS;
  labels_two->zhuang = ui->zhuang_two;
  labels_two->one = ui->one_two;
  labels_two->two = ui->two_two;
  labels_two->three = ui->three_two;
  labels_two->four = ui->one_two_2;
  labels_two->five = ui->one_two_3;
  labels_two->six = ui->one_two_4;
  this->result_list.append(labels_two);
  //
  FOURLABELS *labels_three = new FOURLABELS;
  labels_three->zhuang = ui->zhuang_three;
  labels_three->one = ui->one_three;
  labels_three->two = ui->two_three;
  labels_three->three = ui->three_three;
  labels_three->four = ui->one_three_2;
  labels_three->five = ui->one_three_3;
  labels_three->six = ui->one_three_4;
  this->result_list.append(labels_three);
  //
  FOURLABELS *labels_four = new FOURLABELS;
  labels_four->zhuang = ui->zhuang_four;
  labels_four->one = ui->one_four;
  labels_four->two = ui->two_four;
  labels_four->three = ui->three_four;
  labels_four->four = ui->one_four_2;
  labels_four->five = ui->one_four_3;
  labels_four->six = ui->one_four_4;
  this->result_list.append(labels_four);
  //
  FOURLABELS *labels_five = new FOURLABELS;
  labels_five->zhuang = ui->zhuang_five;
  labels_five->one = ui->one_five;
  labels_five->two = ui->two_five;
  labels_five->three = ui->three_five;
  labels_five->four = ui->one_five_2;
  labels_five->five = ui->one_five_3;
  labels_five->six = ui->one_five_4;
  this->result_list.append(labels_five);
  //
  FOURLABELS *labels_six = new FOURLABELS;
  labels_six->zhuang = ui->zhuang_six;
  labels_six->one = ui->one_six;
  labels_six->two = ui->two_six;
  labels_six->three = ui->three_six;
  labels_six->four = ui->one_six_2;
  labels_six->five = ui->one_six_3;
  labels_six->six = ui->one_six_4;
  this->result_list.append(labels_six);
  //
  FOURLABELS *labels_seven = new FOURLABELS;
  labels_seven->zhuang = ui->zhuang_seven;
  labels_seven->one = ui->one_seven;
  labels_seven->two = ui->two_seven;
  labels_seven->three = ui->three_seven;
  labels_seven->four = ui->one_seven_2;
  labels_seven->five = ui->one_seven_3;
  labels_seven->six = ui->one_seven_4;
  this->result_list.append(labels_seven);
  //
  FOURLABELS *labels_eight = new FOURLABELS;
  labels_eight->zhuang = ui->zhuang_eight;
  labels_eight->one = ui->one_eight;
  labels_eight->two = ui->two_eight;
  labels_eight->three = ui->three_eight;
  labels_eight->four = ui->one_eight_2;
  labels_eight->five = ui->one_eight_3;
  labels_eight->six = ui->one_eight_4;
  this->result_list.append(labels_eight);
  //
  FOURLABELS *labels_nine = new FOURLABELS;
  labels_nine->zhuang = ui->zhuang_nine;
  labels_nine->one = ui->one_nine;
  labels_nine->two = ui->two_nine;
  labels_nine->three = ui->three_nine;
  labels_nine->four = ui->one_nine_2;
  labels_nine->five = ui->one_nine_3;
  labels_nine->six = ui->one_nine_4;
  this->result_list.append(labels_nine);
  //
  FOURLABELS *labels_ten = new FOURLABELS;
  labels_ten->zhuang = ui->zhuang_ten;
  labels_ten->one = ui->one_ten;
  labels_ten->two = ui->two_ten;
  labels_ten->three = ui->three_ten;
  labels_ten->four = ui->one_ten_2;
  labels_ten->five = ui->one_ten_3;
  labels_ten->six = ui->one_ten_4;
  this->result_list.append(labels_ten);
  //第十一局
  FOURLABELS *labels_eleven = new FOURLABELS;
  labels_eleven->zhuang = ui->zhuang_ele;
  labels_eleven->one = ui->one_ele;
  labels_eleven->two = ui->two_ele;
  labels_eleven->three = ui->three_ele;
  labels_eleven->four = ui->one_ele_2;
  labels_eleven->five = ui->one_ele_3;
  labels_eleven->six = ui->one_ele_4;
  this->result_list.append(labels_eleven);
  //
  FOURLABELS *labels_twe = new FOURLABELS;
  labels_twe->zhuang = ui->zhuang_twe;
  labels_twe->one = ui->one_twe;
  labels_twe->two = ui->two_twe;
  labels_twe->three = ui->three_twe;
  labels_twe->four = ui->one_twe_2;
  labels_twe->five = ui->one_twe_3;
  labels_twe->six = ui->one_twe_4;
  this->result_list.append(labels_twe);
  //
  FOURLABELS *labels_thr = new FOURLABELS;
  labels_thr->zhuang = ui->zhuang_thr;
  labels_thr->one = ui->one_thr;
  labels_thr->two = ui->two_thr;
  labels_thr->three = ui->three_thr;
  labels_thr->four = ui->one_thr_2;
  labels_thr->five = ui->one_thr_3;
  labels_thr->six = ui->one_thr_4;
  this->result_list.append(labels_thr);
  //
  FOURLABELS *labels_fourteen = new FOURLABELS;
  labels_fourteen->zhuang = ui->zhuang_fourteen;
  labels_fourteen->one = ui->one_fourteen;
  labels_fourteen->two = ui->two_fourteen;
  labels_fourteen->three = ui->three_fourteen;
  labels_fourteen->four = ui->one_fourteen_2;
  labels_fourteen->five = ui->one_fourteen_3;
  labels_fourteen->six = ui->one_fourteen_4;
  this->result_list.append(labels_fourteen);
  //
  FOURLABELS *labels_fif = new FOURLABELS;
  labels_fif->zhuang = ui->zhuang_fif;
  labels_fif->one = ui->one_fif;
  labels_fif->two = ui->two_fif;
  labels_fif->three = ui->three_fif;
  labels_fif->four = ui->one_fif_2;
  labels_fif->five = ui->one_fif_3;
  labels_fif->six = ui->one_fif_4;
  this->result_list.append(labels_fif);
  //
  FOURLABELS *labels_sixteen = new FOURLABELS;
  labels_sixteen->zhuang = ui->zhuang_sixteen;
  labels_sixteen->one = ui->one_sixteen;
  labels_sixteen->two = ui->two_sixteen;
  labels_sixteen->three = ui->three_sixteen;
  labels_sixteen->four = ui->one_sixteen_2;
  labels_sixteen->five = ui->one_sixteen_3;
  labels_sixteen->six = ui->one_sixteen_4;
  this->result_list.append(labels_sixteen);
  //
  FOURLABELS *labels_seventeen = new FOURLABELS;
  labels_seventeen->zhuang = ui->zhuang_seventeen;
  labels_seventeen->one = ui->one_seventeen;
  labels_seventeen->two = ui->two_seventeen;
  labels_seventeen->three = ui->three_seventeen;
  labels_seventeen->four = ui->one_seventeen_2;
  labels_seventeen->five = ui->one_seventeen_3;
  labels_seventeen->six = ui->one_seventeen_4;
  this->result_list.append(labels_seventeen);
  //
  FOURLABELS *labels_eighteen = new FOURLABELS;
  labels_eighteen->zhuang = ui->zhuang_eighteen;
  labels_eighteen->one = ui->one_eighteen;
  labels_eighteen->two = ui->two_eighteen;
  labels_eighteen->three = ui->three_eighteen;
  labels_eighteen->four = ui->one_eighteen_2;
  labels_eighteen->five = ui->one_eighteen_3;
  labels_eighteen->six = ui->one_eighteen_4;
  this->result_list.append(labels_eighteen);
  //
  FOURLABELS *labels_ninteen = new FOURLABELS;
  labels_ninteen->zhuang = ui->zhuang_ninteen;
  labels_ninteen->one = ui->one_ninteen;
  labels_ninteen->two = ui->two_ninteen;
  labels_ninteen->three = ui->three_ninteen;
  labels_ninteen->four = ui->one_ninteen_2;
  labels_ninteen->five = ui->one_ninteen_3;
  labels_ninteen->six = ui->one_ninteen_4;
  this->result_list.append(labels_ninteen);
  //
  FOURLABELS *labels_twt = new FOURLABELS;
  labels_twt->zhuang = ui->zhuang_twt;
  labels_twt->one = ui->one_twt;
  labels_twt->two = ui->two_twt;
  labels_twt->three = ui->three_twt;
  labels_twt->four = ui->one_twt_2;
  labels_twt->five = ui->one_twt_3;
  labels_twt->six = ui->one_twt_4;
  this->result_list.append(labels_twt);
  //M
  ui->lineEdit_2->setVisible(false);
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
        ui->pu_start->setFocus();
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

    result_list[quarter]->zhuang->setText(PaixingToResult(zhuang.paiXing));

    for(int i = 0;i < 6;i++){
        if(!Bigger(zhuang,vec[i])){
            switch (i) {
            case(0):{
                //闲家1 赢
                result += "闲1 ";
                int j = stoi(ui->one_win_times->text().toStdString());
                ui->one_win_times->setText(QString::fromStdString(to_string(j+1)));

                result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->one->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            case(1):{
                //闲家2 赢
                result += "闲2 ";
                int j = stoi(ui->two_win_times->text().toStdString());
                ui->two_win_times->setText(QString::fromStdString(to_string(j+1)));

                result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->two->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            case(2):{
                //闲家3 赢
                result += "闲3 ";
                int j = stoi(ui->three_win_times->text().toStdString());
                ui->three_win_times->setText(QString::fromStdString(to_string(j+1)));

                result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->three->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            case(3):{
                // 闲家4 赢
                result += "闲4 ";

                result_list[quarter]->four->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->four->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            case(4):{
                // 闲家5 赢
                result += "闲5 ";

                result_list[quarter]->five->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->five->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            case(5):{
                // 闲家6 赢
                result += "闲6 ";

                result_list[quarter]->six->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->six->setStyleSheet("image: url(:/image/blue.png)");
                break;
            }
            }
        }
        else{
            switch (i) {
            case(0):{
                //闲家1 输

                result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->one->setStyleSheet("image: url(:/image/gray.png)");
                break;
            }
            case(1):{
                //闲家2 输

                result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->two->setStyleSheet("image: url(:/image/gray.png)");
                break;
            }
            case(2):{
                //闲家3 输

                result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->three->setStyleSheet("image: url(:/image/gray.png)");
                break;
            }
            case(3):{
                //闲家4 输

                result_list[quarter]->four->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->four->setStyleSheet("image: url(:/image/gray.png)");
                break;
            }
            case(4):{
                //闲家5 输

                result_list[quarter]->five->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->five->setStyleSheet("image: url(:/image/gray.png)");
                break;
            }
            case(5):{
                //闲家6 输

                result_list[quarter]->six->setText(PaixingToResult(vec[i].paiXing));
                result_list[quarter]->six->setStyleSheet("image: url(:/image/gray.png)");
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

void MainWindow::update_date(){
    ui->label_date->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd    dddd    hh:mm:ss"));
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
            result_list.at(quarter)->zhuang->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->one->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->two->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->three->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->four->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->five->setStyleSheet("image: url(:/useless.png)");
            result_list.at(quarter)->six->setStyleSheet("image: url(:/useless.png)");
        }
        else{
            // 庄家点数
            QString PaiXing = array.at(i)["bankernum"].toString();
            // 刷新显示
            result_list.at(quarter)->zhuang->setText(PaiXing);
            // 闲家1点数
            PaiXing = array.at(i)["x1num"].toString();
            result_list.at(quarter)->one->setText(PaiXing);
            if(array.at(i)["x1result"].toString() == "win"){
                result_list.at(quarter)->one->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->one->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家2点数
            PaiXing = array.at(i)["x2num"].toString();
            result_list.at(quarter)->two->setText(PaiXing);
            if(array.at(i)["x2result"].toString() == "win"){
                result_list.at(quarter)->two->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->two->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家3点数
            PaiXing = array.at(i)["x3num"].toString();
            result_list.at(quarter)->three->setText(PaiXing);
            if(array.at(i)["x3result"].toString() == "win"){
                result_list.at(quarter)->three->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->three->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家4点数
            PaiXing = array.at(i)["x4num"].toString();
            result_list.at(quarter)->four->setText(PaiXing);
            if(array.at(i)["x4result"].toString() == "win"){
                result_list.at(quarter)->four->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->four->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家5点数
            PaiXing = array.at(i)["x5num"].toString();
            result_list.at(quarter)->five->setText(PaiXing);
            if(array.at(i)["x5result"].toString() == "win"){
                result_list.at(quarter)->five->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->five->setStyleSheet("image: url(:/image/gray.png)");
            }
            // 闲家6点数
            PaiXing = array.at(i)["x6num"].toString();
            result_list.at(quarter)->six->setText(PaiXing);
            if(array.at(i)["x6result"].toString() == "win"){
                result_list.at(quarter)->six->setStyleSheet("image: url(:/image/blue.png)");
            }
            else{
                result_list.at(quarter)->six->setStyleSheet("image: url(:/image/gray.png)");
            }
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
    ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    // 倒计时中
    unsigned int time = end - start;
    count_down = count_down_num - time;
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
        ui->label_locate->setText("");
        ui->pu_start->setEnabled(false);
        ui->who_win->setText(QString(""));
        count_down = count_down_num;
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
        count_down_num = data.at(0)["CountDown"].toInt();
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
        ui->four_win_times->setText(QString::number(four));
        ui->five_win_times->setText(QString::number(five));
        ui->six_win_times->setText(QString::number(six));

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
        for(int i = 0;i < 20;i++){
            result_list[i]->zhuang->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->one->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->two->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->three->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->four->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->five->setStyleSheet("image: url(:/image/blue.png)");
            result_list[i]->six->setStyleSheet("image: url(:/image/blue.png)");
        }
        ui->one_win_times->setText("");
        ui->two_win_times->setText("");
        ui->three_win_times->setText("");
        ui->four_win_times->setText("");
        ui->five_win_times->setText("");
        ui->six_win_times->setText("");
        quarter = 0;
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

//void MainWindow::finishedSlot(QNetworkReply* reply)
//{
//    if (reply->error() == QNetworkReply::NoError) {
//            QByteArray bytes = reply->readAll();
//            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
//            QJsonObject json_object2 = json_object.value("data").toObject();

//            if (m_post_type == QString("start")) {
//                QString         info = json_object.value("info").toString();
//                unsigned int    status = json_object.value("status").toInt();

//                qDebug() << info  << endl;
//                qDebug() << status  << endl;
//                //M 应用靴次和铺次
//                if(status == 1){
//                    // 开始请求成功
//                    // 应用靴次和铺次
//                    unsigned int    boot_num = json_object2.value("boot_num").toInt();
//                    unsigned int    pave_num = json_object2.value("pave_num").toInt();
//                    ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
//                    ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));

//                    // 禁用开始按钮
//                    ui->pu_start->setEnabled(false);
//                    ui->who_win->setText(QString(""));
//                    timer_Countdown->start(1000);
//                    // 倒计时恢复为 30
//                    count_down = 30;
//                }
//                else{
//                    // 开始请求失败
//                    // 启用开始按钮
//                    ui->pu_start->setEnabled(true);

//                    // 报告错误
//                    QMessageBox box;
//                    box.setText("请求开局失败");
//                    box.exec();
//                }
//            }
//            else if(m_post_type == "room_card"){
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();
//                qDebug() << "info : " << info << "  sttus : " << status;
//                if(status == 1){
//                    QString l = json_object2.value("LocationNum").toString();
//                    qDebug() << "location : " << l;
//                    location = l.toInt();
//                    ui->label_locate->setText(l);
//                    if(location == 0){
//                        ui->button_locate->setEnabled(true);
//                    }
//                    else{
//                        QJsonArray zhuang = json_object2.value("BankerCard").toArray();
//                        QJsonArray one = json_object2.value("IdleOneCard").toArray();
//                        QJsonArray two = json_object2.value("IdleTwoCard").toArray();
//                        QJsonArray three = json_object2.value("IdleThreeCard").toArray();
//                        QJsonArray four = json_object2.value("IdleFourCard").toArray();
//                        QJsonArray five = json_object2.value("IdleFiveCard").toArray();
//                        QJsonArray six = json_object2.value("IdleSixCard").toArray();
//                        on_room_card(zhuang,one,two,three,four,five,six);
//                        ui->button_useless->setEnabled(true);
//                    }
//                }
//                else{
//                    // 游戏记录信息请求失败
//                    QMessageBox box;
//                    box.setText("本局游戏信息请求失败");
//                    box.exec();
//                }
//            } else if (m_post_type == QString("locate")) {
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();

//                if(status == 1){
//                    // 定位请求成功
//                    m_fapai = true;
//                    this->locate_success();
//                }
//                else{
//                    // 定位请求失败
//                    // 启用定位按钮
//                    ui->button_locate->setEnabled(true);

//                    // 提示错误
//                    QMessageBox box;
//                    box.setText("定位请求失败");
//                    box.exec();
//                }

//            } else if (m_post_type == QString("fapai")) {
//                QString info = json_object.value("info").toString();
//               // unsigned int status = json_object.value("status").toInt();
//                if(1){
//                    // M 更新荷官端显示牌
//                    m_fapai = true;
//                    // 更新牌
//                    wait(strToCard(m_edit_last.toStdString()));
//                }
//                else{
//                    // 将扫码机设为空字符串，等待重新扫码
//                    m_edit_last = "";
//                    // 提示重新扫码
//                    QMessageBox box;
//                    box.setText("刷牌失败");
//                    box.exec();
//                }
//            } else if (m_post_type == QString("summit")) {
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();
//                qDebug() << "summit : " << info << " - " << status;
//                if( 1){
//                    // 提交请求成功
//                    this->on_summit();
//                }
//                else{
//                    // 提交请求失败
//                    // 重新启用提交按钮
//                    ui->button_summit->setEnabled(true);

//                    // 提示重新提交
//                    QMessageBox box;
//                    box.setText("提交请求失败");
//                    box.exec();
//                }
//            } else if (m_post_type == QString("useless")) {
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();
//                if(status == 1){
//                    // 作废请求成功
//                    this->on_useless();
//                }
//                else{
//                    ui->button_useless->setEnabled(true);

//                    // 提示作废失败
//                    QMessageBox box;
//                    box.setText("作废失败");
//                    box.exec();
//                    return;
//                }
//            }
//            else if(m_post_type == QString("roominfo")){
//                // 响应房间信息
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();

//                if(status == 1){
//                    QJsonArray json_array = json_object.value("data").toArray();
//                    // 刷新靴次
//                    unsigned int boot_num = json_array.at(0)["BootNum"].toInt(); //json_object2.value("BootNum").toInt();
//                    qDebug() << "boot_room : " << boot_num;
//                    ui->xue_times->setText(QString::number(boot_num));
//                    // 刷新铺次
//                    unsigned int PaveNum = json_array.at(0)["PaveNum"].toInt(); //json_object2.value("PaveNum").toInt();
//                    ui->pu_times->setText(QString::number(PaveNum));
//                    qDebug() << "PaveNum : " << PaveNum;
//                    // 刷新台桌
//                    QString DeskName = json_array.at(0)["DeskName"].toString(); //json_object2.value("DeskName").toString();
//                    ui->desk_num->setText(DeskName);
//                    qDebug() << "desk id : " << DeskName;
//                    // 获取时间戳
//                    unsigned int GameStarTime = json_array.at(0)["GameStarTime"].toInt(); //json_object2.value("GameStarTime").toInt();
//                    unsigned int Systime = json_array.at(0)["Systime"].toInt();
//                    // 获取房间状态
//                    unsigned int phase = json_array.at(0)["Phase"].toInt();
//                    qDebug() << "phase : " << phase;
//                    switch (phase) {
//                    case 0:
//                        // 洗牌中
//                        phase_zero();
//                        break;
//                    case 1:
//                        // 倒计时
//                        phase_countDown(GameStarTime,Systime);
//                        break;
//                    case 2:
//                        // 开牌中
//                        phase_kaiPai();
//                        break;
//                    case 3:
//                        // 结算完成
//                        phase_finish();
//                        break;
//                    }
//                }
//                else{
//                    QMessageBox box;
//                    box.setText("获取房间信息失败");
//                    box.exec();
//                }
//            }
//            else if(m_post_type == QString("record")){
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();

//                if(status == 1){
//                    QJsonArray json_array = json_object.value("data").toArray();
//                    QJsonArray array = json_array.at(0)["list"].toArray();

//                    // 应用赢得次数
//                    // 闲家1
//                    unsigned int x1wincount = json_array.at(0)["x1wincount"].toInt();
//                    ui->one_win_times->setText(QString::number(x1wincount));
//                    // 闲家2
//                    unsigned int x2wincount = json_array.at(0)["x2wincount"].toInt();
//                    ui->two_win_times->setText(QString::number(x2wincount));
//                    // 闲家3
//                    unsigned int x3wincount = json_array.at(0)["x3wincount"].toInt();
//                    ui->three_win_times->setText(QString::number(x3wincount));
//                    // 闲家4
//                    unsigned int x4wincount = json_array.at(0)["x4wincount"].toInt();
//                    ui->one_win_times->setText(QString::number(x4wincount));
//                    // 闲家5
//                    unsigned int x5wincount = json_array.at(0)["x5wincount"].toInt();
//                    ui->two_win_times->setText(QString::number(x5wincount));
//                    // 闲家6
//                    unsigned int x6wincount = json_array.at(0)["x6wincount"].toInt();
//                    ui->three_win_times->setText(QString::number(x6wincount));


//                    on_game_record(array);
//                    request_room_info();
//                }
//                else{
//                    // 游戏记录信息请求失败
//                    QMessageBox box;
//                    box.setText("游戏记录信息请求失败");
//                    box.exec();
//                }
//            }
//            else if(m_post_type == QString("end")){
//                //? 终止的接口
//                qDebug() << "endyes";
//            }else if(m_post_type == QString("init")){
//                QString info = json_object.value("info").toString();
//                unsigned int status = json_object.value("status").toInt();
//                if(status == 1){
//                    // 初始化请求成功
//                    // 应用靴次和铺次
//                    unsigned int boot_num = json_object2.value("boot_num").toInt();
//                    unsigned int pave_num = json_object2.value("pave_num").toInt();
//                    ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
//                    ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));

//                }
//                else{
//                    // 初始化请求失败
//                    QMessageBox box;
//                    box.setText("初始化失败");
//                    box.exec();
//                }
//            }
//        }
//         else
//         {
//             qDebug() << "finishedSlot errors here";
//             qDebug( "found error .... code: %d\n", (int)reply->error());
//             qDebug() << reply->errorString();

//             QMessageBox box;
//             box.setText("网络连接错误");
//             box.exec();
//             return;
//         }
//         reply->deleteLater();
//}

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
    this->setFocus();
    // 启用定位，禁用提交
    ui->button_summit->setEnabled(false);

    // 停止闪烁
    timer_opacity->stop();

    // 该把作废了
    result_list.at(quarter)->zhuang->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->one->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->two->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->three->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->four->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->five->setStyleSheet("image: url(:/useless.png)");
    result_list.at(quarter)->six->setStyleSheet("image: url(:/useless.png)");

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

void MainWindow::quarter_increase()
{
    if(quarter < 19){
        quarter++;
    }
    else{
        for(int q = 0;q < 19;q++){
            result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
            result_list[q]->one->setText(result_list[q+1]->one->text());
            result_list[q]->two->setText(result_list[q+1]->two->text());
            result_list[q]->three->setText(result_list[q+1]->three->text());
            result_list[q]->four->setText(result_list[q+1]->four->text());
            result_list[q]->five->setText(result_list[q+1]->five->text());
            result_list[q]->six->setText(result_list[q+1]->six->text());

            result_list[q]->zhuang->setStyleSheet(result_list[q+1]->zhuang->styleSheet());
            result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());
            result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());
            result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
            result_list[q]->four->setStyleSheet(result_list[q+1]->four->styleSheet());
            result_list[q]->five->setStyleSheet(result_list[q+1]->five->styleSheet());
            result_list[q]->six->setStyleSheet(result_list[q+1]->six->styleSheet());
        }
        result_list[19]->zhuang->setText("");
        result_list[19]->one->setText("");
        result_list[19]->two->setText("");
        result_list[19]->three->setText("");
        result_list[19]->four->setText("");
        result_list[19]->five->setText("");
        result_list[19]->six->setText("");

        result_list[19]->zhuang->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->four->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->five->setStyleSheet("image: url(:/image/blue.png)");
        result_list[19]->six->setStyleSheet("image: url(:/image/blue.png)");
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

