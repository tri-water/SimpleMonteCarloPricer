#include "SimpleMC8.h"
#include "Random2.h"
#include <cmath>
#include <vector>

void SimpleMonteCarlo6(const VanillaOption& TheOption, 
						double Spot, 
						const Parameters& Vol, 
						const Parameters& r, 
						unsigned long NumberOfPaths, 
						StatisticsMC& gatherer,
						RandomBase& generator)
{
	double Expiry = TheOption.GetExpiry();
	double Variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(Variance);
	double itoCorrection = -0.5*Variance;

	double movedSpot = Spot*exp(r.Integral(0, Expiry) + itoCorrection);
	double thisSpot;
	double discounting = exp(-r.Integral(0, Expiry));

	std::vector<double> VariateArray(1);

	for (unsigned long i = 0; i < NumberOfPaths; ++i) {
		generator.GetGaussians(VariateArray);
		thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);

		gatherer.DumpOneResult(thisPayOff*discounting);
	}
}