//LAB7 PC_01 package.h
//ZHUOZHAOJIN 12330443

#include <string>
#include <iostream>
#include "Package.h"

using namespace std;

// constructor definition
Package::Package( string sn, string sa, string sc, string ss, 
		  string sco,string rn, string ra, string rc,
		  string rs,string rco, double w, double c )
    // initialize the data members
    :SenderName( sn ), SenderAddress( sa ), SenderCity( sc ), 
     SenderState( ss ),SenderCode( sco), RecipientName( rn ), 
     RecipientAddress( ra ), RecipientCity( rc ), RecipientState( rs ), RecipientCode( rco )
{
    weight = ( w < 0.0 ) ? 0.0 : w;
    cost = ( c < 0.0 )? 0.0 : c;
}// end definition
// function calcualte the cost
double Package::calculateCost()
{
    return weight * cost;
}// end function
// function output the message
void Package::print() 
{
    cout << "\nSender:\n" << SenderName << endl
         << SenderAddress << endl << SenderCity
	 << ", " << SenderState << " " << SenderCode
	 << endl;

    cout << "\nRecipient:\n" << RecipientName << endl
	 << RecipientAddress << endl << RecipientCity 
	 << ", " << RecipientState << " " << RecipientCode
	 << endl;
    cout << "\nCost: $"<< calculateCost() << endl;

}// end function
// function for get senderaddress
string Package::getSenderAddress() const
{
    return SenderAddress;
}
// function for get recipientaddress
string Package::getRecipientAddress() const
{
    return RecipientAddress;
}
