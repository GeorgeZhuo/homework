//LAB8 PC_02 packageTest.cpp
//ZHUOZHAOJIN 12330443

#include <iostream>
#include <vector>
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

using namespace std;

int main ()
{
    // creat object package1 and initialation
    Package package1("Lou Brown", "1 Main St", "Boston", "MA","11111", 
		     "Mary Smith", "7 Elm St","New York","NY ", "22222",
		     4.25, 1.0);

    //creat object package2 and initialation
    TwoDayPackage package2("Lisa Klein", "5 Broadway", "Somerville", "MA",
			   "33333","Bob George", "21 Pine Rd",
			   "Cambridge","MA","44444", 6.82, 1.0, 2.0 );

    // creat object package2 and initialation
    OvernightPackage package3("Ed Lewis","2 Oak St","Boston","MA","55555",
			      "Don Kelly", "9 Main St","Denver",
			      "CO", "66666", 10.64, 1.0 );

    vector< Package * > packages( 3 );
    
    // package pointer point to the objects
    packages[ 0 ] = &package1;
    packages[ 1 ] = &package2;
    packages[ 2 ] = &package3;
    
    double totalCost = 0;
    
    // output the message and calcualte the total cost
    for ( size_t i = 0; i < packages.size() ; i++ )
    {
	totalCost += packages[ i ]->calculateCost();
	packages[ i ]->print();
 
    }

    cout << "\nTotal shipping cost: " << totalCost << endl;

    return 0;
}
