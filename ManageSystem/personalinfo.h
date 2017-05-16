#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <QMainWindow>
#include "select.h"
#include "alter.h"
#include "add.h"
#include "deletepersonal.h"

namespace Ui {
class personalInfo;
}

class personalInfo : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit personalInfo(QWidget *parent = 0);
    ~personalInfo();

private slots:
   void on_selectInfoBtn_clicked();

   void on_alterInfoBtn_clicked();

   void on_addInfoBtn_clicked();

   void on_deleteInfoBtn_clicked();

private:
    Ui::personalInfo *ui;
    select s;
    alter al;
    add a;
    deletePersonal d;
};

#endif // PERSONALINFO_H
