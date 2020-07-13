#ifndef MREWORD_H
#define MREWORD_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class MReword;
}

class MReword : public QWidget
{
    Q_OBJECT

public:
    explicit MReword(QWidget *parent = nullptr);
    ~MReword();

private:
    Ui::MReword *ui;

public slots:
    void show_reword(QString user,int money);

private slots:
    void timer_close();

private:
    QTimer *timer;
};

#endif // MREWORD_H
