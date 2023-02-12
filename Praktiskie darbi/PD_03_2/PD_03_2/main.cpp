//
//  main.cpp
//  PD_03_2
//
//  Created by Eriks Karklins on 11/02/2023.
//Izveidot klasi "Rectangle", ar laukiem platums un garums. Konstruktorā inicializēt  parametru sākumvērtības. Jārealizē sekojošas funkcijas:
//Konstruktors
//SetRectangle
//PrintRectangle (izvada abus parametrus)

//kā arī:
//Length (atrod garāko malu)
//Width (atrod īsāko malu)
//Perimeter
//Area
//IsSquare (vai ir kvadrāts?)


#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
    Rectangle r(3,4);
   
    r.print();
    cout << "Length: " << r.Length() << endl;
    cout << "Width: " << r.Width() << endl;
    cout << "Perimeter: " << r.Perimeter() << endl;
    cout << "Area: " <<  r.Area() << endl;
    cout << "IsSquare: " << r.IsSquare() << endl;


   cout << endl;

   return 0;
}
