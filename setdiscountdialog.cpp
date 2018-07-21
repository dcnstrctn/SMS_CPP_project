#include "setdiscountdialog.h"
#include "ui_setdiscountdialog.h"
#include"global.h"

setDiscountDialog::setDiscountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDiscountDialog)
{
    ui->setupUi(this);
    //fix the size of the dialog
    setFixedSize(this->width(), this->height());
    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
setDiscountDialog::~setDiscountDialog()
{
    delete ui;
}
//end distructor

//when clicked ok button, discount will be set and the dialog will be closed
 void setDiscountDialog::on_okButt_clicked()
 {
    holidayDiscount = ui->enterDiscount->text().toDouble();
    this->close();
 }
 //end on_okButt_clicked function

//when push button is clicked, the dialog will be closed
void setDiscountDialog::on_pushButton_clicked()
{
    this->close();
}
//end on_pushButton_clicked function
