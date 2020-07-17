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

enum {LOGIN,START,ROOMINFO,ROOMCARD,RECORD,LOCATE,FAPAI,SUMMIT,USELESS,INIT,END};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_fapai(false)
    , m_edit_last("")
{
    ui->setupUi(this);

    ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    timer_focus = new QTimer(this);

    // 设置焦点到 定位按钮
    ui->button_locate->setFocus();
    timer_opacity = new QTimer(this);
    timer_Countdown = new QTimer(this);
    timer_date = new QTimer(this);

    m_light = false;
    m_graphiceffect = new QGraphicsOpacityEffect;
    n_graphiceffect = new QGraphicsOpacityEffect;

    timer_date->start(200);

    login_window = new Login();

    _map.insert(LOGIN,&MainWindow::responsed_login);
    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(ROOMCARD,&MainWindow::responsed_roomcard);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(LOCATE,&MainWindow::responsed_locate);
    _map.insert(FAPAI,&MainWindow::responsed_fapai);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(END,&MainWindow::responsed_end);

    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    connect(ui->pu_end,SIGNAL(clicked()),this,SLOT(pu_end()));
    connect(ui->pu_exit,SIGNAL(clicked()),this,SLOT(pu_exit()));
    connect(ui->button_locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
    connect(ui->button_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(ui->button_summit,SIGNAL(clicked()),this,SLOT(pu_summit()));
    connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(when_line_finish()));
    connect(timer_opacity, SIGNAL(timeout()), this, SLOT(when_timeout()));
    connect(timer_focus, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer_date,SIGNAL(timeout()),this,SLOT(update_date()));
    connect(timer_Countdown,SIGNAL(timeout()),this,SLOT(when_count_down()));
    connect(login_window->get_login_Button(),SIGNAL(clicked()),this,SLOT(pu_login()));


    manager = new MNetManager;
    manager->setHeader("application/x-www-form-urlencoded");
    manager->setIp("101.32.22.231:8210");
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

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
           m_edit_last = str;
           if(number.num == 2){
               return;
           }
           if((m_edit_last.size() == 3) && m_fapai){
               request_faPai(strToCard(m_edit_last.toStdString()));
           }
       }
       ui->lineEdit->setText(QString(""));
    }
}

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
        int win_times = ui->one_win_times->text().toInt();
        ui->one_win_times->setText(QString::number(win_times + 1));
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
        int win_times = ui->two_win_times->text().toInt();
        ui->two_win_times->setText(QString::number(win_times + 1));
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
        int win_times = ui->three_win_times->text().toInt();
        ui->three_win_times->setText(QString::number(win_times + 1));
    }
    else{
        // 反门输
        result_list[quarter]->three->setText(FanMen);
        result_list[quarter]->three->setStyleSheet("image: url(:/image/gray.png)");
    }


    quarter_increase();
}

void MainWindow::update_focus()
{
    ui->lineEdit->setFocus();
}

void MainWindow::update_date(){
    ui->label_date->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd    dddd    hh:mm:ss"));
}

void MainWindow::when_timeout()
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

void MainWindow::when_count_down()
{
    ui->who_win->setText(QString::number(count_down));
    count_down--;

    if(count_down == -1){
        timer_Countdown->stop();
        ui->who_win->setText(QString(""));
        ui->button_locate->setEnabled(true);
    }
}

void MainWindow::when_line_finish()
{
    bool ok = false;
    location = ui->lineEdit_2->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        QMessageBox box;
        box.setText("输入的定位无效");
        box.exec();
        return;
    }
    request_locate();
}

void MainWindow::pu_login()
{
    request_login();
}

void MainWindow::pu_init()
{
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        request_init();
    }
}

void MainWindow::pu_start()
{
    ui->pu_start->setEnabled(false);
    request_start();
}

void MainWindow::pu_change_boot()
{

}

void MainWindow::pu_end()
{

}

//void MainWindow::pu_end()
//{
//    // 请求终止
//    int choose = QMessageBox::question(this,QString("终止"),QString("确认终止？"),QMessageBox::Yes | QMessageBox::No);
//    if(choose == QMessageBox::Yes){
//        // 发送请求
//        m_post_type = QString("end");
//        m_request->setUrl(QUrl("http://" + URL + "/GetGameOver"));
//        QByteArray postData;
//        postData.append("boot_num=");postData.append(ui->pu_times->text());
//        m_accessManager->post(*m_request, postData);
//    }
//}

void MainWindow::pu_locate()
{
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setVisible(true);

    ui->button_locate->setEnabled(false);
}

void MainWindow::pu_summit()
{
    ui->button_summit->setEnabled(false);
    request_summit();
}

void MainWindow::on_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three,string zhuang_result,string one_result,string two_result,string three_result)
{
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

void MainWindow::phase_zero()
{
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    unsigned int time = end - start;
    count_down = 30 - time;
    timer_Countdown->start(1000);
}

void MainWindow::phase_kaiPai()
{
    // 开牌中
    request_roomcard();
}

void MainWindow::phase_finish()
{
    // 结算完成
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::apply_locate()
{
    ui->lineEdit->setFocus();
    timer_focus->start(200);

    QString str = ui->lineEdit_2->text();
    ui->label_locate->setText(str);
    ui->lineEdit_2->setVisible(false);

    for(int j = 2;j <= location;j++){
      head = head->next;
    }

    timer_opacity->start(10);
    ui->button_locate->setEnabled(false);
    ui->button_useless->setEnabled(true);

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

    ui->opration_show->setText("停止下注");
}

void MainWindow::apply_summit()
{
    timer_opacity->stop();

    players *node = head;
    do{
        for(int i = 0;i < 2;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    while(head->player != "ShunMen"){
        head = head->next;
    }

    number.man = 0;
    number.num = 0;

    ui->button_summit->setEnabled(false);

    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));
    result();

    m_edit_last = QString("");

    ui->opration_show->setText(QString("已完结"));
    ui->label_locate->setText(QString(""));
    ui->pu_start->setEnabled(true);
    ui->button_useless->setEnabled(false);
}

void MainWindow::apply_useless()
{
    timer_focus->stop();
    ui->button_locate->setFocus();
    ui->button_summit->setEnabled(false);

    result_list.at(quarter)->zhuang->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->one->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->two->setStyleSheet("image: url(:/image/useless.png)");
    result_list.at(quarter)->three->setStyleSheet("image: url(:/image/useless.png)");

    quarter_increase();

    timer_opacity->stop();

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

    players *node = head;
    do{
        for(int i = 0;i < 2;i++){
            node->data[i].label->setStyleSheet("background-color: rgb(0, 32, 57)");
        }
        node = node->next;
    }while(node != head);

    while (head->player != "ShunMen") {
        head = head->next;
    }

    number.man = 0;
    number.num = 0;

    ui->xian1_result->setText(QString(""));
    ui->xian2_result->setText(QString(""));
    ui->xian3_result->setText(QString(""));
    ui->zhuang_result->setText(QString(""));

    m_edit_last = QString("");

    ui->button_useless->setEnabled(false);
    ui->pu_start->setEnabled(true);
}

void MainWindow::apply_record(QJsonArray array)
{
    for(int i = array.count() - 1;i >= 0;i--){
        unsigned int status = array.at(i)["status"].toInt();
        if(status == 2){
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
        quarter_increase();
    }
}

void MainWindow::request_login()
{
    QByteArray postData;
<<<<<<< HEAD
<<<<<<< HEAD
    QString str = "desk=A8&password=123456";
=======
    QString str = "desk=a8&password=123456";
>>>>>>> parent of 7a39d67... 0714
=======
    QString str = "desk=A8&password=f1289f70767841ae";
>>>>>>> parent of 345f219... 0716
    postData.append(str);
    manager->setStatus(LOGIN);
    manager->setInterface("dutch_login");
    manager->postData(postData);
}

void MainWindow::request_start()
{
    manager->setStatus(START);
    manager->setInterface("A89RoomProcess");
    manager->postData(QByteArray());
}

void MainWindow::request_roominfo()
{
    manager->setInterface("HeGuanRoominfo");
    manager->setStatus(ROOMINFO);
    manager->postData(QByteArray());
}

void MainWindow::request_roomcard()
{
    manager->setInterface("HeGuanA89RoomCard");
    manager->setStatus(ROOMCARD);
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());
    manager->postData(postData);
}



void MainWindow::request_faPai(CARD card)
{
    manager->setStatus(FAPAI);
    manager->setInterface("A89GameCard");

    QJsonObject json_object;
    QJsonObject json_object2;
    json_object2.insert("Player",head->player);
    json_object2.insert("NumCard",QString::number(number.num + 1)); // CardPosition
    json_object2.insert("Num",QString::number(card.num)); // 点数
    json_object2.insert("Cardnum",m_edit_last);//CardAllNum

    QByteArray postData;

    postData.append("boot_num=");postData.append(ui->xue_times->text());postData.append("&");
    postData.append("pave_num=");postData.append(ui->pu_times->text());postData.append("&");
    postData.append("Card=");postData.append(QString(QJsonDocument(json_object2).toJson()));

    manager->postData(postData);
    m_fapai = false;
}

void MainWindow::request_record()
{
    manager->setInterface("HeGuanA89GameRecord");
    manager->setStatus(RECORD);
    manager->postData(QByteArray());
}

void MainWindow::request_locate()
{
    manager->setInterface("A89Orientation");
    manager->setStatus(LOCATE);
    QByteArray postData;
    postData.append("location_num=");
    postData.append(QString::number(location));
    manager->postData(postData);
}

void MainWindow::request_summit()
{
    manager->setStatus(SUMMIT);
    manager->setInterface("A89GetGameResult");
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());
    manager->postData(postData);
}

void MainWindow::request_useless()
{
    manager->setStatus(USELESS);
    manager->setInterface("A89Abolish");

    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->xue_times->text());
    postData.append("&pave_num=");postData.append(ui->pu_times->text());

    manager->postData(postData);
}

void MainWindow::request_init()
{
    manager->setStatus(INIT);
    manager->setInterface("A89RonmInitialize");
    manager->postData(QByteArray());
}

void MainWindow::request_end()
{
    manager->setStatus(END);
    manager->setInterface("GetGameOver");
    QByteArray postData;
    postData.append("boot_num=");postData.append(ui->pu_times->text());
    manager->postData(postData);
}

void MainWindow::responsed_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();

        unsigned int desk_id = data.value("desk_id").toInt();
        QString desk_token = data.value("desk_token").toString();

        manager->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
        manager->setRawHeader("desk_token",desk_token.toUtf8());

        int maxLimit = data.value("maxLimit").toInt();
        int minLimit = data.value("minLimit").toInt();
        int tieMinLimit = data.value("tieMinLimit").toInt();
        int tieMaxLimit = data.value("tieMaxLimit").toInt();
        QString limit = QString::number(minLimit) + "-" + QString::number(maxLimit);
        QString tieLimit = QString::number(tieMinLimit) + "-" + QString::number(tieMaxLimit);

        ui->label_limit->setText(limit);
        ui->label_tieLimit->setText(tieLimit);

        login_window->close();
        this->show();
        this->showFullScreen();
        request_record();
    }
    else{
        QMessageBox box;
        box.setText("登录失败");
        box.exec();
    }
}

void MainWindow::responsed_start(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
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
        box.setText("请求开局失败");
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

        unsigned int boot_num = data.at(0)["BootNum"].toInt();
        unsigned int PaveNum = data.at(0)["PaveNum"].toInt();
        QString DeskName = data.at(0)["DeskName"].toString();

        ui->xue_times->setText(QString::number(boot_num));
        ui->pu_times->setText(QString::number(PaveNum));
        ui->desk_num->setText(DeskName);

        unsigned int phase = data.at(0)["Phase"].toInt();
        switch(phase){
        case 0:{
            phase_zero();
            break;
        }
        case 1:{
            unsigned int GameStarTime = data.at(0)["GameStarTime"].toInt();
            unsigned int Systime = data.at(0)["Systime"].toInt();
            phase_countDown(GameStarTime,Systime);
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
        box.setText("获取房间信息失败");
        box.exec();
    }
}

void MainWindow::responsed_roomcard(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        QString LocationNum = data.value("LocationNum").toString();
        if(LocationNum == ""){
            ui->button_locate->setEnabled(true);
        }
        else{
            location = LocationNum.toInt();
            QJsonArray zhuang = data.value("BankerCard").toArray();
            QJsonArray one = data.value("ShunCard").toArray();
            QJsonArray two = data.value("TianCard").toArray();
            QJsonArray three = data.value("FanCard").toArray();
            QString zhuang_result = data.value("Bankerresult").toString();
            QString one_result = data.value("Shunresult").toString();
            QString two_result = data.value("Tianresult").toString();
            QString three_result = data.value("Fanresult").toString();
            on_room_card(zhuang,one,two,three,zhuang_result.toStdString(),one_result.toStdString(),two_result.toStdString(),three_result.toStdString());
            ui->button_useless->setEnabled(true);
        }
    }
}

void MainWindow::responsed_record(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        unsigned int x1wincount = data.at(0)["ShunWinCount"].toInt();
        unsigned int x2wincount = data.at(0)["TianWinCount"].toInt();
        unsigned int x3wincount = data.at(0)["FanWinCount"].toInt();
        ui->one_win_times->setText(QString::number(x1wincount));
        ui->two_win_times->setText(QString::number(x2wincount));
        ui->three_win_times->setText(QString::number(x3wincount));

        QJsonArray array = data.at(0)["list"].toArray();
        apply_record(array);
        request_roominfo();
    }
    else{
        QMessageBox box;
        box.setText("游戏记录信息请求失败");
        box.exec();
    }
}

void MainWindow::responsed_locate(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        m_fapai = true;
        this->apply_locate();
    }
    else{
        ui->button_locate->setEnabled(true);

        QMessageBox box;
        box.setText("定位请求失败");
        box.exec();
    }
}

void MainWindow::responsed_fapai(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();

    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        QString Cardresult = data.value("Cardresult").toString();
        m_fapai = true;
        wait(strToCard(m_edit_last.toStdString()),Cardresult.toStdString());
    }
    else{
        m_edit_last = "";
        QMessageBox box;
        box.setText("刷牌失败");
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
        box.setText("提交请求失败");
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
        box.setText("作废失败");
        box.exec();
    }
}

void MainWindow::responsed_init(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();

    if(status == 1){
        unsigned int boot_num = json.value("boot_num").toInt();
        unsigned int pave_num = json.value("pave_num").toInt();
        ui->pu_times->setText(QString::fromStdString(to_string(pave_num)));
        ui->xue_times->setText(QString::fromStdString(to_string(boot_num)));
    }
    else{
        ui->pu_init->setEnabled(true);

        QMessageBox box;
        box.setText("初始化失败");
        box.exec();
    }
}

void MainWindow::responsed_end(QNetworkReply *reply)
{
    qDebug() << "endyes";
}

void MainWindow::pu_exit(){
    this->close();
}

void MainWindow::pu_useless()
{
    ui->button_useless->setEnabled(true);
    request_useless();
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

void MainWindow::quarter_increase()
{
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

