#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include"supervip.h"
#include"discountaccount.h"

namespace Ui {
class checkOutDialog;
}

class checkOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit checkOutDialog(QWidget *parent = 0);
    ~checkOutDialog();

public:
    void sendVip(Vip);
    void sendSvip(SuperVip);
    void sendCustomer(Vip);


private slots:
    void on_addItemButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Account *accountPtr;
    Ui::checkOutDialog *ui;
};

#endif // CHECKOUTDIALOG_H
