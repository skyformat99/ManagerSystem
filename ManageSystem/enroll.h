#ifndef ENROLL_H
#define ENROLL_H

#include <QDialog>

namespace Ui {
class enroll;
}

class enroll : public QDialog
{
    Q_OBJECT

public:
    explicit enroll(QWidget *parent = 0);
    ~enroll();

private slots:
    void on_registerBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::enroll *ui;
};

#endif // ENROLL_H
