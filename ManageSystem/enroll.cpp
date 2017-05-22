#include "enroll.h"
#include "ui_enroll.h"
#include <QMessageBox>

enroll::enroll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll)
{
    ui->setupUi(this);
}

enroll::~enroll()
{
    delete ui;
}

void enroll::on_registerBtn_clicked()
{
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("注册成功"), QMessageBox::Yes);
}
void enroll::on_cancleBtn_clicked()
{
    accept();
}
