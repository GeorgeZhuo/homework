// HW7 13.13 Sphere.cpp
// ZHUOZHAOJIN 1233O443

#include <iostream>
#include "Sphere.h"

using namespace std;

Sphere::Sphere( double r )
    :ThreedimensionalShape(), radius( r )
{
}

double Sphere::getVolume() const
{
    return 3 * 3.14 * radius * radius * radius / 4;
}

double Sphere::getArea() const 
{
    return 4 * 3.14 * radius * radius;
}

void Sphere::print() const
{
    ThreedimensionalShape::print();
    cout << "The area of sphere is " << getArea() << endl;
    cout << "The volume of sphere is " << getVolume() << endl;
}
