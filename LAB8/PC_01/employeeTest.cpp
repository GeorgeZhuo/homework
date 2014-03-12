// Fig. 13.19: fig13_19.cpp
// Demonstrating downcasting and runtime type information.
// NOTE: You may need to enable RTTI on your compiler
// before you can execute this application.
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <ctime>

#include "Employee.h"
#include "SalariedEmployee.h" 
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 

using namespace std;
 time_t tt = time(NULL);
 tm* t= localtime(&tt);

int main()
{
   // set floating-point output formatting
   cout << fixed << setprecision( 2 );   
   
   // create vector of three base-class pointers
   vector < Employee * > employees( 4 );

   // initialize vector with various kinds of Employees
   employees[ 0 ] = new SalariedEmployee( 
       "John", "Smith", "111-11-1111", 800, 6, 15, 1944 );
   employees[ 1 ] = new HourlyEmployee( 
       "Karla", "Price", "222-22-2222", 16.75, 40.00, 12, 29, 1960 );
   employees[ 2 ] = new CommissionEmployee( 
       "Sue", "Jones", "333-33-3333", 10000, .06, 9, 8, 1954 );
   employees[ 3 ] = new BasePlusCommissionEmployee( 
       "Bob", "Lewis", "444-44-4444", 5000, .04, 300, 3, 2, 1965);

   // polymorphically process each element in vector employees
   for ( size_t i = 0; i < employees.size(); ++i ) 
   {
      employees[ i ]->print(); // output employee information
      cout << endl;

      // downcast pointer
      BasePlusCommissionEmployee *derivedPtr =
         dynamic_cast < BasePlusCommissionEmployee * > 
            ( employees[ i ] );

      // determine whether element points to base-salaried 
      // commission employee
      if ( derivedPtr != 0 ) // 0 if not a BasePlusCommissionEmployee
      {
         double oldBaseSalary = derivedPtr->getBaseSalary();
         cout << "old base salary: $" << oldBaseSalary << endl;
         derivedPtr->setBaseSalary( 1.10 * oldBaseSalary );
         cout << "new base salary with 10% increase is: $" 
            << derivedPtr->getBaseSalary() << endl;
      } // end if

      double Earned;
      if (  t->tm_mon + 1  == employees[ i ]->birthDate.getMonth() )
	  { 
	      cout << "HAPPY BIRTHDAY!" << endl;
	      Earned =  employees[ i ]->earnings() + 100;
	  }
      else 
	   Earned =  employees[ i ]->earnings();

	  cout << "earned $" << Earned << "\n\n";
   } // end for   
 
   // release objects pointed to by vector’s elements
   for ( size_t j = 0; j < employees.size(); ++j ) 
   {
      // output class name
      cout << "deleting object of " 
         << typeid( *employees[ j ] ).name() << endl;

      delete employees[ j ];
   } // end for
} // end main


