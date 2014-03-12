// LAB_10 PC_01
// ZHUOZHAOJIN 12330443

#include <iostream>

using namespace std;

int main ()
{
    int value1 = 12345;
    float value2 = 1.2345;

    for ( int i = 0; i <= 10; i++ )
	{
	    cout.width( i );
	    cout << right << value1 << endl;
	}
    for ( int i = 0; i <= 10; i++ )
    {
	cout.width( i );
	cout << right << value2 << endl;
    }

    return 0;
}
