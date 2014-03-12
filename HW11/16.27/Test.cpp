// 16.27 Test.cpp
// Order of exception handle 
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <stdexcept>

using namespace std;

class Base
{
public:
    Base()
    {
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
};

int main ()
{
    // throw derived class, catch order: base, derived
    try
    {
	cout << "Throw the derived class" << endl;
	throw Derived();
    }
    catch ( Base )
    {
	cout << "Handled by Base class" << endl;
    }
    catch ( Derived )
    {
	cout << "Handled by Derived class" << endl;
    }

    // throw derived class, catch order derived, base
    try
    {
	cout << "\nThrow the derived class" << endl;
	throw Derived();
    }
    catch ( Derived )
    {
	cout << "Handled by Derived class" << endl;
    }
    catch ( Base )
    {
	cout << "Handled by Base class" << endl;
    }
   
}
