#ifndef MDIALOG_H
#define MDIALOG_H

#include <QDialog>

namespace Ui {
class MDialog;
}

class MDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MDialog(QWidget *parent = nullptr);
    ~MDialog();

private:
    Ui::MDialog *ui;

public:
    void set_message(QString msg);

private slots:
    void on_yes();
    void on_no();
};

#endif // MDIALOG_H
