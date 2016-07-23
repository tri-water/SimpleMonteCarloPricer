#pragma once
#include "TreeProduct.h"
#include "PayOffBridge.h"
#include <memory>

class TreeAmerican : public TreeProduct
{
public:
	TreeAmerican(double fFinalTime, const PayOffBridge& fThePayOff);
	virtual double FinalPayOff(double Spot) const; // the final pay-off
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const; // the value at a point in the tree
	virtual ~TreeAmerican() {}
	virtual std::shared_ptr<TreeProduct> clone() const;

private:
	PayOffBridge ThePayOff;
};
