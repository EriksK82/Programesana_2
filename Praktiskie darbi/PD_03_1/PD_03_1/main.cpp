//
//  main.cpp
//  PD_03_1
//
//  Created by Eriks Karklins on 11/02/2023.
//

//Izveidot klasi “Date", ar laukiem day, month year. Konstruktorā inicializēt  lauku sākumvērtības. Jārealizē sekojošas funkcijas:
//Konstruktors
//SetDate
//PrintDate (izvada datumu)

//kā arī:
//NextDay (pievieno datumam vienu dienu), pārbaudiet lai pareizi mainītos mēneša un gada vērtības!


#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
   Date t;
   cout << "datums ir: ";
   
t.printDate();
t.nextDay();
    cout<<"datums plus 1 diena ir: ";
t.printDate();

   return 0;
}
