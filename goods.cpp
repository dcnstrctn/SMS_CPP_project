#include"Goods.h"
#include<iostream>
#include<string>
using namespace std;

Goods::Goods(string x, int n, int q, double c, double p)
    :number(n), quantity(q), cost(c), price(p)
{
    setName(x);//set name char[] with string

}

void Goods::setName(const string &n)
{
    int length = n.size();
    length = (length<20? length : 19);
    for (int i = 0; i < length; i++)
    {
        name[i] = n[i];
    }
    name[length] = '\0';
}

void Goods::setquantity(int q)
{
    quantity = q;
}

void Goods::setcost(double c)
{
    cost = c;
}

void Goods::setprice(double p)
{
    price = p;
}


string Goods::getName()
{
    return name;
}

double Goods::getprice()
{
    return price;
}

int Goods::getquantity()
{
return quantity;
}

double 	Goods::getCost()
{
    return cost;
}

int Goods::getNumber()
{
    return number;
}


