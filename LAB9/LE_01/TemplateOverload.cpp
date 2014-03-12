// Lab 1: TemplateOverload.cpp
// ZHUOZHAOJIN 12330443
// Using template functions
#include <iostream>
using namespace std;

// function template printArray definition
// original function from Fig. 14.1
template< typename T >
void printArray( const T *array, int count )
{
// display array
    for ( int i = 0; i < count; i++ )
	cout << array[ i ] << " ";
    cout << endl;
} // end function printArray

// overloaded function template printArray
// takes upper and lower subscripts to print
template< typename T >
int printArray( const T *array, int count, int lowSubscrip, int highSubscript )
{
// check if subscript is negative or out of range
    if ( highSubscript > count || highSubscript < lowSubscrip || lowSubscrip < 0 )
	return 0;
    int counter = 0;
// display array
    for ( int i = lowSubscrip; i <= highSubscript; i++ )
    {
	++counter;
	cout << array[ i ] << ' ';
    } // end for
    cout << '\n';

    return counter; // number or elements output
} // end overloaded function printArray

int main()
{
	const int aCount = 5; // size of array a
	const int bCount = 7; // size of array b
	const int cCount = 6; // size of array c

	int a[ aCount ] = { 1, 2, 3, 4, 5 };
	double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char c[ cCount ] = "HELLO"; // 6th position for null

	cout << "Using original printArray function" << endl;
	// call integer function-template specialization
	printArray( a, aCount );  

	cout << "Array a contains:" << endl;
	// call integer function-template specialization
	cout << printArray( a, aCount, 0, aCount - 1 ) << " elements were output" << endl;  

	cout << "Array a from positions 1 to 3 is:\n"
		<< printArray( a, aCount, 1, 3 ) << " elements were output" << endl;
	cout << "Array a output with invalid subscript:\n"
		<< printArray( a, aCount, -1, 5 ) << " elements were output\n" << endl;

	cout << "Using original printArray function" << endl;
	// call double function-template specialization
	printArray( b, bCount );  
	cout << "Array b contains:" << endl;
	// call double function-template specialization
	printArray( b, bCount, 0, bCount - 1 );  

	cout << "Array b from positions 1 to 3 is:\n"
		<< printArray( b, bCount, 1, 3 ) << " elements were output" << endl;
	cout << "Array b output with invalid subscript:\n"
		<< printArray( b, bCount, -1, 5 ) << " elements were output\n" << endl;
	
	// call char function-template specialization
	cout << "Using original printArray function" << endl;
	printArray( c, cCount - 1 );  
	
	// call char function-template specialization
	cout << "Array c contains:\n";
	cout << printArray( c, cCount, 0, cCount - 2 )
	     << " elements were output" << endl;

	cout << "Array c from positions 1 to 3 is:\n";
	cout << printArray( c, cCount, 1, 3 ) << " elements were output" << endl;
	cout << "Array c output with invalid subscript:\n";
	cout << printArray( c, cCount, -1, 5 ) << " elements were output\n" << endl;
	
	return 0;

} // end main
