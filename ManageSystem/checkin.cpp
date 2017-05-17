#include "checkin.h"
#include "ui_checkin.h"
#include "QDateTime"
#include <qtimer.h>

checkIn::checkIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::checkIn)
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
}

checkIn::~checkIn()
{
    delete ui;
}

void checkIn::tim_slot()//时间显示
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void checkIn::on_selectCheckInBtn_clicked()
{
    s.show();
}

void checkIn::on_alterCheckInBtn_clicked()
{
    a.show();
}

void checkIn::showAbout()
{
    ab.show();
}

void checkIn::showHelp()
{
    h.show();
}

void checkIn::showAlter()
{
    ap.show();
}

void checkIn::showLogout()
{
    l.show();
}
