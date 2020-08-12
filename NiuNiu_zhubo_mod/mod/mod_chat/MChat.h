#ifndef MCHAT_H
#define MCHAT_H

#include <QWidget>
#include <QGridLayout>
#include <mod/MNetManager.h>
#include <QJsonObject>

namespace Ui {
class MChat;
}

class MNetManager;
typedef struct{
    //QGridLayout *grid;
    QTcpSocket *tcpSocket;
    MNetManager *manager;
    QString inter;
    int status;

    unsigned int *desk_id;
    MNetManager *manager_clear;
}MChatArg;

class MChat;
typedef void (MChat::*exe_chat)(QNetworkReply *);

class MChat : public QWidget
{
    Q_OBJECT

public:
    explicit MChat(MChatArg *arg);
    ~MChat();

private:
    void cmd_equal_twenty(QDataStream *in,int length);
    void cmd_equal_four(QDataStream *in,int length);
    void responsed_ban(QNetworkReply *reply);

private:
    Ui::MChat *ui;

    MChatArg *arg;
    QMap<int,exe_chat> _map;

private slots:
    void readMessage();
    void request_ban(QString uid);
    void on_responsed(QNetworkReply *reply, int status);

public slots:
    void clear();

public:
    int talkid;

public:
    Q_INVOKABLE void pu_name(QString userid,QString name);

signals:
    void show_reword(QString user,int money);
    void showText(QString txt,QString name,QString id);
    void ban_finish(QString txt);
    void show_top_three(QJsonObject);
};

#endif // MCHAT_H
