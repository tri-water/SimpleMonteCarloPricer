#pragma once
#include <memory>

class TreeProduct
{
public:
	TreeProduct(double fFinalTime);
	virtual double FinalPayOff(double Spot) const = 0; // the final pay-off
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const = 0; // the value at a point in the tree
	virtual ~TreeProduct() {}
	virtual std::shared_ptr<TreeProduct> clone() const = 0;
	double GetFinalTime() const;

private:
	double FinalTime; // the exipiry time of the option
};
