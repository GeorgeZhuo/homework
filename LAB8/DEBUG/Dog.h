// Debugging: Dog.h
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

// class Dog definition
class Dog : public Animal
{
public:
	Dog( int = 0, int = 0, string = "Toto" );

	virtual void print() const;
	virtual int  getHeight();
	virtual int  getWeight();
	string getName() const;
	void setName( string );
private:
	bool useMetric( string );
	string name;
	int metricHeight;
	int metricWeight;
}; // end class Dog
#endif // DOG_H
