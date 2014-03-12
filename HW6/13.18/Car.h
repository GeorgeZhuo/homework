// HW6 13.18 Car.h
// ZHUOZHAOJIN 12330443

#ifndef CAR_H
#define CAR_H

#include "CarbonFootprint.h"

class Car: public CarbonFootprint
{
public:
	Car( double = 0 );
	
	virtual double  getCarbonFootprint() const;
	virtual double getGasCost() const;
	virtual void print() const;

private:
	double gasCost; 

};

#endif // CAR_H
