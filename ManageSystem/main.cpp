#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);

    static int isManager = 1;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ManagerSystem");
    db.setUserName("root");
    db.setPassword("llll");
    if(db.open())
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("系统载入数据库失败，无法运行"),QMessageBox::Yes);
    }

    return 0;
}
