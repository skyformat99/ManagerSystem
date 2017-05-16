#ifndef SALARY_H
#define SALARY_H

#include <QMainWindow>
#include "select.h"
#include "alter.h"

namespace Ui {
class salary;
}

class salary : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit salary(QWidget *parent = 0);
    ~salary();

private slots:
   void on_selectSalaBtn_clicked();

   void on_alterSalaBtn_clicked();

private:
    Ui::salary *ui;
    select s;
    alter a;
};

#endif // SALARY_H
