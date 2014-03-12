// LAB8 PC_02 TwoDayPackage.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>
#include <string>

using namespace std;

#include "TwoDayPackage.h"

// constructor definition
TwoDayPackage::TwoDayPackage( string sn, string sa, string sc,                 
			      string ss,  string sco,string rn,
                              string ra,  string rc,string rs,
			      string rco, double w,double c, double f )
    // initialize the base class package
    :Package( sn, sa, sc, ss, sco, rn, ra, rc, rs, rco, w, c ), flagFee( f )
{
}// end constructor
// function calculate cost
 double TwoDayPackage::calculateCost()
 {
     return Package::calculateCost() + flagFee;
 }// end function
// function output the message
void TwoDayPackage::print()  
{
    Package::print();
    
}// end function

