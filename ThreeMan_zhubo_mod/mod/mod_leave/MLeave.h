#ifndef MLEAVE_H
#define MLEAVE_H

#include <QObject>
#include <QPushButton>

class MLeave : public QObject
{
    Q_OBJECT
public:
    explicit MLeave(QPushButton *button,QWidget *parent = nullptr);
    ~MLeave();

private slots:
    void pu_button();

private:
    QPushButton *button;
    QWidget *widget;
};

#endif // MLEAVE_H
