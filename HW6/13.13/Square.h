// HW7 13.13 Square.h
// ZHUOZHAOJIN 1233O443

#ifndef SQUARE_H
#define SQUARE_H

#include "TwodimensionalShape.h"

class Square: public TwodimensionalShape
{
public:
	Square( double );

	virtual double getArea() const;
	virtual void print() const;

private:
	double length;
		
};

#endif // SQUARE_H
