//LAB8 PC_02 TwoDayPackage.h
//ZHUOZHAOJIN 12330443

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <string>

#include "Package.h"

using namespace std;
class TwoDayPackage: public Package
{
public:
	// constructor 
	TwoDayPackage( string, string, string, string, string, 
		       string, string, string, string, string, 
		       double, double, double );
	
	// function calculate the cost
	virtual double calculateCost();
	// function print the message
	virtual void print();

private: 
	double flagFee;
};

#endif // TWODAYPACKAGE_H
