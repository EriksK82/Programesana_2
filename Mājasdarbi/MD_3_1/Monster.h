// No Character jāatvasina klasi Monster ar int parametru level.
//     Jārealizē metodes:
// konstruktors
// GetLevel() 
// Print()


#include "Character.h"

using namespace std;

class Monster :  public Character {
public:
    Monster(string, int, int);// konstruktors
    int GetLevel() const;// GetLevel() 
    void Print();// Print()

protected:
    int level;//int parametru level.
};