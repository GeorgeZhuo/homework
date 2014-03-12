// HW7 13.13 Triangle.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <cmath>
#include "Triangle.h"

using namespace std;

Triangle::Triangle( double l1, double l2, double l3 )
    :TwodimensionalShape(), length1( l1 ), length2( l2 ), length3( l3 )
{
}

double Triangle::getArea() const
{
    double p = ( length1 + length2 + length3 ) / 2;

    return sqrt( p * ( p - length1 ) * ( p - length2 ) * ( p - length3 ) );
}

void Triangle::print() const
{
    TwodimensionalShape::print();
    cout << "The area of Triangle is " << getArea() <<endl;
}

