//LAB8 PC_02 package.h
//ZHUOZHAOJIN 12330443

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using namespace std;
class Package
{
public:
	// constructor
	Package( string, string, string, string, string, 
		 string, string, string, string,string, 
		 double, double );

	// function calculate the cost
	virtual double calculateCost();
	string getSenderAddress() const;
	string getRecipientAddress() const;
	// function print the message
	virtual void print();

private: 
	string SenderName;
	string SenderAddress;
	string SenderState;
	string SenderCity;
	string SenderCode;
	string RecipientName;
	string RecipientAddress;
	string RecipientState;
	string RecipientCity;
	string RecipientCode;

	double weight;
	double cost;
};

#endif //PACKAGE_H
