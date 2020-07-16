#include "login.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "ui_login.h"

Login::Login(QWidget *parent) : QWidget(parent),ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    this->show();
}

Login::~Login()
{

}

QPushButton *Login::get_login_Button()
{
    return ui->enter;
}

void Login::on_cancel()
{
    this->close();
}
