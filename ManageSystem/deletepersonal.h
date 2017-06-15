#ifndef DELETEPERSONAL_H
#define DELETEPERSONAL_H

#include <QDialog>

namespace Ui {
class deletePersonal;
}

class deletePersonal : public QDialog
{
    Q_OBJECT

public:
    explicit deletePersonal(QWidget *parent = 0);
    ~deletePersonal();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::deletePersonal *ui;
};

#endif // DELETEPERSONAL_H
