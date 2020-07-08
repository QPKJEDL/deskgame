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
#include <QHostAddress>
using namespace std;

enum {START,ROOMINFO,RECORD,ROOMCARD,LOCATE,FAPAI,SUMMIT,USELESS,INIT,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY};

static QString URL = "101.32.22.231:8210";
//static QString URL = "129.211.114.135:8210";
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

    // 初始化透明度相关
    timer_opacity = new QTimer(this);
    timer_date = new QTimer(this);
    m_graphiceffect = new QGraphicsOpacityEffect;
    m_light = false;
    n_graphiceffect = new QGraphicsOpacityEffect;
    connect(timer_date,SIGNAL(timeout()),this,SLOT(update_date()));
    timer_date->start(200);


    connect(timer_opacity, SIGNAL(timeout()), this, SLOT(while_timeout()));
    connect(ui->button_locate,SIGNAL(clicked()),this,SLOT(pu_locate()));
    connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(while_line_finish()));
    connect(ui->button_summit,SIGNAL(clicked()),this,SLOT(pu_summit()));
    connect(ui->pu_exit,SIGNAL(clicked()),this,SLOT(pu_exit()));
    connect(ui->button_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));

    // 开始按钮
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    // 倒计时计数器
    timer_Countdown = new QTimer(this);
    connect(timer_Countdown,SIGNAL(timeout()),this,SLOT(while_count_down()));

    // 初始化按钮
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));

    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(ROOMCARD,&MainWindow::responsed_roomcard);
    _map.insert(LOCATE,&MainWindow::responsed_locate);
    _map.insert(FAPAI,&MainWindow::responsed_fapai);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(LOGIN,&MainWindow::responsed_first_login);
    _map.insert(SECONDLOGIN,&MainWindow::responsed_second_login);
    _map.insert(TOPTHREE,&MainWindow::responsed_top_three);
    _map.insert(MONEY,&MainWindow::responsed_money);

   manager = new MNetManager;
   manager->setIp("129.211.114.135:8210");
   manager->setHeader("application/x-www-form-urlencoded");
   connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(while_responsed(QNetworkReply*,int)));

   second_manager = new MNetManager;
   second_manager->setIp("129.211.114.135:8210");
   second_manager->setHeader("application/x-www-form-urlencoded");
   connect(second_manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(while_responsed(QNetworkReply*,int)));

   login_window = new Login();
   connect(login_window->get_login_Button(),SIGNAL(clicked()),this,SLOT(pu_login()));

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

  //// added by mengjinhao 0619
  m_tcpsocket = new QTcpSocket(this);
  //    m_tcpsocket->abort();
  //    m_tcpsocket->connectToHost(QHostAddress(QString("129.211.114.135")),23001);
  connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(while_connected()));
  connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(while_readyRead()));
  //// end added

  //M
  ui->lineEdit_2->setVisible(false);

  live_window = new Live();
  connect(live_window,SIGNAL(request_money_list()),this,SLOT(pu_money_list()));
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
    r.biggest = player[4];//由于paixu() 函数已经将最大的牌放到最后一个了，所以直接获取就行
    qDebug() << "biggest : " << r.biggest.color << " - " << QString::fromStdString(r.biggest.face);
    r.paiXing = FiveBull(player);
    if(r.paiXing == -1){
        r.paiXing = BullCount(player);
    }
    if(r.paiXing == -1){
        r.paiXing = dianShu(r.biggest.face) - 14;//用于后面比较牌型
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
    manager->setInterface("GameCard");

    QJsonObject json_object;
    QJsonObject json_object2;
    json_object2.insert("Player",QString::number(head->num));
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

    if(number.num == 4){
        // 如果是第五张牌，则显示牌型
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

    qDebug() << "head->num : " << head->num;
    // 前进到下一个玩家
    head = head->next;
    number.increase();

    // 如果所有牌都发完了
    if(number.num == 5){
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

void MainWindow::pintosend(QDataStream &stream, QString id, QString token)
{
    int length        = 35 + id.length();
    qDebug() << "LENGTH = " << length;


    int seq        = 1;
    qint8 cmd        = 15;
    qint8 vervion    = 1;
    qint8 flag       = 0;
    qint8 kong       = 0;

    qint8 temp7 = 0;

    qint8 tokensize = (qint8)token.length();
    QString desk_id(id);
    qint8 desk_idsize = (qint8)desk_id.length();



    stream << length;
    stream << seq;
    stream << cmd;

    stream << vervion;
    stream << flag;
    stream << kong;

    stream << temp7;
    stream << tokensize;


    stream.writeRawData(token.toLocal8Bit().constData(),tokensize);

    stream << desk_idsize;

    stream.writeRawData(desk_id.toLocal8Bit().constData(),desk_idsize);
}

void MainWindow::sendLoginMsg(QDataStream &stream)
{
    int length        = 8;


    int seq          = 2;
    qint8 cmd        = 18;
    qint8 vervion    = 1;
    qint8 flag       = 0;
    qint8 kong       = 0;

    qint64 temp7 = 16;

    //QString token("939175818fba9f401894d315bde357c4");
    //qint8 tokensize = (qint8)token.length();
    //QString desk_id("6");
    //qint8 desk_idsize = (qint8)desk_id.length();



    stream << length;
    stream << seq;
    stream << cmd;

    stream << vervion;
    stream << flag;
    stream << kong;

    stream << temp7;
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
           if((m_edit_last.size() == 3) && m_fapai){
               //m_post_type = QString("fapai");
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
        if(dianShu(player_1.biggest.face) > dianShu(player_2.biggest.face)){
            return true;
        }
        if(dianShu(player_1.biggest.face) == dianShu(player_2.biggest.face)){
            return player_1.biggest.color < player_2.biggest.color ? true : false;
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

//    if(quarter < 19){
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

    for(int i = 0;i < 3;i++){
        if(!Bigger(zhuang,vec[i])){
            switch (i) {
            case(0):{
                //闲家1 赢
                result += "闲1 ";

//                if(quarter < 19){
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

                break;
            }
            case(1):{
                //闲家2 赢
                result += "闲2 ";

//                if(quarter < 19){
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
                break;
            }
            case(2):{
                //闲家3 赢
                result += "闲3 ";

//                if(quarter < 19){
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

                break;
            }
            }
        }
        else{
            switch (i) {
            case(0):{
                //闲家1 输

//                if(quarter < 19){
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

                break;
            }
            case(1):{
                //闲家2 输

//                if(quarter < 19){
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


                break;
            }
            case(2):{
                //闲家3 输

//                if(quarter < 19){
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
                break;
            }
            }
        }
    }
    if(result == ""){
        ui->pu_result->setText(QString("庄赢"));
    }
    else{
        ui->pu_result->setText(result);
    }
}

void MainWindow::update()
{
    ui->lineEdit->setFocus();
}

void MainWindow::while_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MainWindow::update_date(){

}

void MainWindow::while_timeout()
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

void MainWindow::pu_stop()
{

}

void MainWindow::pu_locate()
{
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setVisible(true);
    // 禁用定位按钮
    ui->button_locate->setEnabled(false);
    ui->lineEdit_2->setFocus();
    manager->setStatus(LOCATE);
}

void MainWindow::pu_first_login()
{
    Request_first_login();
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

void MainWindow::apply_locate(){
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

QString PaixingToShow(QString paixing){
    if(paixing == "没牛"){
        return "N";
    }
    else if(paixing == "牛牛" || paixing == "炸弹牛" || paixing == "五花牛"){
        return "B";
    }
    else if(paixing == "牛1"){
        return "1";
    }
    else if(paixing == "牛2"){
        return "2";
    }
    else if(paixing == "牛3"){
        return "3";
    }
    else if(paixing == "牛4"){
        return "4";
    }
    else if(paixing == "牛5"){
        return "5";
    }
    else if(paixing == "牛6"){
        return "6";
    }
    else if(paixing == "牛7"){
        return "7";
    }
    else if(paixing == "牛8"){
        return "8";
    }
    else if(paixing == "牛9"){
        return "9";
    }
    return "";
}

void MainWindow::request_room_card()
{
    manager->setInterface("HeGuanRoomCard");
    manager->setStatus(ROOMCARD);

    QByteArray Data;
    Data.append("boot_num=");Data.append(ui->xue_times->text());
    Data.append("&pave_num=");Data.append(ui->pu_times->text());

    manager->postData(Data);
}

void MainWindow::apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three)
{
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
            case 3:{
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

void MainWindow::request_money()
{
    second_manager->setStatus(MONEY);
    second_manager->setInterface("live_reward_list");
    QByteArray postData;
    postData.append("lastid=" + QString::number(live_window->lastid));
    postData.append("&type=" + QString::number(live_window->type));
    postData.append("&begin=" + live_window->get_time_begin());
    postData.append("&end=" + live_window->get_time_end());
    second_manager->postData(postData);
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
    manager->setInterface("HeGuanRoomCard");
    manager->setStatus(ROOMCARD);

    QByteArray Data;
    Data.append("boot_num=");Data.append(ui->xue_times->text());
    Data.append("&pave_num=");Data.append(ui->pu_times->text());

    manager->postData(Data);
}

void MainWindow::phase_finish()
{
    // 结算完成
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->xue_change->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::responsed_first_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        qDebug() << "zhubo login success";

        QJsonObject data = json.value("data").toObject();
        unsigned int desk_id = data.value("desk_id").toInt();
        QString desk_token = data.value("desk_token").toString();

        manager->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
        manager->setRawHeader("desk_token",desk_token.toUtf8());

        Request_second_login(login_window->get_live_user(),login_window->get_password());
    }
    else{
        QMessageBox box;
        box.setText("荷官登录失败");
        box.exec();
    }
}

void MainWindow::responsed_second_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();

    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        _long_id = data.value("userid").toString();
        _long_token = data.value("token").toString();
        second_manager->setRawHeader("userid",_long_id.toUtf8());
        second_manager->setRawHeader("token",_long_token.toUtf8());

        m_tcpsocket->abort();
        m_tcpsocket->connectToHost(QHostAddress(QString("129.211.114.135")),23001);
    }
    else{
        QMessageBox box;
        box.setText("主播登录失败");
        box.exec();
    }
}

void MainWindow::responsed_top_three(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        QJsonArray topThree = data.value("top3").toArray();
        int i = topThree.count();
        int h = 0;
        auto f = [](QString bet,QLabel *label){
            QString path = ":/result/image/result/";
            if(bet == "player"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/player.png\"/></p></body></html>");
            }
            else if(bet == "banker"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/banker.png\"/></p></body></html>");
            }
            else if(bet == "tie"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/tie.png\"/></p></body></html>");
            }
            else if(bet == "playerPair"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/playerpair.png\"/></p></body></html>");
            }
            else if(bet == "bankerPair"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/bankerpair.png\"/></p></body></html>");
            }
        };
        auto f2 = [&](QLabel *m,QLabel *b,QLabel *n){
            QJsonObject ob = topThree.at(h).toObject();
            int money = ob.value("Money").toInt();
            QString bet = ob.value("Bet").toString();
            QString NickName = ob.value("NickName").toString();

            n->setText(NickName);
            m->setText(QString::number(money) + "元");
            f(bet,b);
        };

        if(h < i){
            f2(ui->label_first_money,ui->label_first_bet,ui->label_first_name);
            if(++h < i){
                f2(ui->label_second_money,ui->label_second_bet,ui->label_second_name);
                if(++h < i){
                    f2(ui->label_third_money,ui->label_third_bet,ui->label_third_name);
                }
            }
        }
    }
    else{
        QMessageBox box;
        box.setText("获取下注前三失败");
        box.exec();
    }
}

void MainWindow::responsed_money(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        live_window->update_panel(data);
    }
    else{
        QMessageBox box;
        box.setText("获取打赏记录失败");
        box.exec();
    }
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
        count_down = 30;
        timer_Countdown->start(1000);
    }
    else{
        ui->pu_start->setEnabled(true);

        QMessageBox box;
        box.setText("牛牛请求开局失败");
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
        box.setText("牛牛获取房间信息失败");
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
        location = data.value("LocationNum").toString().toInt();
        ui->label_locate->setText(QString::number(location));
        if(location == 0){
            ui->button_locate->setEnabled(true);
        }
        else{
            QJsonArray zhuang = data.value("BankerCard").toArray();
            QJsonArray one = data.value("IdleOneCard").toArray();
            QJsonArray two = data.value("IdleTwoCard").toArray();
            QJsonArray three = data.value("IdleThreeCard").toArray();
            apply_room_card(zhuang,one,two,three);
            ui->button_useless->setEnabled(true);
        }
    }
    else{
        QMessageBox box;
        box.setText("牛牛本局游戏信息请求失败");
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
        box.setText("牛牛定位请求失败");
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
        box.setText("牛牛刷牌失败");
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
        box.setText("牛牛提交请求失败");
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
        box.setText("牛牛作废失败");
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
    }
    else{
        QMessageBox box;
        box.setText("牛牛初始化失败");
        box.exec();
    }
}

void MainWindow::while_line_finish()
{
    bool ok = false;
    location = ui->lineEdit_2->text().toInt(&ok);
    if(!ok || location < 2 || location > 12){
        //提示
        ui->lineEdit_2->setText("");
        QMessageBox box;
        box.setText("输入的定位无效");
        box.exec();
        return;
    }

    manager->setInterface("Orientation");

    QByteArray Data;
    Data.append("location_num=");
    Data.append(QString::number(location));

    manager->postData(Data);
}

void MainWindow::pu_login()
{
    Request_first_login();
}

void MainWindow::Request_summit(){
    //发送提交请求
    ui->button_summit->setEnabled(false);

    manager->setStatus(SUMMIT);
    manager->setInterface("GetGameOver");

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
        for(int i = 0;i < 5;i++){
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
    result();

    // 重新排序每个玩家的 label
    LabelPaixu(head);

    // 清空上张牌的数据，避免 52 分之一 的几率出错
    m_edit_last = QString("");

    ui->opration_show->setText(QString("已完结"));
    ui->label_locate->setText(QString(""));
    ui->pu_start->setEnabled(true);
    ui->button_useless->setEnabled(false);
}

void MainWindow::pu_exit(){
    this->close();
}

void MainWindow::Request_useless(){
    // 请求作废
    // 禁用作废按钮
    ui->button_useless->setEnabled(false);

    manager->setStatus(USELESS);
    manager->setInterface("NnAbolish");

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
    // 禁用提交
    ui->button_summit->setEnabled(false);

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
        for(int i = 0;i < 5;i++){
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
    manager->setInterface("RoomProcess");

    manager->postData(QByteArray());
}

void MainWindow::Request_initialize()
{
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        // 请求初始化
        manager->setStatus(INIT);
        manager->setInterface("NnRonmInitialize");
        manager->postData(QByteArray());
    }
}

void MainWindow::while_readyRead()
{
    if (m_login) {
        int    length  = 0;
        int    seq     = 0;

        qint8  cmd     = 0;
        qint8  version = 0;
        qint8  flag    = 0;
        qint8  kong    = 0;

        int    mark    = 0;
        QString string;
        QByteArray block = m_tcpsocket->readAll();
        QDataStream in(block);
        in.setVersion(QDataStream::Qt_5_14);
        in >> length;
        in >> seq;
        in >> cmd;
        in >> version;
        in >> flag;
        in >> kong;
        in >> mark;

        qDebug() << length;
        qDebug() << seq;
        qDebug() << cmd;
        qDebug() << version;
        qDebug() << flag;
        qDebug() << kong;
        qDebug() << mark;

        if (mark == 0) {
            qDebug() << QString("login success！");
            QByteArray block;

            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_14);

            sendLoginMsg(out);

            m_tcpsocket->write(block);
            m_login = false;

            login_window->close();
            this->show();
            this->showFullScreen();
            request_room_info();
        }
        else{
            qDebug() << "login faild";
        }
    } else {
        int    length  = 0;
        int    seq     = 0;

        qint8  cmd     = 0;
        qint8  version = 0;
        qint8  flag    = 0;
        qint8  kong    = 0;

        qint64    sendid    = 0;
        qint64    receiveid = 0;

        //QString   receivedata("");

        QByteArray block = m_tcpsocket->readAll();
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

        //in >> receivedata;
        int strsize = length - sizeof(qint64) * 2;

        char* p = new char[strsize];


        in.readRawData(p, strsize);

        QByteArray receivedata(p,strsize);

        delete[] p;

        //QByteArray jbyte = receivedata.toUtf8();

        QJsonObject json_object = QJsonDocument::fromJson(receivedata).object();

        int Cmd = json_object.value("Cmd").toInt();
        int Deskid = 0;
        int Boot_num = 0;
        int Pave_num = 0;
        int CountDown = 0;
        int Phase     = 0;
        qint64 GameStarTime = 0;

        int LocationNum = 0;
        QString Desk_name("");
        QString Result("");
        int Sumgetmoney = 0;
        int Balance = 0;

        if (Cmd == 2 || Cmd == 3|| Cmd == 4 || Cmd == 5) {
            Deskid = json_object.value("DeskId").toInt();
            Boot_num = json_object.value("Boot_num").toInt();
            Pave_num = json_object.value("Pave_num").toInt();

            CountDown = json_object.value("CountDown").toInt();
            Phase = json_object.value("Phase").toInt();

            GameStarTime = json_object.value("GameStarTime").toInt();

        } else if (Cmd == 6) {
            Deskid = json_object.value("DeskId").toInt();
            Boot_num = json_object.value("Boot_num").toInt();
            Pave_num = json_object.value("Pave_num").toInt();

            CountDown = json_object.value("CountDown").toInt();
            Phase = json_object.value("Phase").toInt();

            GameStarTime = json_object.value("GameStarTime").toInt();

        } else if (Cmd == 7) {
            Boot_num = json_object.value("Boot_num").toInt();
            Pave_num = json_object.value("Pave_num").toInt();

            Desk_name = json_object.value("Desk_name").toString();
            Result = json_object.value("Result").toString();

            Sumgetmoney = json_object.value("Sumgetmoney").toInt();
            Balance = json_object.value("Balance").toInt();
        } else if (Cmd == 8) {
            Deskid = json_object.value("DeskId").toInt();
            LocationNum = json_object.value("LocationNum").toInt();
        }


        qDebug() << "length" << length;
        qDebug() << "seq" <<seq;
        qDebug() << "cmd" <<cmd;
        qDebug() << "version" <<version;
        qDebug() << "flag" <<flag;
        qDebug() << "kong" <<kong;
        qDebug() << "sendid" <<sendid;
        qDebug() << "receiveid" <<receiveid;


    }
    //in >>
    //textEdit->append(string + '\n');
    qDebug() << "read message success";
}

void MainWindow::sendMessage(QString id, QString token)
{
    qDebug() << "request long link login" << id << "  -token-  " << token;
    //int typee = 1;
    QString string; //= lineEdit->text();
    QByteArray block;
    //QFile file("a.txt");
    //file.open(QIODevice::WriteOnly);

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);

    pintosend(out,id,token);
    //out<<userStr;
    // out<<type;
    // out<<string;
    m_tcpsocket->write(block);
}

void MainWindow::while_connected()
{
    sendMessage(_long_id,_long_token);
    qDebug() << "connected server success......";
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

void MainWindow::while_count_down()
{
    ui->label_locate->setText(QString::number(count_down));
    // 刷新倒计时
    count_down--;

    // 如果倒计时为 -1
    if(count_down == -1){
        // 停止倒计时
        timer_Countdown->stop();
        ui->label_locate->setText("");
        // 启用定位
        ui->button_locate->setEnabled(true);
    }
}

void MainWindow::pu_summit()
{
    Request_summit();
}

void MainWindow::pu_useless()
{
    Request_useless();
}

void MainWindow::pu_start()
{
    Request_start();
}

void MainWindow::pu_init()
{
    Request_initialize();
}

void MainWindow::pu_money_list()
{
    request_money();
}

void MainWindow::on_money()
{
    live_window->show();
}

void MainWindow::Request_first_login()
{
    QByteArray postData;
    QString str = "desk=a2&password=123456";
    postData.append(str);
    manager->setStatus(LOGIN);
    manager->setInterface("dutch_login");
    manager->postData(postData);
}

void MainWindow::Request_second_login(QString live_user, QString password)
{
    second_manager->setInterface("live_login");
    second_manager->setStatus(SECONDLOGIN);
    QByteArray postData;
    postData.append(QString("live_user=" + live_user));
    postData.append(QString("&password=" + password));
    second_manager->postData(postData);
}

void MainWindow::Request_top_three()
{
    manager->setInterface("");
    manager->setStatus(TOPTHREE);
    QByteArray postData;
    postData.append("boot_num=" + ui->xue_times->text());
    postData.append("&pave_num=" + ui->pu_times->text());
    manager->postData(postData);
}
