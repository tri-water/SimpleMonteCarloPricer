#pragma once
#include "VanillaOption2.h"
#include "Parameters.h"
#include "MCStatistics.h"
#include "Random2.h"
#include "AntiThetic.h"

void SimpleMonteCarlo6(const VanillaOption& TheOption, 
					    double Spot, const Parameters& Vol, 
						const Parameters& r, 
						unsigned long NumberOfPaths, 
						StatisticsMC& gatherer, 
						RandomBase& generator);