// LAB8 HourlyEmployee.cpp
// HourlyEmployee menmber function definition 


#include <iostream>
using namespace std;

#include "HourlyEmployee.h"

HourlyEmployee:: HourlyEmployee( const string &f, const string &l, 
				 const string &ssn, double hwa, double hwk, 
				 int m, int d, int y  )
    :Employee( f, l, ssn, m, d, y )
{
    setWage( hwa );
    setHours( hwk);
}

void HourlyEmployee::setWage( double hw )
{
    wage = ( hw < 0.0 ? 0.0 : hw );
}

double HourlyEmployee::getWage() const
{
    return wage;
}

void HourlyEmployee::setHours( double h )
{
    hours = ( ( ( h >= 0.0 ) && ( h <= 168.0 ) ) ? h : 0.0 );
}

double HourlyEmployee::getHours() const
{
    return hours;
}

double HourlyEmployee::earnings() const
{
    if ( getHours() <= 40 )
	return getWage() * getHours();
    else 
	return 40 * getWage() * ( ( getHours() - 40 ) * getWage() * 1.5 );
}

void HourlyEmployee::print() 
{
    cout << "hourly employee: ";
    Employee::print();
    cout << "\nhourly wage: "<< getWage() <<
	"; hours worked: " << getHours();
}
