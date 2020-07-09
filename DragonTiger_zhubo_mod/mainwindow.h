#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QLabel>
#include <QTcpSocket>
#include "mod/mod_money/MMoney.h"
#include "mod/mod_login/MLogin.h"
#include "mod/MNetManager.h"
#include "mod/mod_topThree/MTopThree.h"
#include "mod/mod_leave/MLeave.h"
#include "mod/mod_gameover/MGameOver.h"
#include "mod/mod_roominfo/MRoomInfo.h"
#include "mod/mod_phase/MPhase.h"
#include "mod/mod_record/MRecord.h"
#include "mod/mod_start/MStart.h"
#include "mod/mod_useless/MUseless.h"
#include "mod/mod_changeBoot/MChangeBoot.h"
#include "mod/mod_init/MInit.h"
#include "mod/mod_topFive/MTopFive.h"

class MMoney;
class MLogin;
class MTopThree;
class MGameOver;
class MRoomInfo;
class MPhase;
class MRecord;
class MStart;
class MUseless;
class MUseless;
class MChangeBoot;
class MInit;
class MTopFive;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // 网络
    MNetManager *manager;
    MNetManager *second_manager;
    QTcpSocket *m_tcpsocket;

private:
    MLogin *module_login;
    MMoney *module_money;
    MTopThree *module_topThree;
    MLeave *module_leave;
    MGameOver *module_gameOver;
    MRoomInfo *module_roomInfo;
    MPhase *module_phase;
    MRecord *module_record;
    MStart *module_start;
    MUseless *module_useless;
    MChangeBoot *module_changeBoot;
    MInit *module_init;
    MTopFive *module_topFive;
};
#endif // MAINWINDOW_H
