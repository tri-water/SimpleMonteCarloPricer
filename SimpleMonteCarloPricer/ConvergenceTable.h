#pragma once
#include "MCStatistics.h"
#include "Wrapper.h"
#include <memory>

class ConvergenceTable : public StatisticsMC
{
public:
	ConvergenceTable(Wrapper<StatisticsMC> fInner);
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;
	virtual std::shared_ptr<StatisticsMC> clone() const;

private:
	Wrapper<StatisticsMC> Inner;
	std::vector<std::vector<double>> ResultsSoFar;
	unsigned long StoppingPoint;
	unsigned long PathsDone;
};