#pragma once
#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "MCStatistics.h"
#include <vector>

class ExoticEngine
{
public:
	ExoticEngine(const Wrapper<PathDependent>& fTheProduct, const Parameters& fr);

	virtual void GetOnePath(std::vector<double>& SpotValues) = 0;
	void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
	virtual ~ExoticEngine() {}
	double DoOnePath(const std::vector<double>& SpotValues) const;

private:
	Wrapper<PathDependent> TheProduct;
	Parameters r;
	std::vector<double> Discounts;
	mutable std::vector<CashFlow> TheseCashFlows;
};
