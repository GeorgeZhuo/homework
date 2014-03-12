// HW7 13.13 Sphere.h
// ZHUOZHAOJIN 1233O443

#ifndef SPHERE_HN
#define SPHERE_HN

#include "ThreedimensionalShape.h"

class Sphere: public ThreedimensionalShape
{
public:
	Sphere( double );

	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void print() const;
	
private:
	double radius;
};

#endif // TRIANGLE_H
