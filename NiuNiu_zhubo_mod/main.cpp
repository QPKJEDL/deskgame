#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    return a.exec();
}
