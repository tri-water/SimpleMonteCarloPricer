#include "PayOffForward.h"

double PayOffForward::operator() (double Spot) const
{
	return Spot - Strike;
}

PayOffForward::PayOffForward(double fStrike) :
	Strike(fStrike)
{

}

std::shared_ptr<PayOff> PayOffForward::clone() const
{
	return std::shared_ptr<PayOff>(new PayOffForward(*this));
}