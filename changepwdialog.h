#ifndef CHANGEPWDIALOG_H
#define CHANGEPWDIALOG_H

#include <QDialog>
#include<fstream>
#include"global.h"
namespace Ui {
class ChangePwDialog;
}

class ChangePwDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwDialog(QWidget *parent = 0);
    ~ChangePwDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::ChangePwDialog *ui;
};

#endif // CHANGEPWDIALOG_H
