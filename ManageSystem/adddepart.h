#ifndef ADDDEPART_H
#define ADDDEPART_H

#include <QDialog>

namespace Ui {
class addDepart;
}

class addDepart : public QDialog
{
    Q_OBJECT

public:
    explicit addDepart(QWidget *parent = 0);
    ~addDepart();

private slots:
    void on_cancleBtn_clicked();

private:
    Ui::addDepart *ui;
};

#endif // ADDDEPART_H
