#include "DateManager.h"

string DateManager::addZeroToDate(string date)
{
    string dateWithZero;
    if (date.size()==1) dateWithZero=date.insert (0,1,'0');
    else dateWithZero=date;

    return dateWithZero;
}

string DateManager::addDashToDate(string date)
{
    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');

    return stringDateWithDash;
}

string DateManager::convertIntDateToStringDate(int year, int month, int day)
{
    //convert intDate e.g (int year=2022, int month=1, int day=15) to stringDate 2022-01-15//
    //-------------------------------------------------------------------------------------//
    string stringYear, stringMonth, stringDay,  stringDate;
    stringYear=AuxiliaryMethods::convertIntegerToString(year);
    stringMonth=AuxiliaryMethods::convertIntegerToString(month);
    stringMonth=addZeroToDate(stringMonth);
    stringDay=AuxiliaryMethods::convertIntegerToString(day);
    stringDay=addZeroToDate(stringDay);
    stringDate=stringYear+stringMonth+stringDay;
    stringDate=addDashToDate(stringDate);

    return stringDate;
}

int DateManager::getCurrentYear()
{
    time_t calculatedTime;
    struct tm * data;
    int year;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    year = data -> tm_year+1900;

    return year;
}

int DateManager::getCurrentMonth()
{
    time_t calculatedTime;
    struct tm * data;
    int month;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    month = data -> tm_mon+1;

    return month;
}

int DateManager::getCurrentDay()
{
    time_t calculatedTime;
    struct tm * data;
    int day;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    day = data -> tm_mday;

    return day;
}

string DateManager::createCurrentDate()
{
    int year, month, day;
    string currentDate;
    year = getCurrentYear();
    month = getCurrentMonth();
    day = getCurrentDay();
    currentDate=convertIntDateToStringDate(year,month,day);

    return currentDate;
}

int DateManager::convertStringDateToIntDate (string date)
{
   //convert stringDate e.g 2022-01-15 to intDate 20220115 //
  //------------------------------------------------------//
    int intDate = (date[0]-'0')*10000000 + (date[1]-'0')*1000000 + (date[2]-'0')*100000 + (date[3]-'0')*10000 + (date[5]-'0')*1000 + (date[6]-'0')*100 + (date[8]-'0')*10 + (date[9]-'0');

    return intDate;
}

bool DateManager::isLeapYear(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    else return false;
}
int DateManager::checkNumberOfDaysInMonth(int year, int month)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
        if (isLeapYear(year)) return 29;
        else return 28;
        break;

    default:
        cout<<"Uncorrect number of month!";
    }
}

bool DateManager::isDateCorrect(string date)
{
    if (date.size()!=10)
    {
        cout<<"Incorrect date! "<<endl;
        return false;
    }
    else
    {
        int year = AuxiliaryMethods::convertStringToInteger(date.substr(0,4));
        int month = AuxiliaryMethods::convertStringToInteger(date.substr(5,2));
        int day = AuxiliaryMethods::convertStringToInteger(date.substr(8,2));

        if (isDateFormatCorrect(date)==false || isYearCorrect(year)==false || isMonthCorrect(month,year)==false  || isDayCorrect(day,month,year)==false)
        {
            cout<<"Incorrect date! "<<endl;
            return false;
        }
    }
    return true;
}

bool DateManager::isDateFormatCorrect(string date)
{
    for (int i=5; i<=6; i++)
    {
        if (date[i]<'0' || date[i]>'9') return false;
    }

    for (int i=8; i<=9; i++)
    {
        if (date[i]<'0' || date[i]>'9') return false;
    }

    if (date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    return true;
}

bool DateManager::isYearCorrect(int year)
{
    if (year>getCurrentYear() || year<MIN_FEASIBLE_YEAR)
    {
        return false;
    }
    return true;
}

bool DateManager::isMonthCorrect(int month, int year)
{
    if(month<1 || month>12 ||(year==getCurrentYear() && month>getCurrentMonth()))//max feasible date = last day of current month
    {
        return false;
    }
    return true;
}

bool DateManager::isDayCorrect(int day, int month, int year)
{
    if (day<1 || day>checkNumberOfDaysInMonth(year, month))
    {
        return false;
    }
    return true;
}
