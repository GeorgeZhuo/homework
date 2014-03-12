// 16.29 Test.cpp
// Rethrowing exception 
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <exception>

using namespace std;

void Exception( )
{
    try
    {
	cout << "Funtion Exception throw an exception\n";
	throw exception();
    }
    catch ( exception &)
    {
	cout << "Handled in function Exception" << endl;
	cout << "\nFunction Exception rethrow an exception\n";
	throw;
    }

}

int main ()
{
    try
    {
	cout << "Calling the Exception function in main\n";
	Exception();
    }
    catch ( exception & )
    {
	cout << "Handled in main function" << endl;
    }
}
