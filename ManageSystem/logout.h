#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

namespace Ui {
class logout;
}

class logout : public QDialog
{
    Q_OBJECT

public:
    explicit logout(QWidget *parent = 0);
    ~logout();

private slots:
    void on_cancleBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::logout *ui;
};

#endif // LOGOUT_H
