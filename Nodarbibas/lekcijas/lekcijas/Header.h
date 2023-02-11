//
//  Header.h
//  lekcijas
//
//  Created by Eriks Karklins on 11/02/2023.
//

#ifndef Header_h
#define Header_h

class Date
{
public:
   Date();
    void setDate(int, int, int);
    void nextDay(int, int, int);
    void printDate();

private:
   int day;   // 0-31
   int month; // 0-12
   int year; // 0-9999
};
#endif /* Header_h */
