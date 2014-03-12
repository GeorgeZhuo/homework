// 16.25 Test.cpp
// member object exception
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <stdexcept>

using namespace std;

class Object
{
public:
    Object( int n )
	:number( n )
	{
	    cout << "The constructor of object" << number << endl;
	}
    ~Object()
    {
	cout << "The destructor of object" << number << endl;
    }
private:
    int number;
    
};

class TestObject
{
public:
    TestObject( int n )
	:object( n )
	{
	    cout << "The constructor of Testobject\n" << endl;
	}
    ~TestObject()
	{
	    cout << "The destructor of Testobject" << endl;
	}
private:
    Object object;
};

int main ()
{
    try
    {
	TestObject object1( 1 );
	TestObject object2( 2 );
	TestObject object3( 3 );
	    
	throw runtime_error( "This is exception" );
    }
    catch( runtime_error &e )
    {
	cout << "\n" << e.what() << endl;
    }
}
