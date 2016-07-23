#pragma once

class BSCall
{
public:
	BSCall(double fr, double fd, double fT, double fSpot, double fStrike);
	double operator() (double Vol) const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};