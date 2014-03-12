// HW7 13.13 Tetrahedron.h
// ZHUOZHAOJIN 1233O443

#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "ThreedimensionalShape.h"

class Tetrahedron: public ThreedimensionalShape
{
public:
	Tetrahedron( double );

	virtual double getArea() const;
	virtual double getVolume() const;

	virtual void print() const; 
private:
	double length;

};

#endif // TETRAHEDRON_H
