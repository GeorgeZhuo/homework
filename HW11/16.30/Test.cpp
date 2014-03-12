// 16.30 Test.cpp
// Uncaught exception
// ZHUOZHAOJIN 12330443 

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void Exception( )
{
    try
    {
	cout << "Funtion Exception throw an exception\n";
	throw runtime_error( "Thrown in function Exception" );
    }
    catch ( int )
    {
	cout << "Handled in function Exception" << endl;
    }

}

int main ()
{
    try
    {
	cout << "Calling the Exception function in main\n";
	Exception();
    }
    catch ( runtime_error &e )
    {
	cout << "Handled in main function \n" << e.what() << endl;
    }
}
