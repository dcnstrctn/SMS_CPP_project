#include "dailyaccountdialog.h"
#include "ui_dailyaccountdialog.h"
#include<QMessageBox>
#include"dateandtime.h"
#include"global.h"

dailyAccountDialog::dailyAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dailyAccountDialog)
{
    ui->setupUi(this);

    //set fixed dialog size
    setFixedSize(this->width(), this->height());

    /*set limits to the input information:
      day is limited from 1 to 31,
      month is lomited from 1 to 12,
      year is limited from 1000 to 3000.
    */
    ui->enterDay->setValidator(new QIntValidator(1, 31, this));
    ui->enterMonth->setValidator(new QIntValidator(1, 12, this));
    ui->enterYear->setValidator(new QIntValidator(1000, 3000, this));

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");


}

//destructor
dailyAccountDialog::~dailyAccountDialog()
{
    delete ui;
}
//end destructor

//fill in all the blanks in the dialog, and then click search button,
//the information input will be transfered to corresponding data type.
//an object of class DateAndTime is created and is initialized with the time input.
//after searching in the txt file, the daily account of that day and the total profit
//of that day will be displayed.
void dailyAccountDialog::on_searchButt_clicked()
{
    if(ui->enterMonth->text().isEmpty()||ui->enterYear->text().isEmpty())
    {
         QMessageBox::warning(0,"Empty", "Please enter month and year. ", QMessageBox::Yes);
    }
    else
    {
        int year=ui->enterYear->text().toInt();
        int month=ui->enterMonth->text().toInt();
        int day=ui->enterDay->text().toInt();

        DateAndTime d(year,month,day,0,0,0);
        ui->displayDailyProfit->setText(QString::number((getTotalDayProfit(d)),10,2));
        ui->displayTotalAccount->setText(QString::number((getTotalDayAccount(d)),10,2));

    }
}
//end function on_searchButt_clicked

//when the exit button is clicked, the dialog will be closed.
void dailyAccountDialog::on_exitButt_clicked()
{

    this->close();
}
//end functon on_exitButt_clicked
