#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"
#include "user.h"
#include "enroll.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_CommRaBt_clicked();

    void on_ManaRaBt_clicked();

    void on_loginBtn_clicked();

    void on_exitBtm_clicked();

private:
    Ui::MainWindow *ui;
    manager m;
    user u;
    enroll e;
    QSqlTableModel *model;
    QSqlTableModel *model1;
};

#endif // MAINWINDOW_H
