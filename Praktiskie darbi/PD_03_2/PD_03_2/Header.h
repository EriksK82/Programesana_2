//
//  Header.h
//  PD_03_2
//
//  Created by Eriks Karklins on 12/02/2023.
//

#ifndef Header_h
#define Header_h

class Rectangle
{
public:
    Rectangle( int = 1, int = 1); //konstruktors ar defoltaam veertiibaam
   void print();
   void setRect(int, int);
   int Length();
   int Width();
   int Perimeter();
   int Area();
   bool IsSquare();

private:
   int w;
   int h;
};

#endif /* Header_h */
