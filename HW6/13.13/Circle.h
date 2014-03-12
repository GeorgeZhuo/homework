// HW7 13.13 Circle.h
// ZHUOZHAOJIN 1233O443

#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwodimensionalShape.h"

class Circle: public TwodimensionalShape
{
public:
	Circle( double = 0 );

	virtual double getArea() const;
	virtual void print() const;
	
private:
	double radius;
};

#endif // CIRCLE_H
