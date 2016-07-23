#include "TreeEuropean.h"
#include <minmax.h>

TreeEuropean::TreeEuropean(double fFinalTime, const PayOffBridge& fThePayOff):
	TreeProduct(fFinalTime), ThePayOff(fThePayOff)
{

}

double TreeEuropean::FinalPayOff(double Spot) const
{
	return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double , double , double DiscountedFutureValue) const
{
	return DiscountedFutureValue;
}

std::shared_ptr<TreeProduct> TreeEuropean::clone() const
{
	return std::shared_ptr<TreeProduct>(new TreeEuropean(*this));
}