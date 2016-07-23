#include "ExoticBSEngine.h"
#include <cmath>

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& fTheProduct,
	const Parameters& fR,
	const Parameters& fD,
	const Parameters& fVol,
	const Wrapper<RandomBase>& fTheGenerator,
	double fSpot) :
	ExoticEngine(fTheProduct, fR), TheGenerator(fTheGenerator)
{
	std::vector<double> Times(fTheProduct->GetLookAtTimes());
	NumberOfTimes = Times.size();

	TheGenerator->ResetDimensionality(NumberOfTimes);
	Drifts.resize(NumberOfTimes);
	StandardDeviations.resize(NumberOfTimes);

	double Variance = fVol.IntegralSquare(0, Times[0]);
	Drifts[0] = fR.Integral(0.0, Times[0]) - fD.Integral(0, Times[0]) - 0.5*Variance;

	StandardDeviations[0] = sqrt(Variance);

	for (unsigned long i = 1; i < NumberOfTimes; ++i) {
		double thisVariance = fVol.IntegralSquare(Times[i - 1], Times[i]);
		Drifts[i] = fR.Integral(Times[i - 1], Times[i]) - fD.Integral(Times[i - 1], Times[i]) - 0.5*thisVariance;

		StandardDeviations[i] = sqrt(thisVariance);
	}

	LogSpot = log(fSpot);
	Variates.resize(NumberOfTimes);
}

void ExoticBSEngine::GetOnePath(std::vector<double>& SpotValues)
{
	TheGenerator->GetGaussians(Variates);

	double CurrentLogSpot = LogSpot;

	for (unsigned long i = 0; i < NumberOfTimes; ++i) {
		CurrentLogSpot += Drifts[i];
		CurrentLogSpot += StandardDeviations[i] * Variates[i];
		SpotValues[i] = exp(CurrentLogSpot);
	}
	return;
}