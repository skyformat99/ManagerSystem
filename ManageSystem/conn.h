#ifndef CONN_H
#define CONN_H

#include <QtSql/QSqlDatabase>
#include <QDebug>

bool connectiondatabes()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ManagerSystem");
    db.setUserName("root");
    db.setPassword("llll");
    if(db.open())
    {
        qDebug() << "database is established!";
    }
    else
    {
        qDebug() << "build error!";
        return false;
    }

    return true;
}

#endif // CONN_H

