// 16.22 Test.cpp
// catch a derived class exception 
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <stdexcept>

using namespace std;


class Derived1 : public runtime_error
{
public:

    Derived1()
	:runtime_error( "This occured in the Derived1" )
	{}
};
class Derived2 : public runtime_error
{
public:

    Derived2()
	:runtime_error( "This occured in the Derived2" )
	{}
};
class Derived3 : public runtime_error
{
public:

    Derived3()
	:runtime_error( "This occured in the Derived3" )
	{}
};

void fun( int num )
{
    if( num == 1 )
	throw Derived1();
    if ( num == 2 )
	throw Derived2();
    if ( num == 3 )
	throw Derived3();
    	
}

int main ()
{
    for( int i = 1; i < 4; i++ )
    {
	try
	{  
	    fun( i );	
	}    
	catch ( runtime_error &e )
	{
	    cout << e.what() << endl;
	}
    }
    return 0;
}
