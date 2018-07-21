#include "goodindialog.h"
#include"stockinfodialog.h"
#include "ui_goodindialog.h"
#include<QMessageBox>
#include<string>
#include"goods.h"
#include<fstream>
#include"global.h"
using namespace std;




GoodInDialog::GoodInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoodInDialog)
{
    ui->setupUi(this);
    //integer enter only
    ui->quantityEdit->setValidator(new QIntValidator);
    //enter double only
    ui->costEdit->setValidator(new QDoubleValidator);
    ui->priceEdit->setValidator(new QDoubleValidator);

    //limit is set to the number input:
    //the maximum length of the name input is 20,
    //the maximum length of the number input is 4,
    ui->nameEdit->setMaxLength(20);
    ui->numberEdit->setMaxLength(4);

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
GoodInDialog::~GoodInDialog()
{
    delete ui;
}
//end destructor

//open stock information dialog
void GoodInDialog::on_stockInfoButton_2_clicked()
{
    StockInfoDialog* d = new StockInfoDialog();
    d->show();
}
//end functionon_stockInfoButton_2_clicked

//when click the exit button, the dialog will be closed
void GoodInDialog::on_exitButton_clicked()
{
    this->close();
}
//end function on_exitButton_clicked

//when ok button is clicked, the information a good is added to the file
void GoodInDialog::on_OKButton_clicked()
{
    /*add information into the file*/
    if(ui->nameEdit->text().isEmpty()||ui->numberEdit->text().isEmpty()||
            ui->priceEdit->text().isEmpty()||ui->costEdit->text().isEmpty()||
            ui->quantityEdit->text().isEmpty())
    {
        //any blank is empty, the error information will dispaly to remind you
        QMessageBox::warning(0,"Empty", "Empty space is not allowed. ", QMessageBox::Yes);
    }
    else
    {
        //transfer the inputs to corresponding type
        double costt=ui->costEdit->text().toDouble();
        double pricee=ui->priceEdit->text().toDouble();
        string namee = ui->nameEdit->text().toStdString();
        int numberr = ui->numberEdit->text().toInt();
        int quantityy = ui->quantityEdit->text().toInt();

        Goods g(namee, numberr, quantityy, costt, pricee);

        writeGoods(g);

    }

}
//end function on_OKButton_clicked


void GoodInDialog::on_clearButton_clicked()
{
//clear all the edits for next commodity
        ui->costEdit->clear();
        ui->nameEdit->clear();
        ui->priceEdit->clear();
        ui->numberEdit->clear();
        ui->quantityEdit->clear();

}
//end function on_clearButton_clicked
