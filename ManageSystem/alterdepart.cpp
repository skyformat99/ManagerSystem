#include "alterdepart.h"
#include "ui_alterdepart.h"

alterDepart::alterDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterDepart)
{
    ui->setupUi(this);
}

alterDepart::~alterDepart()
{
    delete ui;
}

void alterDepart::on_cancelBtn_clicked()
{
    accept();
}
