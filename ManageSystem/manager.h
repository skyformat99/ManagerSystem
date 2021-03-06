﻿#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include "personalinfo.h"
#include "salary.h"
#include "checkin.h"
#include "depart.h"
#include "about.h"
#include "help.h"
#include "alterpassword.h"
#include "logout.h"
#include "selectme.h"
#include "alterme.h"

namespace Ui {
class manager;
}

class manager : public QMainWindow
{
    Q_OBJECT

public slots:
   void tim_slot();

public:
    explicit manager(QWidget *parent = 0);
    ~manager();

    void nowTime();

private slots:
   void on_infoBtn_clicked();

   void on_salaBtn_clicked();

   void on_clock_inBtn_clicked();

   void on_departBtn_clicked();

   void showAbout();

   void showHelp();

   void showAlter();

   void showLogout();

   void showSelf();

   void alterSelf();

private:
    Ui::manager *ui;
    personalInfo p;
    salary s;
    checkIn c;
    depart d;
    about ab;
    help h;
    alterPassword ap;
    logout l;
    selectMe sm;
    alterMe am;
};

#endif // MANAGER_H
