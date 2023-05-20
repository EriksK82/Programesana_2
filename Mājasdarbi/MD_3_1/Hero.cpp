// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()


#include "Hero.h"

Hero::Hero(string name, int life, int experience) : Character(name, life) {// konstruktors ar sākotnējo exp 1
    Hero::experience = (experience > 0) ? experience : 1;
}


void Hero::Kill(Monster &monster) {// Kill(Monster) – palielina experience par Monster life*level
    Hero::experience += monster.GetLife() * monster.GetLevel();
    monster.Hit(monster.GetLife());
}


void Hero::Print() {// Print()
    Hero::PrintCharacter();
    cout << "Experience: " << Hero::experience << endl;
}