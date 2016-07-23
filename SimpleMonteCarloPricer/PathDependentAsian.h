#pragma once
#include "PathDependent.h"
#include "PayOffBridge.h"
#include <vector>

class PathDependentAsian : public PathDependent
{
public:
	PathDependentAsian(const std::vector<double>& fLookAtTimes, double fDeliveryTime, const PayOffBridge& fThePayOff);
	
	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual std::vector<double> PossibleCashFlowTimes() const;
	virtual unsigned long CashFlows(const std::vector<double>& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
	virtual std::shared_ptr<PathDependent> clone() const;
	virtual ~PathDependentAsian() {};

private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;
};