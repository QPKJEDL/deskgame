#include "mod/mod_record/MRecord.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>

MRecord::MRecord(MRecordArg *arg, QObject *parent) : QObject(parent)
{
    this->arg = new MRecordArg();
    this->arg->boot = arg->boot;
    this->arg->grid = arg->grid;
    this->arg->status = arg->status;
    this->arg->manager = arg->manager;
    this->arg->interface = arg->interface;

    link = new Record_link();
    Record_link *node = new Record_link();
    link = node;
    head = node;

    for(int i = 0;i < 20;i++){
        for(int j = 0;j < 6;j++){
            QLabel* label = new QLabel();
            label->setStyleSheet("background-color: rgb(255, 255, 255);");
            arg->grid->addWidget(label,j,i);

            node->data = label;
            if(i == 19 && j == 5){
                node->next = nullptr;
            }
            else{
                node->next = new Record_link;
                node = node->next;
            }
        }
    }


    _map.insert(arg->status,&MRecord::responsed_record);
    connect(arg->manager,SIGNAL(responsed(QNetworkReply*,int)),this,SLOT(on_responsed(QNetworkReply*,int)));
}

void MRecord::request_record()
{
    arg->manager->setStatus(arg->status);
    arg->manager->setInterface(arg->interface);
    QByteArray postData;
    postData.append("boot_num=" + arg->boot->text());
    arg->manager->postData(postData);
}

void MRecord::apply_record(QString game)
{
    append(game);

}

void MRecord::on_useless()
{

    append("");
}

void MRecord::append(QString game)
{
    QString path = QString(":/result/");
    if(game == "龙"){
        path.append("long");
    }
    else if(game == "虎"){
        path.append("tiger");
    }
    else if(game == "和"){
        path.append("same");
    }
    else if(game == ""){
        path.append("useless");
    }

    path.append(".png");
    QString style = "border-image: url(" + path + ");";
    link->data->setStyleSheet(link->data->styleSheet().append(style));
    increase();
}

void MRecord::on_responsed(QNetworkReply *reply, int status)
{
    if(_map.find(status) != _map.end()){
        (this->*(_map[status]))(reply);
    }
    else{
        qDebug() << "unknow status";
    }
}

void MRecord::responsed_record(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QJsonObject json = QJsonDocument::fromJson(bytes).object();
    unsigned int status = json.value("status").toInt();
    if(status == 1){
        QJsonArray data = json.value("data").toArray();
        QJsonArray array = data.at(0)["list"].toArray();
        update_panel(array);
    }
    else{
        QMessageBox box;
        box.setText("获取历史记录失败");
        box.exec();
    }
}

void MRecord::update_panel(QJsonArray array)
{
    link = head;
    while(link->next != nullptr){
        link->data->setText("");
        link->data->setStyleSheet("background-color: rgb(255, 255, 255);");
        link = link->next;
    }
    link = head;

    for(int i = 0;i < array.count();i++){
        QString game = array.at(i)["winner"].toString();

        append(game);
    }
}

void MRecord::increase()
{
    if(link->next == nullptr){

        for(Record_link *node = head;node->next != nullptr;node = node->next){
            node->data->setStyleSheet(node->next->data->styleSheet());
            node->data->setText(node->next->data->text());
        }
    }
    else{
        link = link->next;
    }
}
