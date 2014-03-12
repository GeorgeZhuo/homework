// Lab 2: Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;
class Complex
{
    // overloaded input and output operators
    friend ostream &operator<<( ostream &, const Complex & );
    friend istream &operator>>( istream &, Complex & );
public:
	
    Complex( void ); // constructor
private:
    
    double real;
    double imaginary;

}; // end class Complex

#endif // COMPLEX_H
