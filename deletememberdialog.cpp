#include "deletememberdialog.h"
#include "ui_deletememberdialog.h"
#include<QMessageBox>
#include<string>
#include"newmnmberdialog.h"
#include"global.h"
using namespace std;

DeleteMemberDialog::DeleteMemberDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteMemberDialog)
{
    ui->setupUi(this);
    /*set limits to the input information:
      day is limited from 1 to 31,
      month is lomited from 1 to 12,
      year is limited from 1000 to 3000.
    */
    ui->dayEdit->setValidator(new QIntValidator(1, 31, this));
    ui->monthEdit->setValidator(new QIntValidator(1, 12, this));
    ui->yearEdit->setValidator(new QIntValidator(1000, 3000, this));

    //the maximum length of the phone number entered is 11
    ui->phoneNoEdit->setMaxLength(11);

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
DeleteMemberDialog::~DeleteMemberDialog()
{
    delete ui;
}
//end destructor

//afte your entering the information of a member and clicking
//the delet button, a message will display to remind you if you are
//sure to delete this member from the file. If you still choose yes,
//then the vip or super vip will be deleted(depends on which radio button you
//have chosen.
void DeleteMemberDialog::on_deleteButton_clicked()
{
    int YN = QMessageBox::question(0, "Delete",
                             ("Are you sure to delete this member? "),
                             QMessageBox::Yes, QMessageBox::No);
    if(YN == QMessageBox::Yes)
    {
        std::string phonenum = ui->phoneNoEdit->text().toStdString();
        if(ui->vipButton->isChecked())
        {
            deletevip(phonenum);

        }
        else if(ui->svipButton->isChecked())
        {
            deleteSvip(phonenum);
        }
    }

}
//end function on_deleteButton_clicked

//enter the phone number of a member, click the search button,
//chose the vip radio button, if this member is a vip, then the name, birthday,
//current points and total points will be displayed.
//enter the phone number of a member, click the search button,
//chose the super vip radio button, if this member is a super vip, then the name, birthday,
//current points and total points will be displayed.
void DeleteMemberDialog::on_searchButton_clicked()
{
    std::string phonenum = ui->phoneNoEdit->text().toStdString();
    if(ui->vipButton->isChecked())
    {
        Vip v = findvip(phonenum);
        ui->nameEdit->setText(QString::fromStdString(v.getName()));
        ui->dayEdit->setText(QString::number(v.getBirthday().getDay()));
        ui->monthEdit->setText(QString::number(v.getBirthday().getMonth()));
        ui->yearEdit->setText(QString::number(v.getBirthday().getYear()));
        ui->pointLabel->setText(QString::number(v.getPoint()));
        ui->totalPointLabel->setText(QString::number(v.getTotalPoint()));
        oldphonenumber = v.getPhoneNumber();
        //in case that the member want to change a phone number
    }
    else if(ui->svipButton->isChecked())
    {
        SuperVip v = findSvip(phonenum);
        ui->nameEdit->setText(QString::fromStdString(v.getName()));
        ui->dayEdit->setText(QString::number(v.getBirthday().getDay()));
        ui->monthEdit->setText(QString::number(v.getBirthday().getMonth()));
        ui->yearEdit->setText(QString::number(v.getBirthday().getYear()));
        ui->pointLabel->setText(QString::number(v.getPoint()));
        ui->totalPointLabel->setText(QString::number(v.getTotalPoint()));
        oldphonenumber = v.getPhoneNumber();
        //in case that the member want to change a phone number
    }

}
//end function on_searchButton_clicked

//fill in all the blanks of this dialog and click the update button.
//the information input will be transfered to corresponding date type.
//if the vip radio button is chosen,the the information of this vip will be update.
//if the super vip radio button is chosen,the the information of this super vip will be update.
void DeleteMemberDialog::on_updateButton_clicked()
{
    if(ui->nameEdit->text().isEmpty()||ui->dayEdit->text().isEmpty()||ui->monthEdit->text().isEmpty()||
            ui->yearEdit->text().isEmpty()||ui->phoneNoEdit->text().isEmpty())
    {
        QMessageBox::warning(0,"Empty", "Empty space is not allowed. ", QMessageBox::Yes);
    }
    else
    {
        string name = ui->nameEdit->text().toStdString();
        string phonenum = ui->phoneNoEdit->text().toStdString();
        int year = ui->yearEdit->text().toInt();
        int month = ui->monthEdit->text().toInt();
        int day = ui->dayEdit->text().toInt();
        DateAndTime bday(year, month, day);
        if(ui->vipButton->isChecked())
        {
            Vip v = findvip(oldphonenumber);
            v.setName(name);
            v.setPhoneNumber(phonenum);
            v.setBirthday(bday);
            changevip(oldphonenumber, v);
        }
        else if(ui->svipButton->isChecked())
        {
            SuperVip v = findSvip(oldphonenumber);
            v.setName(name);
            v.setPhoneNumber(phonenum);
            v.setBirthday(bday);
            changeSvip(oldphonenumber, v);
        }

    }

}
//end function on_updateButton_clicked

//when the exit button is clicked, the dialog will be closed.
void DeleteMemberDialog::on_exitButton_clicked()
{
    this->close();
}
//end function on_exitButton_clicked

//when click the clear button all the blanks will be cleared.
void DeleteMemberDialog::on_clearButton_clicked()
{
    ui->phoneNoEdit->clear();
    ui->nameEdit->clear();
    ui->dayEdit->clear();
    ui->monthEdit->clear();
    ui->yearEdit->clear();
    ui->pointLabel->clear();
    ui->totalPointLabel->clear();
}
//end function on_clearButton_clicked
