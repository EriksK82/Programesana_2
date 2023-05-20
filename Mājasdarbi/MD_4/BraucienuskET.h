#include "eTalons.h"

using namespace std;

class BraucienuskET : public eTalons {
public:
    BraucienuskET(int);
    void Print() const;
    void Use() override;
    void Add(int);

private:
    int trips = 1;
};
