#ifndef SETDISCOUNTDIALOG_H
#define SETDISCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class setDiscountDialog;
}

class setDiscountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setDiscountDialog(QWidget *parent = 0);
    ~setDiscountDialog();
private slots:
    void on_okButt_clicked();
    void on_pushButton_clicked();

private:
    Ui::setDiscountDialog *ui;
};

#endif // SETDISCOUNTDIALOG_H
