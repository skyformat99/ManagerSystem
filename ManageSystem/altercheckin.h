#ifndef ALTERCHECKIN_H
#define ALTERCHECKIN_H

#include <QDialog>

namespace Ui {
class alterCheckIn;
}

class alterCheckIn : public QDialog
{
    Q_OBJECT

public:
    explicit alterCheckIn(QWidget *parent = 0);
    ~alterCheckIn();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::alterCheckIn *ui;
};

#endif // ALTERCHECKIN_H
