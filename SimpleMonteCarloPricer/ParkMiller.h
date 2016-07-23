#pragma once
#include "Random2.h"
#include <vector>
#include <memory>

class ParkMiller
{
public:
	ParkMiller(long fSeed = 1);

	long GetOneRandomInteger();
	void SetSeed(long fSeed);

	static unsigned long Max();
	static unsigned long Min();

private:
	long Seed;
};

class RandomParkMiller : public RandomBase
{
public:
	RandomParkMiller(unsigned long fDimensionality, unsigned long fSeed = 1);

	virtual std::shared_ptr<RandomBase> clone() const;
	virtual void GetUniforms(std::vector<double>& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void Reset();
	virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
	ParkMiller InnerGenerator;
	unsigned long InitialSeed;
	double Reciprocal;
};