#ifndef DEPART_H
#define DEPART_H

#include <QMainWindow>
#include "selectdepart.h"
#include "alterdepart.h"
#include "adddepart.h"
#include "deletedepart.h"

namespace Ui {
class depart;
}

class depart : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit depart(QWidget *parent = 0);
    ~depart();

private slots:
   void on_selectDepartBtn_clicked();

   void on_alterDepartBtn_clicked();

   void on_addDepartBtn_clicked();

   void on_deleteDepartBtn_clicked();

private:
    Ui::depart *ui;
    selectDepart s;
    alterDepart al;
    addDepart a;
    deleteDepart d;
};

#endif // DEPART_H
