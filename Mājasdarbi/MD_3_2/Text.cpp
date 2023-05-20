// konstruktors
// SetText
// GetKatrsParametrs
// PrintText  //parametru vērtību izvade

#include "Text.h"

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