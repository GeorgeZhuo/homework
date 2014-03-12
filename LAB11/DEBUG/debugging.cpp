// Debugging: debugging.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

// class InvalidInputTypeException definition
class InvalidInputTypeException
{
public:
    // constructor
    InvalidInputTypeException()
	: message( "entered input of the wrong data type" )
	{
         // empty
	} // end class InvalidInputTypeException
    // function what definition
       const char *what() const
	{
	    return message.c_str();
	} // end function what
private:
    string message;
}; // end class InvalidInputTypeException
// class OutOfRangeException definition
class OutOfRangeException
{
public:
// constructor
      OutOfRangeException()
	: message( "entered a number not in the valid range" )
	{
        // empty
	} // end class OutOfRangeException constructor
     // function what definition
      const char *what() const
	{
	    return message.c_str();
	} // end function what
private:
    string message;
}; // end class OutOfRangeException

// function inputNumber definition
int inputNumber()
{
    int number;
    cout << "Enter an integer from 1 to 100 (-1 to end): ";
    cin >> number;
    if ( cin.fail() == 1 )
	throw InvalidInputTypeException();
    if (( number > 100 || number < 1 ) && number != -1 )
	throw OutOfRangeException();
    if ( number == -1 )
	throw exception();
    return number;
} // end function inputNumber
int main()
{
    int number1 = 0;
    int number2 = 0;
    double result;

// only way to exit this loop is an exception
    while ( true )
    {
	
	try
	{
           number1 = inputNumber();
	   number2 = inputNumber();

	    result = static_cast< double >( number1 ) / number2;
	    cout << number1 << " / " << number2 << " = " << result
		 << endl << endl;
	} // end try
	catch ( exception &)
	{
	    cout << "An unknown exception has"
		 << "exiting the program\n" << endl;
	    exit( 0 );
	} // end catch
	catch( InvalidInputTypeException &e )
	{
	    cout << "Exception occurred: " << e.what() << '\n';
	    cin.clear();
	    cin.ignore();
	} // end catch
	catch( OutOfRangeException &e )
	{
	    cout << "Exception occurred: " << e.what() << '\n';
	}
    } // end while

} // end
