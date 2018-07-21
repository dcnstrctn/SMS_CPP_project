#ifndef SEARCHACCOUNTDIALOG_H
#define SEARCHACCOUNTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
namespace Ui {
class searchAccountDialog;
}

class searchAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchAccountDialog(QWidget *parent = 0);
    ~searchAccountDialog();
private slots:
    void on_searchButt_clicked();
    void on_exitButt_clicked();
private:
    Ui::searchAccountDialog *ui;
};

#endif // SEARCHACCOUNTDIALOG_H
