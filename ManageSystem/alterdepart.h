#ifndef ALTERDEPART_H
#define ALTERDEPART_H

#include <QDialog>

namespace Ui {
class alterDepart;
}

class alterDepart : public QDialog
{
    Q_OBJECT

public:
    explicit alterDepart(QWidget *parent = 0);
    ~alterDepart();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::alterDepart *ui;
};

#endif // ALTERDEPART_H
