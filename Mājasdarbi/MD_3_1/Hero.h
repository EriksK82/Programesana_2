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
    Hero(string, int, int);
    void Kill(Monster &);
    void Print();

protected:
    int experience;
};