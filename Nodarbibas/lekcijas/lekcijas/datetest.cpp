//
//  main.cpp
//  lekcijas
//
//  Created by Eriks Karklins on 11/02/2023.
//

#include <iostream>
#include "Header.h"

using namespace std;



int main()
{
   Date t;
   cout << "datums ir: ";
   
t.setDate(13, 12, 2022);
t.printDate();
t.nextDay(0,0,0);
t.printDate();

   return 0;
}
