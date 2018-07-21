#include<string>
#include"Vip.h"
using namespace std;

//constructor
Vip::Vip(const std::string & n,
    const std::string & pn, const DateAndTime & bDay, int po, int tp)
    :birthday(bDay), point(po), totalPoint(tp)
{
	setName(n);
	setPhoneNumber(pn);
}
//end constructor

//set name value
void Vip::setName(const std::string & nameString)
{
	int length = nameString.size();
	length = (length < 20 ? length : 19);
	for (int i = 0; i < length; i++)
	{
		name[i] = nameString[i];
	}
	name[length] = '\0';
}
//end function setName

//get name value
string Vip::getName()const
{
    return name;
}
//end function getName

//set phone number value
void Vip::setPhoneNumber(const std::string & phoneString)
{
	int length = phoneString.size();
	length = (length < 12 ? length : 11);
	for (int i = 0; i < length; i++)
	{
		phoneNumber[i] = phoneString[i];
	}
	phoneNumber[length] = '\0';
}
//end function setPhoneNumber

//get phone number value
string Vip::getPhoneNumber()const
{
    return phoneNumber;
}
//end function getPhoneNumber

//set birthday
void Vip::setBirthday(DateAndTime y)
{
    birthday = y;
}


DateAndTime Vip::getBirthday() const
{
    return birthday;
}

//When a purchasing is done, add corresponding points to the member.
void Vip::increasePoint(int a)
{
    point += a;
    totalPoint += a;
    //在增加积分的时候保留总积分的记录以进行supervip的折扣判断
}
//end increasePoint function

//When the member exchanges a gift from the points, the points is substracted.
void Vip::decreasePoint(int a)
{
    point -= a;
}
//end decreasePoint function


int Vip::getPoint() const
{
    return point;
}

int Vip::getTotalPoint() const
{
    return totalPoint;
}
