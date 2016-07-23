#include "BinomialTree.h"
#include <cmath>

SimpleBinomialTree::SimpleBinomialTree(double fSpot, const Parameters& fr, const Parameters& fd, double fVolatility, unsigned long fSteps, double fTime) :
	Spot(fSpot), r(fr), d(fd), Volatility(fVolatility), Steps(fSteps), Time(fTime), Discounts(Steps)
{
	TreeBuilt = false;
}

void SimpleBinomialTree::BuildTree()
{
	TreeBuilt = true;
	TheTree.resize(Steps + 1);

	double InitialLogSpot = log(Spot);

	for (unsigned long i = 0; i <= Steps; ++i) {
		TheTree[i].resize(i + 1);

		double thisTime = (i*Time) / Steps;

		double movedLogSpot = InitialLogSpot + r.Integral(0.0, thisTime) - d.Integral(0.0, thisTime);
		movedLogSpot -= 0.5*Volatility*Volatility*thisTime;

		double sd = Volatility*sqrt(Time / Steps);

		for (long j = -static_cast<long>(i), k = 0; j <= static_cast<long>(i); j += 2, ++k)
		{
			TheTree[i][k].first = exp(movedLogSpot + j*sd);
		}
	}
	
	for (unsigned long l = 0; l < Steps; ++l) {
		Discounts[l] = exp(-r.Integral(l*Time / Steps, (l + 1)*Time / Steps));
	}
}

double SimpleBinomialTree::GetThePrice(const TreeProduct& TheProduct)
{
	if (!TreeBuilt)
		BuildTree();

	if (TheProduct.GetFinalTime() != Time)
		throw("mismatched product in SimpleBinomialTree");

	for (long j = -static_cast<long>(Steps), k = 0; j <= static_cast<long>(Steps); j += 2, ++k) {
		TheTree[Steps][k].second = TheProduct.FinalPayOff(TheTree[Steps][k].first);
	}

	for (unsigned long i = 1; i <= Steps; ++i) {
		unsigned long index = Steps - i;
		double ThisTime = index*Time / Steps;

		for (long j = -static_cast<long>(index), k = 0; j <= static_cast<long>(index); j = j + 2, ++k) {
			double Spot = TheTree[index][k].first;
			double futureDiscountedValue = 0.5*Discounts[index] * (TheTree[index + 1][k].second + TheTree[index + 1][k + 1].second);
			TheTree[index][k].second = TheProduct.PreFinalValue(Spot, ThisTime, futureDiscountedValue);
		}
	}
	return TheTree[0][0].second;
}