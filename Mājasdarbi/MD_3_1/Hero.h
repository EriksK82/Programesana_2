// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()


#include <iostream>
#include "Character.h"
#include "Monster.h"

class Hero : public Character {
public:
    Hero(string, int, int);// konstruktors
    void Kill(Monster &);// Kill(Monster) – palielina experience par Monster life*level
    void Print();// Print()

protected:
    int experience;//int parametru experience
};