#pragma once
#include "ExoticEngine.h"
#include "random2.h"
#include <vector>

class ExoticBSEngine : public ExoticEngine
{
public:
	ExoticBSEngine(const Wrapper<PathDependent>& fTheProduct,
		const Parameters& fR,
		const Parameters& fD,
		const Parameters& fVol,
		const Wrapper<RandomBase>& fTheGenerator,
		double fSpot);

	virtual void GetOnePath(std::vector<double>& SpotValues);
	virtual ~ExoticBSEngine() {}

private:
	Wrapper<RandomBase> TheGenerator;
	std::vector<double> Drifts;
	std::vector<double> StandardDeviations;
	double LogSpot;
	unsigned long NumberOfTimes;
	std::vector<double> Variates; // store randon variates
};