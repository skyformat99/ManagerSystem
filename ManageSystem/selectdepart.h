#ifndef SELECTDEPART_H
#define SELECTDEPART_H

#include <QDialog>

namespace Ui {
class selectDepart;
}

class selectDepart : public QDialog
{
    Q_OBJECT

public:
    explicit selectDepart(QWidget *parent = 0);
    ~selectDepart();

private:
    Ui::selectDepart *ui;
};

#endif // SELECTDEPART_H
