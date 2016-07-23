#include "AntiThetic.h"

AntiThetic::AntiThetic(const Wrapper<RandomBase>& finnerGenerator):
	RandomBase(*finnerGenerator), InnerGenerator(finnerGenerator)
{
	InnerGenerator->Reset();
	OddEven = true;
	NextVariates.resize(GetDimensionality());
}

std::shared_ptr<RandomBase> AntiThetic::clone() const
{
	return std::shared_ptr<RandomBase>(new AntiThetic(*this));
}

void AntiThetic::GetUniforms(std::vector<double>& variates)
{
	if (OddEven) {
		InnerGenerator->GetUniforms(variates);

		for (unsigned long i = 0; i < GetDimensionality(); ++i) {
			NextVariates[i] = 1.0 - variates[i];
		}
		OddEven = false;
	}
	else {
		variates = NextVariates;
		OddEven = true;
	}
}

void AntiThetic::SetSeed(unsigned long Seed)
{
	InnerGenerator->SetSeed(Seed);
	OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
	if (numberOfPaths == 0)
		return;

	if (!OddEven) {
		OddEven = true; // ensure the skip is considered from an odd position
		--numberOfPaths;
	}

	InnerGenerator->Skip(numberOfPaths / 2);

	if (numberOfPaths % 2)
	{
		std::vector<double> tmp(GetDimensionality());
		GetUniforms(tmp);
	}
}

void AntiThetic::ResetDimensionality(unsigned long NewDimensionality)
{
	RandomBase::ResetDimensionality(NewDimensionality);
	NextVariates.resize(NewDimensionality);
	InnerGenerator->ResetDimensionality(NewDimensionality);
}

void AntiThetic::Reset()
{
	InnerGenerator->Reset();
	OddEven = true;
}
