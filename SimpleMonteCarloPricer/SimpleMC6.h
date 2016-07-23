#pragma once
#include "VanillaOption2.h"
#include "Parameters.h"
#include "MCStatistics.h"

void SimpleMonteCarlo5(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer);