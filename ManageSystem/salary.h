#ifndef SALARY_H
#define SALARY_H

#include <QMainWindow>
#include "select.h"
#include "alter.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"

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

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

private:
    Ui::salary *ui;
    select s;
    alter a;
    about ab;
    help h;
    alterPassword ap;
    logout l;
};

#endif // SALARY_H
