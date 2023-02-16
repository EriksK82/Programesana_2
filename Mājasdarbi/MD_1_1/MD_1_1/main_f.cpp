//
//  main_f.cpp
//  MD_1_1
//
//  Created by Eriks Karklins on 14/02/2023.
//

#include <iostream>
#include "Header.h"

using namespace std;

Character::Character(string name, int life){
    Character::name = name;

    if (life > 10) { // ja dzives skaits ir lielaks par 10, tad pieskiram maksimalu vertibu (10)
        Character::life = 10;
        return;
    }

    if (life < 1) { // ja dzives skaits ir mazaks par 1, tad pieskiram minimalu vertibu (1)
        Character::life = 1;
        return;
    }

    Character::life = life;
}



bool Character::Hit(int h)
{
    if (life<=0) {
        cout<<"Personāžs ir Dead"<<endl;
    } else {
        life = life - h;//samazina personāža dzīvi par parametra vērtību
        
        if (life>0) {
            cout<<"Alive"<<endl;//atgriež alive ja life lielāks par 0
        } else {
            cout<<"Dead"<<endl;//atgriež Dead ja life mazāks par 0
        }
    }
    
    return life;//ja kas cits atgriež life
}

int Character::GetLife()
{
    if (life>0) {
        cout << "Life: " << life<<endl;//izvada aktuālo life skaitu pēc samazinājuma ja vairāk par 0
    } else {
        cout << "Life: " << "Personāžs ir Dead"<<endl;//paziņo ka ir miris jo dzīvibu vairs nav
    }
    
    
    return 0;
}
    
void Character::Go(char direction)//t-top, b-bottom, l-left, r-right parbaude, soļu skaita parbaude
{
    
    if (life<=0) {
        cout<<"Personāžs ir Dead"<<endl;
    } else {
       
        if (direction != 't' && direction != 'r' && direction != 'l' && direction != 'b' && Character::life > 0) {
            cout << "Move direction is invalid" << endl;
         
        }

        if (Character::life > 0) {
            for (int i = 0; i < 10; i++) {
                if (i != 9) {
                    Character::path[i] = Character::path[i + 1];
                }
            }

            Character::path[9] = direction;
        }
    }
}
    
void Character::PrintCharacter()//izvada vārdu, dzīvs (tad izvada arī dzīves punktu skaitu), vai miris, pēdējos 10 gājienus

{
    if (life>0) {
        cout<< "PrintCharacter: " <<name<<", "<<"Alive"<<", "<<life<<", ";
        cout << "pēdējie 10 : ";

        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
        
    } else {
        cout<< "PrintCharacter: " <<name<<", "<<"Dead"<<", ";
        
        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
    }
    
}

Character::~Character()
{
   cout << "Game Over For " <<name<<endl<<endl;
}




