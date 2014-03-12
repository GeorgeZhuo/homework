// HW6 13.13 test.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <vector>

#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Cube.h"
#include "Sphere.h"
#include "Tetrahedron.h"

using namespace std;

int main ()
{
    vector< Shape * > shapes( 6 );

    Circle circle( 2 );
    Square square( 2 );
    Triangle triangle( 3, 4, 5 );
    Cube cube( 2, 3, 4 );
    Sphere sphere( 2 );
    Tetrahedron tetrahedron( 2 );
    
    shapes[ 0 ] = &circle;
    shapes[ 1 ] = &square;
    shapes[ 2 ] = &triangle;
    shapes[ 3 ] = &cube;
    shapes[ 4 ] = &sphere;
    shapes[ 5 ] = &tetrahedron;

    for ( size_t i = 0; i < 6; i++ )
	{
	    TwodimensionalShape *ptr1 = dynamic_cast
		< TwodimensionalShape * > ( shapes[ i ] );
	    ThreedimensionalShape *ptr2 = dynamic_cast 
		< ThreedimensionalShape * > ( shapes[ i ] );

	    if ( ptr1 != 0 )
		shapes[ i ]->print();

	    if( ptr2 != 0 )
		shapes[ i ]->print();
	}
    return 0;
}
