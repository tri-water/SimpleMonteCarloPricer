#include "BSCallClass.h"
#include "BlackScholesFormulas.h"

BSCall::BSCall(double fr, double fd, double fT, double fSpot, double fStrike) :
	r(fr), d(fd), T(fT), Spot(fSpot), Strike(fStrike)
{

}

double BSCall::operator()(double Vol) const
{
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}