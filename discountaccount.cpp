#include "discountAccount.h"
#include"dateAndTime.h"
#include"SuperVIP.h"
#include"Account.h"


DiscountAccount::DiscountAccount(SuperVip sVIP)
    :sCustomer(sVIP)
{

}

double DiscountAccount::calculateTotal()
{
    totalAccount = sCustomer.getVipDiscount()*Account::calculateTotal();
    return totalAccount;
}

void DiscountAccount::addPoint()
{
    sCustomer.increasePoint(static_cast<int>(totalAccount));
    sCustomer.setVipDiscount();//update discount
}

SuperVip DiscountAccount::getSMember() const
{
    return sCustomer;
}
