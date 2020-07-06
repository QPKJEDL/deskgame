#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTcpSocket>
#include <QList>
#include <string>
using namespace std;

#include "mod/MNetManager.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QNetworkReply;
class QGraphicsOpacityEffect;

class MNetManager;
class MainWindow;
typedef void (MainWindow::*exe)(QNetworkReply *);

#include "Structure.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString m_str;

    void pintosend(QDataStream& stream, QString id, QString token);
    void sendLoginMsg(QDataStream& stream);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void update();
    void update_date();

    void while_line_finish();
    void while_timeout();
    void while_responsed(QNetworkReply* reply,int status);
    void while_count_down();
    void while_readyRead();
    void while_connected();

    void pu_exit();
    void pu_login();
    void pu_stop();
    void pu_locate();
    void pu_first_login();
    void pu_summit();
    void pu_useless();
    void pu_start();
    void pu_init();

private:
    void sendMessage(QString id,QString token);


private:
    Ui::MainWindow *ui;

    Login *login_window;
    //Live *live_window;
    QPushButton *pu_money;

    QTimer* timer_focus;
    QTimer* timer_opacity;
    QTimer* timer_date;
    QTimer* timer_Countdown;
    QGraphicsOpacityEffect* m_graphiceffect;
    QGraphicsOpacityEffect* n_graphiceffect;

    bool m_light;
    QLabel *label_name;
    QString m_edit_last;
    players *head;

    bool m_fapai;

    NUMBER number;
    int location;
    int count_down;

    MNetManager *manager;
    MNetManager *second_manager;
    QMap<int,exe> _map;
    QString _long_id;
    QString _long_token;

    QTcpSocket *m_tcpsocket;
    QString userStr;
    bool m_login = true;

    // 聊天信息条数
    int chat_num = 0;

private:
    void LabelPaixu(players *head);
    void wait(CARD card);
    void result();


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

    void Request_first_login();
    void Request_second_login(QString live_user, QString password);
    void Request_top_three();
    void Request_faPai(CARD card);
    void Request_summit();
    void Request_useless();
    void Request_start();
    void Request_initialize();
    void request_room_info();

    void responsed_first_login(QNetworkReply *reply);
    void responsed_second_login(QNetworkReply *reply);
    void responsed_start(QNetworkReply *reply);
    void responsed_roominfo(QNetworkReply *reply);
    void responsed_roomcard(QNetworkReply *reply);
    void responsed_locate(QNetworkReply *reply);
    void responsed_fapai(QNetworkReply *reply);
    void responsed_summit(QNetworkReply *reply);
    void responsed_useless(QNetworkReply *reply);
    void responsed_init(QNetworkReply *reply);
    void responsed_top_three(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
