#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include"searchphonenumber.h"
#include"global.h"
#include<QMessageBox>

checkOutDialog::checkOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkOutDialog)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

    ui->goodsNumberEdit->setMaxLength(4);//limit the length of number
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButton_2->hide();

    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("Hello"));

    //以下标签右对齐
    ui->label_7->setAlignment(Qt::AlignRight);
    ui->label_8->setAlignment(Qt::AlignRight);
    ui->label_9->setAlignment(Qt::AlignRight);
    ui->timeLabel->setText(QString::fromStdString(getNow().returnStandard()));
}

checkOutDialog::~checkOutDialog()
{
    delete ui;
}
//send a vip member to check out dialog and create a pointer to it
void checkOutDialog::sendVip(Vip vipmember)
{
    accountPtr = new Account(vipmember);
    ui->nameLabel->setText(QString::fromStdString(vipmember.getName()));
    ui->levelLabel->setText("VIP");
}

//send a super vip member to check out dialog and create a pointer to it
void checkOutDialog::sendSvip(SuperVip svipmember)
{
    accountPtr = new DiscountAccount(svipmember);
    ui->nameLabel->setText(QString::fromStdString(svipmember.getName()));
    ui->levelLabel->setText("SUPER VIP");
}

//send a normal non-vip customer to check out dialog and create a pointer to it
void checkOutDialog::sendCustomer(Vip customer)
{
    accountPtr = new Account(customer);
    //hide all the labels for vip
    ui->label->hide();
    ui->label_2->hide();
    ui->IncrementLabel->hide();
    ui->currrentPointLabel->hide();
}


//When Add item push button is clicked
void checkOutDialog::on_addItemButton_clicked()
{
    Goods g = getGoods(ui->goodsNumberEdit->text().toInt());
    if(ui->quantityEdit->text().toInt()>g.getquantity())//check if inventory is enough
    {
        QMessageBox::warning(this, "Warning", "Inventory shortage! ", QMessageBox::Yes);
        ui->quantityEdit->clear();
    }
    else  //when the inventory is enough
    {
        int RowCont;
        RowCont=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);//add one row

        int quan = 1;//default quantity
        if(!ui->quantityEdit->text().isEmpty())
            quan = ui->quantityEdit->text().toInt();
        //if the edit is not empty, set quantity of this commodity

        accountPtr->addGoods(g, quan);
        ui->tableWidget->setItem((accountPtr->getNumberOfGoods()-1),0,
                                 new QTableWidgetItem(QString::fromStdString(g.getName())));
        ui->tableWidget->setItem((accountPtr->getNumberOfGoods()-1),1,
                                 new QTableWidgetItem(QString::number(g.getprice(), 10, 2)));
        ui->tableWidget->setItem((accountPtr->getNumberOfGoods()-1),2,
                                 new QTableWidgetItem(QString::number(quan)));

        //display current total cost
        double t = 0;
        for(int i = 0; i<RowCont+1; i++)
        {
            t+=(ui->tableWidget->item(i,1)->text().toDouble())*(ui->tableWidget->item(i,2)->text().toInt());
        }
        ui->displayTCostLabel->setText(QString::number(t, 10, 2));

        ui->goodsNumberEdit->clear();
        ui->quantityEdit->clear();
    }

}

void checkOutDialog::on_pushButton_clicked()
{
    accountPtr->calculateTotal();


    //Calculate total cost
    DiscountAccount *dcPtr = dynamic_cast<DiscountAccount *>(accountPtr);
    if(dcPtr != nullptr)
    {
        ui->finalDiscountlabel->setText(QString::number(dcPtr->getSMember().getVipDiscount()*holidayDiscount, 10, 2));
        double currentAccount = accountPtr->getTotalAccount();
        accountPtr->setTotalAccount(currentAccount*holidayDiscount);
    }
    else
    {
        ui->finalDiscountlabel->setText(QString::number(holidayDiscount, 10, 2));
        double currentAccount = accountPtr->getTotalAccount();
        accountPtr->setTotalAccount(currentAccount*holidayDiscount);
    }

    //display final cost
    ui->finalCostLabel->setText(QString::number(accountPtr->getTotalAccount(), 10, 2));

    //add point
    ui->IncrementLabel->setText(QString::number(static_cast<int>(accountPtr->getTotalAccount())));
    accountPtr->addPoint();

    //calculate profit
    accountPtr->calculateProfit();

    //display current points
    dcPtr = dynamic_cast<DiscountAccount *>(accountPtr);
    if(dcPtr != nullptr)
        ui->currrentPointLabel->setText(QString::number(dcPtr->getSMember().getTotalPoint()));
    else
        ui->currrentPointLabel->setText(QString::number(accountPtr->getMember().getTotalPoint()));

    ui->pushButton->hide();
    ui->pushButton_2->show();
}

void checkOutDialog::on_pushButton_3_clicked()
{
    this->close();
}

void checkOutDialog::on_pushButton_2_clicked()
{
    //update member information
    QMessageBox::about(this, "Succeed", "Check out!");
    DiscountAccount *dcPtr = dynamic_cast<DiscountAccount *>(accountPtr);
    if(dcPtr != nullptr)//case supervip
    {
        changeSvip(dcPtr->getSMember().getPhoneNumber(), dcPtr->getSMember());
        Record re;
        re.DAT = dcPtr->getDateAndTime();
        re.profit = dcPtr->getTotalProfit();
        re.total = dcPtr->getTotalAccount();
        writeAccount(re);
        dayAccount(re.DAT, re.total, re.profit);
        monthAccount(re.DAT, re.total, re.profit);
    }
    else if (accountPtr->getMember().getName() != "")//case vip but not a non-vip
    {
        changevip(accountPtr->getMember().getPhoneNumber(), accountPtr->getMember());
        Record re;
        re.DAT = accountPtr->getDateAndTime();
        re.profit = accountPtr->getTotalProfit();
        re.total = accountPtr->getTotalAccount();
        writeAccount(re);
        dayAccount(re.DAT, re.total, re.profit);
        monthAccount(re.DAT, re.total, re.profit);
    }
    else{
        Record re;
        re.DAT = accountPtr->getDateAndTime();
        re.profit = accountPtr->getTotalProfit();
        re.total = accountPtr->getTotalAccount();
        writeAccount(re);
        dayAccount(re.DAT, re.total, re.profit);
        monthAccount(re.DAT, re.total, re.profit);
    }

    //update goods information
    for(int i = 0;i<accountPtr->getNumberOfGoods();i++)
    {
        //invoke function getGoods to get goods information
        int goodNo = accountPtr->goodArray[i].getNumber();
        Goods g = getGoods(goodNo);
        int currentQuantity = g.getquantity();
        currentQuantity -=accountPtr->goodQuantity[i];
        g.setquantity(currentQuantity);
        changeGoods(g);
        //update goods
    }

    this->close();

}
