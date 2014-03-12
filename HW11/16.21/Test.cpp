// 16.21 test.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <exception>

using namespace std;

void fun()
{
    cout << "This occured in fun " << endl;
    throw exception();
}

int main ()
{
    try
    {
	fun();
    }
    catch( exception & )
    {
	cout << "This handle by catch" <<endl;
	throw exception();
    }

    return 0;
}
