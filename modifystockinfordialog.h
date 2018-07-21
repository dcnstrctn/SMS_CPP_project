#ifndef MODIFYSTOCKINFORDIALOG_H
#define MODIFYSTOCKINFORDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyStockInforDialog;
}

class ModifyStockInforDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyStockInforDialog(QWidget *parent = 0);
    ~ModifyStockInforDialog();

private slots:
    void on_stockInfoButton_2_clicked();

    void on_exitButton_clicked();

    void on_deleteButton_clicked();

    void on_modifyButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::ModifyStockInforDialog *ui;
};

#endif // MODIFYSTOCKINFORDIALOG_H
