#include "user.h"
#include "ui_user.h"
#include"QDateTime"
#include <qtimer.h>

user::user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user)
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

user::~user()
{
    delete ui;
}

void user::tim_slot()//时间显示
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void user::on_infoBtn_clicked()
{
    s.show();
}

void user::on_salaBtn_clicked()
{
    s.show();
}

void user::on_clock_inBtn_clicked()
{
    sc.show();
}

void user::showAbout()
{
    ab.show();
}

void user::showHelp()
{
    h.show();
}

void user::showAlter()
{
    ap.show();
}

void user::showLogout()
{
    l.show();
}

void user::showSelf()
{
    sm.show();
}

void user::alterSelf()
{
    am.show();
}
