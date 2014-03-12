// HW6 13.18 carbonFootprint.h
// ZHUOZHAOJIN 12330443

#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H

class CarbonFootprint
{
public:
	CarbonFootprint();
	virtual ~CarbonFootprint();

	virtual double  getCarbonFootprint() const = 0;
	virtual void print() const = 0;

};

#endif // CARBONFOOTPRINT_H
