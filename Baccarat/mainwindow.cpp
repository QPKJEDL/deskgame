#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QKeyEvent>
#include "mod/mod_dialog/MDialog.h"

//QString URL = "101.32.22.231:8210";192.168.0.102:8210
//QString URL = "129.211.114.135:8210";

enum {LOGIN,START,CHANGEBOOT,ROOMINFO,RECORD,SUMMIT,USELESS,INIT,STOP};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login_window = new Login();

    // 结果值初始化
    m_playerPair = 0;
    m_bankerPair = 0;
    // 倒计时初始化
    times = 30;
    label_count_down = new QLabel(this);
    label_count_down->setMinimumSize(QSize(300,300));
    label_count_down->move(550,400);
    label_count_down->setStyleSheet("background-color: transparent;font: 200pt \"方正粗黑宋简体\";");

    // 网络初始化
    manager = new MNetManager;
    manager->setIp("101.32.22.231:8210");
    manager->setHeader("application/x-www-form-urlencoded");
    connect(manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));


    _map.insert(LOGIN,&MainWindow::responsed_login);
    _map.insert(START,&MainWindow::responsed_start);
    _map.insert(ROOMINFO,&MainWindow::responsed_roominfo);
    _map.insert(RECORD,&MainWindow::responsed_record);
    _map.insert(SUMMIT,&MainWindow::responsed_summit);
    _map.insert(USELESS,&MainWindow::responsed_useless);
    _map.insert(INIT,&MainWindow::responsed_init);
    _map.insert(CHANGEBOOT,&MainWindow::responsed_change_boot);
    _map.insert(STOP,&MainWindow::responsed_stop);

    login_window->showFullScreen();

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
    for (int i = 0;i < 46;i++) {
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
    for(int row = 0;row < 23;row++){
        for(int line = 0;line < 3;line++){
            QLabel* label_one = new QLabel();
            label_one->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_one->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_one->setAlignment(Qt::AlignHCenter);

            QLabel* label_two = new QLabel();
            label_two->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_two->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_two->setAlignment(Qt::AlignHCenter);

            QLabel* label_three = new QLabel();
            label_three->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_three->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_three->setAlignment(Qt::AlignHCenter);

            QLabel* label_four = new QLabel();
            label_four->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_four->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_four->setAlignment(Qt::AlignHCenter);

            QGridLayout *grid = new QGridLayout();
            grid->setSpacing(0);
            grid->addWidget(label_one,0,0);
            grid->addWidget(label_two,0,1);
            grid->addWidget(label_three,1,0);
            grid->addWidget(label_four,1,1);



            ui->gridLayout_5->addLayout(grid,line,row);

            way_big_eye->labels[row * 2][line * 2].label = label_one;
            way_big_eye->labels[row * 2 + 1][line * 2].label = label_two;
            way_big_eye->labels[row * 2][line * 2 + 1].label = label_three;
            way_big_eye->labels[row * 2 + 1][line * 2 + 1].label = label_four;
        }
    }

    // 小路扑通扑通的跳
    way_little = new WAY;
    way_little->dragon.m_now_row = -1;
    for(int row = 0;row < 23;row++){
        for(int line = 0;line < 3;line++){
            QLabel* label_one = new QLabel();
            label_one->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_one->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_one->setAlignment(Qt::AlignHCenter);

            QLabel* label_two = new QLabel();
            label_two->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_two->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_two->setAlignment(Qt::AlignHCenter);

            QLabel* label_three = new QLabel();
            label_three->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_three->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_three->setAlignment(Qt::AlignHCenter);

            QLabel* label_four = new QLabel();
            label_four->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_four->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_four->setAlignment(Qt::AlignHCenter);

            QGridLayout *grid = new QGridLayout();
            grid->setSpacing(0);
            grid->addWidget(label_one,0,0);
            grid->addWidget(label_two,0,1);
            grid->addWidget(label_three,1,0);
            grid->addWidget(label_four,1,1);

            ui->gridLayout_8->addLayout(grid,line,row);

            // 270小路回家
            way_little->labels[row * 2][line * 2].label = label_one;
            way_little->labels[row * 2 + 1][line * 2].label = label_two;
            way_little->labels[row * 2][line * 2 + 1].label = label_three;
            way_little->labels[row * 2 + 1][line * 2 + 1].label = label_four;
        }
    }

    // 凹凸路有多凹凸呢？
    way_aotu = new WAY;
    way_aotu->dragon.m_now_row = -1;
    for(int row = 0;row < 23;row++){
        for(int line = 0;line < 3;line++){
            QLabel* label_one = new QLabel();
            label_one->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_one->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_one->setAlignment(Qt::AlignHCenter);

            QLabel* label_two = new QLabel();
            label_two->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_two->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_two->setAlignment(Qt::AlignHCenter);

            QLabel* label_three = new QLabel();
            label_three->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_three->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_three->setAlignment(Qt::AlignHCenter);

            QLabel* label_four = new QLabel();
            label_four->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_four->setFont(QFont(QString("方正粗黑宋简体"),25));
            label_four->setAlignment(Qt::AlignHCenter);

            QGridLayout *grid = new QGridLayout();
            grid->setSpacing(0);
            grid->addWidget(label_one,0,0);
            grid->addWidget(label_two,0,1);
            grid->addWidget(label_three,1,0);
            grid->addWidget(label_four,1,1);

            ui->gridLayout_7->addLayout(grid,line,row);

            // 270 凹凸
            way_aotu->labels[row * 2][line * 2].label = label_one;
            way_aotu->labels[row * 2 + 1][line * 2].label = label_two;
            way_aotu->labels[row * 2][line * 2 + 1].label = label_three;
            way_aotu->labels[row * 2 + 1][line * 2 + 1].label = label_four;
        }
    }

    for(int row = 0;row < 23;row++){
        for(int line = 0;line < 3;line++){
            QList<QLabel*> list;
            QLabel* label_one = new QLabel();
            label_one->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_one->setFont(QFont(QString("方正粗黑宋简体"),13));
            label_one->setAlignment(Qt::AlignHCenter);
            list.append(label_one);

            QLabel* label_two = new QLabel();
            label_two->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_two->setFont(QFont(QString("方正粗黑宋简体"),13));
            label_two->setAlignment(Qt::AlignHCenter);
            list.append(label_two);

            QLabel* label_three = new QLabel();
            label_three->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_three->setFont(QFont(QString("方正粗黑宋简体"),13));
            label_three->setAlignment(Qt::AlignHCenter);
            list.append(label_three);

            QLabel* label_four = new QLabel();
            label_four->setStyleSheet("background-color: rgb(255, 255, 255);");
            label_four->setFont(QFont(QString("方正粗黑宋简体"),13));
            label_four->setAlignment(Qt::AlignHCenter);
            list.append(label_four);

            QGridLayout *grid = new QGridLayout();
            grid->setSpacing(0);
            grid->addWidget(label_one,0,0);
            grid->addWidget(label_two,1,0);
            grid->addWidget(label_three,0,1);
            grid->addWidget(label_four,1,1);

            ui->gridLayout_9->addLayout(grid,line,row);

            little_little_way.append(list);
        }
    }


    // 链接槽函数
    //connect(ui->pu_init,SIGNAL(clicked()),this,SLOT(pu_init()));
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
    connect(login_window->get_login_Button(),SIGNAL(clicked()),this,SLOT(pu_login()));
    // 连接弹窗信号
    form = new Form();
    form->setWindowFlag(Qt::FramelessWindowHint);
    connect(form->button_enter(),SIGNAL(clicked()),this,SLOT(tc_enter()));
    connect(form->button_cancel(),SIGNAL(clicked()),this,SLOT(tc_cancel()));

    qDebug() << way_big_eye->now.m_now_row;
    qDebug() << "------------";
    qDebug() << way_big_eye->now.m_now_line;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::little_little_append(int m_game)
{
    if(m_game == 1){
        if(index_x == -1 && index_y == -1){
            return;
        }
        little_little_way.at(index_x).at(index_y)->setText(QString::number(++tie_num));
    }
    else{
        tie_num = 0;
        // 移动到下一个小小路
        if(index_x == -1 && index_y == -1){
            index_x = 0;
            index_y = 0;
        }
        else if(index_y == 0){
            index_y = 1;
        }
        else if(index_y == 1){
            if((index_x + 1) % 3 == 0){
                index_x -= 2;
                index_y = 2;
            }
            else{
                index_x++;
                index_y = 0;
            }
        }
        else if(index_y == 2){
            index_y = 3;
        }
        else if(index_y == 3){
            if((index_x + 1) % 3 == 0){
                index_x++;
                index_y = 0;
            }
            else{
                index_x++;
                index_y = 2;
            }
        }
        // 更新问路
        if(m_game == 7){
            QLabel *label = little_little_way.at(index_x).at(index_y);
            label->setStyleSheet(label->styleSheet() + "border-image: url(:/ask_way/images/ask_way/red.png);");
        }
        else if(m_game == 4){
            QLabel *label = little_little_way.at(index_x).at(index_y);
            label->setStyleSheet(label->styleSheet() + "border-image: url(:/ask_way/images/ask_way/blue.png);");
        }
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
    ASKWAY askway;
    // 判断齐整
    if(way_big->now.m_now_line == 0 && way_big->now.m_now_row > 1){
        // 肯定需要判断 大眼仔路
        if(if_order(way_big->now,1,2)){
            // 齐整大眼仔路
            qDebug() << way_big_eye->now.m_now_row;
            qDebug() << way_big_eye->now.m_now_line;
            qDebug() << way_big_eye->labels[0][0].who_win;
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/redPoint.png") + QString(");");
            game = 7;
        }
        else{
            // 不齐整大眼仔路
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/bluePoint.png") + QString(");");
            game = 4;
        }
        // 移动到下一个大眼仔路
        qDebug() << "game : " << game;
        askway = next_ask_way(way_big_eye,game,style,true);
        if(way_big_eye->now.m_now_row == 46){
            qDebug() << 46;
        }
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].who_win = askway.game;
        way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->setStyleSheet(askway.style);


        if(way_big->now.m_now_row > 2){
            // 可以判断小路
            if(if_order(way_big->now,1,3)){
                // 齐整小路
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/red.png") + QString(");");
                game = 7;
            }
            else{
                // 不齐整大路
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/blue.png") + QString(");");
                game = 4;
            }
            // 移动到下一个小路路
            askway = next_ask_way(way_little,game,style,true);
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].who_win = askway.game;
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->setStyleSheet(askway.style);

            if(way_big->now.m_now_row > 3){
                // 可以判断凹凸路
                if(if_order(way_big->now,1,4)){
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/redLine.png") + QString(");");
                    game = 7;
                }
                else{
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/blueLine.png") + QString(");");
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
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/redPoint.png") + QString(");");
            game = 7;
        }
        else{
            // 无
            style = way_big_eye->labels[way_big_eye->now.m_now_row][way_big_eye->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/bluePoint.png") + QString(");");
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
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/red.png") + QString(");");
                game = 7;
            }
            else{
                // 无
                style = way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/blue.png") + QString(");");
                game = 4;
            }
            // 移动到下一个小路路
            askway = next_ask_way(way_little,game,style,true);
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].who_win = askway.game;
            way_little->labels[way_little->now.m_now_row][way_little->now.m_now_line].label->setStyleSheet(askway.style);

            if(way_big->now.m_now_row > 2){
                // 可以判断凹凸路
                if(if_YesOrNo(way_big->now,3)){
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/redLine.png") + QString(");");
                    game = 7;
                }
                else{
                    style = way_aotu->labels[way_aotu->now.m_now_row][way_aotu->now.m_now_line].label->styleSheet() + QString("border-image: url(") + QString(":/ask_way/images/ask_way/blueLine.png") + QString(");");
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
                if(way->now.m_now_row == 45){
                    for(int row = 0;row < 45;row++){
                        for(int line = 0;line < 6;line++){
                            way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());

                            way->labels[row][line].who_win = way->labels[row + 1][line].who_win;


                        }

                    }
                    for(int i = 0;i < 6;i++){
                        way->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");

                        way->labels[45][i].who_win = 0;
                    }
                    way->equa.m_now_row--;
                    way->front.m_now_row--;
                    way->dragon.m_now_row--;
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
            if(way->now.m_now_row == 45){
                for(int row = 0;row < 45;row++){
                    for(int line = 0;line < 6;line++){
                        way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());

                        way->labels[row][line].who_win = way->labels[row + 1][line].who_win;


                    }
                }
                for(int i = 0;i < 6;i++){
                    way->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");

                    way->labels[45][i].who_win = 0;
                }
                way->equa.m_now_row--;
                way->front.m_now_row--;
                way->dragon.m_now_row--;
            }
            else{
                way->now.m_now_row++;
            }
        }
    }
    // 连赢断了
    else{
        // 如果已经成龙，先找到成龙点
        if(way->dragon.m_now_row != -1){
            // 如果是第一行
            if(way->now.m_now_line == 0){
                if(way->now.m_now_row == 45){
                    for(int row = 0;row < 45;row++){
                        for(int line = 0;line < 6;line++){
                            way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());

                            way->labels[row][line].who_win = way->labels[row + 1][line].who_win;


                        }
                    }
                    for(int i = 0;i < 6;i++){
                        way->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");

                        way->labels[45][i].who_win = 0;
                    }
                    way->equa.m_now_row--;
                    way->front.m_now_row--;
                    way->dragon.m_now_row--;
                }
                else{
                    way->now.m_now_row++;
                }
            }
            else{
                way->now.m_now_row = way->dragon.m_now_row;
                way->now.m_now_line = 0;
            }
        }
        // 如果还没成龙，移动到右一列第一行
        else if(!way->first){
//            way->now.m_now_row++;
//            way->now.m_now_line = 0;
            // 如果已经是最后一列了
            if(way->now.m_now_row == 45){
                for(int row = 0;row < 45;row++){
                    for(int line = 0;line < 6;line++){
                        way->labels[row][line].label->setStyleSheet(way->labels[row + 1][line].label->styleSheet());

                        way->labels[row][line].who_win = way->labels[row + 1][line].who_win;


                    }
                }
                for(int i = 0;i < 6;i++){
                    way->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");

                    way->labels[45][i].who_win = 0;
                }
                way->now.m_now_line = 0;
                way->equa.m_now_row--;
                way->front.m_now_row--;
                way->dragon.m_now_row--;
            }
            else{
                way->now.m_now_row++;
                way->now.m_now_line = 0;
            }
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

void MainWindow::pu_login()
{
    request_login();
}

void MainWindow::pu_init()
{
    // 禁用初始化按钮
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否初始化?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_init();
    }
}

void MainWindow::on_start(){
    m_timer_count_down->start(1000);
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
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否换靴?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_change_boot();
    }
}

void MainWindow::pu_stop(){
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否停止?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        request_stop();
    }
}

void MainWindow::pu_leave(){
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("是否离开?");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        this->close();
    }
}

void MainWindow::pu_useless(){
    MDialog *dlg = new MDialog();
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->set_message("确认作废？");
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        // 禁用作废按钮
        ui->pu_useless->setEnabled(false);

        request_useless();
    }
}

void MainWindow::pu_zhuang()
{
    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);
    on_zhuang();
}

void MainWindow::pu_zhuangdui()
{
    // 禁用庄对按钮
    ui->pu_zhuangdui->setEnabled(false);
    on_zhuangdui();
}

void MainWindow::pu_xian()
{
    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);
    on_xian();
}

void MainWindow::pu_xiandui()
{

    // 禁用闲对按钮
    ui->pu_xiandui->setEnabled(false);
    on_xiandui();
}

void MainWindow::pu_same()
{
    // 禁用结果按钮
    ui->pu_zhuang->setEnabled(false);
    ui->pu_xian->setEnabled(false);
    ui->pu_same->setEnabled(false);
    on_same();
}

void MainWindow::count_down()
{
    label_count_down->setText(QString::number(times));
    if(--times < 0){
        if(first){
            first = false;
            times = wait_down;
            ui->pu_stop->setEnabled(false);
            return;
        }

        //倒计时完成
        m_timer_count_down->stop();
        label_count_down->setText(QString(""));
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
}

void MainWindow::on_xian()
{
    m_game = 4;
    QString str = ui->label_result->text();
    str.append("闲赢");
    ui->label_result->setText(str);
}

void MainWindow::on_same()
{
    m_game = 1;
    QString str = ui->label_result->text();
    str.append("和");
    ui->label_result->setText(str);
}

void MainWindow::on_zhuangdui()
{
    m_bankerPair = 2;
    QString str = ui->label_result->text();
    str.append("庄对");
    ui->label_result->setText(str);
}

void MainWindow::on_xiandui()
{
    m_playerPair = 5;
    QString str = ui->label_result->text();
    str.append("闲对");
    ui->label_result->setText(str);
}

void MainWindow::phase_zero()
{
    // 洗牌中
    // 启用该启用的按钮
    ui->pu_start->setEnabled(true);
    ui->pu_changeXue->setEnabled(true);
    ui->pu_leave->setEnabled(true);
    //ui->pu_init->setEnabled(true);
}

void MainWindow::phase_countDown(unsigned int start, unsigned int end)
{
    // 倒计时中
    first = true;
    unsigned int time = end - start;
    times = count_down_num - time;
    ui->pu_stop->setEnabled(true);
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
    //ui->pu_init->setEnabled(true);
}

void MainWindow::result_list(QJsonArray array)
{
    qDebug() << "array.count : " << array.count();
    // 获取结果和规律的图片
    for(int i = 0;i < array.count();i++){
        QString path = QString(":/result/images/result/");//:/result/images/result/same.png
        QString path_gl = QString(":/big_way/images/big_way/gl_");//:/big_way/images/big_way/gl_xian.png
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
        if(path != ":/result/images/result/useless.png"){
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

            little_little_append(m_game);
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
    form->button_enter()->setEnabled(true);
    form->exec();
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
    // 发送结果
    if(m_game == -1){
        QMessageBox box;
        box.setText("结果无效");
        box.exec();
    }
    else{
        // 发送请求
        form->button_enter()->setEnabled(false);
        request_summit();
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
                if(way_big->now.m_now_row == 45){
                    for(int row = 0;row < 45;row++){
                        for(int line = 0;line < 6;line++){
                            way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                            way_big->labels[row][line].label->setText(way_big->labels[row + 1][line].label->text());
                            way_big->labels[row][line].who_win = way_big->labels[row + 1][line].who_win;


                        }
                    }
                    for(int i = 0;i < 6;i++){
                        way_big->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                        way_big->labels[45][i].label->setText("");
                        way_big->labels[45][i].who_win = 0;
                    }
                    way_big->equa.m_now_row--;
                    way_big->front.m_now_row--;
                    way_big->dragon.m_now_row--;
                }
                else{
                    way_big->now.m_now_row++;
                }
            }
            // 还没成龙
            else{
                // 如果下一个有值，则成龙,移动到下列同行
                if(way_big->now.m_now_line == 5 || way_big->labels[way_big->now.m_now_row][way_big->now.m_now_line + 1].who_win != 0){
                    // 移动到下一列同行，如果已经是最后一列了怎么办？
                    if(way_big->now.m_now_row == 45){
                        for(int row = 0;row < 45;row++){
                            for(int line = 0;line < 6;line++){
                                way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                                way_big->labels[row][line].label->setText(way_big->labels[row + 1][line].label->text());
                                way_big->labels[row][line].who_win = way_big->labels[row + 1][line].who_win;


                            }
                        }
                        for(int i = 0;i < 6;i++){
                            way_big->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                            way_big->labels[45][i].label->setText("");
                            way_big->labels[45][i].who_win = 0;
                        }
                        way_big->equa.m_now_row--;
                        way_big->front.m_now_row--;
                        way_big->dragon.m_now_row--;
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
                    // 移动到下一列同行，如果已经是最后一列了怎么办？
                    if(way_big->now.m_now_row == 45){
                        for(int row = 0;row < 45;row++){
                            for(int line = 0;line < 6;line++){
                                way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                                way_big->labels[row][line].label->setText(way_big->labels[row + 1][line].label->text());
                                way_big->labels[row][line].who_win = way_big->labels[row + 1][line].who_win;


                            }
                        }
                        for(int i = 0;i < 6;i++){
                            way_big->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                            way_big->labels[45][i].label->setText("");
                            way_big->labels[45][i].who_win = 0;
                        }
                        way_big->equa.m_now_row--;
                        way_big->front.m_now_row--;
                        way_big->dragon.m_now_row--;
                    }
                    else{
                        way_big->now.m_now_row++;
                    }
                }
                else{
                    way_big->now.m_now_row = way_big->dragon.m_now_row;
                    way_big->now.m_now_line = 0;
                }
            }
            else if(!way_big->first){
                // 移动到下一列同行，如果已经是最后一列了怎么办？
                if(way_big->now.m_now_row == 45){
                    for(int row = 0;row < 45;row++){
                        for(int line = 0;line < 6;line++){
                            way_big->labels[row][line].label->setStyleSheet(way_big->labels[row + 1][line].label->styleSheet());
                            way_big->labels[row][line].label->setText(way_big->labels[row + 1][line].label->text());
                            way_big->labels[row][line].who_win = way_big->labels[row + 1][line].who_win;
                        }
                    }
                    for(int i = 0;i < 6;i++){
                        way_big->labels[45][i].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                        way_big->labels[45][i].label->setText("");
                        way_big->labels[45][i].who_win = 0;
                    }
                    way_big->equa.m_now_row--;
                    way_big->front.m_now_row--;
                    way_big->dragon.m_now_row--;
                }
                else{
                    way_big->now.m_now_row++;
                }
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
                    border-image: url(:/ask_way/images/ask_way/redPoint.png);";
        }
        else{
            // 不齐整大眼仔路
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/ask_way/images/ask_way/bluePoint.png);";
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
                        border-image: url(:/ask_way/images/ask_way/red.png);";
            }
            else{
                // 不齐整 小路
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/ask_way/images/ask_way/blue.png);";
            }
            if(zhuang){
                ui->label_zwl_two->setStyleSheet(style);
            }
            else{
                ui->label_xwl_two->setStyleSheet(style);
            }
            if(big_way.m_now_line == 0 && big_way.m_now_row > 3){
                // 肯定需要判断 凹凸路
                if(if_order(big_way,1,4)){
                    // 齐整凹凸路
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/ask_way/images/ask_way/redLine.png);";
                }
                else{
                    // 不齐整凹凸路
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/ask_way/images/ask_way/blueLine.png);";
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
                    border-image: url(:/ask_way/images/ask_way/redPoint.png);";
        }
        else{
            style = "border-radius: 8px; \
                    background-color: rgb(255, 255, 255); \
                    border-image: url(:/ask_way/images/ask_way/bluePoint.png);";
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
                        border-image: url(:/ask_way/images/ask_way/red.png);";
            }
            else{
                style = "border-radius: 8px; \
                        background-color: rgb(255, 255, 255); \
                        border-image: url(:/ask_way/images/ask_way/blue.png);";
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
                            border-image: url(:/ask_way/images/ask_way/redLine.png);";
                }
                else{
                    style = "border-radius: 8px; \
                            background-color: rgb(255, 255, 255); \
                            border-image: url(:/ask_way/images/ask_way/blueLine.png);";
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
        node->data->setText("");
        node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
    else{
        m_link_reslut = m_link_reslut->next;
    }
}

void MainWindow::request_stop()
{
    manager->setStatus(STOP);
    manager->setInterface("bjl_early_stop");
    manager->postData(QByteArray());
}

void MainWindow::request_login()
{
    manager->setStatus(LOGIN);
    manager->setInterface("dutch_login");
    QByteArray postData;
    postData.append("desk=CS1&password=b86170ccbe836000");
    manager->postData(postData);
}

void MainWindow::request_init()
{
    manager->setStatus(INIT);
    manager->setInterface("bjl_desk_ini");
    manager->postData(QByteArray());
}

void MainWindow::request_roominfo()
{
    manager->setStatus(ROOMINFO);
    manager->setInterface("HeGuanRoominfo");
    manager->postData(QByteArray());
}

void MainWindow::request_record()
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

void MainWindow::request_change_boot()
{
    manager->setStatus(CHANGEBOOT);
    manager->setInterface("bjl_change_boot");
    manager->postData(QByteArray());
}

void MainWindow::request_useless()
{
    // 禁用作废按钮
    ui->pu_useless->setEnabled(false);

    manager->setStatus(USELESS);
    manager->setInterface("bjl_game_burn");
    QByteArray postData;
    postData.append(QString("boot_num="));postData.append(ui->label_times_xue->text());
    postData.append(QString("&pave_num="));postData.append(ui->label_times_pu->text());
    manager->postData(postData);
}

void MainWindow::request_summit()
{
    manager->setStatus(SUMMIT);
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

        login_window->close();
        this->showFullScreen();
        request_roominfo();
    }
    else{
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
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

        Link* node = m_link_reslut_head;
        while(node->next != nullptr){
            node->data->setStyleSheet("background-color: rgb(255, 255, 255);");
            node->data->setText("");
            node = node->next;
        }
        m_link_reslut = m_link_reslut_head;

        ui->label_zwl_one->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_zwl_two->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_zwl_three->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");

        ui->label_xwl_one->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_xwl_two->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_xwl_three->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");

        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
    }
    else{
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
        box.exec();

        //ui->pu_init->setEnabled(true);
    }
}

void MainWindow::responsed_roominfo(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        qDebug() << data.at(0);
        unsigned int BootNum = data.at(0)["BootNum"].toInt();
        unsigned int PaveNum = data.at(0)["PaveNum"].toInt();
        QString DeskName = data.at(0)["DeskName"].toString();
        count_down_num = data.at(0)["CountDown"].toInt();
        wait_down = data.at(0)["WaitDown"].toInt();
        ui->label_times_xue->setText(QString::number(BootNum));
        ui->label_times_pu->setText(QString::number(PaveNum));
        ui->label_desk_id->setText(DeskName);

        unsigned int maxLimit = data.at(0)["MaxLimit"].toInt();
        unsigned int minLimit = data.at(0)["MinLimit"].toInt();
        unsigned int tieMaxLimit = data.at(0)["TieMaxLimit"].toInt();
        unsigned int tieMinLimit = data.at(0)["TieMinLimit"].toInt();
        unsigned int PairMaxLimit = data.at(0)["PairMaxLimit"].toInt();
        unsigned int PairMinLimit = data.at(0)["PairMinLimit"].toInt();
        ui->label_maxLimit->setText(QString::number(maxLimit));
        ui->label_minLimit->setText(QString::number(minLimit));
        ui->label_tieMaxLimit->setText(QString::number(tieMaxLimit));
        ui->label_tieMinLimit->setText(QString::number(tieMinLimit));
        ui->label_pairMaxLimit->setText(QString::number(PairMaxLimit));
        ui->label_pairMinLimit->setText(QString::number(PairMinLimit));

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
        case 3:{
            phase_finish();
            break;
        }
        }
        request_record();
    }
    else{
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
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
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
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
        times = count_down_num;
        ui->pu_changeXue->setEnabled(false);
        first = true;
        ui->pu_stop->setEnabled(true);
        on_start();
    }
    else{
        ui->pu_start->setEnabled(true);

        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
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

        for(QList<QLabel*> list : little_little_way){
            for(QLabel *label : list){
                label->setText("");
                label->setStyleSheet("background-color: rgb(255, 255, 255);");
            }
        }
        index_x = -1;
        index_y = -1;
        tie_num = 0;


        ui->label_zwl_one->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_zwl_two->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_zwl_three->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");

        ui->label_xwl_one->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_xwl_two->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");
        ui->label_xwl_three->setStyleSheet("border-radius: 8px;background-color: rgb(255, 255, 255);");

        way_big->init();
        way_big_eye->init();
        way_little->init();
        way_aotu->init();
    }
    else{
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
        box.exec();
    }
}

void MainWindow::responsed_useless(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        //QString path = QString("border-image: url(:/result/useless.png);");
        //m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(path));

        // 指向下一个结果 label
        //next_result();

        ui->label_result->setText("");

        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);
        ui->pu_zhuang->setEnabled(false);
        ui->pu_xian->setEnabled(false);
        ui->pu_same->setEnabled(false);
        ui->pu_zhuangdui->setEnabled(false);
        ui->pu_xiandui->setEnabled(false);
        ui->pu_useless->setEnabled(false);
        ui->pu_start->setEnabled(true);
        ui->pu_changeXue->setEnabled(true);
        ui->label_up_pave->setText("上铺：作废");


        //request_change_boot();
        //this->times = wait_down;
    }
    else{
        ui->pu_useless->setEnabled(true);

        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
        box.exec();
    }
}

void MainWindow::responsed_summit(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    QString info = json.value("info").toString();
    unsigned int status = json.value("status").toInt();

    if(status == 1){
        ui->label_result->setText(QString(""));
        QString path = QString(":/result/images/result/");//:/result/images/result/same.png
        QString path_gl = QString(":/big_way/images/big_way/gl_");//:/big_way/images/big_way/gl_xian.png
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
        QString style = "border-image: url(" + path + ");";
        m_link_reslut->data->setStyleSheet(m_link_reslut->data->styleSheet().append(style));
        ongl_enter(path_gl);
        // 指向下一个结果 label
        next_result();

        // 续添小小路
        little_little_append(m_game);

        ui->pu_start->setEnabled(true);
        ui->pu_zhuang->setEnabled(false);
        ui->pu_zhuangdui->setEnabled(false);
        ui->pu_xian->setEnabled(false);
        ui->pu_xiandui->setEnabled(false);
        ui->pu_same->setEnabled(false);

        times = 30;

        m_game = -1;
        m_playerPair = 0;
        m_bankerPair = 0;
        ui->label_result->setText("");

        ui->pu_enter->setEnabled(false);
        ui->pu_cancel->setEnabled(false);

        form->hide();
        ui->pu_useless->setEnabled(false);
        ui->pu_changeXue->setEnabled(true);
    }
    else{
        ui->pu_enter->setEnabled(true);
        ui->pu_cancel->setEnabled(true);

        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
        box.exec();
    }
}

void MainWindow::responsed_stop(QNetworkReply *reply)
{
    ui->pu_stop->setEnabled(false);
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        times = 0;
    }
    else{
        QString info = json.value("info").toString();
        QMessageBox box;
        box.setText("error: " + info);
        box.exec();
    }
}



