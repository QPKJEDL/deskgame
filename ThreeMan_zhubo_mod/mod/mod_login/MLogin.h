#ifndef MLOGIN_H
#define MLOGIN_H

#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
typedef struct{
    QString userid;
    QString passwd;

    QWidget *widget;
    MNetManager *manager_first;
    MNetManager *manager_second;
    QString interface_first;
    QString interface_second;
    int status_first;
    int status_second;
    QTcpSocket *tcpsocket;
    QString IP;
}MLoginArg;

class MLogin;
typedef void (MLogin::*exe_login)(QNetworkReply *);

namespace Ui {
class MLogin;
}

class MLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MLogin(MLoginArg *arg);
    ~MLogin();

public:
    int limit_player;
    int limit_tie;
    int limit_pair;

private:
    Ui::MLogin *ui;
    MLoginArg *arg;
    QString _long_id;
    QString _long_token;
    QMap<int,exe_login> _map;
    unsigned int desk_id;

private slots:
    void pu_login();
    void pu_cancel();
    void on_responsed(QNetworkReply* reply,int status);
    void connectedServer();
    void readMessage();

private:
    void request_first_login();
    void request_second_login();
    void responsed_first_login(QNetworkReply *reply);
    void responsed_second_login(QNetworkReply *reply);

signals:
    void successed();
};

#endif // MLOGIN_H
