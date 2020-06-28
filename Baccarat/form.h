#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
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
