#include"supervip.h"
#include"global.h"

//Constructor allow users to initialize data members
SuperVip::SuperVip(const std::string &n, const std::string &pn,
    const DateAndTime &bDay, int po, int tp)//最后两个分别是积分和总积分
    :Vip(n, pn, bDay, po, tp)
{
    setVipDiscount();
}


double SuperVip::getVipDiscount() const
{
    return vipDiscount;
}
//Get the discount for super vip

void SuperVip::setVipDiscount()
{
    vipDiscount = 0.95 - 0.01*(getTotalPoint() / 2000);
    if (vipDiscount < 0.8)
        vipDiscount = 0.8;
    //not below 80%
    DateAndTime tod=getNow();
    if(tod.getMonth()==getBirthday().getMonth() && tod.getDay()==getBirthday().getDay())
            vipDiscount*=vipBirthdayDiscount;
    //set additional discount if it is his birthday
}

//A function to set the discount and birthday discount by the total points they have, and ensure that discount is no less than twenty percent.
void SuperVip::setVipBirthdayDiscount(double x)
{
    vipBirthdayDiscount=x;
}
//Allow to set birthday discount respectively
