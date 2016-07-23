#include "BlackScholesFormulas.h"
#include <cmath>
#include "Normals.h"

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double standardDeviation = Vol*sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	// For an European call option
	// N(d1) is the factor by which the present value of contingent receipt of the stock exceeds the current stock price
	// N(d2) is the risk-adjusted probability that the option will be exercised
	double d1 = (moneyness + (r - d)*Expiry + 0.5*standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return Spot*exp(-d*Expiry)*CumulativeNormal(d1) - Strike*exp(-r*Expiry)*CumulativeNormal(d2);
}

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double standardDeviation = Vol*sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d)*Expiry + 0.5*standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return Strike*exp(-r*Expiry)*(1-CumulativeNormal(d2)) - Spot*exp(-d*Expiry)*(1 - CumulativeNormal(d1));
}

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double standardDeviation = Vol*sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d)*Expiry + 0.5*standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return exp(-r*Expiry)*CumulativeNormal(d2);
}

double BlackScholesDigitalPut(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double standardDeviation = Vol*sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d)*Expiry + 0.5*standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return exp(-r*Expiry)*(1 - CumulativeNormal(d2));
}

double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double standardDeviation = Vol*sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d)*Expiry + 0.5*standardDeviation*standardDeviation) / standardDeviation;
	return Spot*exp(-d*Expiry)*sqrt(Expiry)*NormalDensity(d1);
}



