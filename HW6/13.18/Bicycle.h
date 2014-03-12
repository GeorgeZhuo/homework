// HW6 13.18 Bicycle.h
// ZHUOZHAOJIN 12330443

#ifndef BICYCLE_H
#define BICYCLE_H

#include "CarbonFootprint.h"

class Bicycle: public CarbonFootprint
{
public:
Bicycle( double = 0 );
    
virtual double getCarbonFootprint() const;
virtual void print() const;

double getDistance() const;

private:
double distance; // per kilometer
 
};

#endif // BICYCLE_H
