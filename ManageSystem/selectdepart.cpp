#include "selectdepart.h"
#include "ui_selectdepart.h"

selectDepart::selectDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDepart)
{
    ui->setupUi(this);
}

selectDepart::~selectDepart()
{
    delete ui;
}
