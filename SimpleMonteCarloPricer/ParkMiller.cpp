#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long fSeed) :
	Seed(fSeed)
{
	if (Seed == 0)
		Seed = 1;
}

void ParkMiller::SetSeed(long fSeed)
{
	Seed = fSeed;
	if (Seed == 0)
		Seed = 1;
}

long ParkMiller::GetOneRandomInteger()
{
	long k;
	k = Seed / q;
	Seed = a*(Seed - k*q) - r*k;

	if (Seed < 0)
		Seed += m;

	return Seed;
}

unsigned long ParkMiller::Max()
{
	return m - 1;
}

unsigned long ParkMiller::Min()
{
	return 1;
}

RandomParkMiller::RandomParkMiller(unsigned long fDimensionality, unsigned long fSeed):
	RandomBase(fDimensionality), InnerGenerator(fSeed), InitialSeed(fSeed)
{
	Reciprocal = 1 / (1.0 + InnerGenerator.Max());
}

std::shared_ptr<RandomBase> RandomParkMiller::clone() const
{
	return std::shared_ptr<RandomBase>(new RandomParkMiller(*this));
}

void RandomParkMiller::GetUniforms(std::vector<double>& variates)
{
	for (unsigned long i = 0; i < GetDimensionality(); ++i) {
		variates[i] = InnerGenerator.GetOneRandomInteger()*Reciprocal;
	}
}

void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
	std::vector<double> tmp(GetDimensionality());
	for (unsigned long i = 0; i < numberOfPaths; ++i)
	{
		GetUniforms(tmp);
	}
}

void RandomParkMiller::SetSeed(unsigned long Seed)
{
	InitialSeed = Seed;
	InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
	InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality)
{
	RandomBase::ResetDimensionality(NewDimensionality);
	InnerGenerator.SetSeed(InitialSeed);
}