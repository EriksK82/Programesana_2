#include <iostream>

using namespace std;

////
////////////////////////////// klase Text

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


protected:
    string font = "Arial";
    double size = 14;
    string color = "#000000";//kāsu kods HEX
    string data = "";
};

////////////////////////////////////////// klases Text realizācija

// konstruktors
Text::Text(string f, double s, string c, string d) {
    Text::font = f;
    Text::size = s;
    Text::color = c;
    Text::data = d;
}

// SetText
void Text::SetText(string f, double s, string c, string d) {
    Text::font = f;
    Text::size = s;
    Text::color = c;
    Text::data = d;
}

// GetKatrsParametrs
TextStruct Text::GetKatrsParameters() const {
    TextStruct text;

    text.font = Text::font;
    text.size = Text::size;
    text.color = Text::color;
    text.data = Text::data;

    return text;
}

// PrintText  //parametru vērtību izvade
void Text::PrintText() const {
    cout << "PrintText" << endl;
    cout << "Font: " << Text::font << endl;
    cout << "Size: " << Text::size << endl;
    cout << "Color: " << Text::color << endl;
    cout << "Data: " << Text::data << endl;
}

/////////////////////////// Klase BOX

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

protected:
    double width = 99;
    double height = 99;
    string border_color = "#000000";
};

////////////////////////////// klases box realizācija

// konstruktors
Box::Box(double w, double h, string bc) {
    Box::width = w;
    Box::height = h;
    Box::border_color = bc;
}
// SetBox
void Box::SetBox(double w, double h, string bc) {
    Box::width = w;
    Box::height = h;
    Box::border_color = bc;
}
// GetKatrsParametrs
BoxStruct Box::GetKatrsParameters() const {
    BoxStruct box;

    box.width = Box::width;
    box.height = Box::height;
    box.border_color = Box::border_color;

    return box;
}

// PrintBox //parametru vērtību izvade
void Box::PrintBox() const {
    cout << "Box Parameters:" << endl;
    cout << "Width: " << Box::width << endl;
    cout << "Height: " << Box::height << endl;
    cout << "Border Color: " << Box::border_color << endl;
}

//////////////////////// klase text box

class TextBox : public Text, public Box {// No klasēm Text un Box jāatvasina klasi TextBox. 

public:
    TextBox(string, double, string, string, double, double, string);// konstruktors
    void SetTextBox(string, double, string, string, double, double, string);// SetTextBox
    void PrintTextBox() const;// PrintTextBox (parametru vērtību izvade)
};

/////////////// klases TextBox realizācija

// konstruktors
TextBox::TextBox(string f, double s, string c, string d, double w, double h, string bc) : Text(f, s, c, d), Box(w, h, bc) {}

// SetTextBox
void TextBox::SetTextBox(string f, double s, string c, string d, double w, double h, string bc) {
    TextBox::SetText(f, s, c, d);
    TextBox::SetBox(w, h, bc);
}

// PrintTextBox (parametru vērtību izvade)
void TextBox::PrintTextBox() const {
    TextStruct text = Text::GetKatrsParameters();
    BoxStruct box = Box::GetKatrsParameters();

    cout << "TextBox Parameters:" << endl;
    cout << "Font: " << text.font << endl;
    cout << "Size: " << text.size << "px" << endl;
    cout << "Color: " << text.color << endl;
    cout << "Data: " << text.data << endl;
    cout << "Width: " << box.width << "px" << endl;
    cout << "Height: " << box.height << "px" << endl;
    cout << "Border Color: " << box.border_color << endl;
}

///////////////////////// izpilde 
//Uzrakstiet programmu kas ilustrē iegūtas struktūras darbu. Parādiet  GetKatrsParametrs  funkcijas izsaukumus no TextBox klases.


int main() {


    Text teksts1("Time New Roman", 24, "#AA4343", "text color text color text color");
    teksts1.PrintText();

    cout << endl;
    
    Box boks1(55, 66, "#BB5555");
    boks1.PrintBox();

    cout << endl;

    TextBox kaste1("Times New Roman (Headings)", 13, "#CC5555", "some random text ", 60, 15, "PP0000");
    kaste1.PrintTextBox();

    return 0;
}
