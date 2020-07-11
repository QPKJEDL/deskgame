#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTcpSocket>
#include <QList>
#include <string>
#include "live.h"
using namespace std;

#include "mod/MNetManager.h"

#include "mod/mod_login/MLogin.h"
#include "mod/mod_roominfo/MRoomInfo.h"
#include "mod/mod_phase/MPhase.h"
#include "mod/mod_roomCard/MRoomCard.h"
#include "mod/mod_useless/MUseless.h"
#include "mod/mod_start/MStart.h"
#include "mod/mod_summit/MSummit.h"
#include "mod/mod_init/MInit.h"
#include "mod/mod_leave/MLeave.h"
#include "mod/mod_topThree/MTopThree.h"
#include "mod/mod_changeBoot/MChangeBoot.h"
#include "mod/mod_chat/MChat.h"

class MLogin;
class MRoomInfo;
class MPhase;
class MRoomCard;
class MUseless;
class MStart;
class MSummit;
class MInit;
class MLeave;
class MTopThree;
class MChangeBoot;
class MChat;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QNetworkReply;
class QGraphicsOpacityEffect;

class MNetManager;
class MainWindow;
typedef void (MainWindow::*exe)(QNetworkReply *);

//#include "Structure.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString m_str;
private:
    Ui::MainWindow *ui;

    MNetManager *manager;
    MNetManager *second_manager;
    QMap<int,exe> _map;

    QTcpSocket *m_tcpsocket;

private:
    MLogin *module_login;
    MRoomInfo *module_roomInfo;
    MPhase *module_phase;
    MRoomCard *module_roomCard;
    MUseless *module_useless;
    MStart *module_start;
    MSummit *module_summit;
    MInit *module_init;
    MLeave *module_leave;
    MTopThree *module_topThree;
    MChangeBoot *module_changeBoot;
    MChat *module_chat;
};
#endif // MAINWINDOW_H
