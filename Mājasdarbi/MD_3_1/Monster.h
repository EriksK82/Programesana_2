#include "Character.h"

using namespace std;

class Monster :  public Character {
public:
    Monster(string, int, int);
    int GetLevel() const;
    void Print();
    ~Monster();

private:
    int level;
};