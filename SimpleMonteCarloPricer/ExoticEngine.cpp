#include "ExoticEngine.h"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& fTheProduct, const Parameters& fr) :
	TheProduct(fTheProduct), r(fr), Discounts(TheProduct->PossibleCashFlowTimes())
{
	for (auto iterator = Discounts.begin(); iterator != Discounts.end(); ++iterator) {
		*iterator = exp(-r.Integral(0.0, *iterator));
	}
	TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths)
{
	std::vector<double> SpotValues(TheProduct->GetLookAtTimes().size());

	TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
	double thisValue;

	for (unsigned long i = 0; i < NumberOfPaths; ++i) {
		GetOnePath(SpotValues);
		thisValue = DoOnePath(SpotValues);
		TheGatherer.DumpOneResult(thisValue);
	}
	return;
}

double ExoticEngine::DoOnePath(const std::vector<double>& SpotValues) const
{
	unsigned long NumberFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
	double Value = 0.0;

	for (auto iterator : TheseCashFlows)
		Value += iterator.Amount * Discounts[iterator.TimeIndex];

	return Value;
}


