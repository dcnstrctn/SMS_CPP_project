#ifndef DAILYACCOUNTDIALOG_H
#define DAILYACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class dailyAccountDialog;
}

class dailyAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dailyAccountDialog(QWidget *parent = 0);
    ~dailyAccountDialog();
private slots:
    void on_searchButt_clicked();
    void on_exitButt_clicked();
private:
    Ui::dailyAccountDialog *ui;
};

#endif // DAILYACCOUNTDIALOG_H
