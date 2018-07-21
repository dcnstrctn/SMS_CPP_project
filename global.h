#ifndef GLOBAL_H
#define GLOBAL_H
#include<QString>
#include<goods.h>
#include<fstream>
#include"dateandtime.h"
#include"supervip.h"
#include"discountaccount.h"

using namespace std;
extern QString password;//store password
extern double holidayDiscount;

//functions for Goods
void writeGoods(Goods a);
void changeGoods(Goods a);
void deleteGoods(int);
Goods getGoods(int);
void initializeGoods();
void printTotxt();

//function for getting current time
DateAndTime getNow();

//functions for Vips
bool searchVip(std::string x);
void addmember(Vip v);
Vip findvip(std::string x);
void changevip(std::string x, Vip y);
void deletevip(std::string x);
void vipPrint();

bool searchSvip(std::string x);
void addSmember(SuperVip v);
SuperVip findSvip(std::string x);
void changeSvip(std::string x, SuperVip y);
void deleteSvip(std::string x);
void svipPrint();

//functions for account
struct Record
{
    DateAndTime DAT;
    double total,profit;
};
void writeAccount(Record a);

void printTOtxt(DateAndTime m,DateAndTime n);

//functions for Daily Account
struct day
{
    DateAndTime DAT;
    double total,profit;
};
void dayAccount(DateAndTime a,double t,double p);
double getTotalDayAccount(DateAndTime a);
double getTotalDayProfit(DateAndTime a);

//functions for Monthly Account
struct month
{
    DateAndTime DAT;
    double total,profit;
};

void monthAccount(DateAndTime a, double t,double p);
double getTotalMonthAccount(DateAndTime a);
double getTotalMonthProfit(DateAndTime a);

#endif // GLOBAL_H
