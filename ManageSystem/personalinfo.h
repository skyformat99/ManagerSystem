#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <QMainWindow>
#include "select.h"
#include "alter.h"
#include "add.h"
#include "deletepersonal.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"
#include "selectme.h"
#include "alterme.h"

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

    void nowTime();

private slots:
   void on_selectInfoBtn_clicked();

   void on_alterInfoBtn_clicked();

   void on_addInfoBtn_clicked();

   void on_deleteInfoBtn_clicked();

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

   void showSelf();

   void alterSelf();

private:
    Ui::personalInfo *ui;
    select s;
    alter al;
    add a;
    deletePersonal d;
    about ab;
    help h;
    alterPassword ap;
    logout l;
    selectMe sm;
    alterMe am;
};

#endif // PERSONALINFO_H
