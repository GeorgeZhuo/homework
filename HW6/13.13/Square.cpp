// HW7 13.13 Square.cpp
// ZHUOZHAOJIN 1233O443

#include <iostream>
#include "Square.h"

using namespace std;

Square::Square (  double l )
    :TwodimensionalShape(), length( l )
{
}

double Square::getArea() const
{
    return length * length;
}

void Square::print() const
{
    TwodimensionalShape::print();
    cout << "The area of square is: " << getArea() << endl;
}
