//
//  main_f.cpp
//  MD_1_1
//
//  Created by Eriks Karklins on 14/02/2023.
//

#include <iostream>
#include "Header.h"

using namespace std;

Character::Character(string n, int l){
    name = n;
    life = l;
}

bool Character::Hit(int h)
{
    if (life<=0) {
        cout<<"Personāžs ir Dead"<<endl<<endl;
    } else {
        life = life - h;//samazina personāža dzīvi par parametra vērtību
        
        if (life>0) {
            cout<<"Alive"<<endl<<endl;//atgriež alive ja life lielāks par 0
        } else {
            cout<<"Dead"<<endl<<endl;//atgriež Dead ja life mazāks par 0
        }
    }
    
    return life;//ja kas cits atgriež life
}

int Character::GetLife()
{
    if (life>0) {
        cout << "GetLife: " << life<<endl<<endl;//izvada aktuālo life skaitu pēc samazinājuma ja vairāk par 0
    } else {
        cout << "GetLife: " << "Dead for shure"<<endl<<endl;//paziņo ka ir miris jo dzīvibu vairs nav
    }
    
    
    return 0;
}
    
void Character::Go(char j)//t-top, b-bottom, l-left, r-right parbaude, soļu skaita parbaude
{
    
    if (life<=0) {
        cout<<"Personāžs ir Dead"<<endl<<endl;
    } else {
        
        char ch;
        //string pth;
        
        cout <<"Craracter "<<name<< " ievadiet kustibas virzienu t-top, b-bottom, l-left, r-right"<<endl;
        for (int i=0; i<j; i++) {//j saņemtā vertiba par iešanas virzieniem
            
            do//parbauda vai ievade korekta liek ievadīt atkārtoti ja nav korekti
            {
                cin >> ch;
                
                if ((ch != 't') && (ch != 'b') && (ch != 'l')&& (ch != 'r'))
                { cout << "nepareiza ievade!!" << endl;
                    cout << "jābūt t-top, b-bottom, l-left, r-right" << endl;
                }
                
                Character::path[i] = ch;// piešķir i tajai vērtībai jaunu vērtību
                
            }
            while ((ch != 't') && (ch != 'b') && (ch != 'l')&& (ch != 'r'));
            
            
            
            //pth.push_back(ch);

        }
        //cout<<name<<" maršruts"<<pth<<endl<<endl;//izvada ievadīto ceļu pilnība
    }
}
    
void Character::PrintCharacter()//izvada vārdu, dzīvs (tad izvada arī dzīves punktu skaitu), vai miris, pēdējos 10 gājienus

{
    if (life>0) {
        cout<< "PrintCharacter: " <<endl<<name<<", "<<"Alive"<<", "<<GetLife()<<endl<<endl;
        cout << "last 10 turns: ";

        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
        
    } else {
        cout<< "PrintCharacter: " <<name<<", "<<"Dead"<<endl<<endl;
        
        for (int i = 0; i < 10; i++) {
            cout << Character::path[i] << " ";
        }
    }
    
   
}

Character::~Character()
{
   cout << "Game Over For " <<name<<endl<<endl;
}




