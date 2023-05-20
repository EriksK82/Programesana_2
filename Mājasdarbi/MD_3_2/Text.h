// Jārealizē klasi Text ar parametriem font, size, color, data.
// Jārealizē sekojošas klases Text metodes:
// konstruktors
// SetText
// GetKatrsParametrs
// PrintText  //parametru vērtību izvade




#include <iostream>

using namespace std;

struct TextStruct {//Struktūras mainīgo noteikšana, //Jārealizē klasi Text ar parametriem font, size, color, data.
    string font;
    double size;
    string color;
    string data;
};



class Text {
public:
    Text(string, double, string, string);// konstruktors
    void SetText(string, double, string, string);// SetText
    TextStruct GetKatrsParameters() const;// GetKatrsParametrs
    void PrintText() const;// PrintText  //parametru vērtību izvade

private:
    string font = "Arial";
    double size = 14;
    string color = "#000000";//kāsu kods HEX
    string data = "";
};