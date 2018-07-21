#include "searchphonenumber.h"
#include "ui_searchphonenumber.h"
#include"supervip.h"
#include "checkoutdialog.h"
#include"global.h"
#include "QGridLayout"
#include<QMessageBox>
#include<string>

searchPhoneNumber::searchPhoneNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchPhoneNumber)
{
    ui->setupUi(this);

    //the maximum length of the phone number input is 11
    ui->enterPhoneNum->setMaxLength(11);
    //set fixed dialog size
    setFixedSize(this->width(), this->height());

    //chose vip radio button defaultly
    ui->radioButt_vip->setChecked(true);

    //hide the discount label defaultly
    ui->discountLabel->hide();
     //hide the display diacount label defaultly
    ui->displayDiscount->hide();

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
searchPhoneNumber::~searchPhoneNumber()
{
    delete ui;
}
//end destructor

void searchPhoneNumber::on_searchButt_clicked()
{
    /*when vip radio button is chosen,
the discount label and display discount label will be hiden.
Enter the phone number. Click the search button, if the phone number is empty,
a message will be diaplay to remind you to enter none-empty phone number.
If the phone number is valid, then the findVip function will be invoked, finally
the member's name and his total points will be displayed.*/
    if(ui->radioButt_vip->isChecked())
    {
        ui->discountLabel->hide();//hide this label
        ui->displayDiscount->hide();
        if(ui->enterPhoneNum->text().isEmpty())
        {
            QMessageBox::warning(0,"Empty", "Please enter phone number. ", QMessageBox::Yes);
        }
        else
        {
            std::string phoneNumber=ui->enterPhoneNum->text().toStdString();
            vipmember=findvip(phoneNumber);
            ui->displayMemberName->setText(QString::fromStdString(vipmember.getName()));
            ui->displayMemberPoint->setText(QString::number(vipmember.getTotalPoint()));

        }
    }
    /*when super vip radio button is chosen,
the discount label and display discount label will be showen.
Enter the phone number. Click the search button, if the phone number is empty,
a message will be diaplay to remind you to enter none-empty phone number.
If the phone number is valid, then the findVip function will be invoked, finally
the member's name, his total points and his discount number will be displayed.*/
    if(ui->radioButton_superVip->isChecked())
    {
        ui->displayDiscount->show();
        ui->discountLabel->show();
        if(ui->enterPhoneNum->text().isEmpty())
        {
          QMessageBox::warning(0,"Empty", "Please enter phone number. ", QMessageBox::Yes);
        }
        else
        {
            std::string phoneNumber=ui->enterPhoneNum->text().toStdString();
            svipmember = findSvip(phoneNumber);
            svipmember.setVipDiscount();
            ui->displayMemberName->setText(QString::fromStdString(svipmember.getName()));
            ui->displayMemberPoint->setText(QString::number(svipmember.getTotalPoint()));
            ui->displayDiscount->setText(QString::number(svipmember.getVipDiscount(), 10, 2));

        }
    }
}
//end function on_searchButt_clicked

/*when ok button is clicked, if the member searched is a vip, then the
 information of this vip member will be pass to the next dialog.
  If the member searched is a super vip, then the
 information of this vip member will be pass to the next dialog.
*/
void searchPhoneNumber::on_okButt_clicked()
{
    if(ui->radioButt_vip->isChecked())
    {
        std::string phoneNumber=ui->enterPhoneNum->text().toStdString();
        vipmember=findvip(phoneNumber);
        checkOutDialog *cod = new checkOutDialog;
        cod->sendVip(vipmember);
        cod->show();
    }
    else if (ui->radioButton_superVip->isChecked())
    {
        std::string phoneNumber=ui->enterPhoneNum->text().toStdString();
        svipmember = findSvip(phoneNumber);
        svipmember.setVipDiscount();
        checkOutDialog *cod = new checkOutDialog;
        cod->sendSvip(svipmember);
        cod->show();
    }

}
//end on_okButt_clicked function

/*if the member searched is not a vip or a super vip,
you can click the skip button to enter the check out dialog
*/

void searchPhoneNumber::on_skipButt_clicked()
{
    vipmember = Vip();

    checkOutDialog *cod = new checkOutDialog;
    cod->sendCustomer(vipmember);
    cod->show();
}
//end the on_skipButt_clicked function
