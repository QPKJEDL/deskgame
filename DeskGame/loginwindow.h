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

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

private:
    QLabel m_label_user;
    QLabel m_label_pwd;
    QLineEdit m_edit_user;
    QLineEdit m_edit_pwd;
    QPushButton m_button_login;
    QPushButton m_button_cancel;
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
