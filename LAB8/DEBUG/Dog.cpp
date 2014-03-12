// Debugging: Dog.cpp
//ZHUOZHAOJIN 12330443
#include <iostream>
using namespace std;

#include "Dog.h"

// constructor
Dog::Dog( const int h, const int w, string n )
    : Animal( h, w )
{
    setName( n );
    metricHeight = h * 2.5;
    metricWeight = w / 2.2;

} // end class Dog constructor
// function setName definition
void Dog::setName(  string  n )
{
    name = n;
} // end function setName
// function print definition
void Dog::print() const
{
    cout << "This animal is a dog, its name is: " << name << endl;
    Animal::print();
} // end function print
int Dog::getHeight() 
{
    if ( useMetric( "height" ) )
	return metricHeight;
    else
	return Animal::getHeight();
} // end function print
// return weight
int Dog::getWeight()  
{
    if ( useMetric( "weight" ) )
	return metricWeight;
    else
	return Animal::getWeight();
} // end function getWeight
// function useMetric definition
bool Dog::useMetric( string type )
{
    int choice = 0;

    cout << "Which units would you like to see the "
	 << type << " in? (Enter 1 or 2)\n"
	 << "\t1. metric\n"
	 << "\t2. standard\n";
    cin >> choice;
    if ( choice == 1 )
	return true;
    else
	return false;
} // end function useMetric
