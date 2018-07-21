#ifndef SUPERVIP_H
#define SUPERVIP_H
#include"VIP.h"
#include"dateandtime.h"

/*This is a derived class inherit basic class vip, which is used to record information for super vips. Compared to vip, super
vip has dicount and birthday discount, so it has overrided function to calculate these discount.*/
class SuperVip : public Vip
{
public:
    SuperVip(const std::string & = "", const std::string & = "",
        const DateAndTime & = DateAndTime(), int = 0, int = 0);

    double getVipDiscount() const;
    void setVipDiscount();
    void setVipBirthdayDiscount(double);
private:
    double vipDiscount;//SuperVIP discount
    double vipBirthdayDiscount = 0.9;
};
#endif
