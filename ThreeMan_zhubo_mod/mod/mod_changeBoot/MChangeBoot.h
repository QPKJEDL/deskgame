#ifndef MCHANGEBOOT_H
#define MCHANGEBOOT_H

#include <QObject>
#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
typedef struct{
    QLabel *boot;
    QLabel *pave;

    MNetManager *manager;
    int status;
<<<<<<< HEAD
    QString inter;
<<<<<<< HEAD
<<<<<<< HEAD

=======
    QString interface;
>>>>>>> parent of 345f219... 0716
=======
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
=======
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
}MChangeBootArg;

class MChangeBoot;
typedef void (MChangeBoot::*exe_changeBoot)(QNetworkReply *);

class MChangeBoot : public QWidget
{
    Q_OBJECT
public:
    explicit MChangeBoot(MChangeBootArg *arg,QWidget *parent = nullptr);
private:
    MChangeBootArg *arg;
    QMap<int,exe_changeBoot> _map;

signals:
    void changed();

private slots:
    void pu_changeBoot();
    void on_responsed(QNetworkReply *reply, int status);

private:
    void request_changeBoot();
    void responsed_changeBoot(QNetworkReply *reply);
};

#endif // MCHANGEBOOT_H
