#ifndef QQCHAT_H
#define QQCHAT_H

#include <QWidget>

namespace Ui {
class QQChat;
}

class QQChat : public QWidget
{
    Q_OBJECT

public:
    explicit QQChat(QWidget *parent = nullptr);
    ~QQChat();

    void update_input(QString str);

    void update_name(QString str);

signals:

    void banUser(int);

private slots:

    void pu_name();

private:
    Ui::QQChat *ui;
public:
    int talkid;
};

#endif // QQCHAT_H
