#ifndef ALTER_H
#define ALTER_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class alter;
}

class alter : public QDialog
{
    Q_OBJECT

public:
    explicit alter(QWidget *parent = 0);
    ~alter();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::alter *ui;
    QSqlTableModel *model;
};

#endif // ALTER_H
