// Fig. 11.6: Date.h
// Date class definition with overloaded increment operators.
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
  
public:
   Date( int m = 1, int d = 1, int y = 1900 ); // default constructor
   void setDate( int, int, int ); // set month, day, year
   bool leapYear( int );
   void getBirthDate();
   int getMonth();

private:
   int month;
   int day;
   int year;

   static const int days[]; // array of days per month
  
}; // end class Date

#endif

