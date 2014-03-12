// 16.26 Test.cpp
// Cathing all exceptions
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <exception>
#include <string>

using namespace std;

int main ()
{
    int a = 1;
    double b = 2.3;
    char c = 'a';
    string d = "bcd";

    for( int i = 1; i < 5; i++ )
    {
	try
	{
	    switch( i )
	    {
	    case 1:
		throw a;
	    case 2:
		throw b;
	    case 3:
		throw c;
	    case 4:
		throw d;
	    }

	}
	catch( int )
	{
	    cout << "This handled in INT" << endl;
	}
	catch ( double )
	{
	    cout << "This handled in DOUBLE" << endl;
	}
	catch ( char )
	{
	    cout << "This handled in CHAR" << endl;
	}
	catch ( string )
	{
	    cout << "This handled in STRING" << endl;
	}
    }
}
