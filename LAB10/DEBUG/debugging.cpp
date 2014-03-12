// Debugging: debugging.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

double readNumber();
void printFormatted( double, double );

int main()
{
    double x, y;

    x = readNumber();
    y = readNumber();

    printFormatted( x, y );
} // end main

// function readNumber definition
double readNumber()
{
    double number = 0;
    double place = 10;

    cout << "Enter a number: ";
    number = cin.get() - '0';

    while ( cin.peek() != '.' && cin.peek() != '\n' )
	number *= 10 +( static_cast< double >( cin.get() ) - 48 );
   
    if ( cin.peek() == '.' )
	cin.ignore();

	while ( cin.peek() != '\n' )
	{
	    double a = ( static_cast< double >( cin.get() ) - 48 )/ place;
	    number += a;
	    place *= 10;
	  
	} // end while

    cin.ignore();

    return number;
} // end function getNumber

// function printFormatted definition
void printFormatted( double x, double y )
{
    char buffer[] = "The value of x is: ";

    for ( int i = 0; buffer[ i ] != '\0'; i++ )
	cout.put( buffer[ i ] );
  
	cout << setw( 12 ) << setprecision( 3 ) << setfill( '0' )
	     << fixed << left <<  x << endl;
    

    char buffer1[]= "The value of y is: ";

    cout.write( buffer1, 19 );
    cout << setprecision( 2 )<< scientific << right
	 << setw( 5 ) << y << endl;
} // end function printFormatted
