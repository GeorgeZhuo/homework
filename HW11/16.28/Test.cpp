// 16.28 Test.cpp
// Constructor throwing exception 
// ZHUOZHAOJIN 12330443

#include <iostream>

using namespace std;

class Test
{
public:
    Test()
	{	
	}
};

int main ()
{
    try
    {
	throw Test();
    }
    catch ( Test )
    {
	cout << "Handled by Test" << endl;
    }
}
