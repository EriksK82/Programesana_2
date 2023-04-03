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
    Vector operator+(const Vector &) const;
    const Vector operator-(const Vector &) const;
    const Vector operator*(const Vector &) const;
    bool operator>(const Vector &) const;
    bool operator<(const Vector &) const;
    bool operator>=(const Vector &) const;
    bool operator<=(const Vector &) const;
    bool operator==(const Vector &) const;
    bool operator!=(const Vector &) const;
    double getMagnitude() const;

private:
    double* coordinates = new double[6];
};

//pauze

// konstruktors pieskir parmetru vertibas masiva
Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) {
    coordinates[0] = x1;
    coordinates[1] = y1;
    coordinates[2] = z1;
    coordinates[3] = x2;
    coordinates[4] = y2;
    coordinates[5] = z2;
}

Vector::~Vector() { // destruktors deallocate masivu
    delete [] coordinates;
}

ostream &operator<<(ostream &output, const Vector &obj) {
    output << "x1: " << obj.coordinates[0] << "\n"
          << "y1: " << obj.coordinates[1] << "\n"
          << "z1: " << obj.coordinates[2] << "\n"
          << "x2: " << obj.coordinates[3] << "\n"
          << "y2: " << obj.coordinates[4] << "\n"
          << "z2: " << obj.coordinates[5]
          << endl;

    return output;
}

istream &operator>>(istream &input, Vector &obj) {
    double x1, y1, z1, x2, y2, z2;

    cout << "Enter x1: ";
    input >> x1;
    obj.coordinates[0] = x1;

    cout << "Enter y1: ";
    input >> y1;
    obj.coordinates[1] = y1;

    cout << "Enter z1: ";
    input >> z1;
    obj.coordinates[2] = z1;

    cout << "Enter x2: ";
    input >> x2;
    obj.coordinates[3] = x2;

    cout << "Enter y2: ";
    input >> y2;
    obj.coordinates[4] = y2;

    cout << "Enter z2: ";
    input >> z2;
    obj.coordinates[5] = z2;

    return input;
}
// dabujam vektora magnitudu pec formulas sqrt(a^2+b^2+c^2)
// a = x2 - x1, b = y2 - y1, c = z2 - z1
double Vector::getMagnitude() const {
    return sqrt(pow(coordinates[3] - coordinates[0], 2) +
            pow(coordinates[4] - coordinates[1], 2) +
            pow(coordinates[5] - coordinates[2], 2));
}

Vector &Vector::operator=(const Vector &right) {
    if (*this == right) {
        return *this;
    }

    for (int i = 0; i < sizeof(coordinates); i++) {
        coordinates[i] = right.coordinates[i];
    }

    return *this;
}

Vector Vector::operator+(const Vector &right) const {
    return Vector(
            coordinates[0] + right.coordinates[0],
            coordinates[1] + right.coordinates[1],
            coordinates[2] + right.coordinates[2],
            coordinates[3] + right.coordinates[3],
            coordinates[4] + right.coordinates[4],
            coordinates[5] + right.coordinates[5]
    );
}

const Vector Vector::operator-(const Vector &right) const {
    return Vector(
            coordinates[0] - right.coordinates[0],
            coordinates[1] - right.coordinates[1],
            coordinates[2] - right.coordinates[2],
            coordinates[3] - right.coordinates[3],
            coordinates[4] - right.coordinates[4],
            coordinates[5] - right.coordinates[5]
    );
}

const Vector Vector::operator*(const Vector &right) const {
    return Vector(
            coordinates[1] * right.coordinates[2] - coordinates[2] * right.coordinates[1],
            coordinates[2] * right.coordinates[0] - coordinates[0] * right.coordinates[2],
            coordinates[0] * right.coordinates[1] - coordinates[1] * right.coordinates[0],
            coordinates[4] * right.coordinates[5] - coordinates[5] * right.coordinates[4],
            coordinates[5] * right.coordinates[3] - coordinates[3] * right.coordinates[5],
            coordinates[3] * right.coordinates[4] - coordinates[4] * right.coordinates[3]
    );
}

bool Vector::operator>(const Vector &right) const {
    return getMagnitude() > right.getMagnitude();
}

bool Vector::operator<(const Vector &right) const {
    return !(*this > right);
}

bool Vector::operator>=(const Vector &right) const {
    return getMagnitude() >= right.getMagnitude();
}

bool Vector::operator<=(const Vector &right) const {
    return getMagnitude() <= right.getMagnitude();
}

bool Vector::operator==(const Vector &right) const {
    return getMagnitude() == right.getMagnitude();
}

bool Vector::operator!=(const Vector &right) const {
    return !(*this == right);
}

//pauze

int main() {
    Vector v1, v2(1, 2, 3, 4, 5, 6), v3(1, 1, 1, 1, 1, 1);

    cout << "Original values\n"
         << "v1:\n" << v1 << "\n"
         << "v2:\n" << v2 << "\n"
         << "v3:\n" << v3
        << endl;

    cin >> v1;

    cout << "cin >> v1\n"
         << "v1:\n" << v1
         << endl;

    v3 = v1;

    cout << "v3 = v1" << endl;
    cout << "v3:\n" << v3 << endl;

    cout << "v1 + v2" << endl;
    cout << (v1 + v2) << endl;

    cout << "v3 - v1" << endl;
    cout << (v3 - v1) << endl;

    cout << "v1 * v2" << endl;
    cout << (v1 * v2) << endl;

    cout << "v1 > v2" << endl;

    if (v1 > v2) {
        cout << "TRUE" << endl;
        cout << "v1 is greater then v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is smaller or equal to v2\n" << endl;
    }

    cout << "v1 < v2" << endl;

    if (v1 < v2) {
        cout << "TRUE" << endl;
        cout << "v1 is smaller then v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is greater or equal to v2\n" << endl;
    }

    cout << "v1 >= v2" << endl;

    if (v1 >= v2) {
        cout << "TRUE" << endl;
        cout << "v1 is greater or equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is smaller then v2\n" << endl;
    }

    cout << "v1 <= v2" << endl;

    if (v1 <= v2) {
        cout << "TRUE" << endl;
        cout << "v1 is smaller or equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is greater then v2\n" << endl;
    }

    cout << "v1 == v2" << endl;

    if (v1 == v2) {
        cout << "TRUE" << endl;
        cout << "v1 is equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is not equal to v2\n" << endl;
    }

    cout << "v1 != v2" << endl;

    if (v1 != v2) {
        cout << "TRUE" << endl;
        cout << "v1 is not equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is equal to v2\n" << endl;
    }

    system("PAUSE");

    return 0;
}

