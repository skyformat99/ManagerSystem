#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include "select.h"
#include "selectcheckin.h"

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

private:
    Ui::user *ui;
    select s;
    selectCheckIn sc;
};

#endif // USER_H
