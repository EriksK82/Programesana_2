//
// Character.cpp
//  MD_3_1
//
//  Created by Eriks Karklins on 15/04/2023.
//

#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(string name, int life){
    Character::name = name;

    if (life > 10) { // ja dzives skaits ir lielaks par 10, tad definējam ka 10 dzivibas
        Character::life = 10;
        return;
    }

    if (life < 1) { // ja dzives skaits ir mazaks par 1, tad definējam ka 10 dzivibas
        Character::life = 1;
        return;
    }

    Character::life = life;
}

bool Character::Hit(int h)
{
    if (life<=0) {
        cout<<"Personazs ir Dead"<<endl;
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
            return life;
}

    
void Character::Go(char d)//t-top, b-bottom, l-left, r-right parbaude, soļu skaita parbaude
{
    
    if (life<=0) {
        cout<<"Personazs ir Dead"<<endl;
    } else {
       
        if (d == 't' || d == 'r' || d == 'l' || d == 'b') {
            
                for (int i = 0; i < 10; i++) {
                    if (i != 9) {
                        Character::path[i] = Character::path[i + 1];
                    }
                }

                Character::path[9] = d;
         
        } else{
            cout << "Nepareizs virziens " << endl;
            
        }
    }
}
    
void Character::PrintCharacter()//izvada vārdu, dzīvs (tad izvada arī dzīves punktu skaitu), vai miris, pēdējos 10 gājienus

{
    if (life>0) {
        cout<< "PrintCharacter: " <<name<<", "<<"Alive"<<", "<<life<<", ";
        cout << "pedejie 10 gajieni : ";

        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
        
    } else {
        cout<< "PrintCharacter: " <<name<<", "<<"Dead"<<", ";
        cout << "pedejie 10 gajieni: ";
        
        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
    }
    
}

Character::~Character()
{
   cout << "Game Over For " <<name<<endl<<endl;
}




