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

class MChat : public QWidget
{
    Q_OBJECT

public:
    explicit MChat(MChatArg *arg);
    ~MChat();

private:
    void request_ban();
    void responsed_ban(QNetworkReply *reply);

private:
    Ui::MChat *ui;

    MChatArg *arg;

private slots:
    void pu_name();
    void readMessage();

public:
    int talkid;
};

#endif // MCHAT_H
