// Galvenā programmā izveidot pa vienam Hero, Monster, Boss objektam.
// Visiem objektiem izsaukt Print
// Hero Kill Monster
// Boss Eat Hero 
// Visiem objektiem izsaukt Print

//  main.cpp
//  MD_3_1


#include <iostream>
#include "Character.h"
#include "Character.cpp"
#include "Hero.cpp"
#include "Monster.cpp"
#include "Boss.cpp"

using namespace std;


int main()
{
  

    Hero hero("Suns", 8, 4);//izveidot pa vienam Hero, Monster, Boss objektam
    Monster monster("Kakis", 2, 1);
    Boss boss("Lapsa", 99, 30, 0);

    cout << "Print izvade visiem" << endl;// Visiem objektiem izsaukt Print
    hero.Print();
    monster.Print();
    boss.Print();

    cout << "Hero Kill Monster:" << endl;// Hero Kill Monster
    hero.Kill(monster);

    cout << "Boss Eat Hero :" << endl;// Boss Eat Hero 
    boss.Eat(hero);

    cout << "Print izvade visiem" << endl;// Visiem objektiem izsaukt Print
    hero.Print();
    monster.Print();
    boss.Print();
    
   return 0;
}

