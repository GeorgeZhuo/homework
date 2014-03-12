// LAB8 HourlyEmployee.h
// HourlyEmployee class definiton 

#ifndef HOURLYEMPLOYEE
#define HOURLYEMPLOYEE

#include "Employee.h"

class HourlyEmployee: public Employee
{
public:
	HourlyEmployee( const string &, const string &,
			const string &, double, double, int, int, int );
	void setWage( double );
	double getWage() const;

	void setHours( double );
	double getHours() const;

	virtual double earnings() const;
	virtual void print();

private:
	double wage;
	double hours;
	
};

#endif //HOURLYEMPLOYEE
