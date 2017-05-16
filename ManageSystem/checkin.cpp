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
