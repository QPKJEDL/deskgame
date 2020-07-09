#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHostAddress>
#include "qqchat.h"
QString URL = "101.32.22.231:8210";

// lh a1 // bjl a5 // nn a2

enum {LOGIN,START,CHANGEBOOT,ROOMINFO,RECORD,SUMMIT,USELESS,INIT,SECONDLOGIN,TOPTHREE,TOPTHREETWO,TOPFIVE,MONEY,BAN};

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 倒计时初始化
    times = 30;
    // 结果初始化
    m_result = 0;

    login_window = new Login();
    manager = new MNetManager;
    manager->setIp("101.32.22.231:8210");
    manager->setHeader("application/x-www-form-urlencoded");

    second_manager = new MNetManager;
    second_manager->setIp("101.32.22.231:8210");
    second_manager->setHeader("application/x-www-form-urlencoded");

    pu_money = new QPushButton(this);
    pu_money->setMinimumSize(150,150);
    pu_money->move(1400,400);
    pu_money->setStyleSheet("background-color: transparent;border-image: url(:/icon/image/icon/money.png);");
    pu_money->show();

    // 倒计时初始化
    this->m_timer_count_down = new QTimer(this);
    connect(m_timer_count_down,SIGNAL(timeout()),this,SLOT(count_down()));
    label_count_down = new QLabel(this);
    label_count_down->setMinimumSize(QSize(300,300));
    label_count_down->move(800,400);
    label_count_down->setStyleSheet("background-color: transparent;font: 200pt \"方正粗黑宋简体\";");



    // 生成恶心人的体力活链表
    m_link_reslut = new Link();
    Link* node = new Link();
    m_link_reslut = node;
    // 先动态生成QGridLayout 中的 120 个 QLabel
    for(int i = 0;i < 20;i++){
        for(int j = 0;j < 6;j++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            ui->gridLayout_2->addWidget(label,j,i);

            // 生成结果链表
            node->data = label;
            node->next = new Link;
            node = node->next;
        }
    }

    _map.insert(LOGIN,&MainWindow::responsed_login);
    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(CHANGEBOOT,&MainWindow::responsed_change_boot);
    _map.insert(TOPTHREE,&MainWindow::responsed_top_three);
    _map.insert(TOPFIVE,&MainWindow::responsed_top_five);
    _map.insert(SECONDLOGIN,&MainWindow::responsed_second_login);
    _map.insert(MONEY,&MainWindow::responsed_money);
    _map.insert(BAN,&MainWindow::responsed_ban);

    // 链接槽函数
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    connect(ui->pu_changeXue,SIGNAL(clicked()),this,SLOT(pu_changeXue()));
    connect(ui->pu_stop,SIGNAL(clicked()),this,SLOT(pu_stop()));
    connect(ui->pu_leave,SIGNAL(clicked()),this,SLOT(pu_leave()));
    connect(ui->pu_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(ui->pu_long,SIGNAL(clicked()),this,SLOT(pu_long()));
    connect(ui->pu_tiger,SIGNAL(clicked()),this,SLOT(pu_tiger()));
    connect(ui->pu_same,SIGNAL(clicked()),this,SLOT(pu_same()));
    connect(ui->pu_enter,SIGNAL(clicked()),this,SLOT(pu_enter()));
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(pu_cancel()));
    connect(login_window->get_login_Button(),SIGNAL(clicked()),this,SLOT(pu_login()));
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(second_manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
    connect(pu_money,SIGNAL(clicked()),this,SLOT(on_money()));

    // 连接弹窗信号
    form = new Form();
    form->setWindowFlag(Qt::FramelessWindowHint);
    connect(form->button_enter(),SIGNAL(clicked()),this,SLOT(tc_enter()));
    connect(form->button_cancel(),SIGNAL(clicked()),this,SLOT(tc_cancel()));

    m_tcpsocket = new QTcpSocket(this);

    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(connectedServer()));
    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));

    live_window = new Live();
    connect(live_window,SIGNAL(request_money_list()),this,SLOT(pu_money_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pintosend(QDataStream &stream, QString id, QString token)
{
    int length        = 35 + id.length();

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

    qint64 temp7 = _long_id.toLong();

    stream << length;
    stream << seq;
    stream << cmd;

    stream << vervion;
    stream << flag;
    stream << kong;

    stream << temp7;
}

void MainWindow::pu_init(){
    // 禁用初始化按钮
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        ui->pu_init->setEnabled(false);

        // 发送初始化请求
        request_init();
    }
}

void MainWindow::apply_init()
{
    // 结果链表
    m_link_reslut = m_link_reslut_head;
    // 结果
    m_result = 0;
    // 倒计时
    times = 30;
}


void MainWindow::apply_start(){
    m_timer_count_down->start(1000);
}

void MainWindow::request_room_info()
{
    manager->setStatus(ROOMINFO);
    manager->setInterface("HeGuanRoominfo");
    manager->postData(QByteArray());
}

void MainWindow::request_result_list()
{
    manager->setStatus(RECORD);
    manager->setInterface("lh_dutch_game_list");
    QByteArray postData;
    postData.append("boot_num=" + ui->label_xues->text());
    manager->postData(postData);
}

void MainWindow::request_init()
{
    manager->setStatus(INIT);
    manager->setInterface("lh_desk_ini");
    manager->postData(QByteArray());
}

void MainWindow::request_start()
{
    manager->setStatus(START);
    manager->setInterface("lh_count_down");
    manager->postData(QByteArray());
}

void MainWindow::request_change_boot()
{
    manager->setStatus(CHANGEBOOT);
    manager->setInterface("lh_change_boot");
    manager->postData(QByteArray());
}

void MainWindow::request_useless()
{
    manager->setStatus(USELESS);
    manager->setInterface("lh_game_burn");
    QByteArray postData;
    postData.append(QString("boot_num="));postData.append(ui->label_xues->text());
    postData.append(QString("&pave_num="));postData.append(ui->label_pus->text());
    manager->postData(postData);
}

void MainWindow::request_summit()
{
    manager->setStatus(SUMMIT);
    manager->setInterface("lh_game_over");
    QByteArray postData;
    postData.append(QString("boot_num=") + ui->label_xues->text());
    postData.append(QString("&pave_num=") + ui->label_pus->text());
    postData.append(QString("&game_num=") + QString::number(m_result));
    manager->postData(postData);
}

void MainWindow::request_top_three()
{
    manager->setInterface("lh_bet_top_three");
    manager->setStatus(TOPTHREE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_xues->text());
    postData.append("&pave_num=" + ui->label_pus->text());
    manager->postData(postData);
}

void MainWindow::request_top_five()
{
    manager->setInterface("lh_bingo_top_five");
    manager->setStatus(TOPFIVE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_xues->text());
    manager->postData(postData);
}

void MainWindow::request_top_three_two()
{
    manager->setInterface("lh_bingo_top_five");
    manager->setStatus(TOPFIVE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_xues->text());
    manager->postData(postData);
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

void MainWindow::request_ban(int talkid)
{
    second_manager->setInterface("live_ban_user");
    QByteArray postData;
    postData.append("talkid=" + QString::number(talkid));
    second_manager->setStatus(BAN);
    second_manager->postData(postData);
}

void MainWindow::responsed_init(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();
        ui->label_xues->setText(QString::number(boot_num));
        ui->label_pus->setText(QString::number(pave_num));

        Link *node = m_link_reslut_head;
        while(node->next != NULL){
            node->data->setText("");
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node = node->next;

        }

        m_link_reslut = m_link_reslut_head;
    }
    else{
        ui->pu_init->setEnabled(true);

        QMessageBox box;
        box.setText("初始化失败");
        box.exec();
    }
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
        unsigned int maxLimit = data.value("maxLimit").toInt();
        unsigned int minLimit = data.value("minLimit").toInt();
        unsigned int tieMaxLimit = data.value("tieMaxLimit").toInt();
        unsigned int tieMinLimit = data.value("tieMinLimit").toInt();
        ui->label_minLimit->setText(QString::number(minLimit) + "-" + QString::number(maxLimit));
        ui->label_tieMinLimit->setText(QString::number(tieMinLimit) + "-" + QString::number(tieMaxLimit));

        reqeust_second_login(login_window->get_live_user(),login_window->get_password());
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
        qDebug() << "zhubo login success";

        QJsonObject data = json.value("data").toObject();
        _long_id = data.value("userid").toString();
        _long_token = data.value("token").toString();
        second_manager->setRawHeader("userid",_long_id.toUtf8());
        second_manager->setRawHeader("token",_long_token.toUtf8());

        m_tcpsocket->abort();
        m_tcpsocket->connectToHost(QHostAddress(QString("101.32.22.231")),23001);
    }
    else{
        QMessageBox box;
        box.setText("主播登录失败");
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
        ui->label_xues->setText(QString::number(boot_num));
        ui->label_pus->setText(QString::number(PaveNum));
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
        }
        case 2:{
            phase_kaiPai();
            is_fapai_phase = true;
            break;
        }
        case 3:{
            phase_finish();
            break;
        }
        }
        request_result_list();
    }
    else{
        QMessageBox box;
        box.setText("获取房间信息失败");
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
        unsigned int sumTie = data.at(0)["sumTie"].toInt();
        unsigned int sumBanker = data.at(0)["sumDragon"].toInt();
        unsigned int sumPlayer = data.at(0)["sumTiger"].toInt();
        QJsonArray array = data.at(0)["list"].toArray();
        apply_enter(array);

        request_top_five();
    }
    else{
        QMessageBox box;
        box.setText("获取房间历史记录失败");
        box.exec();
    }
}



void MainWindow::responsed_start(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        ui->label_first_bet->setText("");
        ui->label_second_bet->setText("");
        ui->label_third_bet->setText("");

        ui->label_first_money->setText("");
        ui->label_second_money->setText("");
        ui->label_third_money->setText("");

        ui->label_first_name->setText("");
        ui->label_second_name->setText("");
        ui->label_third_name->setText("");


        QJsonObject data = json.value("data").toObject();
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();
        ui->label_xues->setText(QString::number(boot_num));
        ui->label_pus->setText(QString::number(pave_num));
        ui->pu_changeXue->setEnabled(false);

        apply_start();

        request_top_five();
    }
    else{
        ui->pu_start->setEnabled(true);

        QMessageBox box;
        box.setText("开局失败");
        box.exec();
    }
}

void MainWindow::responsed_change_boot(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();

        Link* node = m_link_reslut_head;
        while(node->next != nullptr){
            node->data->setText("");
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node = node->next;
        }
        m_link_reslut = m_link_reslut_head;
    }
    else{
        QMessageBox box;
        box.setText("换靴失败");
        box.exec();
    }
}

void MainWindow::responsed_useless(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QString path = QString("border-image: url(:/result/useless.png);");
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(path));

        // 指向下一个结果 label
        next_result();

        ui->label_result->setText("");
        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);
        ui->pu_long->setEnabled(false);
        ui->pu_tiger->setEnabled(false);
        ui->pu_same->setEnabled(false);
        ui->pu_useless->setEnabled(false);
        ui->pu_start->setEnabled(true);
        this->times = 30;
    }
    else{
        ui->pu_useless->setEnabled(true);

        QMessageBox box;
        box.setText("作废失败");
        box.exec();
    }
}

void MainWindow::responsed_summit(QNetworkReply *reply)
{
    // 无论成功与否，启用结算按钮
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);

    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QString up = "上铺：";
        ui->label_result->setText(QString(""));
        QString path = ":/result/";
        QString path_gl = ":/result/";
        switch (m_result) {
        case 7:
            path.append("long");
            path_gl.append("red");
            up.append("龙赢");
            break;
        case 4:
            path.append("tiger");
            path_gl.append("blue");
            break;
            up.append("虎赢");
        case 1:
            path.append("same");
            up.append("和");
            break;
        }
        path.append(".png");
        path_gl.append(".png");

        // 更新结果样式表
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));

        next_result();

        ui->pu_start->setEnabled(true);
        ui->pu_changeXue->setEnabled(true);
        ui->pu_long->setEnabled(false);
        ui->pu_tiger->setEnabled(false);
        ui->pu_same->setEnabled(false);
        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);
        ui->pu_useless->setEnabled(false);
        form->hide();
        times = 30;
    }
    else{
        QMessageBox box;
        box.setText("结算失败");
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
            if(bet == "dragon"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/dragon.png\"/></p></body></html>");
            }
            else if(bet == "tiger"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/tiger.png\"/></p></body></html>");
            }
            else if(bet == "tie"){
                label->setText("<html><head/><body><p><img src=\":/bet/image/bet/tie.png\"/></p></body></html>");
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

        is_fapai_phase = false;
    }
    else{
        QMessageBox box;
        box.setText("获取下注前三失败");
        box.exec();
    }
}

void MainWindow::responsed_top_five(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        QJsonArray topFive = data.value("top5").toArray();
        int i = topFive.count();
        int h = 0;
        auto f = [&](QLabel *n,QLabel *a){
            QJsonObject ob = topFive.at(h).toObject();
            QString NickName = ob.value("NickName").toString();
            double num = ob.value("Num").toInt();
            if(num != 0){
                a->setText(NickName);
                n->setText(QString::number(num));
            }
        };

        if(h < i){
            f(ui->label_first_num,ui->label_bingo_one);
            if(++h < i){
                f(ui->label_second_num,ui->label_bingo_two);
                if(++h < i){
                    f(ui->label_third_num,ui->label_bingo_three);
                    if(++h < i){
                        f(ui->label_fourth_num,ui->label_bingo_four);
                        if(++h < i){
                            f(ui->label_fifth_num,ui->label_bingo_five);
                        }
                    }
                }
            }
        }

        if(is_fapai_phase){
            request_top_three();
        }
    }
    else{
        QMessageBox box;
        box.setText("获取连续中铺记录失败");
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

void MainWindow::responsed_ban(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QLabel *label = new QLabel();
        label->setStyleSheet("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;");
        label->setText("禁言成功");
        label->setMaximumSize(100,50);
        ui->ChatPanel->addWidget(label);
    }
    else{
        QLabel *label = new QLabel();
        label->setStyleSheet("color: rgb(255, 255, 255);background:rgb(180, 45, 55);border:1px solid grey; border-radius: 8px;");
        label->setText("禁言失败");
        label->setMaximumSize(100,50);
        ui->ChatPanel->addWidget(label);
    }
}

void MainWindow::pu_login()
{
    request_login();
}

void MainWindow::pu_money_list()
{
    request_money();
}

void MainWindow::pu_ban(int talkid)
{
    request_ban(talkid);
}

void MainWindow::on_money()
{
    live_window->show();
}




void MainWindow::phase_zero()
{
    // 洗牌中
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    // 倒计时中
    unsigned int time = end - start;
    times = 30 - time;
    m_timer_count_down->start(1000);
}

void MainWindow::phase_kaiPai()
{
    // 开牌中
    // 启用该启用的按钮
    ui->pu_leave->setEnabled(true);
    ui->pu_long->setEnabled(true);
    ui->pu_tiger->setEnabled(true);
    ui->pu_same->setEnabled(true);
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
    // 启用作废按钮
    ui->pu_useless->setEnabled(true);
}

void MainWindow::phase_finish()
{
    // 结算完成
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::apply_enter(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    // 获取结果和规律的图片
    for(int i = 0;i < array.count();i++){
        // 获取结果图片
        QString path = ":/result/";
        QString path_gl = ":/result/";
        QString up = "上铺：";
        QString m_game_str = array.at(i)["winner"].toString();
        if(m_game_str == "龙"){
            m_result = 7;
            path.append("long");
            path_gl.append("red");
            up.append("龙赢");
        }
        else if(m_game_str == "虎"){
            m_result = 4;
            path.append("tiger");
            path_gl.append("blue");
            up.append("虎赢");
        }
        else if(m_game_str == "和"){
            m_result = 1;
            path.append("same");
            up.append("和");
        }
        else if(m_game_str == ""){
            m_result = 0;
            path.append("useless");
        }
        path.append(".png");
        path_gl.append(".png");


        // 更新结果样式表
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
        qDebug() << m_link_reslut->data->styleSheet();
        // 指向下一个结果 label
        // 如果下一个 结果label 为 nullptr 如何？
        if(m_link_reslut->next == nullptr){
            Link* node = m_link_reslut_head;
            for (int i = 0;node->next != nullptr;i++) {
                qDebug() << "node -> next : " << i;
                node->data->setStyleSheet(node->next->data->styleSheet());
                node->data->setText(node->next->data->text());
                node = node->next;
            }
            node->data->setText("");
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            qDebug() << "m_link_reslut->next : nullptr";
        }
        else{
            m_link_reslut = m_link_reslut->next;
            qDebug() << "m_link_reslut->next : not null";
        }

        // 更新规律表
    }
}

void MainWindow::next_result()
{
    if(m_link_reslut->next == nullptr){
        Link* node = m_link_reslut_head;
        for (int i = 0;node->next != nullptr;i++) {
            qDebug() << "node -> next : " << i;
            node->data->setStyleSheet(node->next->data->styleSheet());
            node->data->setText(node->next->data->text());
            node = node->next;
        }
        node->data->setStyleSheet("");
        node->data->setText("background-color: rgb(255, 255, 255);");
    }
    else{
        m_link_reslut = m_link_reslut->next;
    }
}

void MainWindow::request_login()
{
    manager->setStatus(LOGIN);
    manager->setInterface("dutch_login");
    QByteArray postData;
    postData.append("desk=vip11&password=7c6f50493eed622b");
    manager->postData(postData);
}

void MainWindow::reqeust_second_login(QString live_user, QString password)
{
    second_manager->setInterface("live_login");
    second_manager->setStatus(SECONDLOGIN);
    QByteArray postData;
    postData.append(QString("live_user=" + live_user));
    postData.append(QString("&password=" + password));

    second_manager->postData(postData);
}

void MainWindow::pu_start()
{
    // 禁用按钮
    ui->pu_start->setEnabled(false);
    // 请求倒计时接口
    request_start();
}

void MainWindow::pu_changeXue()
{
    int choose = QMessageBox::question(this,QString("换靴"),QString("确认换靴？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        request_change_boot();
    }
}

void MainWindow::pu_stop(){

}

void MainWindow::pu_leave(){
    this->close();
}

void MainWindow::pu_useless(){
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        // 禁用作废按钮
        ui->pu_useless->setEnabled(false);
        request_useless();
    }
}

void MainWindow::tc_enter(){
    // 发送结果
    if(m_result == -1){
        QMessageBox box;
        box.setText("结果无效");
        box.exec();
    }
    else{
        // 发送请求
        request_summit();
    }
}

void MainWindow::tc_cancel(){
    // 初始化结果值
    m_result = 0;
    // 初始化结果显示
    ui->label_result->setText("");
    // 启用结果按钮
    ui->pu_long->setEnabled(true);
    ui->pu_tiger->setEnabled(true);
    ui->pu_same->setEnabled(true);
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
    // 关闭弹窗
    form->hide();
}

void MainWindow::pu_enter()
{
    // 禁用结算 取消按钮
    ui->pu_enter->setEnabled(false);
    ui->pu_cancel->setEnabled(false);

    form->init("AA",ui->label_xues->text(),ui->label_pus->text(),ui->label_result->text());
    form->show();
    form->move(600,400);
}

void MainWindow::pu_cancel()
{
    // 初始化结果值
    m_result = -1;
    m_playerPair = 0;
    m_bankerPair = 0;
    ui->label_result->setText("");

    // 启用结果按钮
    ui->pu_long->setEnabled(true);
    ui->pu_tiger->setEnabled(true);
    ui->pu_same->setEnabled(true);
    // 启用结算按钮
    ui->pu_enter->setEnabled(true);
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

void MainWindow::pu_long()
{
    m_result = 7;
    // 禁用按钮
    ui->pu_long->setEnabled(false);
    ui->pu_tiger->setEnabled(false);
    ui->pu_same->setEnabled(false);
    // 显示结果
    ui->label_result->setText("龙赢");
}

void MainWindow::pu_tiger()
{
    m_result = 4;
    // 禁用按钮
    ui->pu_long->setEnabled(false);
    ui->pu_tiger->setEnabled(false);
    ui->pu_same->setEnabled(false);
    // 显示结果
    ui->label_result->setText("虎赢");
}

void MainWindow::pu_same(){
    m_result = 1;
    // 禁用按钮
    ui->pu_long->setEnabled(false);
    ui->pu_tiger->setEnabled(false);
    ui->pu_same->setEnabled(false);
    // 显示结果
    ui->label_result->setText("和");
}

void MainWindow::count_down(){
    label_count_down->setText(QString::number(times));
    if(--times < 0){
        //倒计时完成
        m_timer_count_down->stop();

        request_top_three();

        label_count_down->setText(QString(""));
        // 启用该启用的按钮
        ui->pu_leave->setEnabled(true);
        ui->pu_useless->setEnabled(true);
        ui->pu_long->setEnabled(true);
        ui->pu_tiger->setEnabled(true);
        ui->pu_same->setEnabled(true);
        ui->pu_enter->setEnabled(true);
        ui->pu_cancel->setEnabled(true);
    }
}

void MainWindow::readMessage()
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

        QString text = json_object.value("text").toString();
        QJsonObject user = json_object.value("user").toObject();
        QString username = user.value("username").toString();
        QString talkid = user.value("userid").toString();

        QQChat *qc = new QQChat();
        connect(qc,SIGNAL(banUser(int)),this,SLOT(pu_ban(int)));
        qc->update_input(text);
        qc->update_name(username);
        qc->talkid = talkid.toInt();
        ui->ChatPanel->addWidget(qc);


//        if (Cmd == 2 || Cmd == 3|| Cmd == 4 || Cmd == 5) {
//            Deskid = json_object.value("DeskId").toInt();
//            Boot_num = json_object.value("Boot_num").toInt();
//            Pave_num = json_object.value("Pave_num").toInt();

//            CountDown = json_object.value("CountDown").toInt();
//            Phase = json_object.value("Phase").toInt();

//            GameStarTime = json_object.value("GameStarTime").toInt();

//        } else if (Cmd == 6) {
//            Deskid = json_object.value("DeskId").toInt();
//            Boot_num = json_object.value("Boot_num").toInt();
//            Pave_num = json_object.value("Pave_num").toInt();

//            CountDown = json_object.value("CountDown").toInt();
//            Phase = json_object.value("Phase").toInt();

//            GameStarTime = json_object.value("GameStarTime").toInt();

//        } else if (Cmd == 7) {
//            Boot_num = json_object.value("Boot_num").toInt();
//            Pave_num = json_object.value("Pave_num").toInt();

//            Desk_name = json_object.value("Desk_name").toString();
//            Result = json_object.value("Result").toString();

//            Sumgetmoney = json_object.value("Sumgetmoney").toInt();
//            Balance = json_object.value("Balance").toInt();
//        } else if (Cmd == 8) {
//            Deskid = json_object.value("DeskId").toInt();
//            LocationNum = json_object.value("LocationNum").toInt();
//        }


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

    QString string;
    QByteArray block;

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);

    pintosend(out,id,token);

    m_tcpsocket->write(block);
}

void MainWindow::connectedServer()
{
    sendMessage(_long_id,_long_token);
    qDebug() << "connected server success......";
}
