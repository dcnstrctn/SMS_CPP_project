#include "Account.h"
#include"Vip.h"
#include"dateAndTime.h"
#include"Goods.h"
#include"global.h"
#include<vector>

Account::Account(Vip customer)
    :customer(customer)
{
    todayDate=getNow();
}
//Constructor for users to initialize data members
void Account::addGoods(Goods &a, int quan)//The number of goods is manually entered by the salesperson. The default is 1
{
    goodArray[numberOfGoods] = a;
    goodQuantity[numberOfGoods] = quan;
    numberOfGoods++;
}
//Add goods to the account
double  Account::calculateTotal()
{
    for (int i = 0; i < numberOfGoods; ++i)
        totalAccount += goodQuantity[i]*goodArray[i].getprice();
    return totalAccount;
 }
//Calculate the total price
double  Account::calculateProfit()
{
    double costTotal=0;
    for (int i = 0; i < numberOfGoods; ++i)
        costTotal += goodQuantity[i]*goodArray[i].getCost();
    totalProfit = totalAccount - costTotal;
    return totalProfit;
}
//Caculate the total profit
void Account::addPoint()
{
    customer.increasePoint(static_cast<int>(totalAccount));
}
//Add points of vips according to goods they buy
void Account::setTotalAccount(double total)
{
    totalAccount = total;
}
//Set total account
double Account::getTotalAccount()const
{
    return totalAccount;
}
//Get total account
double Account::getTotalProfit()const
{
    return totalProfit;
}
//Get total profit
std::string Account::getcustomernumber()const
{
    return customer.getPhoneNumber();
}
//Get the phonenumber of customers
DateAndTime Account::getDateAndTime() const
{
	DateAndTime tmp = todayDate;
    return tmp;
}
//Get the date and time when the account is created
int Account::getNumberOfGoods() const
{
    return numberOfGoods;

}
//Get the number of goods
Vip Account::getMember() const
{
    return customer;
}
//Get the customer information

