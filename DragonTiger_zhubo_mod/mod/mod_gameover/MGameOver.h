#ifndef MGAMEOVER_H
#define MGAMEOVER_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include "mod/MNetManager.h"

namespace Ui{class MGameOver;}

typedef struct{
    QPushButton *banker;
    QPushButton *player;
    QPushButton *tie;
    QPushButton *enter;
    QPushButton *cancel;
    QLabel *boot;
    QLabel *pave;
    QLabel *desk_id;
    QLabel *result;
    int status;
    QString interface;
    MNetManager *manager;
}MGameOverArg;



class MGameOver;
typedef void  (MGameOver::*exe_gameover)(QNetworkReply *);

class MGameOver : public QWidget
{
    Q_OBJECT
public:
    explicit MGameOver(MGameOverArg *arg, QWidget *parent = nullptr);

private:
    Ui::MGameOver *ui;

    MGameOverArg *arg;
    int score_game = 0;
    int score_playerPair = 0;
    int score_bankerPair = 0;

    QMap<int,exe_gameover> _map;

private slots:
    void pu_banker();
    void pu_player();
    void pu_tie();
    void pu_enter();
    void on_responsed(QNetworkReply* reply,int status);
    void pu_yes();
    void pu_no();

private:
    void request_gameover();
    void responsed_gameover(QNetworkReply *reply);

public slots:
    void clear();

signals:
    void gameOver(QString);
};

#endif // MGAMEOVER_H
