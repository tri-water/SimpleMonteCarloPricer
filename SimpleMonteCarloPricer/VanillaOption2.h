#pragma once
#include "PayOffBridge.h"

class VanillaOption
{
public:
	VanillaOption(const PayOffBridge& fThePayOff, double fExpiry);
	~VanillaOption() {};

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOffBridge ThePayOff;
};