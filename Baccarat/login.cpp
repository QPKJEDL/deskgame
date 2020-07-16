#include "login.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "ui_login.h"

//static QString URL = "101.32.22.231:8210";

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    this->show();
}

Login::~Login()
{
    delete ui;
}

QPushButton *Login::get_login_Button()
{
    return ui->pu_enter;
}

void Login::on_cancel()
{
    this->close();
}
