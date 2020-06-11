#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QLabel>
#include <string>
#include <QMainWindow>
using namespace std;

#include <QNetworkReply>
#include <QNetworkRequest>

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
    CARD data[5] = {};
    int num;// 0 代表闲家1 3代表庄家
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
    void finishedSlot(QNetworkReply*);
    void on_timeout();
    //void pu_start();
    void pu_stop();
    void pu_end();
    void pu_locate();
    void line_finish();
    void on_summit();
    void update_date();
    void on_exit();
    void on_useless();
    // 点击开始按钮的槽函数
    //void on_start();
    // 倒计时间隔计时器\

    void Request_faPai(CARD card);
    void Request_summit();
    void Request_useless();
    void Request_start();
    void Request_initialize();
    void on_count_down();


private:
    Ui::MainWindow *ui;
    QTimer* timer_focus;
    QTimer* timer_opacity;
    QTimer* timer_date;
    QGraphicsOpacityEffect* m_graphiceffect;
    QGraphicsOpacityEffect* n_graphiceffect;
    bool m_light;
    QString m_edit_last;
    //M
    players *head;
    QList<FOURLABELS*> result_list;
    int quarter;
    QLabel *label_name;

    int desk_id;
    QString desk_token;
    QString m_post_type;
    bool m_fapai;
    //QNetworkReply* m_reply;
    QNetworkRequest* m_request;
    QNetworkAccessManager* m_accessManager;

    NUMBER number;
    int location;
    int count_down;//倒计时计时器函数执行几回
    QTimer* timer_Countdown; // 间隔1秒的倒计时更新计时器

private:
    void LabelPaixu(players *head);

    void wait(CARD card); //等待发牌
    //void locate();
    void result();
    void locate_success();

    void request_game_record();
    void on_game_record(QJsonArray array);
    void request_room_card();
    void on_room_card(QJsonArray zhuang,QJsonArray one,QJsonArray two,QJsonArray three);
    void request_room_info();
    // 房间状态
    void phase_zero();
    void phase_countDown(unsigned int start,unsigned int end);
    void phase_kaiPai();
    void phase_finish();
    //M
};
#endif // MAINWINDOW_H
