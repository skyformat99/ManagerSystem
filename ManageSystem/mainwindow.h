#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"
#include "user.h"
#include "enroll.h"

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
    void on_loginBtm_clicked();

    void on_registerBtm_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    manager m;
    user u;
    enroll e;
};

#endif // MAINWINDOW_H
