#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QLabel>
#include <string>
#include <QMainWindow>
using namespace std;

#include "mod/MNetManager.h"

typedef struct{
    int num = 0;
    int color = -1;
    bool hua = false;
    QLabel *label;
    string face = ""; //面板
}CARD;

typedef struct node{
    int num;// 0 代表闲家1 3代表庄家
    struct node *next;
    CARD data[5] = {};
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

    void line_finish();

    void pu_stop();
    void pu_locate();

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

    NUMBER number;
    int location;
    int count_down;

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
    void apply_room_card(QJsonArray zhuang,QJsonArray one,QJsonArray two,QJsonArray three);

    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();

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
