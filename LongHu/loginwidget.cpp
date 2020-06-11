#include "loginwidget.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>

static QString URL = "129.211.114.135:8210";

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent),
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

void LoginWidget::on_login()
{
    QByteArray postData;
    QString str = "desk=" + m_edit_user.text() + "&password=" + m_edit_pwd.text();
    qDebug() << str;
    postData.append(str);
    m_accessManager->post(*m_request, postData);
}

void LoginWidget::on_cancel()
{
    this->close();
}

void LoginWidget::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError){
        QByteArray bytes = reply->readAll();
        QJsonObject json_object = QJsonDocument::fromJson(bytes).object();


        unsigned int    status = json_object.value("status").toInt();
        if(status == 1){
            // 登录成功
            QJsonObject json_object2 = json_object.value("data").toObject();
            qDebug() << QString(QJsonDocument(json_object2).toJson());
            unsigned int desk_id = json_object2.value("desk_id").toInt();
            QString desk_token = json_object2.value("desk_token").toString();
            //on_login();
            m_request->setRawHeader("desk_id",QString::number(desk_id).toUtf8());
            m_request->setRawHeader("desk_token",desk_token.toUtf8());
            qDebug() << "desk_id : " << QString::number(desk_id).toUtf8() << "--" << "desk_token" << desk_token;
            // 刷新限红
            unsigned int maxLimit = json_object2.value("maxLimit").toInt();
            unsigned int minLimit = json_object2.value("minLimit").toInt();
            unsigned int tieMaxLimit = json_object2.value("tieMaxLimit").toInt();
            unsigned int tieMinLimit = json_object2.value("tieMinLimit").toInt();
            QString limit = QString::number(minLimit) + "-" + QString::number(maxLimit);
            QString tieLimit = QString::number(tieMinLimit) + "-" + QString::number(tieMaxLimit);


            window = new MainWindow(desk_id,desk_token,maxLimit,minLimit,tieMaxLimit,tieMinLimit);
            window->show();
            this->close();
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

