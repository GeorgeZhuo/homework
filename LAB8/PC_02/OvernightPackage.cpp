// LAB8 PC_02 overnightPackage.h
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <string>

using namespace std;

#include "OvernightPackage.h"

//construtor
OvernightPackage::OvernightPackage( string sn, string sa, string sc,
				string ss,  string sco, string rn,
                                string ra,  string rc,string rs,
				string rco, double w , double c )
    //initialize the base class package
    :Package( sn, sa, sc, ss, sco, rn, ra, rc, rs, rco, w, c ), flagFee( 1 )
{
}// end constructor
//function calculate the cost
 double OvernightPackage::calculateCost()
 {
     return Package::calculateCost() + flagFee;
 }// end function 
// function output the message
void OvernightPackage::print()
{
    Package::print();
    
}// end function 
