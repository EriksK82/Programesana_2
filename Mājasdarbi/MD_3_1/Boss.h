// No Monster jāatvasina klasi Boss ar int parametru heads.
//     Jārealizē metodes:
// konstruktors
// GetHeads() 
// Eat(Hero) – palielina Boss life par Hero life, palielina Boss heads par 1
// Print()

#include "Character.h"

using namespace std;

class Boss : public Monster {
public:
    Boss(string, int, int, int);// konstruktors
    int GetHeads() const;// GetHeads() 
    void Eat(Hero &);// Eat(Hero) 
    void Print();// Print()

protected:
    int heads;//jāatvasina klasi Boss ar int parametru heads
};