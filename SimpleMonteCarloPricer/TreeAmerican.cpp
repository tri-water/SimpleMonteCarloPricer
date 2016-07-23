#include "TreeAmerican.h"
#include <minmax.h>

TreeAmerican::TreeAmerican(double FinalTime, const PayOffBridge& fThePayOff) :
	TreeProduct(FinalTime), ThePayOff(fThePayOff)
{

}

std::shared_ptr<TreeProduct> TreeAmerican::clone() const
{
	return std::shared_ptr<TreeProduct>(new TreeAmerican(*this));
}

double TreeAmerican::FinalPayOff(double Spot) const
{
	return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double , double DiscountedFutreValue) const
{
	return max(ThePayOff(Spot), DiscountedFutreValue);
}