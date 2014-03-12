//LAB8 PC_02 overnightPackage.h
//ZHUOZHAOJIN 12330443

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <string>

#include "Package.h"

using namespace std;

class OvernightPackage: public Package
{
public:
	// constructor
	OvernightPackage( string, string, string, string, string, 
			  string, string, string, string, string, 
			  double, double );
	// function calculate the cost
	virtual double calculateCost();
	// function output the message
	virtual void print();
private:
	double flagFee;

};

#endif // OVERNIGHTPACKAGE_H
