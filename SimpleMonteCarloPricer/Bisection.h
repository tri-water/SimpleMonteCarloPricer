#pragma once
#include <cmath>
#include <iostream>

template<class T>
double Bisection(double Target, double Low, double High, double Tolerance, T TheFunction)
{	
	unsigned StepCounter = 0;
	double x = 0.5*(Low + High);
	double y = TheFunction(x);

	do {
		if (y < Target)
			Low = x;
		if (y > Target)
			High = x;
		x = 0.5*(Low + High);
		y = TheFunction(x);
		if (StepCounter > 500) {
			std::cout << "\n Not converge, the result may not right.\nplease reset lower and higher guesses.\n";
			break;
		}
		++StepCounter;
	} while (abs(fabs(y - Target) > Tolerance));

	return x;	
}
