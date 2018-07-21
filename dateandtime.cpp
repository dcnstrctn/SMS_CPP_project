#include"DateAndTime.h"

#include<iostream>
#include<iomanip>
#include<QMessageBox>

using namespace std;
//check if the year is leap.
bool LeapCheck(int y)
{
    if (y % 100 != 0 && y % 4 == 0)
        return 1;
    if (y % 3200 != 0 && y % 400 == 0)
        return 1;
    if (y % 172800 == 0)
        return 1;
    return 0;
}
//check if the day is legal.
bool daycheck(int m, int d, int y)
{
    return ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31) || (m == 2 && ((LeapCheck(y) && d <= 29) || (!LeapCheck(y) && d <= 28))) || d <= 30;
}

//constructor
DateAndTime::DateAndTime(int y, int mn, int d, int h, int mi, int s)
{
    setYear(y);
    setMonth(mn);
    setDay(y,mn,d);
    setHour(h);
    setMinute(mi);
    setSecond(s);
}

//set the year to y.
void DateAndTime::setYear(int y)
{
    year = y;
}

//set the month to m and check if it is legal.
void DateAndTime::setMonth(int m)
{
    if (m > 0 && m <= 12)
        month = m;
    else
    {
        QMessageBox::warning(0, "Warning", "Month must be 1-12.", QMessageBox::Yes);
        month = 1;
    }
}

//set the day and check if it is legal.
void DateAndTime::setDay(int y,int m,int d)
{
    if (d >= 1 && daycheck(m, d, y))
    {
        day = d;
    }
    else
    {
        QMessageBox::warning(0, "Warning", "Day is illegal.", QMessageBox::Yes);
        day = 1;
    }
}

//set the hour and check if it is legal.
void DateAndTime::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
    {
        QMessageBox::warning(0, "Warning", "Hour must be 0-23.", QMessageBox::Yes);
        hour = 0;
    }
}

//set the minute and check if it is legal.
void DateAndTime::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
    {
        QMessageBox::warning(0, "Warning", "Illegal minute.", QMessageBox::Yes);
        minute = 0;
    }
}

//set the member second and check if it is legal.
void DateAndTime::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
    {
        QMessageBox::warning(0, "Warning", "Illegal second.", QMessageBox::Yes);
        second = s;
    }

}

//get the member year.
int DateAndTime::getYear() const
{
    return year;
}

//get the member month.
int DateAndTime::getMonth() const
{
    return month;
}

//get the member day.
int DateAndTime::getDay() const
{
    return day;
}

//get the member hour.
int DateAndTime::getHour() const
{
    return hour;
}

//get the member minute.
int DateAndTime::getMinute() const
{
    return minute;
}

//get the member second.
int DateAndTime::getSecond() const
{
    return second;
}

//return the date and time as a string in universal pattern.
string DateAndTime::returnUniversal() const
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year) +" " +
        to_string(getHour()) + ":"
        +to_string(getMinute())+ ":" +to_string(getSecond());
}

//return the date and time as a string in standard pattern.
string DateAndTime::returnStandard() const
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " "
        + to_string((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        + ":" +to_string( getMinute())
            + ":" +to_string( getSecond()) + (hour < 12 ? " AM" : " PM");
}

//only return the date.
string DateAndTime::returnDate() const
{
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}

//overload the operator == to check if two DateAndTime object is the same.
bool operator==(DateAndTime a,DateAndTime b)
{
    return a.getYear()==b.getYear()&&a.getMonth()==b.getMonth()&&a.getDay()==b.getDay()
            &&a.getHour()==b.getHour()&&a.getMinute()==b.getMinute()&&a.getSecond()==b.getSecond();
}

//overload the operator > to check which of two DateAndTime object is larger or later.
bool operator >(DateAndTime a,DateAndTime b)
{
    if(a.getYear()!=b.getYear())return(a.getYear()>b.getYear());
    if(a.getMonth()!=b.getMonth())return(a.getMonth()>b.getMonth());
    if(a.getDay()!=b.getDay())return(a.getDay()>b.getDay());
    if(a.getHour()!=b.getHour())return(a.getHour()>b.getHour());
    if(a.getMinute()!=b.getMinute())return(a.getMinute()>b.getMinute());
    if(a.getSecond()!=b.getSecond())return(a.getSecond()>b.getSecond());
    return 0;
}

//overload the operator < to check which of two DateAndTime object is smaller or earlier.
bool operator <(DateAndTime a,DateAndTime b)
{
    return !(a>b||a==b);
}
