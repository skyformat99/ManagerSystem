#ifndef CHECKIN_H
#define CHECKIN_H

#include <QMainWindow>
#include "selectcheckin.h"
#include "altercheckin.h"

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

private slots:
   void on_selectCheckInBtn_clicked();

   void on_alterCheckInBtn_clicked();

private:
    Ui::checkIn *ui;
    selectCheckIn s;
    alterCheckIn a;
};

#endif // CHECKIN_H
