// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()


#include <iostream>
#include "Character.h"
#include "Monster.h"

// using namespace std;

// class Hero: public Character {//No Character jāatvasina klasi Hero

// public:
//     Hero(string, int);// kā tas izskatīsies konstruktorā - modelis???
//     void Kill(Monster &);//Kill(Monster)
//     void Print();//Print()
//     // ~Hero();

// private:
//     int experience;//int parametru experience
// };
class Hero : public Character {
public:
    Hero(string, int, int);
    void Kill(Monster &);
    void Print();

protected:
    int experience;
};