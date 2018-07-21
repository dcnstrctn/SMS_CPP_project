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

using namespace std;

//the io file stream that month account use.
fstream monthio("monthAccount.txt",ios::in|ios::out|ios::binary);

//the function to take the total account t and the profit p into the dayAccount of the dateAndTime a
void monthAccount(DateAndTime a, double t,double p)
{
    monthio.seekp(0,ios::end);
    month m;
    int x=monthio.tellp();
    if(x!=0)
    {
        monthio.seekg(x-sizeof(month));
        monthio.read(reinterpret_cast<char*>(&m),sizeof(month));
        if(m.DAT.getYear()==a.getYear()&&m.DAT.getMonth()==a.getMonth())
        {
            m.total+=t;
            m.profit+=p;
            monthio.seekp(x-sizeof(month));
            monthio.write(reinterpret_cast<char*>(&m),sizeof(month));
            return;
        }
    }
    m.DAT=a,m.total=t,m.profit=p;
    monthio.seekp(0,ios::end);
    monthio.write(reinterpret_cast<char*>(&m),sizeof(month));
}

//the function which use binary search to find the number of terms the dateAndTime a in
//or no such a return -1.
int MonthReturnMinNumberLargerOrEqualToDAT(DateAndTime a)
{
    monthio.seekg(0,ios::end);
    int left=1,right=monthio.tellg()/sizeof(month),mid=(left+right)/2;
    month Record_m;
    monthio.seekg((left-1) * sizeof (month));
    monthio.read(reinterpret_cast<char *>(&Record_m), sizeof (month));
    if(Record_m.DAT==a)return left;
    if(Record_m.DAT.getYear()>a.getYear()||(Record_m.DAT.getYear()==a.getYear()&&Record_m.DAT.getMonth()>a.getMonth()))return -1;
    monthio.seekg((right-1) * sizeof (month));
    monthio.read(reinterpret_cast<char *>(&Record_m), sizeof (month));
    if(Record_m.DAT.getYear()<a.getYear()||(Record_m.DAT.getYear()==a.getYear()&&Record_m.DAT.getMonth()<a.getMonth()))return -1;
    if(Record_m.DAT==a)return right;
    while(right>left)
    {
        monthio.seekg((mid-1) * sizeof (month));
        monthio.read(reinterpret_cast<char *>(&Record_m), sizeof (month));
        if(Record_m.DAT.getYear()>a.getYear()||(Record_m.DAT.getYear()==a.getYear()&&Record_m.DAT.getMonth()>a.getMonth()))right=mid;
        else if(Record_m.DAT.getYear()<a.getYear()||(Record_m.DAT.getYear()==a.getYear()&&Record_m.DAT.getMonth()<a.getMonth()))left=mid+1;
        else return mid;
        mid=(right+left)/2;
    }
    return left;
}

//use getTotalDayAccount to get its number of term and then its term, and get TotalDayAccount from its term.
double getTotalMonthAccount(DateAndTime a)
{
    int x=MonthReturnMinNumberLargerOrEqualToDAT(a);
    if(x==-1)return 0;
    month m;
    monthio.seekg((x-1) * sizeof (month));
    monthio.read(reinterpret_cast<char *>(&m), sizeof (month));
    if(m.DAT.getYear()==a.getYear()&&m.DAT.getMonth()==a.getMonth())return m.total;
    return 0;
}

//use getTotalDayAccount to get its number of term and then its term, and get TotalDayProfit from its term.
double getTotalMonthProfit(DateAndTime a)
{
    int x=MonthReturnMinNumberLargerOrEqualToDAT(a);
    if(x==-1)return 0;
    month m;
    monthio.seekg((x-1) * sizeof (month));
    monthio.read(reinterpret_cast<char *>(&m), sizeof (month));
    if(m.DAT.getYear()==a.getYear()&&m.DAT.getMonth()==a.getMonth())return m.profit;
    return 0;
}
