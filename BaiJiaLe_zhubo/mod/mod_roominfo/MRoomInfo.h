#ifndef MROOMINFO_H
#define MROOMINFO_H

#include <QObject>
#include "mod/MNetManager.h"

typedef struct{
    int status;
    QString inter;
    MNetManager *manager;

    QLabel *limit;
    QLabel *tieLimit;
    QLabel *pairLimit;

    QLabel *timesBoot;
    QLabel *timesPave;
    QLabel *deskId;
}MRoomInfoArg;

class MRoomInfo;
typedef void (MRoomInfo::*exe_roomInfo)(QNetworkReply *);

class MRoomInfo : public QObject
{
    Q_OBJECT
public:
    explicit MRoomInfo(MRoomInfoArg *arg,QObject *parent = nullptr);

private:
    MRoomInfoArg *arg;
    QMap<int,exe_roomInfo> _map;

private:
    void responsed_room_info(QNetworkReply *reply);

public slots:
    void request_room_info();
    void on_responsed(QNetworkReply* reply,int status);

signals:
    void send_phase(int,int,int,int,int);
};

#endif // MROOMINFO_H
