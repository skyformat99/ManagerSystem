#ifndef CHECKIN_H
#define CHECKIN_H

#include <QMainWindow>
#include "selectcheckin.h"
#include "altercheckin.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"
#include "selectme.h"
#include "alterme.h"

namespace Ui {
class checkIn;
}

class checkIn : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit checkIn(QWidget *parent = 0);
    ~checkIn();

    void nowTime();

private slots:
   void on_selectCheckInBtn_clicked();

   void on_alterCheckInBtn_clicked();

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

   void showSelf();

   void alterSelf();

private:
    Ui::checkIn *ui;
    selectCheckIn s;
    alterCheckIn a;
    about ab;
    help h;
    alterPassword ap;
    logout l;
    selectMe sm;
    alterMe am;
};

#endif // CHECKIN_H
