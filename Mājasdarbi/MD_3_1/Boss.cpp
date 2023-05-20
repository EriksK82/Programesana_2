// No Monster jāatvasina klasi Boss ar int parametru heads.
//     Jārealizē metodes:
// konstruktors
// GetHeads() 
// Eat(Hero) – palielina Boss life par Hero life, palielina Boss heads par 1
// Print()

#include "Boss.h"
#include "Character.h"

Boss::Boss(string name, int life, int level, int heads) : Monster(name, life, level) {
    Boss::heads = (heads > 0) ? heads : 0;
}

int Boss::GetHeads() const {
    return Boss::heads;
}

void Boss::Eat(Hero &hero) {
    Boss::life += hero.GetLife();
    Boss::heads += 1;
    hero.Hit(hero.GetLife());
}

void Boss::Print() {
    Boss::PrintCharacter();
    cout << "Level: " << Boss::level << endl;
    cout << "Heads: " << Boss::heads << endl;
}