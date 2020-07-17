#include "mod/mod_leave/MLeave.h"
#include <QDialog>
#include <mod/mod_dialog/MDialog.h>

MLeave::MLeave(QPushButton *button, QWidget *parent) : QObject(parent)
{
    this->button = button;
    this->widget = parent;

    connect(this->button,SIGNAL(clicked()),this,SLOT(pu_button()));
}

MLeave::~MLeave()
{

}

void MLeave::pu_button()
{
    MDialog *dlg = new MDialog(widget);
    dlg->set_message("是否离开?");
    dlg->setWindowFlag(Qt::FramelessWindowHint);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dlg->exec();
    if(ret == QDialog::Accepted){
        widget->close();
    }
}
