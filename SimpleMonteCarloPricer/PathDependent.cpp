#include "PathDependent.h"
PathDependent::PathDependent(const std::vector<double>& fLookAtTimes):
	LookAtTimes(fLookAtTimes)
{}

const std::vector<double>& PathDependent::GetLookAtTimes() const
{
	return LookAtTimes;
}