#ifndef MTOPFIVE_H
#define MTOPFIVE_H

#include <QWidget>
#include "mod/MNetManager.h"

class MNetManager;
namespace Ui {
class MTopFive;
}

typedef struct{
    QString inter;
    int status;
    MNetManager *manager;

    QLabel *times_xue;
    QLabel *times_pu;
}MTopFiveArg;

class MTopFive;
typedef void (MTopFive::*exe_topFive)(QNetworkReply *);

class MTopFive : public QWidget
{
    Q_OBJECT

public:
    explicit MTopFive(MTopFiveArg *arg);
    ~MTopFive();

private:
    Ui::MTopFive *ui;
    MTopFiveArg *arg;
    QMap<int,exe_topFive> _map;
private slots:
    void on_responsed(QNetworkReply *reply, int status);

public slots:
    void request_top_five();
    void clear();

private:
    void responsed_top_five(QNetworkReply *reply);
    void update_panel(QJsonObject data);
};

#endif // MTOPFIVE_H
