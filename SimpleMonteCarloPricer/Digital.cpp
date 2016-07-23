#include "Digital.h"

PayOffDigitalCall::PayOffDigitalCall(double fStrike):
	Strike(fStrike)
{

}

double PayOffDigitalCall::operator()(double Spot) const 
{
	return Spot > Strike ? 1 : 0;
}

PayOff* PayOffDigitalCall::clone() const
{
	return new PayOffDigitalCall(*this);
}

PayOffDigitalPut::PayOffDigitalPut(double fStrike) :
	Strike(fStrike)
{

}

double PayOffDigitalPut::operator()(double Spot) const
{
	return Spot < Strike ? 1 : 0;
}

PayOff* PayOffDigitalPut::clone() const
{
	return new PayOffDigitalPut(*this);
}