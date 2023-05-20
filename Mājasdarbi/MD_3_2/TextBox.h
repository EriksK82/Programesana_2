#include "Text.h"
#include "Box.h"

using namespace std;

class TextBox : public Text, public Box {
public:
    TextBox(string, double, string, string, double, double, string);
    void SetTextBox(string, double, string, string, double, double, string);
    void PrintTextBox() const;
};