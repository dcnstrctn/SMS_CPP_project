#include "newmnmberdialog.h"
#include "ui_newmnmberdialog.h"
#include<QString>
#include<string>
#include<QMessageBox>
#include<QString>
#include"global.h"
#include"viewallmember.h"
using namespace std;

NewMnmberDialog::NewMnmberDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMnmberDialog)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

    //fix the size of the dialog
    this->setFixedSize(this->width(), this->height());

    /*set limits to the input information:
      day is limited from 1 to 31,
      month is lomited from 1 to 12,
    */
    ui->dayEdit->setValidator(new QIntValidator(1, 31, this));
    ui->monthEdit->setValidator(new QIntValidator(1, 12, this));
    ui->yearEdit->setValidator(new QIntValidator(1000, 3000, this));
    ui->phoneNoEdit->setMaxLength(11);

}

//destructor
NewMnmberDialog::~NewMnmberDialog()
{
    delete ui;
}
//end destructor

//when view all number button is clicked, the view all dialog will be showen
void NewMnmberDialog::on_InfoButton_2_clicked()
{
    viewAllMember *view = new viewAllMember(this);
    view->show();
}
//end on_InfoButton_2_clicked

/*when all empty blanks are filled, click the ok button,
 * name and phone number will be transfered to to string and
 * month, year, day entered will be transfered to int.If vip radio button
 * is chosen, then the member information will be add to vip file.
 * If super vip radio button is chosen, then the member information
 * will be add to super vip file.
 */
void NewMnmberDialog::on_OKButton_clicked()
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
            Vip newv(name, phonenum, bday);
            addmember(newv);

        }
        else if(ui->svipButton->isChecked())
        {
            SuperVip newsv(name, phonenum, bday);
            addSmember(newsv);
        }
    }

}
//end on_OKButton_clicked function

//click the exist button, the dialog will be closed
void NewMnmberDialog::on_exitButton_clicked()
{
    this->close();
}
//end the on_exitButton_clicked function

//click the clear  button, all the inputs will be cleared
void NewMnmberDialog::on_clearButton_clicked()
{
    ui->dayEdit->clear();
    ui->nameEdit->clear();
    ui->phoneNoEdit->clear();
    ui->yearEdit->clear();
    ui->monthEdit->clear();
}
//end on_clearButton_clicked function
