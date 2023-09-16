#include <iostream>

class Base {
public:
    Base() {}
    int GetX() { return x; }
virtual:
    int x;
};

class Child : public Base {
public:
    Child(int i) { x = i; }
    int GetXAgain() { return x; }
};

int main() {
    Child t(5);
    std::cout << t.GetXAgain();
    return 0;
}
