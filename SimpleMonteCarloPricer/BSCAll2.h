#pragma once

class BSCall2
{
public:
	BSCall2(double fr, double fd, double fT, double fSpot, double fStrike);
	double Price(double Vol) const;
	double Vega(double Vol) const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};
