#include "logindialog.h"
#include "ui_logindialog.h"
#include<QMessageBox>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    //hide the frame of the window
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pswEdit->setPlaceholderText("Password");

    //fix the size of window
    setFixedSize(this->width(), this->height());

    //set background picture
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/beginner_BG.png)}");

    //set the style sheet of the widgets in the window
    ui->loginButton->setStyleSheet("background-color:rgba(1,25,53,90);"
                                   "color:rgba(208,233,255);"
                                   "border-color:rgba(1,25,53,90);"
                                   "border-radius:6px;");
    ui->exitButton->setStyleSheet("background-color:rgba(1,25,53,90);"
                                  "color:rgba(208,233,255);"
                                  "border-color:rgba(1,25,53,90);"
                                  "border-radius:6px;");
    ui->pswEdit->setStyleSheet("border-color:rgba(1,25,53,50);"
                               "border-radius:6px;"
                               "background-color:rgba(208,233,255);"
                               "color:rgba(1,25,53);");
}

//destuctor
LoginDialog::~LoginDialog()
{
    delete ui;
}
//end destructor

//after entering the pass word of the system,
//this function will be invoked to check if the pass word
//is correct. If not, an error information will display.
void LoginDialog::on_loginButton_clicked()
{
    if(ui->pswEdit->text() == password)
        accept();
    else
    {
        QMessageBox::warning(this, tr("Warning"),
                      tr("Wrong password! "),
                      QMessageBox::Yes);
        ui->pswEdit->clear();
    }
}
//end function on_loginButton_clicked
