// HW6 13.18 Building.h
// ZHUOZHAOJIN 12330443

#include <iostream>
#include "Building.h"

using namespace std;

Building::Building( double e )
    :ElectricityCost( e )
{
}

double Building::getCarbonFootprint() const
{
    return ElectricityCost * 0.785;
}

double Building::getElectricityCost() const
{
    return ElectricityCost;
}

void Building::print() const
{
    cout << "The CarbonFootprint is about Building: \n";
}
