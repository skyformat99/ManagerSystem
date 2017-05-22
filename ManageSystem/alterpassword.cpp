#include "alterpassword.h"
#include "ui_alterpassword.h"

alterPassword::alterPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterPassword)
{
    ui->setupUi(this);
    //创建model实现与数据库交互
    model = new QSqlTableModel(this);
    model->setTable("personinfo");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->removeColumns(3, 3);
}

alterPassword::~alterPassword()
{
    delete ui;
}

void alterPassword::on_cancelBtn_clicked()
{
    accept();
}

void alterPassword::on_okBtn_clicked()
{

}
