#ifndef SEARCHPHONENUMBER_H
#define SEARCHPHONENUMBER_H

#include <QDialog>
#include<QRadioButton>
#include<QWidget>
#include"supervip.h"

namespace Ui {
class searchPhoneNumber;
}

class searchPhoneNumber : public QDialog
{
    Q_OBJECT

public:
    explicit searchPhoneNumber(QWidget *parent = 0);
    ~searchPhoneNumber();


private slots:
    void on_searchButt_clicked();

    void on_okButt_clicked();

    void on_skipButt_clicked();

private:
    Ui::searchPhoneNumber *ui;
    QRadioButton *searchVIP;
    QRadioButton *searchSuperVIP;
    Vip vipmember = Vip();
    SuperVip svipmember = SuperVip();


};

#endif // SEARCHPHONENUMBER_H
