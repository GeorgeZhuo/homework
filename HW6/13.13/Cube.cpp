// HW7 13.13 Cube.cpp
// ZHUOZHAOJIN 1233O443

#include <iostream>
#include "Cube.h"

using namespace std;

Cube::Cube( double w, double l, double h )
    :ThreedimensionalShape(), width( w ), length( l ), heigth( h )
{}

double Cube::getArea() const 
{
    return  2 * ( width * length + width * heigth + length * heigth );
}
double Cube::getVolume() const 
{
    return width * length * heigth;
}

void Cube::print() const 
{
    ThreedimensionalShape::print();
    cout << "The area of cube is " << getArea() << endl;
    cout << "The Volume of cube is " << getVolume() << endl;
}
