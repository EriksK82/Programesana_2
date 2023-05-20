// No Character jāatvasina klasi Monster ar int parametru level.
//     Jārealizē metodes:
// konstruktors
// GetLevel() 
// Print()


#include "Character.h"

Monster::Monster(string name, int life, int level) : Character(name, life) {
    Monster::level = (level > 0) ? level : 1;
}

int Monster::GetLevel() const {
    return Monster::level;
}

void Monster::Print() {
    Monster::PrintCharacter();
    cout << "Level: " << Monster::level << endl;
}
