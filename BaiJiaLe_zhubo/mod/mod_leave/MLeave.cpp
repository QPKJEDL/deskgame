#include "mod/mod_leave/MLeave.h"

MLeave::MLeave(QPushButton *button, QWidget *widget, QObject *parent) : QObject(parent)
{
    this->button = button;
    this->widget = widget;

    connect(this->button,SLOT(clicked()),this,SLOT(pu_button()));
}

void MLeave::pu_button()
{
    widget->close();
}
