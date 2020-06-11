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

#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
  //  , m_edit_string("")
    , m_edit_last("")
{
   ui->setupUi(this);
   //ui->lineEdit->setFocus();
   ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

   timer_focus = new QTimer(this);
   connect(timer_focus, SIGNAL(timeout()), this, SLOT(update()));
   ui->button_locate->setFocus();

   timer_opacity = new QTimer(this);
   timer_date = new QTimer(this);
   //connect(timer_opacity, SIGNAL(timeout()), this, SLOT(on_timeout()));
   //timer_opacity->start(10);

   m_graphiceffect = new QGraphicsOpacityEffect;
   m_light = false;
   n_graphiceffect = new QGraphicsOpacityEffect;

   connect(ui->pu_start, SIGNAL(clicked()), this, SLOT(pu_start()));
   connect(ui->pu_stop, SIGNAL(clicked()), this, SLOT(pu_stop()));

   connect(timer_opacity, SIGNAL(timeout()), this, SLOT(on_timeout()));
   connect(ui->button_locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
   connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(line_finish()));
   connect(ui->button_summit,SIGNAL(clicked()),this,SLOT(on_summit()));
   connect(timer_date,SIGNAL(timeout()),this,SLOT(update_date()));
   timer_date->start(200);
   connect(ui->pu_exit,SIGNAL(clicked()),this,SLOT(on_exit()));
   connect(ui->button_useless,SIGNAL(clicked()),this,SLOT(on_useless()));

   //M 连接所有按钮的按下和松开的槽函数
   connect(ui->button_useless,SIGNAL(pressed()),this,SLOT(useless_pressed()));
   connect(ui->button_useless,SIGNAL(released()),this,SLOT(useless_released()));
   connect(ui->button_locate,SIGNAL(pressed()),this,SLOT(locate_pressed()));
   connect(ui->button_locate,SIGNAL(released()),this,SLOT(locate_released()));
   connect(ui->button_summit,SIGNAL(pressed()),this,SLOT(summit_pressed()));
   connect(ui->button_summit,SIGNAL(released()),this,SLOT(summit_released()));
   connect(ui->pu_stop,SIGNAL(pressed()),this,SLOT(stop_pressed()));
   connect(ui->pu_stop,SIGNAL(released()),this,SLOT(stop_released()));
   connect(ui->xue_change,SIGNAL(pressed()),this,SLOT(change_pressed()));
   connect(ui->xue_change,SIGNAL(released()),this,SLOT(change_released()));
   connect(ui->pu_start,SIGNAL(pressed()),this,SLOT(start_pressed()));
   connect(ui->pu_start,SIGNAL(released()),this,SLOT(start_released()));
   //M 开始按钮
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(on_start()));
    //M 倒计时计数器
    timer_Countdown = new QTimer(this);
    count_down = 15;
    connect(timer_Countdown,SIGNAL(timeout()),this,SLOT(on_count_down()));

   QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);
   connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));

   QNetworkRequest request;m_edit_last = QString("");
   request.setUrl(QUrl("http://192.168.0.106:8210/lh_desk_ini"));

   //get
   //accessManager->get(request);

   QByteArray postData;
   postData.append("username=admin&password=123456");

  //post
  QNetworkReply* reply = accessManager->post(request, postData);


  //M
  //闲家一
  head = new players;
  head->num = 0;
  head->data[0].label = ui->one_one_pic;
  head->data[1].label = ui->one_two_pic;
  head->data[2].label = ui->one_three_pic;
  head->data[3].label = ui->one_four_pic;
  head->data[4].label = ui->one_five_pic;
  //闲家二
  players *er = new players;
  er->num = 1;
  er->data[0].label = ui->two_one_pic;
  er->data[1].label = ui->two_two_pic;
  er->data[2].label = ui->two_three_pic;
  er->data[3].label = ui->two_four_pic;
  er->data[4].label = ui->two_four_pic_2;//?
  head->next = er;
  //闲家三
  players *san = new players;
  san->num = 2;
  san->data[0].label = ui->three_one_pic;
  san->data[1].label = ui->three_two_pic;
  san->data[2].label = ui->three_three_pic;
  san->data[3].label = ui->three_four_pic;
  san->data[4].label = ui->three_five_pic;
  er->next = san;
  //庄家
  players *zhuang = new players;
  zhuang->num = 3;
  zhuang->data[0].label = ui->zhuang_one_pic;
  zhuang->data[1].label = ui->zhuang_two_pic;
  zhuang->data[2].label = ui->zhuang_three_pic;
  zhuang->data[3].label = ui->zhuang_four_pic;
  zhuang->data[4].label = ui->zhuang_five_pic;
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
int FiveBull(CARD player[]){
    //炸弹判断
    int shuLiang[5] = {0};
    int count = 0,c = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            if(player[i].face == player[j].face){
                shuLiang[i]++;
                if(c < shuLiang[i]){
                    c = shuLiang[i];
                    //炸弹
                    if(c == 4){
                        return 12;
                    }
                }
            }
        }
        if(player[i].hua){
            count++;
            //五花牛
            if(count == 5){
                return 11;
            }
        }
    }
    return -1;
}

//牛几 ,10 为 牛 10
int BullCount(CARD player[]){
    for(int one = 0;one <= 2;one++){
        for(int two = one + 1;two <= 3;two++){
            for(int three = two + 1;three <= 4;three++){
                if((player[one].num + player[two].num + player[three].num) % 10 == 0){
                    vector<int> vec = {0,1,2,3,4};
                    vec.erase(vec.begin() + one);
                    vec.erase(vec.begin() + two - 1);
                    vec.erase(vec.begin() + three - 2);
                    int m = (player[vec[0]].num + player[vec[1]].num) % 10;
                    if(m == 0){
                        return 10;
                    }
                    return m;
                }
            }
        }
    }
    return -1;
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
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4-i;j++){
            //先判断下一个牌的值是否大于这个牌的值
            if(dianShu(player[j].face) > dianShu(player[j + 1].face)){
                CARD temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
            //如果上面的if语句执行了，则说明值不一样,那么下面这个if不会成立
            if(dianShu(player[j].face) == dianShu(player[j + 1].face) && player[j].color > player[j + 1].color){
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
    r.biggest = player[4];//由于paixu() 函数已经将最大的牌放到最后一个了，所以直接获取就行

    r.paiXing = FiveBull(player);
    if(r.paiXing == -1){
        r.paiXing = BullCount(player);
    }
    if(r.paiXing == -1){
        r.paiXing = dianShu(r.biggest.face) - 14;//用于后面比较牌型
    }
    return r;
}

void MainWindow::locate(){
    for(int j = 2;j <= location;j++){
      head = head->next;
    }
}
//1 2 3 4 1 2 3 4

void MainWindow::flash()
{

}

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

void MainWindow::wait(CARD card){
    head->data[number.num].hua = card.hua;
    head->data[number.num].num = card.num;
    head->data[number.num].face = card.face;
    head->data[number.num].color = card.color;
    if(number.num == 4){
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
            ui->zhuang_result->setText(QString::fromStdString(PaiXingToStr(PaiXing(head->data).paiXing)));
            break;
        }
    }
    head = head->next;
    number.increase();
    if(number.num == 5){
        // 提交按钮启用
        ui->button_summit->setEnabled(true);
        ui->button_summit->setFocus();
        summit_released();
        //M
        timer_focus->stop();
        n_graphiceffect->setOpacity(1);
        label_name->setGraphicsEffect(n_graphiceffect);
        if(location % 4 == 0){
            label_name->setStyleSheet("color: rgb(255, 0, 0)");
        }
        else{
            label_name->setStyleSheet("color: rgb(255, 255, 255)");
        }
    }
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
           if(number.num == 5){
               return;
           }
           if(m_edit_last.size() == 3){
               head->data[number.num].label->setStyleSheet("image: url(:/image/pukepai/" + str +".png)");
               wait(strToCard(m_edit_last.toStdString()));
           }
       }
       //M
       ui->lineEdit->setText(QString(""));
    }
}

//若前者大，则返回true，否则返回false
bool Bigger(PAIRESULT player_1,PAIRESULT player_2){
    if(player_1.paiXing > player_2.paiXing){
        return true;
    }
    if(player_1.paiXing == player_2.paiXing){
        if(dianShu(player_1.biggest.face) > dianShu(player_2.biggest.face)){
            return true;
        }
        if(dianShu(player_1.biggest.face) == dianShu(player_2.biggest.face)){
            return player_1.biggest.color > player_2.biggest.color ? true : false;
        }
        return false;
    }
    return false;
}

QString PaixingToResult(int i){
    if(i < 0){
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
    PAIRESULT vec[3] = {};
    QString result = "";

    for(int i = 0;i < 4;i++){
        PAIRESULT result = PaiXing(head->data);
        if(head->num == 3){
            zhuang = result;
        }
        else{
            vec[head->num] = result;
        }
        head = head->next;
    }

    //所有牌型收集完毕，开始比较
    //庄家结果
    if(quarter <= 19){
        result_list[quarter]->zhuang->setText(PaixingToResult(zhuang.paiXing));
    }
    else{
        for(int q = 0;q < 19;q++){
            result_list[q]->zhuang->setText(result_list[q+1]->zhuang->text());
            result_list[q]->zhuang->setStyleSheet(result_list[q]->zhuang->styleSheet());
        }
        result_list[19]->zhuang->setText(PaixingToResult(zhuang.paiXing));
        result_list[19]->zhuang->setStyleSheet("image: url(:/image/red.png)");
    }

    for(int i = 0;i < 3;i++){
        if(!Bigger(zhuang,vec[i])){
            switch (i) {
            case(0):{
                //闲家1 赢
                result += "闲家1 ";
                int j = stoi(ui->one_win_times->text().toStdString());
                ui->one_win_times->setText(QString::fromStdString(to_string(j+1)));

                if(quarter <= 19){
                    result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->one->setStyleSheet("image: url(:/image/blue.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->one->setText(result_list[q+1]->one->text());
                        result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());
                    }
                    result_list[19]->one->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->one->setStyleSheet("image: url(:/image/blue.png)");
                }

                break;
            }
            case(1):{
                //闲家2 赢
                result += "闲家2 ";
                int j = stoi(ui->two_win_times->text().toStdString());
                ui->two_win_times->setText(QString::fromStdString(to_string(j+1)));

                if(quarter <= 19){
                    result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->two->setStyleSheet("image: url(:/image/blue.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->two->setText(result_list[q+1]->two->text());
                        result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());
                    }
                    result_list[19]->two->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->two->setStyleSheet("image: url(:/image/blue.png)");
                }
                break;
            }
            case(2):{
                //闲家3 赢
                result += "闲家3 ";
                int j = stoi(ui->three_win_times->text().toStdString());
                ui->three_win_times->setText(QString::fromStdString(to_string(j+1)));

                if(quarter <= 19){
                    result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->three->setStyleSheet("image: url(:/image/blue.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->three->setText(result_list[q+1]->three->text());
                        result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
                    }
                    result_list[19]->three->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->three->setStyleSheet("image: url(:/image/blue.png)");
                }

                break;
            }
            }
        }
        else{
            switch (i) {
            case(0):{
                //闲家1 输

                if(quarter <= 19){
                    result_list[quarter]->one->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->one->setStyleSheet("image: url(:/image/gray.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->one->setText(result_list[q+1]->one->text());
                        result_list[q]->one->setStyleSheet(result_list[q+1]->one->styleSheet());
                    }
                    result_list[19]->one->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->one->setStyleSheet("image: url(:/image/gray.png)");
                }

                break;
            }
            case(1):{
                //闲家2 输

                if(quarter <= 19){
                    result_list[quarter]->two->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->two->setStyleSheet("image: url(:/image/gray.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->two->setText(result_list[q+1]->two->text());
                        result_list[q]->two->setStyleSheet(result_list[q+1]->two->styleSheet());
                    }
                    result_list[19]->two->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->two->setStyleSheet("image: url(:/image/gray.png)");
                }


                break;
            }
            case(2):{
                //闲家3 输

                if(quarter <= 19){
                    result_list[quarter]->three->setText(PaixingToResult(vec[i].paiXing));
                    result_list[quarter]->three->setStyleSheet("image: url(:/image/gray.png)");
                }
                else{
                    for(int q = 0;q < 19;q++){
                        result_list[q]->three->setText(result_list[q+1]->three->text());
                        result_list[q]->three->setStyleSheet(result_list[q+1]->three->styleSheet());
                    }
                    result_list[19]->three->setText(PaixingToResult(vec[i].paiXing));
                    result_list[19]->three->setStyleSheet("image: url(:/image/gray.png)");
                }
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

    quarter++;
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
    if(number.num == 5){
        i = 1;
        m_graphiceffect->setOpacity(i);
        head->data[4].label->setGraphicsEffect(m_graphiceffect);
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

void MainWindow::pu_start()
{

}

void MainWindow::pu_stop()
{

}

void MainWindow::pu_locate()
{
    //timer_focus->stop();//应该stop了两遍
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setVisible(true);
    // 禁用定位按钮，把按钮变成灰色
    ui->button_locate->setEnabled(false);
    ui->button_locate->setStyleSheet("border-radius:5px; \
                                     color: rgb(0, 255, 0); \
                                     background-color: rgb(125, 125, 125); \
                                     color: rgb(255, 255, 255);");
}

void MainWindow::LabelPaixu(players *head){
    //闲家一
    head->data[0].label = ui->one_one_pic;
    head->data[1].label = ui->one_two_pic;
    head->data[2].label = ui->one_three_pic;
    head->data[3].label = ui->one_four_pic;
    head->data[4].label = ui->one_five_pic;
    head = head->next;
    //闲家二
    head->data[0].label = ui->two_one_pic;
    head->data[1].label = ui->two_two_pic;
    head->data[2].label = ui->two_three_pic;
    head->data[3].label = ui->two_four_pic;
    head->data[4].label = ui->two_four_pic_2;//?
    head = head->next;
    //闲家三
    head->data[0].label = ui->three_one_pic;
    head->data[1].label = ui->three_two_pic;
    head->data[2].label = ui->three_three_pic;
    head->data[3].label = ui->three_four_pic;
    head->data[4].label = ui->three_five_pic;
    head = head->next;
    //庄家
    head->data[0].label = ui->zhuang_one_pic;
    head->data[1].label = ui->zhuang_two_pic;
    head->data[2].label = ui->zhuang_three_pic;
    head->data[3].label = ui->zhuang_four_pic;
    head->data[4].label = ui->zhuang_five_pic;
    head = head->next;
}

void MainWindow::line_finish()
{
    bool ok = false;
    location = ui->lineEdit_2->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        //提示
        return;
    }
    ui->lineEdit->setFocus();
    timer_focus->start(200);
    QString str = ui->lineEdit_2->text();
    ui->label_locate->setText(str);
    ui->lineEdit_2->setVisible(false);
    locate();
    timer_opacity->start(10);

    ui->button_locate->setEnabled(false);
    // 废除按钮启用，恢复颜色;
    ui->button_useless->setEnabled(true);
    useless_released();
    // 名字开始闪烁
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

void update_result_labels(int ){

}

void MainWindow::on_summit()
{
    timer_opacity->stop();

    //遍历清空节点
    players *node = head;
    do{
        for(int i = 0;i < 5;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    for(int i = location % 4 + 3; i % 4 != 0;i++){
        head = head->next;
    }

    number.man = 0;
    number.num = 0;
    ui->button_locate->setFocus();
    ui->button_locate->setEnabled(true);
    ui->button_summit->setEnabled(false);

    //牌型清空
    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));
    result();

    LabelPaixu(head);
    m_edit_last = QString("");

    //显示已完结
    ui->opration_show->setText(QString("已完结"));
    //增加铺次
    int i = stoi(ui->pu_times->text().toStdString());
    ui->pu_times->setText(QString::fromStdString(to_string(i + 1)));
    //清空定位
    ui->label_locate->setText(QString(""));

}

void MainWindow::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
     {
         QByteArray bytes = reply->readAll();
         qDebug() << bytes;
     }
     else
     {
         qDebug() << "finishedSlot errors here";
         qDebug( "found error .... code: %d\n", (int)reply->error());
         qDebug() << reply->errorString();
     }
     reply->deleteLater();
}

void MainWindow::on_exit(){
    ui->pu_start->setDown(true);
    this->close();
}

void MainWindow::on_useless(){
    //停止闪烁
    timer_opacity->stop();
    //恢复透明度

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

    //遍历清空节点
    players *node = head;
    do{
        for(int i = 0;i < 5;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    //head 归位
    for(int i = location % 4 + 3; i % 4 != 0;i++){
        head = head->next;
    }

    number.man = 0;
    number.num = 0;
    ui->button_locate->setFocus();
    ui->button_locate->setEnabled(true);
    ui->button_summit->setEnabled(false);

    // 牌型清空
    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    LabelPaixu(head);
    m_edit_last = QString("");

    // 作废按钮禁用，颜色变灰
    ui->button_useless->setEnabled(false);
    ui->button_useless->setStyleSheet("border-radius:5px; \
                                      color: rgb(0, 255, 0); \
                                      background-color: rgb(125, 125, 125); \
                                      color: rgb(255, 255, 255);");
}

void MainWindow::useless_pressed()
{
    ui->button_useless->setStyleSheet("border-radius:5px; \
                                      color: rgb(0, 255, 0); \
                                      background-color: rgb(0, 0, 200); \
                                      color: rgb(255, 255, 255);");
}

void MainWindow::useless_released()
{
    ui->button_useless->setStyleSheet("border-radius:5px; \
                                      color: rgb(0, 255, 0); \
                                      background-color: rgb(0, 0, 255); \
color: rgb(255, 255, 255);");
}

void MainWindow::locate_pressed()
{
    ui->button_locate->setStyleSheet("border-radius:5px; \
                                     border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255)); \
                                     background-color: rgb(200, 0, 0); \
                                     color: rgb(255, 255, 255);");
}

void MainWindow::locate_released()
{
    ui->button_locate->setStyleSheet("border-radius:5px; \
                                     border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255)); \
                                     background-color: rgb(255, 0, 0); \
color: rgb(255, 255, 255);");
}

void MainWindow::summit_pressed()
{
    ui->button_summit->setStyleSheet("border-radius:5px; \
                                     background-color: rgb(0, 120, 200); \
                                     color: rgb(255, 255, 255);");
}

void MainWindow::summit_released()
{
    ui->button_summit->setStyleSheet("border-radius:5px; \
                                     background-color: rgb(0, 170, 255); \
            color: rgb(255, 255, 255);");
}

void MainWindow::exit_pressed()
{
    ui->pu_exit->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 120, 200); \
                               color: rgb(255, 255, 255);");
}

void MainWindow::exit_released()
{
    ui->pu_exit->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 170, 255); \
            color: rgb(255, 255, 255);");
}

void MainWindow::stop_pressed()
{
    ui->pu_stop->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 120, 200); \
                               color: rgb(255, 255, 255);");
}

void MainWindow::stop_released()
{
    ui->pu_stop->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 170, 255); \
            color: rgb(255, 255, 255);");
}

void MainWindow::change_pressed()
{
    ui->xue_change->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 120, 200); \
                               color: rgb(255, 255, 255);");
}

void MainWindow::change_released()
{
    ui->xue_change->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 170, 255); \
            color: rgb(255, 255, 255);");
}

void MainWindow::start_pressed()
{
    ui->pu_start->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 120, 200); \
                               color: rgb(255, 255, 255);");
}

void MainWindow::start_released()
{
    ui->pu_start->setStyleSheet("border-radius:5px; \
                               background-color: rgb(0, 170, 255); \
            color: rgb(255, 255, 255);");
}

void MainWindow::on_start()
{
    // 禁用开始按钮
    ui->pu_start->setEnabled(false);
    ui->pu_start->setStyleSheet("border-radius:5px; \
                                border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255)); \
                                color: rgb(255, 255, 255); \
                                background-color: rgb(125, 125, 125);");
    timer_Countdown->start(1000);
}

void MainWindow::on_count_down()
{
    qDebug() << count_down;
    ui->who_win->setText(QString::fromStdString(to_string(count_down)));
    if(count_down-- == 0){
        timer_Countdown->stop();
        ui->who_win->setText(QString(""));
        ui->button_locate->setEnabled(true);
        locate_released();
    }
}

