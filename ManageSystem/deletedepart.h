#ifndef DELETEDEPART_H
#define DELETEDEPART_H

#include <QDialog>

namespace Ui {
class deleteDepart;
}

class deleteDepart : public QDialog
{
    Q_OBJECT

public:
    explicit deleteDepart(QWidget *parent = 0);
    ~deleteDepart();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::deleteDepart *ui;
};

#endif // DELETEDEPART_H
