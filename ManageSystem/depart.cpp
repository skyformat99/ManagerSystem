﻿#include "depart.h"
#include "ui_depart.h"
#include "QDateTime"
#include <qtimer.h>

depart::depart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::depart)
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

depart::~depart()
{
    delete ui;
}

void depart::nowTime()
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void depart::tim_slot()//时间显示
{
    ui->nowTimeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void depart::on_selectDepartBtn_clicked()
{
    s.show();
}

void depart::on_alterDepartBtn_clicked()
{
    al.show();
}

void depart::on_addDepartBtn_clicked()
{
    a.show();
}

void depart::on_deleteDepartBtn_clicked()
{
    d.show();
}

void depart::showAbout()
{
    ab.show();
}

void depart::showHelp()
{
    h.show();
}

void depart::showAlter()
{
    ap.show();
}

void depart::showLogout()
{
    l.show();
}

void depart::showSelf()
{
    sm.showInfo();
    sm.show();
}

void depart::alterSelf()
{
    am.showInfo();
    am.show();
}
