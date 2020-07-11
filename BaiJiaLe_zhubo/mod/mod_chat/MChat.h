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
    void responsed_ban(QNetworkReply *reply);

private:
    Ui::MChat *ui;

    MChatArg *arg;
    QMap<int,exe_chat> _map;

private slots:
    void pu_name();
    void readMessage();
    void request_ban();
    void on_responsed(QNetworkReply *reply, int status);
public:
    int talkid;
};

#endif // MCHAT_H
