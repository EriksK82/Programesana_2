// No Character jāatvasina klasi Monster ar int parametru level.
//     Jārealizē metodes:
// konstruktors
// GetLevel() 
// Print()

#include "Character.h"

using namespace std;

class Monster : public Character {
public:
    Monster(string, int, int);
    int GetLevel() const;
    void Print();

protected:
    int level;
};