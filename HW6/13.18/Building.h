// HW6 13.18 Building.h
// ZHUOZHAOJIN 12330443

#ifndef BUILDING_H
#define BUILDING_H

#include "CarbonFootprint.h"

class Building: public CarbonFootprint
{
public:
	Building( double = 0 );
	
	virtual double getCarbonFootprint() const;
	virtual void print() const;

	double getElectricityCost() const;

private:
	double ElectricityCost; // per degree
	
};

#endif // BUILDING_H
