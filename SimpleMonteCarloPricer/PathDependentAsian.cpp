#include "PathDependentAsian.h"

PathDependentAsian::PathDependentAsian(const std::vector<double>& fLookAtTimes, double fDeliveryTime, const PayOffBridge& fThePayOff) :
	PathDependent(fLookAtTimes), DeliveryTime(fDeliveryTime), ThePayOff(fThePayOff), NumberOfTimes(fLookAtTimes.size())
{

}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
	return 1UL;
}

std::vector<double> PathDependentAsian::PossibleCashFlowTimes() const
{
	std::vector<double> tmp = { DeliveryTime };
	return tmp;
}

unsigned long PathDependentAsian::CashFlows(const std::vector<double>& SpotValues, std::vector<CashFlow>& GeneratedFlows) const
{
	double sum = 0;
	for (auto n : SpotValues) {
		sum += n;
	}
	double mean = sum / NumberOfTimes;

	GeneratedFlows[0].TimeIndex = 0;
	GeneratedFlows[0].Amount = ThePayOff(mean);

	return 1UL;
}

std::shared_ptr<PathDependent> PathDependentAsian::clone() const
{
	return std::shared_ptr<PathDependent>(new PathDependentAsian(*this));
}