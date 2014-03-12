// 16.24: Test.cpp
// Local Variable Destructors
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <stdexcept>
using namespace std;

class TestObject
{
public:
	TestObject( int ); 
	~TestObject();
private:
	int value;
}; // end class TestObject

// constructor takes int parameter
TestObject::TestObject( int val ) : value( val )
{
     cout << "TestObject " << value << " constructor " << endl;
} // end TestObject constructor

// destructor
TestObject::~TestObject()
{
    cout << "TestObject " << value << " destructor" << endl;
} // end TestObject destructor
int main()
{
    try // create objects and throw exception
    {
	// create three TestObjects
	TestObject object1( 1 );
	TestObject object2( 2 );
	TestObject object3( 3 );

	cout << '\n';

	throw runtime_error( "This is an exception test");
    } // end try

    catch( runtime_error &e )
    {
	cerr << e.what() << endl;
    } // end catch

} // end main
