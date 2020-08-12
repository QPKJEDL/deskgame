#ifndef MSUMMIT_H
#define MSUMMIT_H

#include <QWidget>
#include <mod/MNetManager.h>

class MNetManager;
typedef struct{
    QPushButton *button;
    QLabel *boot;
    QLabel *pave;
    QLabel *locate;
    QLabel *opration_show;
    QLabel *result;

    MNetManager *manager;
    QString inter;
    int status;
}MSummitArg;

namespace Ui {
class MSummit;
}

class MSummit;
typedef void (MSummit::*exe_summit)(QNetworkReply *);

class MSummit : public QWidget
{
    Q_OBJECT

public:
    explicit MSummit(MSummitArg *arg,QWidget *parent = nullptr);
    ~MSummit();

private:
    Ui::MSummit *ui;
    MSummitArg *arg;
    QMap<int,exe_summit> _map;
    QString result;

private:
    void request_summit();
    void responsed_summit(QNetworkReply *reply);

signals:
    void summited(QString str);

private slots:
    void on_responsed(QNetworkReply*,int);
    void pu_summit();

public slots:
    void cardFinished(QString re);

};

#endif // MSUMMIT_H
