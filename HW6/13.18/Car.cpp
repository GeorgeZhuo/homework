 // HW6 13.18 Car.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>

#include "Car.h"

using namespace std;

Car::Car( double g )
    :gasCost( g )
{
}
double Car::getCarbonFootprint() const
{
    return gasCost * 0.785;
}

double Car::getGasCost() const
{
    return gasCost;
}

void Car::print() const
{
    cout << "The carbonFootprint is about Car: \n" ;
}
