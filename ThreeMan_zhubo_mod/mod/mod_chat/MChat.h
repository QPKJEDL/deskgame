#ifndef MCHAT_H
#define MCHAT_H

#include <QWidget>
#include <QGridLayout>
#include <mod/MNetManager.h>

namespace Ui {
class MChat;
}

class MNetManager;
typedef struct{
    QGridLayout *grid;
    QTcpSocket *tcpSocket;
    MNetManager *manager;
    QString interface;
    int status;
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

public:
    int talkid;

signals:
    void show_reword(QString user,int money);
};

#endif // MCHAT_H
