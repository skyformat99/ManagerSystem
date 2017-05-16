#include "mainwindow.h"
#include <QApplication>
#include "conn.h"

int main(int argc, char *argv[])
{
    connectiondatabes();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
