#pragma once
#include "PayOff3.h"

class PayOffDigitalCall : public PayOff
{
public:
	PayOffDigitalCall(double fStrike);
	virtual double operator()(double Spot) const;
	virtual PayOff* clone() const;
	virtual ~PayOffDigitalCall() {};
private:
	double Strike;
};

class PayOffDigitalPut : public PayOff
{
public:
	PayOffDigitalPut(double fStrike);
	virtual double operator()(double Spot) const;
	virtual PayOff* clone() const;
	virtual ~PayOffDigitalPut() {};
private:
	double Strike;
};
