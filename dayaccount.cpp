#include<bits/stdc++.h>
#include"account.h"
#include"dateandtime.h"
#include"discountaccount.h"
#include"goods.h"
#include"supervip.h"
#include"vip.h"
#include"global.h"
#include<fstream>
#include<iostream>
#include<QMessageBox>

using namespace std;

fstream dayio("dayAccount.txt",ios::in|ios::out|ios::binary);

void dayAccount(DateAndTime a,double t,double p)
{
    dayio.seekp(0,ios::end);
    day d;
    int x=dayio.tellp();
    if(x!=0)
    {
        dayio.seekg(x-sizeof(day));
        dayio.read(reinterpret_cast<char*>(&d),sizeof(day));
        if(d.DAT.getYear()==a.getYear()&&d.DAT.getMonth()==a.getMonth()&&d.DAT.getDay()==a.getDay())
        {
            d.total+=t;
            d.profit+=p;
            dayio.seekp(x-sizeof(day));
            dayio.write(reinterpret_cast<char*>(&d),sizeof(day));
            return;
        }
    }
    d.DAT=a;
    d.total=t;
    d.profit=p;
    dayio.seekp(x);
    dayio.write(reinterpret_cast<char*>(&d),sizeof(day));
}

int DayReturnNumberEqualToDAT(DateAndTime a)
{
    dayio.seekg(0,ios::end);
    int left=1,right=dayio.tellg()/sizeof(day),mid=(left+right)/2;
    day R;
    dayio.seekg((left-1) * sizeof (day));
    dayio.read(reinterpret_cast<char *>(&R), sizeof (day));
    if(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()==a.getDay())return left;
    if(R.DAT.getYear()>a.getYear()||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()>a.getMonth())||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()>a.getDay()))return -1;
    dayio.seekg((right-1) * sizeof (day));
    dayio.read(reinterpret_cast<char *>(&R), sizeof (day));
    if(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()==a.getDay())return right;
    if(R.DAT.getYear()<a.getYear()||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()<a.getMonth())||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()<a.getDay()))return -1;
    while(right>left)
    {
        dayio.seekg((mid-1) * sizeof (day));
        dayio.read(reinterpret_cast<char *>(&R), sizeof (day));
        if(R.DAT.getYear()>a.getYear()||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()>a.getMonth())||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()>a.getDay()))right=mid;
        else if(R.DAT.getYear()<a.getYear()||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()<a.getMonth())||(R.DAT.getYear()==a.getYear()&&R.DAT.getMonth()==a.getMonth()&&R.DAT.getDay()<a.getDay()))left=mid+1;
        else return mid;
        mid=(right+left)/2;
    }
    return left;
}

double getTotalDayAccount(DateAndTime a)
{
    int x=DayReturnNumberEqualToDAT(a);
    if(x==-1)return 0;
    day d;
    dayio.seekg((x-1) * sizeof (day));
    dayio.read(reinterpret_cast<char *>(&d), sizeof (day));
    if(d.DAT.getYear()==a.getYear()&&d.DAT.getMonth()==a.getMonth()&&d.DAT.getDay()==a.getDay())return d.total;
    return 0;
}

double getTotalDayProfit(DateAndTime a)
{
    int x=DayReturnNumberEqualToDAT(a);
    if(x==-1)return 0;
    day d;
    dayio.seekg((x-1) * sizeof (day));
    dayio.read(reinterpret_cast<char *>(&d), sizeof (day));
    if(d.DAT.getYear()==a.getYear()&&d.DAT.getMonth()==a.getMonth()&&d.DAT.getDay()==a.getDay())return d.profit;
    return 0;
}
