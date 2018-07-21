#ifndef VIP_H
#define VIP_H
#include<string>
#include"dateandtime.h"

/*A basic class Vip to store personal information for all customers, including name, phonenumber, birthday, point, and total point,
every object in this class represents one customer*/
class Vip
{
public:

    Vip(const std::string & ="",
        const std::string & = "", const DateAndTime & = DateAndTime(), int = 0, int = 0);

    void setName(const std::string &);
    std::string getName() const;

    void setPhoneNumber(const std::string &);
    std::string getPhoneNumber() const;

    void setBirthday(DateAndTime);
    DateAndTime getBirthday() const;

    void increasePoint(int);
    void decreasePoint(int);

    int getPoint() const;
    int getTotalPoint() const;
private:
    char name[20];
    char phoneNumber[12];
    DateAndTime birthday;
    int point;
    int totalPoint;
    //记录历史总积分 用于决定SuperVIP的打折问题
};

#endif // VIP_H
