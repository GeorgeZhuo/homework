// 16.31 Test.cpp
// Stack Unwilling
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <stdexcept>

using namespace std;

// function1 throw the exception
void function1() throw ( runtime_error)
{
    cout << "In function1 throw exception" << endl;
    throw runtime_error( "function1" );
}

// function2 call function1
void function2() throw ( runtime_error )
{
    cout << "Calling function1 in function 2" << endl;
    function1();
}

// function3 call function2
void function3() throw ( runtime_error )
{
    cout << "Calling function2 in function 3" << endl;
    function2();
}

int main ()
{
    try
    {
	cout << "Calling function3 in main function" << endl;
	function3();
    }

    catch ( runtime_error &e )
    {
	cout << "Exception occured in: " << e.what() << endl; 
	cout << "Handled in main function" << endl;
    }
}
