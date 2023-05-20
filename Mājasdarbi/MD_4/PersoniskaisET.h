#include "eTalons.h"

using namespace std;

class PersoniskaisET : public eTalons {
public:
    PersoniskaisET(int, string, string);
    void Print() const;
    void Use() override;
    void Add(int) override;

private:
    int trips = 1;
    string name;
    string surname;
    int totalTrips = 0;
};