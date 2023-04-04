// Jārealizē klasi Time (Laiks) kas sastāv no sekundes, minūtes, un stundas.
// Jārealizē sekojošas klases Time metodes:
// konstruktors ar noklusēto laika vērtību
// laika ievade (ar >>)
// laika izvade (ar <<)
// laika piešķiršana citam laikam, ar iespēju laiks1=laiks2=laiks3.
// laika palielināšana par vienu sekundi ar ++ prefiksa (++x) operāciju (ja tas ir sekundes pēdēja vērtība, tad jāpalielina arī minūti, u.t.t.)
// laika palielināšana par vienu minūti ar ++ postfiksa (x++) operāciju (ja tas ir minūtes pēdēja vērtība, tad jāpalielina arī stundu, u.t.t.)
// laika samazināšana par vienu sekundi ar -- prefiksa (--x) operāciju (ja tas ir sekundes pirmā vērtība, tad jāsamazina arī minūti, u.t.t.)
// laika samazināšana par vienu minūti ar -- postfiksa (x--) operāciju (ja tas ir minūtes pirmā vērtība, tad jāsamazina arī stundu, u.t.t.)
// laika salīdzināšana ar >, <, >=, <=, ==, != operatoriem. Jāatgriež bool vērtību.

#include "iostream"

using namespace std;

class Time {
    
    friend istream& operator>>(istream&, Time&);
    friend ostream& operator<<(ostream&, const Time&);
    

public:
    Time(int=0, int=0, int=0);
    Time& operator=(const Time&);
    Time operator++();
    Time operator++(int);
    Time operator--();
    Time operator--(int);
    bool operator>(const Time&) const;
    bool operator<(const Time&) const;
    bool operator>=(const Time&) const;
    bool operator<=(const Time&) const;
    bool operator==(const Time&) const;
    bool operator!=(const Time&) const;

private:
    int hours;
    int minutes;
    int seconds;
};

// konstruktors ar noklusēto laika vērtību
Time::Time(int h, int m, int s) { 

    hours = (h>=0 && h <23) ? h : 0;// ja lielāks par 23 tad 0
    minutes = (m>=0 && m<59) ? m : 0;// ja lielāks par 59 tad 0
    seconds = (s>=0 && s<59) ? s : 0;//ja lielāks par 59 tad 0
}

// laika ievade (ar >>)
istream& operator>>(istream& input, Time& obj) {
    string inputH, inputM, inputS;

    cout << "Enter hours : ";
    cin >> inputH;

    //Ievades parbaude Hours
    int i = 0;
    while (i < inputH.length()) {
        if (isdigit(inputH[i]) == false || stoi(inputH) < 0 || stoi(inputH) > 23) { // parbaudam vai ievade: == ir skaitlis, vai nav < par 0,vai nav > par 23//stoi jo inputx ir string
            cout << "Wrong enttry hours : "<< endl; // ja izpildas ludzam ievadīt atkartoti
            cout << "Enter hours : "; 
            input >> inputH;
            i = 0;
        }

        i++;
    }

    cout << "Enter minutes: ";
    cin >> inputM;

    //Ievades parbaude minutes
    i=0;
    while (i < inputM.length()) {
        if (isdigit(inputM[i]) == false || stoi(inputM) < 0 || stoi(inputM) > 59) { // parbaudam vai ievade: == ir skaitlis, vai nav < par 0,vai nav > par 59
            cout << "Wrong enttry minutes: "<< endl; // ja izpildas ludzam ievadīt atkartoti
            cout << "Enter minutes: ";
            input >> inputM;
            i = 0;
        }

        i++;
    }

    cout << "Enter seconds: ";
    cin >> inputS;

    //Ievades parbaude seconds
    i=0;
    while (i < inputS.length()) {
        if (isdigit(inputS[i]) == false || stoi(inputS) < 0 || stoi(inputS) > 59) { // parbaudam vai ievade: == ir skaitlis, vai nav < par 0,vai nav > par 59
            cout << "Wrong enttry seconds: "<< endl; // ja izpildas ludzam ievadīt atkartoti
            cout << "Enter seconds: ";
            input >> inputS;
            i = 0;
        }

        i++;
    }

//Vērtibu pieskirsana klases Time objektiem
    obj.hours = stoi(inputH);
    obj.minutes = stoi(inputM);
    obj.seconds = stoi(inputS);

    return input;
}

// laika izvade (ar <<)
ostream& operator<<(ostream& output, const Time& obj) {
    output
    //no lekcijas piemēra - ja viens simbols pieliekam 0 kā arī starpā saliekam ":"
            << (obj.hours < 10 ? "0" : "") << obj.hours << ":"
            << (obj.minutes < 10 ? "0" : "") << obj.minutes << ":"
            << (obj.seconds < 10 ? "0" : "") << obj.seconds
            <<
            endl;

    return output;
}


//laika piešķiršana citam laikam
Time& Time::operator=(const Time& right) {
    if (*this == right) {
        return *this;
    }

    hours = right.hours;
    minutes = right.minutes;
    seconds = right.seconds;

    return *this;
}

//laika palielināšana par vienu sekundi ar ++ prefiksa (++x) operāciju (ja tas ir sekundes pēdēja vērtība, tad jāpalielina arī minūti, u.t.t.)
Time Time::operator++() {
    if (seconds == 59) {
        if (minutes == 59) {
            if (hours == 23) {
                hours = 0;
            } else {
                hours++;
            }
            minutes = 0;
        } 
        else {
            minutes++;
        }
        seconds = 0;
    } 
    else {
        seconds++;
    }

    return *this;
}

//laika palielināšana par vienu minūti ar ++ postfiksa (x++) operāciju (ja tas ir minūtes pēdēja vērtība, tad jāpalielina arī stundu, u.t.t.)
Time Time::operator++(int) {
    if (minutes == 59) {
        if (hours == 23) {
            hours = 0;
        } else {
            hours++;
        }

        minutes = 0;
    } else {
        minutes++;
    }

    return *this;

}

//laika samazināšana par vienu sekundi ar -- prefiksa (--x) operāciju (ja tas ir sekundes pirmā vērtība, tad jāsamazina arī minūti, u.t.t.)
Time Time::operator--() {
    if (seconds == 0) {
        if (minutes == 0) {
            if (hours == 0) {
                hours = 23;
            } else {
                hours--;
            }

            minutes = 59;
        } else {
            minutes--;
        }

        seconds = 59;
    } else {
        seconds--;
    }

    return *this;
}

//laika samazināšana par vienu minūti ar -- postfiksa (x--) operāciju (ja tas ir minūtes pirmā vērtība, tad jāsamazina arī stundu, u.t.t.)
Time Time::operator--(int) {
    if (minutes == 0) {
        if (hours == 0) {
            hours = 23;
        } else {
            hours--;
        }

        minutes = 59;
    } 
    else {
        minutes--;
    }

    return *this;
}


//laika salīdzināšana ar >
bool Time::operator>(const Time &right) const {
        if (hours > right.hours) {
            return true;
        }

            if (hours == right.hours) {
                if (minutes > right.minutes) {
                    return true;
                }

                if (minutes == right.minutes && seconds > right.seconds) {
                    return true;
                }
            }

    return false;
}

//laika salīdzināšana ar <
bool Time::operator<(const Time &right) const {
        if (hours < right.hours) {
             return true;
        }

            if (hours == right.hours) {
                if (minutes < right.minutes) {
                    return true;
                }

                    if (minutes == right.minutes && seconds < right.seconds) {
                        return true;
                    }
            }

    return false;
}

//laika salīdzināšana ar >=
bool Time::operator>=(const Time &right) const {
    if (*this > right || *this == right) {
        return true;
    }

    return false;
}


//laika salīdzināšana ar <=
bool Time::operator<=(const Time &right) const {
    if (*this < right || *this == right) {
        return true;
    }

    return false;
}

//laika salīdzināšana ar ==
bool Time::operator==(const Time &right) const {
    if (hours == right.hours && minutes == right.minutes && seconds == right.seconds) {
        return true;
    }

    return false;
}


//laika salīdzināšana ar !=
bool Time::operator!=(const Time &right) const {
    return !(*this == right);
}


int main() {

// sākotnējā laika uzstādīšana
    Time laiks1(14,25,25), laiks2(1,9,2), laiks3(25,60,60);

//sākotnējā laika izvade
    cout << "Set time:"<<endl << "Laiks 1: " << laiks1 << endl<< "Laiks 2: " << laiks2<< endl << "Laiks 3: " << laiks3 << endl;

//laika ievade
    cin>>laiks3;

//laika izvade
    cout << "Laiks 3: " << laiks3 << endl;

//laika piešķiršana citam laikam, ar iespēju laiks1=laiks2=laiks3
    laiks1=laiks2=laiks3;

//izvade pēc laika piešķiršanas citam laikam
    cout << "time after laiks1=laiks2=laiks3:"<<endl << "Laiks 1: " << laiks1 << endl<< "Laiks 2: " << laiks2<< endl << "Laiks 3: " << laiks3 << endl;

//laika palielināšana par vienu sekundi ar ++ prefiksa 
    ++ laiks1;

//laika izvade
    cout << "++ Laiks 1: " << laiks1 << endl;

//laika palielināšana par vienu minūti ar ++ postfiksa
    laiks1 ++;

//laika izvade
    cout << "Laiks 1 ++: " << laiks1 << endl;

//laika samazinasana par vienu sekundi ar -- prefiksa 
    -- laiks1;

//laika izvade
    cout << "-- Laiks 1: " << laiks1 << endl;

//laika samazinašana par vienu minūti ar -- postfiksa
    laiks1 --;

//laika izvade
    cout << "Laiks 1 --: " << laiks1 << endl;

//kādi tagad laiki
    cout << "Current times:"<<endl << "Laiks 1: " << laiks1 << endl<< "Laiks 2: " << laiks2<< endl << "Laiks 3: " << laiks3 << endl;

//laika salīdzināšana ar >, <, >=, <=, ==, != operatoriem
    if (laiks1 > laiks2)
        cout << "laiks 1 > laiks 2" << endl;
    if (laiks1 < laiks2)
        cout << "laiks 1 < laiks 2" << endl;
    if (laiks1 >= laiks2)
        cout << "laiks 1 >= laiks 2" << endl;
    if (laiks1 <= laiks2)
        cout << "laiks 1 <= laiks 2" << endl;
    if (laiks1 == laiks2)
        cout << "laiks 1 == laiks 2" << endl;
    if (laiks1 != laiks2)
        cout << "laiks 1 != laiks2" << endl;

            system("PAUSE");

    return 0;
}


