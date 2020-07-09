#ifndef MPHASE_H
#define MPHASE_H

#include <QObject>
#include <QPushButton>
#include <QTimer>

class MPhase;
typedef struct{
    QPushButton *init;
    QPushButton *start;
    QPushButton *changeBoot;
    QPushButton *leave;
    QPushButton *banker;
    QPushButton *player;
    QPushButton *tie;
    QPushButton *enter;
    QPushButton *cancel;
    QPushButton *useless;
}MPhaseArg;

namespace Ui {
class MPhase;
}

class MPhase : public QWidget
{
    Q_OBJECT
public:
    explicit MPhase(MPhaseArg *arg,QWidget *parent = nullptr);

private:
    Ui::MPhase *ui;
    MPhaseArg *arg;

    int times;
    QTimer *timer;

    int count_down;
private slots:
    void on_timeout();

public slots:
    void to_phase(int phase,int start,int end,int countDown);
    void on_started();
    void on_finished();
    void on_useless();
signals:
    void timeout();
};

#endif // MPHASE_H
