// HW7 13.13 TwodimensionalShape.h
// ZHUOZHAOJIN 

#ifndef TWODIMENIALSHAPE_H
#define TWODIMENIALSHAPE_H

#include "Shape.h"

class TwodimensionalShape: public Shape
{
public:
	TwodimensionalShape();
	virtual ~TwodimensionalShape();

	virtual double getArea() const = 0;
	virtual void print() const;	

};

#endif // TWODIMENSIONALSHAPE_H
