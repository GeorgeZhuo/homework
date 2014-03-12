// Lab 2: destructors.cpp
// ZHUOZHAOJIN 12330443
#include <iostream>
#include <stdexcept>

using namespace std;

#include "TestObject.h"

int main()
{
    try // create objects and throw exception
    {
	// create three TestObjects
	TestObject object1( 1 );
	TestObject object2( 2 );
	TestObject object3( 3 );

	cout << '\n';
     // throw an exception to show that all three Objects created above
     // will have their destructors called before the block expires

	throw runtime_error( "This is an exception test");
    } // end try

    catch( runtime_error &e )
    {
	cerr << e.what() << endl;
    } // end catch
} // end main
