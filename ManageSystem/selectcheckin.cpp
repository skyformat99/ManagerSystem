#include "selectcheckin.h"
#include "ui_selectcheckin.h"

selectCheckIn::selectCheckIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectCheckIn)
{
    ui->setupUi(this);
    //获取当前日期，使QDateEdit框里显示的初始日期为当前日期
    QDate date = (new QDate)->currentDate();
    ui->dateEdit->setDate(date);
    //使QDateEdit显示方式为点击三角出来日历形式的时间选择
    ui->dateEdit->setCalendarPopup(true);

    ui->selectLineText->setPlaceholderText(QString::fromLocal8Bit("请输入员工工号"));
}

selectCheckIn::~selectCheckIn()
{
    delete ui;
}
