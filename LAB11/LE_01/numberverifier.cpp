// Lab 1: numberverifier.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;
// class NonNumber definition
class NonNumber : public runtime_error
{
public:
// constructor
    NonNumber()
	: runtime_error( "non-integer detected" )
	{
// empty
	} // end class NonNumber definition
/* write definition for member function what */
    virtual string what()
	{
	    return "non-integer detected";
	}
//private:
    //string message;
}; // end class NonNumber
// function castInput definition
int castInput( string input )
{
    int result = 0;
    int negative = 1;
// check for minus sign
    if ( input[ 0 ] == '-' )
	negative = -1;
    for ( int i = input.length() - 1, j = 0; i >= 0; i--, j++ )
    {
	if ( negative == -1 && i == 0 )
	    continue;
	if ( input[ i ] >= '0' && input[ i ] <= '9' )
	    result += static_cast< int >( input[ i ] - '0' ) * pow( 10.0, j );
	else
/* Write code to throw NonNumber exception */
	    throw NonNumber();
    } // end for
    return result * negative;
} // end function castInput
int main()
{
    string input;
    int convert;
    cout << "Please enter a number (end-of-file to terminate): ";
    while ( cin >> input )
    {
/* Write try block that calls castInput */
	try
	{
	    cout << "The number input is:" << castInput( input ) << endl;

	}
/* Write catch handler that catches any exceptions
   that the call to castInput might have thrown */
	catch ( NonNumber &e )
	{
	    cout << "INVALID INPUT: " << e.what() << endl;
	}
	cout << "\n\nPlease enter a number (end-of-file to terminate): ";
    } // end while
    cout << endl;
} // end main
