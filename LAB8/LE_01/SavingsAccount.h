// Lab 1: SavingsAccount.h
//ZHUOZHAOJIN 12330443
// Definition of SavingsAccount class.

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class SavingsAccount: public Account
{
public:
// constructor initializes balance and interest rate
   SavingsAccount( double, double );

   double calculateInterest();

private:
   double interestRate;

}; // end class SavingsAccount
#endif
