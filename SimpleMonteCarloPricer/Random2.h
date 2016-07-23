#pragma once
#include <vector>
#include <memory>

class RandomBase
{
public:
	RandomBase(unsigned long fDimensionality);

	inline unsigned long GetDimensionality() const;

	virtual std::shared_ptr<RandomBase> clone() const = 0;
	virtual void GetUniforms(std::vector<double>& variates) = 0;
	virtual void Skip(unsigned long numberOfPaths) = 0;
	virtual void SetSeed(unsigned long seed) = 0;
	virtual void Reset() = 0;

	virtual void GetGaussians(std::vector<double>& variates);
	virtual void ResetDimensionality(unsigned long newDimensionality);

private:
	unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const
{
	return Dimensionality;
}