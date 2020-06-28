#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QKeyEvent>

//QString URL = "192.168.0.104:8210";
QString URL = "129.211.114.135:8210";

enum {START,CHANGEBOOT,ROOMINFO,RECORD,ROOMCARD,LOCATE,FAPAI,SUMMIT,USELESS,INIT};

MainWindow::MainWindow(int id, QString token, unsigned int maxLimit, unsigned int minLimit, unsigned int maxPair, unsigned int minPair, unsigned int maxTie, unsigned int minTie, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 结果值初始化
    m_playerPair = 0;
    m_bankerPair = 0;
    // 倒计时初始化
    times = 30;

    // 网络初始化
    manager = new MNetManager;
    manager->setIp("129.211.114.135:8210");
    manager->InitRequest("application/x-www-form-urlencoded",QString::number(id),token);
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));

    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(ROOMCARD,&MainWindow::responsed_roomcard);
    _map.insert(LOCATE,&MainWindow::responsed_locate);
    _map.insert(FAPAI,&MainWindow::responsed_fapai);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);

    ui->label_maxLimit->setText(QString::number(maxLimit));
    ui->label_minLimit->setText(QString::number(minLimit));
    ui->label_tieMaxLimit->setText(QString::number(maxTie));
    ui->label_tieMinLimit->setText(QString::number(minTie));
    ui->label_pairMaxLimit->setText(QString::number(maxPair));
    ui->label_pairMinLimit->setText(QString::number(minPair));

    // 开始请求房间信息
    request_room_info();


    // 倒计时初始化
    this->m_timer_count_down = new QTimer(this);
    connect(m_timer_count_down,SIGNAL(timeout()),this,SLOT(count_down()));

    // 生成恶心人的体力活链表
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

    // 先动态生成大路
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


    // 链接槽函数
    connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
    connect(ui->pu_start,SIGNAL(clicked()),this,SLOT(pu_start()));
    connect(ui->pu_changeXue,SIGNAL(clicked()),this,SLOT(pu_changeXue()));
    connect(ui->pu_stop,SIGNAL(clicked()),this,SLOT(pu_stop()));
    connect(ui->pu_leave,SIGNAL(clicked()),this,SLOT(pu_leave()));
    connect(ui->pu_useless,SIGNAL(clicked()),this,SLOT(pu_useless()));
    connect(ui->pu_zhuang,SIGNAL(clicked()),this,SLOT(pu_zhuang()));
    connect(ui->pu_xian,SIGNAL(clicked()),this,SLOT(pu_xian()));
    connect(ui->pu_zhuangdui,SIGNAL(clicked()),this,SLOT(pu_zhuangdui()));
    connect(ui->pu_xiandui,SIGNAL(clicked()),this,SLOT(pu_xiandui()));
    connect(ui->pu_same,SIGNAL(clicked()),this,SLOT(pu_same()));
    connect(ui->pu_enter,SIGNAL(clicked()),this,SLOT(on_enter()));
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
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
    ASKWAY askway;
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
        askway = next_ask_way(way_big_eye,game,style,true);
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].who_win = askway.game;
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->setStyleSheet(askway.style);


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
            askway = next_ask_way(way_little,game,style,true);
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].who_win = askway.game;
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->setStyleSheet(askway.style);

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
                askway = next_ask_way(way_aotu,game,style,true);
                way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].who_win = askway.game;
                way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->setStyleSheet(askway.style);
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
        askway = next_ask_way(way_big_eye,game,style,true);
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].who_win = askway.game;
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->setStyleSheet(askway.style);

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
            askway = next_ask_way(way_little,game,style,true);
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].who_win = askway.game;
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->setStyleSheet(askway.style);

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
                askway = next_ask_way(way_aotu,game,style,true);
                way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].who_win = askway.game;
                way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->setStyleSheet(askway.style);
            }
        }
    }
}

ASKWAY MainWindow::next_ask_way(WAY* way,int game,QString style,bool T)
{
    // 获取上一个问路 label 的颜色
    WAY front_way = *way;
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
    ASKWAY askway;
    askway.game = game;
    askway.style = style;
    if(!T){
        *way = front_way;
    }
    return askway;

//    way->labels[way->now.m_now_row][way->now.m_now_line].who_win = game;
//    way->labels[way->now.m_now_row][way->now.m_now_line].label->setStyleSheet(style);
}

void MainWindow::pu_init()
{
    // 禁用初始化按钮
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        ui->pu_init->setEnabled(false);

        // 发送初始化请求
        m_post_type = "init";
        m_request->setUrl(QUrl("http://" + URL + "/bjl_desk_ini"));
        QByteArray postData;
        postData.append(QString(""));
        m_accessManager->post(*m_request, postData);


    }
}

//void MainWindow::on_login()
//{
//    // 启用该启用的按钮
//    ui->pu_start->setEnabled(true);
//    ui->pu_changeXue->setEnabled(true);
//    ui->pu_leave->setEnabled(true);
//    ui->pu_init->setEnabled(true);
//}

void MainWindow::on_start(){
    m_timer_count_down->start(1000);
}

void MainWindow::pu_start()
{
    // 禁用按钮
    ui->pu_start->setEnabled(false);
    // 请求倒计时接口
    m_post_type = "start";
    m_request->setUrl(QUrl("http://" + URL + "/bjl_count_down"));
    QByteArray postData;
    m_accessManager->post(*m_request, postData);
}

void MainWindow::pu_changeXue()
{
    int choose = QMessageBox::question(this,QString("换靴"),QString("确认换靴？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        m_post_type = "change_boot";
        m_request->setUrl(QUrl("http://" + URL + "/bjl_change_boot"));
        QByteArray postData;
        m_accessManager->post(*m_request,postData);
    }
}

void MainWindow::pu_stop(){

}

void MainWindow::pu_leave(){

}

void MainWindow::pu_useless(){
    int choose = QMessageBox::question(this,QString("初始化"),QString("确认初始化？"),QMessageBox::Yes | QMessageBox::No);
    if(choose == QMessageBox::Yes){
        m_post_type = "game_burn";
        m_request->setUrl(QUrl("http://" + URL + "/bjl_game_burn"));
        QByteArray postData;
        postData.append(QString("boot_num="));postData.append(ui->label_times_xue->text());
        postData.append(QString("&pave_num="));postData.append(ui->label_times_pu->text());
        m_accessManager->post(*m_request,postData);

        // 禁用作废按钮
        ui->pu_useless->setEnabled(false);
    }
}

void MainWindow::pu_zhuang()
{
    on_zhuang();
}

void MainWindow::pu_zhuangdui()
{
    on_zhuangdui();
}

void MainWindow::pu_xian()
{
    on_xian();
}

void MainWindow::pu_xiandui()
{
    on_xiandui();
}

void MainWindow::pu_same()
{
    on_same();
}

void MainWindow::finishedSlot(QNetworkReply* _reply)
{
    if (_reply->error() == QNetworkReply::NoError){
        QByteArray bytes = _reply->readAll();
        if(m_post_type == "login"){
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            qDebug() << "login : " << info << "-" << status;
            if(status == 1){
                // 登录成功
                QJsonObject json_object2 = json_object.value("data").toObject();
                qDebug() << QString(QJsonDocument(json_object2).toJson());
                unsigned int desk_id = json_object2.value("desk_id").toInt();
                QString desk_token = json_object2.value("desk_token").toString();
                //on_login();
                m_request->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
                m_request->setRawHeader("desk_token",desk_token.toUtf8());
                qDebug() << "desk_id : " << QString::number(desk_id).toUtf8() << "--" << "desk_token" << desk_token;
                // 刷新限红
                unsigned int maxLimit = json_object2.value("maxLimit").toInt();
                unsigned int minLimit = json_object2.value("minLimit").toInt();
                unsigned int tieMaxLimit = json_object2.value("tieMaxLimit").toInt();
                unsigned int tieMinLimit = json_object2.value("tieMinLimit").toInt();
                unsigned int pairMaxLimit = json_object2.value("pairMaxLimit").toInt();
                unsigned int pairMinLimit = json_object2.value("pairMinLimit").toInt();
                ui->label_maxLimit->setText(QString::number(maxLimit));
                ui->label_minLimit->setText(QString::number(minLimit));
                ui->label_tieMaxLimit->setText(QString::number(tieMaxLimit));
                ui->label_tieMinLimit->setText(QString::number(tieMinLimit));
                ui->label_pairMaxLimit->setText(QString::number(pairMaxLimit));
                ui->label_pairMinLimit->setText(QString::number(pairMinLimit));

                // 开始请求房间信息
                request_room_info();
            }
            else{
                QMessageBox box;
                box.setText("登录失败");
                box.exec();
            }
        }
        else if(m_post_type == "init"){
            // 响应初始化
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();          
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            qDebug() << "init status: " << status;
            qDebug() << "init info : " << info.toLocal8Bit();
            if(status == 1){
                QJsonObject json_object2 = json_object.value("data").toObject();
                unsigned int boot_num = json_object2.value("boot_num").toInt();
                unsigned int pave_num = json_object2.value("pave_num").toInt();
                ui->label_times_xue->setText(QString::number(boot_num));
                ui->label_times_pu->setText(QString::number(pave_num));
                // 清空规律面板
                way_big->init();

                // 清空问路
                way_big_eye->init();
                way_little->init();
                way_aotu->init();
            }
            else{
                QMessageBox box;
                box.setText("初始化失败");
                box.exec();

                ui->pu_init->setEnabled(true);
            }
        }
        else if(m_post_type == "roominfo"){
            // 响应房间信息
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            if(status == 1){
                QJsonArray json_array = json_object.value("data").toArray();
                // 刷新靴次
                unsigned int boot_num = json_array.at(0)["BootNum"].toInt(); //json_object2.value("BootNum").toInt();
                qDebug() << "boot_room : " << boot_num;
                ui->label_times_xue->setText(QString::number(boot_num));
                // 刷新铺次
                unsigned int PaveNum = json_array.at(0)["PaveNum"].toInt(); //json_object2.value("PaveNum").toInt();
                ui->label_times_pu->setText(QString::number(PaveNum));
                qDebug() << "PaveNum : " << PaveNum;
                // 刷新台桌
                QString DeskName = json_array.at(0)["DeskName"].toString(); //json_object2.value("DeskName").toString();
                ui->label_desk_id->setText(DeskName);
                qDebug() << "desk id : " << DeskName;
                // 获取时间戳
                unsigned int GameStarTime = json_array.at(0)["GameStarTime"].toInt(); //json_object2.value("GameStarTime").toInt();
                unsigned int Systime = json_array.at(0)["Systime"].toInt(); //json_object2.value("Systime").toInt();
                // 获取房间状态
                unsigned int phase = json_array.at(0)["Phase"].toInt(); //json_object2.value("Phase").toInt();
                switch (phase) {
                case 0:
                    // 洗牌中
                    phase_zero();
                    break;
                case 1:
                    // 倒计时
                    phase_countDown(GameStarTime,Systime);
                    break;
                case 2:
                    // 开牌中
                    phase_kaiPai();
                    break;
                case 3:
                    // 结算完成
                    phase_finish();
                    break;
                }
                request_result_list();
            }
            else{
                QMessageBox box;
                box.setText("获取房间信息失败");
                box.exec();
            }
        }
        else if(m_post_type == "result_list"){
            // 响应结果信息
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            if(status == 1){
                // 成功获取信息
                // 应用结果到每个label上
                QJsonArray json_array = json_object.value("data").toArray();
                // 先应用赢得次数
                // 和
                unsigned int sumTie = json_array.at(0)["sumTie"].toInt(); //json_object.value("sumTie").toInt();
                ui->label_result_same->setText(QString::number(sumTie));
                // 庄
                unsigned int sumBanker = json_array.at(0)["sumBanker"].toInt(); //json_object.value("sumBanker").toInt();
                ui->label_result_zhuang->setText(QString::number(sumBanker));
                // 闲
                unsigned int sumPlayer = json_array.at(0)["sumPlayer"].toInt(); //json_object.value("sumPlayer").toInt();
                ui->label_result_xian->setText(QString::number(sumPlayer));
                // 庄对
                unsigned int sumBankerPair = json_array.at(0)["sumBankerPair"].toInt(); //json_object.value("sumBankerPair").toInt();
                ui->label_result_zhuangDui->setText(QString::number(sumBankerPair));
                // 闲对
                unsigned int PlayerPair = json_array.at(0)["PlayerPair"].toInt(); //json_object.value("PlayerPair").toInt();
                ui->label_result_xianDui->setText(QString::number(PlayerPair));

                // 应用结果表
                QJsonArray array = json_array.at(0)["list"].toArray(); //json_object2.value("list").toArray();
                result_list(array);
            }
            else{
                QMessageBox box;
                box.setText("获取历史记录失败");
                box.exec();
            }
        }
        else if(m_post_type == "start"){
            // 获取倒计时响应
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            qDebug() << "start : " << info << "-" << status;

            if(status == 1){
                // 开始倒计时成功
                QJsonObject json_object2 = json_object.value("data").toObject();
                unsigned int boot_num = json_object2.value("boot_num").toInt();
                unsigned int pave_num = json_object2.value("pave_num").toInt();
                // 刷新靴次和铺次
                ui->label_times_xue->setText(QString::number(boot_num));
                ui->label_times_pu->setText(QString::number(pave_num));
                // 禁用换靴
                ui->pu_changeXue->setEnabled(false);

                on_start();
            }
            else{
                // 请求倒计时失败
                QMessageBox box;
                box.setText("开局失败");
                box.exec();
                // 启用开始按钮
                ui->pu_start->setEnabled(true);
            }
        }
        else if(m_post_type == "change_boot"){
            // 获取响应
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            qDebug() << "start : " << info << "-" << status;

            if(status == 1){
                // 换靴成功
                QJsonObject json_object2 = json_object.value("data").toObject();
                unsigned int boot_num = json_object2.value("boot_num").toInt();
                unsigned int pave_num = json_object2.value("pave_num").toInt();
                // 刷新靴次和铺次
                ui->label_times_xue->setText(QString::number(boot_num));
                ui->label_times_pu->setText(QString::number(pave_num));
                // 置零结果次数
                ui->label_result_same->setText("0");
                ui->label_result_xian->setText("0");
                ui->label_result_zhuang->setText("0");
                ui->label_result_xianDui->setText("0");
                ui->label_result_zhuangDui->setText("0");
                // 清空结果面板
                Link* node = m_link_reslut_head;
                while(node->next != nullptr){
                    node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
                    node->data->setText("");
                    node = node->next;
                }
                m_link_reslut = m_link_reslut_head;

                // 清空规律面板
                way_big->init();

                // 清空问路
                way_big_eye->init();
                way_little->init();
                way_aotu->init();
            }
            else{
                // 换靴失败
                QMessageBox box;
                box.setText("换靴失败");
                box.exec();

                qDebug() << "change_boot_faild";
            }
        }
        else if(m_post_type == "game_burn"){
            // 获取响应
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            QString info = json_object.value("info").toString();
            unsigned int status = json_object.value("status").toInt();
            qDebug() << "game_burn : " << info << "-" << status;

            if(status == 1){
                // 作废成功
                QString path = QString("border-image: url(:/result/useless.png);");
                m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(path));

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

                // 清空结果
                ui->label_result->setText("");
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
                // 上铺结果
                ui->label_up_pave->setText("上铺：作废");
            }
            else{
                // 作废失败
                QMessageBox box;
                box.setText("作废失败");
                box.exec();
                // 启用作废按钮
                ui->pu_useless->setEnabled(true);

                qDebug() << "game_burn_faild";
            }
        }
        else if(m_post_type == "gameover"){
            QJsonObject json_object = QJsonDocument::fromJson(bytes).object();
            unsigned int status = json_object.value("status").toInt();
            QString info = json_object.value("info").toString();
            qDebug() << info;
            if(status == 1){
                ui->label_result->setText(QString(""));
                QString path = QString(":/result/");
                QString path_gl = QString(":/guilv/gl_");
                QString up = "上铺：";
                switch (m_game) {
                case 7:{
                    up.append("庄赢");
                    path.append("zhuang");
                    path_gl.append("zhuang");
                    // 庄赢的次数加一
                    int n_zhuang = ui->label_result_zhuang->text().toInt();
                    ui->label_result_zhuang->setText(QString::number(n_zhuang + 1));
                    break;
                }
                case 4:{
                    up.append("闲赢");
                    path.append("xian");
                    path_gl.append("xian");
                    // 闲赢的次数加一
                    int n_xian = ui->label_result_xian->text().toInt();
                    ui->label_result_xian->setText(QString::number(n_xian + 1));
                    break;
                }
                case 1:{
                    up.append("和");
                    path.append("same");
                    path_gl.append("same");
                    // 和赢的次数加一
                    int n_same = ui->label_result_same->text().toInt();
                    ui->label_result_same->setText(QString::number(n_same + 1));
                    break;
                }
                }
                if(m_bankerPair == 2){
                    up.append("庄对");
                    path.append("zhuangdui");
                    path_gl.append("zhuangdui");
                    // 庄对的次数加一
                    int n_banker = ui->label_result_zhuangDui->text().toInt();
                    ui->label_result_zhuangDui->setText(QString::number(n_banker + 1));
                }
                if(m_playerPair == 5){
                    up.append("闲对");
                    path.append("xiandui");
                    path_gl.append("xiandui");
                    // 闲对的次数加一
                    int n_player = ui->label_result_xianDui->text().toInt();
                    ui->label_result_xianDui->setText(QString::number(n_player + 1));
                }
                path.append(".png");
                path_gl.append(".png");

                ui->label_up_pave->setText(up);
                // 更新结果样式表
                QString style = "border-image: url(" + path + ");";
                m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));

                // 更新规律表
                ongl_enter(path_gl);


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




                // 启用该启用的按钮
                ui->pu_start->setEnabled(true);
                // 禁用结果按钮
                ui->pu_zhuang->setEnabled(false);
                ui->pu_zhuangdui->setEnabled(false);
                ui->pu_xian->setEnabled(false);
                ui->pu_xiandui->setEnabled(false);
                ui->pu_same->setEnabled(false);
                // 倒计时恢复为30
                times = 30;
                // 初始化结果值
                m_game = -1;
                m_playerPair = 0;
                m_bankerPair = 0;
                ui->label_result->setText("");

                // 禁用结算按钮
                ui->pu_enter->setEnabled(false);
                ui->pu_cancel->setEnabled(false);
                // 关闭弹窗
                form->hide();
                // 禁用作废
                ui->pu_useless->setEnabled(false);
                // 启用换靴
                ui->pu_changeXue->setEnabled(true);
            }else{
                QMessageBox box;
                box.setText("结算失败");
                box.exec();

                // 启用结算和取消按钮
                ui->pu_enter->setEnabled(true);
                ui->pu_cancel->setEnabled(true);

                qDebug() << "faild";
            }
        }
    }else{
        qDebug() << "finishedSlot errors here";
        qDebug( "found error .... code: %d\n", (int)_reply->error());
        qDebug() << _reply->errorString();
        // 提示网络连接失败
        QMessageBox box;
        box.setText("网络连接失败");
        box.exec();
    }
}

void MainWindow::count_down()
{
    ui->label_count_down->setText(QString::number(times));
    if(--times < 0){
        //倒计时完成
        m_timer_count_down->stop();
        ui->label_count_down->setText(QString(""));
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
}

void MainWindow::tc_cancel()
{
    form->hide();
    // 启用结算和取消按钮
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::on_init()
{
    // 初始化所有路
    way_big->init();
    way_aotu->init();
    way_little->init();
    way_big_eye->init();
    // 结果链表
    m_link_reslut = m_link_reslut_head;
    // 结果
    m_game = 0;
    m_playerPair = 0;
    m_bankerPair = 0;
    // 倒计时
    times = 30;
}

void MainWindow::on_zhuang()
{
    m_game = 7;
    QString str = ui->label_result->text();
    str.append("庄赢");
    ui->label_result->setText(str);

    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);
}

void MainWindow::on_xian()
{
    m_game = 4;
    QString str = ui->label_result->text();
    str.append("闲赢");
    ui->label_result->setText(str);

    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);

    // 启用结算和取消按钮
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::on_same()
{
    m_game = 1;
    QString str = ui->label_result->text();
    str.append("和");
    ui->label_result->setText(str);

    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);

    // 启用结算和取消按钮
    ui->pu_enter->setEnabled(true);
    ui->pu_cancel->setEnabled(true);
}

void MainWindow::on_zhuangdui()
{
    m_bankerPair = 2;
    QString str = ui->label_result->text();
    str.append("庄对");
    ui->label_result->setText(str);

    // 禁用庄对按钮
    ui->pu_zhuangdui->setEnabled(false);
}

void MainWindow::on_xiandui()
{
    m_playerPair = 5;
    QString str = ui->label_result->text();
    str.append("闲对");
    ui->label_result->setText(str);

    // 禁用闲对按钮
    ui->pu_xiandui->setEnabled(false);
}

void MainWindow::request_room_info()
{
    m_post_type = "roominfo";
    QString url = "http://" + URL + "/HeGuanRoominfo";
    m_request->setUrl(QUrl(url));
    QByteArray postData;
    m_accessManager->post(*m_request,postData);
}

void MainWindow::request_result_list()
{
    m_post_type = "result_list";
    QString url = "http://" + URL + "/bjl_dutch_game_list";
    m_request->setUrl(QUrl(url));
    QByteArray postData;
    postData.append("boot_num=" + ui->label_times_xue->text());
    m_accessManager->post(*m_request,postData);
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
    // 结算完成
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
    ui->pu_init->setEnabled(true);
}

void MainWindow::result_list(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    // 获取结果和规律的图片
    for(int i = 0;i < array.count();i++){
        QString path = QString(":/result/");
        QString path_gl = QString(":/guilv/gl_");
        QString up = "上铺：";
        m_game_str = array.at(i)["game"].toString();
        if(m_game_str == "庄"){
            m_game = 7;
            path.append("zhuang");
            path_gl.append("zhuang");
            up.append("庄赢");
        }
        else if(m_game_str == "闲"){
            m_game = 4;
            path.append("xian");
            path_gl.append("xian");
            up.append("闲赢");
        }
        else if(m_game_str == "和"){
            m_game = 1;
            path.append("same");
            path_gl.append("same");
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
            path_gl.append("zhuangdui");
            up.append("庄对");
        }
        m_playerPair_str = array.at(i)["playerPair"].toString();
        if(m_playerPair_str == "闲对"){
            m_playerPair = 5;
            path.append("xiandui");
            path_gl.append("xiandui");
            up.append("闲对");
        }
        path.append(".png");
        path_gl.append(".png");

        ui->label_up_pave->setText(up);
        // 更新结果样式表
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
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
            node->data->setStyleSheet("");
            node->data->setText("background-color: rgb(255, 255, 255);");
            qDebug() << "m_link_reslut->next : nullptr";
        }
        else{
            m_link_reslut = m_link_reslut->next;
            qDebug() << "m_link_reslut->next : not null";
        }

        // 更新规律样式表
        if(m_game_str != ""){
            ongl_enter(path_gl);
        }

        // 恢复默认结果
        m_game = -1;
        m_playerPair = 0;
        m_bankerPair = 0;
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

void MainWindow::tc_enter()
{
    // 发送结果
    if(m_game == -1){
        QMessageBox box;
        box.setText("结果无效");
        box.exec();
    }
    else{
        // 发送请求
        m_post_type = "gameover";
        QString url = "http://" + URL + "/bjl_game_over";
        m_request->setUrl(QUrl(url));
        QByteArray postData;
        postData.append(QString("boot_num="));postData.append(ui->label_times_xue->text());
        postData.append(QString("&pave_num="));postData.append(ui->label_times_pu->text());
        qDebug() << "postData gameover: " << postData.data();
        QJsonObject json;
        json.insert("game",m_game);
        json.insert("playerPair",m_playerPair);
        json.insert("bankerPair",m_bankerPair);
        qDebug() << QString(QJsonDocument(json).toJson());
        postData.append(QString("&game_num="));postData.append(QString(QJsonDocument(json).toJson()));
        qDebug() << "Json : " << postData.data();
        m_accessManager->post(*m_request,postData);
    }
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

void MainWindow::ongl_enter(QString path_gl){
    //
    path_gl = "border-image: url(" + path_gl + ");";
    // 更新规律表
    if(m_game == 1){
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
        if(front == m_game){
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
        way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line].who_win = m_game;
        way_big->first = false;
        // 更新问路样式表
        update_ask_way();
        NUMBER zhuang_next = next_zhuang(7);
        update_ask(zhuang_next,true);
        NUMBER xian_next = next_zhuang(4);
        update_ask(xian_next,false);
    }
}

NUMBER MainWindow::next_zhuang(int offset)
{
    // 下一把是庄赢
    WAY big_way = *way_big;
    if(m_game == offset){
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

void MainWindow::update_ask(NUMBER big_way,bool zhuang){
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
            ui->label_zwl_one->setStyleSheet(style);
        }
        else{
            ui->label_xwl_one->setStyleSheet(style);
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
                ui->label_zwl_two->setStyleSheet(style);
            }
            else{
                ui->label_xwl_two->setStyleSheet(style);
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
                    ui->label_zwl_three->setStyleSheet(style);
                }
                else{
                    ui->label_xwl_three->setStyleSheet(style);
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
            ui->label_zwl_one->setStyleSheet(style);
        }
        else{
            ui->label_xwl_one->setStyleSheet(style);
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
                ui->label_zwl_two->setStyleSheet(style);
            }
            else{
                ui->label_xwl_two->setStyleSheet(style);
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
                    ui->label_zwl_three->setStyleSheet(style);
                }
                else{
                    ui->label_xwl_three->setStyleSheet(style);
                }
            }
        }
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

        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
    }
    else{
        QMessageBox box;
        box.setText("百家乐初始化失败");
        box.exec();

        ui->pu_init->setEnabled(true);
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
        switch (phase) {
        case 0:{
            phase_zero();
            break;
        }
        case 1:{
            unsigned int starTime = data.at(0)["GameStarTime"].toInt();
            unsigned int sysTime = data.at(0)["Systime"].toInt();
            phase_countDown(starTime,sysTime);
            break;
        }
        case 2:{
            phase_kaiPai();
            break;
        }
        }
        request_result_list();
    }
    else{
        QMessageBox box;
        box.setText("百家乐获取房间信息失败");
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
        unsigned int sumBanker = data.at(0)["sumBanker"].toInt();
        unsigned int sumPlayer = data.at(0)["sumPlayer"].toInt();
        unsigned int sumBankerPair = data.at(0)["sumBankerPair"].toInt();
        unsigned int PlayerPair = data.at(0)["PlayerPair"].toInt();

        ui->label_result_same->setText(QString::number(sumTie));
        ui->label_result_zhuang->setText(QString::number(sumBanker));
        ui->label_result_xian->setText(QString::number(sumPlayer));
        ui->label_result_zhuangDui->setText(QString::number(sumBankerPair));
        ui->label_result_xianDui->setText(QString::number(PlayerPair));

        QJsonArray array = data.at(0)["list"].toArray();
        result_list(array);
    }
    else{
        QMessageBox box;
        box.setText("百家乐获取历史记录失败");
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

        ui->label_times_xue->setText(QString::number(boot_num));
        ui->label_times_pu->setText(QString::number(pave_num));

        ui->pu_changeXue->setEnabled(false);
        on_start();
    }
    else{
        ui->pu_start->setEnabled(true);

        QMessageBox box;
        box.setText("百家乐请求开局失败");
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

        ui->label_result_same->setText("0");
        ui->label_result_xian->setText("0");
        ui->label_result_zhuang->setText("0");
        ui->label_result_xianDui->setText("0");
        ui->label_result_zhuangDui->setText("0");

        Link* node = m_link_reslut_head;
        while(node->next != nullptr){
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node->data->setText("");
            node = node->next;
        }
        m_link_reslut = m_link_reslut_head;

        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
    }
}

