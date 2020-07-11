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

enum {START,ROOMINFO,RECORD,CHNAGEBOOT,ROOMCARD,LOCATE,FAPAI,SUMMIT,USELESS,INIT,LOGIN,SECONDLOGIN,TOPTHREE,TOPFIVE,MONEY,CHAT};

//static QString URL = "101.32.22.231:8210";
//static QString URL = "129.211.114.135:8210";
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

    ui->lineEdit_2->setVisible(false);
    /////////////////////////////////////////////////////////////////////////////
    MLoginArg loginArg;
    loginArg.userid = "VIP5";
    loginArg.passwd = "9fae1f45c7ddeb94";
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

    MRoomInfoArg roomInfoArg;
    roomInfoArg.deskId = ui->desk_num;
    roomInfoArg.status = ROOMINFO;
    roomInfoArg.manager = manager;
    roomInfoArg.interface = "HeGuanRoominfo";
    roomInfoArg.timesBoot = ui->xue_times;
    roomInfoArg.timesPave = ui->pu_times;
    module_roomInfo = new MRoomInfo(&roomInfoArg);

    MPhaseArg phaseArg;
    phaseArg.status_locate = LOCATE;
    phaseArg.manager = manager;
    phaseArg.interface_locate = "A89Orientation";
    phaseArg.init = ui->pu_init;
    phaseArg.leave = ui->pu_exit;
    phaseArg.start = ui->pu_start;
    phaseArg.useless = ui->button_useless;
    phaseArg.locate = ui->button_locate;
    phaseArg.input = ui->lineEdit_2;
    phaseArg.location = ui->label_locate;
    module_phase = new MPhase(&phaseArg);

    MRoomCardArg roomCardArg;
    roomCardArg.boot = ui->xue_times;
    roomCardArg.pave = ui->pu_times;
    roomCardArg.locate = ui->button_locate;
    roomCardArg.status_roomcard = ROOMCARD;
    roomCardArg.manager = manager;
    roomCardArg.lineEdit = ui->lineEdit;
    roomCardArg.location = ui->label_locate;
    roomCardArg.interface_roomcard = "HeGuanA89RoomCard";
    roomCardArg.status_fapai = FAPAI;
    roomCardArg.interface_fapai = "A89GameCard";
    module_roomCard = new MRoomCard(&roomCardArg);
    QVBoxLayout *vbox_five = new QVBoxLayout(ui->groupBox_4);
    vbox_five->addWidget(module_roomCard);
    vbox_five->setMargin(0);
    ui->groupBox_4->setLayout(vbox_five);

    MUselessArg uselessArg;
    uselessArg.useless = ui->button_useless;
    uselessArg.boot = ui->xue_times;
    uselessArg.pave = ui->pu_times;
    uselessArg.status = USELESS;
    uselessArg.manager = manager;
    uselessArg.interface = "A89Abolish";
    module_useless = new MUseless(&uselessArg);

    MStartArg startArg;
    startArg.button = ui->pu_start;
    startArg.status = START;
    startArg.manager = manager;
    startArg.interface = "A89RoomProcess";
    startArg.boot = ui->xue_times;
    startArg.pave = ui->pu_times;
    module_start = new MStart(&startArg);

    MSummitArg summitArg;
    summitArg.button = ui->button_summit;
    summitArg.status = SUMMIT;
    summitArg.manager = manager;
    summitArg.interface = "A89GetGameResult";
    summitArg.boot = ui->xue_times;
    summitArg.pave = ui->pu_times;
    module_summit = new MSummit(&summitArg);

    MInitArg initArg;
    initArg.boot = ui->xue_times;
    initArg.pave = ui->pu_times;
    initArg.status = INIT;
    initArg.manager = manager;
    initArg.init = ui->pu_init;
    initArg.interface = "A89RonmInitialize";
    module_init = new MInit(&initArg);

    MTopThreeArg threeArg;
    threeArg.status = TOPTHREE;
    threeArg.manager = manager;
    threeArg.times_pu = ui->pu_times;
    threeArg.times_xue = ui->xue_times;
    threeArg.interface = "A89BetTop3";
    module_topThree = new MTopThree(&threeArg);
    QVBoxLayout *vbox = new QVBoxLayout(ui->groupBox_6);
    vbox->addWidget(module_topThree);
    vbox->setMargin(0);
    ui->groupBox_5->setLayout(vbox);

    MChangeBootArg changBootArg;
    changBootArg.boot = ui->xue_times;
    changBootArg.pave = ui->pu_times;
    changBootArg.status = CHNAGEBOOT;
    changBootArg.manager = manager;
    changBootArg.changeBoot = nullptr;
    changBootArg.interface = "";
    module_changeBoot = new MChangeBoot(&changBootArg);

    MMoneyArg moneyArg;
    moneyArg.interface = "live_reward_list";
    moneyArg.status = MONEY;
    moneyArg.widget = this;
    moneyArg.manager = second_manager;
    module_money = new MMoney(&moneyArg);

    MChatArg chatArg;
    chatArg.grid = ui->gridLayout_4;
    chatArg.status = CHAT;
    chatArg.manager = second_manager;
    chatArg.interface = "live_ban_user";
    chatArg.tcpSocket = m_tcpsocket;
    module_chat = new MChat(&chatArg);

    module_leave = new MLeave(ui->pu_exit,this);

    connect(module_login,SIGNAL(successed()),module_roomInfo,SLOT(request_room_info()));
    connect(module_roomInfo,SIGNAL(send_phase(int,int,int,int)),module_phase,SLOT(to_phase(int,int,int,int)));
    connect(module_phase,SIGNAL(located(int)),module_roomCard,SLOT(locate(int)));
    connect(module_useless,SIGNAL(uselessed()),module_phase,SLOT(on_finished()));
    connect(module_useless,SIGNAL(uselessed()),module_roomCard,SLOT(clear()));
    connect(module_start,SIGNAL(successed()),module_phase,SLOT(on_start()));
    connect(module_summit,SIGNAL(summited()),module_roomCard,SLOT(clear()));
    connect(module_summit,SIGNAL(summited()),module_phase,SLOT(on_finished()));
    connect(module_init,SIGNAL(inited()),module_phase,SLOT(on_start()));
    connect(module_init,SIGNAL(inited()),module_roomCard,SLOT(clear()));
    connect(module_roomCard,SIGNAL(finished()),module_summit,SLOT(cardFinished()));
    connect(module_phase,SIGNAL(phase_kaipai()),module_roomCard,SLOT(request_roomCard()));
    connect(module_roomCard,SIGNAL(locate_zero()),module_phase,SLOT(on_located()));
    connect(module_roomCard,SIGNAL(locate_zero()),module_topThree,SLOT(request_top_three()));
    connect(module_phase,SIGNAL(timeout()),module_topThree,SLOT(request_top_three()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
