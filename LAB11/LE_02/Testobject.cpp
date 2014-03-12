/// Lab 2: TestObject.cpp
// Class TestObject member function definition.
// ZHUOZHAOJIN 12330443

#include <iostream>

using namespace std;

#include "TestObject.h"

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
