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

    //为菜单栏的Action设置响应函数，可以将该Action的Triggered()信号与想要的槽函数相连。
    connect(ui->aboutAction, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->helpAction, SIGNAL(triggered()), this, SLOT(showHelp()));
    connect(ui->alterAction, SIGNAL(triggered()), this, SLOT(showAlter()));
    connect(ui->logoutAction, SIGNAL(triggered()), this, SLOT(showLogout()));
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

void manager::showAbout()
{
    ab.show();
}

void manager::showHelp()
{
    h.show();
}

void manager::showAlter()
{
    ap.show();
}

void manager::showLogout()
{
    l.show();
}
