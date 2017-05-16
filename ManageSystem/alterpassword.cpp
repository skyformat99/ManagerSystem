#include "alterpassword.h"
#include "ui_alterpassword.h"

alterPassword::alterPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterPassword)
{
    ui->setupUi(this);
}

alterPassword::~alterPassword()
{
    delete ui;
}

void alterPassword::on_cancelBtn_clicked()
{
    accept();
}
