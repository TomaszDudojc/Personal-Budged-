#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    time_t calculatedTime;
    struct tm * data;
    int MIN_FEASIBLE_YEAR = 2000; //min date 2000-01-01

    string addZeroToDate(string date);
    string addDashToDate(string date);
    bool isLeapYear(int year);
    bool isDateFormatCorrect(string date);
    bool isYearCorrect(int year);
    bool isMonthCorrect(int month, int year);
    bool isDayCorrect(int day, int month, int year);

public:
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    string createCurrentDate();
    int convertStringDateToIntDate(string date);
    string convertIntDateToStringDate (int year, int month, int day);
    bool isDateCorrect(string date);
    int checkNumberOfDaysInMonth(int year, int month);
};

#endif
