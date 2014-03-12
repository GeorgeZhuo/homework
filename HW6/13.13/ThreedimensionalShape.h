// HW7 13.13 ThreedimensionalShape.h
// ZHUOZHAOJIN 

#ifndef THREEDIMENIALSHAPE_H
#define THREEDIMENIALSHAPE_H

#include "Shape.h"

class ThreedimensionalShape: public Shape
{
public:
	ThreedimensionalShape();

	virtual double getArea() const = 0;
	virtual void print() const;

	virtual double getVolume() const = 0;

};

#endif // THREEDIMENIALSHAPE_H
