#include "eTalons.h"
#include <ctime>

using namespace std;

class DiennaktsET : public eTalons {
public:
    DiennaktsET();
    void Print() const;
    void Use() override;
    void Add(int);

private:
    time_t activation_date = 0;
    bool activated = false;
};