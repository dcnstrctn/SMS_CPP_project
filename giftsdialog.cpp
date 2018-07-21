#include "giftsdialog.h"
#include "ui_giftsdialog.h"
#include"global.h"
#include<QMessageBox>

GiftsDialog::GiftsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GiftsDialog)
{
    ui->setupUi(this);

    //the maximum length of the number input is 11
    ui->phoneNoEdit->setMaxLength(11);
    ui->exchangelineEdit->setValidator(new QIntValidator(1, 10000, this));
    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

}

//destructor
GiftsDialog::~GiftsDialog()
{
    delete ui;
}
//end destructor

//when search button is clicked,  this function will be invoked.
//If the vip radio button is chosen, the we search the phone in the
//vip file, and display the name and the points of the vip member.
//If the super vip radio button is chosen, the we search the phone in the
//super vip file, and display the name and the points of the super vip member.
void GiftsDialog::on_searchButton_clicked()
{
    std::string phonenum = ui->phoneNoEdit->text().toStdString();
    if(ui->vipButton->isChecked())
    {
        Vip v = findvip(phonenum);
        ui->nameEdit->setText(QString::fromStdString(v.getName()));
        ui->pointLabel->setText(QString::number(v.getPoint()));
        vipmember = v;

    }
    else if(ui->svipButton->isChecked())
    {
        SuperVip v = findSvip(phonenum);
        ui->nameEdit->setText(QString::fromStdString(v.getName()));
        ui->pointLabel->setText(QString::number(v.getPoint()));
        svipmember = v;
    }

}
//end function on_searchButton_clicked

//When all the blanks is filled, this function will take the exchange
//point of the vip or super vip(depends on which radio button you choose)
//and decrease the current points correspondingly.
void GiftsDialog::on_okButton_clicked()
{
    if(ui->nameEdit->text().isEmpty()||ui->exchangelineEdit->text().isEmpty()||ui->phoneNoEdit->text().isEmpty())
    {
        QMessageBox::warning(0,"Empty", "Empty space is not allowed. ", QMessageBox::Yes);
    }
    else
    {
        int p = ui->exchangelineEdit->text().toInt();
        if(ui->vipButton->isChecked())
        {
            vipmember.decreasePoint(p);
            changevip(vipmember.getPhoneNumber(), vipmember);

        }
        else if(ui->svipButton->isChecked())
        {
            svipmember.decreasePoint(p);

            changeSvip(svipmember.getPhoneNumber(), svipmember);
        }
    }
    this->close();
}
//end function on_okButton_clicked

//when the cencal button is clicked, the dialog will be closed.
void GiftsDialog::on_cancelButton_clicked()
{
    this->close();
}
//end function on_cancelButton_clicked5
