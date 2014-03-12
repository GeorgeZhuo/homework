// Fig. 13.16: BasePlusCommissionEmployee.cpp
// BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee( 
   const string &first, const string &last, const string &ssn, 
   double sales, double rate, double salary, int m, int d, int y )
    : CommissionEmployee( first, last, ssn, sales, rate, m, d, y )  
{
   setBaseSalary( salary ); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{ 
   if ( salary >= 0.0 )                                        
      baseSalary = salary;                                         
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{ 
    return baseSalary; 
} // end function getBaseSalary

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const
{ 
    return getBaseSalary() + CommissionEmployee::earnings(); 
} // end function earnings

// print BasePlusCommissionEmployee's information 
void BasePlusCommissionEmployee::print() 
{
   cout << "base-salaried ";
   CommissionEmployee::print(); // code reuse
   cout << "; base salary: " << getBaseSalary();
} // end function print

