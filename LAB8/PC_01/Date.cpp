// Fig. 11.7: Date.cpp
// Date class member- and friend-function definitions.
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// initialize static member; one classwide copy
const int Date::days[] = 
   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int month, int day, int year ) 
{ 
   setDate( month, day, year ); 
} // end Date constructor

// set month, day and year
void Date::setDate( int mm, int dd, int yy )
{
   if ( mm >= 1 && mm <= 12 )
      month = mm;

   if ( yy >= 1900 && yy <= 2100 )
      year = yy;
      
   // test for a leap year
   if ( ( month == 2 && leapYear( year ) && dd >= 1 && dd <= 29 ) ||
        ( dd >= 1 && dd <= days[ month ] ) )
      day = dd;
  
} // end function setDate

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear( int testYear )
{
   if ( testYear % 400 == 0 || 
      ( testYear % 100 != 0 && testYear % 4 == 0 ) )
      return true; // a leap year
   else
      return false; // not a leap year
} // end function leapYear

// determine whether the day is the last day of the month


// overloaded output operator
void Date::getBirthDate()
{
   static string monthName[ 13 ] = { "", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December" };
   cout <<"birthday: " << monthName[ month ] 
	<< ' ' << day << ", " << year;
 }

int Date::getMonth()
{
    return month;
}
