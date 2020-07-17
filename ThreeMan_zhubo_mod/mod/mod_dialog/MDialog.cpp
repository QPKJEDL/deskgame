#include "MDialog.h"
#include "ui_MDialog.h"

MDialog::MDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MDialog)
{
    ui->setupUi(this);
    connect(ui->pu_yes,SIGNAL(clicked()),this,SLOT(on_yes()));
    connect(ui->pu_no,SIGNAL(clicked()),this,SLOT(on_no()));
}

MDialog::~MDialog()
{
    delete ui;
}

void MDialog::set_message(QString msg)
{
    ui->label->setText(msg);
}

void MDialog::on_yes()
{
    this->accept();
}

void MDialog::on_no()
{
    this->reject();
}
