// Debugging: Animal.cpp
//ZHUOZHAOJIN 12330443

#include <iostream>
using namespace std;

#include "Animal.h"

// default constructor
Animal::Animal(  int h,  int w )
{
    height = h;
    weight = w;
} // end class Animal constructor
// function print definition
 void Animal::print() const
{
    cout << "This animal's height and weight are as follows\n"
	 << "Height: " << height << "\tWeight: " << weight
	 << endl << endl;
} // end function print
// return height
int Animal::getHeight()
{
    return height;
} // end function getHeight
// return weight
int Animal::getWeight() 
{
    return weight;
} // end function getWeight
// function print definition
void Animal::setHeight( int h )
{
    height = h;
} // end function setHeight
// function print definition
void Animal::setWeight( int w )
{
    weight = w;
} // end function setWeight
// return name

