// HW7 13.13 Shape.h
// ZHUOZHAOJIN 

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape( );
	virtual ~Shape();

	virtual double  getArea() const = 0; 
	virtual void print() const = 0;
	

};

#endif // SHAPE_H
