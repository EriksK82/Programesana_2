// Realizēt doto klašu struktūru. E-Talons – virtuāla klase, DiennaktsET, BraucienuskET, PersoniskaisET – atvasinātas klases. Klašu konstruktori inicializē visus parametrus. Funkcija Print() izvada visus iekšēju datus.
// DiennaktsET – diennakts E-Talons.
// BraucienuskET – E-Talons uz noteikto braucienu skaitu.
// PersoniskaisET – personiskais E-Talons, ar iespēju papildināt braucienu skaitu.


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class ETalons {
public:
    virtual void Print() = 0;
    virtual void Use() = 0;
    virtual void Add(int x) = 0;
    int GetSerial() { return serial; }

protected:
    ETalons(int serialNumber) : serial(serialNumber) {}
    void E_Coupon() {
        // E_Coupon funkcija priekš ETalons
    }

private:
    int serial;
};

class DiennaktsET : public ETalons {
public:
    DiennaktsET(int serialNumber) : ETalons(serialNumber) {}

    void Print() override {
        cout << "DiennaktsET - 24-hour E-Talon" << endl;
        cout << "Serial: " << GetSerial() << endl;
        //  DiennaktsET datu iezvade//Print
    }

    void Use() override {
        // lietošana DiennaktsET //USE
    }

    void Add(int x) override {
        // pievienošana DiennaktsET//Add
    }
};

class BraucienuskET : public ETalons {
public:
    BraucienuskET(int serialNumber, int numTrips) : ETalons(serialNumber), trips(numTrips) {}

    void Print() override {
        cout << "BraucienuskET - E-Talon konkrētam braucienu skaitam" << endl;
        cout << "Serial: " << GetSerial() << endl;
        //  BraucienuskET//print
    }

    void Use() override {
        // BraucienuskET//USE
    }

    void Add(int x) override {
        // BraucienuskET//ADD
    }

private:
    int trips;
};

class PersonaliskaisET : public ETalons {
public:
    PersonaliskaisET(int serialNumber, int numTrips, string houseName, string personSurname)
        : ETalons(serialNumber), trips(numTrips), house(houseName), surname(personSurname) {}

    void Print() override {
        cout << "PersonaliskaisET - personalizētais  E-Talon, ar iespēju papildināt " << endl;
        cout << "Serial: " << GetSerial() << endl;
        // PersonaliskaisET//Print
    }

    void Use() override {
        // PersonaliskaisET//USE
    }

    void Add(int x) override {
        // PersonaliskaisET//ADD
    }

private:
    int trips;
    string house;
    string surname;
};

class DaytimeET : public ETalons {
public:
    DaytimeET(int serialNumber, string activationDate) : ETalons(serialNumber), activation_date(activationDate), activated(false) {}

    void Print() override {
        cout << "DaytimeET" << endl;
        cout << "Serial: " << GetSerial() << endl;
        cout << "Activation Date: " << activation_date << endl;
        cout << "Activated: " << (activated ? "true" : "false") << endl;
        // DaytimeET//Print
    }

    void Use() override {
        if (!activated) {
            // Aktivācija ETalon
            activated = true;
            time_t now = time(0);
            struct tm* timeinfo = localtime(&now);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
            activation_date = buffer;
        } else {
            // pārbauda vai aktivācījas datums nav lielāks par šodienu +1diena
            time_t now = time(0);
            struct tm* timeinfo = localtime(&now);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
            string today = buffer;

            if (today == activation_date || today == GetNextDay(activation_date)) {
                cout << "Green" << endl;
            } else {
                cout << "Red" << endl;
            }
        }
    }

private:
    string activation_date;
    bool activated;

    string GetNextDay(const string& date) {
        // iegūstam dienu
        return date;
    }
};

class Ride : public ETalons {
public:
    Ride(int serialNumber, int numTrips) : ETalons(serialNumber), trips(numTrips) {}

    void Print() override {
        cout << "Ride" << endl;
        cout << "Serial: " << GetSerial() << endl;
        cout << "Trips: " << trips << endl;
        // Brauciena Ride izvade//Print
    }

    void Use() override {
        if (trips > 0) {
            cout << "Green" << endl;
            trips--;
        } else {
            cout << "Red" << endl;
        }
    }

    void Add(int x) override {
        // Ride//Add
    }

private:
    int trips;
};

class PersonalET : public ETalons {
public:
    PersonalET(int serialNumber, int numTrips, string houseName, string personSurname)
        : ETalons(serialNumber), trips(numTrips), house(houseName), surname(personSurname) {}

    void Print() override {
        cout << "PersonalET" << endl;
        cout << "Serial: " << GetSerial() << endl;
        cout << "Trips: " << trips << endl;
        cout << "House: " << house << endl;
        cout << "Surname: " << surname << endl;
        // PersonalET//Print
    }

    void Use() override {
        if (trips > 0) {
            cout << "Green" << endl;
            trips--;
        } else {
            cout << "Red" << endl;
        }
    }

    void Add(int x) override {
        trips += x;
    }

private:
    int trips;
    string house;
    string surname;
};

int main() {
    const int numETalons = 2;
    ETalons* etalons[numETalons * 2];

    // Masīva izveide
    for (int i = 0; i < numETalons; i++) {
        etalons[i] = new DiennaktsET(i + 1);
        etalons[i + numETalons] = new DiennaktsET(i + 1);
    }

    for (int i = 0; i < numETalons; i++) {
        etalons[i + numETalons * 2] = new BraucienuskET(i + 1, 5);
        etalons[i + numETalons * 3] = new BraucienuskET(i + 1, 5);
    }

    for (int i = 0; i < numETalons; i++) {
        etalons[i + numETalons * 4] = new PersonaliskaisET(i + 1, 10, "My House", "My Surname");
        etalons[i + numETalons * 5] = new PersonaliskaisET(i + 1, 10, "My House", "My Surname");
    }

    // Print
    for (int i = 0; i < numETalons * 6; i++) {
        etalons[i]->Print();
        cout << endl;
    }

    // Use() and Add() funkcija
    Ride* rideET = dynamic_cast<Ride*>(etalons[0]);
    if (rideET) {
        rideET->Use();
        rideET->Add(2);
        rideET->Use();
    }

    PersonalET* personalET = dynamic_cast<PersonalET*>(etalons[numETalons * 4]);
    if (personalET) {
        personalET->Use();
        personalET->Add(5);
        personalET->Use();
    }

    // izdzēšama 
    for (int i = 0; i < numETalons * 6; i++) {
        delete etalons[i];
    }

    return 0;
}
