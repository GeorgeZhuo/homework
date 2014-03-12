// Lab 1: CheckingAccount.h
//ZHUOZHAOJIN 12330443
// Definition of CheckingAccount class.
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class CheckingAccount: public Account
{
public:
// constructor initializes balance and transaction fee
	CheckingAccount( double, double );
	virtual void credit( double );
	virtual bool debit( double );

private:
	 double transactionFee;
	 void chargeFee();
// utility function to charge fee

}; // end class CheckingAccount
#endif
