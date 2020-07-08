#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHostAddress>

#include "qqchat.h"

//QString URL = "192.168.0.104:8210";
//QString URL = "129.211.114.135:8210";

enum {ROOMINFO,RECORD,GAMEOVER,INIT,START,CHNAGEBOOT,USELESS,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY,BAN};

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

    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(CHNAGEBOOT,&MainWindow::responsed_changeBoot);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(TOPFIVE,&MainWindow::responsed_top_five);


    manager = new MNetManager;
    manager->setIp("129.211.114.135:8210");
    manager->setHeader("application/x-www-form-urlencoded");
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    second_manager = new MNetManager;
    second_manager->setIp("129.211.114.135:8210");
    second_manager->setHeader("application/x-www-form-urlencoded");
    connect(second_manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    m_tcpsocket = new QTcpSocket(this);

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
    // 链接槽函数
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    connect(ui->pu_changeXue,SIGNAL(clicked()),this,SLOT(pu_changeXue()));
    connect(ui->pu_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(ui->pu_leave,SIGNAL(clicked()),this,SLOT(pu_leave()));

    // 模块
    MLoginArg loginArg;
    loginArg.IP = "129.211.114.135";
    loginArg.widget = this;
    loginArg.tcpsocket = m_tcpsocket;
    loginArg.status_first = LOGIN;
    loginArg.status_second = SECONDLOGIN;
    loginArg.manager_first = manager;
    loginArg.manager_second = second_manager;
    loginArg.interface_first = "dutch_login";
    loginArg.interface_second = "live_login";
    module_login = new MLogin(&loginArg);
    module_login->showFullScreen();

    MMoneyArg moneyArg;
    moneyArg.interface = "live_reward_list";
    moneyArg.status = MONEY;
    moneyArg.widget = this;
    moneyArg.manager = second_manager;
    module_money = new MMoney(&moneyArg);

    MTopThreeArg threeArg;
    threeArg.status = TOPTHREE;
    threeArg.manager = manager;
    threeArg.times_pu = ui->label_times_pu;
    threeArg.times_xue = ui->label_times_xue;
    threeArg.interface = "bjl_bet_top_three";
    module_topThree = new MTopThree(&threeArg);
    QVBoxLayout *vbox = new QVBoxLayout(ui->groupBox_3);
    vbox->addWidget(module_topThree);
    vbox->setMargin(0);
    ui->groupBox_3->setLayout(vbox);

    MGameOverArg gameOverArg;
    gameOverArg.tie = ui->pu_same;
    gameOverArg.boot = ui->label_times_xue;
    gameOverArg.pave = ui->label_times_pu;
    gameOverArg.enter = ui->pu_enter;
    gameOverArg.banker = ui->pu_zhuang;
    gameOverArg.cancel = ui->pu_cancel;
    gameOverArg.player = ui->pu_xian;
    gameOverArg.result = ui->label_result;
    gameOverArg.status = GAMEOVER;
    gameOverArg.desk_id = ui->label_desk_id;
    gameOverArg.manager = manager;
    gameOverArg.interface = "bjl_game_over";
    gameOverArg.bankerPair = ui->pu_zhuangdui;
    gameOverArg.playerPair = ui->pu_xiandui;
    module_gameOver = new MGameOver(&gameOverArg);

    MRoomInfoArg roomInfoArg;
    roomInfoArg.deskId = ui->label_desk_id;
    roomInfoArg.status = ROOMINFO;
    roomInfoArg.manager = manager;
    roomInfoArg.interface = "HeGuanRoominfo";
    roomInfoArg.timesBoot = ui->label_times_xue;
    roomInfoArg.timesPave = ui->label_times_pu;
    module_roomInfo = new MRoomInfo(&roomInfoArg);

    module_leave = new MLeave(ui->pu_leave,this);

    connect(module_login,SIGNAL(successed()),module_roomInfo,SLOT(on_logined()));
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

void MainWindow::count_down()
{
    label_count_down->setText(QString::number(times));
    if(--times < 0){
        m_timer_count_down->stop();
        label_count_down->setText("");

        module_topThree->request_top_three();

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

void MainWindow::on_init()
{
    m_link_reslut = m_link_reslut_head;
    m_game = 0;
    m_playerPair = 0;
    m_bankerPair = 0;
    times = 30;
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

void MainWindow::request_top_five()
{
    manager->setInterface("bjl_bingo_top_five");
    manager->setStatus(TOPFIVE);
    QByteArray postData;
    postData.append("boot_num=" + ui->label_times_xue->text());
    manager->postData(postData);
}

void MainWindow::request_init()
{
    manager->setStatus(INIT);
    manager->setInterface("bjl_desk_ini");
    manager->postData(QByteArray());
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
        module_topThree->clear();

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

//void MainWindow::responsed_gameover(QNetworkReply *reply)
//{
//    QByteArray bytes = reply->readAll();
//    QJsonObject json = QJsonDocument::fromJson(bytes).object();
//    unsigned int status = json.value("status").toInt();
//    if(status == 1){
//        QString path = QString(":/result/image/result/");//:/result/image/result/same.png
//        QString up = "上铺：";
//        switch (m_game) {
//        case 7:{
//            up.append("庄赢");
//            path.append("zhuang");
//            break;
//        }
//        case 4:{
//            up.append("闲赢");
//            path.append("xian");
//            break;
//        }
//        case 1:{
//            up.append("和");
//            path.append("same");
//            break;
//        }
//        }
//        if(m_bankerPair == 2){
//            up.append("庄对");
//            path.append("zhuangdui");
//        }
//        if(m_playerPair == 5){
//            up.append("闲对");
//            path.append("xiandui");
//        }
//        path.append(".png");
//        QString style = "border-image: url(" + path + ");";
//        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
//        result_increase();
//        // 禁用结算取消按钮
//        ui->pu_enter->setEnabled(false);
//        ui->pu_cancel->setEnabled(false);
//        form->hide();
//        ui->label_result->setText("");
//        // 禁用结果按钮
//        ui->pu_zhuang->setEnabled(false);
//        ui->pu_xian->setEnabled(false);
//        ui->pu_same->setEnabled(false);
//        ui->pu_zhuangdui->setEnabled(false);
//        ui->pu_xiandui->setEnabled(false);
//        // 禁用作废按钮
//        //ui->pu_useless->setEnabled(false);
//        // 启用开局按钮
//        ui->pu_start->setEnabled(true);
//        // 恢复倒计时
//        this->times = 30;
//    }
//    else{
//        ui->pu_enter->setEnabled(true);
//        ui->pu_cancel->setEnabled(true);
//        QMessageBox box;
//        box.setText("结算失败");
//        box.exec();
//    }
//}

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
                n->setText(QString::number(num));
                a->setText(NickName);
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
    }
    else{
        QMessageBox box;
        box.setText("获取连续中铺记录失败");
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

void MainWindow::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow--- status";
    }
}
