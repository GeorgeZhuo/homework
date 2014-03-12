// PC_02 TemplateOverload.cpp
// ZHUOZHAOJIN 12330443
// Using template functions
#include <iostream>
#include <string>
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

// function ordinary printArray definition 
void printArray( const string *array, int count )
{
    for ( int i = 0; i < count; i++ )
    {
	cout << "\t" << array[ i ]; 
	if ( ( i + 1 ) % 4 == 0 )
	    cout << "\n";
    }
    cout << endl;
} // end function 

int main()
{
	const int aCount = 5; // size of array a
	const int bCount = 7; // size of array b
	const int cCount = 6; // size of array c
	const int dCount = 8; // size of array d

	int a[ aCount ] = { 1, 2, 3, 4, 5 };
	double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char c[ cCount ] = "HELLO"; // 6th position for null
	string d[ dCount ] = { "one", "two", "three", "four", "five", "six", "seven", "eight" };
	
	// call function print array a 
	cout << "\nArray a contains:" << endl;
	printArray( a, aCount ); 

	// call function print array b
	cout << "\nArray b contains:" << endl;
	printArray( b, bCount ); 
	
	// call function print array c 
	cout << "\nArray c contains:\n"; 
	printArray( c, cCount - 1 );  

	// call function print array d
	cout << "\nArray strings contains:\n";
	printArray( d, dCount );
	
	return 0;


} // end main
