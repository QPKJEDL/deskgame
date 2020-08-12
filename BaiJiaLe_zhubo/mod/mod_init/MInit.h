#ifndef MINIT_H
#define MINIT_H

#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
typedef struct{
    QPushButton *init;
    QLabel *boot;
    QLabel *pave;

    MNetManager *manager;
    int status;
    QString inter;
}MInitArg;

class MInit;
typedef void (MInit::*exe_init)(QNetworkReply *);

class MInit : public QWidget
{
    Q_OBJECT
public:
    explicit MInit(MInitArg *arg,QWidget *parent = nullptr);

private:
    MInitArg *arg;
    QMap<int,exe_init> _map;

signals:
    void inited();

private slots:
    void pu_init();
    void on_responsed(QNetworkReply *reply, int status);

private:
    void request_init();
    void responsed_init(QNetworkReply *reply);
};

#endif // MINIT_H
