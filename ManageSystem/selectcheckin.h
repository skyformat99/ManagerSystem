#ifndef SELECTCHECKIN_H
#define SELECTCHECKIN_H

#include <QDialog>

namespace Ui {
class selectCheckIn;
}

class selectCheckIn : public QDialog
{
    Q_OBJECT

public:
    explicit selectCheckIn(QWidget *parent = 0);
    ~selectCheckIn();

private:
    Ui::selectCheckIn *ui;
};

#endif // SELECTCHECKIN_H
