#include "login.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "ui_login.h"

static QString URL = "101.32.22.231:8210";

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    this->showFullScreen();
}

Login::~Login()
{
    delete ui;
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
    return ui->pu_enter;
}

void Login::on_cancel()
{
    this->close();
}
