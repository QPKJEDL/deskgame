#include "mainwindow.h"
#include "login.h"
#include "bannerwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.showFullScreen();
    return a.exec();
}
