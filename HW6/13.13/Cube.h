// HW7 13.13 Cube.h
// ZHUOZHAOJIN 1233O443

#ifndef CUBE_H
#define CUBE_H

#include "ThreedimensionalShape.h"

class Cube: public ThreedimensionalShape
{
public:
	Cube( double, double, double );

	virtual double getArea() const;
	virtual double getVolume() const;

	virtual void print() const;

private:
	double width;
	double length;
	double heigth;
};

#endif // CUBE_H
