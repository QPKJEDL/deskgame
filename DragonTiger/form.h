#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    Form(QDialog *parent = nullptr);
    void init(QString desk_id, QString boot, QString pave, QString result);
    ~Form();

public :
    Ui::Form *ui;
signals:
    void enter();
    void cancel();
public:
    QPushButton* button_enter();
    QPushButton* button_cancel();
};

#endif // FORM_H
