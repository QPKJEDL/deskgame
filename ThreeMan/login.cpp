#include "login.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include "ui_login.h"

static QString URL = "101.32.22.231:8210";

//static QString URL = "129.211.114.135:8210";

Login::Login(QWidget *parent) : QWidget(parent) ,ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("登录");

    m_request = new QNetworkRequest;
    m_request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString url = "http://" + URL + "/dutch_login";
    m_request->setUrl(QUrl(url));

    m_accessManager = new QNetworkAccessManager(this);
    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));

    connect(ui->pu_enter,SIGNAL(clicked()),this,SLOT(on_login()));
    connect(ui->pu_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
}

void Login::on_login()
{
    QByteArray postData;
<<<<<<< HEAD
    QString str = "desk=SVIP8&password=7f2d0517446b496e";
=======
<<<<<<< HEAD
    QString str = "desk=SVIP8&password=123456";
=======
    QString str = "desk=svip8&password=123456";
>>>>>>> parent of 7a39d67... 0714
>>>>>>> parent of f632436... 这次提交是为了回滚到前0716版本的代码
    postData.append(str);
    m_accessManager->post(*m_request, postData);
}

void Login::on_cancel()
{
    this->close();
}

void Login::finishedSlot(QNetworkReply* reply)
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


            window = new MainWindow(desk_id,desk_token,limit,tieLimit);
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

