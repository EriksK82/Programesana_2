// Jārealizē klasi Box ar parametriem width, height, border_color.
// Jārealizē sekojošas klases Box metodes:
// konstruktors
// SetBox
// GetKatrsParametrs
// PrintBox //parametru vērtību izvade



#include <iostream>

using namespace std;

struct BoxStruct {// Jārealizē klasi Box ar parametriem width, height, border_color.
    double width;
    double height;
    string border_color;
};

class Box {
public:
    Box(double, double, string);// konstruktors
    void SetBox(double, double, string);// SetBox
    BoxStruct GetKatrsParameters() const;// GetKatrsParametrs
    void PrintBox() const;// PrintBox //parametru vērtību izvade

private:
    double width = 24;
    double height = 12;
    string border_color = "#000000";
};