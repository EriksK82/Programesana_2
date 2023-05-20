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
    Boss(string, int, int, int);
    int GetHeads() const;
    void Eat(Hero &);
    void Print();

protected:
    int heads;
};