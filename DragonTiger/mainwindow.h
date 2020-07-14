#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QLabel>
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "mod/MNetManager.h"
#include "login.h"

typedef struct node{
    QLabel* data;
    struct node* front;
    struct node* next;
}Link;

typedef struct node_num{
    int m_now_line = 0; // 行号，最大5
    int m_now_row = 0; // 列号 最大44
    struct node_num up(){
        struct node_num node_num;
        if(m_now_line == 0){
            if(m_now_row == 0){
                node_num.m_now_row = 0;
                node_num.m_now_line = 0;
                return node_num;
            }
            else{
                node_num.m_now_row = m_now_row - 1;
                node_num.m_now_line = 5;
                return node_num;
            }
        }
        else{
            node_num.m_now_line = m_now_line - 1;
            node_num.m_now_row = m_now_row;
            return node_num;
        }
    }
    struct node_num down(){
        struct node_num node_num;
        if(m_now_line == 5){
            if(m_now_row == 44){
                node_num.m_now_row = 44;
                node_num.m_now_line = 5;
                return node_num;
            }
            else{
                node_num.m_now_row = m_now_row + 1;
                node_num.m_now_line = m_now_line = 0;
                return node_num;
            }
        }
        else{
            node_num.m_now_line = m_now_line + 1;
            node_num.m_now_row = m_now_row;
            return node_num;
        }
    }
    void init(){
        m_now_row = 0;
        m_now_line = 0;
    }
}NUMBER;

typedef struct{
    QLabel* label;
    int who_win = 0; // 这个label是谁赢了
    bool bank = false; // 是否为庄对
    bool tie = false; // 是否为闲对
}LABEL;

typedef struct{
    LABEL  labels[45][6];
    NUMBER now; // 指向哪个 label 了；
    NUMBER front; // 前一个赢得 label 是哪个
    NUMBER dragon; // 成龙之后的第一个 label 的位置
    bool first = true; // 是否是第一个
    NUMBER equa; // 和的位置
    int times = 0; // 连赢的次数
    void init(){
        for(int row = 0;row < 45;row++){
            for(int line = 0;line < 6;line++){
                labels[row][line].label->setText("");
                labels[row][line].label->setStyleSheet("background-color: rgb(255, 255, 255);");
                labels[row][line].tie = false;
                labels[row][line].who_win = 0;
                labels[row][line].bank = false;
            }
        }
        now.init();
        front.init();
        dragon.init();
        equa.init();
        first = true;
        times = 0;
        dragon.m_now_row = -1;
    }
}WAY;

class MainWindow;
class MNetManager;
typedef void (MainWindow::*exe)(QNetworkReply *);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // 网络
    MNetManager *manager;
    QMap<int,exe> _map;
    Login *login_window;

    // 倒计时
    QTimer *m_timer_count_down;
    int times;
    int count_down_num;

    // 结果
    int m_result;

    // 确定弹窗
    Form *form;

    // 结果链表
    Link* m_link_reslut;
    Link* m_link_reslut_head;

    int m_front_win;// 上次是谁赢
    int m_same_times;// 连和的次数

    // 大路
    WAY* way_big;
    // 大眼仔
    WAY* way_big_eye;
    // 小路
    WAY* way_little;
    // 凹凸路
    WAY* way_aotu;
    // 判断是否齐整的函数
    bool if_order(NUMBER now, int first, int offset);
    int how_many(int row);
    // 判断有无或直落的函数
    bool if_YesOrNo(NUMBER now, int offset);
    // 更新问路结果
    void update_ask_way();
    // 下一个问路 label
    void next_ask_way(WAY *way, int game, QString style);



    // 房间状态
    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();
    // 下一个该更新的大路的位置
    NUMBER next_zhuang(int offset);
    // 刷新结果
    void apply_init();
    void apply_start();
    void apply_enter(QJsonArray array);
    void update_ask(NUMBER big_way, bool zhuang);

    void next_result();

private:
    void request_login();
    void request_room_info();
    void request_result_list();
    void request_init();
    void request_start();
    void request_change_boot();
    void request_useless();
    void request_summit();

    void responsed_init(QNetworkReply *reply);
    void responsed_login(QNetworkReply *reply);
    void responsed_roominfo(QNetworkReply *reply);
    void responsed_record(QNetworkReply *reply);
    void responsed_start(QNetworkReply *reply);
    void responsed_change_boot(QNetworkReply *reply);
    void responsed_useless(QNetworkReply *reply);
    void responsed_summit(QNetworkReply *reply);

private slots:
    void pu_login();
    void pu_init();
    void pu_start();
    void pu_changeXue();
    void pu_stop();
    void pu_leave();
    void pu_useless();
    void pu_long();
    void pu_tiger();
    void pu_enter();
    void pu_cancel();
    void pu_same();

    void tc_enter();
    void tc_cancel();

    void on_responsed(QNetworkReply* reply,int status);
    // 刷新结果
    void ongl_enter(QString path_gl);

    // 倒计时
    void count_down();
};
#endif // MAINWINDOW_H
