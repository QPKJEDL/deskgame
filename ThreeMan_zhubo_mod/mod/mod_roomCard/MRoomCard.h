#ifndef MROOMCARD_H
#define MROOMCARD_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QGraphicsOpacityEffect>
#include "QLineEdit"
#include "Structure.h"
#include "mod/MNetManager.h"
#include <QPushButton>
#include <QTimer>

typedef struct{
    MNetManager *manager;
    int status_roomcard;
    QString interface_roomcard;
    int status_fapai;
    QString interface_fapai;
    QLabel* boot;
    QLabel* pave;
    QPushButton *locate;
    QLabel* location;
    QLineEdit* lineEdit;
}MRoomCardArg;

namespace Ui {
class MRoomCard;
}

class MRoomCard;
typedef void (MRoomCard::*exe_roomCard)(QNetworkReply *);

class MRoomCard : public QWidget
{
    Q_OBJECT

public:
    explicit MRoomCard(MRoomCardArg *arg,QWidget *parent = nullptr);
    ~MRoomCard();

private:
    Ui::MRoomCard *ui;

    int location;
    QLabel *label_name;
    QString last_input;
    NUMBER NUM;
    QTimer *timer_opacity;
    QTimer *timer_focus;
    QGraphicsOpacityEffect *graphiceffect;
    QGraphicsOpacityEffect *graphiceffect_name;
    bool light = false;


    MRoomCardArg *arg;
    QMap<int,exe_roomCard> _map;

    SEVENMAN *link;
signals:
    int get_location(int);
    int finished();
    void clear_finished();
    int locate_zero();

private:
    void init_link();
    void apply_room_card(QJsonArray zhuang, QJsonArray one, QJsonArray two, QJsonArray three, QJsonArray four, QJsonArray five, QJsonArray six);
    void responsed_roomcard(QNetworkReply *reply);
    void request_fapai(CARD card);
    void responsed_fapai(QNetworkReply *reply);
    void focus_lineedit();
    void append(string card);

public slots:
    void request_roomCard();
    void locate(int loca);
    void clear();

private slots:
    void while_timeout();
    void focus();
    void while_input();
    void on_responsed(QNetworkReply *reply, int status);
};

#endif // MROOMCARD_H
