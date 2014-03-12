// HW7 13.13 Circle.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle( double r )
    :TwodimensionalShape(), radius( r )
{
}

double Circle::getArea() const
{
    return radius * radius * 3.14;
}

void Circle::print() const
{
    TwodimensionalShape::print();
    cout << "The area of circle is: " << getArea() << endl;
}
