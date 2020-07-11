#ifndef MRECORD_H
#define MRECORD_H

#include <QObject>
#include <QGridLayout>
#include "mod/MNetManager.h"

typedef struct Link_node{
    QLabel* data;
    struct Link_node* front;
    struct Link_node* next;
}Record_link;

class MRecord;
class MNetManager;
typedef struct{
    QLabel *boot;
    QGridLayout *grid;

    MNetManager *manager;
    int status;
    QString interface;
}MRecordArg;

class MRecord;
typedef void (MRecord::*exe_record)(QNetworkReply *);

class MRecord : public QObject
{
    Q_OBJECT
private:
    MRecordArg *arg;
    QMap<int,exe_record> _map;
    Record_link *link;
    Record_link *head;

public:
    explicit MRecord(MRecordArg *arg ,QObject *parent = nullptr);

public slots:
    void request_record();
    void apply_record(QString game,QString bankerPair,QString playerPair);
    void on_useless();
signals:
    void finished();

private slots:
    void on_responsed(QNetworkReply* reply,int status);

private:
    void responsed_record(QNetworkReply *reply);
    void update_panel(QJsonArray array);
    void increase();
    void append(QString game,QString bankerPair,QString playerPair);
};

#endif // MRECORD_H
