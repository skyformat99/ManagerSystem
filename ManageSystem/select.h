#ifndef SELECT_H
#define SELECT_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>

namespace Ui {
class select;
}

class select : public QDialog
{
    Q_OBJECT

public:
    explicit select(QWidget *parent = 0);

    ~select();

     void closeEvent(QCloseEvent* event);

private slots:
    void on_selectBtn_clicked();

private:
    Ui::select *ui;
    QSqlTableModel *model;
};

#endif // SELECT_H
