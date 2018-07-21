#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<QMessageBox>
#include"global.h"


#include"goods.h"
using namespace std;

//intitialize the goods.txt.
void initializeGoods()
{
    ofstream inOutGoods("Goods.txt",ios::out | ios::binary);
    Goods g;
    for( int i = 0;i<2000;i++)
    {
        inOutGoods.seekp(i*sizeof(Goods));
        inOutGoods.write(reinterpret_cast<char*>(&g),sizeof(Goods));
    }

}

//write a new term into the txt.
void writeGoods(Goods a)
{
    fstream inOutGoods("Goods.txt", ios::in | ios::out | ios::binary);
    if(!inOutGoods)
        QMessageBox::warning(0, "Warning", "Unable to open file. ", QMessageBox::Yes);
    Goods g;
    int place = a.getNumber() * sizeof(Goods);
    inOutGoods.seekg(place);
    inOutGoods.read(reinterpret_cast<char*>(&g), sizeof(Goods));
    if (g.getName() == "")
    {
        inOutGoods.seekp(place);//remove to the original place
        inOutGoods.write(reinterpret_cast<const char*>(&a), sizeof(Goods));
        QMessageBox::information(0, "Succeed",
                                 ("New commodity has been added. "),
                                 QMessageBox::Yes);
    }
    else
        QMessageBox::warning(0, "Warning",
                                 "The number has been occupied. ",
                                 QMessageBox::Yes);
}

//change the goods a.
void changeGoods(Goods a)
{
    fstream inOutGoods("Goods.txt", ios::in | ios::out | ios::binary);

    inOutGoods.seekp(a.getNumber() * sizeof(Goods));
    inOutGoods.write(reinterpret_cast<const char*>(&a), sizeof(Goods));


}

//delete the nth goods.
void deleteGoods(int n)
{
    fstream inOutGoods("Goods.txt", ios::in | ios::out | ios::binary);
    Goods a;
    inOutGoods.seekg(n * sizeof(Goods));
    inOutGoods.read(reinterpret_cast<char *>(&a), sizeof(Goods));
    if (a.getName() != "")
    {
        Goods b;
        inOutGoods.seekp(a.getNumber() * sizeof(Goods));
        inOutGoods.write(reinterpret_cast<const char*>(&b), sizeof(Goods));
    }
    else
        QMessageBox::warning(0, "Warning",
                                 "No such commodity. ",
                                 QMessageBox::Yes);

}

//get the nth goods.
Goods getGoods(int n)
{
    fstream inOutGoods("Goods.txt", ios::in | ios::out | ios::binary);
    Goods a;
    inOutGoods.seekg(n * sizeof(Goods));
    inOutGoods.read(reinterpret_cast<char *>(&a), sizeof(Goods));
    if (a.getName() != "")
    {
        return a;
    }
    else
    {
        QMessageBox::warning(0, "Warning",
                                 "No such commodity. ",
                                 QMessageBox::Yes);
        return a;
    }
}

//print all goods to txt.
void printTotxt()
{
    ifstream inOutGoods("Goods.txt", ios::in | ios::binary);
    ofstream out("stockInformation.txt", ios::out);
    out<<left<<setw(10)<<"Number"
      <<left<<setw(19)<<"Name"
      <<right<<setw(10)<<"Cost"
     <<right<<setw(12)<<"Price"
     <<right<<setw(16)<<"Quantity\n";

    Goods a;
    for(int i=0;i<2000;i++)
    {
        inOutGoods.seekg(i * sizeof(Goods));
        inOutGoods.read(reinterpret_cast<char *>(&a), sizeof(Goods));
        if(a.getName()=="")
            continue;
        out<<left<<setw(10)<<a.getNumber()
          <<left<<setw(19)<<a.getName()
          <<right<<setw(10)<<a.getCost()
         <<right<<setw(12)<<a.getprice()
         <<right<<setw(15)<<a.getquantity()<<'\n';

    }
}


