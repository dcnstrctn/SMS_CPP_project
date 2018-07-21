#include "modifystockinfordialog.h"
#include "ui_modifystockinfordialog.h"
#include<QMessageBox>
#include<fstream>
#include<string>
#include"global.h"
using namespace std;
ModifyStockInforDialog::ModifyStockInforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyStockInforDialog)
{
    ui->setupUi(this);

    //integer enter only
    //enter double only
    ui->quantityEdit->setValidator(new QIntValidator);//integer enter only
    ui->costEdit->setValidator(new QDoubleValidator);//enter double only
    ui->priceEdit->setValidator(new QDoubleValidator);
    /*set limits to the information input:
     * the maximum length of the name input is 20,
     * the maximum length of the number input is 4
*/
    ui->nameEdit->setMaxLength(20);
    ui->numberEdit->setMaxLength(4);

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
ModifyStockInforDialog::~ModifyStockInforDialog()
{
    delete ui;
}
//end destructor


void ModifyStockInforDialog::on_stockInfoButton_2_clicked()
{
    /*get number*/
    int num = ui->numberEdit->text().toInt();

    /*search information*/
    Goods target = getGoods(num);
    string s = target.getName();

    /*show information*/
    QString str = QString::fromStdString(target.getName());
    ui->nameEdit->setText(str);
    ui->quantityEdit->setText(QString::number(target.getquantity()));
    //base 10, precision 2
    ui->costEdit->setText(QString::number(target.getCost(), 10, 2));

    //base 10, precision 2
    ui->priceEdit->setText(QString::number(target.getprice(), 10, 2));

    /*set number line edit read only*/
    if(ui->nameEdit->text() != "")
        ui->numberEdit->setEnabled(false);

}

//when click exit button, the dialog will be closed
void ModifyStockInforDialog::on_exitButton_clicked()
{
    this->close();
}
//end function on_exitButton_clicked

//delete stock information
void ModifyStockInforDialog::on_deleteButton_clicked()
{
    int YN = QMessageBox::question(0, "Delete",
                             ("Are you sure to delete this item? "),
                             QMessageBox::Yes, QMessageBox::No);
    if(YN == QMessageBox::Yes)
    {
        deleteGoods(ui->numberEdit->text().toInt());
        QMessageBox::information(0, "Deleted",
                                 "The record has been deleted. ", QMessageBox::Yes);
    }
}
//end functionon_deleteButton_clicked



//enter name, number, price, cost, quantity to modify the information of a stock
void ModifyStockInforDialog::on_modifyButton_clicked()
{
    //if any blank is empty, an error information will be sent
    if(ui->nameEdit->text().isEmpty()||ui->numberEdit->text().isEmpty()||
            ui->priceEdit->text().isEmpty()||ui->costEdit->text().isEmpty()||
            ui->quantityEdit->text().isEmpty())
    {
        QMessageBox::warning(0,"Empty", "Empty space is not allowed. ", QMessageBox::Yes);
    }
    else
    {
        /*modify information from the file*/
        double costt=ui->costEdit->text().toDouble();
        double pricee=ui->priceEdit->text().toDouble();
        string namee = ui->nameEdit->text().toStdString();
        int numberr = ui->numberEdit->text().toInt();
        int quantityy = ui->quantityEdit->text().toInt();

        Goods g(namee, numberr, quantityy, costt, pricee);

        changeGoods(g);
        QMessageBox::information(0, "Succeed",
                                     ("The commodity has been modified. "),
                                     QMessageBox::Yes);
    }
}
//end the function on_modifyButton_clicked

//clear all the information input
void ModifyStockInforDialog::on_pushButton_clicked()
{
    ui->numberEdit->setEnabled(true);

    //clear all the edits
    ui->costEdit->clear();
    ui->nameEdit->clear();
    ui->priceEdit->clear();
    ui->numberEdit->clear();
    ui->quantityEdit->clear();
}
//end the function on_pushButton_clicked
