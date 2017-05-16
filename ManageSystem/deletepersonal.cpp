#include "deletepersonal.h"
#include "ui_deletepersonal.h"

deletePersonal::deletePersonal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletePersonal)
{
    ui->setupUi(this);
}

deletePersonal::~deletePersonal()
{
    delete ui;
}

void deletePersonal::on_cancelBtn_clicked()
{
    accept();
}
