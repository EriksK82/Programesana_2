// Realizēt doto klašu struktūru. E-Talons – virtuāla klase, DiennaktsET, BraucienuskET, PersoniskaisET – atvasinātas klases. 
// Klašu konstruktori inicializē visus parametrus. 
// Funkcija Print() izvada visus iekšēju datus.
// DiennaktsET – diennakts E-Talons.
// BraucienuskET – E-Talons uz noteikto braucienu skaitu.
// PersoniskaisET – personiskais E-Talons, ar iespēju papildināt braucienu skaitu.

#include <iostream>

using namespace std;

//////////////// klase e-talons
// E-Talons()
// Print()
// Use()
// Add()
// serial


class eTalons {
public:
    eTalons();
    virtual void Print() const;
    virtual void Use() = 0;
    virtual void Add(int) = 0;

private:
    static string serialGenerator();
    string serial;
};

//////////// klases e-talons realizāciaja

// int randomNumber(int, int);

// int randomNumber(int min, int max) {
//     random_device rd; // funkcija izmanto <random> biblioteku
//     mt19937 gen(rd());
//     uniform_int_distribution<> random(min,max);

//     return random(gen);
// }

eTalons::eTalons() {
    eTalons::serial = eTalons::serialGenerator(); // kad eTalons objekts tiek izveidots, pieskiru vertibu mainigajiem serial
}

void eTalons::Print() const {
    cout << "Serial: " << eTalons::serial << endl;
}

string eTalons::serialGenerator() {
    string generatedSerial = "0" + to_string(randomNumber(1, 9)) + "-"; // deklareju string ar randomu vienskaitli ar 0 prieksa

    for (int i = 0; i < 15; i++) { // pieskiru vel 15 nejausus vienskaitlus, izmantojot funkciju, kuru es glabu Helpers.h
        generatedSerial += to_string(randomNumber(1, 9));
    }

    return generatedSerial;
}




