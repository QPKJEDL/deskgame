#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

QString URL = "101.32.22.231:8210";

// lh a1 // bjl a5 // nn a2

enum {LOGIN,START,CHANGEBOOT,ROOMINFO,RECORD,SUMMIT,USELESS,INIT};

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 倒计时初始化
    times = 30;
    // 结果初始化
    m_result = 0;
    m_front_win = -1;

    login_window = new Login();
    manager = new MNetManager;
    manager->setIp("101.32.22.231:8210");
    manager->setHeader("application/x-www-form-urlencoded");

    // 倒计时初始化
    this->m_timer_count_down = new QTimer(this);
    connect(m_timer_count_down,SIGNAL(timeout()),this,SLOT(count_down()));

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

    // 先动态生成 超级无敌牛逼至尊双龙 所用二维数组之 270天星下凡 QLabel
    way_big = new WAY;
    way_big->dragon.m_now_row = -1;
    for (int i = 0;i < 45;i++) {
        for(int j = 0;j < 6;j++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            label->setFont(QFont(QString("方正粗黑宋简体"),25));
            label->setAlignment(Qt::AlignHCenter);
            ui->gridLayout_4->addWidget(label,j,i);

            // 270 天星听令 ~~ 归~~~ 位~~~
            way_big->labels[i][j].label = label;
        }
    }

    // 生成大眼仔拥有的 label
    way_big_eye = new WAY;
    way_big_eye->dragon.m_now_row = -1;
    for(int row = 0;row < 45;row++){
        for(int line = 0;line < 6;line++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            label->setFont(QFont(QString("方正粗黑宋简体"),25));
            label->setAlignment(Qt::AlignHCenter);
            ui->gridLayout_5->addWidget(label,line,row);

            // 270 鸡仔仔听令 ~~ 回~~~ 笼~~~
            way_big_eye->labels[row][line].label = label;
        }
    }

    // 小路扑通扑通的跳
    way_little = new WAY;
    way_little->dragon.m_now_row = -1;
    for(int row = 0;row < 45;row++){
        for(int line = 6;line < 12;line++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            label->setFont(QFont(QString("方正粗黑宋简体"),25));
            label->setAlignment(Qt::AlignHCenter);
            ui->gridLayout_5->addWidget(label,line,row);

            // 270小路回家
            way_little->labels[row][line - 6].label = label;
        }
    }

    // 凹凸路有多凹凸呢？
    way_aotu = new WAY;
    way_aotu->dragon.m_now_row = -1;
    for(int row = 45;row < 90;row++){
        for(int line = 0;line < 6;line++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            label->setFont(QFont(QString("方正粗黑宋简体"),25));
            label->setAlignment(Qt::AlignHCenter);
            ui->gridLayout_5->addWidget(label,line,row);

            // 270 凹凸
            way_aotu->labels[row - 45][line].label = label;
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

    // 连接弹窗信号
    form = new Form();
    form->setWindowFlag(Qt::FramelessWindowHint);
    connect(form->button_enter(),SIGNAL(clicked()),this,SLOT(tc_enter()));
    connect(form->button_cancel(),SIGNAL(clicked()),this,SLOT(tc_cancel()));
}

MainWindow::~MainWindow()
{
    delete ui;
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

int MainWindow::how_many(int row){
    // 这个函数可以获取大路某列的连赢次数
    int who_win = way_big->labels[row][0].who_win;
    int x = row;
    int y = 0;
    int m = 1;
    while(true){
        // 如果没到最后一行，并且
        if(y < 5 && way_big->labels[x][y + 1].who_win == who_win){
            m++;
            y++; // 向下移动一位
            continue;
        }
        // 如果走到这一步，不是到底了，就是下面没了
        // 看右边有没有
        if(way_big->labels[x + 1][y].who_win == who_win){
            m++;
            x++;
            continue;
        }
        // 如果走到这一步，说明下面或右边都没了
        return m;
    }
}

bool MainWindow::if_order(NUMBER now,int first,int offset)
{
    // 看齐整
    // 大路左边第 1 列,即 x 行， y 列
    int row = now.m_now_row - first;
    int one = how_many(row);

    // 至此，已经获得左边第一列的数量 first;
    // 获取左边第 offset 列的数量
    row = now.m_now_row - offset;
    int second = how_many(row);
    // 比较一下是否齐整
    if(one == second){
        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::if_YesOrNo(NUMBER now,int offset)
{
    // 判断“有”或“无”
    // 左边第一列
    if(way_big->labels[now.m_now_row - offset][now.m_now_line].who_win != 0){
        // 有
        return true;
    }
    else{
        if(way_big->labels[now.m_now_row - offset][now.m_now_line - 1].who_win != 0){
            // 无
            return false;
        }
        else{
            // 直落
            return true;
        }
    }
}

void MainWindow::update_ask_way()
{
    QString style;
    int game = 0;

    // 判断齐整
    if(way_big->now.m_now_line == 0 && way_big->now.m_now_row > 1){
        // 肯定需要判断 大眼仔路
        if(if_order(way_big->now,1,2)){
            // 齐整大眼仔路
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/redPoint.png") + QString(");");
            game = 7;
        }
        else{
            // 不齐整大眼仔路
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/bluePoint.png") + QString(");");
            game = 4;
        }
        // 移动到下一个大眼仔路
        qDebug() << "game : " << game;
        next_ask_way(way_big_eye,game,style);

        if(way_big->now.m_now_row > 2){
            // 可以判断小路
            if(if_order(way_big->now,1,3)){
                // 齐整小路
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/red.png") + QString(");");
                game = 7;
            }
            else{
                // 不齐整大路
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/blue.png") + QString(");");
                game = 4;
            }
            // 移动到下一个小路路
            next_ask_way(way_little,game,style);

            if(way_big->now.m_now_row > 3){
                // 可以判断凹凸路
                if(if_order(way_big->now,1,4)){
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/redLine.png") + QString(");");
                    game = 7;
                }
                else{
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/blueLine.png") + QString(");");
                    game = 4;
                }
                // 移动到下一个凹凸路
                next_ask_way(way_aotu,game,style);
            }
        }
    }

    // 判断有无 或 直落
    if(way_big->now.m_now_line > 0 && way_big->now.m_now_row > 0){
        // 肯定需要判断 大眼仔路
        if(if_YesOrNo(way_big->now,1)){
            // 有 或 直落
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/redPoint.png") + QString(");");
            game = 7;
        }
        else{
            // 无
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/bluePoint.png") + QString(");");
            game = 4;
        }
        // 移动到下一个大眼仔路
        next_ask_way(way_big_eye,game,style);

        if(way_big->now.m_now_row > 1){
            // 可以判断小路
            if(if_YesOrNo(way_big->now,2)){
                // 有 或 直落
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/red.png") + QString(");");
                game = 7;
            }
            else{
                // 无
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/blue.png") + QString(");");
                game = 4;
            }
            // 移动到下一个小路路
            next_ask_way(way_little,game,style);

            if(way_big->now.m_now_row > 2){
                // 可以判断凹凸路
                if(if_YesOrNo(way_big->now,3)){
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/redLine.png") + QString(");");
                    game = 7;
                }
                else{
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/result/blueLine.png") + QString(");");
                    game = 4;
                }
                // 移动到下一个凹凸路
                next_ask_way(way_aotu,game,style);
            }
        }
    }
}

void MainWindow::next_ask_way(WAY* way,int game,QString style)
{
    // 获取上一个问路 label 的颜色
    int now = way->first ? -1 : way->labels[way->now.m_now_row][way->now.m_now_line].who_win;

    // 如果和 now 的 who_win 相等,说明连赢
    if(game == now){
        // 还没有成龙
        if(way->dragon.m_now_row == -1){
            // 如果到底了，或者，下行同列有值，则成龙，移动到下列同行
            if(way->now.m_now_line == 5 || way->labels[way->now.m_now_row][way->now.m_now_line + 1].who_win != 0){
                // 如果已经是最后一列了
                if(way->now.m_now_row == 44){
                    for(int row = 0;row < 44;row++){
                        for(int line = 0;line < 6;line++){
                            way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());
                        }
                        for(int i = 0;i < 6;i++){
                            way->labels[44][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                        }
                    }
                }
                else{
                    way->now.m_now_row++;
                }
                way->dragon = way->now;
            }
            else if(!way->first){
                way->now = way->now.down();
            }
        }
        else{
            // 移动到下列同行，如果已经是最后一行了怎么办？
            if(way->now.m_now_row == 44){
                for(int row = 0;row < 44;row++){
                    for(int line = 0;line < 6;line++){
                        way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());
                    }
                    for(int i = 0;i < 6;i++){
                        way->labels[44][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                    }
                }
            }
            way->now.m_now_row++;
        }
    }
    // 连赢断了
    else{
        // 如果已经成龙，先找到成龙点
        if(way->dragon.m_now_row != -1){
            // 如果是第一行
            if(way->now.m_now_line == 0){
                way->now.m_now_row++;
            }
            else{
                way->now.m_now_row = way->dragon.m_now_row;
                way->now.m_now_line = 0;
            }
        }
        // 如果还没成龙，移动到右一列第一行
        else if(!way->first){
            way->now.m_now_row++;
            way->now.m_now_line = 0;
        }
        // 没有成龙
        way->dragon.m_now_row = -1;
    }
    way->first = false;
    // 必须在这里让上个问路的 label 等于向后移动之前的 label
    way->front = way->now;
    // 更新正指向的 label 的信息
    way->labels[way->now.m_now_row][way->now.m_now_line].who_win = game;
    way->labels[way->now.m_now_row][way->now.m_now_line].label->setStyleSheet(style);
}

void MainWindow::apply_init()
{
    // 初始化所有路
    way_big->init();
    way_aotu->init();
    way_little->init();
    way_big_eye->init();
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
        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
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
        ui->label_maxLimit->setText(QString::number(maxLimit));
        ui->label_minLimit->setText(QString::number(minLimit));
        ui->label_tieMaxLimit->setText(QString::number(tieMaxLimit));
        ui->label_tieMinLimit->setText(QString::number(tieMinLimit));
        login_window->close();
        this->show();
        this->showFullScreen();
        request_room_info();
    }
    else{
        QMessageBox box;
        box.setText("登录失败");
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
        ui->label_VIP_level->setText(DeskName);
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
        ui->label_score_same->setText(QString::number(sumTie));
        ui->label_score_long->setText(QString::number(sumBanker));
        ui->label_score_tiger->setText(QString::number(sumPlayer));
        QJsonArray array = data.at(0)["list"].toArray();
        apply_enter(array);
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
        QJsonObject json_object2 = json.value("data").toObject();
        unsigned int boot_num = json_object2.value("boot_num").toInt();
        unsigned int pave_num = json_object2.value("pave_num").toInt();
        ui->label_xues->setText(QString::number(boot_num));
        ui->label_pus->setText(QString::number(pave_num));
        ui->pu_changeXue->setEnabled(false);

        apply_start();
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
        ui->label_times_xue->setText(QString::number(boot_num));
        ui->label_times_pu->setText(QString::number(pave_num));

        Link* node = m_link_reslut_head;
        while(node->next != nullptr){
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node = node->next;
        }
        m_link_reslut = m_link_reslut_head;

        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
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

        ui->label_result->setText("结果:");
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
        ui->label_result->setText(QString("结果:"));
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
        ui->label_up_pave->setText(up);

        // 更新结果样式表
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));

        next_result();
        ongl_enter(path_gl);

        ui->pu_start->setEnabled(true);
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

void MainWindow::pu_login()
{
    request_login();
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

NUMBER MainWindow::next_zhuang(int offset)
{
    // 下一把是庄赢
    WAY big_way = *way_big;
    if(m_result == offset){
        // 连庄没断
        if(big_way.dragon.m_now_row != -1){
            // 如果已经成龙了
            big_way.now.m_now_row++;
        }
        else{
            // 如果没成龙
            // 如果下一个有值，则成龙,移动到下列同行
            if(big_way.now.m_now_line == 5 || big_way.labels[big_way.now.m_now_row][way_big->now.m_now_line + 1].who_win != 0){
                big_way.now.m_now_row++;
            }
            else{
                big_way.now = big_way.now.down();
            }
        }
    }
    else{
        // 断了，如果已经成龙，并且不是第一行，xxx，并回到第一行，如果是第一行，向右移动一位
        if(big_way.dragon.m_now_row != -1){
            if(big_way.dragon.m_now_line == 0){
                big_way.now.m_now_row++;
            }
            else{
                big_way.now.m_now_row = big_way.dragon.m_now_row;
                big_way.now.m_now_line = 0;
            }
        }
        else{
            big_way.now.m_now_row++;
            big_way.now.m_now_line = 0;
        }
    }
    return big_way.now;
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

        ui->label_up_pave->setText(up);
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
        if(m_game_str != ""){
            ongl_enter(path_gl);
        }
    }
}

void MainWindow::update_ask(NUMBER big_way, bool zhuang)
{
    QString style;
    if(big_way.m_now_line == 0 && big_way.m_now_row > 1){
        // 肯定需要判断 大眼仔路
        if(if_order(big_way,1,2)){
            // 齐整大眼仔路
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/result/redPoint.png);";
        }
        else{
            // 不齐整大眼仔路
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/result/bluePoint.png);";
        }
        if(zhuang){
            ui->label_lwl_one->setStyleSheet(style);
        }
        else{
            ui->label_hwl_one->setStyleSheet(style);
        }

        if(big_way.m_now_line == 0 && big_way.m_now_row > 2){
            // 肯定需要判断 小路
            if(if_order(big_way,1,3)){
                // 齐整 小路
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/result/red.png);";
            }
            else{
                // 不齐整 小路
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/result/blue.png);";
            }
            if(zhuang){
                ui->label_lwl_two->setStyleSheet(style);
            }
            else{
                ui->label_hwl_two->setStyleSheet(style);
            }
            if(big_way.m_now_line == 0 && big_way.m_now_row > 3){
                // 肯定需要判断 凹凸路
                if(if_order(big_way,1,2)){
                    // 齐整凹凸路
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/result/redLine.png);";
                }
                else{
                    // 不齐整凹凸路
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/result/blueLine.png);";
                }
                if(zhuang){
                    ui->label_lwl_three->setStyleSheet(style);
                }
                else{
                    ui->label_hwl_three->setStyleSheet(style);
                }
            }
        }
    }

    // 判断有无 或 直落
    if(big_way.m_now_line > 0 && big_way.m_now_row > 0){
        // 肯定需要判断 大眼仔路
        if(if_YesOrNo(big_way,1)){
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/result/redPoint.png);";
        }
        else{
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/result/bluePoint.png);";
        }
        if(zhuang){
            ui->label_lwl_one->setStyleSheet(style);
        }
        else{
            ui->label_hwl_one->setStyleSheet(style);
        }
        if(big_way.m_now_line > 0 && big_way.m_now_row > 1){
            // 肯定需要判断 小路
            if(if_YesOrNo(big_way,2)){
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/result/red.png);";
            }
            else{
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/result/blue.png);";
            }
            if(zhuang){
                ui->label_lwl_two->setStyleSheet(style);
            }
            else{
                ui->label_hwl_two->setStyleSheet(style);
            }
            if(big_way.m_now_line > 0 && big_way.m_now_row > 2){
                // 肯定需要判断 小路
                if(if_YesOrNo(big_way,3)){
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/result/redLine.png);";
                }
                else{
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/result/blueLine.png);";
                }
                if(zhuang){
                    ui->label_lwl_three->setStyleSheet(style);
                }
                else{
                    ui->label_hwl_three->setStyleSheet(style);
                }
            }
        }
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
    postData.append("desk=VIP11&password=7c6f50493eed622b");
    manager->postData(postData);
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
    ui->label_result->setText("结果:");
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

    form->init(ui->label_VIP_level->text(),ui->label_xues->text(),ui->label_pus->text(),ui->label_result->text());
    form->show();
    form->move(600,400);
}

void MainWindow::pu_cancel()
{
    // 初始化结果值
    m_result = -1;
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
    ui->label_result->setText("结果：龙赢");
}

void MainWindow::pu_tiger()
{
    m_result = 4;
    // 禁用按钮
    ui->pu_long->setEnabled(false);
    ui->pu_tiger->setEnabled(false);
    ui->pu_same->setEnabled(false);
    // 显示结果
    ui->label_result->setText("结果：虎赢");
}

void MainWindow::pu_same(){
    m_result = 1;
    // 禁用按钮
    ui->pu_long->setEnabled(false);
    ui->pu_tiger->setEnabled(false);
    ui->pu_same->setEnabled(false);
    // 显示结果
    ui->label_result->setText("结果：和");
}

void MainWindow::count_down(){
    ui->label_count_down->setText(QString::number(times));
    if(--times < 0){
        //倒计时完成
        m_timer_count_down->stop();
        ui->label_count_down->setText(QString(""));
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

void MainWindow::ongl_enter(QString path_gl){
    path_gl = "border-image: url(" + path_gl + ");";
    // 更新规律表
    if(m_result == 1){
        // 和
        way_big->times++;
        // 如果 前和星 不是第（0,0）位，将 m_same_times 应用到所在的 Label
        if(!way_big->first){
            way_big->labels[way_big->equa.m_now_row][way_big->equa.m_now_line].label->setText(QString::number(way_big->times));
        }
    }
    else{
        // 不是和
        way_big->times = 0;
        int front = way_big->first ? -1 : way_big->labels[way_big->front.m_now_row][way_big->front.m_now_line].who_win;
        if(front == m_result){
            // 连赢没断，
            // 如果已经是成龙了
            if(way_big->dragon.m_now_row != -1){
                // 移动到下一列同行，如果已经是最后一列了怎么办？
                if(way_big->now.m_now_row == 44){
                    for(int row = 0;row < 43;row++){
                        for(int line = 0;line < 6;line++){
                            way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                        }
                    }
                    for(int i = 0;i < 6;i++){
                        way_big->labels[44][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                    }
                }
                way_big->now.m_now_row++;
            }
            // 还没成龙
            else{
                // 如果下一个有值，则成龙,移动到下列同行
                if(way_big->now.m_now_line == 5 || way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line + 1].who_win != 0){
                    // 移动到下一列同行，如果已经是最后一列了怎么办？
                    if(way_big->now.m_now_row == 44){
                        for(int row = 0;row < 43;row++){
                            for(int line = 0;line < 6;line++){
                                way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                            }
                        }
                        for(int i = 0;i < 6;i++){
                            way_big->labels[44][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                        }
                    }
                    else{
                        way_big->now.m_now_row++;
                    }
                    way_big->dragon = way_big->now;
                }
                else if(!way_big->first){
                    way_big->now = way_big->now.down();
                }
            }
        }
        else{
            // 连赢断了， 如果已经成龙，并且不是第一行，xxx，并回到第一行，如果是第一行，向右移动一位
            if(way_big->dragon.m_now_row != -1){
                if(way_big->dragon.m_now_line == 0){
                    way_big->now.m_now_row++;
                }
                else{
                    way_big->now.m_now_row = way_big->dragon.m_now_row;
                    way_big->now.m_now_line = 0;
                }
            }
            else if(!way_big->first){
                way_big->now.m_now_row++;
                way_big->now.m_now_line = 0;
            }
            // 没有成龙
            way_big->dragon.m_now_row = -1;
        }
        way_big->equa = way_big->now;
        way_big->front = way_big->now;
        way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line].label->setStyleSheet(way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line].label->styleSheet().append(path_gl));
        way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line].who_win = m_result;
        way_big->first = false;
        // 更新问路样式表
        update_ask_way();
        NUMBER zhuang_next = next_zhuang(7);
        update_ask(zhuang_next,true);
        NUMBER xian_next = next_zhuang(4);
        update_ask(xian_next,false);
    }
}
