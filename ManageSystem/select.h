#ifndef SELECT_H
#define SELECT_H

#include <QDialog>

namespace Ui {
class select;
}

class select : public QDialog
{
    Q_OBJECT

public:
    explicit select(QWidget *parent = 0);
    ~select();

private:
    Ui::select *ui;
};

#endif // SELECT_H
