#include "BSCall2.h"
#include "BlackScholesFormulas.h"

BSCall2::BSCall2(double fr, double fd, double fT, double fSpot, double fStrike) :
	r(fr), d(fd), T(fT), Spot(fSpot), Strike(fStrike)
{

}

double BSCall2::Price(double Vol) const
{
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCall2::Vega(double Vol) const
{
	return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}