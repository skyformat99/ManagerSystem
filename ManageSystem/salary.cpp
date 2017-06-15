#include "salary.h"
#include "ui_salary.h"
#include "QDateTime"
#include <qtimer.h>

salary::salary(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::salary)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);//用于时间显示
    connect(timer, SIGNAL(timeout()), this, SLOT(tim_slot()));
    timer->start(1000);

    //为菜单栏的Action设置响应函数，可以将该Action的Triggered()信号与想要的槽函数相连。
    connect(ui->aboutAction, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->helpAction, SIGNAL(triggered()), this, SLOT(showHelp()));
    connect(ui->alterAction, SIGNAL(triggered()), this, SLOT(showAlter()));
    connect(ui->logoutAction, SIGNAL(triggered()), this, SLOT(showLogout()));

    connect(ui->selectAction, SIGNAL(triggered()), this, SLOT(showSelf()));
    connect(ui->alterAction_2, SIGNAL(triggered()), this, SLOT(alterSelf()));
}

salary::~salary()
{
    delete ui;
}

void salary::nowTime()
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void salary::tim_slot()//时间显示
{
    ui->nowTimeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void salary::on_selectSalaBtn_clicked()
{
    s.show();
}

void salary::on_alterSalaBtn_clicked()
{
    a.show();
}

void salary::showAbout()
{
    ab.show();
}

void salary::showHelp()
{
    h.show();
}

void salary::showAlter()
{
    ap.show();
}

void salary::showLogout()
{
    l.show();
}

void salary::showSelf()
{
    sm.showInfo();
    sm.show();
}

void salary::alterSelf()
{
    am.showInfo();
    am.show();
}
