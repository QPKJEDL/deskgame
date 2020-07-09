#ifndef MSTART_H
#define MSTART_H

#include <QObject>
#include <mod/MNetManager.h>

class MNetManager;
typedef struct{
    QPushButton *button;
    QLabel *boot;
    QLabel *pave;

    MNetManager *manager;
    QString interface;
    int status;
}MStartArg;

class MStart;
typedef void (MStart::*exe_start)(QNetworkReply *);

class MStart : public QObject
{
    Q_OBJECT

public:
    MStart(MStartArg *arg,QObject *parent = nullptr);

private:
    MStartArg *arg;
    QMap<int,exe_start> _map;

private:
    void request_start();
    void responsed_start(QNetworkReply *reply);

signals:
    void successed();

private slots:
    void on_responsed(QNetworkReply*,int);
    void pu_start();
};

#endif // MSTART_H
