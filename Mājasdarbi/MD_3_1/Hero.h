// 1. No Character jāatvasina klasi Hero ar int parametru experience.
//     Jārealizē metodes:
// konstruktors
// Kill(Monster) – palielina experience par Monster life*level
// Print()

#include "Character.h"
#include "Monster.h"

using namespace std;


class Hero : public Character {
public:
    Hero(string, int, int);// konstruktors
    void Kill(Monster &);// Kill(Monster)
    void Print();// Print()

protected:
    int experience;// 1. No Character jāatvasina klasi Hero ar int parametru experience.
};