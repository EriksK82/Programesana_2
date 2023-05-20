#include "Hero.h"

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