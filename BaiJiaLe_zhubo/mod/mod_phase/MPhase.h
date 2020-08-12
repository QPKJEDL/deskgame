#ifndef MPHASE_H
#define MPHASE_H

#include <QObject>
#include <QPushButton>
#include <QTimer>
#include <mod/MNetManager.h>

class MNetManager;
typedef struct{
    QPushButton *start;
    QPushButton *changeBoot;
    QPushButton *leave;
    QPushButton *banker;
    QPushButton *bankerPair;
    QPushButton *player;
    QPushButton *playerPair;
    QPushButton *tie;
    QPushButton *enter;
    QPushButton *cancel;
    QPushButton *useless;

    QPushButton *stop;
    MNetManager *manager;
    int status_stop;
    QString interface_stop;
}MPhaseArg;

namespace Ui {
class MPhase;
}

class MPhase;
typedef void (MPhase::*exe_phase)(QNetworkReply *);

class MPhase : public QWidget
{
    Q_OBJECT
public:
    explicit MPhase(MPhaseArg *arg,QWidget *parent = nullptr);

private:
    Ui::MPhase *ui;
    MPhaseArg *arg;

    QMap<int,exe_phase> _map;

    int times;
    QTimer *timer;

    int count_down;
    int WaitDown;
    bool first;
private slots:
    void on_timeout();
    void pu_stop();
    void on_responsed(QNetworkReply *reply, int status);

public slots:
    void to_phase(int phase,int start,int end,int countDown,int wait_down);
    void on_started();
    void on_finished();
    void on_useless();

signals:
    void timeout();

private:
    void request_stop();
    void responsed_stop(QNetworkReply *reply);
};

#endif // MPHASE_H
