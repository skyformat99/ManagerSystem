#include "deletedepart.h"
#include "ui_deletedepart.h"

deleteDepart::deleteDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDepart)
{
    ui->setupUi(this);
}

deleteDepart::~deleteDepart()
{
    delete ui;
}

void deleteDepart::on_cancelBtn_clicked()
{
    accept();
}
