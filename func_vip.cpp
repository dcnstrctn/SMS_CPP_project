#include<iostream>
#include<fstream>
#include<string>
#include<QMessageBox>
#include<iomanip>
#include"vip.h"
#include"supervip.h"
#include"global.h"
#include<ctime>
using namespace std;
//get now date and time as an DateAndTime.
DateAndTime getNow()
{
    time_t t = time(0);
    tm* tt = localtime(& t);
    return DateAndTime((tt->tm_year) + 1900,tt->tm_mon+1,tt->tm_mday,tt->tm_hour,tt->tm_min,tt->tm_sec);
}

//search vip from his or her phone number.
bool searchVip(string x)
{
    Vip a;
    fstream V("VIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(Vip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(Vip));
        if (a.getPhoneNumber() == x)
        {
            return true;
        }
    }
    return false;
}

//add new vip member.
void addmember(Vip v)
{
    fstream V("VIP.txt", ios::in | ios::out | ios::binary);

    if (searchVip(v.getPhoneNumber())) //check if there is the same number
    {
        QMessageBox::warning(0, "Warning",
                                 ("This phone number has been occupied. "),
                                 QMessageBox::Yes);
    }
    else
    {
        V.seekg(0, ios::end);
        V.write(reinterpret_cast<const char*>(&v), sizeof(Vip));
        QMessageBox::information(0, "Succeed",
                                     ("New vip member "+QString::fromStdString(v.getName())+" has been added. "),
                                     QMessageBox::Yes);
    }
}
//Add new objects for the two files.

Vip findvip(string x)
{
	Vip a;
	fstream V("VIP.txt", ios::in | ios::out | ios::binary);
	while (!V.eof())
	{
        V.read(reinterpret_cast<char*>(&a), sizeof(Vip));
        if (a.getPhoneNumber() == x)
		{
			break;
        }
    }
    if(V.eof())
    {
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);
        Vip b = Vip();
        return b;
    }
    return a;
}

//Find the object according to the phone number
void changevip(string x, Vip y)
{
	Vip a;
    fstream V("VIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(Vip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(Vip));
        if (a.getPhoneNumber() == x)
        {
            V.seekp(sizeof(Vip)*(i-1));
            V.write(reinterpret_cast<const char*>(&y),sizeof(Vip));
            QMessageBox::information(0, "Succeed",
                                     ("Vip member "+QString::fromStdString(y.getName())+" has been modified. "),
                                     QMessageBox::Yes);
            break;
        }

    }
    if(V.eof())
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);
}

//Change the object
void deletevip(string x)
{
    Vip a;
    Vip y;
    fstream V("VIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(Vip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(Vip));
        if (a.getPhoneNumber() == x)
        {
            V.seekp(sizeof(Vip)*(i-1));
            V.write(reinterpret_cast<const char*>(&y),sizeof(Vip));
            QMessageBox::information(0, "Deleted",
                                     ("Vip member "+QString::fromStdString(a.getName())+" has been deleted. "),
                                     QMessageBox::Yes);
            break;
        }

    }
    if(V.eof())
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);
}
//Delete an vip object

void vipPrint()
{
    ifstream inFile("VIP.txt",ios::in);
    ofstream outFile("memberInformation.txt", ios::out);

    outFile<<left<<setw(19)<<"Name"
          <<left<<setw(15)<<"Phone Number"
         <<left<<setw(15)<<"Birthday"
        <<right<<setw(5)<<"Points"
       <<right<<setw(20)<<"Total Points\n";

    Vip a;
    inFile.read(reinterpret_cast<char *>(&a), sizeof(Vip));
    while(!inFile.eof())
    {
        if(a.getName() != "")
        {
            outFile<<left<<setw(19)<<a.getName()
                  <<left<<setw(15)<<a.getPhoneNumber()
                  <<left<<setw(15)<<a.getBirthday().returnDate()
                 <<right<<setw(5)<<a.getPoint()
                 <<right<<setw(20)<<a.getTotalPoint()<<'\n';
        }
        inFile.read(reinterpret_cast<char *>(&a), sizeof(Vip));

    }
}
//print all the vip informations to txt file



/*Functions for supervip*/
bool searchSvip(std::string x)
{
    SuperVip a;
    fstream V("SUPERVIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(SuperVip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(SuperVip));
        if (a.getPhoneNumber() == x)
        {
            return true;
        }
    }
    return false;
}

void addSmember(SuperVip v)
{
    fstream V("SUPERVIP.txt", ios::in | ios::out | ios::binary);

    if (searchSvip(v.getPhoneNumber())) //check if there is the same number
    {
        QMessageBox::warning(0, "Warning",
                                 ("This phone number has been occupied. "),
                                 QMessageBox::Yes);
    }
    else
    {

        V.seekg(0, ios::end);
        V.write(reinterpret_cast<const char*>(&v), sizeof(SuperVip));
        QMessageBox::information(0, "Succeed",
                                ("New vip member "+QString::fromStdString(v.getName())+" has been added. "),
                                     QMessageBox::Yes);

    }

}

SuperVip findSvip(string x)
{
    SuperVip a;
    fstream V("SUPERVIP.txt", ios::in | ios::out | ios::binary);
    while (!V.eof())
    {
        V.read(reinterpret_cast<char*>(&a), sizeof(SuperVip));
        if (a.getPhoneNumber() == x)
        {
            break;
        }
    }
    if(V.eof())
    {
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);
        SuperVip b = SuperVip();
        return b;
    }
    return a;
}

void changeSvip(std::string x, SuperVip y)
{
    SuperVip a;
    fstream V("SUPERVIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(SuperVip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(SuperVip));
        if (a.getPhoneNumber() == x)
        {
            V.seekp(sizeof(SuperVip)*(i-1));
            V.write(reinterpret_cast<const char*>(&y),sizeof(SuperVip));
            QMessageBox::information(0, "Succeed",
                                     ("Supervip member "+QString::fromStdString(y.getName())+" has been modified. "),
                                     QMessageBox::Yes);
            break;
        }

    }
    if(V.eof())
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);

}

void deleteSvip(std::string x)
{
    SuperVip a;
    SuperVip y;
    fstream V("SUPERVIP.txt", ios::in | ios::out | ios::binary);
    int i = 0;
    while (!V.eof())
    {
        V.seekg(sizeof(SuperVip)*i++);
        V.read(reinterpret_cast<char*>(&a), sizeof(SuperVip));
        if (a.getPhoneNumber() == x)
        {
            V.seekp(sizeof(SuperVip)*(i-1));
            V.write(reinterpret_cast<const char*>(&y),sizeof(SuperVip));
            QMessageBox::information(0, "Deleted",
                                     ("Supervip member "+QString::fromStdString(a.getName())+" has been deleted. "),
                                     QMessageBox::Yes);
            break;
        }

    }
    if(V.eof())
        QMessageBox::warning(0, "Warning",
                                 ("No such member. Please check the phone number. "),
                                 QMessageBox::Yes);
}

void svipPrint()
{
    ifstream inFile("SUPERVIP.txt",ios::in);
    ofstream outFile("supermemberInformation.txt", ios::out);

    outFile<<left<<setw(19)<<"Name"
          <<left<<setw(15)<<"Phone Number"
         <<left<<setw(15)<<"Birthday"
        <<right<<setw(5)<<"Points"
       <<right<<setw(20)<<"Total Points"
      <<right<<setw(20)<<"Vip Discount\n";

    SuperVip a;
    inFile.read(reinterpret_cast<char *>(&a), sizeof(SuperVip));
    while(!inFile.eof())
    {
        if(a.getName() != "")
        {
            outFile<<left<<setw(19)<<a.getName()
                  <<left<<setw(15)<<a.getPhoneNumber()
                  <<left<<setw(15)<<a.getBirthday().returnDate()
                 <<right<<setw(5)<<a.getPoint()
                 <<right<<setw(20)<<a.getTotalPoint()
                <<right<<setw(20)<<a.getVipDiscount()<<'\n';
        }
        inFile.read(reinterpret_cast<char *>(&a), sizeof(SuperVip));

    }
}
