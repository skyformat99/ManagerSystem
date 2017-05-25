#ifndef ALTERPASSWORD_H
#define ALTERPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>

extern int jobNum;
extern QString nameStr;

namespace Ui {
class alterPassword;
}

class alterPassword : public QDialog
{
    Q_OBJECT

public:
    explicit alterPassword(QWidget *parent = 0);
    ~alterPassword();

private slots:
    void on_cancelBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::alterPassword *ui;
    QSqlTableModel *model;
};

#endif // ALTERPASSWORD_H
