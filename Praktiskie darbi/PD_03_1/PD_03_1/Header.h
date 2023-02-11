//
//  Header.h
//  PD_03_1
//
//  Created by Eriks Karklins on 11/02/2023.
//

#ifndef Header_h
#define Header_h

class Date// izveidota klase "DATE"
{
public:// publiskā daļa
    Date(int=12, int = 13, int = 1900);// klases konstruktors
    void setDate(int, int, int);
    void nextDay();
    void printDate();

private:// privātā daļa, piekļuve caur publisko daļu
   int day;
   int month;
   int year;
};

#endif /* Header_h */
