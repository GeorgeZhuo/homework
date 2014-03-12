// Debugging: Animal.h
//ZHUOZHAOJIN 12330443

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

// class Animal definition
class Animal
{
public:
	Animal(  int = 0,  int = 0 );

	virtual void setHeight( int );
	virtual	int getHeight();

	virtual	void setWeight( int );
	virtual	int getWeight();

	virtual	void print() const = 0;

private:
	int height;
	int weight;
}; // end class Animal

#endif // ANIMAL_H
