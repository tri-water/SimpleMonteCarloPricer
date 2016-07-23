#include "DoubleDigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double fLowerLevel, double fUpperLevel) :
	LowerLevel(fLowerLevel), UpperLevel(fUpperLevel)
{

}

double PayOffDoubleDigital::operator()(double Spot) const
{
	if (Spot < LowerLevel) {
		return 0;
	}
	if (Spot > UpperLevel) {
		return 0;
	}

	return 1;
}