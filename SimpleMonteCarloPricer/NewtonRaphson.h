#pragma once
#include <cmath>

// make function pointers template parameters rather than arguments to the funciton
// avoiding the time spent on evaluating the pointers.
template<class T, double (T::*Value)(double) const, double (T::*Derivative)(double) const>
double NewtonRaphson(double Target, double Start, double Tolerance, const T& TheObject)
{
	double y = (TheObject.*Value)(Start);
	double x = Start;
	double StepCounter = 0;

	do {
		double d = (TheObject.*Derivative)(x);
		
		x += (Target - y) / d;
		y = (TheObject.*Value)(x);
		if (StepCounter > 500) {
			std::cout << "\n Not converge, the result may not right.\nplease reset lower and higher guesses.\n";
			break;
		}
		++StepCounter;
	} while (fabs(y - Target) > Tolerance);

	return x;
}