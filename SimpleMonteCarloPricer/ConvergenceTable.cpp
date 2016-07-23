#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(Wrapper<StatisticsMC> fInner) :
	Inner(fInner)
{
	StoppingPoint = 2;
	PathsDone = 0;
}

void ConvergenceTable::DumpOneResult(double result)
{
	Inner->DumpOneResult(result);
	++PathsDone;

	if (PathsDone == StoppingPoint) {
		StoppingPoint *= 2;
		std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());

		for (unsigned long i = 0; i < thisResult.size(); ++i) {
			thisResult[i].push_back(PathsDone);
			ResultsSoFar.push_back(thisResult[i]);
		}
	}

	return;
}

std::shared_ptr<StatisticsMC> ConvergenceTable::clone() const
{
	return std::shared_ptr<StatisticsMC>(new ConvergenceTable(*this));
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const
{
	std::vector<std::vector<double>> tmp(ResultsSoFar);

	if (PathsDone * 2 != StoppingPoint) {
		std::vector<std::vector<double>> thisResult(Inner->GetResultsSoFar());

		for (unsigned long i = 0; i < thisResult.size(); ++i)
		{
			thisResult[i].push_back(PathsDone);
			tmp.push_back(thisResult[i]);
		}
	}
	return tmp;
}