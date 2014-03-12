// Lab 2: ComplexInput.cpp
// Complex test program.

#include <iostream>
using namespace std;

#include "Complex.h"

int main()
{
    Complex complex; // create Complex object

    // ask user to enter complex number
    cout << "Input a complex number in the form A + Bi:\n";
    cin >> complex; // store complex number
    if ( cin.fail() != 0 ) // display complex number entered by user if valid
	cout << "Complex number entered was:\n" << complex << endl;
    else
	cout << "Invalid Data Entered\n";
} // end main
