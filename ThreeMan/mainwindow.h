#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QLabel>
#include <string>
#include <QMainWindow>
using namespace std;

#include "mod/MNetManager.h"

//M
// !我认为，face和color就可以得到203了
typedef struct{
    QLabel *label;
    string face = ""; //面板
    int num = 0;
    bool hua = false;//true 为花牌，用于判断是否是5花牛
    int color = -1;//3代表黑桃，2代表红桃，1代表梅花，0代表方块
}CARD;

typedef struct node{
    CARD data[3] = {};
    int num;// 0 代表闲家1 3代表庄家
    struct node *next;
}players;

//分针走一轮，时针走一格
typedef struct{
    int man = 0;//第几个玩家
    int num = 0;//第几张牌
    void increase(){
        if(++man == 7){
            num++;
            man = 0;
        }
    }
}NUMBER;

typedef struct{
    int paiXing;
    CARD biggest;
    int huaNum;
}PAIRESULT;


typedef struct{
    QLabel *zhuang;
    QLabel *one;
    QLabel *two;
    QLabel *three;
    QLabel *four;
    QLabel *five;
    QLabel *six;
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
    MainWindow(int id, QString token, QString limit, QString tieLimit, QWidget *parent = nullptr);
    ~MainWindow();

    QString m_str;
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void update();
    void update_date();

    void pu_stop();
    void pu_locate();

    void line_finish();

    void on_timeout();
    void on_exit();
    void on_responsed(QNetworkReply* reply,int status);
    void on_count_down();

    void Request_faPai(CARD card);
    void Request_summit();
    void Request_useless();
    void Request_start();
    void Request_initialize();

private:
    Ui::MainWindow *ui;

    QTimer* timer_focus;
    QTimer* timer_opacity;
    QTimer* timer_date;
    QTimer* timer_Countdown;
    QGraphicsOpacityEffect* m_graphiceffect;
    QGraphicsOpacityEffect* n_graphiceffect;


    int quarter;
    bool m_light;
    QLabel *label_name;
    QString m_edit_last;
    players *head;
    QList<FOURLABELS*> result_list;

    bool m_fapai;

    int desk_id;
    QString desk_token;

    NUMBER number;
    int location;
    int count_down;
    int count_down_num;

    MNetManager *manager;
    QMap<int,exe> _map;

private:
    void quarter_increase();
    void LabelPaixu(players *head);
    void wait(CARD card);
    void result();

    void request_game_record();
    void request_room_info();
    void request_room_card();

    void apply_summit();
    void apply_useless();
    void apply_locate();
    void apply_game_record(QJsonArray array);
    void apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three, QJsonArray four, QJsonArray five, QJsonArray six);

    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();

public:
    void responsed_start(QNetworkReply *reply);
    void responsed_roominfo(QNetworkReply *reply);
    void responsed_record(QNetworkReply *reply);
    void responsed_roomcard(QNetworkReply *reply);
    void responsed_locate(QNetworkReply *reply);
    void responsed_fapai(QNetworkReply *reply);
    void responsed_summit(QNetworkReply *reply);
    void responsed_useless(QNetworkReply *reply);
    void responsed_init(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
