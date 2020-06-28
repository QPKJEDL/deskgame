#include "login.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "ui_login.h"

//static QString URL = "129.211.114.135:8210";

enum {FIRST};

Login::Login(QWidget *parent) : QWidget(parent),ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    this->show();
}

Login::~Login()
{

}

QString Login::get_live_user()
{
    return ui->userid->text();
}

QString Login::get_password()
{
    return ui->passwd->text();
}

QPushButton *Login::get_login_Button()
{
    return ui->enter;
}

void Login::on_cancel()
{
    this->close();
}
