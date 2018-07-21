#include "changepwdialog.h"
#include "ui_changepwdialog.h"
#include<fstream>
#include<QMessageBox>
#include<QString>
#include<string>
using namespace std;

ChangePwDialog::ChangePwDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePwDialog)
{
    ui->setupUi(this);

    //default information dispalyed in the blanks
    //in order to remind you of what to input
    ui->oldPwEdit->setPlaceholderText("Old password");
    ui->newPwEdit_1->setPlaceholderText("New password");
    ui->newPwEdit_2->setPlaceholderText("New password again");

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");


}

//destructor
ChangePwDialog::~ChangePwDialog()
{
    delete ui;
}
//end destructor

//enter the old pass word and the new password,
//then enter the new for again to check if the inputs of the two times are the same.
//if so, the function will try to open the file and write the new password to the txt.
//if the file could not be open, then an error message will be displayed.
void ChangePwDialog::on_okButton_clicked()
{
    string pwString;

    if(ui->oldPwEdit->text()==password)
    {
        if(ui->newPwEdit_1->text()==ui->newPwEdit_2->text())
        {
            ofstream out("pw.dat", ios::out|ios::binary);
            if(!out)
            {
                QMessageBox::warning(0, "Warning", "File could not be opened. ", QMessageBox::Yes);
            }else
            {
                password = ui->newPwEdit_1->text();
                pwString = password.toStdString();
                out<<pwString;
                QMessageBox::information(0, "Succeed", "Password has been modified successfully. ", QMessageBox::Yes);
                this->close();
            }

        }
        //if the two new password input is different , then an error message will be
        //displayed to remind you, and the new password will be clesred at the same time.
        else
        {
            QMessageBox::warning(0, "Warning", "Two new passwords are not the same. ", QMessageBox::Yes);
            ui->newPwEdit_1->clear();
            ui->newPwEdit_2->clear();
        }
    }
    //if the old password is wrong, then an error message will be
    //displayed to remind you, and both the new password and the old one
    //will be clesred at the same time.
    else
    {
        QMessageBox::warning(0, "Warning", "Wrong password! ", QMessageBox::Yes);
        ui->oldPwEdit->clear();
        ui->newPwEdit_1->clear();
        ui->newPwEdit_2->clear();
    }

}
//end function on_okButton_clicked
