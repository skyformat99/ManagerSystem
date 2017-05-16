#ifndef ADD_H
#define ADD_H

#include <QDialog>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    ~add();

private slots:
    void on_cancleBtn_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
