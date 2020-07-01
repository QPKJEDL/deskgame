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
    int first_id;
    int second_id;
    int type = 1;

public:
    explicit Live(QWidget *parent = nullptr);
    ~Live();

    void update_panel(QJsonArray data);
private slots:
    void pu_today();
    void pu_yesterday();
    void pu_now_month();
    void pu_front_month();

signals:
    void request_today();
    void request_yesterday();
    void request_now_month();
    void request_front_month();

private:
    Ui::Live *ui;
};

#endif // LIVE_H
