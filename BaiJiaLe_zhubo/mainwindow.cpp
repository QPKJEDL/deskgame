#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHostAddress>

//QString URL = "192.168.0.104:8210";
//QString URL = "129.211.114.135:8210";

enum {ROOMINFO,RECORD,GAMEOVER,INIT,START,CHNAGEBOOT,USELESS,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_login(true)
{
    ui->setupUi(this);
    // 结果值初始化
    m_playerPair = 0;
    m_bankerPair = 0;
    // 倒计时初始化
    times = 30;

    pu_money = new QPushButton(this);
    pu_money->setMinimumSize(150,150);
    pu_money->move(1400,400);
    pu_money->setStyleSheet("background-color: transparent;border-image: url(:/icon/image/icon/money.png);");
    pu_money->show();

    _map.insert(LOGIN,&MainWindow::responsed_login);
    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(CHNAGEBOOT,&MainWindow::responsed_changeBoot);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(GAMEOVER,&MainWindow::responsed_gameover);
    _map.insert(SECONDLOGIN,&MainWindow::responsed_second_login);
    _map.insert(TOPTHREE,&MainWindow::responsed_top_three);
    _map.insert(TOPFIVE,&MainWindow::responsed_top_five);
    _map.insert(MONEY,&MainWindow::responsed_money);


    manager = new MNetManager;
    manager->setIp("129.211.114.135:8210");
    manager->setHeader("application/x-www-form-urlencoded");
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    second_manager = new MNetManager;
    second_manager->setIp("129.211.114.135:8210");
    second_manager->setHeader("application/x-www-form-urlencoded");
    connect(second_manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));


    //// added by mengjinhao 0619
    m_tcpsocket = new QTcpSocket(this);
//    m_tcpsocket->abort();
//    m_tcpsocket->connectToHost(QHostAddress(QString("129.211.114.135")),23001);
    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(connectedServer()));
    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    //// end added

    // 倒计时初始化
    this->m_timer_count_down = new QTimer(this);
    connect(m_timer_count_down,SIGNAL(timeout()),this,SLOT(count_down()));
    label_count_down = new QLabel(this);
    label_count_down->setMinimumSize(QSize(300,300));
    label_count_down->move(800,400);
    label_count_down->setStyleSheet("background-color: transparent;font: 200pt \"方正粗黑宋简体\";");

    // 生成体力活链表
    m_link_reslut = new Link();
    Link* node = new Link();
    m_link_reslut = node;
    m_link_reslut_head = node;
    // 先动态生成QGridLayout 中的 120 个 QLabel
    for(int i = 0;i < 20;i++){
        for(int j = 0;j < 6;j++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            ui->gridLayout_2->addWidget(label,j,i);

            // 生成结果链表
            node->data = label;
            // 如果第 120 个 label 已经生成
            if(i == 19 && j == 5){
                node->next = nullptr;
            }
            else{
                node->next = new Link;
                node = node->next;
            }
        }
    }
    login_window = new Login();
    // 链接槽函数
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    connect(ui->pu_changeXue,SIGNAL(clicked()),this,SLOT(pu_changeXue()));
    connect(ui->pu_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(ui->pu_zhuang,SIGNAL(clicked()),this,SLOT(pu_zhuang()));
    connect(ui->pu_xian,SIGNAL(clicked()),this,SLOT(pu_xian()));
    connect(ui->pu_zhuangdui,SIGNAL(clicked()),this,SLOT(pu_zhuangdui()));
    connect(ui->pu_xiandui,SIGNAL(clicked()),this,SLOT(pu_xiandui()));
    connect(ui->pu_same,SIGNAL(clicked()),this,SLOT(pu_same()));
    connect(ui->pu_enter,SIGNAL(clicked()),this,SLOT(on_enter()));
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    connect(ui->pu_leave,SIGNAL(clicked()),this,SLOT(pu_leave()));
    connect(pu_money,SIGNAL(clicked()),this,SLOT(on_money()));
    connect(login_window->get_login_Button(),SIGNAL(clicked()),this,SLOT(pu_login()));
    // 连接弹窗信号
    form = new Form();
    form->setWindowFlag(Qt::FramelessWindowHint);
    connect(form->button_enter(),SIGNAL(clicked()),this,SLOT(tc_enter()));
    connect(form->button_cancel(),SIGNAL(clicked()),this,SLOT(tc_cancel()));

    live_window = new Live();
    connect(live_window,SIGNAL(request_money_list()),this,SLOT(pu_money_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initlimit(QStringList &list)
{
    ui->label_minLimit->setText(list.at(0));
    ui->label_tieMinLimit->setText(list.at(1));
    ui->label_pairMinLimit->setText(list.at(2));
}

void MainWindow::pu_init()
{
    // 禁用初始化按钮
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){   
        // 发送初始化请求
        manager->setStatus(INIT);
        manager->setInterface("bjl_desk_ini");
        manager->postData(QByteArray());
    }
}

void MainWindow::apply_start(){
    m_timer_count_down->start(1000);
}

void MainWindow::pu_start()
{
    ui->pu_start->setEnabled(false);
    m_bankerPair = 0;
    m_playerPair = 0;
    m_game = 0;

    request_start();
}

void MainWindow::pu_changeXue()
{
    int choose = QMessageBox::question(this,QString("换靴"),QString("确认换靴？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        manager->setStatus(CHNAGEBOOT);
        manager->setInterface("bjl_change_boot");
        manager->postData(QByteArray());
    }
}


void MainWindow::pu_useless(){
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        manager->setStatus(USELESS);
        manager->setInterface("bjl_game_burn");
        QByteArray postData;
        postData.append(QString("boot_num="));postData.append(ui->label_times_xue->text());
        postData.append(QString("&pave_num="));postData.append(ui->label_times_pu->text());
        manager->postData(postData);
        // 禁用作废按钮
        ui->pu_useless->setEnabled(false);
    }
}

void MainWindow::pu_zhuang()
{
    m_game = 7;
    ui->label_result->setText(ui->label_result->text().append("庄赢"));
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);
}

void MainWindow::pu_zhuangdui()
{
    m_bankerPair = 2;
    ui->label_result->setText(ui->label_result->text().append("庄对"));
    ui->pu_zhuangdui->setEnabled(false);
}

void MainWindow::pu_xian()
{
    m_game = 4;
    ui->label_result->setText(ui->label_result->text().append("闲赢"));
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);

    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::pu_xiandui()
{
    m_playerPair = 5;
    ui->label_result->setText(ui->label_result->text().append("闲对"));
    ui->pu_xiandui->setEnabled(false);
}

void MainWindow::pu_same()
{
    m_game = 1;
    ui->label_result->setText(ui->label_result->text().append("和"));
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);

    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::pu_login()
{
    request_first_login();
}

void MainWindow::pu_leave()
{
    this->close();
}

void MainWindow::pu_money_list()
{
    request_money();
}

void MainWindow::on_money()
{
    live_window->show();
}

void MainWindow::count_down()
{
    label_count_down->setText(QString::number(times));
    if(--times < 0){
        m_timer_count_down->stop();
        label_count_down->setText("");

        request_top_three();

        ui->pu_enter->setEnabled(true);
        ui->pu_cancel->setEnabled(true);
        ui->pu_leave->setEnabled(true);
        ui->pu_zhuang->setEnabled(true);
        ui->pu_zhuangdui->setEnabled(true);
        ui->pu_xian->setEnabled(true);
        ui->pu_xiandui->setEnabled(true);
        ui->pu_same->setEnabled(true);
        ui->pu_enter->setEnabled(true);
        ui->pu_cancel->setEnabled(true);
        ui->pu_useless->setEnabled(true);
    }
}

void MainWindow::tc_cancel()
{
    form->hide();
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::on_init()
{
    m_link_reslut = m_link_reslut_head;
    m_game = 0;
    m_playerPair = 0;
    m_bankerPair = 0;
    times = 30;
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
    manager->setInterface("bjl_dutch_game_list");
    QByteArray postData;
    postData.append("boot_num=" + ui->label_times_xue->text());
    manager->postData(postData);
}

void MainWindow::request_start()
{
    manager->setStatus(START);
    manager->setInterface("bjl_count_down");
    manager->postData(QByteArray());
}

void MainWindow::phase_zero()
{
    // 洗牌中
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
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
    ui->pu_zhuang->setEnabled(true);
    ui->pu_zhuangdui->setEnabled(true);
    ui->pu_xian->setEnabled(true);
    ui->pu_xiandui->setEnabled(true);
    ui->pu_same->setEnabled(true);
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
    // 启用作废按钮
    ui->pu_useless->setEnabled(true);
}

void MainWindow::phase_finish()
{
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::request_gameover()
{
    if(m_game == -1){
        QMessageBox box;
        box.setText("结果无效");
        box.exec();
    }
    else{
        manager->setStatus(GAMEOVER);
        manager->setInterface("bjl_game_over");
        QByteArray postData;
        postData.append(QString("boot_num="));postData.append(ui->label_times_xue->text());
        postData.append(QString("&pave_num="));postData.append(ui->label_times_pu->text());
        QJsonObject json;
        json.insert("game",m_game);
        json.insert("playerPair",m_playerPair);
        json.insert("bankerPair",m_bankerPair);
        postData.append(QString("&game_num="));postData.append(QString(QJsonDocument(json).toJson()));
        manager->postData(postData);
    }
}

void MainWindow::request_top_three()
{
    manager->setInterface("bjl_bet_top_three");
    manager->setStatus(TOPTHREE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_times_xue->text());
    postData.append("&pave_num=" + ui->label_times_pu->text());
    manager->postData(postData);
}

void MainWindow::request_top_five()
{
    manager->setInterface("bjl_bingo_top_five");
    manager->setStatus(TOPFIVE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_times_xue->text());
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

void MainWindow::request_first_login()
{
    QByteArray postData;
    QString str = "desk=a5&password=123456";
    postData.append(str);
    manager->setStatus(LOGIN);
    manager->setInterface("dutch_login");
    manager->postData(postData);
}

void MainWindow::reqeust_second_login(QString live_user,QString password)
{
    second_manager->setInterface("live_login");
    second_manager->setStatus(SECONDLOGIN);
    QByteArray postData;
    postData.append(QString("live_user=" + live_user));
    postData.append(QString("&password=" + password));

    //?
    second_manager->postData(postData);
}

void MainWindow::request_init()
{
    manager->setStatus(INIT);
    manager->setInterface("bjl_desk_ini");
    manager->postData(QByteArray());
}

void MainWindow::responsed_login(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        qDebug() << "desk login success";

        QJsonObject data = json.value("data").toObject();
        unsigned int desk_id = data.value("desk_id").toInt();
        qDebug() << "desk_id : " << desk_id;
        QString desk_token = data.value("desk_token").toString();
        qDebug() << "desk_token : " << desk_token;
        manager->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
        manager->setRawHeader("desk_token",desk_token.toUtf8());

        unsigned int minLimit = json.value("minLimit").toInt();
        unsigned int tieMinLimit = json.value("tieMinLimit").toInt();
        unsigned int pairMinLimit = json.value("pairMinLimit").toInt();

        ui->label_minLimit->setText(QString::number(minLimit));
        ui->label_tieMinLimit->setText(QString::number(tieMinLimit));
        ui->label_pairMinLimit->setText(QString::number(pairMinLimit));

        reqeust_second_login(login_window->get_live_user(),login_window->get_password());
    }
    else{
        QMessageBox box;
        box.setText("荷官登录失败");
        box.exec();
    }
}

void MainWindow::responsed_second_login(QNetworkReply *reply){
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
        m_tcpsocket->connectToHost(QHostAddress(QString("129.211.114.135")),23001);
    }
    else{
        QMessageBox box;
        box.setText("主播登录失败");
        box.exec();
    }
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
        ui->label_times_xue->setText(QString::number(boot_num));
        ui->label_times_pu->setText(QString::number(pave_num));

        Link *node = m_link_reslut_head;
        while(node->next != NULL){
            node->data->setText("");
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node = node->next;

        }

        m_link_reslut = m_link_reslut_head;
    }
    else{
        QMessageBox box;
        box.setText("初始化失败");
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

        ui->label_times_xue->setText(QString::number(BootNum));
        ui->label_times_pu->setText(QString::number(PaveNum));
        ui->label_desk_id->setText(DeskName);

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
        QJsonArray array = data.at(0)["list"].toArray();
        result_list(array);
    }
    else{
        QMessageBox box;
        box.setText("获取历史记录失败");
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
        ui->label_times_xue->setText(QString::number(boot_num));
        ui->label_times_pu->setText(QString::number(pave_num));
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

void MainWindow::responsed_changeBoot(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonObject data = json.value("data").toObject();
        unsigned int boot_num = data.value("boot_num").toInt();
        unsigned int pave_num = data.value("pave_num").toInt();
        ui->label_times_xue->setText(QString::number(boot_num));
        ui->label_times_pu->setText(QString::number(pave_num));
        Link* node = m_link_reslut_head;
        while(node->next != nullptr){
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node->data->setText("");
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
        QString path = QString("border-image: url(:/result/image/result/useless.png;");
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(path));
        result_increase();
        // 禁用结算取消按钮
        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);
        // 禁用结果按钮
        ui->pu_zhuang->setEnabled(false);
        ui->pu_xian->setEnabled(false);
        ui->pu_same->setEnabled(false);
        ui->pu_zhuangdui->setEnabled(false);
        ui->pu_xiandui->setEnabled(false);
        // 禁用作废按钮
        ui->pu_useless->setEnabled(false);
        // 启用开局按钮
        ui->pu_start->setEnabled(true);
        // 恢复倒计时
        this->times = 30;
    }
    else{
        ui->pu_useless->setEnabled(true);
        QMessageBox box;
        box.setText("作废失败");
        box.exec();
    }
}

void MainWindow::responsed_gameover(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QString path = QString(":/result/image/result/");//:/result/image/result/same.png
        QString up = "上铺：";
        switch (m_game) {
        case 7:{
            up.append("庄赢");
            path.append("zhuang");
            break;
        }
        case 4:{
            up.append("闲赢");
            path.append("xian");
            break;
        }
        case 1:{
            up.append("和");
            path.append("same");
            break;
        }
        }
        if(m_bankerPair == 2){
            up.append("庄对");
            path.append("zhuangdui");
        }
        if(m_playerPair == 5){
            up.append("闲对");
            path.append("xiandui");
        }
        path.append(".png");
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
        result_increase();
        // 禁用结算取消按钮
        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);
        form->hide();
        ui->label_result->setText("");
        // 禁用结果按钮
        ui->pu_zhuang->setEnabled(false);
        ui->pu_xian->setEnabled(false);
        ui->pu_same->setEnabled(false);
        ui->pu_zhuangdui->setEnabled(false);
        ui->pu_xiandui->setEnabled(false);
        // 禁用作废按钮
        //ui->pu_useless->setEnabled(false);
        // 启用开局按钮
        ui->pu_start->setEnabled(true);
        // 恢复倒计时
        this->times = 30;
    }
    else{
        ui->pu_enter->setEnabled(true);
        ui->pu_cancel->setEnabled(true);
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
            n->setText(QString::number(num));
            a->setText(NickName);
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

void MainWindow::result_increase(){
    if(m_link_reslut->next == nullptr){
        Link* node = m_link_reslut_head;
        for (int i = 0;node->next != nullptr;i++) {
            node->data->setStyleSheet(node->next->data->styleSheet());
            node->data->setText(node->next->data->text());
            node = node->next;
        }
        node->data->setText("");
        node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
    else{
        m_link_reslut = m_link_reslut->next;
    }
}


void MainWindow::result_list(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    // 获取结果和规律的图片
    for(int i = 0;i < array.count();i++){
        QString path = QString(":/result/image/result/");//:/result/image/result/
        QString up = "上铺：";
        m_game_str = array.at(i)["game"].toString();
        if(m_game_str == "庄"){
            m_game = 7;
            path.append("zhuang");
            up.append("庄赢");
        }
        else if(m_game_str == "闲"){
            m_game = 4;
            path.append("xian");
            up.append("闲赢");
        }
        else if(m_game_str == "和"){
            m_game = 1;
            path.append("same");
            up.append("和");
        }
        else if(m_game_str == ""){
            m_game = 0;
            path.append("useless");
            up.append("作废");
        }
        m_bankerPair_str = array.at(i)["bankerPair"].toString();
        if(m_bankerPair_str == "庄对"){
            m_bankerPair = 2;
            path.append("zhuangdui");
            up.append("庄对");
        }
        else{
            m_bankerPair = 0;
        }
        m_playerPair_str = array.at(i)["playerPair"].toString();
        if(m_playerPair_str == "闲对"){
            m_playerPair = 5;
            path.append("xiandui");
            up.append("闲对");
        }
        else{
            m_playerPair = 0;
        }
        path.append(".png");

       // ui->label_up_pave->setText(up);
        // 更新结果样式表
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
        // 指向下一个结果 label
        result_increase();
    }
}

void MainWindow::on_enter()
{
    // 禁用结算 取消按钮
    ui->pu_enter->setEnabled(false);
    ui->pu_cancel->setEnabled(false);

    form->init(ui->label_desk_id->text(),ui->label_times_xue->text(),ui->label_times_pu->text(),ui->label_result->text());
    form->show();
    form->move(600,400);
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

void MainWindow::tc_enter()
{
    request_gameover();
}

void MainWindow::on_cancel()
{
    // 初始化结果值
    m_game = -1;
    m_playerPair = 0;
    m_bankerPair = 0;
    ui->label_result->setText("");

    // 启用结果按钮
    ui->pu_zhuang->setEnabled(true);
    ui->pu_xian->setEnabled(true);
    ui->pu_same->setEnabled(true);
    // 启用结果对按钮
    ui->pu_zhuangdui->setEnabled(true);
    ui->pu_xiandui->setEnabled(true);
    // 启用结算按钮
    ui->pu_enter->setEnabled(true);
}
///////////////////////////////added by kris,2020-6-16
void MainWindow::pintosend(QDataStream &stream,QString id,QString token)
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

            //sendLoginMsg(out);

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

void MainWindow::sendMessage(QString id,QString token)
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

void MainWindow::connectedServer()
{
    sendMessage(_long_id,_long_token);
    qDebug() << "connected server success......";
}
