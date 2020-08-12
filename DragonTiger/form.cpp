#include "form.h"
#include "ui_form.h"

void Form::init(QString desk_id,QString boot,QString pave,QString result)
{
    ui->label_desk_id->setText(desk_id);
    ui->label_pave->setText(pave);
    ui->label_boot->setText(boot);
    ui->label_result->setText(result);
}

Form::Form(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

QPushButton* Form::button_cancel()
{
    return ui->pu_cancel;
}

QPushButton* Form::button_enter()
{
    return ui->pu_enter;
}
