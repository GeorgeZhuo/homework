// LAB9 selectionSort.cpp
// ZHUOZHAOJIN 12330443
// Selection sort with pass-by-reference. This program puts values into an 
// array, sorts them into ascending order and prints the resulting array.

#include <iostream> 
#include <iomanip>
using namespace std;

template< typename T >
void selectionSort( T * const, const int ); // prototype

template< typename T >
void swap( T * const, T * const ); // prototype

int main()
{
   const int arraySize = 10;
   int a[ arraySize ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
   double b[ arraySize ] = { 10.1, 9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1 };

   cout << "int data items in original order\n";

   for ( int i = 0; i < arraySize; ++i )
      cout << setw( 5 ) << a[ i ];

   selectionSort( a, arraySize ); // sort the array

   cout << "\nint data items in ascending order\n";

   for ( int j = 0; j < arraySize; ++j )
      cout << setw( 5 ) << a[ j ];

   cout << "\ndouble data items in original order\n";

   for ( int i = 0; i < arraySize; ++i )
      cout << setw( 5 ) << b[ i ];

   selectionSort( b, arraySize ); // sort the array

   cout << "\ndouble data items in ascending order\n";

   for ( int j = 0; j < arraySize; ++j )
      cout << setw( 5 ) << b[ j ];

   cout << endl;
} // end main

// template function to sort an array
template< typename T >
void selectionSort( T * const array, const int size )
{
   int smallest; // index of smallest element

   // loop over size - 1 elements
   for ( int i = 0; i < size - 1; ++i )
   {
      smallest = i; // first index of remaining array

      // loop to find index of smallest element
      for ( int index = i + 1; index < size; ++index )

         if ( array[ index ] < array[ smallest ] )
            smallest = index;

      swap( &array[ i ], &array[ smallest ] );
   } // end if
} // end function selectionSort

// template function swap values at memory locations to which
// element1Ptr and element2Ptr point 
template< typename T >
void swap( T * const element1Ptr, T * const element2Ptr )
{
   T hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
} // end function swap
