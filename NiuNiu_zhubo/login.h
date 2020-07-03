#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include "mainwindow.h"

namespace Ui {
class Login;
}
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

private:
    Ui::Login *ui;
    MainWindow *window;
    // login 请求
    QNetworkRequest* m_request;
    QNetworkAccessManager* m_accessManager;

private slots:
    void on_login();
    void on_cancel();
    void finishedSlot(QNetworkReply *reply);
};

#endif // LOGINWINDOW_H
