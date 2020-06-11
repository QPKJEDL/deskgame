#include "loginwindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>

static QString URL = "129.211.114.135:8210";
//static QString URL = "192.168.0.111:8210";

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent),
    m_label_user(this),
    m_edit_user(this),
    m_label_pwd(this),
    m_edit_pwd(this),
    m_button_login(this),
    m_button_cancel(this)
{
    m_label_user.setText(QString("用户名"));
    m_label_user.move(20, 30);
    m_label_user.resize(60, 25);

    m_edit_user.move(85, 30);
    m_edit_user.resize(120,25);

    m_label_pwd.setText(QString("密码"));
    m_label_pwd.move(20, 65);
    m_label_pwd.resize(60, 25);

    m_edit_pwd.move(85, 65);
    m_edit_pwd.resize(120,25);

    m_button_login.setText(QString("登录"));
    m_button_login.move(180, 110);
    m_button_login.resize(85, 30);

    m_button_cancel.setText(QString("取消"));
    m_button_cancel.move(85, 110);
    m_button_cancel.resize(85, 30);

    setWindowTitle("登录");

    m_request = new QNetworkRequest;
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString url = "http://" + URL + "/dutch_login";
    m_request->setUrl(QUrl(url));

    m_accessManager = new QNetworkAccessManager(this);
    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));

    connect(&m_button_login,SIGNAL(clicked()),this,SLOT(on_login()));
    connect(&m_button_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
}

void LoginWindow::on_login()
{
    QByteArray postData;
    //postData.append("desk=A2&password=123456");
    QString str = "desk=" + m_edit_user.text() + "&password=" + m_edit_pwd.text();
    qDebug() << str;
    postData.append(str);
    m_accessManager->post(*m_request, postData);
}

void LoginWindow::on_cancel()
{
    this->close();
}

void LoginWindow::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError){
        QByteArray bytes = reply->readAll();
        QJsonObject json_object = QJsonDocument::fromJson(bytes).object();


        unsigned int    status = json_object.value("status").toInt();
        if(status == 1){
            // 登录成功
            this->close();
            QJsonObject json_object2 = json_object.value("data").toObject();
            qDebug() << json_object2;
            // 获取 id 和 token
            int desk_id = json_object2.value("desk_id").toInt();
            qDebug() << desk_id;
            QString desk_token = json_object2.value("desk_token").toString();
            qDebug() << desk_token;
            // 获取平倍和翻倍限红
            // 刷新限红
            int maxLimit = json_object2.value("maxLimit").toInt();
            qDebug() << maxLimit;
            int minLimit = json_object2.value("minLimit").toInt();
            qDebug() << minLimit;
            int tieMaxLimit = json_object2.value("tieMaxLimit").toInt();
            qDebug() << tieMaxLimit;
            int tieMinLimit = json_object2.value("tieMinLimit").toInt();
            qDebug() << tieMinLimit;
            // 靴次和铺次


            QString limit = QString::number(minLimit) + "-" + QString::number(maxLimit);
            QString tieLimit = QString::number(tieMinLimit) + "-" + QString::number(tieMaxLimit);


            window = new MainWindow(desk_id,desk_token,limit,tieLimit);
            window->show();
        }
        else{
            QMessageBox box;
            box.setText("账号或密码错误");
            box.exec();
        }
    }
    else{
        qDebug() << "finishedSlot errors here";
        qDebug( "found error .... code: %d\n", (int)reply->error());
        qDebug() << reply->errorString();

        QMessageBox box;
        box.setText("网络连接错误");
        box.exec();
    }
    reply->deleteLater();
}
