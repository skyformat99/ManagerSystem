#include "altercheckin.h"
#include "ui_altercheckin.h"

alterCheckIn::alterCheckIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterCheckIn)
{
    ui->setupUi(this);
    //获取当前日期，使QDateEdit框里显示的初始日期为当前日期
    QDate date = (new QDate)->currentDate();
    ui->dateEdit->setDate(date);
    //使QDateEdit显示方式为点击三角出来日历形式的时间选择
    ui->dateEdit->setCalendarPopup(true);
}

alterCheckIn::~alterCheckIn()
{
    delete ui;
}

void alterCheckIn::on_cancelBtn_clicked()
{
    accept();
}
