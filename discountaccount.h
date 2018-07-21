#pragma once
#include"SuperVIP.h"
#include "Account.h"
#include"dateAndTime.h"
#include"Vip.h"

//说明：DiscountAccount用来计算super vip的账单，构造函数改成只有两个参数，
//这时候从account基类继承来的vip对象是默认值，被隐藏起来
class DiscountAccount :
    public Account
{
public:
    DiscountAccount(SuperVip);

    double calculateTotal()override;
    void addPoint()override;
    SuperVip getSMember() const;
private:
    SuperVip sCustomer;
};

