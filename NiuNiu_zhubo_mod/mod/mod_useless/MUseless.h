#ifndef MUSELESS_H
#define MUSELESS_H

#include <QObject>
#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
typedef struct{
    QPushButton *useless;
    QLabel *boot;
    QLabel *pave;

    MNetManager *manager;
    int status;
    QString interface;
}MUselessArg;

class MUseless;
typedef void (MUseless::*exe_useless)(QNetworkReply *);


class MUseless : public QWidget
{
    Q_OBJECT
public:
    explicit MUseless(MUselessArg *arg,QWidget *parent = nullptr);

private:
    MUselessArg *arg;
    QMap<int,exe_useless> _map;

signals:
    void uselessed();

private slots:
    void pu_useless();
    void on_responsed(QNetworkReply *reply, int status);

private:
    void request_useless();
    void responsed_useless(QNetworkReply *reply);

};

#endif // MUSELESS_H
