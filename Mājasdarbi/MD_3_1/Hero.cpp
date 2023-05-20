// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()


#include "Hero.h"

Hero::Hero(string name, int life, int experience) : Character(name, life) {
    Hero::experience = (experience > 0) ? experience : 1;
}

void Hero::Kill(Monster &monster) {
    Hero::experience += monster.GetLife() * monster.GetLevel();
    monster.Hit(monster.GetLife());
}

void Hero::Print() {
    Hero::PrintCharacter();
    cout << "Experience: " << Hero::experience << endl;
}