//
//  main_f.cpp
//  PD_03_1
//
//  Created by Eriks Karklins on 11/02/2023.
//

#include <iostream>
#include "Header.h"

using namespace std;

Date::Date(int d, int m, int y)
{
     setDate(d, m, y);
}

void Date::setDate (int d, int m, int y)
{
  day = (d >= 0 && d <=31) ? d : 0;
  month = (m >=0 && m <=12) ? m : 0;
  year = (y >=0 && y <=9999) ? y:0;
}

void Date::nextDay()
{
    setDate(day+1, month, year);
}

void Date::printDate()
{
   cout  << day << "." << month << "." << year<<endl;
}
