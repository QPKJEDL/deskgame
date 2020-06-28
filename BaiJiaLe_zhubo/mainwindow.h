#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QLabel>
#include <QTcpSocket>
#include "form.h"
#include "login.h"
#include "mod/MNetManager.h"

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

typedef struct{
    int game;
    QString style;
}ASKWAY;

class MainWindow;
class MNetManager;
typedef void (MainWindow::*exe)(QNetworkReply *);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initlimit(QStringList& list  );
    //////////////////////////////
    //added by kris,2020-6-16
    //添加长连接相关代码。
    ////////////////////////////////

    void pintosend(QDataStream& stream, QString id, QString token);

    void sendLoginMsg(QDataStream& stream);
    /////////////////////////////////////////////////

private:
    Ui::MainWindow *ui;
    Login *login_window;
    // 网络
    MNetManager *manager;
    QMap<int,exe> _map;
    QString _long_id;
    QString _long_token;

    // 倒计时
    QTimer *m_timer_count_down;
    int times;

    // 结果
    int m_game;
    int m_playerPair;
    int m_bankerPair;

    // 重连时使用的变量
    QString m_game_str;
    QString m_playerPair_str;
    QString m_bankerPair_str;

    // 确定弹窗
    Form *form;

    // 结果链表
    Link* m_link_reslut;
    Link* m_link_reslut_head;


    ////////////////////////////added by kris,2020-6-16
    QTcpSocket *m_tcpsocket;
    QString userStr;
    bool m_login;


private slots:
    void pu_init();
    void pu_start();
    void pu_changeXue();
    void pu_useless();
    void pu_zhuang();
    void pu_zhuangdui();
    void pu_xian();
    void pu_xiandui();
    void pu_same();
    void on_cancel();
    void on_enter();
    void on_responsed(QNetworkReply* reply,int status);
    void request_first_login();
    // 倒计时
    void count_down();
    // 弹窗
    void tc_enter();
    void tc_cancel();
    /////////////////////added by kris,2020-6-16
    void readMessage();
    void sendMessage(QString id,QString token);
    void connectedServer();

private:
    void on_init();
    void apply_start();

    void request_room_info();
    void request_result_list();
    void request_gameover();

    void reqeust_second_login(QString live_user, QString password);
    // 刷新重启前结果
    void result_list(QJsonArray array);
    void result_increase();
    // 房间状态
    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();

    void responsed_login(QNetworkReply *reply);
    void responsed_second_login(QNetworkReply *reply);
    void responsed_init(QNetworkReply *reply);
    void responsed_roominfo(QNetworkReply *reply);
    void responsed_record(QNetworkReply *reply);
    void responsed_start(QNetworkReply *reply);
    void responsed_changeBoot(QNetworkReply *reply);
    void responsed_useless(QNetworkReply *reply);
    void responsed_gameover(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
