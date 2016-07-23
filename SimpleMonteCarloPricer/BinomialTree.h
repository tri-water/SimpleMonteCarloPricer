#pragma once
#include "TreeProduct.h"
#include <vector>
#include "Parameters.h"

class SimpleBinomialTree
{
public:
	SimpleBinomialTree(double fSpot, const Parameters& fr, const Parameters& fd, double fVolatility, unsigned long Steps, double Time);
	double GetThePrice(const TreeProduct& TheProduct);

protected:
	void BuildTree();

private:
	double Spot;
	Parameters r;
	Parameters d;
	double Volatility;
	unsigned long Steps;
	double Time;
	bool TreeBuilt;

	std::vector<std::vector<std::pair<double, double>>> TheTree;
	std::vector<double> Discounts;
};