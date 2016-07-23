#pragma once
#include "PayOff3.h"
#include <memory>

class PayOffForward : public PayOff
{
public:
	PayOffForward(double fStrike);

	virtual double operator() (double Spot) const;
	virtual ~PayOffForward() {}
	virtual std::shared_ptr<PayOff> clone() const;

private:
	double Strike;
};