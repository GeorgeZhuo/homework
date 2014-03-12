// HW7 13.13 Tetrahedron.cpp
// ZHUOZHAOJIN 1233O443

#include <iostream>
#include <cmath>
#include "Tetrahedron.h"

using namespace std;

Tetrahedron::Tetrahedron( double l )
    :ThreedimensionalShape(), length( l )
{
    
}

double Tetrahedron::getArea() const
{
    return 4 * length * length  * sqrt( 3 ) / 4;
}

double Tetrahedron::getVolume() const
{
    return length * length * length / 2;
}

void Tetrahedron::print() const 
{
    ThreedimensionalShape::print();
    cout << "The area of tetrahedron is " << getArea() << endl;
    cout << "The volume of tetrahedron is " << getVolume() << endl;
}
