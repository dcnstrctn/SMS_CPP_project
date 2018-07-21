#ifndef GOODINDIALOG_H
#define GOODINDIALOG_H

#include <QDialog>

namespace Ui {
class GoodInDialog;
}

class GoodInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoodInDialog(QWidget *parent = 0);
    ~GoodInDialog();

private slots:
    void on_stockInfoButton_2_clicked();

    void on_exitButton_clicked();

    void on_OKButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::GoodInDialog *ui;
};

#endif // GOODINDIALOG_H
