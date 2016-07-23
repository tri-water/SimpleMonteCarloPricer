#include "VanillaOption2.h"

VanillaOption::VanillaOption(const PayOffBridge& fThePayOff, double fExpiry) :
	ThePayOff(fThePayOff), Expiry(fExpiry)
{
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}