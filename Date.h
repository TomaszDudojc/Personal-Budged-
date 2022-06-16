#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
    string date;
    string year;
    string month;
    string day;

public:
    Date(string date="")
    {
        this->date = date;
    }

    void setYear(string newYear);
    void setMonth(string newMonth);
    void setDay(string newDay);

    string getDate();
    string getYear();
    string getMonth();
    string getDay();
};

#endif
