﻿#include "select.h"
#include "ui_select.h"
#include <QCloseEvent>

select::select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select)
{
    ui->setupUi(this);
    //创建model实现与数据库交互
    model = new QSqlTableModel(this);
    model->setTable("personinfo");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->selectLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入员工工号"));
}

select::~select()
{
    delete ui;
}

void select::on_selectBtn_clicked()
{
    if(ui->selectLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请输入员工工号"),QMessageBox::Yes);
        return;
    }

    model->select();
    int i;

    for(i=0;i<model->rowCount();i++)
    {
        if(model->data(model->index(i,0)) == ui->selectLineEdit->text().toInt())
        {
            break;
        }
    }

    if(i!=model->rowCount())
    {
        ui->jobNumLineEdit->setText(model->data(model->index(i,0)).toString());
        ui->nameLineEdit->setText(model->data(model->index(i,1)).toString());
        ui->connLineEdit->setText(model->data(model->index(i,2)).toString());
        ui->posiLineEdit->setText(model->data(model->index(i,3)).toString());
        ui->departLineEdit->setText(model->data(model->index(i,4)).toString());
        ui->salaLineEdit->setText(model->data(model->index(i,5)).toString());
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("该工号无对应的职工"),QMessageBox::Yes);
        ui->selectLineEdit->clear();
        return;
    }
}

//当点击右上角的红叉时清空查询记录
void select::closeEvent(QCloseEvent* event)
{
    ui->selectLineEdit->clear();
    ui->jobNumLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->connLineEdit->clear();
    ui->posiLineEdit->clear();
    ui->departLineEdit->clear();
    ui->salaLineEdit->clear();
}
