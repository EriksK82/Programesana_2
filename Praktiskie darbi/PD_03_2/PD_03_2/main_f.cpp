//
//  main_f.cpp
//  PD_03_2
//
//  Created by Eriks Karklins on 12/02/2023.
//

#include <iostream>
#include "Header.h"

using namespace std;

void Rectangle::setRect( int width, int height)
{
     w = (width>0)?width:1;
     h = (height>0)?height:1;
}

Rectangle::Rectangle(int wt, int ht)
{
     setRect(wt, ht);
}

void Rectangle::print()
{
   cout<< " paltums:"<<w << ' ' << " augstums:"<< h << endl;
}

int Rectangle::Length()
{
    return (w>h)?w:h;
}

int Rectangle::Width()
{
    return (w>h)?h:w;
}

int Rectangle::Perimeter()
{
    return 2*(w+h);
}

int Rectangle::Area()
{
    return w*h;
}

bool Rectangle::IsSquare()
{
     return w==h;
}
