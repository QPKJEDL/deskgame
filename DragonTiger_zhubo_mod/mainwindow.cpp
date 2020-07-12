#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHostAddress>
QString URL = "101.32.22.231:8210";

// lh a1 // bjl a5 // nn a2

enum {CHAT,LOGIN,START,CHANGEBOOT,ROOMINFO,RECORD,SUMMIT,USELESS,INIT,SECONDLOGIN,TOPTHREE,TOPTHREETWO,TOPFIVE,MONEY,BAN};

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new MNetManager;
    manager->setIp("101.32.22.231:8210");
    manager->setHeader("application/x-www-form-urlencoded");

    second_manager = new MNetManager;
    second_manager->setIp("101.32.22.231:8210");
    second_manager->setHeader("application/x-www-form-urlencoded");

    m_tcpsocket = new QTcpSocket(this);

    // 模块
    MLoginArg loginArg;
    loginArg.userid = "VIP11";
    loginArg.passwd = "7c6f50493eed622b";
    loginArg.IP = "101.32.22.231";
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
    threeArg.times_pu = ui->label_pus;
    threeArg.times_xue = ui->label_xues;
    threeArg.interface = "lh_bet_top_three";
    module_topThree = new MTopThree(&threeArg);
    QVBoxLayout *vbox = new QVBoxLayout(ui->groupBox_4);
    vbox->addWidget(module_topThree);
    vbox->setMargin(0);
    ui->groupBox_4->setLayout(vbox);

    MTopFiveArg fiveArg;
    fiveArg.status = TOPFIVE;
    fiveArg.manager = manager;
    fiveArg.times_pu = ui->label_pus;
    fiveArg.times_xue = ui->label_xues;
    fiveArg.interface = "lh_bingo_top_five";
    module_topFive = new MTopFive(&fiveArg);
    QVBoxLayout *vbox_five = new QVBoxLayout(ui->groupBox_5);
    vbox_five->addWidget(module_topFive);
    vbox_five->setMargin(0);
    ui->groupBox_5->setLayout(vbox_five);

    MGameOverArg gameOverArg;
    gameOverArg.tie = ui->pu_same;
    gameOverArg.boot = ui->label_xues;
    gameOverArg.pave = ui->label_pus;
    gameOverArg.enter = ui->pu_enter;
    gameOverArg.banker = ui->pu_long;
    gameOverArg.cancel = ui->pu_cancel;
    gameOverArg.player = ui->pu_tiger;
    gameOverArg.result = ui->label_result;
    gameOverArg.status = SUMMIT;
    gameOverArg.desk_id = ui->label_2;
    gameOverArg.manager = manager;
    gameOverArg.interface = "lh_game_over";
    module_gameOver = new MGameOver(&gameOverArg);

    MRoomInfoArg roomInfoArg;
    roomInfoArg.deskId = ui->label_2;
    roomInfoArg.status = ROOMINFO;
    roomInfoArg.manager = manager;
    roomInfoArg.interface = "HeGuanRoominfo";
    roomInfoArg.timesBoot = ui->label_xues;
    roomInfoArg.timesPave = ui->label_pus;
    roomInfoArg.limit = ui->label_minLimit;
    roomInfoArg.tieLimit = ui->label_tieMinLimit;
    module_roomInfo = new MRoomInfo(&roomInfoArg);

    MPhaseArg phaseArg;
    phaseArg.tie = ui->pu_same;
    phaseArg.init = ui->pu_init;
    phaseArg.enter = ui->pu_enter;
    phaseArg.leave = ui->pu_leave;
    phaseArg.start = ui->pu_start;
    phaseArg.banker = ui->pu_long;
    phaseArg.cancel = ui->pu_cancel;
    phaseArg.player = ui->pu_tiger;
    phaseArg.useless = ui->pu_useless;
    phaseArg.changeBoot = ui->pu_changeXue;
    module_phase = new MPhase(&phaseArg);

    MRecordArg recordArg;
    recordArg.boot = ui->label_xues;
    recordArg.grid = ui->gridLayout_2;
    recordArg.status = RECORD;
    recordArg.interface = "lh_dutch_game_list";
    recordArg.manager = manager;
    module_record = new MRecord(&recordArg);

    MStartArg startArg;
    startArg.button = ui->pu_start;
    startArg.status = START;
    startArg.manager = manager;
    startArg.interface = "lh_count_down";
    startArg.boot = ui->label_xues;
    startArg.pave = ui->label_pus;
    module_start = new MStart(&startArg);

    MUselessArg uselessArg;
    uselessArg.useless = ui->pu_useless;
    uselessArg.boot = ui->label_xues;
    uselessArg.pave = ui->label_pus;
    uselessArg.status = USELESS;
    uselessArg.manager = manager;
    uselessArg.interface = "lh_game_burn";
    module_useless = new MUseless(&uselessArg);

    MChangeBootArg changBootArg;
    changBootArg.boot = ui->label_xues;
    changBootArg.pave = ui->label_pus;
    changBootArg.status = CHANGEBOOT;
    changBootArg.manager = manager;
    changBootArg.changeBoot = ui->pu_changeXue;
    changBootArg.interface = "lh_change_boot";
    module_changeBoot = new MChangeBoot(&changBootArg);

    MInitArg initArg;
    initArg.boot = ui->label_xues;
    initArg.pave = ui->label_pus;
    initArg.status = INIT;
    initArg.manager = manager;
    initArg.init = ui->pu_init;
    initArg.interface = "lh_desk_ini";
    module_init = new MInit(&initArg);

    MChatArg chatArg;
    chatArg.grid = ui->ChatPanel;
    chatArg.status = CHAT;
    chatArg.manager = second_manager;
    chatArg.interface = "live_ban_user";
    chatArg.tcpSocket = m_tcpsocket;
    module_chat = new MChat(&chatArg);

    module_leave = new MLeave(ui->pu_leave,this);

    connect(module_init,SIGNAL(inited()),module_record,SLOT(request_record()));
    connect(module_changeBoot,SIGNAL(changed()),module_phase,SLOT(on_finished()));
    connect(module_changeBoot,SIGNAL(changed()),module_record,SLOT(request_record()));
    connect(module_useless,SIGNAL(uselessed()),module_record,SLOT(on_useless()));
    connect(module_useless,SIGNAL(uselessed()),module_phase,SLOT(on_useless()));
    connect(module_start,SIGNAL(successed()),module_phase,SLOT(on_started()));
    connect(module_login,SIGNAL(successed()),module_roomInfo,SLOT(request_room_info()));
    connect(module_roomInfo,SIGNAL(send_phase(int,int,int,int)),module_phase,SLOT(to_phase(int,int,int,int)));
    connect(module_roomInfo,SIGNAL(send_phase(int,int,int,int)),module_record,SLOT(request_record()));
    connect(module_gameOver,SIGNAL(gameOver(QString)),module_record,SLOT(apply_record(QString)));
    connect(module_phase,SIGNAL(timeout()),module_topThree,SLOT(request_top_three()));
    connect(module_phase,SIGNAL(timeout()),module_topFive,SLOT(request_top_five()));
    connect(module_phase,SIGNAL(timeout()),module_gameOver,SLOT(clear()));
    connect(module_gameOver,SIGNAL(gameOver(QString)),module_phase,SLOT(on_finished()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
