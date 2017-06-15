#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include "select.h"
#include "selectcheckin.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"
#include "selectme.h"
#include "alterme.h"

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

    void nowTime();

private slots:
   void on_infoBtn_clicked();

   void on_salaBtn_clicked();

   void on_clock_inBtn_clicked();

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

   void showSelf();

   void alterSelf();

private:
    Ui::user *ui;
    select s;
    selectCheckIn sc;
    about ab;
    help h;
    alterPassword ap;
    logout l;
    selectMe sm;
    alterMe am;
};

#endif // USER_H
