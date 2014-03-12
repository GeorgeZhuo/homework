// HW6 13.18 test.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <vector>

#include "CarbonFootprint.h"
#include "Car.h"
#include "Building.h"
#include "Bicycle.h"

using namespace std;

int main ()
{
      vector< CarbonFootprint * > pointers( 3 );
    
    Car car( 23.0 );
    Building building( 70.0 );
    Bicycle bicycle( 15 );

    pointers[ 0 ] = &car;
    pointers[ 1 ] = &building;
    pointers[ 2 ] = &bicycle;

    for ( int i = 0; i < 3; i++ )
	{
	    pointers[ i ]->print();
	    cout << pointers[ i ]->getCarbonFootprint() << endl;
	}
  

    return 0;
}
