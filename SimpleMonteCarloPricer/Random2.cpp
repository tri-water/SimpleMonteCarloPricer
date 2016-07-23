#include "Random2.h"
#include <cstdlib>
#include "Normals.h"

RandomBase::RandomBase(unsigned long fDimensionality):
	Dimensionality(fDimensionality)
{ }


void RandomBase::GetGaussians(std::vector<double>& variates)
{
	GetUniforms(variates);

	for (auto i = variates.begin(); i != variates.end(); ++i) {
		double x = *i;
		*i = InverseCumulativeNormal(x);
	}
}

void RandomBase::ResetDimensionality(unsigned long newDimensionality)
{
	Dimensionality = newDimensionality;
}