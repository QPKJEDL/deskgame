#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

namespace Ui {
class Login;
}
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

#endif // LOGINWINDOW_H
