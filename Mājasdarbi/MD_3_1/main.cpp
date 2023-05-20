//
//  main.cpp
//  MD_1_1
//
//  Created by Eriks Karklins on 14/02/2023.

#include <iostream>
#include "Character.h"
#include "Character.cpp"

using namespace std;



int main()
{
    cout<<"Personazs Suns"<<endl;
    
    Character Ch1("suns", 10);//Testa personāžs Nr.1 (vards,dzivibas)
    
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Go('l');
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Hit(1);
    Ch1.Go('l');
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Hit(1);
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Go('t');
    Ch1.Hit(1);
    Ch1.Go('b');
    Ch1.Go('b');
    Ch1.Go('s');//nepareiza ievade
    Ch1.Go('b');
    Ch1.Go('l');
    Ch1.Hit(1);
    cout<<Ch1.GetLife();
    Ch1.GetLife();


    
    // Ch1.PrintCharacter();
  
    
   return 0;
}

