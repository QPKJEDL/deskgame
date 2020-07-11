#ifndef LIVE_H
#define LIVE_H

#include <QWidget>
#include <QJsonObject>
#include <QPushButton>

namespace Ui {
class Live;
}

class Live : public QWidget
{
    Q_OBJECT
public:
    int lastid;
    int type = 1;

private:
    int first_id;
    int second_id;

public:
    explicit Live(QWidget *parent = nullptr);
    ~Live();

    void update_panel(QJsonArray data);

    QString get_time_begin();
    QString get_time_end();
private slots:
    void pu_today();
    void pu_yesterday();
    void pu_now_month();
    void pu_front_month();
    void pu_next_page();
    void pu_front_page();
    void pu_search();

signals:
    void request_money_list();

private:
    Ui::Live *ui;
};

#endif // LIVE_H
