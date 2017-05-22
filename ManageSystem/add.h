#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    ~add();

    void setJobNum();

    bool judgeEmpty();

    void clearAll();

private slots:
    void on_cancleBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::add *ui;
    QSqlTableModel *model;
    QSqlTableModel *model1;
};

#endif // ADD_H
