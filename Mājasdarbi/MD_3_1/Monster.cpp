// No Character jāatvasina klasi Monster ar int parametru level.
//     Jārealizē metodes:
// konstruktors
// GetLevel() 
// Print()


#include "Monster.h"

using namespace std;

Monster::Monster(string name, int life, int level) : Character(name, life) {
    Monster::level = (level > 0) ? level : 1;// konstruktors
}

int Monster::GetLevel() const {// GetLevel() 
    return Monster::level;
}

void Monster::Print() {
    Monster::PrintCharacter();
    cout << "Level: " << Monster::level << endl;// Print()
}
