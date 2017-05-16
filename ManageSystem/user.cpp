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
