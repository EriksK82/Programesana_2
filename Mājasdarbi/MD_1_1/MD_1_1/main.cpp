//
//  main.cpp
//  MD_1_1
//
//  Created by Eriks Karklins on 14/02/2023.

#include <iostream>
#include "Header.h"

using namespace std;



int main()
{
    
    cout<< "Kurš paliks dzīvs no Charakteriem?"<<endl<<endl;
    
    
    Character Ch1("Eriks", 10);//Testa personāžs Nr.1 (vards,dzivibas)
    int Ch1_HitsTaken = 4;//samazina personāža dzīvi par parametra vērtību
    int Ch1_MoveCount = 12;// personāža move skaits
    
    Ch1.Go(Ch1_MoveCount);// Go parbauda vai ievadits korekti, liek ievadīt kustības virzienus pēc augstāk noteikta skaita;
    Ch1.Hit(Ch1_HitsTaken);//statuss dead or alive
    Ch1.GetLife();//izvada aktuālo dzīvību skaitu
    Ch1.PrintCharacter();// informacijas izvade Vards, dzivibas, gajieni......
  
    
    Character Ch2("Katrina", 7);
    int Ch2_HitsTaken = 7;
    int Ch2_MoveCount = 5;

    Ch2.Go(Ch2_MoveCount);
    Ch2.Hit(Ch2_HitsTaken);
    Ch2.GetLife();
    Ch2.Hit(Ch2_HitsTaken);
    Ch2.Go(Ch2_MoveCount);
    Ch2.PrintCharacter();

   cout << endl;

   return 0;
}

