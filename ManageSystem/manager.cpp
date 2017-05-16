#include "manager.h"
#include "ui_manager.h"
#include "QDateTime"
#include <qtimer.h>

manager::manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);//用于时间显示
    connect(timer, SIGNAL(timeout()), this, SLOT(tim_slot()));
    timer->start(1000);
}

manager::~manager()
{
    delete ui;
}

void manager::tim_slot()//时间显示
{
    //用lcdNumbe方式来显示时间
    //ui->lcdNumber->setDigitCount(28);
    //ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    //ui->lcdNumber->display((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
    ui->timeLabel->setText((new QDateTime)->currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void manager::on_infoBtn_clicked()
{
    p.show();
}

void manager::on_salaBtn_clicked()
{
    s.show();
}

void manager::on_clock_inBtn_clicked()
{
    c.show();
}

void manager::on_departBtn_clicked()
{
    d.show();
}
