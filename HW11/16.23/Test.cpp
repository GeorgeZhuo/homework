// 16.23 Test.cpp
// throwing the Result of a Conditional Expression
// ZHUOZHAOJIN 12330443

#include <iostream>

using namespace std;

int main ()
{
    int a = 1;
    double b = 1.23;
    
    for ( int i = 1; i < 3; i++ )
    {
	try
	{
	    throw (i <= 1 ? a : b);
	}
	catch ( int )
	{
	    cout << "This exception handled by int " << endl;
	}
	catch ( double )
	{
	    cout << "This exception handled by double" << endl;
	}
    }
}
