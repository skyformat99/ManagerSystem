#ifndef ALTERPASSWORD_H
#define ALTERPASSWORD_H

#include <QDialog>

namespace Ui {
class alterPassword;
}

class alterPassword : public QDialog
{
    Q_OBJECT

public:
    explicit alterPassword(QWidget *parent = 0);
    ~alterPassword();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::alterPassword *ui;
};

#endif // ALTERPASSWORD_H
