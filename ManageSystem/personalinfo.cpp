#include "personalinfo.h"
#include "ui_personalinfo.h"
#include "QDateTime"
#include <qtimer.h>

personalInfo::personalInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::personalInfo)
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

personalInfo::~personalInfo()
{
    delete ui;
}

void personalInfo::tim_slot()//时间显示
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void personalInfo::on_selectInfoBtn_clicked()
{
    s.show();
}

void personalInfo::on_alterInfoBtn_clicked()
{
    al.show();
}

void personalInfo::on_addInfoBtn_clicked()
{
    a.show();
}

void personalInfo::on_deleteInfoBtn_clicked()
{
    d.show();
}

void personalInfo::showAbout()
{
    ab.show();
}

void personalInfo::showHelp()
{
    h.show();
}

void personalInfo::showAlter()
{
    ap.show();
}

void personalInfo::showLogout()
{
    l.show();
}

void personalInfo::showSelf()
{
    sm.showInfo();
    sm.show();
}

void personalInfo::alterSelf()
{
    am.showInfo();
    am.show();
}
