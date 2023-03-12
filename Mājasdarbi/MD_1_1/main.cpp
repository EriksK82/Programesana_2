//
//  main.cpp
//  MD_1_1
//
//  Created by Eriks Karklins on 14/02/2023.

#include <iostream>
#include "Header.h"
#include "main_f.cpp"

using namespace std;



int main()
{
    cout<<"Personāžš Suns"<<endl;
    
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

    
    Ch1.PrintCharacter();
    cout << endl;
    
    cout<<"Personāžš Suns"<<endl;
    
    Character Ch2("kaķis", 7);
    
    Ch2.Go('t');
    Ch2.Go('t');
    Ch2.Go('l');
    Ch2.Go('t');
    Ch2.Go('l');
    Ch2.Go('t');
    Ch2.Hit(5);
    Ch2.Go('t');
    Ch2.Hit(2);
    Ch2.Go('r');
    Ch2.Hit(2);
    Ch2.Go('t');

    
    Ch2.PrintCharacter();

   return 0;
}

