#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public:
    Ui::Login *ui;

    QString get_live_user();
    QString get_password();
    QPushButton* get_login_Button();

private slots:
    void on_cancel();
};

#endif // LOGIN_H
