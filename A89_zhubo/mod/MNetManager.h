#ifndef __MNETMANAGER_H__
#define __MNETMANAGER_H__

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <typeinfo>
#include "mainwindow.h"

class MNetManager : public QObject{
    Q_OBJECT
public:
    explicit MNetManager(QObject *parent = nullptr);

    void setHeader(QString header);
    void setRawHeader(QByteArray name, QByteArray rawHeader);
    void setIp(QString ip);
    void setStatus(int status);
    void setInterface(QString interface);
    void postData(QByteArray data);
private:
    QNetworkRequest *_request;
    QNetworkAccessManager *_manager;
    int _status;
    QString _ip;
signals:
    void responsed(QNetworkReply* reply,int status);
private slots:
    void onFinished(QNetworkReply *reply);
};

#endif
