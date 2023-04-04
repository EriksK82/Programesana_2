// Izveidot klasi Vector (orientēts taisnes nogrieznis), aprakstīt to ar divu punktu koordinātēm kas glabājas masīvā ar garumu 6 (x1, y1, z1, x2, y2, z2).
// Pārslogot operatorus:
// “=”
// “+”
// “-”
// “*” (vektoriālais reizinājums)
// “>”, “<”, “>=”, “<=”, “==”, “!=” (jāsalīdzina pēc garuma)
// “>>” (jāievada vektora parametri)
// “<<” (jāizvada vektora garumu) 

// Galvenā programmā nodemonstrēt visu operatoru darbu.
// Lai dabūt 10 masīvu ar vektora koordinātēm jāveido dinamiski!

#include "iostream"
#include "cmath"

using namespace std;

class Vector {
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);

public:
    Vector(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
    ~Vector();
    Vector &operator=(const Vector &);
    double vectorLenght() const;
    double operator+(const Vector &) const;
    double operator-(const Vector &) const;
    const Vector operator*(const Vector &) const;
    bool operator>(const Vector &) const;
    bool operator<(const Vector &) const;
    bool operator>=(const Vector &) const;
    bool operator<=(const Vector &) const;
    bool operator==(const Vector &) const;
    bool operator!=(const Vector &) const;
    
private:
    double* coordinates = new double[6];
};


// konstruktors vektoru vertibu pieskirsanai. Netiek lietots vektoru saskaitīšanai, atņemšanai, jo šo darbību rezultātā ir vērtības kuras neatbilst konstruktora struktūrai 
Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) {
    coordinates[0] = x1;
    coordinates[1] = y1;
    coordinates[2] = z1;
    coordinates[3] = x2;
    coordinates[4] = y2;
    coordinates[5] = z2;
}

//iztīram
Vector::~Vector() { // 
    delete [] coordinates;
}

// vērtības piešķiršana citam vektoram
Vector &Vector::operator=(const Vector &right) {
    if (*this == right) {
        return *this;
    }

    coordinates[0] = right.coordinates[0];
    coordinates[1] = right.coordinates[1];
    coordinates[2] = right.coordinates[2];
    coordinates[3] = right.coordinates[3];
    coordinates[4] = right.coordinates[4];
    coordinates[5] = right.coordinates[5];

    return *this;
}

// vektora garuma aprēķins pēc formulas = √(x2−x1)^2+(y2−y1)^2+(z2−z1)^2
double Vector::vectorLenght() const {
    return sqrt(pow(coordinates[3] - coordinates[0], 2) + pow(coordinates[4] - coordinates[1], 2) + pow(coordinates[5] - coordinates[2], 2));
}

// vektoru summas aprēķināšana pēc formulas = vektora x garums + vektora y garums
double Vector ::operator+(const Vector &right) const {
    return (vectorLenght() + right.vectorLenght()
    );
}

// vektoru starpības aprēķināšana pēc formulas = vektora x garums + (- vektora y garums)
double Vector ::operator-(const Vector &right) const {
    return ( vectorLenght() + (- right.vectorLenght())
    );
}

// vektoriālais reizinājums ar Tiešo metodi 

const Vector Vector::operator*(const Vector &right) const {
    return Vector(
            Vector::coordinates[1] * right.coordinates[2] - Vector::coordinates[2] * right.coordinates[1],
            Vector::coordinates[2] * right.coordinates[0] - Vector::coordinates[0] * right.coordinates[2],
            Vector::coordinates[0] * right.coordinates[1] - Vector::coordinates[1] * right.coordinates[0],
            Vector::coordinates[4] * right.coordinates[5] - Vector::coordinates[5] * right.coordinates[4],
            Vector::coordinates[5] * right.coordinates[3] - Vector::coordinates[3] * right.coordinates[5],
            Vector::coordinates[3] * right.coordinates[4] - Vector::coordinates[4] * right.coordinates[3]
    );
}



bool Vector::operator>(const Vector &right) const {
    return vectorLenght() > right.vectorLenght();
}

bool Vector::operator<(const Vector &right) const {
    return !(*this > right);
}

bool Vector::operator>=(const Vector &right) const {
    return vectorLenght() >= right.vectorLenght();
}

bool Vector::operator<=(const Vector &right) const {
    return vectorLenght() <= right.vectorLenght();
}

bool Vector::operator==(const Vector &right) const {
    return vectorLenght() == right.vectorLenght();
}

bool Vector::operator!=(const Vector &right) const {
    return !(*this == right);
}


// ievade
istream &operator>>(istream &input, Vector &obj) {
    double x1, y1, z1, x2, y2, z2;

    cout << "Input value x1: ";
    input >> x1;
    obj.coordinates[0] = x1;

    cout << "Input value y1: ";
    input >> y1;
    obj.coordinates[1] = y1;

    cout << "Input value z1: ";
    input >> z1;
    obj.coordinates[2] = z1;

    cout << "Input value x2: ";
    input >> x2;
    obj.coordinates[3] = x2;

    cout << "Input value y2: ";
    input >> y2;
    obj.coordinates[4] = y2;

    cout << "Input value z2: ";
    input >> z2;
    obj.coordinates[5] = z2;

    return input;
}

// izvade garums
ostream &operator<<(ostream &output, const Vector &obj) {
    output 
        << "Lenght " << obj.vectorLenght();
    return output;
}

int main() {

    Vector vector1(5, 6, 7, 8, 9, 10), vector2(1, -9, -6, 4, -2, -1), vector3(0, 0, 0, 0, 0, 0);

    vector1=vector3;// vērtību nomainīšana

    cout << "Vector 1 = Vector 3"<< endl;
    cout << "Vector 1 " << vector1<< endl;
    cout << "Vector 3 " << vector2<< endl;

    cout << "Vector 1 + Vector 2"<< endl;//vektoru saskaitīšana
    cout << vector1 + vector2<< endl;

    cout << "Vector 1 - Vector 2"<< endl;//vektoru atņemšana
    cout << vector1 - vector2<< endl;

    cout << "Vector 1 * Vector 2"<< endl;//vektoru reizināšana
    cout << vector1 * vector2<< endl;

    //salīdzināšana ar >, <, >=, <=, ==, != operatoriem
    if (vector1 > vector2)
        cout << "vector1 > vector2" << endl;
    if (vector1 < vector2)
        cout << "vector1 < vector2" << endl; 
    if (vector1 >= vector2)
        cout << "vector1 >= vector2" << endl;
    if (vector1 == vector2)
        cout << "vector1 <= vector2" << endl; 
    if (vector1 == vector2)
        cout << "vector1 <= vector2" << endl; 
    if (vector1 != vector2)
        cout << "vector1 != vector2" << endl; 

    cin >> vector1;// vektora parametru ievade


    //vektora garumu izvade
    cout << "Vector 1 " << vector1<< endl;
    cout << "Vector 2 " << vector2<< endl;
    cout << "Vector 3 " << vector3<< endl;

    system("PAUSE");

    return 0;
}

