// No Monster jāatvasina klasi Boss ar int parametru heads.
//     Jārealizē metodes:
// konstruktors
// GetHeads() 
// Eat(Hero) – palielina Boss life par Hero life, palielina Boss heads par 1
// Print()

#include "Boss.h"
#include "Character.h"

Boss::Boss(string name, int life, int level, int heads) : Monster(name, life, level) {// konstruktors, definējam galvu vērtību uz 0
    Boss::heads = (heads > 0) ? heads : 0;
}

int Boss::GetHeads() const {// GetHeads() 
    return Boss::heads;
}

void Boss::Eat(Hero &hero) {// Eat(Hero) – palielina Boss life par Hero life, palielina Boss heads par 1
    Boss::life += hero.GetLife();
    Boss::heads += 1;
    hero.Hit(hero.GetLife());
}

void Boss::Print() {// Print()
    Boss::PrintCharacter();
    cout << "Level: " << Boss::level << endl;
    cout << "Heads: " << Boss::heads << endl;
}