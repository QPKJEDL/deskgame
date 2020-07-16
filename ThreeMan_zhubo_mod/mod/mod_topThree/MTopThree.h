#ifndef MTOPTHREE_H
#define MTOPTHREE_H

#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
namespace Ui {
class MTopThree;
}

typedef struct{
    QString inter;
    int status;
    MNetManager *manager;

    QLabel *times_xue;
    QLabel *times_pu;
}MTopThreeArg;

class MTopThree;
typedef void (MTopThree::*exe_topThree)(QNetworkReply *);

class MTopThree : public QWidget
{
    Q_OBJECT

public:
    explicit MTopThree(MTopThreeArg *arg);
    ~MTopThree();

private:
    Ui::MTopThree *ui;
    MTopThreeArg *arg;
    QMap<int,exe_topThree> _map;

private slots:
    void on_responsed(QNetworkReply* reply,int status);

public slots:
    void request_top_three();
    void clear();

private:
    void responsed_top_three(QNetworkReply *reply);
    void update_panel(QJsonObject data);
};

#endif // MTOPTHREE_H
