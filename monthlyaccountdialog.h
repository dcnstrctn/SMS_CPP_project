#ifndef MONTHLYACCOUNTDIALOG_H
#define MONTHLYACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class monthlyAccountDialog;
}

class monthlyAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit monthlyAccountDialog(QWidget *parent = 0);
    ~monthlyAccountDialog();
private slots:
    void on_searchButt_clicked();
    void on_exitButt_clicked();
private:
    Ui::monthlyAccountDialog *ui;
};

#endif // MONTHLYACCOUNTDIALOG_H
