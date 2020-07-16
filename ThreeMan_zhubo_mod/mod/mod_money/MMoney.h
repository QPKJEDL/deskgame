#ifndef MMONEY_H
#define MMONEY_H

#include <QWidget>
#include <QPushButton>
#include "mod/MNetManager.h"

class MNetManager;
typedef struct{
    QWidget *widget;
    MNetManager *manager;
    int status;
    QString inter;
}MMoneyArg;

class MMoney;
typedef void (MMoney::*exe_money)(QNetworkReply *);

namespace Ui {
class MMoney;
}

class MMoney : public QWidget
{
    Q_OBJECT

public:
    explicit MMoney(MMoneyArg *arg);
    ~MMoney();

private:
    Ui::MMoney *ui;

    QPushButton *button_money;
    MMoneyArg *arg;
    QMap<int,exe_money> _map;

    int first_id;
    int second_id;
    int lastid;
    int type = 1;

private slots:
    void pu_today();
    void pu_yesterday();
    void pu_now_month();
    void pu_front_month();
    void pu_next_page();
    void pu_front_page();
    void pu_search();
    void pu_money();
    void on_responsed(QNetworkReply* reply,int status);

private:
    void request_money();
    void responsed_money(QNetworkReply *reply);
    void update_panel(QJsonArray data);
};

#endif // MMONEY_H
