#include "alter.h"
#include "ui_alter.h"

alter::alter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alter)
{
    ui->setupUi(this);
}

alter::~alter()
{
    delete ui;
}

void alter::on_cancelBtn_clicked()
{
    accept();
}
