// Lab 2: Complex.cpp
// Member-function definition of class Complex.
#include <iostream>
#include <iomanip>
using namespace std;
#include "Complex.h"
// default constructor
Complex::Complex( void ):
    real( 0 ),
    imaginary( 0 )
{
} // end Complex constructor

// overloaded output (<<) operator
ostream &operator<<( ostream &output, const Complex &c )
{
    output << c.real << showpos << c.imaginary << "i\n" << showpos;

    return output; // return ostream reference
} // end overloaded output (<<) operator

// overloaded input (>>) operator
istream &operator>>( istream &input, Complex &c )
{
    int number;
    int multiplier;

    char temp; // temporary variable used to store input
    input >> number; // get input

    // test if character is a space
    if ( input.peek() == ' ' ) // case a + bi
    {
	c.real = number;
	input >> temp;
	multiplier = ( temp == '+' ) ? 1 : -1;

        // set failbit if character not a space
	if ( input.peek() != ' ' )
	    input.clear( ios::failbit );
	else
	{
            // set imaginary part if data is valid
	    if ( input.peek() == ' ' )
	    {
		input >> c.imaginary;
		c.imaginary *= multiplier;
		input >> temp;
		if ( input.peek() == '\n' ) // character not a newline
		    input.clear( ios::failbit ); // set bad bit
	    } // end if
	    else
		input.clear( ios::failbit ); // set bad bit
	} // end else
    } // end if
    else if (input.peek() == 'i' ) // test for i of imaginary number
    {
	input >> temp;
        // test for newline character entered
	if ( input.peek() == '\n' )
	{
	    c.real = 0;
	    c.imaginary = number;
	} // end if
	else
	    input.clear( ios::failbit ); // set bad bit
    } // end else if
    else if ( input.peek() == '\n' ) // set real number if it is valid
    {
	c.real = number;
	c.imaginary = 0;
    } // end else if
    else
	input.clear( ios::failbit ); // set bad bit

    return input;
} // end overloaded input (>>) operator
