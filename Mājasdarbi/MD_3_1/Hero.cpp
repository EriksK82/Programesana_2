// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()


#include "Hero.h"

using namespace std;


Hero::Hero(string name, int life, int experience) : Character(name, life) {
    Hero::experience = (experience > 0) ? experience : 1;//nodefinējam sākotnējo vērtību experience
}

void Hero::Kill(Monster &monster) {
    Hero::experience += monster.GetLife() * monster.GetLevel();//palielina experience par Monster life*level
    monster.Hit(monster.GetLife());
}

void Hero::Print() {
    Hero::PrintCharacter();
    cout << "Experience: " << Hero::experience << endl;// Print()
}