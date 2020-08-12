#ifndef MSTOP_H
#define MSTOP_H

#include <QObject>
#include "mod/MNetManager.h"

class MNetManager;


class MStop : public QObject
{
    Q_OBJECT
public:
    explicit MStop(QObject *parent = nullptr);

public  slots:
    void request_stop();
signals:

};

#endif // MSTOP_H
