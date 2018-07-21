#pragma once
#include"Vip.h"
#include"dateAndTime.h"
#include"Goods.h"
#include<string>
class Account
{
public:
    Account(Vip = Vip());
    void addGoods(Goods&, int = 1);
    virtual double calculateTotal();
    virtual double calculateProfit();
    virtual void addPoint();
    void setTotalAccount(double total);
    double getTotalAccount() const;
    double getTotalProfit() const;
    std::string getcustomernumber()const;
    DateAndTime getDateAndTime()const;
    int getNumberOfGoods()const;
    Vip getMember() const;

    Goods goodArray[200];
    int goodQuantity[200];//记录每个商品的数量
protected:
    int numberOfGoods = 0;
    DateAndTime todayDate;
    Vip customer;
    double totalAccount = 0;
    double totalProfit = 0;

};
/*This is a class used to record and fix each account, including the goods, number, date and custom information. Moreover, it has
virtual method to calculate totalprofit and profit for different objects.*/
