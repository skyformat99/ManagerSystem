#include "depart.h"
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
}

depart::~depart()
{
    delete ui;
}

void depart::tim_slot()//时间显示
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
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