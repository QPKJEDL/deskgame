#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QLabel>
#include <string>
#include <QList>
#include <QMainWindow>
#include "mod/MNetManager.h"
#include "login.h"
using namespace std;

#include <QNetworkReply>
#include <QNetworkRequest>

//M
// !我认为，face和color就可以得到203了
typedef struct{
    QLabel *label;
    string face = ""; //面板
    int num = 0;
    int color = -1;//3代表黑桃，2代表红桃，1代表梅花，0代表方块
}CARD;

typedef struct node{
    CARD data[2] = {};
    QString player;// 0 代表闲家1 3代表庄家
    struct node *next;
}players;

//分针走一轮，时针走一格
typedef struct{
    int man = 0;//第几个玩家
    int num = 0;//第几张牌
    void increase(){
        if(++man == 4){
            num++;
            man = 0;
        }
    }
}NUMBER;

typedef struct{
    int paiXing;
    CARD biggest;
}PAIRESULT;


typedef struct{
    QLabel *zhuang;
    QLabel *one;
    QLabel *two;
    QLabel *three;
}FOURLABELS;

typedef struct{
    string face;
    bool win;
} LABELRESULT;
//M


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QNetworkReply;
class QGraphicsOpacityEffect;



class MNetManager;
class MainWindow;
typedef void (MainWindow::*exe)(QNetworkReply *);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString m_str;
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    QTimer* timer_focus;
    QTimer* timer_opacity;
    QTimer* timer_date;
    QGraphicsOpacityEffect* m_graphiceffect;
    QGraphicsOpacityEffect* n_graphiceffect;
    bool m_light;

    players *head;
    QList<FOURLABELS*> result_list;
    int quarter;
    QLabel *label_name;

    // 网络
    MNetManager *manager;
    QMap<int,exe> _map;
    bool m_fapai;

    Login *login_window;

    QString m_edit_last;

    NUMBER number;
    int location;
    int count_down;//倒计时计时器函数执行几回
    QTimer* timer_Countdown; // 间隔1秒的倒计时更新计时器
    int count_down_num;

    // 用于断线重连
    QString ShunMen;
    QString TianMen;
    QString FanMen;
    QString Banker;

private slots:
    void update_focus();
    void update_date();

    void when_timeout();
    void when_count_down();
    void when_line_finish();

    void pu_login();
    void pu_init();
    void pu_start();
    void pu_change_boot();
    void pu_end();
    void pu_locate();
    void pu_summit();
    void pu_exit();
    void pu_useless();

    void on_responsed(QNetworkReply* reply,int status);

private:
    void LabelPaixu(players *head);
    void quarter_increase();
    void wait(CARD card,string paixing);
    void result();

    void on_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three,string zhuang_result,string one_result,string two_result,string three_result);

    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();

    void apply_locate();
    void apply_summit();
    void apply_useless();
    void apply_record(QJsonArray array);

    void request_login();
    void request_start();
    void request_roominfo();
    void request_roomcard();
    void request_record();
    void request_locate();
    void request_faPai(CARD card);
    void request_summit();
    void request_useless();
    void request_init();
    void request_end();

    void responsed_login(QNetworkReply *reply);
    void responsed_start(QNetworkReply *reply);
    void responsed_roominfo(QNetworkReply *reply);
    void responsed_roomcard(QNetworkReply *reply);
    void responsed_record(QNetworkReply *reply);
    void responsed_locate(QNetworkReply *reply);
    void responsed_fapai(QNetworkReply *reply);
    void responsed_summit(QNetworkReply *reply);
    void responsed_useless(QNetworkReply *reply);
    void responsed_init(QNetworkReply *reply);
    void responsed_end(QNetworkReply *reply);

    //void on_game_record(QJsonArray array);
};
#endif // MAINWINDOW_H
