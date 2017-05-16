#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置登录窗口的大小为固定值，不可改变
    QWidget::setFixedSize(396, 253);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtm_clicked()
{
    if(ui->CommRaBt->isChecked())
    {
        this->hide();
        u.show();
    }
    if(ui->ManaRaBt->isChecked())
    {
        this->hide();
        m.show();
    }
}

void MainWindow::on_registerBtm_clicked()
{
    e.show();
}

void MainWindow::on_exitBtn_clicked()
{
    ;
}
