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

private:
    Ui::QQChat *ui;
};

#endif // QQCHAT_H
