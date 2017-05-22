#include "add.h"
#include "ui_add.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QString>
#include <QDebug>

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    //创建model实现与数据库交互
    model = new QSqlTableModel(this);
    model->setTable("personinfo");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model1 = new QSqlTableModel(this);
    model1->setTable("user");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //先设置员工工号，让员工工号实现自动生成
    //setJobNum();
    //设置lineEdit提示字段
    ui->nameLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入职工姓名"));
    ui->jobNumLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入职工工号"));
    ui->connLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入联系方式"));
    ui->posiLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入员工职位"));
    ui->departLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入员工所在部门"));
    ui->salaLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入员工薪资"));
}

add::~add()
{
    delete ui;
}

void add::on_cancleBtn_clicked()
{
    accept();
}

void add::clearAll()
{
    //QString::number() 将int转换为QString类型，括号里填int型数据
    //int num = ui->jobNumLineEdit->text().toInt() + 1;
    //ui->jobNumLineEdit->setText(QString::number(num));
    ui->jobNumLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->connLineEdit->clear();
    ui->posiLineEdit->clear();
    ui->departLineEdit->clear();
    ui->salaLineEdit->clear();
}

void add::setJobNum()
{
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    QString str = (new QDate)->currentDate().toString("yyyy");
    int num = str.toInt();

    if(rowNum == 0)
    {
        model->setData(model->index(rowNum,0),1);
    }
    else
    {
        ;  //设置为自动增长，不用自己设置
    }

    int n = model->data(model->index(rowNum, 0)).toInt();
    num = num * 10000 + n % 10000;
    model->setData(model->index(rowNum,0),num);

    str = model->data(model->index(rowNum, 0)).toString();
    ui->jobNumLineEdit->setPlaceholderText(str);
}

bool add::judgeEmpty()
{
    if(ui->jobNumLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工工号不能为空"),QMessageBox::Yes);
        return false;
    }
    if(ui->nameLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工姓名不能为空"),QMessageBox::Yes);
        return false;
    }
    else if(ui->connLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工联系方式不能为空"),QMessageBox::Yes);
        return false;
    }
    else if(ui->posiLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工职位不能为空"),QMessageBox::Yes);
        return false;
    }
    else if(ui->departLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工部门不能为空"),QMessageBox::Yes);
        return false;
    }
    else if(ui->salaLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("职工薪资不能为空"),QMessageBox::Yes);
        return false;
    }
    else
        return true;
}

void add::on_okBtn_clicked()
{
    if(!this->judgeEmpty())
        return;
    model->select();
    int i;
    for(i=0;i<model->rowCount();i++)
    {
        if(model->data(model->index(i,0)) == ui->jobNumLineEdit->text().toInt())
        {
            break;
        }
    }
    if(i!=model->rowCount())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("职工工号已经存在"),QMessageBox::Yes);
        this->clearAll();
        return;
    }

    int rowNum = model->rowCount(); //获得表的行数
    //因为前面setJobNum已经进行了添加，所以这儿不用添加
    model->insertRow(rowNum); //添加一行

    //设置添加的对应信息
    model->setData(model->index(rowNum,0),ui->jobNumLineEdit->text().toInt());
    model->setData(model->index(rowNum,1),ui->nameLineEdit->text());
    model->setData(model->index(rowNum,2),ui->connLineEdit->text());
    model->setData(model->index(rowNum,3),ui->posiLineEdit->text());
    model->setData(model->index(rowNum,4),ui->departLineEdit->text());
    model->setData(model->index(rowNum,5),ui->salaLineEdit->text().toInt());

    //submitAll()->提交对表的修改
    if(model->submitAll())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("职工信息添加成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("职工信息添加失败"),QMessageBox::Yes);
        return;
    }


    int rowNum1 = model1->rowCount(); //获得表的行数
    model1->insertRow(rowNum1); //添加一行
    model1->setData(model1->index(rowNum1,0),ui->jobNumLineEdit->text().toInt());
    model1->setData(model1->index(rowNum1,1),ui->nameLineEdit->text());
    model1->setData(model1->index(rowNum1,2),"123456");

    if(ui->managerRB->isChecked())
    {
         model1->setData(model1->index(rowNum1,3),1);
    }
    else
    {
         model1->setData(model1->index(rowNum1,3),0);
    }
    model1->submitAll();   //只有提交了修改，添加才生效

    //只有等user也添加了信息才能清空输入框，不然清空了后user表添加不了信息
    this->clearAll();
}
