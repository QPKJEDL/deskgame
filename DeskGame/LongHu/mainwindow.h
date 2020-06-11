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
                labels[row][line].label->setStyleSheet("");
                labels[row][line].tie = false;
                labels[row][line].who_win = 0;
                labels[row][line].bank = false;
            }
        }
        now.init();
        front.init();
        dragon.init();
        equa.init();
        first = false;
        times = 0;
    }
}WAY;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int id,QString token,unsigned int maxLimit,unsigned int minLimit,unsigned int maxTie,unsigned int minTie,QMainWindow *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // 网络
    QNetworkRequest* m_request;
    QNetworkAccessManager* m_accessManager;
    QString m_post_type;

    // 倒计时
    QTimer *m_timer_count_down;
    int times;

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
    bool if_order(int offset);
    int how_many(int row);
    // 判断有无或直落的函数
    bool if_YesOrNo(int offset);
    // 更新问路结果
    void update_ask_way();
    // 下一个问路 label
    void next_ask_way(WAY *way, int game, QString style);

    void on_init();
    void on_login();
    void on_start();
    void request_room_info();
    void request_result_list();
    // 房间状态
    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();
    // 刷新结果
    void ontc_enter(QJsonArray array);
private slots:
    void pu_init();
    void pu_start();
    void pu_changeXue();
    void pu_stop();
    void pu_leave();
    void pu_useless();
    void tc_enter();
    void tc_cancel();
    void pu_enter();
    void pu_cancel();
    // 刷新结果
    void ongl_enter(QString path_gl);

    void pu_long();
    void pu_tiger();
    void pu_same();

    // 网络
    void finishedSlot(QNetworkReply *_reply);
    // 倒计时
    void count_down();
};
#endif // MAINWINDOW_H
