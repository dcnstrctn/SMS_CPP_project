#ifndef GOODS_H
#define GOODS_H
#include<string>
/*A basic class named Goods to store all the information about goods,
every object in this class represents one type of goods with its name, quantity, price, cost, and number.*/
class Goods
{
public:
    Goods(std::string = "", int = 0, int = 0, double = 0.0, double = 0.0);

    void setName(const std::string &);
    void setquantity(int q);
    void setcost(double c);
    void setprice(double p);

    std::string getName();
    double getprice();
    int getquantity();
    double getCost();
    int getNumber();


private:
    char name[20];
    int number;
    int quantity;
    double cost;
    double price;

};

#endif
