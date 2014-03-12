// Lab 1: ASCII.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // display column headings and set field lengths
    cout << setw( 7 ) << "Decimal" << setw( 9 ) << "Octal " << setw( 15 )
         << "Hexadecimal " << setw( 13 ) << "Character" << showbase << '\n';
    for ( int i = 33; i < 127; i++ )
    {
	cout << setw( 7 ) << dec <<  i << setw( 9 ) << oct << i << setw( 15 )
	      << hex << i << setw( 13 ) << static_cast< char >( i ) << "\n";	    	  
    }
    
    return 0;
}
