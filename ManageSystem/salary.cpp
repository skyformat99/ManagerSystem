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
}

salary::~salary()
{
    delete ui;
}

void salary::tim_slot()//时间显示
{
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void salary::on_selectSalaBtn_clicked()
{
    s.show();
}

void salary::on_alterSalaBtn_clicked()
{
    a.show();
}
