#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cstdlib>
#include"Account.h"
#include"dateandtime.h"
#include"global.h"
using namespace std;

//the io file stream that account use.
fstream inOutAccount("AccountRecord.txt", ios::in | ios::out|ios::binary);

//write a new account term into record text.
void writeAccount(Record a)
{
        inOutAccount.seekp(0,ios::end);
        inOutAccount.write(reinterpret_cast<const char*>(&a), sizeof(Record));
}

//change the nth term to the Record a.
void changeAccount(int n,Record a)
{
        inOutAccount.seekg((n-1) * sizeof (Record));
        inOutAccount.read(reinterpret_cast<char *>(&a), sizeof (Record));
        inOutAccount.seekp((n-1) * sizeof (Record));
        inOutAccount.write(reinterpret_cast<const char*>(&a), sizeof (Record));
}

//get the nth term.
Record returnAccount(int n)
{
        Record a;
        inOutAccount.seekg((n-1) * sizeof (Record));
        inOutAccount.read(reinterpret_cast<char *>(&a), sizeof (Record));
        return a;
}

//get the number of the term which is at dateAndTime a or after that term
int returnMinNumberGreaterOrEqualToDAT(DateAndTime a)
{
    inOutAccount.seekg(0,ios::end);
    int left=1,right=inOutAccount.tellg()/sizeof(Record),mid=(left+right)/2;
    Record Record_m;
    inOutAccount.seekg((left-1) * sizeof (Record));
    inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
    if(Record_m.DAT>a||Record_m.DAT==a)return left;
    inOutAccount.seekg((right-1)*sizeof(Record));
    inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
    if(Record_m.DAT==a)return right;
    if(Record_m.DAT<a)return -1;
    while(right>left)
    {
        inOutAccount.seekg((mid-1) * sizeof (Record));
        inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
        if(Record_m.DAT > a)right=mid;
        else if(Record_m.DAT < a)left=mid+1;
        else return mid;
        mid=(right+left)/2;
    }
    return left;
}

//get the number of the term which is at dateAndTime a or earlier that term
int returnMaxNumberSmallerOrEqualToDAT(DateAndTime a)
{
    inOutAccount.seekg(0,ios::end);
    int left=1,right=inOutAccount.tellg()/sizeof(Record),mid=(left+right)/2;
    Record Record_m;
    inOutAccount.seekg((left-1) * sizeof (Record));
    inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
    if(Record_m.DAT==a)return left;
    if(Record_m.DAT>a)return -1;
    inOutAccount.seekg((right-1) * sizeof (Record));
    inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
    if(Record_m.DAT<a||Record_m.DAT==a)return right;
    while(right>left)
    {
        inOutAccount.seekg((mid-1) * sizeof(Record));
        inOutAccount.read(reinterpret_cast<char*>(&Record_m), sizeof (Record));
        if(Record_m.DAT>a)right=mid-1;
        else if(Record_m.DAT<a)left=mid;
        else return mid;
        mid=(right+left+1)/2;
    }
    return left;
}

//use above that two function to get the number of term is between x and y,and then print them to txt.
void printTOtxt(DateAndTime m,DateAndTime n)
{
    if(n<m)
    {
        DateAndTime tmp=m;
        m=n;
        n=tmp;
    }
    ofstream out("accountPrint.txt");
    out<<left<<setw(30)<<"DateAndTime"<<setw(20)<<"Total"<<setw(20)<<"Profit"<<'\n';
    Record a;
    int x=returnMinNumberGreaterOrEqualToDAT(m);
    int y=returnMaxNumberSmallerOrEqualToDAT(n);
    if(x==-1||y==-1)return;
    for(int i=x;i <=y;i++)
    {
        inOutAccount.seekg((i-1) * sizeof(Record));
        inOutAccount.read(reinterpret_cast<char*>(&a), sizeof(Record));
        out<<left<<setw(30)<<a.DAT.returnUniversal()<<fixed<<setprecision(2)
          <<setw(20)<<a.total<<setw(20)<<a.profit<<'\n';
    }
}
