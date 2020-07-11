#ifndef MPHASE_H
#define MPHASE_H

#include <QObject>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>
#include "mod/MNetManager.h"

class MNetManager;
class MPhase;
typedef struct{
    QPushButton *init;
    QPushButton *start;
    QPushButton *leave;
    QPushButton *useless;

    // 定位
    QPushButton *locate;
    QLineEdit *input;
    QLabel *location;

    MNetManager *manager;
    int status_locate;
    QString interface_locate;
}MPhaseArg;

namespace Ui {
class MPhase;
}

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
    int location;

    int times;
    QTimer *timer;

    int count_down;
private slots:
    void on_timeout();
    void on_responsed(QNetworkReply *reply, int status);
    void pu_locate();
    void while_line_finish();

public slots:
    void to_phase(int phase,int start,int end,int countDown);
    void on_finished();
    void on_start();
    void on_located();

signals:
    void located(int);
    void timeout();
    void phase_kaipai();
private:
    void request_locate(int location);
    void responsed_locate(QNetworkReply *reply);

};

#endif // MPHASE_H
