// HW6 13.18 Bicycle.h
// ZHUOZHAOJIN 12330443

#include <iostream>
#include "Bicycle.h"

using namespace std;

Bicycle::Bicycle( double d )
    :distance( d )
{
}
double Bicycle::getCarbonFootprint() const
{
    return distance * 0;
}

double Bicycle::getDistance() const
{
    return distance;
}
void Bicycle::print() const
{
    cout << "The CarbonFootprint is about Bicycle: \n";
}
