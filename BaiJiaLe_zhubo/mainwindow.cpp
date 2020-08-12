#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHostAddress>
#include <QQmlContext>

enum {ROOMINFO,RECORD,GAMEOVER,INIT,START,CHNAGEBOOT,USELESS,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY,BAN,STOP};

MainWindow::MainWindow(QWidget *parent)
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
    loginArg.userid = "VIP2";
    loginArg.passwd = "e5134a96afacbcb0";
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
    moneyArg.inter = "live_reward_list";
    moneyArg.status = MONEY;
    moneyArg.widget = this;
    moneyArg.manager = second_manager;
    module_money = new MMoney(&moneyArg);

    MTopThreeArg threeArg;
    threeArg.status = TOPTHREE;
    threeArg.manager = manager;
    threeArg.times_pu = ui->label_times_pu;
    threeArg.times_xue = ui->label_times_xue;
    threeArg.inter = "bjl_bet_top_three";
    module_topThree = new MTopThree(&threeArg);
    QVBoxLayout *vbox = new QVBoxLayout(ui->groupBox_3);
    vbox->addWidget(module_topThree);
    vbox->setMargin(0);
    ui->groupBox_3->setLayout(vbox);

    MTopFiveArg fiveArg;
    fiveArg.status = TOPFIVE;
    fiveArg.manager = manager;
    fiveArg.times_pu = ui->label_times_pu;
    fiveArg.times_xue = ui->label_times_xue;
    fiveArg.inter = "bjl_bingo_top_five";
    module_topFive = new MTopFive(&fiveArg);
    QVBoxLayout *vbox_five = new QVBoxLayout(ui->groupBox_4);
    vbox_five->addWidget(module_topFive);
    vbox_five->setMargin(0);
    ui->groupBox_4->setLayout(vbox_five);


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
    gameOverArg.inter = "bjl_game_over";
    gameOverArg.bankerPair = ui->pu_zhuangdui;
    gameOverArg.playerPair = ui->pu_xiandui;
    module_gameOver = new MGameOver(&gameOverArg);

    MRoomInfoArg roomInfoArg;
    roomInfoArg.status = ROOMINFO;
    roomInfoArg.manager = manager;
    roomInfoArg.inter = "HeGuanRoominfo";
    roomInfoArg.deskId = ui->label_desk_id;
    roomInfoArg.timesBoot = ui->label_times_xue;
    roomInfoArg.timesPave = ui->label_times_pu;
    roomInfoArg.limit = ui->label_minLimit;
    roomInfoArg.pairLimit = ui->label_pairMinLimit;
    roomInfoArg.tieLimit = ui->label_tieMinLimit;
    module_roomInfo = new MRoomInfo(&roomInfoArg);

    MPhaseArg phaseArg;
    phaseArg.tie = ui->pu_same;
    phaseArg.enter = ui->pu_enter;
    phaseArg.leave = ui->pu_leave;
    phaseArg.start = ui->pu_start;
    phaseArg.banker = ui->pu_zhuang;
    phaseArg.cancel = ui->pu_cancel;
    phaseArg.player = ui->pu_xian;
    phaseArg.useless = ui->pu_useless;
    phaseArg.bankerPair = ui->pu_zhuangdui;
    phaseArg.changeBoot = ui->pu_changeXue;
    phaseArg.playerPair = ui->pu_xiandui;

    phaseArg.stop = ui->pu_stop;
    phaseArg.manager = manager;
    phaseArg.status_stop = STOP;
    phaseArg.interface_stop = "bjl_early_stop";

    module_phase = new MPhase(&phaseArg,this);

    MRecordArg recordArg;
    recordArg.boot = ui->label_times_xue;
    recordArg.grid = ui->gridLayout_2;
    recordArg.status = RECORD;
    recordArg.inter = "bjl_dutch_game_list";
    recordArg.manager = manager;
    module_record = new MRecord(&recordArg);

    MStartArg startArg;
    startArg.button = ui->pu_start;
    startArg.status = START;
    startArg.manager = manager;
    startArg.inter = "bjl_count_down";
    startArg.boot = ui->label_times_xue;
    startArg.pave = ui->label_times_pu;
    module_start = new MStart(&startArg);

    MUselessArg uselessArg;
    uselessArg.useless = ui->pu_useless;
    uselessArg.boot = ui->label_times_xue;
    uselessArg.pave = ui->label_times_pu;
    uselessArg.status = USELESS;
    uselessArg.manager = manager;
    uselessArg.inter = "bjl_game_burn";
    module_useless = new MUseless(&uselessArg);

    MChangeBootArg changBootArg;
    changBootArg.boot = ui->label_times_xue;
    changBootArg.pave = ui->label_times_pu;
    changBootArg.status = CHNAGEBOOT;
    changBootArg.manager = manager;
    changBootArg.changeBoot = ui->pu_changeXue;
    changBootArg.inter = "bjl_change_boot";
    module_changeBoot = new MChangeBoot(&changBootArg);

    MInitArg initArg;
    initArg.boot = ui->label_times_xue;
    initArg.pave = ui->label_times_pu;
    initArg.status = INIT;
    initArg.manager = manager;
    initArg.inter = "bjl_desk_ini";
    module_init = new MInit(&initArg);

    MChatArg chatArg;
    chatArg.status = BAN;
    chatArg.manager_clear = manager;
    chatArg.manager = second_manager;
    chatArg.inter = "live_ban_user";
    chatArg.tcpSocket = m_tcpsocket;

    chatArg.desk_id = &(module_login->desk_id);
    chatArg.manager_clear = second_manager;

    module_chat = new MChat(&chatArg);
    QQmlContext *context = ui->quickWidget->rootContext();
    context->setContextProperty("module_chat",module_chat);
    ui->quickWidget->setSource(QUrl("qrc:/qml/MChat.qml"));

    module_reword = new MReword(this);
    connect(module_chat,SIGNAL(show_reword(QString,int)),module_reword,SLOT(show_reword(QString,int)));

    module_leave = new MLeave(ui->pu_leave,this);

    connect(module_login,SIGNAL(successed()),module_roomInfo,SLOT(request_room_info()));
    connect(module_roomInfo,SIGNAL(send_phase(int,int,int,int,int)),module_phase,SLOT(to_phase(int,int,int,int,int)));

    connect(module_init,SIGNAL(inited()),module_record,SLOT(request_record()));
    connect(module_changeBoot,SIGNAL(changed()),module_phase,SLOT(on_finished()));
    connect(module_changeBoot,SIGNAL(changed()),module_record,SLOT(request_record()));
    connect(module_useless,SIGNAL(uselessed()),module_record,SLOT(on_useless()));
    connect(module_useless,SIGNAL(uselessed()),module_phase,SLOT(on_useless()));
    connect(module_start,SIGNAL(successed()),module_phase,SLOT(on_started()));
    connect(module_start,SIGNAL(successed()),module_topThree,SLOT(clear()));
    connect(module_start,SIGNAL(successed()),module_topFive,SLOT(request_top_five()));
    connect(module_roomInfo,SIGNAL(send_phase(int,int,int,int,int)),module_record,SLOT(request_record()));
    connect(module_gameOver,SIGNAL(gameOver(QString,QString,QString)),module_record,SLOT(apply_record(QString,QString,QString)));
    connect(module_record,SIGNAL(finished()),module_topThree,SLOT(request_top_three()));
    connect(module_phase,SIGNAL(timeout()),module_gameOver,SLOT(clear()));
    connect(module_chat,SIGNAL(show_top_three(QJsonObject)),module_topThree,SLOT(update_panel(QJsonObject)));
    connect(module_gameOver,SIGNAL(gameOver(QString,QString,QString)),module_phase,SLOT(on_finished()));
    connect(module_gameOver,SIGNAL(gameOver(QString,QString,QString)),module_topThree,SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
