#ifndef NEWMNMBERDIALOG_H
#define NEWMNMBERDIALOG_H

#include <QDialog>

namespace Ui {
class NewMnmberDialog;
}

class NewMnmberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMnmberDialog(QWidget *parent = 0);
    ~NewMnmberDialog();

private slots:
    void on_InfoButton_2_clicked();

    void on_OKButton_clicked();

    void on_exitButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::NewMnmberDialog *ui;
};

#endif // NEWMNMBERDIALOG_H
