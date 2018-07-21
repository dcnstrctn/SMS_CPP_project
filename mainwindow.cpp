#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"changepwdialog.h"
#include"stockinfodialog.h"
#include"goodindialog.h"
#include"modifystockinfordialog.h"
#include"newmnmberdialog.h"
#include"deletememberdialog.h"
#include"viewallmember.h"
#include"searchphonenumber.h"
#include"setdiscountdialog.h"
#include"dailyaccountdialog.h"
#include"monthlyaccountdialog.h"
#include"searchaccountdialog.h"
#include"giftsdialog.h"
#include"setdiscountdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    this->setFixedSize(this->width(),this->height());
    ui->checkOutButton->setStyleSheet("background-image:url(:/myimages/shoppingButton.png)");


    //slots of the widgets in the mainwindow
    connect(ui->actionChange_Password, SIGNAL(triggered()), this, SLOT(openCPD()));
    connect(ui->actionExit_E, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionStock_Information_I,SIGNAL(triggered()),this,SLOT(openSID()));
    connect(ui->actionGoods_In_G,SIGNAL(triggered()),this,SLOT(openGID()));
    connect(ui->actionModify_Stock_Information_M,SIGNAL(triggered()),this,SLOT(openMSID()));
    connect(ui->actionNew_Member_N,SIGNAL(triggered()),this,SLOT(openNMD()));
    connect(ui->actionDelete_Member_D,SIGNAL(triggered()),this,SLOT(openDMD()));
    connect(ui->actionView_All_V,SIGNAL(triggered()),this,SLOT(openVAMD()));
    connect(ui->actionDaily,SIGNAL(triggered()),this,SLOT(openDAD()));
    connect(ui->actionMonthly,SIGNAL(triggered()),this,SLOT(openMAD()));
    connect(ui->actionSearch,SIGNAL(triggered()),this,SLOT(openSAD()));

}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}
//end destructor

//open Change Pass Word Dialog
void MainWindow::openCPD()
{
    ChangePwDialog *cpd = new ChangePwDialog (this);
    cpd->show();
}
//end function openCPD

//open Stock Information Dialog
void MainWindow::openSID()
{
    StockInfoDialog *sid = new StockInfoDialog (this);
    sid->show();
}
//end function openSID

//open GoodsIn Dialog
void MainWindow::openGID()
{
    GoodInDialog *gid = new GoodInDialog (this);
    gid->show();
}
//end function openGID

//open ModifyStockInformation Dialog
void MainWindow::openMSID()
{
    ModifyStockInforDialog *msid = new ModifyStockInforDialog (this);
    msid->show();
}
//end function openMSID

//open NewMember Dialog
void MainWindow::openNMD()
{
    NewMnmberDialog*nmd = new NewMnmberDialog (this);
    nmd->show();
}
//end function openNMD

//open DeleteMember Dialog
void MainWindow::openDMD()
{
    DeleteMemberDialog*dmd = new DeleteMemberDialog (this);
    dmd->show();
}
//end function openDMD

//open View All Dialog
void MainWindow::openVAMD()
{
    viewAllMember*dmd = new viewAllMember (this);
    dmd->show();

}
//end function openVAMD

//open Check Out Dialog
void MainWindow::on_checkOutButton_clicked()
{
    searchPhoneNumber *s = new searchPhoneNumber(this);
    s->show();
}
//end function on_checkOutButton_clicked

//open Set Discount Dialog
void MainWindow:: on_setDiscountButton_clicked()
 {
     setDiscountDialog*sdd=new setDiscountDialog(this);
     sdd->show();
 }
//end function on_setDiscountButton_clicked

//open Daily Account Dialog
void MainWindow::openDAD()
{
    dailyAccountDialog *dad = new dailyAccountDialog(this);
    dad->show();
}
//end function openDAD

//open Monthly Account Dialog
void MainWindow::openMAD()
{
    monthlyAccountDialog *mad = new monthlyAccountDialog(this);
    mad->show();
}
//end function openMAD

//open Search Account Dialog
void MainWindow::openSAD()
{
    searchAccountDialog *sad = new searchAccountDialog(this);
    sad->show();
}
//end function openSAD

//open gifts dialog
void MainWindow::on_pushButton_clicked()
{
    GiftsDialog *gd = new GiftsDialog(this);
    gd->show();
}
//end function on_pushButton_clicked

//open set discount dialog
void MainWindow::on_setButton_clicked()
{
    setDiscountDialog *sdk = new setDiscountDialog(this);
    sdk->show();
}
//end function on_setButton_clicked
