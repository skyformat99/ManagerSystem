#include "alterpassword.h"
#include "ui_alterpassword.h"
#include <QDebug>

alterPassword::alterPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterPassword)
{
    ui->setupUi(this);
    //创建model实现与数据库交互
    model = new QSqlTableModel(this);
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->newLineEdit->setEchoMode(QLineEdit::Password);
    ui->affirmLineEdit->setEchoMode(QLineEdit::Password);
    ui->newLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入新密码"));
    ui->affirmLineEdit->setPlaceholderText(QString::fromLocal8Bit("请重复输入密码"));
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
    if(ui->newLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请输入要修改的密码"),QMessageBox::Yes);
        return;
    }

    if(ui->newLineEdit->text() != ui->affirmLineEdit->text())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("两次输入的密码不一致"),QMessageBox::Yes);
        return;
    }

    model->select();
    int i;
    for(i=0;i<model->rowCount();i++)
    {
        if((model->data(model->index(i,0)) == jobNum) || (model->data(model->index(i, 1)) == nameStr))
        {
            break;
        }
    }
    //能登录成功，则说明用户存在于数据库表项中，所以不用判断i是否小于model->rowCount()
    model->setData(model->index(i, 2), ui->newLineEdit->text());
    if(model->submitAll())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("密码修改成功"),QMessageBox::Yes);
    }
}
