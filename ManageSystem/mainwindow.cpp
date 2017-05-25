#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

//C++多个文件共享变量的方法：一个.cpp文件定义变量，使用一个.h文件加extern声明变量，其余想使用这些变量的文件包含该.h文件即可
int jobNum = 0;
QString nameStr = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置登录窗口的大小为固定值，不可改变
    QWidget::setFixedSize(396, 253);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->loginBtn->setEnabled(false);

    //创建model实现与数据库交互
    model = new QSqlTableModel(this);
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //在 Qt 中，默认的编码是 Unicode，我们书写的代码文件被强制转换为 utf8，但是，在简体中文版的 Windows 操作系统中，默认编码却是 GBK。
    //若想字符得以正常显示，则可以使用 QString::fromLocal8Bit 来将本地字符编码转换为 Unicode 形式的 QString。
    ui->loginLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入员工工号/姓名"));
    ui->passwordLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CommRaBt_clicked()
{
    ui->loginBtn->setEnabled(true);
}

void MainWindow::on_ManaRaBt_clicked()
{
    ui->loginBtn->setEnabled(true);
}

void MainWindow::on_loginBtn_clicked()
{
    model->select();
    int i;
    for(i=0;i<model->rowCount();i++)
    {
        //员工工号和姓名都可作为登陆名
        if((model->data(model->index(i,0)) == ui->loginLineEdit->text().toInt()) || (model->data(model->index(i,1)).toString()==ui->loginLineEdit->text()))
        {
            if(model->data(model->index(i,0)) == ui->loginLineEdit->text().toInt())
                jobNum = ui->loginLineEdit->text().toInt();
            else
                nameStr = ui->loginLineEdit->text();
            break;
        }
    }

    if(i!=model->rowCount())
    {
        if(ui->ManaRaBt->isChecked())
        {
            if(model->data(model->index(i,3)).toInt() == 1)
            {
                if(model->data(model->index(i,2)).toString() == ui->passwordLineEdit->text())
                {
                    this->hide();
                    m.show();
                }
                else
                {
                    QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("密码输入错误"),QMessageBox::Yes);
                }
            }
            else
            {
                QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("该用户不是管理员"),QMessageBox::Yes);
            }
        }
        else
        {
            if(model->data(model->index(i,2)).toString() == ui->passwordLineEdit->text())
            {
                //因为管理员和普通用户都可作为普通用户登陆，因此此处不加是否选中的用户类型符合的判断
                this->hide();
                u.show();
            }
            else
            {
                QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("密码输入错误"),QMessageBox::Yes);
            }
        }
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("用户不存在"),QMessageBox::Yes);
        return;
    }
}

void MainWindow::on_exitBtm_clicked()
{
    QApplication::exit();
}
