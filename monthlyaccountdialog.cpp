#include "monthlyaccountdialog.h"
#include "ui_monthlyaccountdialog.h"
#include<QMessageBox>
#include"dateandtime.h"
#include"global.h"

monthlyAccountDialog::monthlyAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monthlyAccountDialog)
{
    ui->setupUi(this);

    //fix the size of the dialog
    setFixedSize(this->width(), this->height());

    /*set limits to the input information:
      month is lomited from 1 to 12,
    */
    ui->enterMonth->setValidator(new QIntValidator(1, 12, this));
    ui->enterYear->setValidator(new QIntValidator(1000, 3000, this));
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
monthlyAccountDialog::~monthlyAccountDialog()
{
    delete ui;
}
//end destructor

/*when all the blanks are filled, year and month which entered will be
 * transfered to int number and used to initialize a object of DateAndTime.
 *Then function getTotalMonthAccount and function getTotalMonthProfit will be invoked.
 * Finally, TotalAccount and MonthlyProfit of the certain month will display in the labels.
*/
void monthlyAccountDialog::on_searchButt_clicked()
{
    if(ui->enterMonth->text().isEmpty()||ui->enterYear->text().isEmpty())
    {
         QMessageBox::warning(0,"Empty", "Please enter month and year. ", QMessageBox::Yes);
    }
    else
    {
        int year=ui->enterYear->text().toInt();
        int month=ui->enterMonth->text().toInt();
        DateAndTime m(year,month,1,0,0,0);

        ui->displayTotalAccount->setText(QString::number((getTotalMonthAccount(m)),10,2));
        ui->displayMonthlyProfit->setText(QString::number((getTotalMonthProfit(m)),10,2));


    }
}
//end the function on_searchButt_clicked

//when exit button is clicked, the dialog will be closed
void monthlyAccountDialog::on_exitButt_clicked()
{

    this->close();
}
//end the finction on_exitButt_clicked
