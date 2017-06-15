#include "adddepart.h"
#include "ui_adddepart.h"

addDepart::addDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDepart)
{
    ui->setupUi(this);
}

addDepart::~addDepart()
{
    delete ui;
}

void addDepart::on_cancleBtn_clicked()
{
    accept();
}
