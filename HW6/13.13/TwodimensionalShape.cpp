// HW7 13.13 TwodimensionalShape.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include "TwodimensionalShape.h"

using namespace std;

TwodimensionalShape::TwodimensionalShape()
    :Shape()
{
}
TwodimensionalShape::~TwodimensionalShape()
{
}
void TwodimensionalShape::print() const
{
    cout << "\nThis is a TwodimensionalShape" << endl;
}
