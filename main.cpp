#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QApplication::setApplicationDisplayName(MainWindow::tr("Score Calculator"));
    MainWindow w;
    w.show();

    return a.exec();
}
