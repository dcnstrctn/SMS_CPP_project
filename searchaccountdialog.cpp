#include "searchaccountdialog.h"
#include "ui_searchaccountdialog.h"
#include"QMessageBox"
#include"dateandtime.h"
#include"global.h"



searchAccountDialog::searchAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchAccountDialog)
{
    ui->setupUi(this);
    /*unable to edit the line edit, so, when the
     * line edit widget is set to display message only.
    */

    ui->showAccountTxt->setEnabled(false);//read only
    /*set limits to the input information:
      day is limited from 1 to 31,
      month is lomited from 1 to 12,
    */
    ui->enterFromDay->setValidator(new QIntValidator(1, 31, this));
    ui->enterFromMonth->setValidator(new QIntValidator(1, 12, this));
    ui->enterFromYear->setValidator(new QIntValidator(1000, 3000, this));

    ui->enterToDay->setValidator(new QIntValidator(1, 31, this));
    ui->enterToMonth->setValidator(new QIntValidator(1, 12, this));
    ui->enterToYear->setValidator(new QIntValidator(1000, 3000, this));

    //set default number
    ui->enterFromDay->setText("1");
    ui->enterFromMonth->setText("1");
    ui->enterFromYear->setText("1900");
    ui->enterToDay->setText(QString::number(getNow().getDay()));
    ui->enterToMonth->setText(QString::number(getNow().getMonth()));
    ui->enterToYear->setText(QString::number(getNow().getYear()));

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

    //fix the size of the window
    setFixedSize(this->width(), this->height());
}

/*if all the blanks are all filled, the all the information input will be
 * transfered to int type. These int numbers will be used to initialize two
 * objects of class DateAndTime. Then function printTOtxt will be invoked to
 * print information to the txt. And txt will be opened and print the information
 * to the dialog.
 * */
void searchAccountDialog::on_searchButt_clicked()
{
    if(ui->enterFromMonth->text().isEmpty()||ui->enterFromYear->text().isEmpty()
            ||ui->enterFromDay->text().isEmpty()||ui->enterFromYear->text().isEmpty()
            ||ui->enterToMonth->text().isEmpty()||ui->enterToDay->text().isEmpty())
    {
         QMessageBox::warning(0,"Empty", "Please enter month and year and day. ", QMessageBox::Yes);
    }
    else
    {
        int fromYear=ui->enterFromYear->text().toInt();
        int fromMonth=ui->enterFromMonth->text().toInt();
        int fromDay=ui->enterFromDay->text().toInt();
        int toYear=ui->enterToYear->text().toInt();
        int toMonth=ui->enterToMonth->text().toInt();
        int toDay=ui->enterToDay->text().toInt();

        DateAndTime f(fromYear,fromMonth,fromDay,0,0,0);
        DateAndTime t(toYear,toMonth,toDay,23,59,59);

        ui->showAccountTxt->clear();
         printTOtxt(f, t);
         QFile file("accountPrint.txt");
         if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))

             {
                 QTextStream textStream(&file);
                 while (!textStream.atEnd())
                 {

                     ui->showAccountTxt->append(textStream.readLine());
                 }
             }
             else
             {

                 QMessageBox ::information(NULL, NULL, "open file error");
             }
         file.close();
         }
//close the file
    }

//when the exist button is clicked, the dialog will be closed
void searchAccountDialog::on_exitButt_clicked()
{

    this->close();
}
//end the on_exitButt_clicked function

//destructor
searchAccountDialog::~searchAccountDialog()
{
    delete ui;
}
//end the destructor
