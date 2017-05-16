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
