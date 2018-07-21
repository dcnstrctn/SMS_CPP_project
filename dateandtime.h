#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include"dateandtime.h"
#include<string>
/*
    A class which is the base class to express the date and the time the goods be bought, the account done,etc.
*/
class DateAndTime
{
public:
    explicit DateAndTime(int = 0, int = 1, int = 1, int = 0, int = 0, int = 0);

    void setYear(int);
    void setMonth(int);
    void setDay(int,int,int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    int getYear()const;
    int getMonth()const;
    int getDay()const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    std::string returnUniversal() const;
    std::string returnStandard() const;
    std::string returnDate() const;

    friend bool operator ==(DateAndTime a,DateAndTime b);
    friend bool operator >(DateAndTime a,DateAndTime b);
    friend bool operator <(DateAndTime a,DateAndTime b);

private:
    unsigned int month, day, year, hour, minute, second;
};

#endif
