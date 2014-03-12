// Fig. 13.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iostream>
#include "SalariedEmployee.h" // SalariedEmployee class definition
using namespace std;

// constructor 
SalariedEmployee::SalariedEmployee( const string &first, 
				    const string &last, const string &ssn, 
				    double salary, int m, int d, int y )
    : Employee( first, last, ssn, m, d, y )
{ 
   setWeeklySalary( salary ); 
} // end SalariedEmployee constructor

// set salary
void SalariedEmployee::setWeeklySalary( double salary )
{ 
   if ( salary >= 0.0 )
      weeklySalary = salary;
  
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
   return weeklySalary;
} // end function getWeeklySalary

// calculate earnings; 
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const 
{ 
   return getWeeklySalary(); 
} // end function earnings

// print SalariedEmployee's information 
void SalariedEmployee::print()
{
   cout << "salaried employee: ";
   Employee::print(); // reuse abstract base-class print function
   cout << "\nweekly salary: " << getWeeklySalary();
} // end function print

