#include <iostream>
#include "Header.h"

using namespace std;

Date::Date()
{
   day=month=year = 0;
}

void Date::setDate (int d, int m, int y)
{
  day = (d >= 0 && d <=31) ? d : 0;
  month = (m >=0 && m <=12) ? m : 0;
  year = (y >=0 && y <=9999) ? y:0;
}

void Date::nextDay (int d, int m, int y)
{

    setDate(day+1, month, year);
 
}

void Date::printDate()
{
   cout << (day < 10 ? "0" : "") << day << "."
        << (month < 10 ? "0" : "") << month << "."
        << (year < 10 ? "0" : "") << year<<endl;
}
