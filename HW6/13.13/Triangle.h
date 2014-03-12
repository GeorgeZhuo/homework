// HW7 13.13 Triangle
// ZHUOZHAOJIN 1233O443

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "TwodimensionalShape.h"

class Triangle: public TwodimensionalShape
{
public:
	Triangle( double, double , double );

	virtual double getArea() const;
	virtual void print() const;

private:
	double length1;
	double length2;
	double length3;
};

#endif // TRIANGLE_H
