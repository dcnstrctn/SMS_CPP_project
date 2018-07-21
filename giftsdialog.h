#ifndef GIFTSDIALOG_H
#define GIFTSDIALOG_H

#include <QDialog>
#include"supervip.h"
namespace Ui {
class GiftsDialog;
}

class GiftsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GiftsDialog(QWidget *parent = 0);
    ~GiftsDialog();

private slots:
    void on_searchButton_clicked();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::GiftsDialog *ui;
    Vip vipmember;
    SuperVip svipmember;
};

#endif // GIFTSDIALOG_H
