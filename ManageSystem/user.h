#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include "select.h"
#include "selectcheckin.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"

namespace Ui {
class user;
}

class user : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit user(QWidget *parent = 0);
    ~user();

private slots:
   void on_infoBtn_clicked();

   void on_salaBtn_clicked();

   void on_clock_inBtn_clicked();

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

private:
    Ui::user *ui;
    select s;
    selectCheckIn sc;
    about ab;
    help h;
    alterPassword ap;
    logout l;
};

#endif // USER_H
